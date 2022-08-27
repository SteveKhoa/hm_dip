#include "../include/matrix.h"
#include <iostream>

using namespace dip;

matrix::matrix(unsigned int width, unsigned int height)
{
    init(width, height);
}

matrix::~matrix()
{
    for (int i = 0; i < i_height; ++i)
    {
        delete[] head[i];
    }

    delete[] head;
}

void matrix::init(unsigned int height, unsigned int width)
{
    head = new intensity *[height];
    for (int i = 0; i < height; ++i)
    {
        head[i] = new intensity[width];
    }

    i_width = width;
    i_height = height;
}

matrix::intensity& matrix::at(int x, int y)
{
    return head[x][y];
}

unsigned int matrix::width()
{
    return this->i_width;
}

unsigned int matrix::height()
{
    return this->i_height;
}

// This method is for testing only.
void matrix::print()
{
    std::cout << "\n";

    for (int i = 0 ; i < i_height ; ++i)
    {
        for (int j = 0 ; j < i_width ; ++j)
        {
            if (j > 0)
                std::cout << " ";
            std::cout << head[i][j];
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}