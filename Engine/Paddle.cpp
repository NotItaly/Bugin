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
	if (!isCoolDown)
	{
		RectF rect = GetRect();
		RectF brect = b.GetRect();
		const Vec2 ballCenter = b.GetCenter();
		if (rect.isOverLapping(brect))
		{
			if (std::signbit(b.GetVelocity().x) == std::signbit(b.GetCenter().x - pos.x))
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
			isCoolDown = true;
			return true;
		}
		return false;
	}
	else return false;
}

void Paddle::doWallCollision(const RectF & walls)
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
}

RectF Paddle::GetRect() const
{
	return RectF(RectF::FromCenter(pos,halfWidth,halfHeight));
}

void Paddle::ResetCoolDown()
{
	isCoolDown = false;
}

