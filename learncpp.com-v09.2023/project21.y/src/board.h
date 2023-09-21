#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <algorithm>

#include "tile.h"
#include "point.h" // which includes direction

#include "konstants.h"
#include "random.h"


class Board
{
public:
    Board() = default;

    void randomMove();

    void randomise();

    // you can give an integer as an argument
    Point getPosition(const Tile& tile) const;

    Tile& operator()(const Point& point);

    Board& move0(const Direction& direction);

    friend std::ostream& operator<<(std::ostream& out, const Board& board);

    friend bool operator==(const Board& board1, const Board& board2);

private:
    Tile m_grid[g_size][g_size] {
            Tile{ 1 }, Tile { 2 }, Tile { 3 } , Tile { 4 },
            Tile { 5 } , Tile { 6 }, Tile { 7 }, Tile { 8 },
            Tile { 9 }, Tile { 10 }, Tile { 11 }, Tile { 12 },
            Tile { 13 }, Tile { 14 }, Tile { 15 }, Tile { 0 } };
};

#endif