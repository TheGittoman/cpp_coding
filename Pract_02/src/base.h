#ifndef BASE_H
#define BASE_H

template<class T>
struct Vect
{
	T m_x{0.0f};
	T m_y{0.0f};

	Vect() : m_x{ 0 }, m_y{ 0 } {}
	Vect(T x, T y) : m_x{ x }, m_y{ y } {}
	Vect(const Vect &v) : m_x{v.m_x}, m_y{v.m_y} {}

};


#endif