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

void insertion_sort(int *arr, int size)
{
  int i;
  int curr, pred;
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
}

int main()
{
  int i, size=100;
  int *arr;
  printf("----------Start------------\n");
  for(i=0;i<4;i++)
  {
    printf("-[Insertion_Sort]\nFor %d elements-\n",size);
    arr = create_init_array(size);
    clock_t begin = clock();
    insertion_sort(arr,size);
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds\n", time_spent);
    //print_array(arr,size);
    //printf("\n-----------------------------------------------------------\n");
    size = (size*100)/10;
  }






  return 0;
}
