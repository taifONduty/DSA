#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int ara[N];

void merge(int l,int m,int r){
    int l_sz = m-l+1;
    int L[l_sz+1];
    int r_sz = r-m;
    int R[r_sz+1];
    for(int i=0;i<l_sz;i++){
        L[i] = ara[l+i];
    }
    for(int i=0;i<r_sz;i++){
        R[i] = ara[m+1+i];
    }
    L[l_sz] = R[r_sz] = INT_MAX;
    int l_idx = 0;
    int r_idx = 0;
    for(int i=l;i<=r;i++){
        if(L[l_idx]<=R[r_idx]){
            ara[i] = L[l_idx];
            l_idx++;
        }
        else{
            ara[i] = R[r_idx];
            r_idx++;
        }
    }
}
void mergeSort(int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r)/2;
    mergeSort(l,m);
    mergeSort(m+1,r);
    merge(l,m,r);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }   
    mergeSort(0,n-1);

    for(int i=0;i<n;i++){
        cout<<ara[i]<<" ";
    }
}