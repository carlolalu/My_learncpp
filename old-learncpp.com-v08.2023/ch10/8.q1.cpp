/* '''
Question #1

You are running a website, and you are trying to keep track of how much money 
you make per day from advertising. Declare an advertising struct that keeps 
track of how many ads you’ve shown to readers, what percentage of ads were 
clicked on by users, and how much you earned on average from each ad that was 
clicked. Read in values for each of these fields from the user. Pass the 
advertising struct to a function that prints each of the values, and then 
calculates how much you made for that day (multiply all 3 fields together).
*/

#include<iostream>
#include <sstream>

struct AdvertisingDay
{
    int adsNo {};
    double adsWatchedPercentage {};
    double gainPerAd {};
};

std::string printAds(AdvertisingDay& ads)
{
    std::ostringstream out {};
    out << "Of the " << ads.adsNo << " presented ";
    out << ads.adsWatchedPercentage << "% were watched and ";
    out << "for each one I gained " << ads.gainPerAd << " euros";
    return out.str();
}

double gain_for_day(AdvertisingDay& ads)
{
    return ads.gainPerAd * ads.adsWatchedPercentage * ads.adsNo;
}

int main(void)
{
    AdvertisingDay today {};

    std::cout << "How many ads did you publish today?\n";
    std::cin >> today.adsNo;
    std::cout << "\nHow many were watched in percentage?\n";
    std::cin >> today.adsWatchedPercentage;
    std::cout << "\nHow much you gained per ad?\n";
    std::cin >> today.gainPerAd;

    std::cout << "\n\nToday you gained " << gain_for_day(today) << "euros";

    return 0;
}