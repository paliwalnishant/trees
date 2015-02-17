#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void insertNode(struct node *q, int data) {
    if(q == NULL) {
// create the 1st node (root)
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;
    p->data = data;
		root = p;
		return;
	}
	else if(data < q->data && q->left != NULL) {
		q = q->left;
		insertNode(q,data);
	}
	else if(data > q->data && q->right != NULL) {
		q = q->right;
		insertNode(q,data);
	}
	else if(q->left == NULL && data < q->data) {
		struct node *p = (struct node*)malloc(sizeof(struct node));
		p->data = data;
		p->right = NULL;
		p->left = NULL;
		q->left = p;
		return;
	}
	else if(q->right == NULL  && data > q->data) {
		struct node *p = (struct node*)malloc(sizeof(struct node));
		p->data = data;
		p->right = NULL;
		p->left = NULL;
		q->right = p;
		return;
	}
}

void inOrderTrav(struct node *q) {
	if(q != NULL) {
		inOrderTrav(q->left);
		printf("%d\n",q->data);
		inOrderTrav(q->right);
	}
}

void preOrderTrav(struct node *q) {
	if(q != NULL) {
		printf("%d\n",q->data);
		preOrderTrav(q->left);
		preOrderTrav(q->right);
	}
}

void postOrderTrav(struct node *q) {
	if(q != NULL) {
		postOrderTrav(q->left);
		postOrderTrav(q->right);
		printf("%d\n",q->data);
	}
}


void main() {
	int n,x;
	int num_nodes = 10;
	for(x=0;x<num_nodes;x++) {
		printf("Enter new node of BST ");
		scanf("%d",&n);
		insertNode(root,n);
	}

	printf("\nInorder Traversal is:\n");
	inOrderTrav(root);

	printf("\nPreorder Traversal is:\n");
	preOrderTrav(root);

	printf("\nPostorder Traversal is:\n");
	postOrderTrav(root);
}
