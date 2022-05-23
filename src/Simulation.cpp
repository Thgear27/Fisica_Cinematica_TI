#include "Simulation.hpp"
#include <iostream>

Simulation::Simulation() : m_window("Simulacion de Cinematica", sf::Vector2u(800, 600)) {
    m_elapsed_fixedTime = 0.0f;
    // m_window.GetRenderWindow()->setFramerateLimit(60);
}

Simulation::~Simulation() {}

void Simulation::HandleInput() {
    m_window.Update();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        std::cout << "UP\n";
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        std::cout << "DOWN\n";
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        std::cout << "LEFT\n";
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        std::cout << "RIGHT\n";
    }
}

void Simulation::Update() {
    float timestep = 1.0f / framesPerSecond;

    if (m_elapsed_fixedTime >= timestep) {
        m_elapsed_fixedTime -= timestep;
    }
}

void Simulation::Render() {
    m_window.BeginDraw();
    m_window.EndDraw();
}

Window* Simulation::GetWindow() { return &m_window; }

sf::Time Simulation::getElapsedTime() { return m_elapsed; }

void Simulation::RestartClock() {
    m_elapsed = m_clock.restart();
    m_elapsed_fixedTime += m_elapsed.asSeconds();
}
