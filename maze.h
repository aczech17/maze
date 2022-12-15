#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

#include <cstddef>
#include "graph.h"
#include "cell_array.h"

class Maze :public CellArray
{
    size_t n;
    Graph graph;

    vertex start{};
    vertex stop{};

    void init();
public:
    explicit Maze(size_t n) : n(n), CellArray(n), graph(n * n) { init(); }
    vertex getStart() const;
    vertex getStop() const;
};


#endif //MAZE_MAZE_H
