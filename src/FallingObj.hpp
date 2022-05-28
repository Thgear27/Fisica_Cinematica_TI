#ifndef FALLINGOBJ_H
#define FALLINGOBJ_H

#include "Colider.hpp"
#include <SFML/Graphics.hpp>

class FallingObj {
public:
    FallingObj(sf::Color l_color, sf::Vector2f l_position, sf::Vector2f l_size);
    ~FallingObj();

    void Render(sf::RenderWindow& l_window);
    void UpdateYPosition();
    void UpdateVelocity();

    void setVelocity(float l_velocity);
    float getVelocity() const;
    void setGravity(float l_gravity);
    float getGravity() const;
    void setPosition(sf::Vector2f pos);

    // sf::Vector2f GetPosition();

    void Move(float dx, float dy);

    Colider* GetCollider();

private:
    sf::CircleShape m_body;
    sf::RectangleShape m_body_collider; // this is just to use it in the collider

    float m_velocity { 0.0f };
    float m_gravity { 1.0f };

    Colider m_collider;
};

#endif // FALLINGOBJ_H