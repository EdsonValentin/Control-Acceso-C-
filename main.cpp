#include <iostream>
#include <memory>    // Librería obligatoria para Smart Pointers (make_unique)
#include "Usuario.h" // Importamos nuestro plano de usuarios

using namespace std;

int main() {
    cout << "====================================================" << endl;
    cout << "===   SISTEMA DE CONTROL DE ACCESO INTELIGENTE   ===" << endl;
    cout << "====================================================" << endl;

    // 1. CREAMOS LOS USUARIOS CON PUNTEROS INTELIGENTES (RAM SEGURA)
    // Reservamos habitaciones limpias en la memoria RAM para cada tipo de usuario
    auto juanAdmin = make_unique<Administrador>("Juan (Admin)");
    auto mariaInvitadoValido = make_unique<Invitado>("Maria (Invitado)", true);
    auto carlosInvitadoVencido = make_unique<Invitado>("Carlos (Invitado)", false);

    // 2. EL PUNTERO POLIMÓRFICO INTELIGENTE
    // Creamos una variable abstracta de la clase base 'Usuario'
    unique_ptr<Usuario> puertaEscaner = nullptr;

    // --- ESCENARIO 1: Juan pasa su tarjeta por el escaner ---
    cout << "\n>>> [Escaneando Tarjeta 1...] <<<" << endl;
    puertaEscaner = move(juanAdmin); // Transferimos la llave de Juan al escaner
    
    cout << "Usuario: " << puertaEscaner->obtenerNombre() << endl;
    if (puertaEscaner->tieneAcceso()) {
        cout << "🔒 [ACCESO PERMITIDO]: Abriendo puerta magnetica..." << endl;
    } else {
        cout << "❌ [ACCESO DENEGADO]: Puerta bloqueada." << endl;
    }

    // --- ESCENARIO 2: Maria pasa su tarjeta (Pase Válido) ---
    cout << "\n>>> [Escaneando Tarjeta 2...] <<<" << endl;
    puertaEscaner = move(mariaInvitadoValido); // El escaner destruye a Juan y recibe a Maria
    
    cout << "Usuario: " << puertaEscaner->obtenerNombre() << endl;
    if (puertaEscaner->tieneAcceso()) {
        cout << "🔒 [ACCESO PERMITIDO]: Abriendo puerta magnetica..." << endl;
    } else {
        cout << "❌ [ACCESO DENEGADO]: Puerta bloqueada." << endl;
    }

    // --- ESCENARIO 3: Carlos pasa su tarjeta (Pase Vencido) ---
    cout << "\n>>> [Escaneando Tarjeta 3...] <<<" << endl;
    puertaEscaner = move(carlosInvitadoVencido); // El escaner destruye a Maria y recibe a Carlos
    
    cout << "Usuario: " << puertaEscaner->obtenerNombre() << endl;
    if (puertaEscaner->tieneAcceso()) {
        cout << "🔒 [ACCESO PERMITIDO]: Abriendo puerta magnetica..." << endl;
    } else {
        cout << "❌ [ACCESO DENEGADO]: Puerta bloqueada." << endl;
    }

    cout << "\n[FIN]: El programa termina y los Smart Pointers limpian la RAM solo." << endl;
    return 0;
}