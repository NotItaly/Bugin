#include "Brick.h"
#include <assert.h>

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

void Bricks::ExecuteBallCollision(Ball & b)
{
	assert(isBallCollsion(b));

	RectF brect = b.GetRect();
	const Vec2 ballCenter = b.GetCenter();
	if (std::signbit(b.GetVelocity().x) == std::signbit(b.GetCenter().x - GetCenter().x))
	{
		b.ReboundY();
	}
	else if (ballCenter.x >= rect.left && ballCenter.x <= rect.right)
	{
		b.ReboundY();
	}
	else
	{
		b.ReboundX();
	}
	destroyed = true;
}

Vec2 Bricks::GetCenter() const
{
	return rect.GetCenter();
}

bool Bricks::isBallCollsion(const Ball & b) const
{
	return !destroyed && rect.isOverLapping(b.GetRect());
}
