#include <bits/stdc++.h>
#include<vector>
using namespace std;

class Element {        
  public:          
    int value;
    int priority;
    Element(int v, int p) 
    {
      value = v;
      priority = p;
    }
};

Element *arr[30];
int arr_size = 0;


void printArray()
{

	cout << "updated heap:";

	for (int i = 0; i < arr_size; ++i)
		cout << arr[i]->value << " ";

	cout << "\n";
}

void heapify(int size, int i)
{
    
    // ? Initialize largest as root
	int largest = i;
	
    // ? right child
	int l = 2 * i + 1;
	
    // ? left child
	int r = 2 * i + 2;

	// ? If left child is larger than root
	if (l < size && arr[l]->priority < arr[largest]->priority)
		largest = l;

	// ? If right child is larger than largest
	if (r < size && arr[r]->priority < arr[largest]->priority)
		largest = r;

	// ? If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// ? Recursively heapify the affected sub-tree
		heapify(size, largest);
	}
}

void insertion(int x, int p) 
{
    arr[arr_size] = new Element(x,p);
    arr_size++;

	// ? build heap 
	for (int i = arr_size / 2 - 1; i >= 0; i--)
        heapify(arr_size, i);
}

void deletion() 
{
    int highest_priority = 0;
	for (int i = 0; i < arr_size; ++i)
		if (arr[i]->priority <= highest_priority)
        {
            highest_priority = i;
        }
        
    arr[highest_priority] = NULL;
    
    swap(arr[highest_priority], arr[arr_size-1]);
    
    arr_size--;

    // ? build heap 
	for (int i = arr_size / 2 - 1; i >= 0; i--)
        heapify(arr_size, i);
}

void peek() 
{
    cout << "highest priority element is: \n" << arr[0]->value << "\n";
}

int main() 
{
    
    int c = 0;
    cout << "option: \n 1 for insertion \n 2 for deletion \n 3 for peek \n 4 for exit\n";
    while (c != 4) {
        cout << "select option \n";
        cin >> c;

        switch (c)
        {
        case 1:
            int v, p; 
            cout << "enter value to insert: \n";
            cin >> v;
            cout << "enter priority of value: \n";
            cin >> p;

            insertion(v, p);

            break;

        case 2:

            if (arr_size > 0)
                deletion();
            else
                cout << "array is empty!: \n";
        
            break;

        case 3:
            peek();
            break;
        
        default:
            break;
        }


        // ? updated heap:
        printArray();
    }


}
