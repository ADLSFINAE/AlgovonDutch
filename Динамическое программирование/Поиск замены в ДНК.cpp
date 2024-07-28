#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <fstream>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;


int minEditDistance(string s1, string s2){
    int len1 = s1.size() + 1;
    int len2 = s2.size() + 1;
    
    vector<vector<int>> vec(len1, vector<int>(len2, 0));
    
    for(int i = 0; i < len1; i++){
        vec[i][0] = i;
    }
    
    for(int j = 0; j < len2; j++){
        vec[0][j] = j;
    }
    
    for(int i = 1; i < len1; i++){
        for(int j = 1; j < len2; j++){
            int cost = 1;
            if(s1[i - 1] == s2[j - 1]){
                cost = 0;
            }
            int replaceCost = vec[i - 1][j - 1] + cost;
            int removeCost = vec[i - 1][j] + 1;
            int insertCost = vec[i][j - 1] + 1;
            
            vec[i][j] = min(replaceCost, min(removeCost, insertCost));
        }
    }
    
    for(auto& elem : vec){
        for(auto& elem2 : elem){
            cout<<elem2<<" ";
        }
        cout<<endl;
    }
    
    return vec[len1 - 1][len2 - 1];
}

int main() {
    cout<<minEditDistance("GCTAC", "CTCA")<<endl;
    return 0;
}
