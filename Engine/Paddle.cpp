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
	RectF brect = b.GetRect();
	if (rect.isOverLapping(brect))
	{
		if (brect.bottom > rect.top && brect.right > rect.left && brect.left<rect.left) //top left corner of paddle
		{
			b.ReboundX();
			b.ReboundY();
			return true;
		}
		else if (brect.bottom > rect.top && brect.left < rect.right && brect.right>rect.right) // top right corner of paddle
		{
			b.ReboundX();
			b.ReboundY();
			return true;
		}
		else if (brect.right > rect.left && brect.left<rect.left)
		{
			
			b.ReboundX();
			return true;
		}
		else if (brect.left < rect.right && brect.right>rect.right)
		{
			b.ReboundX();
			return true;
		}
		else if(brect.bottom>rect.top && brect.top<rect.top)
		{
			b.ReboundY();
			return true;
		}
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

