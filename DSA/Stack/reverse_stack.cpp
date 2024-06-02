#include<bits/stdc++.h>
using namespace std;

void reverseSentence(string s){
    stack<string> st;

    for(int i= 0;i<s.length();i++){
        string word = "";
        while(s[i] != ' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

void reverseWord(string s){
    stack<char> st;

    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }

}

int main(){

    string s = "BD Army er mayrechudi, shob batparer dol";

    reverseSentence(s);

    string s1 = "Bangladesh";
    reverseWord(s1);

}