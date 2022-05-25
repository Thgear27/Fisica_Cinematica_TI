#ifndef COLIDER_H
#define COLIDER_H

#include <SFML/Graphics.hpp>

class Colider { // I know it's collider, i don't want to work for change all Colider to
                // Collider
public:
    Colider(sf::RectangleShape& l_body);
    ~Colider();

    void Move(float dx, float dy);
    sf::Vector2f GetPosition();
    sf::Vector2f GetHalfSize();

    bool CheckColision(Colider& l_other, float push);

private:
    sf::RectangleShape& body;
};

#endif // COLIDER_H