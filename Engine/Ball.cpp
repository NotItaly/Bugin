#include "Ball.h"

Ball::Ball(const Vec2 & pos_in, const Vec2 & vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::Draw(Graphics & gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel*dt;
	
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

bool Ball::doWallCollision(const RectF & walls)
{
	bool collided = false;
	RectF rect = GetRect();
	if (rect.left < walls.left && rect.top < walls.top) //top left corner hit
	{
		pos.x += walls.left - rect.left;
		pos.y += walls.top - rect.top;
		ReboundX();
		ReboundY();
		collided = true;
	}
	else if (rect.right > walls.right && rect.top < walls.top) // top right corner hit
	{
		pos.x -= rect.right - walls.right;
		pos.y += walls.top - rect.top;
		ReboundX();
		ReboundY();
		collided = true;
	}
	else if (rect.left < walls.left && rect.bottom > walls.bottom) //bottom left corner hit
	{
		pos.x += walls.left - rect.left;
		pos.y -= rect.bottom - walls.bottom;
		ReboundX();
		ReboundY();
		collided = true;
	}
	else if (rect.right > walls.right && rect.bottom > walls.bottom) // bottom right corner hit
	{
		pos.x -= rect.right - walls.right;
		pos.y -= rect.bottom - walls.bottom;
		ReboundX();
		ReboundY();
		collided = true;
	}
	else if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
		collided = true;
	}
	else if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}

Vec2 Ball::GetCenter() const
{
	return Vec2(pos);
}
