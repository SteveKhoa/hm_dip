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
        unsigned int color_depth; // color depth is a fixed integer number (from input image)
    public:
        pgm() : matrix() {}
        ~pgm() {}

    public:
        pgm& load(std::string file_dir);
        void write(std::string export_dir);
    public:
        unsigned int ColorDepth();
        void setColorDepth(unsigned int new_value);
    };

    // not finish
    class ppm : public matrix
    {};
}

#endif