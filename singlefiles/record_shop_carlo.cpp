/*
    We want to open a rock music shop in the beautiful
    old town of Tuebingen. For this we need a small system
    to catalogue the available record collection in our store.

    Each music album features the following criteria:
    - id number
    - band name
    - album title
    - year of release

    When we open our music shop the first day,
    the following titles are available:

    - 1, "Nickelback", "Dark Horse", 2008
    - 5, "Metallica", "Reload", 2003
    - 11, "Red Hot Chili Peppers", "Californication", 1999
    - 8, "Cake", "Fashion Nugget", 1996
    - 85, "Linkin Park", "Minutes To Midnight", 2007

    We want to present two lists of available myalbums,
    one sorted by "band name" in ascending order and one
    sorted by "year of release" with the latest one first.

    Now we just need a way to manage, sort and output the lists
    in an object oriented way... Carlo, can you help us?

    A console application displaying the sorted lists would be fine.

    Please apply the following design patterns:
    - data enscapsulation
    - iterators

    Just to be sure, don't implement any of this:
    - loading the catalogue from disk
    - database / network access
    - cmdline argument processing

    It's a small program and should take less than two hours.

    Feel free to extend the outdated music catalogue.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <functional>
#include <string_view>

class Album {
    private:
        int id;
        std::string band;
        std::string title;
        int year;
    public:
        Album (int id_given, std::string band_given, std::string title_given, int year_given)
        {
            set_id(id_given);
            set_band(band_given);
            set_title(title_given);
            set_year(year_given);
        }

        void set_id(int id_given)
        {Album::id = id_given;}

        void set_band(std::string band_given)
        {Album::band = band_given;}

        void set_title(std::string title_given)
        {Album::title = title_given;}

        void set_year(int year_given)
        {Album::year = year_given;}

        int get_id(void)
        {return Album::id;}

        std::string get_band(void)
        {return Album::band;}

        std::string get_title(void)
        {return Album::title;}

        int get_year(void)
        {return Album::year;}

        void display()
        {
            std::cout << "(id = " << Album::get_id() << ", band = "<< Album::get_band() << ", title = " << Album::get_title() << ", year of release = " << Album::get_year() <<")"<< std::endl;
        }
};

bool YearReleaseLess(Album a, Album b)
{
    return a.get_year() > b.get_year();
}

bool LexicogrBandLess(Album a, Album b)
{
    return a.get_band().compare(b.get_band())<0;
}

void swap(Album* a, Album* b) {Album tmp=*a; *a=*b; *b=tmp;}


int main(void)
{
    //creation of the myalbums
    Album dark_horse(1, "Nickelback", "Dark Horse", 2008);
    Album reload(5, "Metallica", "Reload", 2003);
    Album californication(11, "Red Hot Chili Peppers", "Californication", 1999);
    Album fashion_nugget(8, "Cake", "Fashion Nugget", 1996);
    Album minutes_to_midnight(85, "Linkin Park", "Minutes To Midnight", 2007);

    //introduction
    std::cout << "\nThis is our original album list:" << "\n\n";

    std::vector <Album> myalbums = {dark_horse, reload, californication, fashion_nugget, minutes_to_midnight};
    std::vector<Album>::iterator ext_iter, inn_iter;

    for(ext_iter = myalbums.begin(); ext_iter !=myalbums.end(); ++ext_iter)
    {
        (*ext_iter).display();
    }

    // my myalbums as well
    Album nevermind(2, "Nirvana", "Nevermind", 1991);
    Album mass_manipulation(3, "Rezz", "Mass Manipulation", 2017);
    Album bar_della_rabbia(4, "Mannarino", "Bar della rabbia", 2009);
    Album cigarettes_after_sex(6, "Cigarettes after sex", "Cigarettes after sex", 2017);
    Album futuro_imperfetto(7, "Punkreas", "Futuro imperfetto", 2008);
    Album bijelo_dugme(13, "Bijelo dugme", "Kad bi bio bijelo dugme", 1974);

    myalbums.insert(myalbums.end(), {nevermind, mass_manipulation, bar_della_rabbia, cigarettes_after_sex, futuro_imperfetto, bijelo_dugme} );

    std::cout << "\nThis is the album list with my additions:" << "\n";


    for(ext_iter = myalbums.begin(); ext_iter !=myalbums.end(); ++ext_iter)
    {
        (*ext_iter).display();
    }

    std::sort(myalbums.begin(), myalbums.end(), YearReleaseLess);

    std::cout << "\nThis is the list ordered according to descending year of release: \n";
    for(ext_iter = myalbums.begin(); ext_iter !=myalbums.end(); ++ext_iter)
    {
        (*ext_iter).display();
    }

    std::sort(myalbums.begin(), myalbums.end(), LexicogrBandLess);
    std::cout << "\nThis is the list ordered according to ascending lexicographic order (according to the band name): \n";
    for(ext_iter = myalbums.begin(); ext_iter !=myalbums.end(); ++ext_iter)
        {
            (*ext_iter).display();
        }

    return 0;
}
