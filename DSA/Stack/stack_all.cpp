#include<bits/stdc++.h>
using namespace std;
const int N = 1e+10;

struct Node {
    int data;
    Node* link;
    Node(int val){
        data = val;
        link = NULL;
    }
};

struct Stack{
    Node* top = NULL;
    void push(int data){
        Node* temp = new Node(data);
        if(top == NULL){
            top = temp;
            return;
        }
        temp->link = top;
        top = temp;
    }
    bool isEmpty(){
        return top == NULL;
    }
    int peek(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        top = top->link;
        free(temp);
    }
    void display(){
        Node* temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
};


struct StackArray{
    int top = -1;
    int arr[100000];
    
    void push(int data){
        if(top == 100000){
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = data;
    }

    void pop(){
        if(top == -1){
            cout << "Stack is empty\n";
            return;
        }
        top--;
    }
    
    int peek(){
        if(top == -1){
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }
    void display(){
        for(int i = 0; i <= top; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    
    }
};

int main(){

    StackArray s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
 
    // Display stack elements
    s.display();
 
    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;
 
    // Delete top elements of stack
    s.pop();
    s.pop();
 
    // Display stack elements
    s.display();
 
    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;
 
    return 0;
}