#include "Paddle.h"

Paddle::Paddle(const Vec2 pos_in)
	:
	pos(pos_in)
{
}

void Paddle::Draw(Graphics & gfx)
{
	RectF rect = GetRect();
	gfx.DrawRect(rect,WingColor);
	rect.left += halfwingWidth;
	rect.right -= halfwingWidth;
	gfx.DrawRect(rect, color);
	
}

void Paddle::Update(Keyboard & kbrd, float dt)
{
	if (kbrd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed *dt;
	}
	else if (kbrd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed*dt;
	}
}

bool Paddle::doBallCollision(Ball & b)
{
	RectF rect = GetRect();
	RectF bRect = b.GetRect();
	if (rect.isOverLapping(bRect))
	{
		b.ReboundY();
	}
	return false;
}

bool Paddle::doWallCollision(const RectF & walls)
{
	RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right)
	{
		pos.x += walls.right - rect.right;
	}
	return false;
}

RectF Paddle::GetRect() const
{
	return RectF(RectF::FromCenter(pos,halfWidth,halfHeight));
}

