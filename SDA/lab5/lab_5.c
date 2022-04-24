#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *create_init_array(int size)
{
  int i;
  int * arr = malloc(size*sizeof(int));

  for(i=0;i<size;i++)
  {
    arr[i] = rand() % size + 1;
  }

  return arr;
}

void print_array(int *arr, int size)
{
  int i;
  for(i=0;i<size;i++)
  {
    printf("|%d",arr[i]);
  }
}

void free_array(int *arr, int size)
{
    free(arr);
}

void insertion_sort()
{
  int i,j,size=100;
  int curr, pred;
  int * arr;
  for(j=0;j<4;j++)
  {
    clock_t begin = clock();
    arr = create_init_array(size);
    printf("[Insertion_Sort]\nFor %d elements-\n",size);
    for (i = 1; i < size; i++)
    {
      curr = arr[i];
      pred = i - 1;

      while (curr < arr[pred] && pred >= 0) {
        arr[pred + 1] = arr[pred];
        --pred;
      }
      arr[pred + 1] = curr;
    }
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds\n", time_spent);
    size = (size*100)/10;
    free_array(arr,size);
  }
}



void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int *arr, int n, int i) {
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

// Main function to do heap sort
void heapSort() {
int * arr;
int size=100;
for (int i=0;i<4;i++)
{
clock_t begin = clock();
printf("[Heap_Sort]\nFor %d elements-\n",size);
arr = create_init_array(size);
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(arr, size, i);
  }

  // Heap sort
  for (int i = size - 1; i >= 0; i--)
  {
    swap(&arr[0], &arr[i]);

    // Heapify root element to get highest element at root again
    heapify(arr, i, 0);
  }
  clock_t end = clock();
  float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
  printf("The elapsed time is %f seconds\n", time_spent);
  size = (size*100)/10;
  free_array(arr,size);
  }
}


int main()
{
  printf("-----------Start------------\n\n");

    insertion_sort();
    printf("\n\n\n");
    heapSort();







  return 0;
}
