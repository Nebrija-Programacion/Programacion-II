#ifndef TICTOC_H
#define TICTOC_H

#include <chrono>
using namespace std::chrono;

class TicToc
{
public:
    TicToc();
    void tic();
    long toc() const;
private:
    milliseconds t0;
};

#endif // TICTOC_H
