#pragma once
#include "Entity.h"
#include "MainWindow.h"

class Player :
    public Entity
{
public:
    bool inhibitUp = false, inhibitDown = false, inhibitRight = false, inhibitLeft = false, inhibitDrop = false;
    Player() = delete;
    Player(Vec2D& coordinate);
    Player(Vec2D& coordinate, int r, int g, int b);
    void update(const float dt);

    void draw(Graphics& gfx) const override;
    void keyPressed(MainWindow& wnd);
public:

    int score = 0;
    static constexpr int width = 20;
};

