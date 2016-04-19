#pragma once

#include "graphicsmath.h"

class Camera
{
public:
	Camera(int WindowWidth, int WindowHeight);

	const Vector3f& GetPos() { return m_pos; }
	const Vector3f& GetTarget() { return m_target; }
	const Vector3f& GetUp() { return m_up; }

private:
	Vector3f m_pos;
	Vector3f m_target;
	Vector3f m_up;

	int m_windowWidth;
	int m_windowHeight;
};