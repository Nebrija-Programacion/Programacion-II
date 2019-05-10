#include <iostream>
#include <array>
using namespace std;

class Matrix{
public:
    // Default constructor with no params.
    // It iniatizes matrix to all-zeros.
    Matrix(){
        data = {0,0,0,0,0,0,0,0,0};
    }

    float getElement(int row, int col){
        if(row <= 0 || row > 3 || col <= 0 || col > 3){
            throw string{"Wrong row/col dimensions"};
        }

        unsigned short index = (col - 1) + (row -1) * 3;
        return data.at(index);
    }

    void setElement(int row, int col, float value){
        if(row <= 0 || row > 3 || col <= 0 || col > 3){
            throw string{"Wrong row/col dimensions"};
        }

        unsigned short index = (col - 1) + (row -1) * 3;
        data.at(index) = value;
    }

    void setToIdentity(){
        data = { 1, 0 , 0, 0, 1, 0, 0, 0, 1};
    }

    void traspose(){

        // Make a copy in a aux matrix
        Matrix aux;
        for (unsigned short int row{1}; row < 3; row ++){
            for (unsigned short int col{1}; col < 3; col ++){
                aux.setElement( row, col, getElement(row, col));
            }
        }

        //traspose aux row, col --> col , row
        for (unsigned short int row{1}; row <= 3; row ++){
            for (unsigned short int col{1}; col <= 3; col ++){
                setElement( row, col, aux.getElement(col, row));
            }
        }
    }

    void add(Matrix other){
        for (unsigned short int row{1}; row <= 3; ++row){
            for (unsigned short int col{1}; col <= 3; ++col){
                setElement( row, col, getElement( row, col ) + other.getElement( row, col ) );
            }
        }
    }

    void preMultiply( Matrix other ){
        Matrix result;

        //compute the multiplication
        for (unsigned short int row{1}; row <= 3; row ++){
            for (unsigned short int col{1}; col <= 3; col ++){
                float aux{0};
                for(unsigned short k{1}; k <= 3; k++){
                    aux = aux + other.getElement(k, row) * getElement(k, col);
                }
                result.setElement(row, col, aux);
            }
        }

        //copy result to current data
        for (unsigned short int row{1}; row <= 3; row ++){
            for (unsigned short int col{1}; col <= 3; col ++){
                setElement( col, row, result.getElement(row, col));
            }
        }
    }

    void postMultiply( Matrix other ){
        Matrix result;
        //compute the multiplication
        for (unsigned short int row{1}; row <= 3; row ++){
            for (unsigned short int col{1}; col <= 3; col ++){
                float aux{0};
                for(unsigned short k{1}; k <= 3; k++){
                    aux = aux + getElement(row, k) * other.getElement(k, col);
                }
                result.setElement(row, col, aux);
            }
        }

        //copy result to current data
        for (unsigned short int row{1}; row <= 3; row ++){
            for (unsigned short int col{1}; col <= 3; col ++){
                setElement( row, col, result.getElement(row, col));
            }
        }
    }

    void print(){
        for (unsigned short int row{1}; row < 3; row ++){
            for (unsigned short int col{1}; col < 3; col ++){
                cout << getElement( row, col ) << "\t";
            }
            cout << endl;
        }
    }

private:
    array<float,9> data;
};

int main()
{
    try{
        Matrix one;
        Matrix two;


        //Fill both matrix
        for (unsigned short int row{1}; row <= 3; row ++){
            for (unsigned short int col{1}; col <= 3; col ++){
                cout << "Introduce element " << row << ", " << col <<" of matrix one: ";
                float value;
                cin >> value;
                one.setElement( row, col, value);
                cout << "Introduce element " << row << ", " << col <<" of matrix two: ";
                cin >> value;
                two.setElement(row, col, value);
            }
        }

        cout << endl << "=============================" << endl;
        cout << "matrix one: " << endl;
        one.print();
        cout << endl << "=============================" << endl;
        cout << "matrix two: "<< endl;
        two.print();

        cout << endl << "=============================" << endl;
        cout << "Matrix one trasposed: " << endl;
        one.traspose();
        one.print();

        cout << endl << "=============================" << endl;
        cout << "(new) Matrix one plus Matrix two" << endl;
        one.add(two);
        one.print();

        cout << endl << "=============================" << endl;
        cout << "(new) Matrix one post multiplied by Matrix two" << endl;
        one.postMultiply(two);
        one.print();

        cout << endl << "=============================" << endl;
        cout << "(new) Matrix one pre multiplied by Matrix two" << endl;
        one.preMultiply(two);
        one.print();

        cout << endl << "=============================" << endl;
        cout << "Identity Matrix" << endl;
        Matrix three;
        three.setToIdentity();
        three.print();


    }catch(string e){
        cout << e << endl;
    }

    return 0;
}
