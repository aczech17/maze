#include "maze.h"
#include "randomizer.h"
#include <algorithm>
#include <vector>

#include <iostream>

void Maze::init()
{
    for (Vertex row = 0; row < n; row++)
        for (Vertex col = 0; col < n; col++)
        {
            Vertex index = row * (Vertex)(n) + col;

            // left, right, down and up

            // LEFT -> THIS
            if (getRight(row, col - 1))
            {
                Vertex left_index = index - 1;
                double weight = 0.5 * (getValue(row, col - 1) + getValue(row, col));

                // from this to left
                add_edge(index, left_index, weight);
            }

            // THIS -> RIGHT
            if (getRight(row, col))
            {
                Vertex right_index = index + 1;
                double weight = 0.5 * (getValue(row, col) + getValue(row, col + 1));

                // from this to right
                add_edge(index, right_index, weight);
            }

            // THIS
            //   |
            //   V
            // DOWN
            if (getDown(row, col))
            {
                Vertex down_index = (row + 1) * (Vertex)(n) + col;
                double weight = 0.5 * (getValue(row, col) + getValue(row + 1, col));

                // from this to down
                add_edge(index, down_index, weight);
            }

            // UP
            // A
            // |
            // THIS

            if (getDown(row - 1, col))
            {
                Vertex up_index = (row - 1) * (Vertex)(n) + col;
                double weight = 0.5 * (getValue(row, col) + getValue(row - 1, col));

                // from this to up
                add_edge(index, up_index, weight);
            }
        }

    Randomizer randomizer;
    Vertex start_row = 0;
    auto stop_row = static_cast<Vertex>(n - 1);

    Vertex start_col = randomizer.get_int(0, Vertex(n - 1));
    Vertex stop_col = randomizer.get_int(0, Vertex(n - 1));

    start = static_cast<Vertex>(start_row * n + start_col);
    stop = static_cast<Vertex>(stop_row * n + stop_col);
}

CellArray::vertex Maze::get_start() const
{
    return start;
}

CellArray::vertex Maze::get_stop() const
{
    return stop;
}

double Maze::get_path_length(Graph::Path path) const
{
    double sum = 0.0;
    for (auto v = path.begin(); v < path.end() - 1; v++)
    {
        sum += get_weight(*v, *(v + 1));
    }
    return sum;
}


std::vector<std::pair<Graph::Path, double>> Maze::get_all_paths() const
{
    std::vector<std::pair<std::vector<Graph::Vertex>, double>> pairs; // pairs (Path, length_of_path)

    auto paths = Graph::get_all_paths(start, stop);
    for (const auto& path: paths)
    {
        auto pair = std::make_pair(path, get_path_length(path));
        pairs.push_back(pair);
    }
    return pairs;
}

std::pair<Graph::Path, double> Maze::get_shortest_path_and_length() const
{
    typedef std::vector<Graph::Vertex> path;

    auto paths = get_all_paths();


    auto shortest_path_and_length = std::min_element(
            paths.begin(), paths.end(), // go through all the pairs

            // Find the pair with the shortest length.
    [](const std::pair<path, double>& path1, const std::pair<path, double>& path2) -> bool
    {
       double length1 = path1.second;
       double length2 = path2.second;
       return length1 < length2;
    });

    return *shortest_path_and_length;
}


std::string Maze::get_all_crosings() const
{
    std::string picture;
    const wchar_t block = L'X'; // ?

    for (auto row = 0; row < n; row++)
    {
        for (auto col = 0; col < n; col++)
        {
            if (getRight(row, col)) // this -> right
            {
                picture += std::to_string(row * n + col) + " -> " + std::to_string(row * n + col + 1) + "\n";
            }

            if (getDown(row, col)) // this -> down
            {
                picture += std::to_string(row * n + col) + " -> " + std::to_string((row + 1) * n + col) + "\n";
            }
        }
    }

    return picture;
}
