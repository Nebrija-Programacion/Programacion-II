#include <iostream>
#include <memory>

#include "persona.h"
#include "functions.h"

int main()
{
    try {

        std::vector<std::shared_ptr<Persona> > lista;
        lista.push_back(std::make_shared<Persona>(Persona{"Alberto", 23, "12345678K"}));
        lista.push_back(std::make_shared<Persona>(Persona{"Maria", 17, "22222222K"}));
        lista.push_back(std::make_shared<Persona>(Persona{"Ruy", 23, "11111111K"}));

        std::shared_ptr<Persona> found = find<std::shared_ptr<Persona>>(
                                            lista,
                                            [](std::shared_ptr<Persona> p) -> bool {
                                                return (p->getDni()=="11111111K");
                                            });

        if(found.get()){
            std::cout<<found->getNombre() << "\n";
        }

    } catch (std::string e) {
        std::cout << e << "\n";
    }

    return 0;
}
