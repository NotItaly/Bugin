#pragma once

#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"

class Bricks
{
public:
	Bricks(const RectF& rect_in, Color c);
	void Draw(Graphics& gfx);
private:
	RectF rect;
	Color color;
	bool destroyed = false;
	static constexpr float padding = 2.0f;
};