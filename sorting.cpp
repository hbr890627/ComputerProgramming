#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define MAXINT 32767
#define TRUE 1
#define FALSE 0


void random_gen(int value[], int size);
void selectionSort(int a[], int size);
void bubbleSort(int[], int);
void printArray(int[], int);
void copyvalue(int a[], int b[], int size);
void quicksort(int array[], int first, int last);
int partition(int array[], int left, int right, int pivotIndex);
void swap(int *a, int *b );


main()
{
   
   int 	values[SIZE] = {0}, values1[SIZE] = {0},
	values2[SIZE] = {0}, values3[SIZE] = {0};

   srand(time(NULL));

   random_gen(values, SIZE);
   copyvalue(values, values1, SIZE);
   copyvalue(values, values2, SIZE);
   copyvalue(values, values3, SIZE);

   printArray(values, SIZE);
   bubbleSort(values1, SIZE);
   printArray(values1, SIZE);
   selectionSort(values2, SIZE);
   printArray(values2, SIZE);
   quicksort(values3, 0, SIZE - 1);
   printArray(values3, SIZE);
   system("pause");

   return 0;
}

void random_gen(int value[], int size)
{
   int i;

   for (i= 0; i <= size - 1; i++)
      value[i] = (rand() % 100);

}


void bubbleSort(int a[], int size)
{
   int pass, j, hold, finished = FALSE;

   for (pass = 1; pass <= size - 1 && finished == FALSE ; pass++)  {
      finished = TRUE;
      for (j = 0; j <= SIZE - pass - 1 ; j++)
         if (a[j] > a[j+1]) {
            hold = a[j];
            a[j] = a[j+1];
	    a[j+1] = hold;
            finished = FALSE;
	 }
      }
}

void selectionSort(int a[], int size)
{
   int pass, i, hold, min = MAXINT, minp;

   for (pass = 0; pass <= size - 2; pass++){
      min = MAXINT ;
      for (i = pass; i <= size - 1; i++) 
	   if ( a[i] < min ){
		min = a[i];
		minp = i;
           }

      hold = a[pass];
      a[pass] = a[minp];
      a[minp] = hold;
   }
}

void printArray(int a[], int size)
{
   int i;

   printf("\n");
   for (i = 0; i <= size - 1; i++) {

      if (i % 20 == 0)
         printf("\n");

      printf("%3d", a[i]);
   }
}

void copyvalue(int a[], int b[], int size)
{
   int i;

   for (i = 0; i <= size - 1; i++) {
      b[i] = a[i];
   }
}

void quicksort(int array[], int first, int last)
{
   int currentLocation,pivotIndex;

   if (first >= last)
      return;
   pivotIndex = first;
   currentLocation = partition(array, first, last, pivotIndex);  /* place an element */
   quicksort(array, first, currentLocation - 1);     /* sort left side   */
   quicksort(array, currentLocation + 1, last);      /* sort right side  */
}

int partition(int a[], int left, int right, int pivotIndex) {
     int storeIndex, pivotValue, i;
     
     pivotValue = a[pivotIndex];
     swap(&a[pivotIndex], &a[right]); // Move pivot to end 
     storeIndex = left; 
     for ( i = left; i<= right-1; i++)
        if (a[i] <= pivotValue){ 
            swap(&a[storeIndex], &a[i]); 
            storeIndex = storeIndex + 1; 
        }
    swap(&a[right], &a[storeIndex]); // Move pivot to its final place 
    return storeIndex; }

/* int partition(int array[], int left, int right)
{
   int position = left;

   while (TRUE) {
      while (array[position] <= array[right] && position != right)
         --right;

      if (position == right)
         return position ;

      if (array[position] > array[right]) {
         swap(array, position, right);
         position = right;
      }

      while (array[left] <= array[position] && left != position )
         ++left;

      if (position == left)
         return position;

      if (array[left] > array[position]) {
	 swap(array, position, left);
         position = left;
      }
   }
}
*/

void swap(int *index1, int *index2)
{
   int temp;

   temp = *index1;
   *index1 = *index2;
   *index2 = temp;
}