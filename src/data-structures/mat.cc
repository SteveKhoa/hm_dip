#include "mat.h"

template <typename dtype>
dtype &mat<dtype>::at(unsigned int i, unsigned int j)
{
    if (i < 0 || j < 0 || i >= height || j >= width)
        std::cout << "dip: invalid index\n";
    return head[width * i + j];
}