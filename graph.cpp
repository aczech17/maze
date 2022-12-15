#include "graph.h"
#include <algorithm>

#include <iostream>

Graph::Graph(size_t n)
{
    vertex_n = n;

    for (vertex row = 0; row < n; row++)
    {
        std::vector<double> new_row;
        for (vertex col = 0; col < n; col++)
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
    //std::cout << "Dodajemy edge " << v1 << "->" << v2 << "\n";
    arr[v1][v2] = weight;
}

size_t Graph::get_vertex_n() const
{
    return arr.size();
}

void Graph::bfs(Graph::vertex src, Graph::vertex dest)
{
    //std::cout << src << "\n";
    size_t n = get_vertex_n();
    current_path.push_back(src);
    if (src == dest)
        paths.push_back(current_path);

    for (vertex i = 0; i < n; i++)
    {
        //std::cout << "i = " << i << "\n";
        if (i == src)
            continue;

        if (arr[src][i] < 0) // not a neighbor of src
            continue;


        bool visited = !(std::find(current_path.begin(), current_path.end(), i) == current_path.end());
        if (visited)
            continue;

        bfs(i, dest);

    }

    current_path.pop_back();
}

std::vector<std::vector<Graph::vertex>> Graph::get_all_paths(Graph::vertex src, Graph::vertex dest)
{
    bfs(src, dest);

    current_path.clear();

    auto result = paths;
    paths.clear();

    return result;
}
