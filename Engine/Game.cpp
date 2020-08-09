/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>
#include <ctime>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	player(400.0f, 300.0f)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!isEnded)
	{
		if (isStarted)
		{
			for (size_t i = poos.size(); i < count; ++i)
				addPoo();

			keyPressed();


			for (auto it = poos.begin(); it != poos.end(); ++it)
				if (Entity::checkCollision(*it, player))
				{
					player.score += 1;
					poos.erase(it);
					if (player.score >= maxScore)
						isEnded = true;
					break;
				}


			player.update();
			player.keepInFrame(gfx.ScreenWidth, gfx.ScreenHeight - 10);

			for (Poo& poo : poos)
			{
				poo.update();
				poo.keepInFrame(gfx.ScreenWidth, gfx.ScreenHeight - 10);

			}
		}
		else if (wnd.kbd.KeyIsPressed(VK_RETURN))
			isStarted = true;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RETURN))
		exit(0);
}

void Game::ComposeFrame()
{
	if (isStarted && !isEnded)
	{
		for (const auto& poo : poos)
			poo.draw(gfx);
		player.draw(gfx);
		Draw::progressBar(gfx, player.score, maxScore);
	}
	else if (isEnded)
		Draw::progressBar(gfx, player.score, maxScore), Draw::ended(gfx, 350, 250);
	else
		//Draw::circle(gfx, 400, 300, 200, Colors::White);
		Draw::started(gfx, 300, 200);
}

void Game::addPoo()
{
	static std::default_random_engine seed(static_cast<unsigned int>(time(0)));
	static std::uniform_real_distribution<float> randomX(0, gfx.ScreenWidth - Poo::width - 1);
	static std::uniform_real_distribution<float> randomY(0, gfx.ScreenHeight - Poo::width - 1);
	static std::uniform_int_distribution<int> color(150, 256);

	int r = color(seed), g = color(seed), b = color(seed);
	bool isDone;
	Poo poo(randomX(seed), randomY(seed), r, g, b);
	do
	{
		isDone = true;
		poo.x = randomX(seed), poo.y = randomY(seed);
		for (const auto& oldPoo : poos)
			if (Entity::checkCollision(oldPoo, poo))
				isDone = false;
		if (Entity::checkCollision(player, poo))
			isDone = false;
	}while (!isDone);

	static std::uniform_real_distribution<float> randomVDir(-2.0f, 2.0f);

	poo.vx = randomVDir(seed);
	poo.vy = randomVDir(seed);

	poos.push_back(poo);
}

void Game::keyPressed()
{
	if (wnd.kbd.KeyIsPressed(VK_UP) || wnd.kbd.KeyIsPressed('W'))
		if (!player.inhibitUp)
			player.vy -= 1, player.inhibitUp = true;
		else;
	else
		player.inhibitUp = false;

	if (wnd.kbd.KeyIsPressed(VK_DOWN) || wnd.kbd.KeyIsPressed('S'))
		if (!player.inhibitDown)
			player.vy += 1, player.inhibitDown = true;
		else;
	else
		player.inhibitDown = false;

	if (wnd.kbd.KeyIsPressed(VK_LEFT) || wnd.kbd.KeyIsPressed('A'))
		if (!player.inhibitLeft)
			player.vx -= 1, player.inhibitLeft = true;
		else;
	else
		player.inhibitLeft = false;

	if (wnd.kbd.KeyIsPressed(VK_RIGHT) || wnd.kbd.KeyIsPressed('D'))
		if (!player.inhibitRight)
			player.vx += 1, player.inhibitRight = true;
		else;
	else
		player.inhibitRight = false;
}
