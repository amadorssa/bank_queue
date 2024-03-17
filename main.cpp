#include "Banco.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    srand(time(nullptr));

    // Tiempo total de atención del banco entre 20 y 30 segundos
    int tiempoBanco = 20 + rand() % 11;

    // Generar 10 clientes al azar extrayendo el nombre desde un archivo
    Cola<Cliente> clientes;
    ifstream archivo("nombres.txt");
    if (archivo.is_open()) {
        string nombre;
        int clientesGenerados = 0;
        while (clientesGenerados < 10) {
            getline(archivo, nombre);
            // Crear un objeto tipo cliente con el nombre leído del archivo
            Cliente cliente(nombre);
            // Agregar el cliente a la cola de clientes
            clientes.Agregar(cliente);
            clientesGenerados++;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo\n" << endl;
    }

    Cola<Cliente> fila;

// Mostrar contador y procesar clientes hasta que termine el tiempo total del banco
std::cout << "Tiempo total de atención del banco: " << tiempoBanco << " segundos\n";
int tiempoTranscurrido = 0;

while (tiempoTranscurrido <= tiempoBanco || !clientes.EstaVacia()) {
    system("clear"); // Limpiar pantalla (sistema UNIX/Linux)

    // Posicionar el cursor en la parte superior izquierda de la terminal
    std::cout << "\033[H";

    // Mostrar tiempo transcurrido
    std::cout << "Tiempo transcurrido: " << tiempoTranscurrido << " segundos\n";

    // Pasar clientes de la cola clientes a la cola fila cada 5 segundos
    if (tiempoTranscurrido % 5 == 0 && !clientes.EstaVacia()) {
        // Obtener el primer cliente de la cola de clientes y agregarlo a la fila
        Cliente cliente = clientes.ObtenerPrimero();
        fila.Agregar(cliente);

        // Eliminar el cliente de la cola de clientes
        clientes.Eliminar();
    }

    // Mostrar clientes en la fila
    fila.Imprimir();

    // Actualizar la pantalla cada segundo
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Incrementar el tiempo transcurrido
    tiempoTranscurrido++;
}

// Mostrar mensaje de finalización
if (tiempoTranscurrido > tiempoBanco) {
    std::cout << "Todos los clientes han sido atendidos antes de que se agotara el tiempo total del banco.\n";
} else {
    std::cout << "Tiempo total de atención del banco agotado.\n";
}


    // Simulación de la caja del banco
    Caja caja1;

    Cliente clienteEnFrente = fila.ObtenerPrimero();

    // Simular clientes
    if (caja1.estaDisponible()) {
        caja1.atenderCliente(clienteEnFrente);
        fila.Eliminar();

    // Simular tiempo de atención de cada cliente (en segundos)
    int tiempoAtencion = clienteEnFrente.obtenerTiempoAtencion();
    for (int t = 0; t < tiempoAtencion; ++t) {
        caja1.avanzarTiempo();
    }
}
    return 0;

}
