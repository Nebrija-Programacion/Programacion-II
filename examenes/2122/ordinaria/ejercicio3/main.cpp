#include <iostream>

using namespace std;

class Coche{
public:
    Coche(string const & marca, string const & matricula);
    const string &getMarca() const;
    void setMarca(const string &newMarca);

    const string &getMatricula() const;
    void setMatricula(const string &newMatricula);

private:
    string marca;
    string matricula;
};

int main()
{
    Coche panda{"Seat Panda", "1234DHL"};
    Coche corsa{"Seat Corsa", "2345FNS"};
    try{
        Coche error{"Error", "as32dsl"};
    }catch(string e){
        std::cout << e << "\n";
    }

    return 0;
}

Coche::Coche(const string &marca, const string &matricula)
{
    setMarca(marca);
    setMatricula(matricula);
}

const string &Coche::getMarca() const
{
    return marca;
}

void Coche::setMarca(const string &newMarca)
{
    marca = newMarca;
}

const string &Coche::getMatricula() const
{

    return matricula;
}

void Coche::setMatricula(const string &newMatricula)
{
    if(newMatricula.length() != 7) throw string{"La matricula tiene 7 elementos"};
    for(int i=0; i<4; i++){
        if(newMatricula.at(i) < '0' || newMatricula.at(i) > '9' ) throw string{"Los 4 primeros elementos deben ser numeros"};
    }
    for(int i=4; i < 7; i++)
        if(newMatricula.at(i) <= 'A' ||
                newMatricula.at(i) > 'Z' ||
                newMatricula.at(i) == 'E' ||
                newMatricula.at(i) == 'I' ||
                newMatricula.at(i) == 'O' ||
                newMatricula.at(i) == 'U')
            throw string{"Los 3 ultimos elementos deben ser letras"};

    matricula = newMatricula;
}

bool operator==(Coche const &c1, Coche const &c2){
    return c1.getMarca()==c2.getMarca() && c1.getMatricula()==c2.getMatricula();
}

bool operator<(Coche const &c1, Coche const &c2){
    return c1.getMatricula() < c2.getMatricula();
}

bool operator>(Coche const &c1, Coche const &c2){
    return c1.getMatricula() > c2.getMatricula();
}

bool operator<=(Coche const &c1, Coche const &c2){
    return c1 < c2 || c1 == c2;
}

bool operator>=(Coche const &c1, Coche const &c2){
    return c1 > c2 || c1 == c2;
}

bool operator!=(Coche const &c1, Coche const &c2){
    return !(c1 == c2);
}
