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
		RectF Bordered = rect.GetExpanded(padding);
		gfx.DrawRect(Bordered, color);
	}
}

bool Bricks::doBallCollsion(Ball & b)
{
	RectF brect = b.GetRect();
	if (!destroyed && rect.isOverLapping(brect))
	{
		const Vec2 ballCenter = b.GetCenter();
		if (ballCenter.x > rect.left && ballCenter.x < rect.right)
		{
			b.ReboundY();
		}
		else b.ReboundX();
		destroyed = true;
		return true;
	}
	return false;
}
