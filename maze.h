#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

#include <cstddef>
#include "graph.h"
#include "cell_array.h"
#include <utility>

class Maze :public CellArray, private Graph
{
    using Graph::vertex;
    size_t n;

    vertex start{};
    vertex stop{};

    void init();
    double get_path_length(std::vector<vertex>);
public:
    explicit Maze(size_t n) : n(n), CellArray(n), Graph(n * n) { init(); }
    vertex get_start() const;
    vertex get_stop() const;
    std::vector<std::pair<std::vector<vertex>, double>> get_all_paths();
};


#endif //MAZE_MAZE_H
