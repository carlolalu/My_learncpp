#ifndef MONSTER_H
#define MONSTER_H

#include <array>

#include "creature.h"
#include "random.h"

class Player;

class Monster : public Creature
{
public:    

    enum class Type
    {
        dragon,
        orc,
        slime,

        max_types
    };

    Monster(Type type) : Creature(getDefaultCreature(type))
    {}

    Monster(const Monster& monster) = default;

    static Monster getRandomMonster();

    void attackPlayer(Player& player) const;

private:
static const Creature& getDefaultCreature(Type type)
{
    static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
    { { "dragon", 'D', 20, 4, 100 },
      { "orc", 'o', 4, 2, 25 },
      { "slime", 's', 1, 1, 10 } }
    };

    return monsterData.at(static_cast<std::size_t>(type));
}

};


#endif