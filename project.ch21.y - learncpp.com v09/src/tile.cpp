#include "tile.h"


int Tile::getNum() const
{
    return m_value;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
    if (tile.m_value > 9){
        out << " " << tile.m_value << " ";
    } else if (tile.m_value > 0) {
        out << "  " << tile.m_value << " ";
    } else if (tile.m_value == 0) {
        out << "    ";
    }
    return out;
}



bool Tile::isEmpty() const
{
    return m_value==0;
}

bool operator==(const Tile& tile1, const Tile& tile2)
{
    return tile1.getNum()==tile2.getNum();
}


