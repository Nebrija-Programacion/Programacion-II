#ifndef EJERCICIO2_H
#define EJERCICIO2_H

#include <array>
#include <string>

using namespace std;

class Table{
public:
    Table();
    virtual ~Table(){};
    virtual void print() const = 0;
};

class TableInt: public Table{
public:
    TableInt(int f1c1, int f1c2, int f2c1, int f2c2);
    void print() const;
private:
    std::array<int, 4> data;
};

class TableString: public Table{
public:
    TableString(string const & f1c1, string const & f1c2, string const & f2c1, string const & f2c2);
    void print() const;
private:
    std::array<string, 4> data;
};

struct Complex{
    double r,i;
};

class TableComplex: public Table{
public:
    TableComplex(Complex const & f1c1, Complex const & f1c2, Complex const & f2c1, Complex const & f2c2);
    void print() const;
private:
    std::array<Complex, 4> data;
};


#endif // EJERCICIO2_H
