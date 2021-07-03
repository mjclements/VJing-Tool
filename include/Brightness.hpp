#pragma once
#include "Visual.hpp"
#include "Connector.hpp"
class Brightness : public Visual {
public:
    void draw();
private:
    double brightness;
};