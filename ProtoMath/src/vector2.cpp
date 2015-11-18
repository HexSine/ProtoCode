#include "vector2.h"

Vector2::Vector2(float x, float y) : m_x(x),m_y(y)
{
}
Vector2::Vector2(const Vector2& other) : m_x(other.m_x),m_y(other.m_y)
{
}

Vector2::~Vector2()
{
    //dtor
}

//======================================================
//Operator
//======================================================

Vector2 Vector2::operator+ (const Vector2& other)
{
    return Vector2(m_x + other.m_x,m_y + other.m_y);
}

Vector2 Vector2::operator-(const Vector2& other)
{
    return Vector2(m_x - other.m_x,m_y - other.m_y);
}

Vector2 Vector2::operator*(const float f)
{
    return Vector2(m_x * f,m_y * f);
}

Vector2 Vector2::operator/(const float f)
{
    return Vector2(m_x / f,m_y / f);
}

void Vector2::operator+= (const Vector2& other)
{
    m_x += other.m_x;
    m_y += other.m_y;
}

void Vector2::operator-=(const Vector2& other)
{
    m_x -= other.m_x;
    m_y -= other.m_y;
}

void Vector2::operator*=(const float f)
{
    m_x *= f;
    m_y *= f;
}

void Vector2::operator/=(const float f)
{
    m_x /= f;
    m_y /= f;
}

//======================================================
//Member
//======================================================

float Vector2::length() const
{
    return sqrt(m_x * m_x + m_y * m_y);
}

Vector2 Vector2::normalized() const
{
    return Vector2(m_x,m_y) / length();
}

Vector2 Vector2::normalize_self() const
{
    float l = length();
    m_x/=l;
    m_y/=l;
}

//======================================================
//Static
//======================================================

float Vector2::Dot(const Vector2& rhs, const Vector2& lhs)
{
    return rhs.m_x * lhs.m_x + rhs.m_y * lhs.m_y;
}
float Vector2::Angle(const Vector2& rhs, const Vector2& lhs)
{
    return acos(Dot(rhs.normalized(),lhs.normalized()));
}
