# 🔒 Sistema Modular de Control de Acceso Inteligente

Este proyecto consiste en un firmware de nivel industrial diseñado en **C++ Moderno** para la gestión segura de cerraduras magnéticas o electrónicas. Aplica patrones avanzados de herencia, polimorfismo y manejo automatizado de memoria RAM para sistemas embebidos de alta fiabilidad.

---

## 🛠️ Conceptos de Ingeniería Aplicados

A diferencia de los enfoques universitarios tradicionales, este desarrollo implementa las últimas normativas de código robusto exigidas por el mercado:

*   **Modularidad Avanzada:** Estructura limpia que independiza las definiciones de planos (`.h`) en la carpeta `include/` y el desarrollo lógico (`.cpp`) en la carpeta `src/`.
*   **Polimorfismo Dinámico Real:** Implementación de una clase base abstracta (`Usuario`) y métodos virtuales puros, permitiendo que un único puntero de escáner asimile y valide dinámicamente diferentes tipos de credenciales (`Administrador` o `Invitado`).
*   **Gestión Segura de Memoria (Smart Pointers):** Erradicación total de fugas de memoria (*Memory Leaks*) mediante la sustitución de punteros clásicos por `std::unique_ptr` de C++17, garantizando que el sistema destruya los datos anteriores en la RAM de forma automatizada al pasar un nuevo usuario.
*   **Inyección de Dependencias de Hardware:** Integración directa de un módulo de control eléctrico (`Relay`) aislado, encargado de simular de forma física la conmutación de pines de voltaje ante eventos lógicos aprobados.

---

## 📁 Arquitectura del Proyecto

```text
├── CMakeLists.txt        # Motor de automatización y ensamble de CMake
├── main.cpp              # Simulación secuencial de escenarios de acceso en tiempo real
├── include/              # Cabeceras y contratos de clases (.h)
│   ├── Relay.h
│   └── Usuario.h
└── src/                  # Lógica y desarrollo matemático de funciones (.cpp)
    ├── Relay.cpp
    └── Usuario.cpp
```

---

## 🚀 Tecnologías y Estándares

*   **Lenguaje:** C++ Moderno (Estándar C++17)
*   **Automatización de Fábrica:** CMake & GNU Make
*   **Control de Versiones:** Git & GitHub Distributed System
*   **Gestión de RAM:** Smart Pointers (`std::unique_ptr` & `std::move`)