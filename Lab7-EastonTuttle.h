/*
Lab7-EastonTuttle.h
Computer Science II
Lab 07 - Implementing Sorts
October 30, 2017

Contains the interfaces for five sort functions using
bubble, insertion, selection, merge, ans quick sort algorithms.
*/

#ifndef SORT_H
#define SORT_H

#include "stdafx.h"
#include <vector>
using std::vector;

void BubbleSort(vector<double> & number);
void InsertionSort(vector<double> & number);
void SelectionSort(vector<double> & number);
void SplitMergeSort(vector<double>& number);
void MergeSort(vector<double>& first, int beginning, int middle, int end, vector<double>& second);
void QuickSort(vector<double> & number);

#endif