#include "Banco.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
#include <thread>
#include <iomanip>

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
    Caja caja(1, 0);  // Caja 1
    Caja caja2(2, 0); // Caja 2
    Caja caja3(3, 0); // Caja 3

    // Mostrar contador y procesar clientes hasta que termine el tiempo total del banco
    cout << "Tiempo total de atención del banco: " << tiempoBanco << " segundos\n";
    int tiempoTranscurrido = 0;

    while (tiempoTranscurrido <= tiempoBanco || !clientes.EstaVacia()) {
        system("clear"); // Limpiar pantalla (sistema UNIX/Linux)

        // Posicionar el cursor en la parte superior izquierda de la terminal y mostrar el tiempo transcurrido
        cout << "\033[H" << "Tiempo transcurrido: " << tiempoTranscurrido << " segundos\n";


        // Pasar clientes de la cola clientes a la cola fila cada 5 segundos
        if (tiempoTranscurrido % 3 == 0 && !clientes.EstaVacia()) {
            // Obtener el primer cliente de la cola de clientes y agregarlo a la fila
            Cliente cliente = clientes.ObtenerFrente();
            fila.Agregar(cliente);

            // Eliminar el cliente de la cola de clientes
            clientes.Eliminar();
        }

        // Mostrar las cajas y las personas que están siendo atendidas en cada una de ellas
        for (int i = 1; i <= 3; ++i) {
            cout << "Caja " << i << endl;
            if (i == 1) {
                caja.atenderCliente(fila, i);
            } else if (i == 2) {
                caja2.atenderCliente(fila, i);
            } else {
                caja3.atenderCliente(fila, i);
            }
            cout << endl; // Salto de línea entre cada caja
        }


        // Mostrar clientes en la fila
        cout << "Clientes en la fila: " << endl;
        fila.Imprimir();

        // Actualizar la pantalla cada segundo
        this_thread::sleep_for(chrono::seconds(1));

        // Incrementar el tiempo transcurrido
        tiempoTranscurrido++;
    }

    // Mostrar mensaje de finalización
    if (tiempoTranscurrido > tiempoBanco) {
        cout << "Todos los clientes han sido atendidos antes de que se agotara el tiempo total del banco.\n";
    } else {
        cout << "Tiempo total de atención del banco agotado.\n";
    }

    return 0;
}
