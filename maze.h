#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

#include <cstddef>
#include "graph.h"
#include "cell_array.h"
#include <utility>
#include <string>

class Maze :public CellArray, private Graph
{
    using Graph::Vertex;

    Vertex start{};
    Vertex stop{};

    void init();
    double get_path_length(Graph::Path) const;
public:
    explicit Maze(Vertex n) : CellArray(n), Graph(n * n) { init(); }
    Vertex get_start() const;
    Vertex get_stop() const;
    std::vector<std::pair<Graph::Path, double>> get_all_paths() const;
    std::pair<Graph::Path, double> get_shortest_path_and_length() const;
    std::string draw() const;
};


#endif //MAZE_MAZE_H
