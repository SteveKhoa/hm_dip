#ifndef IMAGE_H_
#define IMAGE_H_

#include "matrix.h"
#include <string>

namespace dip
{
    class pgm : public matrix
    {
    public:
        pgm() : matrix() {};
        ~pgm() {};
        pgm& load(std::string);
    };
}

#endif