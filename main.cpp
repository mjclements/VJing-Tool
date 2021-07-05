
#include <SFML/Window.hpp>
#include "VisualRenderer.hpp"
#include "CircleVisualizer.hpp"
#include "AudioStream.hpp"
#include "LinearConnector.hpp"
#include "VolumeAnalyzer.hpp"
int main()
{

    VisualRenderer *vRender = new VisualRenderer();
    // run the program as long as the window is open
    CircleVisualizer *cv = new CircleVisualizer(vRender->window);
    AudioStream *as = new AudioStream();
    VolumeAnalyzer *va = new VolumeAnalyzer(as);
    LinearConnector *lc = new LinearConnector();
    va->registerConnector(lc);
    cv->setRadiusConnector(lc);
    cv->setBlueConnector(lc);
    cv->setRedConnector(lc);
    cv->setGreenConnector(lc);

    while (vRender->window->isOpen())
    {
        as->getFrame();
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