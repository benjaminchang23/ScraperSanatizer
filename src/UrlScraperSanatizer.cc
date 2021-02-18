/**
 * UrlScraperSanatizer.cc
 */

#include <algorithm>

#include <UrlScraperSanatizer.hh>

namespace scraper_sanatizer {

int UrlScraperSanatize(std::string &target_string)
{
    target_string.erase(std::remove(target_string.begin(), target_string.end(), '\r'), target_string.end());

    return 0;
}

} // namespace scraper_sanatizer
