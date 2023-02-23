#include <stdio.h>
#include<time.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {

  int x;
  for (x = 0; x< size - 1; x++) {
    int min = x;
    int i;
    for (i = x + 1; i < size; i++) {

      if (array[i] < array[min])
        min = i;
    }
    swap(&array[min], &array[x]);
  }
}

void insertionSort(int array[], int n)
{
    int i, x, j;
    for (i = 1; i < n; i++) 
    {
        x= array[i];
        j = i - 1;
  
        while (j >= 0 && array[j] > x) 
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = x;
    }
}

void merge(int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int A[n1], B[n2];

    for (i = 0; i < n1; i++)
        A[i] = array[l + i];
    for (j = 0; j < n2; j++)
        B[j] = array[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (A[i] <= B[j]) 
        {
            array[k] = A[i];
            i++;
        }
        else 
        {
            array[k] = B[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        array[k] = A[i];
        i++;
        k++;
    }
  
    while (j < n2) 
    {
        array[k] = B[j];
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

int partition(int array[], int low, int high) {
  
  int pivot = array[high];
  int i = (low - 1);

  int j;
  for (j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {

  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
  
	int arr1[1000];
  	int arr2[2000];
  	int arr3[5500];
  	int arr4[4200];
  	int arr5[3250];
  	
  	int i,j;
  	
  	for(i = 1000, j = 0; i > 0; i--, j++){
	  
		arr1[j] = i;
    }
    
	for(i = 2000, j = 0; i > 0; i--, j++){
	
		arr2[j] = i;
   }
   
	for(i = 5500, j = 0; i > 0; i--, j++){
	
		arr3[j] = i;
	}
	
	for(i = 4200, j = 0; i > 0; i--, j++){
	
		arr4[j] = i;
	}
	for(i = 3250, j = 0; i > 0; i--, j++){
	
		arr5[j] = i;
	}
		
	clock_t start, end;
    double cputime_used;
    
    //array size=1000
    printf("\n\n-----------Array Size=1000------");

    start = clock();
    selectionSort(arr1, 1000);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    insertionSort(arr1, 1000);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    mergeSort(arr1, 0, 1000);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    quickSort(arr1, 0, 1000);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    //array size=2000
    printf("\n\n------------Array size=2000--------");
    
    start = clock();
    selectionSort(arr2, 2000);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    insertionSort(arr2, 2000);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);

    start = clock();
    mergeSort(arr2, 0, 2000);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    quickSort(arr2, 0, 2000);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    //aray size=5500
    printf("\n\n-----------Array Size=5500------------");
    
    start = clock();
    selectionSort(arr3, 5500);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    insertionSort(arr3, 5500);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    mergeSort(arr3, 0, 5500);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    quickSort(arr3, 0, 5500);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    //array size=4200
    printf("\n\n-----------Array Size =4200-------------");
    
    start = clock();
    selectionSort(arr4, 4200);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    insertionSort(arr4, 4200);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    mergeSort(arr4, 0, 4200);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    quickSort(arr4, 0, 4200);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    //array size=3250
    printf("\n\n--------Array Size=3250-------------");
    
    start = clock();
    selectionSort(arr5, 3250);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    insertionSort(arr5, 3250);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    mergeSort(arr5, 0, 3250);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    start = clock();
    quickSort(arr5, 0, 3250);
    end = clock();

    cputime_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f", cputime_used);
    
    return 0;
}
