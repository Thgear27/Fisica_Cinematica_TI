#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Text {
private:
    sf::Text m_text;
    std::string m_vstring { "GA" };
    sf::Font m_font;

public:
    Text(const sf::Vector2f& l_position, const std::string& l_vstring) {
        if (!m_font.loadFromFile("PressStartFont.ttf")) {
            std::cout << "Loading font failed\n";
        } else {
            m_text.setFont(m_font);
        }
        m_vstring = l_vstring;
        m_text.setCharacterSize(12);
        m_text.setPosition(l_position);
        m_text.setFillColor(sf::Color::White);
    }
    ~Text() {}

    template <typename T> void render(const T var_to_show, sf::RenderWindow& l_window) {
        m_text.setString(m_vstring + std::to_string(var_to_show));
        l_window.draw(m_text);
    }
};

#endif