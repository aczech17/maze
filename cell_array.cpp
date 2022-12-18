#include "cell_array.h"
#include "randomizer.h"
#include <stdexcept>
#include <string>

CellArray::CellArray(Graph::vertex n)
{
    this->n = n;

    Randomizer randomizer;
    for (vertex row = 0; row < n; row++)
        for (vertex col = 0; col < n; col++)
        {
            bool right, down;
            double value;

            // IS IT OK? *********
            if (col == n - 1 && row == n - 1)
            {
                right = false;
                down = false;
            }
            else if (col == n - 1 && row < n - 1)
            {
                right = false;
                down = true;
            }
            else if (col < n - 1 && row == n - 1)
            {
                right = true;
                down = false;
            }
            else if (col < n - 1 && row < n - 1)
            {
                do
                {
                    down = randomizer.get_bool();
                    right = randomizer.get_bool();
                }while(!down && !right);
            }
            // ********************

            const double EPS = std::numeric_limits<double>::min();
            value = randomizer.get_double(EPS, 10 - EPS); // (0, 10) open

            cell_arr.emplace_back(right, down, value);
        }
}

bool CellArray::getRight(CellArray::vertex row, CellArray::vertex col)
{
    if (row >= 0 && row < n && col >= 0 && col < n - 1)
    {
        size_t index = row * n + col;
        return cell_arr[index].right;
    }
    return false;
}

bool CellArray::getDown(CellArray::vertex row, CellArray::vertex col)
{
    if (row >= 0 && row < n - 1 && col >= 0 && col < n)
    {
        size_t index = row * n + col;
        return cell_arr[index].down;
    }
    return false;
}

double CellArray::getValue(CellArray::vertex row, CellArray::vertex col)
{
    vertex index = row * vertex(n) + col;
    if (index < 0 || index >= (vertex)cell_arr.size())
    {
        std::string error_msg = "Bad index: " + std::to_string(index) +
                "\nrow = " + std::to_string(row) +
                "\ncol = " + std::to_string(col);

        throw std::out_of_range(error_msg);

    }
    return cell_arr[index].value;
}
