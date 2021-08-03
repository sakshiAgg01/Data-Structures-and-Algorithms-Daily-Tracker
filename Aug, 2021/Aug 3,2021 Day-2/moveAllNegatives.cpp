//An array contains both positive and negative numbers in random order.Rearrange the array elements so that all negative numbers appear before all positive numbers.

// Examples :
// Input : -12 11 -13 -5 6 -7 5 -3 -6 
// Output : -12 - 13 - 5 - 7 - 3 - 6 11 6 5
#include <iostream>
using namespace std;

void moveAllNegative(int *arr, int n){
    int i = 0, j = n-1;
    while(i<=j){
        if(arr[i] > 0 && arr[j] < 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else if(arr[i] < 0){
            i++;
        }
        else if(arr[j] > 0){
            j--;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------
int main()
{
    int n;
    cout<< "Enter no. of elements in the array:";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter elements of the array:";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    moveAllNegative(arr, n);
    cout<<"Array after reaarangement:";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}