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
	player(Vec2D(400.0f, 300.0f))
{
	dt = execTime.getExecutionTime();
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
			dt = execTime.getExecutionTime();
			for (size_t i = poos.size(); i < count; ++i)
				addPoo();

			player.keyPressed(wnd);


			for (auto it = poos.begin(); it != poos.end(); ++it)
				if (Entity::checkCollision(*it, player))
				{
					player.score += 1;
					poos.erase(it);
					if (player.score >= maxScore)
						isEnded = true;
					break;
				}


			player.update(dt);
			player.keepInFrame(Vec2D(gfx.ScreenWidth, gfx.ScreenHeight - 10));

			for (Poo& poo : poos)
			{
				poo.update(dt);
				poo.keepInFrame(Vec2D(gfx.ScreenWidth, gfx.ScreenHeight - 10)); // The 10 px as
													// the progress bar is shown at the bottom
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
	Poo poo(Vec2D(randomX(seed), randomY(seed)), r, g, b);
	do
	{
		isDone = true;
		poo.coordinate.x = randomX(seed), poo.coordinate.y = randomY(seed);
		for (const auto& oldPoo : poos)
			if (Entity::checkCollision(oldPoo, poo))
				isDone = false;
		if (Entity::checkCollision(player, poo))
			isDone = false;
	}while (!isDone);

	static std::uniform_real_distribution<float> randomVDir(-2.0f * 60.0f, 2.0f * 60.0f);

	poo.velocity.x = randomVDir(seed);
	poo.velocity.y = randomVDir(seed);

	poos.push_back(poo);
}