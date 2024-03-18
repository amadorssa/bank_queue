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
    Caja(int tiempoTotal); // Constructor que toma el tiempo total del banco
    bool estaDisponible() const; 
    void avanzarTiempo();
    void atenderCliente(Cola<Cliente>& c); // Método para atender a los clientes
    Cliente ObtenerClientePrimero() const;

private:
    int tiempoRestante;
    Cola<Cliente> caja;
};

#endif // BANCO_HPP_INCLUDED
