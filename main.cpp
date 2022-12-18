#include <iostream>
#include "graph.h"
#include <algorithm>

#include "maze.h"

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


int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Podaj wielkość labiryntu.\n";
        return 1;
    }
    Graph::vertex n = static_cast<Graph::vertex>(std::stoi(argv[1]));
    Maze maze(n);

    auto paths = maze.get_all_paths();
    if (paths.empty())
    {
        std::cout << "Nie ma dróg.\n";
        return 0;
    }

    std::cout << "Wszystkie trasy z " << maze.get_start() << " do " << maze.get_stop() << ":\n";
    for (const auto& path: paths)
    {
        auto vertices = path.first;
        double length = path.second;

        print_path(vertices);
        std::cout << length << "\n\n";
    }

    print_shortest_path(maze);
    return 0;
}
