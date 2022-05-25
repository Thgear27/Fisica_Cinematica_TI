#include "Platform.hpp"

Platform::Platform(sf::Color l_color, sf::Vector2f position, sf::Vector2f size) {
    body.setFillColor(l_color);
    body.setPosition(position);
    body.setSize(size);
    body.setOrigin(size / 2.0f);
}

Platform::~Platform() {}

void Platform::Render(sf::RenderWindow& l_window) { l_window.draw(body); }

Colider Platform::GetCollider() { return Colider { body }; }
