#ifndef USUARIO_H
#define USUARIO_H

#include <string>

// 1. La Clase Base Abstracta (El contrato para cualquier usuario)
class Usuario {
protected:
    std::string nombre;

public:
    Usuario(std::string n);
    
    // Método virtual puro: obliga a los hijos a decidir su lógica de acceso
    virtual bool tieneAcceso() const = 0; 
    
    std::string obtenerNombre() const;
    virtual ~Usuario() {} // Destructor virtual obligatorio
};

// 2. Clase Hija 1: El Administrador (Hereda de Usuario)
class Administrador : public Usuario {
public:
    Administrador(std::string n);
    bool tieneAcceso() const override; // El administrador SIEMPRE tendrá acceso
};

// 3. Clase Hija 2: El Invitado (Hereda de Usuario)
class Invitado : public Usuario {
private:
    bool paseValido; // Una bandera para saber si su tarjeta tiene permiso hoy

public:
    Invitado(std::string n, bool valido);
    bool tieneAcceso() const override; // Su acceso depende de la bandera 'paseValido'
};

#endif