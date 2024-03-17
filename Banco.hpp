#ifndef BANCO_HPP_INCLUDED
#define BANCO_HPP_INCLUDED

#include "ColaCircular.hpp"

class Cliente {
public:
    Cliente(const std::string& n = ""); // Constructor con valor por defecto
    int obtenerTiempoAtencion() const;
    friend std::ostream& operator<<(std::ostream& os, const Cliente& c);
    friend std::istream& operator>>(std::istream& is, Cliente& c);


private:
    int tiempoCliente;
    std::string nombre;
};

/*************************************************************/
class Caja {
public:
    Caja(); // Constructor
    bool estaDisponible() const; 
    void atenderCliente(Cliente cliente);
    void avanzarTiempo();

private:
    int tiempoRestante;
    Cola<Cliente> caja;
};


#endif // BANCO_HPP_INCLUDED