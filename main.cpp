
#include <SFML/Window.hpp>

#include "VisualRenderer.hpp"
#include "CircleVisualizer.hpp"
int main()
{

    VisualRenderer *vRender = new VisualRenderer();
    // run the program as long as the window is open
    CircleVisualizer *cv = new CircleVisualizer(vRender->window);
    while (vRender->window->isOpen())
    {
        cv->draw();
        vRender->window->display();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (vRender->window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                vRender->window->close();
        }
    }

    return 0;
}