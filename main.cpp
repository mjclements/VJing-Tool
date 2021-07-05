
#include <SFML/Window.hpp>
#include "VisualRenderer.hpp"
#include "CircleVisualizer.hpp"
#include "AudioStream.hpp"
#include "MultiFrameMaxConnector.hpp"
#include "StdDevConnector.hpp"
#include <iostream>

#include "VolumeAnalyzer.hpp"
int main()
{

    VisualRenderer *vRender = new VisualRenderer();
    // run the program as long as the window is open
    CircleVisualizer *cv = new CircleVisualizer(vRender->window);
    CircleVisualizer *cv2 = new CircleVisualizer(vRender->window);
    CircleVisualizer *cv3 = new CircleVisualizer(vRender->window);
    cv2->circle->setPosition(200.0,0.0);
    cv3->circle->setPosition(200.0,0.0);
    auto sizes = vRender->window->getSize();
    auto size1 = sizes.x;
    auto size2 = sizes.y;
    AudioStream *as = new AudioStream();
    VolumeAnalyzer *va = new VolumeAnalyzer(as);
    MultiFrameMaxConnector *lc = new MultiFrameMaxConnector(15);
    std::vector<CircleVisualizer *> circles = {};
    StdDevConnector *lc2 = new StdDevConnector(15);
    va->registerConnector(lc2);
    std::cout << size1 << "," << size2;
    for(int i = 0; i < size1; i+= 200){
        for(int j = 0; j < size2; j += 200){
            CircleVisualizer *temp = new CircleVisualizer(vRender->window);
            temp->circle->setPosition(i,j);
            temp->setBlueConnector(lc2);
            temp->setRedConnector(lc2);
            temp->setGreenConnector(lc2);
            circles.push_back(temp);

        }
    }


    //cv->setGreenConnector(lc);

    while (vRender->window->isOpen())
    {
        as->getFrame();
        for(CircleVisualizer *c : circles){
            c->draw();
        }
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