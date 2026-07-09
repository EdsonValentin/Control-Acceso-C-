#include "Usuario.h"

// 1. Desarrollamos el constructor de la clase base Usuario
Usuario::Usuario(std::string n) {
    nombre = n;
}

// 2. Desarrollamos el método para obtener el nombre
std::string Usuario::obtenerNombre() const {
    return nombre;
}

// 3. Desarrollamos el constructor del Administrador (Llama al constructor base)
Administrador::Administrador(std::string n) : Usuario(n) {}

// 4. Desarrollamos la regla de negocio: el Admin siempre entra
bool Administrador::tieneAcceso() const {
    return true; 
}

// 5. Desarrollamos el constructor del Invitado
Invitado::Invitado(std::string n, bool valido) : Usuario(n) {
    paseValido = valido;
}

// 6. Desarrollamos su regla: solo entra si su pase es verdadero
bool Invitado::tieneAcceso() const {
    return paseValido;
}