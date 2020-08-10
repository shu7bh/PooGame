#pragma once
#include "Entity.h"
class Poo :
    public Entity
{
public:
    Poo() = delete;
    Poo(Vec2D& coordinate);
    Poo(Vec2D& coordinate, int r, int g, int b);

    void update(const float dt);
    void keepInFrame(Vec2D& vertice);
    void draw(Graphics& gfx) const override;

    static constexpr int width = 24;
};

