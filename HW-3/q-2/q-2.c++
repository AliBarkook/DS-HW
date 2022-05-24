#include <iostream>
using namespace std;
int queue[5], n = 5, head = -1, tail = 0;

void enqueue(int a) {
    if (tail == head)
        cout<<"queue overflow"<<endl;
    else if (tail == n && head != 0) {
        tail = 0;
        queue[tail] = a;
        tail++;
    }
    else if (tail == n && head == 0)
        cout<<"queue overflow"<<endl;
    else {
        if (head == - 1)
            head = 0;
        queue[tail] = a;
        tail++;
    }
}

void dequeue() {
    if (head == -1 && tail == 0)
        cout<<"Queue is empry ";
    else if (head == tail)
        cout<<"Queue is empry ";
    else if (head == n-1) {
        cout<<"Element deleted from queue is : "<< queue[head] <<endl;
        head = 0;
    }
    else {
        cout<<"Element deleted from queue is : "<< queue[head] <<endl;
        head++;
    }
}

void size() {
    cout<<tail-head<<endl;
   if (head == - 1 && head == -1) {
      cout<<"Queue Underflow ";
   } else {
      cout<<"Element deleted from queue is : "<< queue[head] <<endl;
   }
}

void Display() {
    if (head == -1 || head == tail)
        cout<<"Queue is empty"<<endl;
    else {
        cout<<"Queue elements are : ";
        for (int i = head; i < tail; i++)
            cout<<queue[i]<<" ";
        cout<<endl;
    }
}
int main() {
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display size of queue"<<endl;
   cout<<"4) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
        case 1: {
            int a;
            cout<<"Insert the element in queue : "<<endl;
            cin>>a;
            enqueue(a);
            break;
        }
         case 2: dequeue();
         break;
         case 3: size();
         break;
         case 4: Display();
         break;
         case 5: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=5);
   return 0;
}