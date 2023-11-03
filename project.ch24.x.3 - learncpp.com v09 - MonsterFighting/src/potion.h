#ifndef MY_LEARNCPP_POTION_H
#define MY_LEARNCPP_POTION_H

#include <array>
#include <iostream>

#include "random.h"

class Potion
{
public:
    enum class Size
    {
        small,
        medium,
        large,

        max_sizes
    };

    enum class Type
    {
        health,
        strenght,

        poison,
        weakening,

        max_types
    };

    Potion(Size size, Type type) : m_size{size}, m_type{type}
    {}

    std::string_view getSize() const;
    std::string_view getType() const;

    int getHealthEffect() const;
    int getDamageEffect() const;

    static Potion getRandomPotion();

    friend std::ostream& operator << (std::ostream& out, const Potion& potion);


private:

    Size m_size {Size::small};
    Type m_type {Type::health};

    static constexpr std::size_t max_effect_types{2};
    static constexpr std::array< std::array<int, max_effect_types>, static_cast<std::size_t>(Type::max_types)> effects {
            {   {1, 0},
                {0, 1},
                {-1, 0},
                {0, -1}    }    };
};



#endif //MY_LEARNCPP_POTION_H
