#include <iostream>
#include <string>
#include <climits>
using namespace std;

// RECURSIVE APPROACH
// int LCS(string s1, string s2){
//     //Base Case
//     if(s1.size() == 0|| s2.size() == 0){
//         return 0;
//     }

//     if(s1[0] == s2[0]){
//         return 1 + LCS(s1.substr(1), s2.substr(1));
//     }

//     int way1 = LCS(s1.substr(1), s2);
//     int way2 = LCS(s1, s2.substr(1));
//     int way3 = LCS(s1.substr(1), s2.substr(1));

//     return max(way1, max(way2, way3));
// }

//MEMOIZATION APPROACH
int LCS(string s1, string s2, int i, int j, int **t)
{
    //Base Case
    if (i == 0 || j == 0){
        return 0;
    }
    //Check if ans already exists
    if(t[i][j] != -1){
        return t[i][j];
    }

    int ans;
    if (s1[i-1] == s2[j-1]){
        ans =  1 + LCS(s1, s2, i-1, j-1, t);
    }
    else{
        int way1 = LCS(s1, s2, i - 1, j, t);
        int way2 = LCS(s1, s2, i, j - 1, t);
        int way3 = LCS(s1, s2, i - 1, j - 1, t);

        ans = max(way1, max(way2, way3));
    }
    t[i][j] = ans;
    return t[i][j];
}

int main(){
    string s1, s2;
    s1 = "xyzw";
    s2 = "xay";

    int **t = new int*[s1.size()+1];
    for(int i=0; i< s1.size()+1; i++){
        t[i] = new int[s2.size()+1];
        for(int j=0; j<s2.size()+1; j++){
            t[i][j] = -1;
        }
    }
    cout << LCS(s1, s2, s1.length(), s2.length(), t);
}
