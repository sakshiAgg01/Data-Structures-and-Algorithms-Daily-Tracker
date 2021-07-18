#include <iostream>
using namespace std;

//MEMOIZATION: TOP-DOWN APPROACH, O(N) complexity
int helper(int n, int *ans){
    if(n <= 1){
        return n;
    }

    //check if output already exists.
    if(ans[n] != -1){
        return ans[n];
    }

    //if output doesn't already exists, calculate it here.
    int a = helper(n-1, ans);
    int b = helper(n-2, ans);

    //save the output calculated for future use before returning it.
    ans[n] = a + b;

    //now return the ans after saving it.
    return ans[n];
}

//DYNAMIC PROGRAMMING APPROACH, O(N) complexity
int fib_dp(int n){
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2; i< n+1; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}

int fib_memo(int n){
    int *ans = new int[n+1];
    for(int i=0; i<n+1; i++){
        ans[i] = -1;
    }
    return helper(n, ans);
}

int main(){
    cout<< fib_memo(6);
}