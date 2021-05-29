#include <iostream>
using namespace std;

int main() {
	
	//array
	int a[] = {1,2,3,4};
	 
	cout << a << endl;              // It will return the address of a[0]
	cout << &a << endl;             // It will return the address of a[0]
	cout << &a[0] << endl;          // It will return the address of a[0]
	cout << &a[1] << endl;          // It will return the address of a[1]
	
	cout << a[0] << endl;           // It will return value at index 0
	cout << *a << endl;             // It will return value at index 0
	cout << *(a + 0) << endl;       // *(a + 0) == a[0]   ,  It will return value at index 0
	cout << *(a + 1) << endl;       // *(a + 1) == a[1]   ,  It will return value at index 1
	cout << 1[a] << endl;           // 1[a] == a[1]       ,  It will return value at index 1
	
	//Comparison of two pointers
	int x = *(a + 1) < *(a + 2);
	cout << x << endl;
	
	int i = 10;
	int *p = &i;                    // p is an integer pointer that holds address of i
	cout << &i << endl;             // It will print the address of i
	cout << p << endl;              // It will print the address of i
	cout << &p << endl;             // It will print the address of pointer p
	
	int q = 12;
	p = &q;                         // Pointer can be reassigned with new memory address.
	cout << p << endl; 
	cout << *p << endl;
	
	return 0;
}
