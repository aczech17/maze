#include "graph.h"
#include <algorithm>

#include <iostream>

Graph::Graph(size_t n)
{
    for (vertex row = 0; row < (vertex)n; row++)
    {
        std::vector<double> new_row;
        for (vertex col = 0; col < (vertex)n; col++)
        {
            new_row.push_back(-1);
        }
        arr.push_back(new_row);
    }
}

double Graph::get_weight(Graph::vertex v1, Graph::vertex v2) const
{
    return arr[v1][v2];
}

void Graph::add_edge(Graph::vertex v1, Graph::vertex v2, double weight)
{
    arr[v1][v2] = weight;
}

size_t Graph::get_vertex_n() const
{
    return arr.size();
}

void Graph::traverse(Graph::vertex src, Graph::vertex dest)
{
    auto n = static_cast<vertex>(get_vertex_n());
    current_path.push_back(src);
    if (src == dest)
        paths.push_back(current_path);

    else for (vertex v = 0; v < n; v++)
        if (arr[src][v] >= 0) // for all neighbors
        {
            // if v vertex is present in current path, then it's been already visited
            bool visited = !(std::find(current_path.begin(), current_path.end(), v) == current_path.end());

            if (!visited)
                traverse(v, dest);
    }

    current_path.pop_back();
}

std::vector<std::vector<Graph::vertex>> Graph::get_all_paths(Graph::vertex src, Graph::vertex dest)
{
    traverse(src, dest);
    current_path.clear();

    auto result = std::move(paths);
    return result;
}
