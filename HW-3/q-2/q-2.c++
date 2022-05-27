#include <iostream>
using namespace std;
int queue[1000], n = 1000, head = -1, tail = 0;

void enqueue(int a) {
    if (tail+1 == head)
        cout<<"queue overflow"<<endl;
    else if (tail == n-1 && head == 0)
        cout<<"queue overflow"<<endl;
    else {
        if (head == - 1)
            head = 0;
        queue[tail] = a;
        tail++;

        if (tail == n)
            tail = 0;
    }
    
}

void dequeue() {
    if (head == tail)
        cout<<"Queue is empty ";
    else if (head == n-1) {
        cout<<"Element deleted from queue is : "<< queue[head] <<endl;
        head = 0;
    }
    else {
        cout<<"Element deleted from queue is : "<< queue[head] <<endl;
        head++;
    }
    
}

int size() {
    if (head == -1) {
        cout<<"0"<<endl;
        return 0;
    }
    else if (tail < head) {
        cout<<n-(head-tail)<<endl;
        return (n-(head-tail));
    }
    else {
        cout<<tail-head<<endl;
        return (tail-head);
    }
}

void isEmpty() {
    if (size() == 0)
        cout<<'bale'<<endl;
    else 
        cout<<'hkeir'<<endl;
}
int main() {
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display size of queue"<<endl;
   cout<<"4) check queue is empty"<<endl;
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
         case 4: isEmpty();
         break;
         case 5: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=5);
   return 0;
}