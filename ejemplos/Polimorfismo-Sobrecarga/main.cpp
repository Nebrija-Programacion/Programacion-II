#include <iostream>

#include "vector.h"
#include "vector2.h"
#include "vector3.h"

using namespace std;



int main()
{

    Vector* v1 = new Vector2{1,2};
    // Polymorphic call to getMod().
    // Type of v1 is Vector, but getMod() is called on Vector 2
    cout << "Modulo: " << v1->getMod() << endl;

    Vector2 v2{3,1};
    Vector2 v3{3,1};

    // call to == overloaded operator
    if(v2 == v3){
        cout << "vectors are equal" << endl;
        cout << "v2: " << v2 << endl;
        cout << "v3: " << v3 << endl;
    }

    Vector2 v_add = v2 + v3;
    cout << "Addition is: " << v_add << endl;

    Vector* v4 = new Vector2{1,2};
    Vector* v5 = new Vector2{1,2};

    // if(v4 == v5){
    //     THIS DOES NOT COMPILE, BECAUSE == IS NOT OVERLOADED FOR TYPE Vector *
    // }

    // Correct way


    Vector2* v6 = dynamic_cast<Vector2*>(v4);


    Vector2* v7 = dynamic_cast<Vector2*>(v5);

    // if dynamic cast is well done
    if(v6 && v7){
        // we use * to get value from pointer
        if(*v6 == *v7){
            cout << "vectors are 2D and are equal" << endl;
            cout << "v6: " << *v6 << endl;
            cout << "v7: " << *v7 << endl;
        }
    }


    Vector3* v8 = dynamic_cast<Vector3*>(v4);
    Vector3* v9 = dynamic_cast<Vector3*>(v5);

    // DYNAMIC CAST WONT WORK, AND THUS, THIS WILL NOT HAPPEN
    if(v8 && v9){
        // we use * to get value from pointer
        if(*v8 == *v9){
            cout << "vectors are 3D and are equal" << endl;
        }
    }

    return 0;
}
