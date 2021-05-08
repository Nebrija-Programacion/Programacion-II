//
//  Cuadrado.h
//  Actividad2
//
//  Created by Familia Ancona Ortiz Mac on 19/2/19.
//  Copyright © 2019 Familia Ancona Ortiz Mac. All rights reserved.
//

#ifndef Cuadrado_h
#define Cuadrado_h

#include "figura.h"

class Cuadrado : public Figura
{
public:
    Cuadrado(float l);
    float getArea() const;
    float getPerimetro() const;
private:
    float lado;
};
#endif /* Cuadrado_h */
