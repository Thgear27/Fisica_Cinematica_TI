#include "Colider.hpp"
#include <cmath>

Colider::Colider(sf::RectangleShape& l_body) : body(l_body) {}

Colider::~Colider() {}

void Colider::Move(float dx, float dy) { body.move(dx, dy); }

sf::Vector2f Colider::GetPosition() { return body.getPosition(); }

sf::Vector2f Colider::GetHalfSize() { return body.getSize() / 2.0f; }

bool Colider::CheckColision(Colider& l_other, float push) {
    sf::Vector2f other_Position = l_other.GetPosition();
    sf::Vector2f other_Half_Size = l_other.GetHalfSize();
    sf::Vector2f this_Position = GetPosition();
    sf::Vector2f this_Half_Size = GetHalfSize();

    float Dx = other_Position.x - this_Position.x;
    float Dy = other_Position.y - this_Position.y;

    float intersectX = std::abs(Dx) - (other_Half_Size.x + this_Half_Size.x);
    float intersectY = std::abs(Dy) - (other_Half_Size.y + this_Half_Size.y);

    if (intersectX < 0.0f && intersectY < 0.0f) {
        push = std::min(std::max(push, 0.0f), 1.0f);
        if (intersectX > intersectY) { // intersectX(distance) is smaller than
            if (Dx > 0.0f) {
                // Moves to the left since intersectX is negative
                Move(intersectX * (1.0f - push), 0.0f);
                // Moves to the right since intersectX is negative
                l_other.Move(-intersectX * push, 0.0f);
            } else {
                // Moves to the right since intersectX is negative
                Move(-intersectX * (1.0f - push), 0.0f);
                // Moves to the left since intersectX is negative
                l_other.Move(intersectX * push, 0.0f);
            }
        } else {
            if (Dy > 0.0f) {
                Move(0.0f, intersectY * (1.0f - push));
                l_other.Move(0.0f, -intersectY * push);
            } else {
                Move(0.0f, -intersectY * (1.0f - push));
                l_other.Move(0.0f, intersectY * push);
            }
        }
        return true;
    } else {
        return false;
    }
}