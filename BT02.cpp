#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

const int MAX = 100;
int a[MAX];
void khoiTao( int a[], int &n)
{
	for( int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
	cout << "Khoi tao thanh cong\n";
}
void output(int a[], int n)
{
	for( int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int insert( int a[], int &n)
{
	int y,x;
	cout << "Nhap gia tri can them: ";
	cin >> x;
	cout << "Nhap thu tu: ";
	cin >> y;
	if( y < n  && y > 0)
	{
		for( int i = n; i >= y; i--)
		{
			a[i] = a[i - 1];
		}
		a[ y -1] = x;
		n++;
		return 1;
	}
	else
		return 0;
}

int search( int a[], int n, int x)
{
	for( int i = 0; i < n; i++)
	{
		if( a[i] == x)
			return i;
	}
	return -1;
}
int Delete(int a[], int &n, int y)
{
	if( y < n && y > 0)
	{
		for( int i = y; i <= n; i++)
		{
			a[i] = a[i+1];
		}
		n--;
		return 1;
	}
	return 0;
}

int searchAndDelete( int a[], int &n, int x)
{
	int i = search(a,n,x);
	if( i != -1)
	{
		if( Delete(a,n,i ) == 1)
			return 1;
	}
	return 0;
}

int main()
{
	int choice = 0;
	int x,i,n;
	do{
		cout << "----------------------------------MENU---------------------------------------\n";
		cout << "1.Khoi tao ngau nhien\n2.Xuat\n3.Them tai vi tri thu i\n4.Tim gia tri x\n5.Tim va xoa phan tu x\n6.Thoat\nBan chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Nhap so luong phan tu can dung: ";
			cin >> n;
			khoiTao(a,n);
			cout << "Danh sach sau khi khoi tao la: ";
			output(a,n);
			break;
		case 2:
			output(a,n);
			break;
		case 3:
			i = insert(a,n);
			if( i == 1)
			{
				cout << "Danh sach sau khi them la: ";
				output(a,n);
				break;
			}
			else
				cout << "Them that bai\n";
			break;
		case 4:
			cout << "Nhap gia tri can tim\n";
			cin >> x;
			i = search(a,n,x);
			if( i != -1)
			{
				cout << x << " co trong danh sach tai vi tri thu " << i + 1 << endl;
			}
			else
				cout << x << " khong co trong danh sach\n";
			break;
		case 5:
			cout << "Nhap gia tri can tim va xoa: ";
			cin >> x;
			if( searchAndDelete(a,n,x) == 1)
			{
					cout << "Tim va xoa thanh cong\n";
					cout << "Danh sach sau khi xoa la: ";
					output(a,n);
			}
			else
				cout << "Tim va xoa khong thanh cong\n";
			break;
		case 6:
			break;
		default:
			break;
		}
	}while(choice != 6);
	return 0;
}