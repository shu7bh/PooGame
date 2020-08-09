#pragma once
#include "Entity.h"
class Poo :
    public Entity
{
public:
    Poo() = delete;
    Poo(int x, int y);
    Poo(int x, int y, int r, int g, int b);

    void update(int x, int y);
    void keepInFrame(int right, int bottom);
    void draw(Graphics& gfx) const override;

    static constexpr int width = 24;
};

