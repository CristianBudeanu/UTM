#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

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
    printf("|%d\t",arr[i]);
  }
}


void insertion_sort(int *arr,int size)
{
  int i,j;
  int curr, pred;
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
void heap_sort(int *arr,int size)
{
printf("[Heap_Sort]\nFor %d elements-\n",size);
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
}



int menu()
{
    int error_input_found = 0;
menu_start:
    system("cls");
    printf("%+206s\n","|                       Menu                       |\n");
    printf("%+205s\n","|       ------------------------------------       |");
    printf("%+205s\n","|                   1.init_array                   |");
    printf("%+205s\n","|                   2.print_array                  |");
		printf("%+205s\n","|                   3.free_arr                     |");
    printf("%+205s\n","|                   4.insertion_sort               |");
    printf("%+205s\n","|                   5.heap_sort                    |");
    printf("%+205s\n","|                   0.exit                         |");
    int command = 5;
    if(error_input_found)
    {
        printf("\n\nVa rog sa selectati o comanda existenta.\n");
    }
    printf("\n\nCommand : ");
    scanf("%d",&command);
    while(command>5 || command<0)
    {
      printf("Command does not exist .\n");
      error_input_found = 1;
      scanf("%*[^\n]");
      goto menu_start;
    }
    return command;
}

int main()
{
  printf("-----------Start------------\n\n");

    printf("\n\n\n");

    int size;
    int command = 5;
    int *array = NULL;
    int choose[4] = {100,1000,10000,100000};
    while(command)
	  {
	    command = menu();
			if(command == 1)
			{
				if(array != NULL)
				{
					free(array);
				}
choose_again:
					printf("Choose : \n1) 100\n2) 1000\n3) 10000\n4) 100000\n\n");
          printf("Size[1,2,3,4]: ");
					scanf("%d",&size);
          for(int i=1;i<=4;i++)
          {
            if(i == size)
            {
              array = create_init_array(choose[i-1]);
              break;
            }
          }
          if(size>4 && size<0)
          {
            goto choose_again;
          }
			}
      else if(array != NULL)
			{
	    switch(command)
	    {
	      case 2:
	      {
					print_array(array,choose[size-1]);
	        break;
	      }
	      case 3:
	      {
          if(array!=NULL)
          {
            free(array);
            printf("Tabloul a fost eliberat.\n\n");
            array = NULL;
          }
	        break;
	      }

	      case 4:
	      {
          clock_t begin = clock();
          insertion_sort(array,choose[size-1]);
          clock_t end = clock();
          float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
          printf("The elapsed time is %f seconds\n", time_spent);

	        break;
	      }
	      case 5:
	      {
          clock_t begin = clock();
          heap_sort(array,choose[size-1]);
          clock_t end = clock();
          float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
          printf("The elapsed time is %f seconds\n", time_spent);
	        break;
	      }
	      case 0:
	      {
	        return 0;
	      }
	    }
		} else
		{
			printf("\nArray is NULL! Init please! \n");
		}
	    printf("\n\nPress any Key to continue!\n");
	    _getch();
	  }






  return 0;
}
