#include<bits/stdc++.h>
using namespace std;
int ara2[1000000];
void insertion_sort(int ara[],int size){
    for(int i=1;i<size;i++){
        int j = i;
        while(j>0 && ara[j-1] > ara[j]){
            swap(ara[j],ara[j-1]);
            j--;
        }
    }
}

void bubble_sort(int ara[],int size){
    for(int i=0;i<size-1;i++){
        bool swapped = false;
        for(int j=0;j<size-i-1;j++){
            if(ara[j]>ara[j+1]){
                swap(ara[j],ara[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void selection_sort(int ara[],int n){
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(ara[j]<ara[min_index]){
                min_index = j;
            }
        }
        swap(ara[i],ara[min_index]);
    }
}

void merge(int l,int m,int r){
    int l_sz = m-l+1;
    int L[l_sz+1];
    int r_sz = r-m;
    int R[r_sz+1];
    for(int i=0;i<l_sz;i++){
        L[i] = ara2[l+i];
    }
    for(int i=0;i<r_sz;i++){
        R[i] = ara2[m+1+i];
    }
    L[l_sz] = R[r_sz] = INT_MAX;

    int left_idx = 0;
    int right_idx = 0;
    for(int i = l; i<=r;i++){
        if(L[left_idx]<=R[right_idx]){
            ara2[i] = L[left_idx];
            left_idx++;
        }
        else{
            ara2[i] = R[right_idx];
            right_idx++;
        }
    }
}

void mergeSort(int l,int r){
    if(l==r) return ;

    int m = l+(r-l)/2;
    mergeSort(l,m);
    mergeSort(m+1,r);
    merge(l,m,r);
    
}

void printArray(int ara[],int size){
    for(int i=0;i<size;i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;

}

int main(){
    // int ara[]={5,4,3,2,1};
    // insertion_sort(ara,5);
    // int ara2[]={6,4,3,2,1};
    // bubble_sort(ara2,5);
    // printArray(ara,5);
    // printArray(ara2,5);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>ara2[i];
    }
    mergeSort(0,n-1);
    printArray(ara2,n);
}