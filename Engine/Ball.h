#pragma once

#include "Vec2.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in);
	void Draw(Graphics& gfx);
	void Update(float dt);
	void ReboundX();
	void ReboundY();
	bool doWallCollision(const RectF& walls);
	RectF GetRect()const;
	Vec2 GetVelocity()const;
	Vec2 GetCenter()const;
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float radius = 7.0f;
};