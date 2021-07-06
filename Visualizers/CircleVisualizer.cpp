#include "CircleVisualizer.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <bitset>
#include <iostream>
#include <cmath>

CircleVisualizer::CircleVisualizer(sf::RenderWindow *drawWindow) : AbstractVisualizer(drawWindow)
{
    radiusConnector = nullptr;
    xConnector = nullptr;
    yConnector = nullptr;
    redConnector = nullptr;
    greenConnector = nullptr;
    blueConnector = nullptr;
    pointCountConnector = nullptr;
    rConnector = nullptr;
    angleConnector = nullptr;
    alphaConnector = nullptr;
    circle = new sf::CircleShape();
}

CircleVisualizer::~CircleVisualizer()
{
    delete circle;
}

void CircleVisualizer::draw()
{
    circle->setRadius(getRadius());
    circle->setPosition(getX(), getY());
    circle->setFillColor(getColor());
    circle->setPointCount(getPointCount());
    //   std::cout << getX() << " - " <<  getY() << std::endl;

    //std::cout << std::endl;
    window->draw(*circle);
}

void CircleVisualizer::setRadiusConnector(Connector *connector)
{
    radiusConnector = connector;
}

bool CircleVisualizer::isValid()
{
}

/**
 * Returns a SFML color representing the color of the circle based on subscribers.
 * Uses a 0 value for any un-intialiized connections.
 */
sf::Color CircleVisualizer::getColor()
{
    uint32_t rgba_code = 0x0;
    if (redConnector)
    {
        rgba_code = rgba_code | (redConnector->getValue() / 2) << 24;
    }
    if (greenConnector)
    {
        rgba_code = rgba_code | (greenConnector->getValue() / 2) << 16;
    }
    if (blueConnector)
    {
        rgba_code = rgba_code | (blueConnector->getValue() / 2) << 8;
    }
    if(alphaConnector){
        rgba_code = rgba_code | (alphaConnector->getValue()/2);
    }
    else{
        rgba_code = rgba_code | 126;
    }

    return sf::Color(rgba_code);
}

uint16_t CircleVisualizer::getX()
{
    if (xConnector && (!angleConnector || !rConnector))
    {
        return xConnector->getValue();
    }
    else if (angleConnector && rConnector)
    {
        return cos(angleConnector->getValue() * 3.14159 / 180) * rConnector->getValue() + xConnector->getValue();
    }
    else
    {
        return 0;
    }
}

uint16_t CircleVisualizer::getY()
{
    if (yConnector &&  (!angleConnector || !rConnector))
    {
        return yConnector->getValue();
    }
    else if (angleConnector && rConnector)
    {
        return sin(angleConnector->getValue() * 3.14159 / 180 ) * rConnector->getValue() + yConnector->getValue();
    }
    else
    {
        return 0;
    }
}

uint16_t CircleVisualizer::getPointCount()
{
    if (pointCountConnector)
    {
        return pointCountConnector->getValue();
    }
    else
    {
        return 30;
    }
}

uint16_t CircleVisualizer::getRadius()
{
    if (radiusConnector)
    {
        return radiusConnector->getValue();
    }
    else
    {
        return 100;
    }
}

Connector *CircleVisualizer::getRadiusConnector()
{
    return radiusConnector;
}

void CircleVisualizer::setXConnector(Connector *connector)
{
    xConnector = connector;
}

void CircleVisualizer::setYConnector(Connector *connector)
{
    yConnector = connector;
}
void CircleVisualizer::setAngleConnector(Connector *connector)
{
    angleConnector = connector;
}
void CircleVisualizer::setRConnector(Connector *connector)
{
    rConnector = connector;
}

void CircleVisualizer::setRedConnector(Connector *connector)
{
    redConnector = connector;
}

void CircleVisualizer::setGreenConnector(Connector *connector)
{
    greenConnector = connector;
}

void CircleVisualizer::setBlueConnector(Connector *connector)
{
    blueConnector = connector;
}

void CircleVisualizer::setAlphaConnector(Connector *connector){
    alphaConnector = connector;
}

bool CircleVisualizer::setBrightnessConnector(Connector *connector)
{
    greenConnector = connector;
    redConnector = connector;
    blueConnector = connector;
}

void CircleVisualizer::setPointCountConnector(Connector *connector)
{
    pointCountConnector = connector;
}
