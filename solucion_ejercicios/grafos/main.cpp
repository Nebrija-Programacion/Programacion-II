#include <iostream>
#include <string>
#include <memory>
#include "node.h"

using namespace std;

int main()
{

    auto parada1 = std::make_shared<Node<std::string>>( Node<std::string>{ std::make_shared<std::string>("Pavones") } );
    auto parada2 = std::make_shared<Node<std::string>>( Node<std::string>{ std::make_shared<std::string>("Artilleros") } );
    auto parada3 = std::make_shared<Node<std::string>>( Node<std::string>{ std::make_shared<std::string>("Vinateros") } );
    auto parada4 = std::make_shared<Node<std::string>>( Node<std::string>{ std::make_shared<std::string>("Estrella") } );

    parada1->addNeighbour(parada2);
    parada2->addNeighbour(parada1);

    parada2->addNeighbour(parada3);
    parada3->addNeighbour(parada2);

    parada3->addNeighbour(parada4);
    parada4->addNeighbour(parada3);

    auto it = parada1;
    auto last = parada1;

    while(it){
        std::string este = *(it->getData());
        std::string anterior = *(last->getData());

        std::cout << este << " - ";
        auto neighbours = it->getNeighbours();

        for(auto const & elem: neighbours){
            if(*(elem->getData()) != anterior){
                last = it;
                it = elem;
                break;
            }
        }
        if(este == *(it->getData())) break;
    }

    std::cout << "\n";

    return 0;
}
