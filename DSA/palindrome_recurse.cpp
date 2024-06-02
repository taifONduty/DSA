#include<bits/stdc++.h>
using namespace std;
char c[100];

bool check_palindrome(int start, int end){
    if(start>=end){
        return true;
    }
    if(c[start]!=c[end]){
        return false;
    }
    return check_palindrome(start+1,end-1);
}

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    cout<<check_palindrome(0,n-1)<<endl;

}