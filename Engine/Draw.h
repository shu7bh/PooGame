#pragma once
#include "Graphics.h"

namespace Draw
{
	void circle(Graphics& gfx, const int x, const int y, const int r, const Color c);
	void started(Graphics& gfx, const int x, const int y);
	void ended(Graphics& gfx, const int x, const int y);
	void progressBar(Graphics& gfx, const int score, const int maxScore);
}