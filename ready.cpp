#include "include/image.h"
#include <iostream>

// https://en.wikipedia.org/wiki/Netpbm

// TO-DO:
// Image basics
//  Rotate image by 45, 90 or alpha degree
//  Pixel averaging: Loop for every 3x3 block, replace all its pixels with their average

// Really good practice materials:
// https://www.usna.edu/Users/cs/wcbrown/courses/F14IC210/lab/l09/lab.html

// JPEG
//  Take a look at JPEG TAKEAWAY.pptx

// Scaling up & down images


using namespace dip;

int main()
{
        pgm im;
        im.load("dog.pgm");

        im.setColorDepth(100);

        im.write("out.pgm");

    return 0;
}