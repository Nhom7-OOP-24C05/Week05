#pragma once

#include <iostream>

using namespace std;

class SortAlg
{
private:
	SortAlg() {};
	static void (*currentAlg)(float[], int);
public:
	static void SelectionSort(float[], int);
	static void BubbleSort(float[], int);
	static void InsertionSort(float[], int);
	static void SetAlgorithm(void(*pAlg)(float[], int));
	static void Sort(float[], int);
};