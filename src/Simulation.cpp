#include "Simulation.hpp"
#include <iostream>

Simulation::Simulation()
    : m_window("Simulacion de Cinematica", sf::Vector2u(800, 600)),
      m_floor(sf::Color::White, sf::Vector2f(400, 500), sf::Vector2f(600, 30)),
      m_ball(sf::Color(204.0f, 77.0f, 5.0f), sf::Vector2f(500, 400),
             sf::Vector2f(30, 30)) {
    m_elapsed_fixedTime = 0.0f;
    m_elapsed_fixedTime_render = 0.0f;
}

Simulation::~Simulation() {} // No hace falta liberar memoria

void Simulation::HandleInput() {
    const float vel = 300.0f;
    m_window.Update();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_ball.setVelocity(-20.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_ball.Move(-vel * m_elapsed.asSeconds(), 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_ball.Move(vel * m_elapsed.asSeconds(), 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_ball.setVelocity(-20.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
        m_ball.setGravity(0.1f);
        m_ball.setPosition(sf::Vector2f(500, 400));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        m_ball.setGravity(1.0f);
        m_ball.setPosition(sf::Vector2f(500, 400));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        m_ball.setGravity(2.0f);
        m_ball.setPosition(sf::Vector2f(500, 400));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        m_ball.setGravity(3.0f);
        m_ball.setPosition(sf::Vector2f(500, 400));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        m_ball.setGravity(4.0f);
        m_ball.setPosition(sf::Vector2f(500, 400));
    }
}

void Simulation::Update() {
    float timestep = 1.0f / framesPerSecond;

    static bool collsionDetected { false };

    if (m_floor.GetCollider()->CheckColision(*m_ball.GetCollider(), 1)) {
        collsionDetected = true;
        m_ball.setVelocity(0.0f);
    } else {
        collsionDetected = false;
    }

    if (m_elapsed_fixedTime >= timestep) {
        m_elapsed_fixedTime -= timestep;
        // Calcular la collision
        if (!collsionDetected) {
            m_ball.UpdateVelocity();
            m_ball.UpdateYPosition();
        } else {
            m_ball.setVelocity(0.0f);
        }
    }
}

void Simulation::Render() {
    float timestep_render = 1.0f / 120.0f;
    if (m_elapsed_fixedTime_render >= timestep_render) {
        m_elapsed_fixedTime_render -= timestep_render;
        m_window.BeginDraw();
        m_floor.Render(*m_window.GetRenderWindow());
        m_ball.Render(*m_window.GetRenderWindow());
        m_window.EndDraw();
    }
}

Window* Simulation::GetWindow() { return &m_window; }

sf::Time Simulation::getElapsedTime() { return m_elapsed; }

void Simulation::RestartClock() {
    m_elapsed = m_clock.restart();
    m_elapsed_fixedTime_render += m_elapsed.asSeconds();
    m_elapsed_fixedTime += m_elapsed.asSeconds();
    // m_elapsed_fixedTime_printer += m_elapsed.asSeconds();
}
