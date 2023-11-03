#include "potion.h"

std::string_view Potion::getSize() const
{
    switch(static_cast<int>(this->m_size))
    {
        case(0): return "small";
        case(1): return "medium";
        case(2): return "large";

        default: return "wtf???";
    }
}

std::string_view Potion::getType() const
{
    switch(static_cast<int>(this->m_type))
    {
        case(0): return "health";
        case(1): return "strenght";
        case(2): return "poison";
        case(3): return "weakening";

        default: return "wtf???";
    }
}

int Potion::getHealthEffect() const
{
    // enum Size starts to count from 0
    return ( effects.at( static_cast<std::size_t>(m_type) ).at(0) ) * (static_cast<int>(m_size) + 1);
}

int Potion::getDamageEffect() const
{
    // enum Size starts to count from 0
    return ( effects.at( static_cast<std::size_t>(m_type) ).at(1) ) * (static_cast<int>(m_size) + 1);
}

Potion Potion::getRandomPotion()
{
    int size {Random::get(0, static_cast<int>(Size::max_sizes))};
    int type {Random::get(0, static_cast<int>(Type::max_types))};

    return Potion{static_cast<Potion::Size>(size), static_cast<Potion::Type>(type)};
}

std::ostream& operator << (std::ostream& out, const Potion& potion)
{
    out << "potion of type " << potion.getType() << " and size " << potion.getSize()
    << " (" << potion.getDamageEffect() << " effect on damage and " << potion.getHealthEffect() << " on health)";
    return out;
}

