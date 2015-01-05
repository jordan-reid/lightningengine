#ifndef VEC2_H
#define VEC2_H

template<typename Type> class Vec2
{

public:

	Vec2(Type _x = 0, Type _y = 0)
	{
		X = _x;
		Y = _y;
	}

	~Vec2(){}; 

	Type Magnitude(void)
	{
		return (sqrt((X * X) + (Y * Y)));
	}

	void Normalize(void)
	{
		Type temp = this->Magnitude();

		this->X /= temp;
		this->Y /= temp;
	}

	//operator overloads
	Vec2<Type> operator+(const Vec2<Type>&rhs)
	{
		Vec2<float> temp = *this;

		temp += rhs;

		return temp;
	}

	void operator+=(const Vec2<Type> &rhs)
	{
		this->X += rhs.X;
		this->Y += rhs.Y;
	}

	Vec2<Type> operator-(const Vec2<Type>&rhs)
	{
		Vec2<float> temp = *this;

		temp -= rhs;

		return temp;
	}

	void operator-=(const Vec2<Type> &rhs)
	{
		this->X -= rhs.X;
		this->Y -= rhs.Y;
	}

	Vec2<Type> operator*(const Vec2<Type> &rhs)
	{
		Vec2<Type> temp = *this;

		temp *= rhs;

		return temp;
	}

	void operator*=(const Vec2<Type> &rhs)
	{
		this->X *= rhs.X;
		this->Y *= rhs.Y;
	}

	Vec2<Type> operator/(const Type &rhs)
	{
		Vec2<Type> temp = *this;

		temp.X /= rhs;
		temp.Y /= rhs;

		return temp;
	}

	void operator/=(const Type &rhs)
	{
		this->X /= rhs;
		this->Y /= rhs;
	}



	//Accessors
	Type GetX() {return X;};
	Type GetY() {return Y;};


	//Mutators
	void SetX(Type _x) {X = _x;};
	void SetY(Type _y) {Y = _y;};


private:

	Type X,Y;
};

namespace Vec2D
{
	template<typename Type>
	Type Dot(const Vec2<Type> &_vecA, const Vec2<Type> &_vecB)
	{
		return ((_vecA.GetX() * _vecB.GetX()) + (_vecA.GetY() * _vecB.GetY()));
	}

	//Cross product in 2D space is used to determine if something is on your left or right
	template<typename Type>
	Type CrossProduct(const Vec2<Type> _A, const Vec2<Type> _B)
	{
		return ((_A.GetX() * _B.GetY()) - (_A.GetY() * _B.GetX()));
	}

	//Translate
	template<typename Type>
	void Translate(Vec2<Type> &_translate, Vec2<Type> _translateBy)
	{
		_translate += _translateBy;
	}

	//Scale
	template<typename Type>
	void Scale(Vec2<Type> &_scale, Vec2<Type> _scaleBy)
	{
		_scale *= _scaleBy;
	}

	//Rotate



	template<typename Type>
	Type CalcDistance2D(Vec2<Type> &_vecA, Vec2<Type> &_vecB)
	{
		return sqrt(((_vecB.GetX() - _vecA.GetX()) * (_vecB.GetX() - _vecA.GetX())) + ((_vecB.GetY() - _vecA.GetY()) * (_vecB.GetY() - _vecA.GetY())));
	}
}

#endif

