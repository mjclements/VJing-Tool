#include "CircleVisualizer.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <bitset>
#include <iostream>


CircleVisualizer::CircleVisualizer(sf::RenderWindow * drawWindow) : AbstractVisualizer(drawWindow)
{
    radiusConnector = nullptr;
    xConnector = nullptr;
    yConnector = nullptr;
    redConnector = nullptr;
    greenConnector = nullptr;
    blueConnector = nullptr;
    circle = new sf::CircleShape();
}

CircleVisualizer::~CircleVisualizer()
{
	delete circle;
}

void	CircleVisualizer::draw()
{
    circle->setRadius(getRadius());
    circle->setPosition(getX(), getY());
    circle->setFillColor(getColor());
    std::cout << getRadius() << getColor().toInteger();

    std::cout << std::endl;
    window->draw(*circle);
}

void	CircleVisualizer::setRadiusConnector(Connector *connector)
{
    radiusConnector = connector;
}

bool	CircleVisualizer::isValid()
{
	
}

/**
 * Returns a SFML color representing the color of the circle based on subscribers.
 * Uses a 0 value for any un-intialiized connections.
 */
sf::Color	CircleVisualizer::getColor()
{
    uint32_t rgba_code = 2550000; 
    if(redConnector){
        rgba_code = rgba_code | (redConnector->getValue() / 2) << 24;
    }
    if(greenConnector){
        rgba_code = rgba_code | (greenConnector->getValue() / 2) << 16;
    }
    if(blueConnector){
        rgba_code = rgba_code | (blueConnector->getValue() / 2) << 8;
    }
    u_int8_t alpha = 126; //Do we want alpha? Probably.
    rgba_code = rgba_code | alpha;

    return sf::Color(rgba_code);
}

uint16_t CircleVisualizer::getX()
{
    if(xConnector){
        return xConnector->getValue();
    } else {
        return 0;
    }

}

uint16_t CircleVisualizer::getY()
{
    if(yConnector){
        return yConnector->getValue();
    } else {
        return 0;
    }

}

uint16_t CircleVisualizer::getRadius()
{
    if(radiusConnector){
        return radiusConnector->getValue();
    } else {
        return 100;
    }

}

Connector *	CircleVisualizer::getRadiusConnector()
{
    return radiusConnector;
}

void	CircleVisualizer::setXConnector(Connector* connector)
{
	xConnector = connector;
}

void	CircleVisualizer::setYConnector(Connector* connector)
{
	yConnector = connector;
}

void	CircleVisualizer::setRedConnector(Connector* connector)
{
	redConnector = connector;
}

void	CircleVisualizer::setGreenConnector(Connector* connector)
{
	greenConnector = connector;
}

void	CircleVisualizer::setBlueConnector(Connector* connector)
{
	blueConnector = connector;
}

bool	CircleVisualizer::setBrightnessConnector(Connector *connector)
{
	
}