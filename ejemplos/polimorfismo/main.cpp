#include <iostream>

using namespace std;

#include "worker.h"
#include "doctor.h"
#include "policeman.h"

int main()
{
    // example WITHOUT Polymorphism
    PoliceMan person1;
    person1.printProfessionalInfo(); // Hello, I am a policeman

    // This is NOT using polymorphism either
    // Because the pointer is of the child type (PoliceMan)
    PoliceMan* person2 = new PoliceMan();
    person2->printProfessionalInfo(); //Hello, I am a policeman

    //Polymorphism
    // Pointer to parent. New child
    // When calling printProfessionalInfo it runs child function
    Worker* person3 = new PoliceMan();
    person3->printProfessionalInfo(); ////Hello, I am a policeman

    //Polymorphism
    // Pointer to parent. New child
    // When calling printProfessionalInfo it runs child function
    Worker* person4 = new Doctor();
    person4->printProfessionalInfo(); ////Hello, I am a doctor

    return 0;
}
