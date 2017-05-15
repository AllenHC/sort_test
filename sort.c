#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

//declare the struct
typedef struct{
	int array[SIZE];
	int count;
}Object;
//declare the type of algorithm
typedef enum{
	BUBBLE,
	INSERTION,
	NONE_ALGO
}CHOOSE_ALGO;


Object bubblesort(Object,int);
Object insertionsort(Object,int);
int main()
{
	//declare initial array menber
	srand((unsigned)time(NULL));
	Object A;
	A.count = 0;

	printf("before sort\n");
	for(int i =0;i<SIZE;i++)
	{	
			A.array[i] = (rand() % 100) +1;
			printf("%d ",A.array[i]);

	}
	//choose the algorithm
	CHOOSE_ALGO algorithm = BUBBLE;


	switch(algorithm)
	{
		case BUBBLE:
			printf("\nchoose bubble sort\n");
			A = bubblesort(A,SIZE);
		break;
		case INSERTION:
			printf("\nchoose insertion sort \n");
			A = insertionsort(A,SIZE);
		break;
		default:
			printf("\nthere is valid algorithm choosen\n");
			system("pause");
			return 0;
	}
	
	printf("after insert sort\n");
	for(int i =0;i<SIZE;i++)
		printf("%d ",A.array[i]);
	printf("\nthe number of swap:%d in main\n",A.count);

	system("pause");
	return 0;
}
Object insertionsort(Object A,int size)
{
	int i,j,key;
	for(i = 1;i<SIZE;i++)
	{
		key = A.array[i];
		j = i-1;
		while(key< A.array[j] && j>=0)
		{
			A.array[j+1] = A.array[j];
			j--;
			A.count ++;
		}
		A.array[j+1] = key;
	}
	return A;
}

Object bubblesort(Object A,int size)
{

	int temp;
	int flag = 0;
	for(int i = 1;(i < size)&&(!flag);i++)
	{
		flag = 1;
		for(int j = 0 ;j<(size-i);j++)
		{
			if(A.array[j] > A.array[j+1])
			{
				temp = A.array[j];
				A.array[j] = A.array[j+1];
				A.array[j+1] = temp;
				flag = 0;//set flag to zero if swap occurred at the round.
				A.count ++;
			}
		}
	}
	return A;
}
