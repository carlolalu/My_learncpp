#include "creature.h"



std::string Creature::getName() const
{
    return m_name;
}

char Creature::getSymbol() const
{
    return m_symbol;
}

int Creature::getHealth() const
{
    return m_health;
}

int Creature::getDamage() const
{
    return m_damage;
}

int Creature::getGold() const
{
    return m_gold;
}

void Creature::reduceHealth(int damage)
{
    this->m_health -= damage;
}

bool Creature::isDead() const
{
    return this->m_health <=0;
}

void Creature::addGold(int amount)
{
    m_gold += amount;
}