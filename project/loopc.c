#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#define SIZE 500000


int arr[SIZE];

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
int i, j; 
for (i = 0; i < n-1; i++)	 

	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 




void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n-1; i++) 
	{ 
		// Find the minimum element in unsorted array 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]); 
	} 
} 

void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 

		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		while (j >= 0 && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 
 

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 

int getMax(int arr[], int n)
{   						 // A function to get maximum value in array arr[]; 
    int max = arr[0]; 
	int i=0; 
	    //don't forget to initialise the value of max, either this way or initialize it with a number lower than the minimum of the given array
    for ( i = 1; i < n; i++)
	{
        if (arr[i] > max)
		{        
            max = arr[i];
        }
    }
	return max;
}

void countSort(int arr[], int n, int exp)
{    // A function to do counting sort of arr[] according to
                                                                   // the digit represented by exp.
    int output[n]; 
	                                        // output array
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
	{                           // Store count of occurrences in count[]
        count[ (arr[i]/exp)%10 ]++;
    }

    for (i = 1; i < 10; i++)
	{                        // Change count[i] so that count[i] now contains actual position of this digit in output[]
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
	{                     // Build the output array
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];                 //read carefully how the index is manipulated relating arr[], ccount, output.
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
	{                               // Copy the output array to arr[], so that arr[] now  contains sorted numbers according to current digit
        arr[i] = output[i];
    }
}

void RadixSort(int arr[], int n)
{                    // The function that sorts arr[] of size n using Radix Sort
    int m = getMax(arr, n);                           // Find the maximum number to know number of digits
    int exp=0;                                                                // number, exp is passed. exp is 10^i where i is current digit number                     
  	for ( exp = 1; m/exp > 0; exp *= 10)
	{
        countSort(arr, n, exp);
    }
}

void init()
{
	
	int myArray[SIZE]={/*paste inputs here*/};
	int i=0;
	
	for(i=0;i<SIZE;i++)
	{
		arr[i]=myArray[i];
	}
}

int main()
{
	int n = SIZE;
	int c=0;
	clock_t begin;
	clock_t end;
	double time_spent = 0.0;
	do
	{
		printf("1.Bubble sort\n");
		printf("2.selection sort\n");
		printf("3.insertion sort\n");
		printf("4.merge sort\n");
		printf("5.radix sort\n");
		printf("6.exit\n");
		scanf("%d",&c);

		switch(c)
		{
		case 1:
			init();
			
			begin = clock();
	
			bubbleSort(arr, n); 
		
			end = clock();
			time_spent = 0.0;
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

 		  	printf("Time elpased is %f seconds", time_spent);
 		  	
			break;

		case 2:
			init();
			
			begin = clock();
	
			selectionSort(arr, n); 
		
			end = clock();
			time_spent = 0.0;
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

 		  	printf("Time elpased is %f seconds", time_spent);
 		  	
			break;


		case 3:
			init();
			
			begin = clock();
	
			insertionSort(arr, n); 
		
			end = clock();
			time_spent = 0.0;
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

 		  	printf("Time elpased is %f seconds", time_spent);
 		  	
			break;

		case 4:
			init();
			
			begin = clock();
	
			mergeSort(arr, 0, n - 1); 
		
			end = clock();
			time_spent = 0.0;
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

 		  	printf("Time elpased is %f seconds", time_spent);
 		  	
			break;
		case 5:
			init();
			
			begin = clock();
	
			RadixSort(arr, n);
		
			end = clock();
			time_spent = 0.0;
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

 		  	printf("Time elpased is %f seconds", time_spent);
 		  	
			break;

		}

	}while(c!=6);

	return 0;
}



