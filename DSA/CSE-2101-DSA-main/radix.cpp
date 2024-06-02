#include<bits/stdc++.h>
using namespace std;

void counting_sort(vector <int>&v , int exp){
    int n = v.size();   
    vector<int> freq(10,0);
    for(int i=0;i<n;i++){
        freq[(v[i]/exp)%10]++;
    }

    for(int i = 1; i < 10; i++){
        freq[i] += freq[i-1];
    }

    vector<int> ans(n);
    for(int i = n-1;i>=0;i--){
        ans[--freq[(v[i]/exp)%10]] = v[i];
    }

    for(int i = 0;i<n;i++){
        v[i] = ans[i];
    }   
}

void radix_sort(vector<int>& v){
    int max = *max_element(v.begin(), v.end());
    int exp = 1;
    for(int pos = 1; max/pos > 0; pos*=10){
        counting_sort(v, pos);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    radix_sort(v);
}