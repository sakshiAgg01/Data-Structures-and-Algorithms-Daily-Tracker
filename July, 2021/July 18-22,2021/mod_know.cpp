#include <iostream>
using namespace std;

int main(){
    int n1 = 37;
    int n2 = 38;
    int n3 = 39;
    int r = 5;

    //Both will give same answers
    cout<< (n1*n2*n3)%r << endl;
    cout<< ((n1%r) * (n2%r) * (n3%r))%r << endl;
}