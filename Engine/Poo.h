#pragma once
#include "Entity.h"
class Poo :
    public Entity
{
public:
    Poo() = delete;
    Poo(float x, float y);
    Poo(float x, float y, int r, int g, int b);

    void update(const float dt);
    void keepInFrame(int right, int bottom);
    void draw(Graphics& gfx) const override;

    static constexpr int width = 24;
};

