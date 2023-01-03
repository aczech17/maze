#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

#include <cstddef>
#include "graph.h"
#include "cell_array.h"
#include <utility>

class Maze :public CellArray, private Graph
{
    using Graph::vertex;

    vertex start{};
    vertex stop{};

    void init();
    double get_path_length(std::vector<vertex>) const;
public:
    explicit Maze(vertex n) : CellArray(n), Graph(n * n) { init(); }
    vertex get_start() const;
    vertex get_stop() const;
    std::vector<std::pair<std::vector<vertex>, double>> get_all_paths() const;
    std::pair<std::vector<vertex>, double> get_shortest_path_and_length() const;
};


#endif //MAZE_MAZE_H
