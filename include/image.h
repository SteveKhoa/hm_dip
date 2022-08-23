#ifndef IMAGE_H_
#define IMAGE_H_

#include "matrix.h"
#include <string>

namespace dip
{
    // not finish
    class pbm : public matrix
    {};

    class pgm : public matrix
    {
    public:
        pgm() 
            : matrix() {}
        ~pgm() {}

    public:
        pgm& load(std::string);
    };

    // not finish
    class ppm : public matrix
    {};
}

#endif