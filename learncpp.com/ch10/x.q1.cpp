/*
Question #1

In designing a game, we decide we want to have monsters, because everyone 
likes fighting monsters. Declare a struct that represents your monster. The monster should have 
a type that can be one of the following: an ogre, a dragon, an orc, a giant spider, or a slime. 
Use an enum class for this.

Each individual monster should also have a name (use a std::string or std::string_view), 
as well as an amount of health that represents how much damage they can take before they die. 
Write a function named printMonster() that prints out all of the struct’s members. Instantiate 
an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().

Your program should produce the following output:

This Ogre is named Torg and has 145 health.
This Slime is named Blurp and has 23 health.
*/

#include<iostream>
#include<string_view>

enum class Mon_kind
{
    ogre,
    dragon, 
    orc, 
    giant_spider,
    slime,
};

std::string mon_kind_str(Mon_kind kind)
{
    switch(kind)
    {
        case Mon_kind::ogre: return "ogre";
        case Mon_kind::dragon: return "dragon";
        case Mon_kind::orc: return "orc";
        case Mon_kind::giant_spider: return "giant_spider";
        case Mon_kind::slime: return "slime";
        default: return "???";
    }
}

struct Monster 
{
    std::string name {};
    Mon_kind kind {};
    int total_health {};
};

void print_monster(Monster& monster)
{
    std::cout << "This " << mon_kind_str(monster.kind) << " is named " << monster.name << " and has "
              << monster.total_health << " health\n";
}

int main(void)
{

    /*This Ogre is named Torg and has 145 health.
This Slime is named Blurp and has 23 health.*/
    Monster torg {"Torg", Mon_kind::ogre, 145};
    Monster blurp {"Blurp", Mon_kind::slime, 23};
    print_monster(torg);
    print_monster(blurp);

    return 0;
}