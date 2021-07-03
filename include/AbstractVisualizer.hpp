#include <SFML/Graphics.hpp>

class AbstractVisualizer{
public:
    AbstractVisualizer(sf::RenderWindow * drawWindow);
    sf::RenderWindow *window;
    ~AbstractVisualizer();
};