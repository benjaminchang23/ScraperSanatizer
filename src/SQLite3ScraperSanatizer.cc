/**
 * SQLite3ScraperSanatizer.cc
 */

#include <algorithm>

#include <SQLite3ScraperSanatizer.hh>

namespace scraper_sanatizer {

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

    return 0;
}

} // namespace scraper_sanatizer
