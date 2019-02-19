//
//  Triangulo.h
//  Actividad2
//
//  Created by Familia Ancona Ortiz Mac on 19/2/19.
//  Copyright © 2019 Familia Ancona Ortiz Mac. All rights reserved.
//

#ifndef Triangulo_h
#define Triangulo_h


#include "figura.h"

class Triangulo : public Figura
{
public:
    Triangulo(float l);
    float getArea() const;
    float getPerimetro() const;
private:
    float lado;
};

#endif /* Triangulo_h */
