#include "camera.h"

Camera::Camera(int WindowWidth, int WindowHeight)
{
	m_windowWidth = WindowWidth;
	m_windowHeight = WindowHeight;

	m_pos = Vector3f(0.f);
	m_target = Vector3f(0.f, 0.f, 1.f);
	m_up = Vector3f(0.f, 1.f, 0.f);
}