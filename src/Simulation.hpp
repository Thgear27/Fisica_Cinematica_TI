#ifndef SIMULATION_H
#define SIMULATION_H

#include "FallingObj.hpp"
#include "Platform.hpp"
#include "Window.hpp"
#include "Text.hpp"

// Definicion de la clase Simulation
class Simulation {
public:
    Simulation();        // Constructor
    ~Simulation();       // Destructor
    void HandleInput();  // Maneja la entrada de teclado
    void Update();       // Realiza una acutalizacion de la clase
    void Render();       // Dibuja en la ventana
    Window* GetWindow(); // Retorna un putero de tipo Window

    sf::Time getElapsedTime(); // Retorna el tiempo entre cada iteraicion
    void RestartClock();       // Reinicia el reloj (lo deja en cero)

private:
    sf::Clock m_clock; // Crea un reloj de SFML

    sf::Time m_elapsed; // Variable donde se guardara el tiempo entre cada iteracion
    float m_elapsed_fixedTime = 0.0f; // lo mismo de arriba pero en float
    float m_elapsed_fixedTime_render = 0.0f;

    Window m_window;
    const float framesPerSecond { 60 };

    /// Objetos agregados fuera del funcionamiento principal de la clase
    /////////////////////////////////////////////////////////////
    Platform m_floor;  // El suelo de la simulacion
    FallingObj m_ball; // EL objeto que cae en la simulacion
    Text m_vvGravity;
    Text m_vvVelocity;
    /////////////////////////////////////////////////////////////
};

#endif // SIMULATION_H
