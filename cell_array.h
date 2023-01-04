#ifndef MAZE_CELL_ARRAY_H
#define MAZE_CELL_ARRAY_H

#include <vector>
#include "graph.h"

class CellArray
{
protected:
    typedef Graph::Vertex vertex;

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
    bool getRight(vertex row, vertex col) const;
    bool getDown(vertex row, vertex col) const;
    double getValue(vertex row, vertex col) const;
};


#endif //MAZE_CELL_ARRAY_H
