#include "ColaCircular.hpp"
#include "Banco.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Implementación de la clase Cliente

// Metodo constructor
Cliente::Cliente(const std::string& n) : nombre(n), tiempoCliente(rand() % 6 + 5) {}

// Obetener tiempo de atención del cliente
int Cliente::obtenerTiempoAtencion() const {
    return tiempoCliente;
}

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream& os, const Cliente& c) {
    os << c.nombre;
    return os;
}

// Sobrecarga del operador de extracción
std::istream& operator>>(std::istream& is, Cliente& c) {
    is >> c.nombre;
    return is;
}


// Implementación de la clase Caja
// Metodo constructor
Caja::Caja() {
    tiempoRestante = 0;
}

// Metodo para verificar si la caja está disponible
bool Caja::estaDisponible() const {
    return tiempoRestante == 0;
}

// Metodo para atender al cliente
void Caja::atenderCliente(Cliente cliente) {
    tiempoRestante = cliente.obtenerTiempoAtencion();
}

// Metodo para avanzar el tiempo en la caja mientras atiende a un cliente
void Caja::avanzarTiempo() {
    if (tiempoRestante > 0) {
        tiempoRestante--;
    }
}
