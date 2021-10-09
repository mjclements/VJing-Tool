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
        void setPointCountConnector(Connector * connect);
        void setRConnector(Connector* connector );
        void setAngleConnector(Connector* connector );
        void setAlphaConnector(Connector* connector );
        void setThicknessConnector(Connector* connector);
        void setOutlineColorConnector(Connector* connector);


        sf::CircleShape *circle;


        ~CircleVisualizer();

    protected:
        Connector *radiusConnector;
        Connector *xConnector;
        Connector *yConnector;
        Connector *redConnector;
        Connector *blueConnector;
        Connector *greenConnector;
        Connector *pointCountConnector;
        Connector *rConnector;
        Connector *angleConnector;
        Connector * alphaConnector;
        Connector* thicknessConnector;
        Connector* outlineColorConnector;
        uint16_t getPointCount();
        uint16_t getRadius();
        uint16_t getX();
        uint16_t getY();
        sf::Color getColor();
        sf::Color getOutlineColor();
    private:
 //       sf::CircleShape *circle;

};
