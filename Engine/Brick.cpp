#include "Brick.h"

Bricks::Bricks(const RectF & rect_in, Color c)
	:
	rect(rect_in),
	color(c)
{
}

void Bricks::Draw(Graphics& gfx)
{
	gfx.DrawRect(rect, color);
}
