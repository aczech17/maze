#include "maze.h"
#include "randomizer.h"
#include <algorithm>

void Maze::init()
{
    for (vertex row = 0; row < n; row++)
        for (vertex col = 0; col < n; col++)
        {
            vertex index = row * (vertex)(n) + col;

            // left, right and down

            // LEFT -> THIS
            if (getRight(row, col - 1))
            {
                vertex left_index = index - 1;
                double weight = 0.5 * (getValue(row, col - 1) + getValue(row, col));

                // from this to left
                add_edge(index, left_index, weight);
            }

            // THIS -> RIGHT
            if (getRight(row, col))
            {
                vertex right_index = index + 1;
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
                vertex down_index = (row + 1) * (vertex)(n) + col;
                double weight = 0.5 * (getValue(row, col) + getValue(row + 1, col));

                // from this to down
                add_edge(index, down_index, weight);
            }
        }

    Randomizer randomizer;
    vertex start_row = 0;
    auto stop_row = static_cast<vertex>(n - 1);

    vertex start_col = randomizer.get_int(0, vertex(n - 1));
    vertex stop_col = randomizer.get_int(0, vertex(n - 1));

    start = static_cast<vertex>(start_row * n + start_col);
    stop = static_cast<vertex>(stop_row * n + stop_col);
}

CellArray::vertex Maze::get_start() const
{
    return start;
}

CellArray::vertex Maze::get_stop() const
{
    return stop;
}

double Maze::get_path_length(std::vector<vertex> path)
{
    double sum = 0.0;
    for (auto v = path.begin(); v < path.end() - 1; v++)
    {
        sum += get_weight(*v, *(v + 1));
    }
    return sum;
}


std::vector<std::pair<std::vector<Graph::vertex>, double>> Maze::get_all_paths()
{
    std::vector<std::pair<std::vector<Graph::vertex>, double>> pairs;

    auto paths = Graph::get_all_paths(start, stop);
    for (const auto& path: paths)
    {
        auto pair = std::make_pair(path, get_path_length(path));
        pairs.push_back(pair);
    }
    return pairs;
}

std::pair<std::vector<Graph::vertex>, double> Maze::get_shortest_path_and_length()
{
    typedef std::vector<Graph::vertex> path;

    auto paths = get_all_paths();
    auto shortest_path_and_length = std::min_element(paths.begin(), paths.end(),
    [](const std::pair<path, double>& path1, const std::pair<path, double>& path2)
    {
       double length1 = path1.second;
       double length2 = path2.second;
       return length1 < length2;
    });

    return *shortest_path_and_length;
}

