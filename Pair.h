#ifndef Pair_H
#define Pair_H

template<typename TFirst,typename TSecond>
class Pair
{
private:
	TFirst first;
	TSecond second;
public:
	Pair()
	{

	}
	Pair(const Pair &other)
	{
		this->first = other.first;
		this->second = other.second;
	}
	Pair(TFirst first, TSecond second)
	{
		this->first = first;
		this->second =second;
	}
	TFirst Get_first()
	{
		return this->first;
	}
	TSecond Get_second()
	{
		return this->second;
	}
	void Set_first(TFirst first)
	{
		this->first = first;
	}
	void Set_second(TSecond second)
	{
		this->second = second;
	}
};

#endif