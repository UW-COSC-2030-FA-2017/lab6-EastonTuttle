/*
Lab7-EastonTuttle.cpp
Computer Science II
Lab 07 - Implementing Sorts
October 30, 2017

Contains the definitions for five sort functions using 
bubble, insertion, selection, merge, ans quick sort algorithms.
*/

#include "stdafx.h"
#include "Lab7-EastonTuttle.h"
#include "RandomUtilities.h"
#include "ContainerPrinting.h"
#include "winTimer.h"
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sorts the given vector "number" using the bubble sort technique.
void BubbleSort(vector<double>& number)
{
	bool swapped = true;

	// Perform the sort algorithm until no swapping occurs.
	while (swapped)
	{
		swapped = false;

		// Check each index and compare to the element in the next
		// index. Swap if the next index is smaller than the current.
		for (int i = 0; i < (number.size() - 1); i++)
		{
			if (number[i] > number[i + 1])
			{
				double temp = number[i];
				number[i] = number[i + 1];
				number[i + 1] = temp;
				swapped = true;
			}
		}
	}
}

// Sorts the given vector "number" using the insertion sort technique.
void InsertionSort(vector<double>& number)
{
	// Starting at index 1, compare the element at the index to the indices
	// before it and insert the element into the correct index.
	for (int i = 1; i < number.size(); i++)
	{
		double current = number[i];
		int j = (i - 1);

		while (j >= 0 && (number[j] > current))
		{
			double temp = number[j];
			number[j] = number[j + 1];
			number[j + 1] = temp;
			j--;
		}
		current = number[j + 1];
	}
}

// Sorts the given vector "number" using the selection sort technique.
void SelectionSort(vector<double>& number)
{
	// Determine the smallest element in number and swap it with
	// the first index, then repeat for each index after.
	for (int i = 0; i < (number.size() - 1); i++)
	{
		int minimum = i;

		for (int j = (i + 1); j < number.size(); j++)
		{
			if (number[j] < number[minimum])
			{
				minimum = j;
			}
		}

		if (minimum != i)
		{
			double temp = number[i];
			number[i] = number[minimum];
			number[minimum] = temp;
		}
	}
}

// Sorts the given vector "number" using the merge sort technique.
void SplitMergeSort(vector<double>& number)
{
	if (number.size() <= 1)
	{

	}
	else
	{
		int middle = number.size() / 2;
	}
}


void MergeSort(vector<double>& first, int beginning, int middle, int end, vector<double>& second)
{
	int i = beginning;
	int j = middle;

	for (int k = beginning; k < end; k++)
	{
		if (i < middle && (j >= end || first[i] <= first[j]))
		{
			second[k] = first[i];
			i++;
		}
		else
		{
			second[k] = first[j];
			j++;
		}
	}
}

// Sorts the given vector "number" using the quick sort technique.
void QuickSort(vector<double>& number)
{

}

// Produces an unsorted vector of doubles.
vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
}

// Testing of each of the above functions.
int main()
{
	while (true)
	{
		cout << "Enter size for numbers: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct a sorted list of numbers.
		Timer get;
		get.start();
		vector<double> numbers = getNums(n, -n, n);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		if (n < 10)
			cout << numbers << endl << endl;

		// Report the sorted list of numbers.
		Timer time;
		time.start();
		SelectionSort(numbers);
		cout << numbers << endl << endl;
		time.stop();
		cout << "calculated in " << time() << " seconds"
			<< endl << endl;
	}
	return 0;
}
