#ifndef MAZE_GRAPH_H
#define MAZE_GRAPH_H

#include <vector>
#include <cstdint>

class Graph
{
public:
    typedef int64_t vertex;

private:
    size_t vertex_n;
    std::vector<std::vector<double>> arr;

    std::vector<std::vector<vertex>> paths;
    std::vector<vertex> current_path;

    void bfs(vertex src, vertex dest);

protected:

    void add_edge(vertex v1, vertex v2, double weight);

public:
    Graph() : vertex_n(0) {}
    explicit Graph(size_t n);
    explicit Graph(const std::vector<std::vector<double>>& arr) : arr(arr)
    {
        vertex_n = arr.size();
    }
    [[nodiscard]] double get_weight(vertex v1, vertex v2) const;
    [[nodiscard]] size_t get_vertex_n() const;

    std::vector<std::vector<vertex>> get_all_paths(vertex v1, vertex v2);
};

#endif //MAZE_GRAPH_H
