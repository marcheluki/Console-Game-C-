#pragma once
#include <iostream>
#include <string>

class Mundo;

class Personaje {
    protected:
        std::string nombre;
        std::string descripcion;
        Mundo* ubicacion;

    public:
        Personaje(const std::string& nombre, const std::string& descripcion, Mundo* ubicacion);
        virtual ~Personaje();

        std::string getNombre() const;
        std::string getDescripcion() const;
        Mundo* getUbicacion() const;
        virtual int juega() = 0;
        virtual void recibeInteraccion(int cantidad) = 0;
        virtual void imprimeBarraVida() = 0;
        virtual bool estaVivo() = 0;
        void imprime();
};
