//
//  Circulo.cpp
//  Actividad2
//
//  Created by Familia Ancona Ortiz Mac on 19/2/19.
//  Copyright © 2019 Familia Ancona Ortiz Mac. All rights reserved.
//


#include "Circulo.h"
#include "math.h"

Circulo::Circulo(float r):
Figura{"circulo"},
radio{r}
{
    
}

float Circulo::getArea() const
{
    return M_PI*radio*radio;
    
}

float Circulo::getPerimetro() const
{
    return 2*M_PI*radio;
}
