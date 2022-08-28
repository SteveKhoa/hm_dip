#ifndef IMAGE_H_
#define IMAGE_H_

#include "matrix.h"
#include <string>

/**
 * @brief Image classes: pbm, pgm, ppm are *derived class* from base *matrix class*
 * 
 */

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
        pgm(unsigned int height, unsigned int width) : matrix(height, width) {}
        ~pgm() {}

    public: // Image iostream
        pgm& load(std::string file_dir);
        void write(std::string export_dir);
    public: // Intensity manipulation
        unsigned int ColorDepth();
        void setColorDepth(unsigned int new_value);
    public: // ... processing
        pgm& rotate(double rad);
    };

    // not finish
    class ppm : public matrix
    {};
}

#endif