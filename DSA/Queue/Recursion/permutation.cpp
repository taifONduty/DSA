#include<bits/stdc++.h>
using namespace std;

void permute(vector<char>& a, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = start; i <= end; i++) {
            swap(a[start], a[i]);
            permute(a, start + 1, end);
            swap(a[start], a[i]); // backtrack
        }
    }
}

int main(){
    vector<char> a = {'A', 'B', 'C'};
    permute(a, 0, 2);
    return 0;
}