#include <iostream>

#include "functions.h"
#include "complex.h"
#include "data.h"
#include "node.h"

using namespace std;



int main()
{
    int a{10};
    int b{14};

    Complex c{1,1};
    Complex d{2,2};

    cout << getMax<int>(a,b) << endl;
    cout << getMax<Complex>(c,d) << endl;

    Data<int> data;
    data.setValue(3);
    cout << data.getValue() << endl;

    Node<int> n{data};

    cout << n.getData().getValue() << endl;

    return 0;
}
