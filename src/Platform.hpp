#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include "Colider.hpp"

class Platform {
public:
    Platform(sf::Color l_color, sf::Vector2f position, sf::Vector2f size);
    ~Platform();

    void Render(sf::RenderWindow& l_window);
    void Move(float dx, float dy);

    Colider* GetCollider();

private:
    sf::RectangleShape body;    
    Colider collider;
};

#endif // PLATFORM_H
