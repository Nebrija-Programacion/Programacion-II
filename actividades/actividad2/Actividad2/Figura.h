//
//  Figura.h
//  Actividad2
//
//  Created by Familia Ancona Ortiz Mac on 19/2/19.
//  Copyright © 2019 Familia Ancona Ortiz Mac. All rights reserved.
//

#ifndef Figura_h
#define Figura_h

#include <iostream>

using namespace std;

class Figura
{
public:
    Figura(string const &  _type);
    
    virtual float getArea() const = 0;
    virtual float getPerimetro() const = 0;
    void imprimir() const;
    string getType() const;
    void setType(const string &value);
    
    
protected:
    string type;
    
};
bool operator == (const Figura &1, const Figura &2);
bool operator > (const Figura &1, const Figura &2);
bool operator >= (const Figura &1, const Figura &2);
bool operator < (const Figura &1, const Figura &2);
bool operator <= (const Figura &1, const Figura &2);
ostream &operator << (ostream &os, const Figura &2);

#endif /* Figura_h */
