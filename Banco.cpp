#include "ColaCircular.hpp"
#include "Banco.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

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
Caja::Caja(int tiempoCliente) : tiempoRestante(tiempoCliente) {}


// Metodo para verificar si la caja está disponible
bool Caja::estaDisponible() const {
    return tiempoRestante == 0;
}

// Metodo para atender al cliente
void Caja::atenderCliente(Cola<Cliente>& c) {
    if (estaDisponible()) {
        // Si la caja está disponible, atender al cliente
        if (!c.EstaVacia()) {
            // Obtener el primer cliente de la fila
            Cliente cliente = c.ObtenerFrente();
            // Establecer el tiempo restante de atención en base al tiempo del cliente
            tiempoRestante = cliente.obtenerTiempoAtencion();
            // Agregar el cliente a la caja
            caja.Agregar(cliente);
            // Eliminar el cliente de la fila
            c.Eliminar();
            // Mostrar el nombre del cliente que está siendo atendido
            std::cout << "\033[ 4 ; 0H" << cliente << std::endl << std::endl;
        }
    } else {
        // Si la caja no está disponible
        if (tiempoRestante > 0) {
            // Si el tiempo restante es mayor que 0, mostrar el nombre del cliente que está siendo atendido
            std::cout << "\033[ 4 ; 0H" << caja.ObtenerFondo() << std::endl << std::endl;
        } else {
            // Si el tiempo restante es 0, mostrar que la caja está disponible
            std::cout << "\033[ 4 ; 0H" << "Caja disponible" << std::endl << std::endl;
        }
        // Avanzar el tiempo en la caja
        avanzarTiempo();
    }
}


// Metodo para avanzar el tiempo en la caja mientras atiende a un cliente
void Caja::avanzarTiempo() {
    if (tiempoRestante > 0) {
        tiempoRestante--;
    }
}

Cliente Caja::ObtenerClientePrimero() const {
    return caja.ObtenerFrente();
}
