#include "cell_array.h"
#include "randomizer.h"

CellArray::CellArray(size_t n)
{
    this->n = n;

    Randomizer randomizer;
    for (vertex row = 0; row < n; row++)
        for (vertex col = 0; col < n; col++)
        {
            bool right, down;
            double value;

            // IS IT OK? *********
            do
            {
                down = randomizer.get_bool();
                right = randomizer.get_bool();
            }while(!down && !right);
            // ********************

            value = randomizer.get_double(0, 10);

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
    size_t index = row * n + col;
    return cell_arr[index].value;
}
