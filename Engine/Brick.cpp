#include "Brick.h"

Bricks::Bricks(const RectF & rect_in, Color c)
	:
	rect(rect_in),
	color(c)
{
}

void Bricks::Draw(Graphics& gfx)
{
	if (!destroyed)
	{
		gfx.DrawRect(rect, color);
	}
}

bool Bricks::doBallCollsion(Ball & b)
{
	RectF brect = b.GetRect();
	if (!destroyed && rect.isOverLapping(brect))
	{
		if (brect.right > rect.left && brect.left < rect.left) //checks if hit the left side of a brick
		{
			b.ReboundX();
		}
		else if (brect.left<rect.right &&brect.right>rect.right)
		{
			b.ReboundX();
		}
		else
		{
			b.ReboundY();
		}
		destroyed = true;
		return true;
	}
	return false;
}
