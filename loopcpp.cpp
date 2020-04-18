#include<iostream>
#include<cstdlib>
#include <time.h>
using std::cout;
using std::endl;
using namespace std;
int myArray[/*<NUMBER OF INPUTS>*/];
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int myArray[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)

	for (j = 0; j < n-i-1; j++)
		if (myArray[j] > myArray[j+1])
			swap(&myArray[j], &myArray[j+1]);
}

void printArray(int myArray[], int size)
{
	int i;
	for (i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }
	cout << endl;
}

void selectionSort(int myArray[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (myArray[j] < myArray[min_idx])
			min_idx = j;

		swap(&myArray[min_idx], &myArray[i]);
	}
}
void insertionSort(int myArray[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = myArray[i];
		j = i - 1;

		while (j >= 0 && myArray[j] > key)
		{
			myArray[j + 1] = myArray[j];
			j = j - 1;
		}
		myArray[j + 1] = key;
	}
}
void merge(int myArray[], int l, int m, int r)
{
	int i, j, k=l;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];


	for (i = 0; i < n1; i++)
	{
		L[i] = myArray[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = myArray[m + 1+ j];
	}


	i = 0;
	j = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			myArray[k] = L[i];
			i++;
		}
		else
		{
			myArray[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		myArray[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		myArray[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int myArray[], int l, int r)
{
	if (l < r)
	{

		int m = l+(r-l)/2;
		mergeSort(myArray, l, m);
		mergeSort(myArray, m+1, r);

		merge(myArray, l, m, r);
	}
}
int getMax(int myArray[], int n)
{
	int mx = myArray[0];
	for (int i = 1; i < n; i++)
		if (myArray[i] > mx)
			mx = myArray[i];
	return mx;
}

void countSort(int myArray[], int n, int exp)
{
	int output[n];
	int i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[ (myArray[i]/exp)%10 ]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[ (myArray[i]/exp)%10 ] - 1] = myArray[i];
		count[ (myArray[i]/exp)%10 ]--;
	}

	for (i = 0; i < n; i++)
		myArray[i] = output[i];
}

void radixsort(int myArray[], int n)
{
	int m = getMax(myArray, n);

	for (int exp = 1; m/exp > 0; exp *= 10)
		countSort(myArray, n, exp);
}

void init()
{
 int arr[/*<NUMBER OF INPUTS>*/]={/*<INPUT>*/};
 int i=0;
 for(i=0;i</*<NUMBER OF INPUTS>*/;++i)
 {
    myArray[i]=arr[i];
 }
}

int main()
{
    int i,choice,x;
    for(i=0;i<5;i++)
    {

	   int n = /*<NUMBER OF INPUTS>*/;
	   do
	   {
	   cout<<"\tSELECT SORTING METHOD"
	       <<"\t\n1.Bubble Sort."
	       <<"\t\n2.Selection Sort."
	       <<"\t\n3.Insertion Sort."
	       <<"\t\n4.Merge Sort."
	       <<"\t\n5.Radix Sort";
	   cin>>choice;
	   switch(choice)
	   {
	       case 1 :
	             {
	              init();
	              clock_t t;
	              t = clock();
                      size_t size = 100000;
	              bubbleSort(myArray, n);
	              t = clock() - t;
	              cout << "time: " << t << " miliseconds" << endl;
                      cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	              cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;
		      cout<<"Sorted array: \n";
		      printArray(myArray, n);
	              break;

	             }
	       case 2 :
	              {
	              init();
	              clock_t t1;
	              t1 = clock();
                      size_t size = 100000;
	              selectionSort(myArray, n);
	              t1 = clock() - t1;
	              cout << "time: " << t1 << " miliseconds" << endl;
                      cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	              cout << "time: " << t1*1.0/CLOCKS_PER_SEC << " seconds" << endl;
		      cout << "Sorted array: \n";
	              printArray(myArray, n);
	              break;

	              }
	       case 3 :
	               {
	               init();
	               clock_t t2;
	               t2 = clock();
                       size_t size = 100000;
	               insertionSort(myArray, n);
	               t2 = clock() - t2;
	               cout << "time: " << t2 << " miliseconds" << endl;
                       cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	               cout << "time: " << t2*1.0/CLOCKS_PER_SEC << " seconds" << endl;
		       cout<<"Sorted array: \n";
	               printArray(myArray, n);
	               break;

	               }
	       case 4:
	               {
	               init();
	               clock_t t3;
	               t3 = clock();
                       size_t size = 100000;
	               mergeSort(myArray, 0, n - 1);
	               t3 = clock() - t3;
	               cout << "time: " << t3 << " miliseconds" << endl;
                       cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	               cout << "time: " << t3*1.0/CLOCKS_PER_SEC << " seconds" << endl;
		       cout<<"Sorted array: \n";
	               printArray(myArray, n);
	               break;

	               }

	       case 5:
	              {
	               init();
	               clock_t t4;
	               t4 = clock();
                       size_t size = 100000;
	               radixsort(myArray, n);
	               t4 = clock() - t4;
	               cout << "time: " << t4 << " miliseconds" << endl;
                       cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	               cout << "time: " << t4*1.0/CLOCKS_PER_SEC << " seconds" << endl;
		       cout<<"Sorted array: \n ";
	               printArray(myArray, n);
	               break;

	              }
	       default:
	              {
	                  cout<<"Wrong input";

	              }

	   }

	   }while(choice<6 && choice>0);
    }
	return 0;
}
