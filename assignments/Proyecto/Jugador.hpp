#pragma once

#include <string>
#include "PersonajeGuerrero.hpp"
#include "Item.hpp"

class Jugador : public PersonajeGuerrero {
    public:
        Jugador(const std::string nombre, const std::string descripcion, Mundo* ubicacion, int saludTotal, int ataqueMax);

        bool estaVivo() override;
        int juega() override;
        void recibeInteraccion(int danio) override;
};
