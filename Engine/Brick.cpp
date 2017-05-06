#include "Brick.h"

Bricks::Bricks(const RectF & rect_in, Color c)
	:
	rect(rect_in),
	color(c)
{
}

void Bricks::Draw(Graphics& gfx) const
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
		if (brect.right > rect.left && brect.left < rect.left && brect.top < rect.bottom)// bottom left corner
		{
		//	b.ReboundX();
			b.ReboundY();
		}
		else if (brect.right > rect.left && brect.left < rect.left && brect.bottom < rect.top) // top left corner
		{
		//	b.ReboundX();
			b.ReboundY();
		}
		else if (brect.left<rect.right &&brect.right>rect.right && brect.top < rect.bottom) // bottom right
		{
		//	b.ReboundX();
			b.ReboundY();
		}
		else if (brect.left<rect.right &&brect.right>rect.right && brect.bottom < rect.top) // top right
		{
		//	b.ReboundX();
			b.ReboundY();
		}
		else if (brect.right > rect.left && brect.left < rect.left) //checks if hit the left side of a brick
		{
			b.ReboundX();
		}
		else if (brect.left<rect.right &&brect.right>rect.right) // check if hit the right side of brick
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
