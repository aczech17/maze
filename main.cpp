#include <iostream>
#include "graph.h"
#include <algorithm>

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

    Graph g({
            {-1, 5, 5, 5},
            {-1, -1, -1, 5},
            {5, 5, -1, -1},
            {-1, -1, -1, -1}
    });

    auto paths = g.get_all_paths(2, 3);

    for (const auto& path: paths)
    {
        print_path(path);
        std::cout << path_length(g, path) << "\n\n";
    }
}
