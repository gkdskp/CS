/* Write a menu driven program to implement binary search tree and
perform the following operations:
	a) Insertion b) Deletion c) Search d)Traversal */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left, *right;
};

struct Node *createNode()
{
	struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	scanf("%d", &temp->data);
	temp->left = temp->right = NULL;
	return temp;
}

struct Node *minValue(struct Node *node)
{
	while(node != NULL && node->left != NULL)
		node = node->left;
	return node;
}

struct Node *insertNode(struct Node *node, struct Node *temp)
{
	if(node == NULL)
		return temp;
	else if(node->data >temp-> data)
		node->left = insertNode(node->left, temp);
	else if(node->data < temp->data)
		node->right = insertNode(node->right, temp);
	return node;
}

int searchNode(struct Node *root, int key)
{
	struct Node *node = root;
	while(key > node->data && node->right != NULL)
		node = node->right;

	while(key < node->data && node->left != NULL)
		node = node->left;

	if(node->data == key)
		printf("Element is found\n");
	else
		printf("Element not found\n");
}

struct Node *deleteNode(struct Node *node, int data)
{
	struct Node *temp;
	if(node != NULL){
		if(node->data > data)
			node->left = deleteNode(node->left, data);
		else if(node->data < data)
			node->right = deleteNode(node->right, data);
		else
		{
			if(node->left == NULL)
			{
				temp = node->right;
				free(node);
				return temp;
			}
			else if(node->right == NULL)
				return node->left;
			else
			{
				temp = minValue(node->right);
				node->data = temp->data;
				node->right = deleteNode(node->right, temp->data);
			}
		}
	}
	return node;
}

int preOrder(struct Node *node)
{
	if(node == NULL)
		return;
	else
	{
		printf("%d\t", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
}

int inOrder(struct Node *node)
{
        if(node == NULL)
                return;
        else
        {
			inOrder(node->left);
        	printf("%d\t", node->data);
        	inOrder(node->right);
        }
}

int postOrder(struct Node *node)
{
        if(node == NULL)
                return;
        else
        {
		postOrder(node->left);
		postOrder(node->right);
                printf("%d\t", node->data);
        }
}

int main()
{
	int quit = 0, ch, key;
	struct Node *temp, *root = NULL;

	while(!quit)
	{
		printf("MENU\n"
		"1. Insert\n"
		"2. Pre-order Traversal\n"
		"3. In-order Traversal\n"
		"4. Post-order Traversal\n"
		"5. Delete\n"
		"6. Search\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				temp = createNode();
				root = insertNode(root, temp);
				break;
			case 2:
				preOrder(root);
				printf("\n");
				break;
			case 3:
				inOrder(root);
				printf("\n");
				break;
			case 4:
				postOrder(root);
				printf("\n");
				break;
			case 5:
				scanf("%d", &key);
				root = deleteNode(root, key);
				break;
			case 6:
				scanf("%d", &key);
				searchNode(root, key);
		}
	}
}




