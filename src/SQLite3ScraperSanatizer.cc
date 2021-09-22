/**
 * SQLite3ScraperSanatizer.cc
 */

#include <algorithm>

#include <SQLite3ScraperSanatizer.hh>

namespace scraper_sanatizer {

// based on https://stackoverflow.com/questions/2673207/c-c-url-decode-library/2766963
void urldecode(char *dst, const char *src)
{
    char a, b;
    while (*src) {
        if ((*src == '%') && ((a = src[1]) && (b = src[2])) && (isxdigit(a) && isxdigit(b)))
        {
            if (a >= 'a')
                a -= 'a'-'A';
            if (a >= 'A')
                a -= ('A' - 10);
            else
                a -= '0';
            if (b >= 'a')
                b -= 'a'-'A';
            if (b >= 'A')
                b -= ('A' - 10);
            else
                b -= '0';
            *dst++ = 16*a+b;
            src+=3;
        }
        else if (*src == '+')
        {
            *dst++ = ' ';
            src++;
        }
        else
        {
            *dst++ = *src++;
        }
    }
    *dst++ = '\0';
}

int SQLite3ScraperSanatize(std::string &target_string)
{
    target_string.erase(std::remove(target_string.begin(), target_string.end(), '\r'), target_string.end());
    target_string.erase(std::remove(target_string.begin(), target_string.end(), '\n'), target_string.end());
    target_string.erase(std::remove(target_string.begin(), target_string.end(), ' '), target_string.end());
    target_string.erase(std::remove(target_string.begin(), target_string.end(), '\n'), target_string.end());
    target_string.erase(std::remove(target_string.begin(), target_string.end(), '\0'), target_string.end());
    target_string.erase(std::remove(target_string.begin(), target_string.end(), ';'), target_string.end());

    // remove unprintable characters
    target_string.erase(std::remove_if(target_string.begin(), target_string.end(), 
        [](unsigned char c)
        {
            return !std::isprint(c);
        })
        , target_string.end());

    // decode uri unicode
    char output[target_string.size()];

    urldecode(output, target_string.c_str());

    target_string = std::string(output);

    return 0;
}

} // namespace scraper_sanatizer
