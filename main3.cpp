
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
    regularX->setMin(size1/2);
    regularX->setMax(size1/2);

    LinearConnector *regularY  = new LinearConnector();
    regularY->setMin(size2/2);
    regularY->setMax(size2/2);

    LinearConnector *pointy  = new LinearConnector();
    pointy->setMin(3);
    pointy->setMax(25);

    LinearConnector *pointy2  = new LinearConnector();
    pointy2->setMin(25);
    pointy2->setMax(3);
 
    MultiFrameAvgConnector *rRange = new MultiFrameAvgConnector(25);
    rRange->setMax(500);
    rRange->setMin(0);

    MultiFrameAvgConnector *colorRange = new MultiFrameAvgConnector(25);
    rRange->setMax(500);
    rRange->setMin(100);

    LinearConnector * rad = new LinearConnector();
    rad->setMax(400);
    rad->setMin(50);

    LinearConnector * tlA = new LinearConnector();
    tlA->setMin(0);
    tlA->setMax(90);

    LinearConnector * trA = new LinearConnector();
    trA->setMin(180);
    trA->setMax(90);

    LinearConnector * brA = new LinearConnector();
    brA->setMin(180);
    brA->setMax(270);

    LinearConnector * blA = new LinearConnector();
    blA->setMin(360);
    blA->setMax(270);


    va->registerConnector(regularX);
    va->registerConnector(regularY);
    va->registerConnector(pointy);
    va->registerConnector(tlA);
    va->registerConnector(trA);
    va->registerConnector(blA);
    va->registerConnector(brA);
    va->registerConnector(pointy2);

    tl->setXConnector(regularX);
    tl->setYConnector(regularY);
    tl->setRedConnector(colorRange);
    tl->setRadiusConnector(rad);
    tl->setPointCountConnector(pointy);
    tl->setRConnector(rRange);
    tl->setAngleConnector(tlA);


    tr->setXConnector(regularX);
    tr->setYConnector(regularY);
    tr->setBlueConnector(colorRange);
    tr->setRadiusConnector(rad);
    tr->setRConnector(rRange);
    tr->setAngleConnector(trA);
    tr->setPointCountConnector(pointy2);

    



    bl->setXConnector(regularX);
    bl->setYConnector(regularY);
    bl->setGreenConnector(colorRange);
    bl->setRadiusConnector(rad);
    bl->setRConnector(rRange);
    bl->setAngleConnector(blA);
    bl->setPointCountConnector(pointy);


    br->setXConnector(regularX);
    br->setYConnector(regularY);
    br->setBlueConnector(colorRange);
    br->setGreenConnector(colorRange);
    br->setRadiusConnector(rad);
    br->setPointCountConnector(pointy2);
    br->setRConnector(rRange);
    br->setAngleConnector(brA);







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

    bottom->setBlueConnector(colorRange);

    va->registerConnector(rRange);
    va->registerConnector(colorRange);
    va->registerConnector(lc2);

    CircleVisualizer *c = new CircleVisualizer(vRender->window);
    lc2->setMax(800);
    LinearConnector *lc3 = new LinearConnector();
    lc3->setMax(size2);
    c->setXConnector(lc2);
    c->setYConnector(lc3);

    c->setRedConnector(colorRange);
    c->setGreenConnector(colorRange);

    while (vRender->window->isOpen())
    {
        as->getFrame();
        tl->draw();
        tr->draw();
        bl->draw();
        br->draw();
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