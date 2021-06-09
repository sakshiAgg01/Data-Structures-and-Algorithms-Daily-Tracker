#include <iostream>
using namespace std;

//CREATING OUR OWN COPY CONSTRUCTOR AND COPY ASSIGNMENT OPERATOR
//TO PERFORM DEEP COPY.

class DynamicArray{
    int *data;  //array
    int nextIndex;
    int capacity;   //total size of array
    
    public:
    DynamicArray(){
        //Initializing all the data members here
        data = new int[5];  //Initially we have fixed that size of array is 5
        nextIndex = 0;
        capacity = 5;
    }
    
    //Copy Constructor with Deep Copy
    DynamicArray(DynamicArray const &d1){
        // this->data = d1.data;   Shallow Copy
        this->data = new int[d1.capacity]; //Deep Copy
        for(int i=0; i<d1.nextIndex; i++){       
            //Elements will be present upto nextIndex only, all these elements will be copied
            this->data[i] = d1.data[i];
            
        }
        this->nextIndex = d1.nextIndex;
        this->capacity = d1.capacity;
    }
    
    //Copy assignment operator ( = operator overloaded)
    DynamicArray operator=(DynamicArray const &d1){
        this->data = new int[d1.capacity]; //Deep Copy
        for(int i=0; i<d1.nextIndex; i++){       
            //Elements will be present upto nextIndex only, all these elements will be copied
            this->data[i] = d1.data[i];
            
        }
        this->nextIndex = d1.nextIndex;
        this->capacity = d1.capacity;
        return *this;
    }
    
    //Function to add element in the array
    void add(int element){
        if(nextIndex == capacity){      //If array is filled completely then double the size of array
            //To double the size of array, we need to create a newarray
            int *newData = new int[2*capacity];
            //Copy all the content of data into newData
            for(int i=0;i<capacity;i++){
                newData[i] = data[i];
            }
            
            //newData is the local variable of function add().
            //Our main array is "data". So, we will make data array
            //to point to newData now. Before doing this, we will
            //deallocate memeory from data array.
            delete [] data;
            data = newData;     //Now, data will point to newData
            capacity *=2;       //Our capacity is also double now
        }
        //If array is not completely filled yet, then 
        //go to the nextindex of array and insert element there
        data[nextIndex++] = element;
    }
    
    //Function to return the element present at the index 
    //specified by the user.
    int getElement(int i) const {
        if(i<nextIndex){
           return data[i]; 
        }
        return -1;
    }
    
    //Function to add element at a particular index
    void add(int i, int element){
        if(i<nextIndex){
            data[i] = element;
        }
        else if(i==nextIndex){
            add(element);
        }
        else{
            return;
        }
    }
    
    //Function to print array
    void print() const {
        for(int i=0; i<nextIndex; i++){     
            //We won't run the loop till capacity as it is possible that whole array is not filled yet
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
	DynamicArray d1;
	d1.add(1);
	d1.add(2);
	d1.add(3);
	d1.add(4);
	d1.add(5);
	d1.add(6);      //To add this 6th element, array size will be doubled
	
	d1.print();
	
	//Here we are creating a new object with the help of Copy Constructor
	DynamicArray d2(d1);
	
	DynamicArray d3;        //Default Constructor will be called here
	d3 = d1;                //Copy assignment operator
	//Copy assignment operator also performs Shallow copy
	
	d1.add(0, 100);
	//This change above will be reflected in both objects d1 and d2
	//This is because object d2 is created using Copy Constructor
	//and copy constructor performs Shallow Copy .So, only the reference
	//of d1 is copied in d2.So, changes made in d1 will be seen in d2
	//and changes made in d2 will be seen in d1.
	
	d1.print();
	d2.print();
	d3.print();
	return 0;
}

