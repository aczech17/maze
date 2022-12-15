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

double path_length(const Graph& g, const std::vector<Graph::vertex>& path)
{
    double sum = 0;
    for (auto i = path.begin(); i < path.end() - 1; i++)
    {
        sum += g.get_weight(*i, *(i + 1));
    }

    return sum;
}

int main()
{
    /*Graph g({
            {-1, 1, 1, -1},
            {1, -1, -1, 1},
            {-1, -1, -1, 1},
            {-1, -1, 1, -1}
    });*/


    Maze g(3);
    std::cout << "START: " << g.getStart() << " STOP: " << g.getStop() << "\n";

    auto paths = g.get_all_paths(g.getStart(), g.getStop());
    std::cout << "Jest " << paths.size() << " drog\n\n";

    for (const auto& path: paths)
    {
        print_path(path);
        std::cout << path_length(g, path) << "\n\n";
    }
}
