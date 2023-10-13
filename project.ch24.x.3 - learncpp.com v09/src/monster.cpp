#include "monster.h"

#include "player.h"


Monster Monster::getRandomMonster()
{
    int random_number = Random::get(0, static_cast<int>(Monster::Type::max_types)-1);
    return Monster(static_cast<Monster::Type>(random_number));
}

void Monster::attackPlayer(Player& player) const
{
    player.reduceHealth(this->getDamage());
    std::cout << "The " << this->getName() << " hit you for " << this->getDamage() << " damage.\n";
    std::cout << "You have now " << player.getHealth() << " health points.\n";
}