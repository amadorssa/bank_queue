#include "ColaCircular.hpp"

// Constructor de la clase Cola enlazada
template <typename T>
Cola<T>::Cola() : primero(nullptr), ultimo(nullptr), tam(0) {}

// Destructor de la clase Cola enlazada
template <typename T>
Cola<T>::~Cola() {
    Vaciar();
}

// Constructor copia de la clase Cola enlazada
template <typename T>
Cola<T>::Cola(const Cola<T> &c) : primero(nullptr), ultimo(nullptr), tam(0) {
    *this = c;
}

// Metodo operador de asignación de la clase Cola enlazada
template <typename T>
Cola<T>& Cola<T>::operator=(const Cola<T>& c)
{
    if(this == &c) return *this;
    this->Vaciar();

    Elemento *actual = c.primero;
    while(actual != nullptr){
        Agregar(actual -> valor);
        actual = actual -> siguiente;
    }
    return *this;
}

// Método para agregar un elemento a la cola
template <typename T>
void Cola<T>::Agregar(T valor) {
    Elemento *aux = new Elemento;
    aux->valor = valor;
    aux->siguiente = nullptr;
    if (EstaVacia()) {
        primero = aux;
    } else {
        ultimo->siguiente = aux;
    }
    ultimo = aux;
    ++tam;
}

// Método para eliminar un elemento de la cola
template <typename T>
void Cola<T>::Eliminar() {
    if (EstaVacia()) {
        throw std::out_of_range("La cola está vacía");
    }
    Elemento *aux = primero;
    primero = primero->siguiente;
    delete aux;
    --tam;
}

// Método para obtener el elemento del frente de la cola
template <typename T>
T Cola<T>::ObtenerFrente() const {
    if (EstaVacia()) {
        throw std::out_of_range("La cola está vacía");
    }
    return primero->valor;
}

// Método para obtener el elemento del fondo de la cola
template <typename T>
T Cola<T>::ObtenerFondo() const {
    if (EstaVacia()) {
        throw std::out_of_range("La cola está vacía");
    }
    return ultimo->valor;
}

// Método para vaciar la cola
template <typename T>
void Cola<T>::Vaciar() {
    while (!EstaVacia()) {
        Eliminar();
    }
}

// Método para obtener el tamaño de la cola
template <typename T>
int Cola<T>::ObtenerTam() const {
    return tam;
}

// Método para verificar si la cola está vacía
template <typename T>
bool Cola<T>::EstaVacia() const {
    return tam == 0;
}

// Método para imprimir la cola
template <typename T>
void Cola<T>::Imprimir() const {
    if (EstaVacia()) {
        return;
    }
    Elemento *aux = primero;
    while (aux != nullptr) {
        std::cout << aux->valor << std::endl;
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}