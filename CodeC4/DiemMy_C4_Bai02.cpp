#include <iostream>
#include <stdio.h>
using namespace std;

#define count 10
struct Node {
	int info;
	Node *left;
	Node *right;
};
Node *root;

//Khoi tao cay rong
void Init()
{
	root = NULL;
}
//Them phan tu vo cay nhi phan KHONG DUNG DE QUY
Node *Insert_Not_Recursive(Node *root, Node *newnode)
{
   if (!root)
   {
      root = newnode;
      root->left = root->right=NULL;
   }  
   else 
   {
      Node * temp = root, *prev = NULL;

      while(temp)
      {
		  if (temp->info < newnode->info)
          temp = temp->right;
        else
          temp = temp->left;
      }
      newnode;
      temp->left = temp->right = NULL;
   }
   return root;
}
//Search binary not using recursive || Tìm kiem phan tu trong cay nhi phan KHONG SU DUNG DE QUY
bool Search_notUsing_Recursive(Node *p, int x)
{
        Node* tmp_root = root;
        while (tmp_root != nullptr)
        {
			if (x == tmp_root->info) return true;
			if (x < tmp_root->info)
            {
                tmp_root = tmp_root->left;
                continue;
            }
			if (x > tmp_root->info)
            {
                tmp_root = tmp_root->right;
            }
        }
        return false;
}
//Delete node in binary not using recursive || Xóa phan tu trong cay nhi phan KHONG SU DUNG DE QUY
void searchStandFor(Node *&p, Node *&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Delete(Node *&t, int x)
{
	if ( t == NULL)
		return 0;
	if ( t->info == x)
	{
		Node *p = t;
		if (t->left == NULL)
			t = t->right;
		else
			if (t ->right == NULL)
				t = t->left;
			else
				searchStandFor(p, t->right);
		delete p;
		return 1;
	}
	if (t->info < x)
		return Delete(t->right, x);
	if (t->info > x)
		return Delete(t->left, x);
}
struct node 
{ 
    int data; 
    struct node* l; 
    struct node* r; 
    node (int data) 
    { 
        this->data = data; 
        l = r = NULL; 
    } 
}; 
  
// Stack type 
struct Stack 
{ 
    int size; 
    int top; 
    struct Node* *array; 
}; 
  

  //DUYET CAY NHI PHAN TIM KIEM DUNG STACK
// Khoi tao Stack 
struct Stack* createStack(int size) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->size = size; 
    stack->top = -1; 
    stack->array = (struct Node**) malloc(stack->size * sizeof(struct Node*)); 
    return stack; 
} 
  
// BASIC OPERATIONS OF STACK // Nhung dieu co ban khi khai bao 1 stack can co
int isFull(struct Stack* stack) 
{  
	return stack->top - 1 == stack->size;
} 
  
int isEmpty(struct Stack* stack) 
{  
	return stack->top == -1;
} 
  
void push(struct Stack* stack, struct Node* node) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = node; 
} 
  
struct Node* pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top--]; 
} 
  
struct Node* peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top]; 
}
void postOrderIterative(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
      
    struct Stack* stack = createStack(count); 
    do { 
        while (root) 
        { 
            if (root->right) 
                push(stack, root->right); 
            push(stack, root); 
            root = root->left; 
        } 
        root = pop(stack); 
        if (root->right && peek(stack) == root->right) 
        { 
            pop(stack);  
            push(stack, root); 
            root = root->right; 
        } 
        else
        { 
			cout << root->info; 
            root = NULL; 
        } 
    } while (!isEmpty(stack)); 
}