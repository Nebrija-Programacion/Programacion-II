#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <iostream>
#include <set>

using namespace std;

template <class T>
class Table
{
public:
    Table(unsigned int rows, unsigned int cols, T initValue);
    T getValue(unsigned int r, unsigned int c) const;
    void setValue(unsigned int r, unsigned int c, T value);

    bool find(T const & value, int &row , int &col) const;
    void printNeighbours(T const & value) const;
    unsigned int getRows() const;
    unsigned int getCols() const;
private:
    unsigned int rows, cols;
    vector< vector <T> > data;
    set<T> values;
};

template<class T>
Table<T>::Table(unsigned int rows, unsigned int cols, T initValue):
    cols{cols},
    rows{rows}
{
    for(unsigned int r{0}; r<rows; r++){
        vector<T> col;
        for(unsigned int c{0}; c<cols; c++){
            col.push_back(initValue);
        }
        data.push_back(col);
    }
}

template<class T>
T Table<T>::getValue(unsigned int r, unsigned int c) const
{
    if(c > cols || r > rows) throw string{"Number of cols/rows exceed size"};

    return data.at(r).at(c);

}

template<class T>
void Table<T>::setValue(unsigned int r, unsigned int c, T value)
{
    // check if value is already on the table
    if(values.find(value) == values.end()){
        data.at(r).at(c) = value;
        values.insert(value);
    }else{
        throw new string{"Value already on the table"};
    }

}

template<class T>
bool Table<T>::find(const T &value, int &row, int &col) const
{
    for(unsigned int r{0}; r<rows; r++){
        for(unsigned int c{0}; c<cols; c++){
            if(data.at(r).at(c) == value){
                // coordinates start at 1, so we add 1 to the index
                row = r+1;
                col = c+1;
                return true;
            }
        }
    }

    // not found
    row = -1;
    col = -1;
    return false;
}

template<class T>
void Table<T>::printNeighbours(const T &value) const
{
    int col, row;
    if(find(value, row, col)){
        //substract 1 because coordinates in find start at 1
        int r = row - 1;
        int c = col - 1;

        if(r >= 1) cout << data.at(r-1).at(c) << " - ";
        if(r <= rows-2 ) cout << data.at(r+1).at(c) << " - ";
        if(c >= 1) cout << data.at(r).at(c-1) << " - ";
        if(c <= cols-2 ) cout << data.at(r).at(c+1);

        cout << endl;
    }

}

template<class T>
unsigned int Table<T>::getRows() const
{
    return rows;
}


template<class T>
unsigned int Table<T>::getCols() const
{
    return cols;
}

template<class T>
ostream & operator << (ostream & os, Table<T> t){
    for(unsigned int r{0}; r< t.getRows(); r++){
        for(unsigned int c{0}; c < t.getCols(); c++){
            os << t.getValue(r,c) << " ";
        }
        os << endl;
    }
    return os;
}

#endif // TABLE_H

