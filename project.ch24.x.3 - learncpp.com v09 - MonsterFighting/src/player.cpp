
#include "player.h"

#include "user_input.h"


int Player::getLevel() const
{
    return m_level;
}

void Player::levelUp()
{
    ++m_level;
    ++m_damage;
}

bool Player::hasWon() const
{
    return m_level>=20;
}

void Player::attackMonster(Monster& monster)
{
    monster.reduceHealth(this->getDamage());
    std::cout << "You hit the " << monster.getName()<< " for " << this->getDamage() << " damage.\n";

    if (monster.isDead()) {
        this->levelUp();
        this->addGold(monster.getGold());
        std::cout << "You killed the " << monster.getName() << " and you found " << monster.getGold() << " gold coins on his corpse.\n";
        std::cout << "You are now at level " << this->getLevel() << ".\n";
        return;
    } else {
        monster.attackPlayer(*this);
    }
}

bool Player::fightNewMonster()
{
    Monster monster { Monster::getRandomMonster() };
    std::cout << "You have encountered a " << monster.getName() << "(" << monster.getSymbol() << ")\n";

    char command {};

    do {
        std::cout << "(R)un or (F)ight: ";
        command = UserInput::getValidatedInput();
        if (command == 'f')
        {
            this->attackMonster(monster);
        } else {
            int flee_result {Random::get(0,1)};

            if (flee_result)
            {
                std::cout << "You successfully fled.\n";
                break;
            } else {
                std::cout << "You failed to flee.\n";
                monster.attackPlayer(*this);
            }
        }

    } while ( !monster.isDead() && !(this->isDead()) );

    if( monster.isDead() ){
        return true;
    } else { return false; }
}


void Player::handlePotion()
{
    if(this->isDead())
    { return; }

    int potion_odds {Random::get(-1, 1)};

    // the player founds a potion only in the 33% of cases
    if(potion_odds==1)
    {
        Potion potion {Potion::getRandomPotion()};
        std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
        char command {UserInput::getValidatedYesNoInput()};

        if(command=='y')
        {
            this->drink(potion);
        }
    }
}

void Player::drink(const Potion& potion)
{
    std::cout << "You drank a " << potion << '\n';
    this->m_health += potion.getHealthEffect();
    this->m_damage += potion.getDamageEffect();
}


std::ostream& operator <<(std::ostream& out, const Player& player)
{
    out << "You have " << player.getHealth() << " health, " << player.getDamage() << " damage and you are carrying " << player.getGold() << " gold.";
    return out;
}