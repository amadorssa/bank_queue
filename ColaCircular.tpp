#include<iostream>

template<typename varType/*=int*/>
Cola<varType>::Cola(): ultimo(nullptr), tam(0)
{

}
/********************************************************/
template<typename varType/*=int*/>
Cola<varType>::~Cola()
{
    Vaciar();
}
/********************************************************/
template<typename varType/*=int*/>
Cola<varType>::Cola(const Cola &q)
{
    *this=q;
}
/********************************************************/
template<typename varType/*=int*/>
Cola<varType>& Cola<varType>::operator=(const Cola &q)
{
    if(this==&q) return *this;
    Vaciar();
    Elemento* aAgregar=q.ultimo->siguiente;
    for(int i=0;i<q.ObtenerTam();++i)
    {
        Agregar(aAgregar->valor);
        aAgregar=aAgregar->siguiente;
    }
}
/********************************************************/
template<typename varType/*=int*/>
void Cola<varType>::Agregar(varType e)
{
    Elemento* newElem= new Elemento(e,EstaVacia()?nullptr:ultimo->siguiente);
    (EstaVacia()? newElem->siguiente: ultimo->siguiente)=newElem;
    ultimo=newElem;
    tam++;
}
/********************************************************/
template<typename varType/*=int*/>
varType Cola<varType>::ObtenerFrente() const
{
    if(EstaVacia()) throw ColaVacia();
    return ultimo->siguiente->valor;
}
/********************************************************/
template<typename varType/*=int*/>
bool Cola<varType>::EstaVacia() const
{
    return tam==0;
}
/********************************************************/
template<typename varType/*=int*/>
void Cola<varType>::Eliminar()
{
    if(ultimo==nullptr) throw ColaVacia();
    if(tam==1)
    {
        delete ultimo->siguiente;
        ultimo=nullptr;
        tam--;
        return;
    }
    Elemento* aEliminar=ultimo->siguiente;
    ultimo->siguiente=ultimo->siguiente->siguiente;
    delete aEliminar;
    tam--;

}
/********************************************************/
template<typename varType/*=int*/>
int Cola<varType>::ObtenerTam() const
{
    return tam;
}
/********************************************************/
template<typename varType/*=int*/>
varType Cola<varType>::ObtenerFondo() const
{
    if(EstaVacia()) throw ColaVacia();
    return ultimo->valor;
}
/********************************************************/
template<typename varType/*=int*/>
void Cola<varType>::Vaciar()
{
    Elemento* aBorrar=ultimo->siguiente;
    while(!EstaVacia()) Eliminar();
}
/********************************************************/
template<typename varType/*=int*/>
void Cola<varType>::Imprimir() const
{
    if(EstaVacia()) return;
    Elemento* iterador=ultimo->siguiente;
    for(int i=0;i<tam;++i)
    {
        std::cout<<iterador->valor<<' ';
        iterador=iterador->siguiente;
    } 
}
/********************************************************/

/********************************************************/
template<typename varType/*=int*/>
Cola<varType>::Elemento::Elemento(varType v, Cola<varType>::Elemento* s/*=nullptr*/): valor(v), siguiente(s){}
/********************************************************/
template<typename varType/*=int*/>
const char* Cola<varType>::ColaVacia::what() const throw()
{
    return "La cola no tiene elementos";
}