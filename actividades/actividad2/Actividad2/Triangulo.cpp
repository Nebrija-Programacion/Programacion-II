//
//  Triangulo.cpp
//  Actividad2
//
//  Created by Familia Ancona Ortiz Mac on 19/2/19.
//  Copyright © 2019 Familia Ancona Ortiz Mac. All rights reserved.
//

#include "Triangulo.h"
#include <math.h>

Triangulo::Triangulo(float l):
Figura{"triangulo"},
lado{l}
{
    
}

float Triangulo::getArea() const
{
    const float h = sqrt(3)*lado/2.0;
    return lado * h / 2.0;
}

float Triangulo::getPerimetro() const
{
    return 3*lado;
}

