#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// ? print array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

void heapify(int arr[], int size, int i)
{
    
    // ? Initialize largest as root
	int largest = i;
	
    // ? right child
	int l = 2 * i + 1;
	
    // ? left child
	int r = 2 * i + 2;

	// ? If left child is larger than root
	if (l < size && arr[l] > arr[largest])
		largest = l;

	// ? If right child is larger than largest
	if (r < size && arr[r] > arr[largest])
		largest = r;

	// ? If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// ? Recursively heapify the affected sub-tree
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int size)
{
	
	// ? build heap 
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);


    // ? sort array using heapify
	for (int i = size - 1; i > 0; i--) {
		
		// ? Move current root to end
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}



int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, size);

	cout << "sorted array with heap is: \n";
	printArray(arr, size);

	cout << "height of array is: \n";
	cout << ceil(log2(size));
}
