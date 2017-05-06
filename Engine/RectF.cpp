#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(Vec2 topLeft_in, Vec2 bottomRight_in)
{
	RectF(topLeft_in.x, bottomRight_in.x, topLeft_in.y, bottomRight_in.y);
}

RectF::RectF(Vec2 topLeft_in, float width, float height)
{
	RectF(topLeft_in, Vec2(topLeft_in.x + width, topLeft_in.y + height));
}

RectF RectF::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	Vec2 half(halfWidth, halfHeight);
	return RectF(center.x - halfWidth, center.x + halfWidth, center.y - halfHeight, center.y + halfHeight);
}

bool RectF::isOverLapping(const RectF & other_rect) const
{
	return left<other_rect.right && right>other_rect.left
		&& top < other_rect.bottom && bottom > other_rect.top;
}

RectF RectF::GetExpanded(float offset) const
{
	return RectF(left - offset, right + offset, top - offset, bottom + offset);
}
