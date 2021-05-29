#include <iostream>
using namespace std;

int main() {
	int a[5] = {1,2,3,4,5};
	int *p = &a[0];
	
	cout<< a<< endl;
	cout<< a+3<<endl;
	cout<< *(a+3)<<endl;
	cout<< &a <<endl;
	
	cout<< p<< endl;
	cout<< &p<< endl;       //It will print the address where pointer is stored.
	
	char b[] = "abc";
	char *q = &b[0];
	char *r = &b[1];
	
	cout<< b<< endl;        //It will print the entire string.
	cout<< q<< endl;
	cout<< r<< endl;
	return 0;
}
