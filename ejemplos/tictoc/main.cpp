#include <iostream>
#include "tictoc.h"

using namespace std;

int main()
{
    TicToc clock;
    // start counting milliseconds
    clock.tic();
    for(int i=0; i< 10000000; i++){

    }
    cout << clock.toc() << " ms have elapsed." << endl;
    return 0;
}
