#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

#include <cstddef>
#include "graph.h"
#include "cell_array.h"

class Maze :public CellArray, public Graph
{
    using Graph::vertex;
    size_t n;

    vertex start{};
    vertex stop{};

    void init();
public:
    explicit Maze(size_t n) : n(n), CellArray(n), Graph(n * n) { init(); }
    vertex getStart() const;
    vertex getStop() const;
};


#endif //MAZE_MAZE_H
