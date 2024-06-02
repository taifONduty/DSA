#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

struct queue{
    Node* front = NULL;
    Node* back = NULL;

    void push(int data){
        Node* temp = new Node(data);
        if(front == NULL){
            front = temp;
            back = temp;
            return;
        }
        back->next = temp;
        back = temp;
    }

    void pop(){
        if(front == NULL){
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        free(temp);
    }

    int peek(){
        if(front == NULL){
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void display(){
        Node* temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

struct QueueArray{
    int front = 0;
    int back = 0;
    int arr[100000];

    void push(int data){
        if(back == 100000){
            cout << "Queue is full\n";
            return;
        }
        arr[back] = data;
        back++;
    }

    void pop(){
        if(front == back){
            cout << "Queue is empty\n";
            return;
        }
        front++;
    }

    int peek(){
        if(front == back){
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        return front == back;
    }

    void display(){
        for(int i=front;i<back;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

}