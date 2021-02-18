/**
 * SQLite3ScraperSanatizer.cc
 */

#include <algorithm>

#include <SQLite3ScraperSanatizer.hh>

namespace scraper_sanatizer {

int SQLite3ScraperSanatize(std::string &target_string)
{
    target_string.erase(std::remove(target_string.begin(), target_string.end(), '\r'), target_string.end());

    return 0;
}

} // namespace scraper_sanatizer
