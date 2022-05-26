// CPP program to implement Queue using
// two stacks with costly enqueue()
#include <bits/stdc++.h>
using namespace std;

struct Queue {
	stack<int> s1, s2;

	void enqueue(int x)
	{
		// Move all elements from s1 to s2
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		// Push item into s1
		s1.push(x);

		// Push everything back to s1
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	// dequeue an item from the queue
	int dequeue()
	{
		// if first stack is empty
		if (s1.empty()) {
			cout << "Q is Empty";
			exit(0);
		}

		// Return top of s1
		int x = s1.top();
		s1.pop();
		return x;
	}

    void size() {

    }
};

// Driver code
int main()
{
	Queue q;

    int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display size of queue"<<endl;
//    cout<<"4) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
        case 1: {
            int a;
            cout<<"Insert the element in queue : "<<endl;
            cin>>a;
            q.enqueue(a);
            break;
        }
         case 2: q.dequeue();
         break;
         case 3: q.size();
         break;
        //  case 4: q.Display();
        //  break;
         case 5: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=5);
   return 0;

	// q.enqueue(1);
	// q.enqueue(2);
	// q.enqueue(3);

	// cout << q.dequeue() << '\n';
	// cout << q.dequeue() << '\n';
	// cout << q.dequeue() << '\n';

	// return 0;
}
