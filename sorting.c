#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
\
void BubbleSort(int arr[], int n)
{
  int counter = 1;
  while (counter <= n - 1)
  {
    for (int i = 0; i < n - counter; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(&arr[i], &arr[i + 1]);
      }
    }
    counter++;
  }
}

void insertionSort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int current = arr[i];
    int j = i - 1;
    while (arr[j] > current && j >= 0)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
}

void selectionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[i])
      {
        swap(&arr[i], &arr[j]);
      }
    }
  }
}

int partition(int array[], int low, int high)
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void merge(int arr[], int p, int q, int r)
{

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2)
  {
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main()
{
  int n, choice;
  printf("Enter the size of array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of array: \n");
  for (int i = 0; i < n; i++)
    scanf("%d", arr + i);

  printf("CHOICES-\n1.Bubble sort\n2.Insertion Sort\n3.Selection Sort\n4.Quick Sort\n5.Merge Sort\n\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    BubbleSort(arr, n);
    break;
  case 2:
    insertionSort(arr, n);
    break;
  case 3:
    selectionSort(arr, n);
    break;
  case 4:
    quickSort(arr, 0, n - 1);
    break;
  case 5:
    mergeSort(arr, 0, n - 1);
    break;
  default:
    printf("Your choice doesn't exist!");
  }

  printf("\nSorted array: \n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}