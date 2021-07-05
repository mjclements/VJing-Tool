#include "AbstractVisualizer.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>




AbstractVisualizer::AbstractVisualizer(sf::RenderWindow * drawWindow)
{
	window = drawWindow;
}

AbstractVisualizer::~AbstractVisualizer()
{
	
}