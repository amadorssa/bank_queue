#ifndef COLA_HPP
#define COLA_HPP

#include <exception>

template<typename varType=int>

class Cola
{

    public:

    Cola();
    ~Cola();
    Cola(const Cola &q);
    Cola<varType>& operator=(const Cola &q);
    void Agregar(varType e);
    varType ObtenerFrente() const;
    void Eliminar();
    int ObtenerTam() const;
    varType ObtenerFondo() const;
    bool EstaVacia() const;
    void Vaciar();
    void Imprimir() const;

    class ColaVacia: public std::exception
    {
        public:
    
        virtual const char* what() const throw();

    };

    private:

    int tam;
    struct Elemento
    {
        Elemento(varType v,Elemento* s=nullptr);
        varType valor;
        Elemento* siguiente;
    };
    Elemento* ultimo;

};

#include "ColaCircular.tpp"
#endif //COLA_HPP