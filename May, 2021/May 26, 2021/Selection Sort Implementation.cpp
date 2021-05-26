#include <iostream>
#include <climits>
using namespace std;

int main() {
    //selection sort 
    int arr[1000];
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    
    for(int i=0; i<n-1; i++){   //n-1 rounds
      
      int minindex = i;
      int min = INT_MAX;
      for(int j=i; j<n;j++){
          if(arr[j] < min){
              min = arr[j];
              minindex = j;
          }
      }
      int temp = arr[i];
      arr[i] = arr[minindex];
      arr[minindex] = temp;
      
    }
    
    for(int i=0; i<n; i++){
        cout<< arr[i]<< " ";
    }
    
	return 0;
}
