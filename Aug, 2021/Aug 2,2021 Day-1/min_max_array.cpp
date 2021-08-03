#include <iostream>
using namespace std;

class Pair{
    public:
    int minimum;
    int maximum;
};
//--------------------------------------------------------------------------------------------------------------
Pair getMinandMaxElement(int *arr, int n){
    if(n < 0){
        Pair p;
        p.minimum = INT_MAX;
        p.maximum = INT_MIN;
        return p;
    }

    Pair smallans = getMinandMaxElement(arr, n-1);
    Pair ans;
    ans.minimum = min(arr[n], smallans.minimum);
    ans.maximum = max(arr[n], smallans.maximum);
    return ans;
}
//--------------------------------------------------------------------------------------------------------------
int main(){
    int n;
    cout<<"Enter no. of elements in the array:";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter elements in the array:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Pair ans = getMinandMaxElement(arr, n-1);
    cout<<"Maximum element in the array:"<<ans.maximum<<endl;
    cout<<"Minimum element in the array:"<<ans.minimum<<endl;
}