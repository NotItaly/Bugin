#pragma once

#include "Vec2.h"
#include "RectF.h"
#include "Ball.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(const Vec2 pos_in);
	void Draw(Graphics& gfx);
	void Update(Keyboard& kbrd, float dt);
	bool doBallCollision(Ball& ball);
	void doWallCollision(const RectF& walls);
	RectF GetRect()const;
	void ResetCoolDown();
private:
	Color WingColor = Colors::Red;
	Color color = Colors::White;
	static constexpr float  halfwingWidth = 18.0f;
	static constexpr float halfWidth = 50.0f;
	static constexpr float halfHeight = 18.0f;
	static constexpr float speed = 500.0f;
	Vec2 pos;
	bool isCoolDown = false;
	
};