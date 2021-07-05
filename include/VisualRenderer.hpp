#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class AbstractVisualizer;

class VisualRenderer {
    public:
        VisualRenderer();
        ~VisualRenderer();
        void draw();
        bool addVisual(AbstractVisualizer *visual);
//    protected: for now
        std::vector<AbstractVisualizer *> visuals;
        sf::RenderWindow *window;
};
