#include <iostream>
#include <memory>    // Requisito para Smart Pointers (make_unique)
#include "Usuario.h" // Cabecera de usuarios
#include "Relay.h"   // Cabecera del cerrojo eléctrico

using namespace std;

int main() {
    cout << "====================================================" << endl;
    cout << "===  SISTEMA DE ACCESO INTELIGENTE (POO + HARDWARE) ===" << endl;
    cout << "====================================================" << endl;

    // 1. INSTANCIAMOS EL HARDWARE: Cerrojo magnético en el pin 26
    auto cerrojoPuerta = make_unique<Relay>(26);

    // 2. CREAMOS LAS IDENTIFICACIONES (SMART POINTERS / RAM SEGURA)
    auto juanAdmin = make_unique<Administrador>("Juan (Admin)");
    auto mariaInvitadoValido = make_unique<Invitado>("Maria (Invitado)", true);
    auto carlosInvitadoVencido = make_unique<Invitado>("Carlos (Invitado)", false);

    // 3. EL ESCÁNER POLIMÓRFICO INTELIGENTE (Arranca vacío)
    unique_ptr<Usuario> escanerPuerta = nullptr;


    // =================================================================
    // SIMULACIÓN DE ESCENARIOS EN TIEMPO REAL
    // =================================================================

    cout << "\n>>> [ESCENARIO 1: LLEGA EL ADMINISTRADOR] <<<" << endl;
    escanerPuerta = move(juanAdmin); // Juan aproxima su tarjeta al escáner
    cout << "Tarjeta detectada -> " << escanerPuerta->obtenerNombre() << endl;

    if (escanerPuerta->tieneAcceso()) {
        cout << "🔒 [VALIDADO]: Permisos concedidos de Administrador." << endl;
        cerrojoPuerta->activar(); // Abre físicamente el cerrojo
    } else {
        cout << "❌ [RECHAZADO]: Sin credenciales válidas." << endl;
        cerrojoPuerta->desactivar();
    }


    cout << "\n>>> [ESCENARIO 2: LLEGA INVITADO CON PASE VIGENTE] <<<" << endl;
    // El escáner destruye de la RAM los datos de Juan automáticamente al recibir a María
    escanerPuerta = move(mariaInvitadoValido); 
    cout << "Tarjeta detectada -> " << escanerPuerta->obtenerNombre() << endl;

    if (escanerPuerta->tieneAcceso()) {
        cout << "🔒 [VALIDADO]: Pase temporal vigente detectado." << endl;
        cerrojoPuerta->activar(); 
    } else {
        cout << "❌ [RECHAZADO]: Sin credenciales válidas." << endl;
        cerrojoPuerta->desactivar();
    }


    cout << "\n>>> [ESCENARIO 3: LLEGA INVITADO CON PASE VENCIDO] <<<" << endl;
    // El escáner destruye de la RAM a María automáticamente al recibir a Carlos
    escanerPuerta = move(carlosInvitadoVencido); 
    cout << "Tarjeta detectada -> " << escanerPuerta->obtenerNombre() << endl;

    if (escanerPuerta->tieneAcceso()) {
        cout << "🔒 [VALIDADO]: Acceso correcto." << endl;
        cerrojoPuerta->activar();
    } else {
        cout << "❌ [RECHAZADO]: ¡Alerta! El pase del invitado ha caducado." << endl;
        cerrojoPuerta->desactivar(); // Bloquea y asegura el cerrojo eléctrico
    }


    cout << "\n====================================================" << endl;
    cout << "[FIN]: Sesion terminada. C++ libera la RAM del escaner solo." << endl;
    cout << "====================================================" << endl;
    
    return 0;
}