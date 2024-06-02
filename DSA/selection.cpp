#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ara[n];
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int j=0;j<n-1;j++){
        int min = j;
        for(int i=j+1;i<n;i++){
            if(ara[i]<ara[min]){
                min = i;
            }
        }
        swap(ara[j],ara[min]);
    }
    for(int i=0;i<n;i++){
        cout<<ara[i]<<" ";
    }
}