//
//  Cuadrado.cpp
//  Actividad2
//
//  Created by Familia Ancona Ortiz Mac on 19/2/19.
//  Copyright © 2019 Familia Ancona Ortiz Mac. All rights reserved.
//


#include "Cuadrado.h"



Cuadrado::Cuadrado(float l):
Figura{"cuadrado"},
lado{l}
{
    
}

float Cuadrado::getArea() const
{
    return lado*lado;
}

float Cuadrado::getPerimetro() const
{
    return 4*lado;
}
