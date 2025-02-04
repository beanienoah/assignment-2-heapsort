/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// TODO - BuildHeap on the heap
	buildHeap(A, n);
	// TODO - while n > 0:
	// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
	// TODO - A[n-1] now sorted in place, so decrement n
	// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
	for (int i = n - 1; i > 0; i--) { // while n (initially n-1, do here not later) is > 0...
		swap(&A[0], &A[i]); // swap root with element n - 1 (i)
		heapify(A, 0, i); // and heapify up to n-1. decrement n (i) by 1
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// TODO - heapify() every element from A[n/2] down-to A[0]
	// 		  (literally just do that, lol)
	for (int i = (n / 2 - 1); i >= 0; i--) {
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child. [translated from
 * every other pq/heap/blahblahblah implementation i've done]
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	int largest = i; // start with A[i]
	// TODO - get index of left child of element i
	// TODO - get index of right child of element i
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	// TODO - determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
	if(left < n && A[left].salary < A[largest].salary) {
		largest = left;
	}
	
	if(right < n && A[right].salary < A[largest].salary) {
		largest = right;
	}
	// TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller]. I'm gonna take "recursively"
	// 			literally here.
	// TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
	if (largest != i) {
		swap(&A[i], &A[largest]);
		heapify(A, largest, n);
	}
	// rewritten cus now we have swap yipee
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	// TODO: shamelessly stolen from lab 2
	Employee tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

/**
 * Outputs an array of Employees. Except it's not really an array?
 * Dunno if this is what you meant for us to do, but it was the
 * easiest route and it works fine.
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	// TODO
	for (int i = 0; i < n; i++) { // grab each id and salary
		printf("[id=%s sal=%d]", A[i].name, A[i].salary);
		if (i < n -1) { // make it look nice
			printf(", ");
		}
	}
	printf("\n");
}
