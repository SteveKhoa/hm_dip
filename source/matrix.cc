#include "../include/matrix.h"
#include <iostream>

using namespace dip;

matrix::matrix(unsigned int height, unsigned int width)
{
    init(height, width);
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

    for (int i = 0; i < i_height; ++i)
    {
        for (int j = 0; j < i_width; ++j)
        {
            head[i][j] = 0.0f;
        }
    }
}

// Return reference to an entry of matrix
matrix::intensity &matrix::at(int y, int x)
{
    if (x >= i_width || y >= i_height)
        throw std::runtime_error("Out of bound Access on Matrix.");
    return head[y][x];
}

// Return matrix width
unsigned int matrix::width() const
{
    return this->i_width;
}

// Return matrix height
unsigned int matrix::height() const
{
    return this->i_height;
}

// This method is for testing only.
void matrix::print() const
{
    std::cout << "\n";

    for (int i = 0; i < i_height; ++i)
    {
        for (int j = 0; j < i_width; ++j)
        {
            if (j > 0)
                std::cout << " ";
            std::cout << head[i][j];
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

/**
 * @brief Perform operations on every entries (interpreted as _ENTRY_ALIAS_).
 * @note 'intensity' stands for 'double'
 *
 * @param f lambda function with one param _ENTRY_ALIAS_
 * @param _ENTRY_ALIAS_ alias for an entry in matrix
 *
 * @example forall([](double& pixel){ pix = floor(pix/16)*16; });
 */
void matrix::forall(const std::function<void(intensity &_ENTRY_ALIAS_)> &f)
{
    for (int y = 0; y < this->height(); ++y)
    {
        for (int x = 0; x < this->width(); ++x)
        {
            f(this->at(y, x));
        }
    }
}

void matrix::clear()
{
    for (int i = 0; i < i_height; ++i)
    {
        delete[] head[i];
    }

    delete[] head;

    head = NULL;

    i_width = 0;
    i_height = 0;
}

matrix &matrix::copy(const matrix &target)
{
    this->clear();
    init(target.height(), target.width());

    for (int y = 0; y < this->height(); ++y)
    {
        for (int x = 0; x < this->width(); ++x)
        {
            this->at(y,x) = target.head[y][x];
        }
    }

    return *this;
}