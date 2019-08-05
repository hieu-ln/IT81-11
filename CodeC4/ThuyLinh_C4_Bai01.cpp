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
 //Them 1 phan tu su dung DE QUY , khong su dung dia chi con tro
int Insert_Node_Recursive(int x, Node *q)
{
	if (q->info == x)
		return 0;
	else
		if (q->info > x)
		{
			if (q->left == NULL)
			{
				Node *p = new Node;
				p->info = x;
				p->left = NULL;
				p->right = NULL;
				q->left = p;
				return 1;
			}
			else
				return Insert_Node_Recursive(x, q->left);
		}
		else
		{
			if (q ->right == NULL)
			{
				Node *p = new Node;
				p->info = x;
				p->left = NULL;
				p->right = NULL;
				q->right = p;
				return 1;
			}
			else
				return Insert_Node_Recursive(x, q->right);
		}
}
//Them 1 phan tu su dung De Quy, su dung dia chi con tro
void InsertNode(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else
			if (p->info > x)
				return InsertNode(p->left, x);
			else
				return InsertNode(p->right, x);
	}
}
//Tim mot phan tu dung de quy
Node *Search(Node *p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x > p->info)
				return Search(p->right, x);
			else
				return Search(p->left, x);
	}
	return NULL;
}
//Xoa mot nut trong cay dung DE QUY 
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
//Duyet cay
void DuyetLNR(Node *p)
{
	if (p != NULL)
	{
		DuyetLNR(p->left);
		cout << p->info << " ";
		DuyetLNR(p->right);
	}
}
void DuyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}
void DuyetLRN(Node *p)
{
	if (p != NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info << " ";
	}
}
void print2DUtil(Node *p, int space)
{
	if ( p == NULL)
		return;
	space += count;
	print2DUtil(p->right, space);
	cout << endl;
	for (int i = count; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	print2DUtil(p->left, space);
}
void Process_Tree()
{
	print2DUtil(root, 0);
}
int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "------------------MENU----------------------" << endl;
	cout << "1. Khoi tao cay TKNP rong " << endl;
	cout << "2. Them phan tu vao cay TKNP " << endl;
	cout << "3. Tim phan tu vao cay TKNP " << endl;
	cout << "4. Xoa phan tu vao cay TKNP " << endl;
	cout << "5. Duyet cay TKNP theo LNR " << endl;
	cout << "6. Duyet cay TKNP theo NLR " << endl;
	cout << "7. Duyet cay TKNP theo LRN " << endl;
	cout << "8. Xuat cay TKNP " << endl;
	cout << "9. Thoat " << endl;
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			Init();
			cout << "ban vua khoi tao cay TKNP thanh cong!" << endl;
			break;
		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			InsertNode(root, x);
			cout << "Cay nhi phan sau khi them la: ";
			Process_Tree();
			break;
		case 3:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			p = Search(root, x);
			if (p != NULL)
				cout << "Tim thay gia tri "<< x << " trong cay TKNP " << endl;
			else
				cout << "Khong tim thay gia tri " << x << " trong cay TKNP " << endl;
			break;
		case 4:
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			i = Delete(root, x);
			if ( i == 0)
				cout << "Khong tim thay " << x << " de xoa " << endl;
			else
			{
				cout << "Da xoa thanh cong " << x << " trong cay TKNP " << endl;
				cout << "Cay TKNP sau khi xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout << "Cay TKNP duyet theo LNR la: " << endl;
			DuyetLNR(root);
			break;
		case 6:
			cout << "Cay TKNP duyet theo NLR la: " << endl;
			DuyetNLR(root);
			break;
		case 7:
			cout << "Cay TKNP duyet theo LRN la: " << endl;
			DuyetLRN(root);
			break;
		case 8:
			cout << "Cay TKNP nhu sau: " << endl;
			Process_Tree();
			break;
		case 9:
			cout << "Googbye......!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 9);
	system("pause");
	return 0;
}