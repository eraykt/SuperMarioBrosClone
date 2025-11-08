#pragma once

#include "vec2.hpp"

class Component
{
public:
	bool has = false;
};

class CTransform : public Component
{
public:
	Vec2Float position = { 0.0f, 0.0f };
	Vec2Float velocity = { 0.0f, 0.0f };

	CTransform() = default;

	explicit CTransform(const Vec2Float& p) :position(p) {};

	CTransform(const Vec2Float& p, const Vec2Float& v) : position(p), velocity(v) {};
};