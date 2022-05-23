#include <iostream>
using namespace std;

int stack[1000], n=1000, top=-1;

void push(int a) {
    if(top >= n-1)
        cout<<"stack overflow"<<endl;
    else {
        top++;
        stack[top] = a;
    }
}

void pop() {
    if(top <= -1)
        cout<<"stack Underflow"<<endl;
    else {
        cout<<"the popped element is "<< stack[top] <<endl;
        top--;
    }
}

void size() {
    if (top == -1)
        cout<<"array is empty"<<endl;
    else
        cout<<"stack size is: "<<top<<endl;
}

void peek() {
    if (top == -1)
        cout<<"array is empty"<<endl;
    else
        cout<<"highest element of stack is: "<<stack[top]<<endl;
}

void isEmpty() {
    if (top == -1)
        cout<<"bale"<<endl;
    else
        cout<<"kheir"<<endl;
}

int main() {
   int command, newVal;
   cout<<"1) push in stack"<<endl;
   cout<<"2) pop from stack"<<endl;
   cout<<"3) display size of stack"<<endl;
   cout<<"4) display highest elemnt of stack"<<endl;
   cout<<"5) display stack isEmpty state"<<endl;
   cout<<"6) Exit"<<endl;
   do {
      cout<<"enter option: "<<endl;
      cin>>command;
      switch(command) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>newVal;
            push(newVal);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            size();
            break;
         }
         case 4: {
             peek();
            break;
         }
         case 5: {
            isEmpty();
            break;
         }
         case 6: {
            cout<<"exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   } while(command!=7);
   return 0;
}