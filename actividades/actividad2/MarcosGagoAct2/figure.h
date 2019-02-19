#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
using namespace std;

class Figure
{
public:
    Figure();
    Figure(string const _d);
    virtual float getArea()const=0;
    virtual float getPerimeter()const=0;
    string getD() const;
    void setD(const string &value);
    float getL() const;
    void setL(float value);
protected:
    string d;
    float l;
};
ostream& operator<<(ostream& os, Figure const & p);
bool operator > (Figure const & p1, Figure const & p2);
bool operator >= (Figure const & p1, Figure const & p2);
bool operator < (Figure const & p1, Figure const & p2);
bool operator <= (Figure const & p1, Figure const & p2);
bool operator == (Figure const & p1, Figure const & p2);

#endif // FIGURE_H
