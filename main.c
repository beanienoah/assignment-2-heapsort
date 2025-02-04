#include <stdio.h>
#include "employee.h"
#include "heap.h"
#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
	//TODO
	Employee employees[MAX_EMPLOYEES]; // ezpz
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		printf("Name: ");
		scanf("%s", employees[i].name);
		printf("Salary: ");
		scanf("%d", &employees[i].salary); // ? might have to ask you a question on weds about this
		printf("\n"); // match up with your solution
	}

	printf("Before: "); 
	printList(employees, MAX_EMPLOYEES);
	heapSort(employees, MAX_EMPLOYEES);
	printf("After: ");
	printList(employees, MAX_EMPLOYEES);
	return 0;
}