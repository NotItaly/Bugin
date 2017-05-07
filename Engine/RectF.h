#pragma once

#include "Vec2.h"


class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& topLeft_in,const Vec2& bottomRight_in);
	RectF(const Vec2& topLeft_in, float width, float height);
	static RectF FromCenter(const Vec2& center, float halfWidth, float halfHeight);
	bool isOverLapping(const RectF& other_rect)const;
	RectF GetExpanded(float offset) const;
	Vec2 GetCenter() const;
public:
	float left;
	float right;
	float top;
	float bottom;
};