#include <SFML/Graphics.hpp>
#include "Header.hpp"

// ������������ ����
namespace ao
{
	// �����
	Circle::Circle(int x, int y, float r, float angle, float v0)
	{
		// �����������
		m_x = x;
		m_y = y;
		m_r = r;
		m_v0 = v0;
		m_angle = (2 * acos(-1) - angle);
		m_circle = new sf::CircleShape(m_r);
		m_circle->setOrigin(m_r, m_r);
		m_circle->setPosition(m_x, m_y);
		m_circle->setFillColor(sf::Color::Green);
	}

		// ���������� 
	Circle::~Circle()
	{
		delete m_circle;
	}

		// �����, �������� �������� 
	void Circle::Move(float t, float g)
	{
		float x = m_x + m_v0 * cos(m_angle) * t;
		float y = m_y + m_v0 * sin(m_angle) * t + g * t * t / 2;

		m_circle->setPosition(x, y);
	}

		// �������� �������
	sf::CircleShape* Circle::Get()
	{
		return m_circle;
	}
}