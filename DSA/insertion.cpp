#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ara[n];
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int i=1;i<n;i++){
        int j = i;
        while(j>0 && ara[j-1]>ara[j]){
            swap(ara[j-1],ara[j]);
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ara[i]<<" ";
    }
}