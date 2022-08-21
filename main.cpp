#include "pgm.h"
#include <iostream>

// https://en.wikipedia.org/wiki/Netpbm

using namespace dip;

int main()
{
    pgm im;
    im.load("sample.pgm");

    im.at(3, 1) = 256;

    im.print();
    return 0;
}