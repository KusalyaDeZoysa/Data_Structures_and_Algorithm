
#include <iostream>
using namespace std;

#define MAX 14

int Stack_arr[MAX];
int top = -1;

int isFull(){
    if (top==MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

void Push(int data){
    if (isFull()){
        cout << "stack overflow." << endl;
        return;
    }
    top=top+1;
    Stack_arr[top]=data;
}

int Pop(){
    int value;
    if (isEmpty()){
        cout << "stack underflow." << endl;
        return -1;
    }
    value = Stack_arr[top];
    top=top-1;
    return value;
}

int StackTop(){
    if (isEmpty()){
        cout << "stack underflow." << endl;
        return -1;
    }
    return Stack_arr[top];
}

void Display(){
    int i;
    if (top==-1){
        cout << "stack underflow." << endl;
        return;
    }
    for(i=top; i>=0; i--){
        cout << Stack_arr[i] << " ";
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
