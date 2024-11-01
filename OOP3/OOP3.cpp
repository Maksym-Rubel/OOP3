#include <iostream>
#include "Vector.h"

using namespace std;


int main()
{
	Vector arr(10, 3);
	Vector splice(6, 3);



	arr[0] = 2; arr[1] = 8; arr[2] = 5; arr[3] = 1; arr[4] = 10; arr[5] = 5;
	arr[6] = 9; arr[7] = 9; arr[8] = 3; arr[9] = 5;
	splice[0] = 5; splice[1] = 1; splice[2] = 10; splice[3] = 22; splice[4] = 33;
	splice[5] = 44;
	
	arr.print();
	splice.print();

	Vector arr1 = arr + splice;
	Vector arr2 = arr - splice;
	Vector arr3 = arr * 2;


	arr1.print();
	cout << endl;
	arr2.print();
	cout << endl;
	arr3.print();


	cout << (char*)arr1 << endl;
	arr1.pushBack(63);
	arr1.print();
	arr1.pushUp(24);
	arr1.print();
	arr1.insert(23,2);
	arr1.print();
	arr1.popBack();
	arr1.print();
	arr1.popFront();
	arr1.print();
	cout << endl;
	arr1.remove(2);
	arr1.print();
	cout << arr1.find(3235) << endl;
	



}
