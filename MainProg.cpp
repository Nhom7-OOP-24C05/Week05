#include "SortAlg.h"
#include <ctime>

void arrayGenerated(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = static_cast<float>(rand()) / 100;
	}
}

void arrayOutput(float arr[], int n)
{
	cout << "The array:" << endl;
	cout << "     ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i != n - 1) cout << " | ";
	}
}

void main()
{
	// Algorithm set
	cout << "==================== MENU ====================" << endl;
	cout << "     Sorting algorithm available:" << endl;
	cout << "          1. Selection Sort" << endl;
	cout << "          2. Bubble Sort" << endl;
	cout << "          3. Insertion Sort" << endl;
	cout << "==============================================\n" << endl;

	// initialise
	int n, choice;
	do {
		cout << "Input the array size (1 - 100): ";
		cin >> n;
	} while (n < 1 || n > 100);
	float* arr = new float[n];
	srand(time(NULL));
	arrayGenerated(arr, n);

	// generate the array
	cout << "\n----------AUTOMATICALLY GENERATED----------" << endl;
	arrayOutput(arr, n);
	cout << "\n-------------------------------------------\n" << endl;

	// algorithm selection
	do {
		cout << "Input your algorithm selection (1 - 3): ";
		cin >> choice;
	} while (choice < 1 || choice > 3);
	
	void (*menu[])(float[], int) = {
		nullptr,
		SortAlg::SelectionSort,
		SortAlg::BubbleSort,
		SortAlg::InsertionSort
	};
	menu[choice](arr, n);

	cout << "\n----------SUCCESSFULLY SORTED----------" << endl;
	arrayOutput(arr, n);
	cout << "\n---------------------------------------\n" << endl;

	delete[] arr;
}