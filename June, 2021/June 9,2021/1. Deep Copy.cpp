#include <iostream>
#include <string.h>
using namespace std;

class Student{
    int age;
    
    public:
    char *name;
    
    //Parametrized Constructor
    Student(int age, char *name){
        this->age = age;
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }
    
    //display the string
    void display(){
        cout<< name<<" "<<age<<endl;
    }
};

int main() {
	char name[] = "abcd";
	Student s1(101, name);
	s1.display();
	
	//Inbuilt-Copy Constructor --> Performs Shallow copy
	Student s2(s1);
	Student s3(102, name);
	s2.name[0] = 'x';
	
	s1.display();
	s2.display();
	s3.display();
	
	return 0;
}
