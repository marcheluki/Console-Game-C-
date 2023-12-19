#pragma once
#include <string>
#include "Personaje.hpp"
#include "Item.hpp"

class Mundo;

class Mundo {
    private:
        std::string nombre;
        Mundo* mundoSiguiente;
        Item* item;
        Personaje* personaje;
        bool valido;

    public:
        Mundo(const std::string& nombre, Mundo* mundoSiguiente, Personaje* personaje);
        Mundo(const std::string& nombre);
        ~Mundo();

        std::string getNombre() const;
        Mundo* getMundoSiguiente();
        Item* getItem();
        Personaje* getPersonaje();
        void imprime();
        void agregarItem(Item* nuevoItem);
        void agregarPersonaje(Personaje* nuevoPersonaje);
        void agregarMundoSiguiente(Mundo* nuevoMundo);
        void validar();
        bool esValido();
};
