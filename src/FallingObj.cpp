#include "FallingObj.hpp"

FallingObj::FallingObj(sf::Color l_color, sf::Vector2f l_position, sf::Vector2f l_size)
    : m_collider(m_body_collider) {
    m_body.setFillColor(l_color);
    m_body.setPosition(l_position);
    m_body.setRadius(l_size.x / 2.0f);
    m_body.setOrigin(l_size / 2.0f);

    m_body_collider.setFillColor(l_color);
    m_body_collider.setPosition(l_position);
    m_body_collider.setSize(l_size);
    m_body_collider.setOrigin(l_size / 2.0f);
}

FallingObj::~FallingObj() {}

void FallingObj::Render(sf::RenderWindow& l_window) {
    m_body.setPosition(m_body_collider.getPosition());
    l_window.draw(m_body);
}

void FallingObj::Move(float dx, float dy) {
    // m_body.move(dx, dy);
    m_body_collider.move(dx, dy);
}

void FallingObj::UpdateYPosition(float l_aceleration) {
    // float Yo = m_body.getPosition().y;
    const float time { 1 };
    float Dy = m_velocity * time + (0.5f) * l_aceleration * time;
    Move(0, Dy);
}

void FallingObj::UpdateVelocity(float l_aceleration) {
    const float time { 1 };
    m_velocity = m_velocity + l_aceleration * time;
}

// sf::Vector2f FallingObj::GetPosition() {
//     return m_body.getPosition();
// }
void FallingObj::setVelocity(float l_velocity) {
    m_velocity = l_velocity;
}

Colider* FallingObj::GetCollider() { return &m_collider; }