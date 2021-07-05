#pragma once
#include "AbstractVisualizer.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Connector.hpp"
class CircleVisualizer: public AbstractVisualizer{
    
    public:
        void draw();
        bool setBrightnessConnector(Connector *connector);
        bool isValid();
        CircleVisualizer(sf::RenderWindow * drawWindow);
        Connector *getRadiusConnector();
        void setRadiusConnector(Connector* connector);
        void setXConnector(Connector* connector);
        void setYConnector(Connector* connector);
        void setRedConnector(Connector* connector);
        void setGreenConnector(Connector* connector);
        void setBlueConnector(Connector* connector);

        ~CircleVisualizer();

    protected:
        Connector *radiusConnector;
        Connector *xConnector;
        Connector *yConnector;
        Connector *redConnector;
        Connector *blueConnector;
        Connector *greenConnector;
        uint16_t getRadius();
        uint16_t getX();
        uint16_t getY();
        sf::Color getColor();
    private:
        sf::CircleShape *circle;

};
