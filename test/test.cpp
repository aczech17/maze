#include <iostream>
#include "../graph.h"
#include <algorithm>

#include "../maze.h"

void print_path(std::vector<Graph::vertex>& path)
{
    for (const auto& vertex: path)
    {
        std::cout << vertex << " ";
    }
    std::cout << "\n";
}

void print_shortest_path(Maze& maze)
{
    auto shortest_path_and_length = maze.get_shortest_path_and_length();
    auto shortest_path = shortest_path_and_length.first;
    double shortest_length = shortest_path_and_length.second;

    std::cout << "\nNajkrótsza trasa:\n";
    print_path(shortest_path);
    std::cout << "o długości " << shortest_length << "\n";
}


bool test(size_t n, Graph::vertex size)
{
    for (size_t i = 0; i < n; i++)
    {
        Maze maze(size);
        auto paths = maze.get_all_paths();
        if (paths.empty())
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cerr << "Podaj ilość przebiegów i wielkość.\n";
        return 1;
    }

    if (test(atoi(argv[1]), atoi(argv[2])))
    {
        std::cout << "OK\n";
    }
    else
        std::cout << "FIAL!\n";

    return 0;
}