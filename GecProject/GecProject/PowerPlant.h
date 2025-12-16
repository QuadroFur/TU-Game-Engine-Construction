#pragma once
#include "Structure.h"
#include "Graphics.h"

class PowerPlant :
    public Structure
{
private:
    int PowerProduction{ 10 };
public:
    PowerPlant(Graphics& WorldGraphics);
};

