
typedef struct data{
	int value;
}Data;

typedef struct node{
	struct node *left;
	struct node *right;
	Data data;
	struct node *parent;
}Node;

typedef struct tree{
	Node * root;
}Tree;
	
Tree *createTree();
Node *createNode(Data d);
void insert(Tree *,Data );
void insertNode(Node *,Data );
Node *search(Tree *,Data );
Node *searchNode(Node *,Data );
void printTree(Node *);
void printpostorderdata(Node *);
void removeNode(Tree *, Data );
void removeLeaf(Tree *, Node *);
void shortCircuit(Tree *, Node *);
void promotion(Tree *, Node *);
void deleteTree(Tree *bst,Node *node);

