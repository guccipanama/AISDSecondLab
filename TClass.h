#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;

template <class T>
class Line
{
private:
	T* _data;
	size_t _size;
public:
	Line();
	Line(const T* str, size_t size);
	Line(const Line& str);
	~Line();
	size_t GetSize() const;

	T& operator[](size_t index) const;
	Line<T> operator+(const Line str);
	Line<T>& operator=(const Line& str);
	Line<T> operator*(const int power);
	friend Line<T> operator*(int power, const Line<T> str)
	{
		Line<T> temp;
		if ((power <= 0) || (str._size == 0))
			return temp;
		temp._size = power * str._size;
		temp._data = new T[power * str._size + 1];
		for (int i = 0; i < power; i++)
			for (int j = 0; j < (i == power - 1 ? str._size + 1 : str._size); j++)
				temp._data[j + i * str._size] = str._data[j];
		return temp;
	}
	friend ostream& operator<<(ostream& out, const Line<T>& str)
	{
		for (size_t i = 0; i < str._size; i++)
		{
			cout << str._data[i];
			if(typeid(T) != typeid(char))
				cout << " ";
		}
		return out;
	}
	bool operator==(const Line<T>& str) const;
	bool operator!=(const Line<T>& str) const;
	Line Substring(size_t begin, size_t stop) const;
	Line Substring(size_t begin) const;
};

template <class T>
Line<T>::Line() : _data(NULL), _size(0) {}

template <class T>
Line<T>::Line(const T* str, size_t size)
{
	_size = size;
	_data = new T[_size + 1];
	for (size_t i = 0; i < _size + 1; i++)
		_data[i] = str[i];
}

template <class T>
Line<T>::Line(const Line& str)
{
	_size = str._size;
	_data = new T[_size + 1];
	for (size_t i = 0; i < _size + 1; i++)
		_data[i] = str._data[i];
}

template <class T>
Line<T>::~Line()
{
	delete[]_data;
}

template <class T>
size_t Line<T>::GetSize() const
{
	return _size;
}

template <class T>
T& Line<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw "invalid index";
	else
		return _data[index];
}

template <class T>
Line<T> Line<T>::operator+(const Line str)
{
	if (!_size)
		return str;
	if (!str._size)
		return *this;
	Line result;
	result._size = _size + str._size;
	result._data = new T[_size + str._size + 1];

	for (int i = 0; i < _size; i++)
		result._data[i] = _data[i];
	for (int i = 0; i < str._size + 1; i++)
		result._data[i + _size] = str._data[i];

	return result;
}

template <class T>
Line<T>& Line<T>::operator=(const Line& str)
{
	if (this == (&str))
		return *this;
	if (_size != str._size)
	{
		delete[]_data;
		_size = str._size;
		_data = new T[str._size + 1];
	}
	for (size_t i = 0; i < str._size + 1; i++)
		_data[i] = str._data[i];
	return *this;
}

template <class T>
Line<T> Line<T>::operator*(const int power)
{
	Line<T> temp;
	if ((power <= 0) || (_size == 0))
		return temp;
	temp._size = power * _size;
	temp._data = new T[power * _size + 1];
	for (int i = 0; i < power; i++)
		for (int j = 0; j < (i == power - 1 ? _size + 1 : _size); j++)
			temp._data[j + i * _size] = _data[j];
	return temp;
}

template <class T>
bool Line<T>::operator==(const Line<T>& str) const
{
	if (_size != str._size)
		return false;
	for (int i = 0; i < _size + 1; i++)
	{
		if (_data[i] != str._data[i])
			return false;
	}
	return true;
}

template <class T>
bool Line<T>::operator!=(const Line<T>& str) const
{
	if (*this == str)
		return false;
	return true;
}

template <class T>
Line<T> Line<T>::Substring(size_t begin, size_t stop) const
{
	if ((begin < 0) || (begin >= _size))
		throw "invalid begin index";
	if ((stop < 0) || (stop >= _size) || (stop < begin))
		throw "invalid stop index";
	Line<T> temp;
	temp._size = stop - begin + 1;
	temp._data = new T[stop - begin + 2];
	int j = 0;
	for (size_t i = begin; i < stop + 1; i++)
	{
		temp._data[j] = _data[i];
		j++;
	}
	temp._data[stop - begin + 1] = 0;
	return temp;
}

template<class T>
Line<T> Line<T>::Substring(size_t begin) const
{
	return this->Substring(begin, _size -1);
}
