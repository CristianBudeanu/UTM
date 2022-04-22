#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<windows.h>

#define COUNT 10

typedef struct BinaryTreeNode
{
	 int data;
	 struct BinaryTreeNode * left;
	 struct BinaryTreeNode * right;
}BinaryTreeNode;

typedef struct BinaryTree
{
	struct BinaryTreeNode * root;
}BinaryTree;

/*--------------------------------------------------------------------------*/

void setcolor(int color){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}

/*--------------------------------------------------------------------------*/

BinaryTreeNode * newBinaryTreeNode(int data)
{
   BinaryTreeNode * new_node = calloc(sizeof(BinaryTreeNode),1);
   new_node->data = data;
   return new_node;
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
    printf("%d\n", my_node->data);

    printTree2D(my_node->left, space);
}

void print2D(BinaryTreeNode *my_node)
{
   printTree2D(my_node, 0);
}

/*--------------------------------------------------------------------------*/

void insertNewNode(BinaryTreeNode * current_node , BinaryTreeNode * new_node)
{
  if(current_node)
  {
    if(current_node->data > new_node->data)
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

void insertNewNodeInTree(BinaryTree * myBinaryTree)
{
  int data;
  printf("[Introduceti data]: \n");
  scanf("%d",&data);
  BinaryTreeNode * new_node = newBinaryTreeNode(data);
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

void SVD(BinaryTreeNode * current_node)
{
	if (current_node == NULL)
	{
		return;
	}
	else
	{
		SVD(current_node->left);
		printf("%d -> ", current_node->data);
		SVD(current_node->right);
	}
}

/*--------------------------------------------------------------------------*/

void VSD(BinaryTreeNode * current_node)
{
	if (current_node == NULL)
	{
		return;
	}
		printf("%d -> ", current_node->data);
		VSD(current_node->left);
		VSD(current_node->right);
}

/*--------------------------------------------------------------------------*/

void SDV(BinaryTreeNode * current_node)
{
	if (current_node == NULL)
	{
		return;
	}
		SDV(current_node->left);
		SDV(current_node->right);
		printf("%d -> ", current_node->data);

}

/*--------------------------------------------------------------------------*/

int TreeDepth(BinaryTreeNode * node)
{
	if(node == NULL)
	{
		return -1;
	}
	else
	{
		int max_Left = TreeDepth(node->left);
		int max_Right = TreeDepth(node->right);


		if(max_Left>max_Right)
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

void DeleteTreeNode(BinaryTreeNode *node)
{
	if(node)
	{
		DeleteTreeNode(node->left);
		DeleteTreeNode(node->right);
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

// PascalCase
// camelCase
// snake_case

// void createSomethingWihoutProblems()
// struct BinaryTreeNode
// void sample_function_with_snake_style()
// int number_with_snake_style;
// BinaryTreeNode my_tree_with_dynamic_memory;


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

BinaryTreeNode *SearchInTree(BinaryTreeNode *node, int key,int *counter)
{
	int k = 1;
	if (node == NULL)
	{
		return NULL;
	}
	if(node->data == key)
	{
		printf("BinaryTree -> %d node\n",key);
		//printf("Max Binary Tree Depth is : %d\n",counter);
		return node;
	}
	if(node && key<node->data)
	{
		*counter+=1;
		SearchInTree(node->left,key,counter);
	}
	else
	{
		*counter+=1;
		SearchInTree(node->right,key,counter);
	}
}

/*--------------------------------------------------------------------------*/

void TreeDepthKey(BinaryTreeNode * node, int key)
{
	int counter = 0;
	BinaryTreeNode *current_node = NULL;

	current_node = SearchInTree(node,key,&counter);
	printf("Max Binary Tree Depth is : %d",counter);

}

/*--------------------------------------------------------------------------*/

struct BinaryTree * create_tree()
{
    BinaryTree *my_binary = malloc(sizeof(struct BinaryTree));
    my_binary->root = NULL;
    return my_binary;
}

/*--------------------------------------------------------------------------*/

void PrintLeaf(BinaryTreeNode *node)
{

		if(!node)
		{
			return;
		}
	if(node->left == NULL && node->right == NULL)
	{
		printf("%d ",node->data);
		return;
	}

	if(node->left)
	{
		PrintLeaf(node->left);
	}
	if(node->right)
	{
		PrintLeaf(node->right);
	}
}

/*--------------------------------------------------------------------------*/

void TreeHeightKey(BinaryTreeNode * node,int key)
{
    BinaryTreeNode *current_node = NULL;
		int counter = 0;
    current_node = SearchInTree(node,key,&counter);
		printf("Max Binary Tree Height is : %d",TreeDepth(current_node));
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
    printf("%+205s\n","|         3)Calcularea adancimii arborelui         |");
    printf("%+205s\n","|              4)Cautarea unui nod                 |");
    printf("%+205s\n","| 5)Calcularea adancimii unui nod (Pe baza de key) |");
    printf("%+205s\n","| 6)Calcularea inaltimii unui nod (Pe baza de key) |");
    printf("%+205s\n","|      7)Afisarea tuturor frunzelor arborelui      |");
    printf("%+205s\n","|         8)Curatirea elementelor arborelui        |");
    printf("%+205s\n","|          9)Eliberarea memoriei arborelui         |");
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

int main()
	{
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
					printf("Introduce-ti numarul de noduri : ");
					scanf("%d",&size);
					for (int i=0;i<size;i++)
					{
						insertNewNodeInTree(my_binary);
					}
			} else if(my_binary != NULL)
			{
	    switch(command)
	    {
	      case 2:
	      {

					if(my_binary->root == NULL)
					{
						printf("Binary is NULL\n");
					}
					else
					{
						print2D(my_binary->root);
						SVD(my_binary->root);
						printf("SVD \n");
						VSD(my_binary->root);
						printf("VSD\n");
						SDV(my_binary->root);
						printf("SDV\n");
					}
	        break;
	      }
	      case 3:
	      {
					printf("Max Binary Tree Depth is : %d",TreeDepth(my_binary->root));
	        break;
	      }

	      case 4:
	      {
					int check = 0;
					printf("Key : ");
					scanf("%d",&key);
				  SearchInTree(my_binary->root,key,&check);
	        break;
	      }
	      case 5:
	      {
					printf("Key : ");
					scanf("%d",&key);
					TreeDepthKey(my_binary->root,key);
	        break;
	      }
	      case 6:
	      {
					printf("Key : ");
					scanf("%d",&key);
					TreeHeightKey(my_binary->root,key);
	        break;
	      }
	      case 7:
	      {
					PrintLeaf(my_binary->root);
	        break;
	      }
	      case 8:
	      {
					ClearTree(my_binary);
	        break;
	      }
	      case 9:
	      {
					DeleteTree(my_binary);
					my_binary = NULL;
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
