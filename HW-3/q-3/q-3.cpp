#include <bits/stdc++.h>
using namespace std;

struct Queue {
	stack<int> s1, s2;

	void enqueue(int a) {
		// Move all elements from s1 to s2
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		// Push item into s1
		s1.push(a);

		// Push everything back to s1
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	int dequeue() {
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
		cout<<s1.size()<<endl;
    }

    void isEmpty() {

		if (s1.size() > 0)
			cout<<"bale"<<endl;
		else
			cout<<"bale"<<endl;
    }
};



int main() {
	Queue q;

    int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display size of queue"<<endl;
   cout<<"5) check queue is empty"<<endl;
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
         case 4: q.isEmpty();
         break;
         case 5: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=5);
   return 0;

}
