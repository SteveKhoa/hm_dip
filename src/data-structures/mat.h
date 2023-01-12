#ifndef DIP_DS_MAT
#define DIP_DS_MAT

#include <iostream>

// 2-d matrix - mat

template<typename dtype>
class mat
{
    unsigned int height;
    unsigned int width;

    dtype * head;

public:
    mat(unsigned int height = 0, unsigned int width = 0)
        :   height(height), width(width)
    {
        if (height <= 0 || width <= 0) std::cout << "dip: init failed (dimension < 0)\n";

        head = new dtype[height*width];
    }

public:
    dtype& mat<dtype>::at(unsigned int i, unsigned int j);

public:
    ~mat() 
    {
        delete[] head;
    }
};

#endif