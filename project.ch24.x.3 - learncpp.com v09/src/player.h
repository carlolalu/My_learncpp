#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"
#include "monster.h"
#include "potion.h"


class Player : public Creature
{
public:
    Player(std::string name) : Creature{name, '@', 10, 1, 0}, m_level{1}
    {}

    int getLevel() const;

    void levelUp();
    bool hasWon() const;
    void drink();
    void attackMonster(Monster& monster);
    bool fightNewMonster();
    void handlePotion();
    void drink(const Potion& potion);

    friend std::ostream& operator << (std::ostream& out, const Player& player);

private:
    int m_level{1};
};

#endif