#ifndef MAZE_CELL_ARRAY_H
#define MAZE_CELL_ARRAY_H

#include <vector>
#include "graph.h"

class CellArray
{
protected:
    typedef Graph::vertex vertex;

private:
    struct Cell
    {
        bool right;
        bool down;
        double value;

        Cell(bool right, bool down, double value) : right(right), down(down), value(value)
        {}
    };

protected:
    vertex n;

private:

    std::vector<Cell> cell_arr;

public:
    explicit CellArray(vertex n);
    bool getRight(vertex row, vertex col);
    bool getDown(vertex row, vertex col);
    double getValue(vertex row, vertex col);
};


#endif //MAZE_CELL_ARRAY_H
