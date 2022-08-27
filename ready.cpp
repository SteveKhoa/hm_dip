#include "include/image.h"
#include <iostream>

// https://en.wikipedia.org/wiki/Netpbm

// TO-DO:
// Image basics
//  Rotate image by 45, 90 or alpha degree
//  Pixel averaging: Loop for every 3x3 block, replace all its pixels with their average

// JPEG
//  Take a look at JPEG TAKEAWAY.pptx

// Scaling up & down images


using namespace dip;

int main()
{
        pgm im;
        im.load("sample.pgm");
        
        im.at(3, 1) = 5;
        im.at(5, 1) = 5;
        im.at(1, 7) = 5;
        im.at(1, 9) = 5;
        im.at(1, 13) = 15;

        im.write("out.pgm");
        
        // im.print();

    return 0;
}