#include "maze.h"
#include "randomizer.h"

void Maze::init()
{
    for (vertex row = 0; row < n; row++)
        for (vertex col = 0; col < n; col++)
        {
            vertex index = row * (vertex)(n) + col;

            // left, right and down

            // LEFT
            if (getRight(row - 1, col))
            {
                vertex left_index = index - 1;
                double weight = 0.5 * (getValue(row - 1, col) + getValue(row, col));

                // from this to left
                graph.add_edge(index, left_index, weight);
            }

            // RIGHT
            if (getRight(row, col))
            {
                vertex right_index = index + 1;
                double weight = 0.5 * (getValue(row, col) + getValue(row, col + 1));

                // from this to right
                graph.add_edge(index, right_index, weight);
            }

            // DOWN
            if (getDown(row, col))
            {
                vertex down_index = (row + 1) * (vertex)(n) + col;
                double weight = 0.5 * (getValue(row, col) + getValue(row + 1, col));

                // from this to down
                graph.add_edge(index, down_index, weight);
            }
        }

    Randomizer randomizer;
    start = static_cast<vertex>(randomizer.get_int(0, (vertex)(n * n - 1)));
    stop = static_cast<vertex>(randomizer.get_int(0, (vertex)(n * n - 1)));
}

CellArray::vertex Maze::getStart() const
{
    return start;
}

CellArray::vertex Maze::getStop() const
{
    return stop;
}
