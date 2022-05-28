#ifndef SIMULATION_H
#define SIMULATION_H

#include "Window.hpp"
#include "Platform.hpp"
#include "FallingObj.hpp"

class Simulation {
public:
    Simulation();
    ~Simulation();
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();

    sf::Time getElapsedTime();
    void RestartClock();

    /// Member functions added
    /////////////////////////////////////////////////////////////
    
    /////////////////////////////////////////////////////////////
private:
    sf::Clock m_clock;

    sf::Time m_elapsed;
    float m_elapsed_fixedTime = 0.0f;
    float m_elapsed_fixedTime_render = 0.0f;
    float m_elapsed_fixedTime_printer = 0.0f;

    Window m_window;
    const float framesPerSecond { 60 };
    
    /// Objets added
    /////////////////////////////////////////////////////////////
    Platform m_floor;
    FallingObj m_ball;
    /////////////////////////////////////////////////////////////
};

#endif // SIMULATION_H
