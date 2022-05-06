#include <iostream>
#include <omp.h>
using namespace std;

void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}

int partition(int arr[], int start, int end)
{
int pivot = arr[end];
int i = start - 1;
for (int j = start; j <= end - 1; j++)
{
if (arr[j] < pivot)
{
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[end]);
return (i + 1);
}

void quicksort(int arr[], int start, int end)
{
int index;
if (start < end)
{
index = partition(arr, start, end);
#pragma omp parallel sections
{
#pragma omp section
{
quicksort(arr, start, index - 1);
}
#pragma omp section
{
quicksort(arr, index + 1, end);
}
}
}
}

int main()
{
int n;
cout << "enter the number of elements to be sorted" << endl;
cin >> n;
int arr[n];
cout << "enter the elements" << endl;
for (int i = 0; i < n; i++)
{
cin >> arr[i];
}
double start = omp_get_wtime();
quicksort(arr, 0, n - 1);
double end = omp_get_wtime();
for (int i = 0; i < n; i++)
{
cout << arr[i]<<endl;
}
cout << (end - start) << " sec" << endl;
cout << endl;
return 0;
}