#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;

template <class T>
class String
{
private:
	T* _data;
	std::size_t _size;
public:
	String();
	String(const T* Str);
	String(const String& Str);
	~String();
	std::size_t GetSize();

	T& operator[](std::size_t Index);
	String operator+(const String Str);
	String& operator=(const String& Str);
	friend String operator*(const String Str, int Power);
	friend String operator*(int Power, const String Str);
	friend ostream& operator<<(ostream& Out, const String& Str);
	friend bool operator<(const String& Str1, const String& Str2);
	friend bool operator>(const String& Str1, const String& Str2);
	friend bool operator==(const String& Str1, const String& Str2);
	friend bool operator!=(const String& Str1, const String& Str2);
	String Substring(std::size_t Index, std::size_t Length) const;
};

template <class T>
String<T>::String() : _data(NULL), _size(0) {}

template <class T>
String<T>::String(const T* Str)
{
	_size = strlen(Str);
	_data = new T[_size + 1];
	strcpy_s(_data, _size + 1, Str);
}

template <class T>
String<T>::String(const String& Str)
{
	_size = Str._size;
	_data = new T[Str._size];
	if (Str._data)
		_data = _strdup(Str._data);
	else
		_data = NULL;
}
template <class T>
String<T>::~String()
{
	delete[]_data;
}
template <class T>
std::size_t String<T>::GetSize()
{
	return _size;
}

template <class T>
T& String<T>::operator[](std::size_t Index)
{
	if (Index >= _size)
		throw "invalid index";
	else
		return _data[Index];
}

template <class T>
String<T> String<T>::operator+(const String Str)
{
	if (!_size)
		return Str;
	if (!Str._size)
		return *this;
	String result;
	result._size = _size + Str._size;
	result._data = new T[_size + Str._size + 1];
	strcpy_s(result._data, result._size + 1, _data);
	strcat_s(result._data, result._size + 1, Str._data);
	return result;
}

template <class T>
String<T>& String<T>::operator=(const String& Str)
{
	if (this == (&Str))
		return *this;
	if (_data)
		delete[] _data;
	if (Str._data)
	{
		_size = Str._size;
		_data = _strdup(Str._data);
	}
	else
	{
		_size = 0;
		_data = NULL;
	}
	return *this;
}

template <class T>
String<T> operator*(const String<T> Str, int Power)
{
	String temp;
	if ((Power <= 0) || (Str._size == 0))
		return temp;
	temp._size = Power * Str._size;
	temp._data = new T[Power * Str._size + 1];
	T* p = temp._data;
	*p = 0;
	for (int i = 0; i < Power; i++)
		strcat_s(p, temp._size + 1, Str._data);
	return temp;
}

template <class T>
String<T> operator*(int Power, const String<T> Str)
{
	String temp;
	if ((Power <= 0) || (Str._size == 0))
		return temp;
	temp._size = Power * Str._size;
	temp._data = new T[Power * Str._size + 1];
	T* p = temp._data;
	*p = 0;
	for (int i = 0; i < Power; i++)
		strcat_s(p, temp._size + 1, Str._data);
	return temp;
}

template <class T>
std::ostream& operator<<(std::ostream& Out, const String<T>& Str)
{
	cout << Str._data << endl;
	return Out;
}

template <class T>
bool operator<(const String<T>& Str1, const String<T>& Str2)
{
	return (strcmp(Str1._data, Str2._data) < 0);
}

template <class T>
bool operator>(const String<T>& Str1, const String<T>& Str2)
{
	return (strcmp(Str1._data, Str2._data) > 0);
}

template <class T>
bool operator==(const String<T>& Str1, const String<T>& Str2)
{
	return (strcmp(Str1._data, Str2._data) == 0);
}

template <class T>
bool operator!=(const String<T>& Str1, const String<T>& Str2)
{
	return (strcmp(Str1._data, Str2._data) != 0);
}

template <class T>
String<T> String<T>::Substring(std::size_t Index, std::size_t Length) const
{
	if ((Index < 0) || (Index >= _size))
		throw "invalid index";
	if ((Length < 0) || (Length >= _size) || (Length < Index))
		throw "invalid length";
	String temp;
	temp._size = Length;
	temp._data = new T[Length + 1];
	for (int i = 0; i < Length + 1; i++)
		if (_data)
			temp._data[i] = _data[Index + i];
	temp._data[Length] = 0;
	return temp;
}