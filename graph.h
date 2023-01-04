#ifndef MAZE_GRAPH_H
#define MAZE_GRAPH_H

#include <vector>
#include <cstdint>
#include <cstddef>

class Graph
{
public:
    typedef int64_t Vertex;
    typedef std::vector<Vertex> Path;

private:
    std::vector<std::vector<double>> arr;

    //std::vector<std::vector<Vertex>> paths;
    //std::vector<Vertex> current_path;
    void traverse(Vertex src, Vertex dest, Path &current_path, std::vector<Path> &paths) const;

protected:
    void add_edge(Vertex v1, Vertex v2, double weight);

public:
    Graph() = default;
    explicit Graph(size_t n);
    explicit Graph(const std::vector<std::vector<double>>& arr) : arr(arr) {}
    [[nodiscard]] double get_weight(Vertex v1, Vertex v2) const;
    [[nodiscard]] size_t get_vertex_n() const;

    [[nodiscard]] std::vector<Path> get_all_paths(Vertex v1, Vertex v2) const;
};

#endif //MAZE_GRAPH_H
