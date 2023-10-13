#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

#include "random.h"

class Creature
{
public:
    Creature(std::string name, char symbol, int health=1, int damage=1, int gold=0)
    : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold{gold}
    {}

    std::string getName() const;
    char getSymbol() const;
    int getHealth() const;
    int getDamage() const;
    int getGold() const;

    void reduceHealth(int damage);
    bool isDead() const;
    void addGold(int amount);

protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};
};


#endif