#include <iostream>

#include "table.h"

using namespace std;

int main()
{

    try{
        Table<int> tableInt(2,3,0);

        tableInt.setValue(0,0,3);
        tableInt.setValue(0,1,2);
        tableInt.setValue(0,2,4);
        tableInt.setValue(1,0,5);
        tableInt.setValue(1,1,1);
        tableInt.setValue(1,2,7);


        cout << "----------------------------------------" << endl;

        cout << "table int" << endl;
        cout << tableInt << endl;


        Table<string> tableString(4,3,"init");
        tableString.setValue(0,0,"periquito");
        tableString.setValue(0,1,"perro");
        tableString.setValue(0,2,"paloma");
        tableString.setValue(1,0,"tortuga");
        tableString.setValue(1,1,"gallina");
        tableString.setValue(1,2,"lechuza");
        tableString.setValue(2,0,"canario");
        tableString.setValue(2,1,"gato");
        tableString.setValue(2,2,"delfin");
        tableString.setValue(3,0,"orangutan");
        tableString.setValue(3,1,"gamusino");
        tableString.setValue(3,2,"garrapata");

        cout << "----------------------------------------" << endl;

        cout << "table string" << endl;
        cout << tableString << endl;

        cout << "----------------------------------------" << endl;
        cout << "Find values" << endl;

        cout << "Find gamusino" << endl;
        int r,c;
        if(tableString.find("gamusino",r,c)){
            cout << "Pos: " << r << ", " << c << endl;
        }else{
            cout << "Not found" << endl;
        }

        cout << "----------------------------------------" << endl;
        cout << "Find 7" << endl;
        if(tableInt.find(7,r,c)){
            cout << "Pos: " << r << ", " << c << endl;
        }else{
            cout << "Not found" << endl;
        }

        cout << "----------------------------------------" << endl;
        cout << "Print neighbours of..." << endl;

        cout << "...canario: "; tableString.printNeighbours("canario");
        cout << "...gato: "; tableString.printNeighbours("gato");
        cout << "...lechuza: "; tableString.printNeighbours("lechuza");

        cout << "...2: "; tableInt.printNeighbours(2);
        cout << "...7: "; tableInt.printNeighbours(7);


    }catch(string e){
        cout << e << endl;
    }

    return 0;
}
