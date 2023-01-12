#include <iostream>
#include "src/data-structures/mat.h"

using namespace std;

//
//  This file is used for testing.
//
//
//
//

int main()
{
    mat<int> arr = {10, 20};

    arr.at(2, 3) = 17;
    cout << arr.at(2, 3);
    return 0;
}