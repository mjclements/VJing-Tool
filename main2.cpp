
#include <SFML/Window.hpp>
#include "VisualRenderer.hpp"
#include "CircleVisualizer.hpp"
#include "AudioStream.hpp"
#include "MultiFrameAvgConnector.hpp"
#include "StdDevConnector.hpp"

#include "LinearConnector.hpp"
#include <iostream>

#include "VolumeAnalyzer.hpp"
//four circles that collide in the center and their radii enlarge in the center
int main()
{

    VisualRenderer *vRender = new VisualRenderer();
    // run the program as long as the window is open
    CircleVisualizer *tl = new CircleVisualizer(vRender->window);
    CircleVisualizer *tr = new CircleVisualizer(vRender->window);
    CircleVisualizer *bl = new CircleVisualizer(vRender->window);
    CircleVisualizer *br = new CircleVisualizer(vRender->window);

    auto sizes = vRender->window->getSize();
    auto size1 = sizes.x - 100;
    auto size2 = sizes.y - 100;
    AudioStream *as = new AudioStream();
    VolumeAnalyzer *va = new VolumeAnalyzer(as);

    LinearConnector *regularX  = new LinearConnector();
    regularX->setMin(0);
    regularX->setMax(size1);

    LinearConnector *regularY  = new LinearConnector();
    regularY->setMin(0);
    regularY->setMax(size2);

    LinearConnector *invX  = new LinearConnector();
    invX->setMin(size1);
    invX->setMax(0);

    LinearConnector *invY  = new LinearConnector();
    invY->setMin(size2);
    invY->setMax(0);
 
    MultiFrameAvgConnector *std = new MultiFrameAvgConnector(25);

    LinearConnector * rad = new LinearConnector();
    rad->setMax(400);
    rad->setMin(50);

    va->registerConnector(regularX);
    va->registerConnector(regularY);
    va->registerConnector(invX);
    va->registerConnector(invY);

    tl->setXConnector(regularX);
    tl->setYConnector(regularY);
    tl->setRedConnector(std);
    tl->setRadiusConnector(rad);


    tr->setXConnector(regularX);
    tr->setYConnector(invY);
    tr->setBlueConnector(std);
    tr->setRadiusConnector(rad);



    bl->setXConnector(invX);
    bl->setYConnector(regularY);
    bl->setGreenConnector(std);
    bl->setRadiusConnector(rad);


    br->setXConnector(invX);
    br->setYConnector(invY);
    br->setBlueConnector(std);
    br->setGreenConnector(std);
    br->setRadiusConnector(rad);






    //MultiFrameMaxConnector *lc = new MultiFrameMaxConnector(15);
    std::vector<CircleVisualizer *> circles = {};
    LinearConnector *lc2 = new LinearConnector();
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
        tl->draw();
        tr->draw();
        bl->draw();
        br->draw();
        // for(CircleVisualizer *c : circles){
 //       bottom->draw();
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