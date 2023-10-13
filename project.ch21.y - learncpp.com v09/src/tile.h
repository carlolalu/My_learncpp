#ifndef TILE_H
#define TILE_H

#include<iostream>


class Tile
{
public:
    Tile(const int value = 0) : m_value {value}
    {}

    int getNum() const;

    friend std::ostream& operator<<(std::ostream& out, const Tile& tile);

    bool isEmpty() const;

private:
    int m_value {};

};

bool operator==(const Tile& tile1, const Tile& tile2);





#endif