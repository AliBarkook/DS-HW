#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];

	// ? Index of smaller element
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		// ? If current element is smaller
		// ? than or equal to pivot
		if (arr[j] <= pivot) {

			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// ? Generates Random Pivot, swaps pivot with
// ? end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
	// ? Generate a random number in between low .. high
	srand(time(NULL));
	int random = low + rand() % (high - low);

	// ? Swap A[random] with A[high]
	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}

// ? The main function that implements QuickSort
void quickSort(int arr[], int low, int high)
{
	if (low < high) {

		int pivot = partition_r(arr, low, high);

        // ? recursion
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}


// ? print array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int arr[] = {91, 8, 13, -86, -26, 41, 95, 63, 76, -72, 85, -20, 100, 21, 31, -62, -42, 43, -71, -7};

	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "initial array: \n";
	printArray(arr, size);
	cout << "\n";
	
	quickSort(arr, 0, size-1);


	cout << "sorted array: \n";
	printArray(arr, size);
	
	return 0;
}
