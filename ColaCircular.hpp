#ifndef COLACIRCULAR_HPP_INCLUDED
#define COLACIRCULAR_HPP_INCLUDED
#include <iostream>

template<typename T>
class Cola {
public:
    Cola(); // Constructor
    ~Cola(); // Destructor
    Cola(const Cola &c); // Constructor de copia
    Cola<T>& operator=(const Cola<T>& c); // Operador de asignación
    void Agregar(T valor); // Agrega un elemento a la cola
    void Eliminar(); // Elimina un elemento de la cola
    T ObtenerFrente() const; // Obtiene el elemento del frente de la cola
    T ObtenerFondo() const; // Obtiene el elemento del fondo de la cola
    void Vaciar(); // Elimina todos los elementos de la cola
    int ObtenerTam() const; // Obtiene el tamaño de la cola
    bool EstaVacia() const; // Verifica si la cola está vacía
    void Imprimir() const; // Imprime los elementos de la cola
private:
    int tam; // Tamaño de la cola
    struct Elemento { // Estructura que representa un elemento de la cola
        T valor;
        Elemento* siguiente;
    };
    Elemento* primero; // Puntero al primer elemento de la cola
    Elemento* ultimo; // Puntero al último elemento de la cola
};

#include "ColaCircular.tpp"

#endif // !COLACIRCULAR_HPP_INCLUDED