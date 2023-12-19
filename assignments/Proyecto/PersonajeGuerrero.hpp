#pragma once
#include <string>
#include "Personaje.hpp"
#include "Item.hpp"

class PersonajeGuerrero : public Personaje {
    protected:
        int puntosSaludTotales;
        int puntosSaludActuales;
        int maximoAtaque;

    public:
        PersonajeGuerrero(const std::string nombre, const std::string descripcion, Mundo* ubicacion, int saludTotal, int ataqueMax);
        ~PersonajeGuerrero();

        int getPuntosSaludTotales() const;
        int getMaximoAtaque() const;
        int getPuntosSaludActuales();
        void usar(int);
        bool estaVivo();
        int calcularPorcentajeSalud();
        void imprimeBarraVida() override;
        int juega() override;
        void recibeInteraccion(int danio) override;
        PersonajeGuerrero& operator-=(const int danio);
};
