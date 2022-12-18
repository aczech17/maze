#include <iostream>
#include "graph.h"
#include <algorithm>

#include "maze.h"

void print_path(const std::vector<Graph::vertex>& path)
{
    for (const auto& vertex: path)
    {
        std::cout << vertex << " ";
    }
    std::cout << "\n";
}

int main()
{
    /*Graph g({
            {-1, 1, 1, -1},
            {1, -1, -1, 1},
            {-1, -1, -1, 1},
            {-1, -1, 1, -1}
    });*/


    Maze g(5);
    std::cout << "START: " << g.get_start() << " STOP: " << g.get_stop() << "\n";

    auto paths = g.get_all_paths();
    std::cout << "Jest " << paths.size() << " drog\n\n";

    for (const auto& path: paths)
    {
        auto vertices = path.first;
        double length = path.second;

        print_path(vertices);
        std::cout << length << "\n\n";
    }
}
