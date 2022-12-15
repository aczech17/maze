#include "maze.h"
#include "randomizer.h"

#include <iostream>

void Maze::init()
{
    for (vertex row = 0; row < n; row++)
        for (vertex col = 0; col < n; col++)
        {
            vertex index = row * (vertex)(n) + col;

            // left, right and down

            //std::cout << row - 1 << " " << col << "\n";
            // LEFT -> THIS
            if (getRight(row, col - 1))
            {
                //std::cout << "LEFT\n";
                vertex left_index = index - 1;
                double weight = 0.5 * (getValue(row - 1, col) + getValue(row, col));

                // from this to left
                add_edge(index, left_index, weight);
            }

            //std::cout << row << " " << col << "\n";
            //std::cout << getRight(row, col) << "\n\n";

            // THIS -> RIGHT
            if (getRight(row, col))
            {
                //std::cout << "RIGHT\n";
                vertex right_index = index + 1;
                double weight = 0.5 * (getValue(row, col) + getValue(row, col + 1));

                // from this to right
                add_edge(index, right_index, weight);
            }

            //std::cout << row << " " << col + 1 << "\n";
            // THIS
            //   |
            //   V
            // DOWN
            if (getDown(row, col))
            {
                //std::cout << "DOWN\n";
                vertex down_index = (row + 1) * (vertex)(n) + col;
                double weight = 0.5 * (getValue(row, col) + getValue(row + 1, col));

                // from this to down
                add_edge(index, down_index, weight);
            }
        }

    Randomizer randomizer;
    vertex start_row = 0;
    vertex stop_row = (vertex)n - 1;

    vertex start_col = randomizer.get_int(0, n - 1);
    vertex stop_col = randomizer.get_int(0, n - 1);

    start = start_row * n + start_col;
    stop = stop_row * n + stop_col;
}

CellArray::vertex Maze::getStart() const
{
    return start;
}

CellArray::vertex Maze::getStop() const
{
    return stop;
}
