//
//  Circulo.h
//  Actividad2
//
//  Created by Familia Ancona Ortiz Mac on 19/2/19.
//  Copyright © 2019 Familia Ancona Ortiz Mac. All rights reserved.
//

#ifndef Circulo_h
#define Circulo_h
#include "figura.h"

class Circulo : public Figura
{
public:
    Circulo(float _r);
    float getArea() const;
    float getPerimetro() const;
private:
    float radio;
};


#endif /* Circulo_h */
