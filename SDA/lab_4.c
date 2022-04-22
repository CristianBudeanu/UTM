// Instagram cristian_bn_

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include<windows.h>
#define COUNT 15


typedef struct BinaryTreeNode
{
	 char *firstName;
	 char *lastName;
   int age;
   char *sex;
   int key;
	 struct BinaryTreeNode * left;
	 struct BinaryTreeNode * right;

}BinaryTreeNode;

typedef struct BinaryTree
{
	struct BinaryTreeNode * root;
}BinaryTree;

/*--------------------------------------------------------------------------*/

struct BinaryTree * create_tree()
{
    BinaryTree *my_binary = malloc(sizeof(struct BinaryTree));
    my_binary->root = NULL;
    return my_binary;
}

/*--------------------------------------------------------------------------*/

void setcolor(int color){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}

/*--------------------------------------------------------------------------*/

BinaryTreeNode * newBinaryTreeNode(char *fName,char *lName, int a, char *s, int key)
{
   BinaryTreeNode * new_node = calloc(sizeof(BinaryTreeNode),1);
	 new_node->firstName = calloc(sizeof(char),15);
   strcpy(new_node->firstName,fName);
	 new_node->lastName = calloc(sizeof(char),15);
   strcpy(new_node->lastName, lName);
   new_node->age = a;
	 new_node->sex = calloc(sizeof(char),1);
   strcpy(new_node->sex, s);
   new_node->key = key;
   return new_node;
}

/*--------------------------------------------------------------------------*/

void insertNewNode(BinaryTreeNode * current_node , BinaryTreeNode * new_node)
{
  if(current_node)
  {
    if(current_node->key > new_node->key)
    {
      if(current_node->left)
      {
        insertNewNode(current_node->left,new_node);
      } else
      {
        current_node->left = new_node;
      }
    } else
    {
      if(current_node->right)
      {
        insertNewNode(current_node->right,new_node);
      } else
      {
        current_node->right = new_node;
      }
    }
  }

}

/*--------------------------------------------------------------------------*/

void insertNewNodeInTree(BinaryTree * myBinaryTree, BinaryTreeNode ** storage, int count)
{
  char *fName,*lName,*s;
  int a, k;

  printf("Numele: \n");
	fName = calloc(sizeof(char),15);
  scanf("%s",fName);

	printf("Prenumele: \n");
	lName = calloc(sizeof(char),15);
	scanf("%s",lName);

  printf("Varsta: \n");
  scanf("%d",&a);

	printf("Sex [M sau F]: \n");
	s = calloc(sizeof(char),1);
	scanf("%s",s);

  printf("key: \n");
  scanf("%d",&k);
  BinaryTreeNode * new_node = newBinaryTreeNode(fName,lName,a,s,k);
	storage[count]= new_node;
  if(myBinaryTree->root)
  {
    insertNewNode(myBinaryTree->root, new_node);
  }
	else
  {
    myBinaryTree->root = new_node;
  }

}

/*--------------------------------------------------------------------------*/

BinaryTreeNode *SearchInTree(BinaryTreeNode *node, int new_key, int choice)
{
	if(choice==1)
	{
		if (node == NULL)
		{
			return NULL;
		}
		if(node->key == new_key)
		{
			printf("Key -> %d\n\n", new_key);
			printf("Nume -> %s\n",node->firstName);
			printf("Prenume -> %s\n",node->lastName);
			printf("Varsta -> %d\n",node->age);
			printf("Sex -> %s\n",node->sex);
			return node;
		}
		if(node && new_key<node->key)
		{
			SearchInTree(node->right,new_key,choice);
		}
		else
		{
			SearchInTree(node->left,new_key,choice);
		}
	}
	else if (choice == 0)
	{

		if (node == NULL)
		{
			return NULL;
		}
		if(node->key == new_key)
		{
			printf("Key -> %d\n\n", new_key);
			printf("Nume -> %s\n",node->firstName);
			printf("Prenume -> %s\n",node->lastName);
			printf("Varsta -> %d\n",node->age);
			printf("Sex -> %s\n",node->sex);
			return node;
		}
		if(node && new_key<node->key)
		{
			SearchInTree(node->left,new_key,choice);
		}
		else
		{
			SearchInTree(node->right,new_key,choice);
		}
	}
}

/*--------------------------------------------------------------------------*/

void DeleteTreeNode(BinaryTreeNode *node)
{
	if(node)
	{
		DeleteTreeNode(node->left);
		DeleteTreeNode(node->right);
		free(node->firstName);
		free(node->lastName);
		free(node->sex);
		free(node);
  }
 }

 /*--------------------------------------------------------------------------*/

 void ClearTree(BinaryTree * Tree)
 {
     if(Tree)
     {
         if(Tree->root)
         {
             DeleteTreeNode(Tree->root);
             Tree->root = NULL;
         }
     }
 }

/*--------------------------------------------------------------------------*/

void DeleteTree(BinaryTree *Tree)
{
	if(Tree)
	{
		ClearTree(Tree);
		free(Tree);
		printf("Stergerea arborelui binar a avut loc cu succes\n");
	}
}

/*--------------------------------------------------------------------------*/

int menu()
{
	setcolor(3);
    int error_input_found = 0;
menu_start:
    system("cls");
    printf("%+206s\n","|                       Menu                       |\n");
    printf("%+205s\n","|       ------------------------------------       |");
    printf("%+205s\n","|        1)Introduceti elementele arborelui        |");
    printf("%+205s\n","|            2)Afisarea arborelui binar            |");
		printf("%+205s\n","|              3)Cautarea unui nod                 |");
    printf("%+205s\n","|        4)Parcurgerea arborelui in inordine       |");
    printf("%+205s\n","|       5)Parcurgerea arborelui in preordine       |");
    printf("%+205s\n","|       6)Parcurgerea arborelui in postordine      |");
    printf("%+205s\n","|     7)Parcurgerea arborelui in adancime (DFS)    |");
    printf("%+205s\n","|     8)Parcurgerea arborelui in largime (BFS)     |");
    printf("%+205s\n","|             9)Balansarea arborelui               |");
		printf("%+205s\n","|             10)Oglindirea arborelui              |");
		printf("%+205s\n","|         11)Curatirea elementelor arborelui       |");
		printf("%+205s\n","|          12)Eliberarea memoriei arborelui        |");
    printf("%+205s\n","|                      0)exit                      |");
    int command = 12;
    if(error_input_found)
    {
        printf("\n\nVa rog sa selectati o comanda existenta.\n");
    }
    printf("\n\nCommand : ");
    scanf("%d",&command);
    while(command>12 || command<0)
    {
      printf("Command does not exist .\n");
      error_input_found = 1;
      scanf("%*[^\n]");
      goto menu_start;
    }
    return command;
}

/*--------------------------------------------------------------------------*/

void printTree2D(BinaryTreeNode *my_node, int space)
{
		if (my_node == NULL)
		return;

		space += COUNT;

		printTree2D(my_node->right, space);

		printf("\n");
		for (int i = COUNT; i < space; i++)
		printf(" ");
		printf("%d(%s)\n", my_node->key,my_node->firstName);
		Beep(my_node->key*125, my_node->key*13);


		printTree2D(my_node->left, space);
}

void print2D(BinaryTreeNode *my_node)
{
   printTree2D(my_node, 0);
}

/*--------------------------------------------------------------------------*/

void SVD(BinaryTreeNode * current_node) //Inordine
{
	if (current_node == NULL)
	{
		return;
	}
	else
	{
		SVD(current_node->left);
		printf("Key -> %d\n\n", current_node->key);
		printf("Nume -> %s\n",current_node->firstName);
		printf("Prenume -> %s\n",current_node->lastName);
		printf("Varsta -> %d\n",current_node->age);
		printf("Sex -> %s\n\n",current_node->sex);
		printf("-------------\n\n");
		SVD(current_node->right);
	}
}

/*--------------------------------------------------------------------------*/

void VSD(BinaryTreeNode * current_node) //preordine
{
	if (current_node == NULL)
	{
		return;
	}
  	printf("Key -> %d\n\n", current_node->key);
  	printf("Nume -> %s\n",current_node->firstName);
  	printf("Prenume -> %s\n",current_node->lastName);
  	printf("Varsta -> %d\n",current_node->age);
	  printf("Sex -> %s\n\n",current_node->sex);
  	printf("-------------\n\n");
		VSD(current_node->left);
		VSD(current_node->right);
}

/*--------------------------------------------------------------------------*/

void SDV(BinaryTreeNode * current_node) //postordine
{
	if (current_node == NULL)
	{
		return;
	}
		SDV(current_node->left);
		SDV(current_node->right);
		printf("Key -> %d\n\n", current_node->key);
		printf("Nume -> %s\n",current_node->firstName);
		printf("Prenume -> %s\n",current_node->lastName);
		printf("Varsta -> %d\n",current_node->age);
		printf("Sex -> %s\n\n",current_node->sex);
		printf("-------------\n\n");

}

/*--------------------------------------------------------------------------*/

int TreeDepth(BinaryTreeNode * node)
{
	if (node == NULL)
			return 0;
	else {

			int max_Left = TreeDepth(node->left);
			int max_Right = TreeDepth(node->right);


			if (max_Left>max_Right)
			{
				return (max_Left+1);
			}
			else
			{
			  return (max_Right+1);
			}
	}
}

/*--------------------------------------------------------------------------*/
void bfsLevel(BinaryTreeNode* node, int level , int key_value)
{
	if (node == NULL)
	{
		return;
	}
	if (level == 1 && (node->key == key_value))
	{
		printf("Key -> %d\n\n", node->key);
		printf("Nume -> %s\n",node->firstName);
		printf("Prenume -> %s\n",node->lastName);
		printf("Varsta -> %d\n",node->age);
		printf("Sex -> %s\n\n",node->sex);
		printf("-------------\n\n");
	}
	else if (level > 1) {
		bfsLevel(node->left, level - 1,key_value);
		bfsLevel(node->right, level - 1, key_value);
	}
}

/*--------------------------------------------------------------------------*/

void BFS(BinaryTreeNode* node)
{
    int key;
    printf("Key : ");
    scanf("%d", &key);
    int depth = TreeDepth(node);
    int i;
    for (i = 0; i <=depth; i++)
        bfsLevel(node, i, key);
}

/*--------------------------------------------------------------------------*/

void DFS(BinaryTreeNode * node, int key_value) //Inordine
{
	if (node == NULL)
	{
		return;
	}
  if(node->key == key_value)
  {
    printf("Key -> %d\n\n", node->key);
    printf("Nume -> %s\n",node->firstName);
    printf("Prenume -> %s\n",node->lastName);
    printf("Varsta -> %d\n",node->age);
    printf("Sex -> %s\n\n",node->sex);
    printf("-------------\n\n");
  }
	else
	{
		DFS(node->left,key_value);
		DFS(node->right,key_value );
	}
}

/*--------------------------------------------------------------------------*/

void mirror(BinaryTreeNode * node)
{
  if (node==NULL)
	{
		return;
	}
  else
  {
    BinaryTreeNode * temp_node;

    mirror(node->left);
    mirror(node->right);


    temp_node   = node->left;
    node->left  = node->right;
    node->right = temp_node;
  }
}

/*--------------------------------------------------------------------------*/

void sortArray(BinaryTreeNode ** arr, int size)
{
	BinaryTreeNode * temp;

	for(int i=0;i<size;i++)
	{
		arr[i]->left = NULL;
		arr[i]->right = NULL;
	}


	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(arr[i]->key>arr[j]->key)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}

		}
	}
}

void printArray(BinaryTreeNode ** arr, int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d - ",arr[i]->key);
	}
}


/*--------------------------------------------------------------------------*/

BinaryTreeNode * balanceTreeHelper(BinaryTreeNode ** storage, int start, int end, int choice)
{

	if(start<end){
		int mid = (start + end)/2;
		BinaryTreeNode * node = storage[mid];
	if(choice!=1)
	{
	node->left =  balanceTreeHelper(storage, start, mid, choice);
	node->right = balanceTreeHelper(storage, mid+1, end, choice);
	}
	 else
	{
	node->right =  balanceTreeHelper(storage, start, mid, choice);
	node->left = balanceTreeHelper(storage, mid+1, end, choice);
	}
	return node;
} else
{
	return NULL;
}
}

void balanceTree(BinaryTree * tree, BinaryTreeNode ** storage, int n, int choice)
{
	int start = 0, end = n, mid = (start+end)/2;
  tree->root = balanceTreeHelper(storage, start, end, choice);

}

/*--------------------------------------------------------------------------*/

int main()
	{
		BinaryTreeNode ** storage = NULL;
		double time_spent = 0.0;
		int choice = 0;
		int key;
	  int pos, size;
	  int command = 12;
		BinaryTree *my_binary = NULL;
		while(command)
	  {
	    command = menu();
			if(command == 1)
			{
				if(my_binary != NULL)
				{
					DeleteTree(my_binary);
				}
					my_binary = create_tree();
					printf("Introduce-ti numarul de persoane : ");
					scanf("%d",&size);
					storage = calloc(size,sizeof(BinaryTreeNode*));
					for (int i=0;i<size;i++)
					{
						printf("Persoana #%d\n",i);
						insertNewNodeInTree(my_binary,storage,i);
						printf("\n");
					}
			} else if(my_binary != NULL)
			{
	    switch(command)
	    {
	      case 2:
	      {
					print2D(my_binary->root);
	        break;
	      }
	      case 3:
	      {
					printf("Key : ");
					scanf("%d",&key);
					SearchInTree(my_binary->root,key,choice);
	        break;
	      }

	      case 4:
	      {
					SVD(my_binary->root);
	        break;
	      }
	      case 5:
	      {
					VSD(my_binary->root);
	        break;
	      }
	      case 6:
	      {
					SDV(my_binary->root);
	        break;
	      }
	      case 7:
	      {
          printf("Key : ");
					scanf("%d",&key);
					clock_t begin = clock();
					DFS(my_binary->root,key);
					clock_t end = clock();
					float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
					printf("The elapsed time is %f seconds", time_spent);
	        break;
	      }
	      case 8:
	      {
					clock_t begin = clock();
					BFS(my_binary->root);
	 	 			clock_t end = clock();
					float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	        printf("The elapsed time is %f seconds", time_spent);
	        break;
	      }
	      case 9:
	      {
					sortArray(storage,size);
					printArray(storage,size);
					balanceTree(my_binary,storage,size,choice);
					//print2D(my_binary);
	        break;
	      }
				case 10:
	      {
					if(choice == 0)
					{
						choice = 1;
					}
					else
					{
						choice = 0;
					}
					mirror(my_binary->root);
	        break;
	      }
				case 11:
	      {
					ClearTree(my_binary);
	        break;
	      }
				case 12:
	      {
					DeleteTree(my_binary);
	        break;
	      }
	      case 0:
	      {
	        return 0;
	      }
	    }
		} else
		{
			printf("\nTree is NULL! Init please! \n");
		}
	    printf("\n\nPress any Key to continue!\n");
	    _getch();
	  }

	return 0;
}
