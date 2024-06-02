#include<bits/stdc++.h>
using namespace std;


void combination(vector<int>& a, int n, int k, int start, vector<int>& result) {
    if (result.size() == k) {
        for (int i = 0; i < k; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < n; i++) {
        result.push_back(a[i]);
        combination(a, n, k, i + 1, result);
        result.pop_back(); // backtrack
    }
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> result;
    combination(a, 5, 3, 0, result);
    return 0;
}