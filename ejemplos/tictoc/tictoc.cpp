#include "tictoc.h"


using namespace std::chrono;

TicToc::TicToc()
{

}

void TicToc::tic()
{
    t0 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

}

long int TicToc::toc() const
{
    milliseconds t = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    milliseconds elapsed = t - t0;

    return elapsed.count();

}
