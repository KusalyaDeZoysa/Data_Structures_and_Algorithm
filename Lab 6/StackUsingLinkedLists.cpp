#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* top = NULL;

int isEmpty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}

void Push(int data){
    Node* newNode = new Node(data);
    if (newNode==NULL){
        cout << "stack overflow." << endl;
        return;
    }
    newNode->next = top;
    top = newNode;
}

int Pop(){
    Node* temp;
    int value;
    if (isEmpty()){
        cout << "stack underflow." << endl;
        return -1;
    }
    temp = top;
    value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

int StackTop(){
    if (isEmpty()){
        cout << "stack underflow." << endl;
        return -1;
    }
    return top->data;
}

void Display(){
    Node* temp = top;
    if (isEmpty()){
        cout << "stack underflow." << endl;
        return;
    }
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int data;
    int x = isEmpty();
    if(x){
        cout <<"Stack is Empty..\n";
    } else {
        cout << "Stack has elements.\n";
    }
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    cout << "Top element in the stack: " << StackTop() << endl;
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Display();
    return 0;
}
