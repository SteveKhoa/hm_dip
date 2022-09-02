#include "include/image.h"
#include <math.h>
#include <iostream>

// https://en.wikipedia.org/wiki/Netpbm

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
