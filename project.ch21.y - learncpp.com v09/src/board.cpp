#include"board.h"

void Board::randomMove()
{
    this->move0(Direction::getRandom());
}

void Board::randomise()
{
    for(int index{}; index<100; ++index)
    {
        this->randomMove();
    }
}

Point Board::getPosition(const Tile& tile) const
{
    // bad practice, but not avoidable easily: we used `int` for the class Point, and not std::size_t
    int size { static_cast<int>(g_size) };
    // linear search because the board is not ordered and we used a C-array rather than a std::array
    for(int row_index{}; row_index < size; ++row_index)
    {
        for(int column_index{}; column_index< size; ++column_index)
        {
            if(m_grid[row_index][column_index]==tile){
                // note that we must invert the column and row index!
                // (matrix indices are inverted wrt cartesian coordinates)
                return {column_index, row_index};
            }
        }
    }
    return {-1,-1};     //will never happen
}

Tile& Board::operator()(const Point& point)
{
    // notice: we need to invert the indices between the cartesian and the matrix indexing
    return m_grid[point.getY()][point.getX()];
}

Board& Board::move0(const Direction& direction)
{
    Point zero_tile_position { this->getPosition(0) };
    Point adiacent_position { zero_tile_position.getAdjacentPoint(direction) };

    if(adiacent_position.isOnBoard()){
        std::swap( this->operator()(zero_tile_position), this->operator()(adiacent_position));
    }

    return *this;
}


std::ostream& operator<<(std::ostream& out, const Board& board)
{
    for(int line{}; line < Konstants::g_consoleLines; ++line)
    {
        out << '\n';
    }

    for(std::size_t index_r{}; index_r < g_size; ++index_r)
    {
        for(std::size_t index_c{}; index_c < g_size; ++index_c)
        {
            out << board.m_grid[index_r][index_c];
        }
        out << '\n';
    }
    return out;
}


bool operator==(const Board& board1, const Board& board2)
{
    for(std::size_t index_r{}; index_r < g_size; ++index_r)
    {
        for(std::size_t index_c{}; index_c < g_size; ++index_c)
        {
            if( board1.m_grid[index_r][index_c] != board2.m_grid[index_r][index_c] ) {
                return false;
            }
        }
    }
    return true;
}