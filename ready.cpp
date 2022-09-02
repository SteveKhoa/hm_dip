#include "include/image.h"
#include <math.h>
#include <iostream>

// https://en.wikipedia.org/wiki/Netpbm

// TO-DO:
//  *IMPORTANT* Implement method rotate() :
//  Rotate image by 45, 90 or alpha degree
//  Pixel averaging: Loop for every 3x3 block, replace all its pixels with their average
//  Scaling up & down images
//  https://www.youtube.com/watch?v=rLMznzIslVA

// Benchmarking : try to optimize time (as i see, it is a bit slow isn't it)

// Really good practice materials:
// https://www.usna.edu/Users/cs/wcbrown/courses/F14IC210/lab/l09/lab.html

// JPEG
//  Take a look at JPEG TAKEAWAY.pptx

using namespace dip;

int main()
{
    pgm im;
    im.load("dog.pgm");
    // im.setColorDepth(100);

    im.rotate(90);
    im.write("out.pgm");

    return 0;
}