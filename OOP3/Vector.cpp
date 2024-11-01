#include "Vector.h"
#include <iostream>
#include <string>
using namespace std;

Vector::Vector()
	:Vector(1)
{
}

Vector::Vector(const size_t& size)
	:size(size), capacity(size)
{
	this->arr = new int[this->size] {};
}

Vector::Vector(const size_t& size, const int& value)
	:Vector(size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = value;
	}
}

Vector::Vector(const Vector& other)
	:Vector(other.size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = other.arr[i];
	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = other.size;
	this->capacity = this->size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

void Vector::print() const
{
	std::cout << " Array has size ==> " << size << "; capacity ==> " << capacity << "\n";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

Vector::~Vector()
{
	if (arr != nullptr)
		delete[] arr;
}

int Vector::operator[](size_t index) const
{
	if (isValidIndex(index))
		return arr[index];
	std::cout << "========= Error index (get) : " << index << std::endl;
	return INT_MIN;
}

int& Vector::operator[](size_t index)
{
	static int errVal;
	if(isValidIndex(index))
		return arr[index];
	std::cout << "========= Error index (get) : " << index << std::endl;
	return errVal;

}

Vector Vector::operator()(size_t startIndex, size_t lastIndex) const
{
	if (startIndex > lastIndex)
		std::swap(startIndex, lastIndex);
	if (!isValidIndex(startIndex))
		return Vector(0);
	if (lastIndex >= size)
		lastIndex = size - 1;
	Vector tmp(lastIndex - startIndex + 1);
	for (size_t i = 0; i < tmp.size; i++)
	{
		tmp[i] = this->arr[i + startIndex];
	}
	return tmp;
}

Vector Vector::operator+(const Vector& other) const
{
	int newsize = this->size + other.size;
	Vector tmp(newsize);
	for (size_t i = 0; i < this->size; i++)
	{
		tmp.arr[i] = this->arr[i];
	}

	for (size_t i = 0; i < other.size; i++)
	{
		tmp.arr[this->size + i] = other.arr[i];
	}
	return tmp;
	

}
Vector Vector::operator-(const Vector& other) const
{
	
	
	size_t newSize = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		bool found = false;
		for (size_t j = 0; j < other.size; j++)
		{
			if (this->arr[i] == other.arr[j])
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			newSize++; 
		}
	}

	Vector tmp(newSize);
	size_t index = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		bool found = false;
		for (size_t j = 0; j < other.size; j++)
		{
			if (this->arr[i] == other.arr[j])
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			tmp.arr[index++] = this->arr[i]; 
		}
	}
	return tmp;
}

Vector Vector::operator*(const size_t& n) const
{
	Vector tmp(size);
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = arr[i] * n;
	}
	return tmp;
}

Vector::operator int() const
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

Vector::operator char* () const
{
	string result;
	for (size_t i = 0; i < size; ++i) {
		result += to_string(arr[i]);
		if (i < size - 1) {
			result += ", ";
		}
	}
	char* cas = new char[result.length() + 1];
	for (size_t i = 0; i < result.length(); ++i) {
		cas[i] = result[i]; 
	}
	cas[result.length()] = '\0';
	 return cas;
}

void Vector::pushBack(const int& value)
{
	if (size >= capacity)
		resize();
	arr[size++] = value;
}
void Vector::pushUp(const int& value)
{
	if (size >= capacity)
		this->capacity *= 2;
	int* tmp = new int[this->capacity];
	
	tmp[0] = value;

	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i + 1] = arr[i];
	}
	delete[] arr;
	arr = tmp;
	size++;
}




void Vector::insert(const int& value, const size_t index)
{
	if (size >= capacity)
		this->capacity *= 2;
	if (index > size)
	{
		cout << "Error! out range" << endl;
		return;
	}
	int* tmp = new int[this->capacity];
	for (size_t i = 0; i < size; i++)
	{
		if (i < index)
			tmp[i] = arr[i];
		else
			tmp[i + 1] = arr[i];
	}
	tmp[index] = value;
	delete[] arr;
	arr = tmp;
	size++;
}
void Vector::popBack()
{
	int* tmp = new int[this->capacity];
	for (size_t i = 0; i < size; i++)
	{
		
		tmp[i] = arr[i];
		
	}
	delete[] arr;
	arr = tmp;
	size--;
}
void Vector::popFront()
{
	int* tmp = new int[this->capacity];
	for (size_t i = 0; i < size; i++)
	{

		tmp[i] = arr[i+1];

	}
	delete[] arr;
	arr = tmp;
	size--;
}
void Vector::remove(const size_t& index)
{
	if (index > size)
	{
		cout << "Error! out range" << endl;
		return;
	}
	int* tmp = new int[this->capacity];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = arr[i];

		if (i == index or i > index)
			tmp[i] = arr[i + 1];
		
			
	}

	delete[] arr;
	arr = tmp;
	size--;
}
int Vector::find(const int& value)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return i;
			break;
		}


	}
	return -1;
}
void Vector::resize()
{
	this->capacity *= 2;
	int* tmp = new int[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}
