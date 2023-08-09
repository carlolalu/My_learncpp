/*
Question #3

Let’s create a random monster generator. This one should be fun.

a) First, let’s create an enumeration of monster types named MonsterType. Include the following monster types: 
Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. Add an additional max_monster_types enum so we can count 
how many enumerators there are.

b) Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables): a type (MonsterType), 
a name (std::string), a roar (std::string), and the number of hit points (int). Create a Monster class that has these 
4 member variables.

c) enum MonsterType is specific to Monster, so move the enum inside the class as a public declaration. When the enum is 
inside the class, “MonsterType” can be renamed “Type” since the context is already Monster. We also can make it a normal 
enum rather than an enum class since the enumerators will be contained in the scope of Monster.

d) Create a constructor that allows you to initialize all of the member variables.

The following program should compile:

int main()
{
	Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };

	return 0;
}

e) Now we want to be able to print our monster so we can validate it’s correct. To do that, we’re going to need to write 
a function that converts a Monster::Type into a string. Write that function (called getTypeString()), as well as a print() 
member function.

The following program should compile:

int main()
{
	Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	return 0;
}

and print:

Bones the skeleton has 4 hit points and says *rattle*



f) Now we can create a random monster generator. Let’s consider how our monster generator will work. Ideally, we’ll ask it to 
give us a Monster, and it will create a random one for us. We don’t need more than one monster generator, and we are not 
maintaining any state, so this is a good candidate for a namespace. Create a namespace named MonsterGenerator. Create a 
function named generate() that returns a Monster. For now, make it return anonymous Monster { Monster::Type::skeleton, 
"Bones", "*rattle*", 4 };

The following program should compile:

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}

and print:

Bones the skeleton has 4 hit points and says *rattle*

f) Now we can create a random monster generator. Let’s consider how our monster generator will work. Ideally, we’ll ask 
it to give us a Monster, and it will create a random one for us. We don’t need more than one monster generator, and we 
are not maintaining any state, so this is a good candidate for a namespace. Create a namespace named MonsterGenerator. 
Create a function named generate() that returns a Monster. For now, make it return anonymous Monster { Monster::Type::skeleton, 
"Bones", "*rattle*", 4 };

The following program should compile:

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}

and print:

Bones the skeleton has 4 hit points and says *rattle*

g) Now, MonsterGenerator needs to generate some random attributes. To do that, first copy and save the “Random.h” header 
from lesson 7.20 -- Generating random numbers using Mersenne Twister to your project.

Modify the function generate() from the prior quiz to generate a random Monster::Type (between 0 and 
Monster::Type::max_monster_types-1) and a random hit points (between 1 and 100). This should be fairly straightforward.

Once you’ve done that, define two static fixed arrays of size 6 inside the function (named s_names and s_roars) and initialize 
them with 6 names and 6 sounds of your choice. Pick a random name and roar from these arrays.

Hint: Our array index needs to be of type std::size_t, so use Random::get<std::size_t>(min, max) to get a random number of type 
std::size_t. min and max can be of different types (e.g. min can be int and max can be std::size_t.

The following program should compile:

#include "Random.h"

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
*/

#include<iostream>
#include<random>
#include "Random.h"

class Monster
{
public:
    enum Type
    {
        dragon, 
        goblin, 
        ogre, 
        orc, 
        skeleton, 
        troll, 
        vampire,
        zombie,

        max_monster_types
    };

    Monster(Monster::Type monster_type=Monster::vampire, std::string name="Mr. Smith", std::string roar="grrrrr", int hit_points=5)
    : m_type{monster_type}, m_name{name}, m_roar{roar}, m_hit_points{hit_points}
    {}

    void print()
    {
        std::cout << m_name << " the " << this->getTypeString() << " has " << m_hit_points << " hit points and says " << m_roar << '\n';
    }

    static std::string getName()
    {
        constexpr std::size_t lenght {6};
        return s_names[Random::get<std::size_t>(0,lenght-1)];
    }

    static std::string getRoar()
    {
        constexpr std::size_t lenght {6};
        return s_roars[Random::get<std::size_t>(0,lenght-1)];
    }


private:
    Monster::Type m_type {Monster::vampire};
    std::string m_name {"Mr. Smith"};
    std::string m_roar {"grrrrr"};
    int m_hit_points{5};

    static std::string s_names[];
    static std::string s_roars[];

    std::string getTypeString()
    {
        switch(m_type)
        {
            case Monster::dragon: return "dragon";
            case Monster::goblin: return "goblin";
            case Monster::ogre: return "ogre";
            case Monster::orc: return "orc";
            case Monster::skeleton: return "skeleton";
            case Monster::troll: return "troll";
            case Monster::vampire: return "vampire";
            case Monster::zombie: return "zombie";
            default: return "?";
        }
    }

};

std::string Monster::s_names[] = {"Bob", "Blob", "France", "Lazze", "Crawboard", "Morgoth" };
std::string Monster::s_roars[] = {"grrrr", "*rattle*", "bubaaaaaaaaa", "bbrrrraaains", "grumbleeee", "arrrrr" };


namespace MonsterGenerator
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution random_type{ 0, static_cast<int>(Monster::max_monster_types-1) };

    constexpr int max_hit_points {100};
    std::uniform_int_distribution random_hitpoints{0, max_hit_points};
    
    Monster generate()
    {
        return Monster{static_cast<Monster::Type>(random_type(mt)), Monster::getName(), Monster::getRoar(), random_hitpoints(mt)};
    }
}


// Hint: Our array index needs to be of type std::size_t, so use Random::get<std::size_t>(min, max) to get a random number of type 
// std::size_t. min and max can be of different types (e.g. min can be int and max can be std::size_t.

#include "Random.h"

int main(void)
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}