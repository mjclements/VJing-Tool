#include "VisualRenderer.hpp"
#include <SFML/Graphics.hpp>

VisualRenderer::VisualRenderer(){
    window =  new sf::RenderWindow(sf::VideoMode(800, 600), "OpenGL");
    window->setVerticalSyncEnabled(true);
    window->setActive(true);

}

void VisualRenderer::draw() {

}

VisualRenderer::~VisualRenderer(){
    visuals.clear();
    delete &visuals;
}