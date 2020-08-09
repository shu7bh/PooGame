#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:
    bool inhibitUp = false, inhibitDown = false, inhibitRight = false, inhibitLeft = false, inhibitDrop = false;
    Player() = delete;
    Player(int x, int y);
    Player(int x, int y, int r, int g, int b);
    void update();

    void draw(Graphics& gfx) const override;
    int score = 0;

    static constexpr int width = 20;
};

