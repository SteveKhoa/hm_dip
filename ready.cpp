#include "pgm.h"
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
        
        im.at(3, 1) = 256;
        
        im.print();

    return 0;
}