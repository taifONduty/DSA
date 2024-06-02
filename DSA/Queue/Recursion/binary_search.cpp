#include<bits/stdc++.h> 
using namespace std;



int binary(vector<int>& n, int key){
    int l = 0;
    int r = n.size()-1;
    int result = -1;
    while(l<=r){
        int mid = l + (r-l)/2;

        if(n[mid] < key){
            result = n[mid];
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return result;
}

int main(){

    int x;
    cin>>x;
    vector<int> n;
    for(int i=0;i<x;i++){
        int a;
        cin>>a;
        n.push_back(a);
    }
    int key;
    cin>>key;
    cout<<binary(n,key)<<endl;

}