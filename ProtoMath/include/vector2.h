#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>
class Vector2
{
    public:
        Vector2();
        Vector2(float, float);
        Vector2(const Vector2&);
        ~Vector2();

//Member Functions
        Vector2 operator+ (const Vector2&) const;
        Vector2 operator- (const Vector2&) const;
        Vector2 operator* (const float) const;
        Vector2 operator/ (const float) const;

        void operator+= (const Vector2&) const;
        void operator-= (const Vector2&) const;
        void operator*= (const float) const;
        void operator/= (const float) const;


        float length() const;
        Vector2 normalized() const;
        Vector2 normalize_self() const;
//Static Functions
        static float Dot(const Vector2&,const Vector2&); // all Components multiplied to the respective components of the other vector, all thosevalues added = cos(theta) * length
        static float Angle(const Vector2&, const Vector2&); // inverse cos Dot / length
        float m_x;
        float m_y;

    private:
        //Cached Variables
 };

#endif // VECTOR2_H
