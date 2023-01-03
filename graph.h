#ifndef MAZE_GRAPH_H
#define MAZE_GRAPH_H

#include <vector>
#include <cstdint>
#include <cstddef>

class Graph
{
public:
    typedef int64_t vertex;
    typedef std::vector<vertex> Path;

private:
    std::vector<std::vector<double>> arr;

    //std::vector<std::vector<vertex>> paths;
    //std::vector<vertex> current_path;
    void traverse(vertex src, vertex dest, Path &current_path, std::vector<Path> &paths) const;

protected:
    void add_edge(vertex v1, vertex v2, double weight);

public:
    Graph() = default;
    explicit Graph(size_t n);
    explicit Graph(const std::vector<std::vector<double>>& arr) : arr(arr) {}
    [[nodiscard]] double get_weight(vertex v1, vertex v2) const;
    [[nodiscard]] size_t get_vertex_n() const;

    [[nodiscard]] std::vector<Path> get_all_paths(vertex v1, vertex v2) const;
};

#endif //MAZE_GRAPH_H
