#ifndef INTEGER_H
#define INTEGER_H

#include <vector>

using namespace std;

class Integer
{
public:
    Integer();
    Integer(int n);


    int getValue() const;
    void setValue(int value);

    bool esPrimo() const;
    vector<int> factores() const;

private:
    int value;
};

Integer operator* (Integer const & n1, Integer const & n2);
Integer operator/ (Integer const & n1, Integer const & n2);

#endif // INTEGER_H
