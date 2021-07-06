
#include <SFML/Window.hpp>
#include "VisualRenderer.hpp"
#include "CircleVisualizer.hpp"
#include "AudioStream.hpp"
#include "MultiFrameMaxConnector.hpp"
#include "StdDevConnector.hpp"

#include "LinearConnector.hpp"
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
    LinearConnector *lc2 = new LinearConnector();
    StdDevConnector *std = new StdDevConnector(15);
    LinearConnector *unchanging = new LinearConnector();
    unchanging->setMax(200);
    unchanging->setMin(200);
    LinearConnector *inverse = new LinearConnector();
    inverse->setMax(0);
    inverse->setMin(600);
    va->registerConnector(inverse);
    va->registerConnector(unchanging);

    CircleVisualizer * bottom = new CircleVisualizer(vRender->window);
    bottom->setYConnector(unchanging);
    bottom->setXConnector(inverse);

    bottom->setBlueConnector(std);

    va->registerConnector(std);
    va->registerConnector(lc2);
   // std::cout << size1 << "," << size2;
    // for(int i = 0; i < size1; i+= 200){
    //     for(int j = 0; j < size2; j += 200){
    //         CircleVisualizer *temp = new CircleVisualizer(vRender->window);
    //         temp->circle->setPosition(i,j);
    //         temp->setBlueConnector(lc2);
    //         temp->setRedConnector(lc2);
    //         temp->setGreenConnector(lc2);
    //         circles.push_back(temp);

    //     }
    // }
    CircleVisualizer *c = new CircleVisualizer(vRender->window);
    lc2->setMax(800);
    LinearConnector *lc3 = new LinearConnector();
    lc3->setMax(size2);
    c->setXConnector(lc2);
    c->setYConnector(lc3);

//    c->setBlueConnector(std);
        c->setRedConnector(std);
            c->setGreenConnector(std);





    //cv->setGreenConnector(lc);

    while (vRender->window->isOpen())
    {
        as->getFrame();
        // for(CircleVisualizer *c : circles){
        c->draw();
        bottom->draw();
        // }
        vRender->window->display();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (vRender->window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                vRender->window->close();
        }
        vRender->window->clear();
    }

    return 0;
}