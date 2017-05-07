#pragma once

#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Ball.h"

class Bricks
{
public:
	Bricks() = default;
	Bricks(const RectF& rect_in, Color c);
	void Draw(Graphics& gfx)const;
	bool isBallCollsion(const Ball& b)const;
	void ExecuteBallCollision(Ball& b);
	Vec2 GetCenter()const;
private:
	RectF rect;
	Color color;
	bool destroyed = false;
	static constexpr float padding = -2.0f;
};