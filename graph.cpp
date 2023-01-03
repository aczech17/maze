#include "graph.h"
#include <algorithm>

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

void Graph::traverse(Graph::vertex src, Graph::vertex dest, Path& current_path, std::vector<Path>& paths) const
{
    auto n = static_cast<vertex>(get_vertex_n());
    current_path.push_back(src);
    if (src == dest)
        paths.push_back(current_path);

    else for (vertex v = 0; v < n; v++)
        if (arr[src][v] >= 0) // for all neighbors
        {
            // if v vertex is present in current Path, then it's been already visited
            bool visited = !(std::find(current_path.begin(), current_path.end(), v) == current_path.end());

            if (!visited)
                traverse(v, dest, current_path, paths);
    }

    current_path.pop_back();
}

std::vector<Graph::Path> Graph::get_all_paths(Graph::vertex src, Graph::vertex dest) const
{
    // Pass them through all the recursive calls.
    Path current_path;
    std::vector<Path> paths;
    // ***

    traverse(src, dest, current_path, paths);

    auto result = std::move(paths);
    return result;
}
