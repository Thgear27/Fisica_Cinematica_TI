#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>

class Window {
public:
    // Calls the Setup() method with default arguments
    Window();
    // Calls the Setup() method
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    // Just close the window
    ~Window();

    // Clear the window
    void BeginDraw(); // Clear the window.
    // Display the changes
    void EndDraw();

    // Manage the events of the window
    void Update();
    // Return true if the window has to be closed or if it has closed already
    bool IsDone();
    bool IsFullscreen();

    sf::Vector2u GetWindowSize();
    void ToggleFullscreen();
    void Draw(sf::Drawable& l_drawable);

    sf::RenderWindow* GetRenderWindow();

private:
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);
    void Destroy();
    void Create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;

    bool m_isDone;
    bool m_isFullscreen;
};

#endif // WINDOW_H