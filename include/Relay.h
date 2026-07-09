#ifndef RELAY_H
#define RELAY_H

class Relay {
private:
    int pin;
    bool estadoActivado;

public:
    Relay(int p);
    void activar();
    void desactivar();
    bool estaAbierto() const;
};

#endif