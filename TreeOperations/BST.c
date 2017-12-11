
#include<stdio.h>
#include<stdlib.h>
#include"BST.h"

int main()
{
	int i = 0, ch = 0;
	Data info;
	Tree *tree1=NULL;
        Node *node1 = NULL;
	FILE *fptr;

	tree1 = createTree();

	fptr = fopen("data.txt","r");
	if(fptr == NULL){
		printf("\nSorry!!File empty.");
	}
	else{
		while(fscanf(fptr,"%d", &info.value) != EOF){
			insert(tree1,info);
		}
	}
	fclose(fptr);
	printf("\nTree is created successfully !!");

	do
	{
		printf("\n\n***************************Menu***********************************");
		printf("\n1.Print\n2.Search\n3.Delete\n4.Exit");
		printf("\nEnter your choice of operation: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				if(tree1->root == NULL)
				{
					printf("Sorry! The Tree is empty !!");
					break;
				}

				printf("\nPreorder of the tree is as follow: \n");
				printTree(tree1->root);
				break;

			case 2:
				printf("\nEnter the value you wish to search: ");
				scanf("%d", &info.value);
				node1=search(tree1,info);

				if(node1 != NULL){
					printf("\n%d is found in the Tree",node1->data.value);
				}

				break;

			case 3:
				printf("\nEnter the value you wish to delete: ");
				scanf("%d", &info.value);
				removeNode(tree1,info);

				break;
			case 4:
				break;
			default:
				printf("Please enter your choice: " );
		}
	}while(ch != 4);

        printf("\n");

	deleteTree(tree1,tree1->root);
	free(tree1);
	tree1=NULL;
        return 0;
}

Tree * createTree()
{

	Tree * ptr = malloc(sizeof(Tree));
	 if(ptr == NULL){
                printf("\nSorry!! Not Enough Memory Available.");
		exit(-1);
	}
        else
	{
        	ptr->root=NULL;
	}

        return ptr;
}

Node *createNode(Data d)
{

        Node * ptr = malloc(sizeof(Node));

        if(ptr == NULL)
	{
                printf("\nSorry!! Not Enough Memory Available.");
		exit(-1);
	}
        else
	{
                ptr->left = NULL;
                ptr->right = NULL;
		ptr->parent = NULL;
		ptr->data = d;
	}
        return ptr;
}


void printTree(Node * pt)
{

	//printf("\nCode Here1\n");
	if(pt != NULL)
	{
		printf("%d ",pt -> data.value);
		printTree(pt -> left);
		printTree(pt -> right);
	}
}

void insert(Tree *bst,Data value)
{

	if(bst->root == NULL)
	{

		Node * new_node = createNode(value);

		bst->root = new_node;
		printf("\nThe root Node is : %d",new_node->data.value);
		new_node=NULL;
	}
	else
	{
		insertNode(bst->root,value);
	}
}

void insertNode(Node *node,Data value)
{

	Node * new_node = createNode(value);
	Node * current = node;

	while( current != NULL)
	{

		new_node->parent=current;

		if(new_node->data.value == current->data.value)
		{
			printf("Sorry! A Duplicate Value is already found in the node. Hence, the value cannot be Inserted");
			return;
		}

		if(new_node->data.value < current->data.value)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	if(new_node->data.value < new_node->parent->data.value)
	{
		new_node->parent->left = new_node;
		printf("\n%d is now inserted to the left of %d",new_node->data.value,new_node->parent->data.value);
		new_node=NULL;
	}
	else
	{
		new_node->parent->right = new_node;
		printf("\n%d is now inserted to the right of %d",new_node->data.value,new_node->parent->data.value);
		new_node=NULL;
	}
}

Node *search(Tree *bst,Data value)
{

	Node *return_value;
	if(bst->root == NULL)
	{
		printf("\nSorry! The tree is Empty");
		return NULL;
	}
	else
	{
		return_value=searchNode(bst->root,value);
	}

	return return_value;
}

Node *searchNode(Node *node,Data val)
{

	Node * current = node;
	Node * return_value;

	if( val.value == current->data.value)
	{
		return current;
	}
	else
	{
		if(val.value < current->data.value){
			if(current->left != NULL)
			{
				return_value=searchNode(current->left,val);
			}
			else
			{
				printf("\nSorry! The Value was not found in the Tree");
				return_value=NULL;
			}
		}
		else{
			if(current->right != NULL)
			{
				return_value=searchNode(current->right,val);
			}
			else{
				printf("\nSorry! The Value was not found in the Tree");
				return_value=NULL;
			}
		}
	}

	return return_value;
}

void removeNode(Tree *bst, Data value){

	Node *node1;
	node1=search(bst,value);
	if(node1==NULL)
	{
		printf("\nSorry! Value which was to be deleted is not found");
		return ;
	}
	else
	{
		if(node1->left==NULL && node1->right==NULL)
		{
			printf("\nLeaf Node being Deleted");
			removeLeaf(bst,node1);
		}
		else
		{
			if(node1->left==NULL || node1->right==NULL)
			{
				printf("\nThe Node with one branch is now deleted");
				shortCircuit(bst,node1);
			}
			else
			{
				promotion(bst,node1);
			}
		}
	}
}

void removeLeaf(Tree *bst, Node *d_node)
{

	if(bst->root==d_node)
	{
		free(d_node);
		d_node=NULL;

		bst->root=NULL;
		printf("\nSince there was only one element in the tree the Rootoot node will be now deleted.\n");
	}
	else
	{
		if(d_node->parent->right==d_node)
		{

			printf("\nThe Node deleted from leaf is : %d", d_node->data.value);
			d_node->parent->right=NULL;

			free(d_node);
			d_node=NULL;
		}
		else
		{
			printf("\nNode deleted from leaf is : %d", d_node->data.value);
			d_node->parent->left=NULL;

			free(d_node);
			d_node=NULL;
		}
	}
}

void shortCircuit(Tree *bst, Node *d_node)
{
	if(d_node->parent->left==d_node)
	{
		if(d_node->left==NULL)
		{
			d_node->parent->left=d_node->right;
			d_node->parent->left->parent = d_node->parent;
		}
		else
		{
			d_node->parent->left=d_node->left;
			d_node->parent->left->parent = d_node->parent;
		}
	}
	else{

		if(d_node->left==NULL)
		{
			d_node->parent->right=d_node->right;
			d_node->parent->right->parent = d_node->parent;
		}
		else
		{
			d_node->parent->right=d_node->left;
			d_node->parent->right->parent = d_node->parent;
		}

	}
	printf("\nNode %d is now deleted from BST\n", d_node->data.value);
	free(d_node);
	d_node=NULL;
}

void promotion(Tree *bst, Node *d_node)
{
   	Node *current = d_node->right;

	while (current->left != NULL)
	{
		current = current->left;
	}

	printf("\nNode removed from BST is: %d", d_node->data.value);
	d_node->data = current->data;

	if (current->left == NULL && current->right == NULL)
	{
		removeLeaf(bst, current);
		printf("\nNode added back to BST: %d\n", d_node->data.value);
		return;
	}

	if (current->left == NULL || current->right == NULL)
	{
		shortCircuit(bst, current);
		printf("\nNode added back to BST: %d\n", d_node->data.value);
		return;
	}
}

void printpostorderdata(Node *node)
{
	if (node != NULL) {
	        printpostorderdata(node->left);
	        printpostorderdata(node->right);
	        printf(" %d ", node->data.value);
	}

}

void deleteTree(Tree *bst,Node *node)
{

	if (node != NULL)
	{
		/* first delete both subtrees */
		deleteTree(bst,node->left);
		deleteTree(bst,node->right);
   		removeLeaf(bst,node);
	}
}
