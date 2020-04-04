#include <iostream>
#include "db.h"
#include "pair.h"
#include "data.h"

using namespace std;

int main()
{
    try{
        Pair<std::string, std::string>* pair1 = new Pair<std::string, std::string>{"nombre", "Alberto"};
        Pair<std::string, std::string>* pair2 = new Pair<std::string, std::string>{"edad", "21"};
        Pair<std::string, std::string>* pair3 = new Pair<std::string, std::string>{"nombre", "Maria"};
        Pair<std::string, std::string>* pair4 = new Pair<std::string, std::string>{"pendiente", "tiktok"};
        std::cout << *pair1 << "\n";
        std::cout << "----------------------------\n";

        Data<std::string, std::string> *data1 = new Data<std::string, std::string>{};
        data1->insert(pair1);
        data1->insert(pair2);

        Data<std::string, std::string> *data2 = new Data<std::string, std::string>{};
        data2->insert(pair3);
        data2->insert(pair4);

        std::cout << * data1;
        std::cout << "----------------------------\n";
        std::cout << data1->value("nombre")<< "\n";
        std::cout << "----------------------------\n";

        DB<std::string, std::string> db;
        db.insert(data1);
        db.insert(data2);

        std::cout << db ;
        std::cout << "----------------------------\n";

        auto found = db.find([](Data<std::string, std::string>* d)->bool{
                try {
                    return d->value("nombre") == "Alberto";
                }catch(std::string e){
                    return false;
                }
        });

        if(found) std::cout << *found << std::endl;

    }catch(std::string e){
        std::cout << e << std::endl;
    }

    return 0;
}
