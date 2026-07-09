#include "Relay.h"
#include <iostream>

Relay::Relay(int p) {
    pin = p;
    estadoActivado = false; // CORREGIDO
}

void Relay::activar() {
    estadoActivado = true;  // CORREGIDO
    std::cout << "[FISICO - PIN " << pin << "]: Enviando pulso de 5V. ¡Cerrojo Abierto!" << std::endl;
}

void Relay::desactivar() {
    estadoActivado = false; // CORREGIDO
    std::cout << "[FISICO - PIN " << pin << "]: Cortando energia. ¡Cerrojo Bloqueado!" << std::endl;
}

bool Relay::estaAbierto() const {
    return estadoActivado;  // CORREGIDO
}