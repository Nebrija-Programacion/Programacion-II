#include <iostream>
#include <memory>
#include "ejercicio2.h"
#include <vector>

using namespace std;

Table::Table(){};

TableInt::TableInt(int f1c1, int f1c2, int f2c1, int f2c2)
{
    data = {f1c1, f1c2, f2c1, f2c2};
}

TableString::TableString(const string &f1c1, const string &f1c2, const string &f2c1, const string &f2c2)
{
    data = {f1c1, f1c2, f2c1, f2c2};
}

TableComplex::TableComplex(const Complex &f1c1, const Complex &f1c2, const Complex &f2c1, const Complex &f2c2)
{
    data = {f1c1, f1c2, f2c1, f2c2};
}


void TableInt::print() const{
    std::cout << data.at(0) << "\t" << data.at(1) << "\n" << data.at(2) << "\t" << data.at(3) << "\n" ;
}


void TableString::print() const{
    std::cout << data.at(0) << "\t" << data.at(1) << "\n" << data.at(2) << "\t" << data.at(3) << "\n" ;
}


void TableComplex::print() const{
    std::cout << data.at(0).r << " + " <<data.at(0).i << "i" << "\t"
              << data.at(1).r << " + " <<data.at(1).i << "i" << "\n"
              << data.at(2).r << " + " <<data.at(2).i << "i" << "\t"
              << data.at(3).r << " + " <<data.at(3).i << "i" << "\n";
}

int main()
{
    vector<shared_ptr<Table>> v;
    v.push_back(make_shared<TableInt>(1,2,3,4));
    v.push_back(make_shared<TableInt>(2,2,3,3));
    v.push_back(make_shared<TableString>("hola", "que", "tal", "estas"));
    v.push_back(make_shared<TableComplex>(Complex{1,2}, Complex{2,3}, Complex{2,3}, Complex{3,4}));

    for(shared_ptr<Table> elem: v){
        elem->print();
        cout << "\n""\n""\n";
    }
    return 0;
}
