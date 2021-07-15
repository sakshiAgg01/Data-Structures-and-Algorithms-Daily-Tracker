#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> LCS(int *arr, int n){
    unordered_set<int> q;

    for(int i=0; i<n; i++){
        q.insert(arr[i]);
    }

    int ans = 0;
    vector<int> vq;
    for(int i=0; i<n; i++){
        //element se hi sequence start ho rha hai, usse chota element nhi hai set mein.
        if(q.find(arr[i]-1) == q.end()){
            int j = arr[i];

            vq.clear();
            vq.push_back(j);
            while(q.find(j) != q.end()){
                //vq.push_back(j);
                j++;
            }
            vq.push_back(j-1);
            ans = max(ans, j-arr[i]);
        }
    }
        return vq;
}
//------------------------------------------------------------------------------------------------------------------------
int main(){
    int arr[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    vector<int> vq =  LCS(arr, 13);
    for (auto &it : vq)
    {
        cout << it << " ";
    }
}