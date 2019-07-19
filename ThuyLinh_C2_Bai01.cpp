#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX = 100;
int a[MAX];
int n;
void input( int a[], int &n)
{
	cout << "Nhap so phan tu can dung: ";
	cin >> n;
	for( int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}

void output( int a[], int n)
{
	for( int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
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

int insert_last( int a[], int &n, int x)
{
	if( n < MAX - 1)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}
 int delete_last( int a[], int &n)
 {
	 if( n < MAX)
	 {
		n--;
		return 1;
	 }
	 else
		 return 0;
 }
 int xoa( int a[], int &n,int y)
 {
	 if( y <= n && y > 0)
	 {
		 for( int i = y - 1; i < n  ; i++)
		 {
			 a[i] = a[i + 1];
		 }
		 n--;
		 return 1;
	 }
	 return 0;
 }
 int searchAndDelete( int a[], int &n, int x)
 {
	 if( n < MAX && n > 0)
	 {
		 if( search(a,n,x) != -1)
		 {
			 xoa(a,n,search(a,n,x) + 1);
			 return 1;
		 }
		 else
			 return 0;
	 }
 }

 int main()
 {
	 int choice = 0;
	 int x,i,y;
	 system("cls");
	 do{
		 cout << "---------------MENU----------------\n";
		 cout << "1.Nhap danh sach\n2.Xuat danh sach\n3.Tim x\n4.Them cuoi\n5.Xoa cuoi\n6.Xoa tai vi tri y \n7.Tim va xoa x\n8.Thoat\nBan chon: ";
		 cin >> choice;
		 switch(choice)
		 {
		 case 1:
			cout << "NHAP DANH SACH\n";
			input(a,n);
			cout << "DANH SACH SAU KHI NHAP LA: ";
			output(a,n);
			break;
		 case 2:
			cout << "DANH SACH HIEN TAI LA\n";
			output(a,n);
			break;
		 case 3:
			 cout << "Nhap gia tri can tim: ";
			 cin >> x;
			 i = search(a,n,x);
			 if( i != -1)
				 cout << x << " co trong danh sach tai vi tri thu " << i + 1 << endl;
			 else
				 cout << x << " khong co trong danh sach\n";
			 break;
		 case 4:
			 cout << "Nhap gia tri can them cuoi: ";
			 cin >> x;
			 i = insert_last(a,n,x);
			 if( i == 1)
			 {
				 cout << "Them cuoi thanh cong\n";
				 cout << "Danh sach sau khi them cuoi la: ";
				 output(a,n);
			 }
			 else
				 cout << "Them cuoi that bai\n";
			 break;
		 case 5:
			 i = delete_last(a,n);
			 if( i == 1)
			 {
				 cout << "Xoa cuoi thanh cong\n";
				 cout << "Danh sach sau khi xoa la: ";
				 output(a,n);
			 }
			 else
				 cout << "Xoa cuoi that bai\n";
			 break;
		 case 6:
			 cout << "Nhap vi tri can xoa: ";
			 cin >> y;
			 i = xoa(a,n,y);
			 if( i == 1)
			 {
				 cout << "Xoa thanh cong\n";
				 cout << "Danh sach sau khi xoa la: ";
				 output(a,n);
			 }
			 else
				 cout << "Xoa khong thanh cong\n";
			 break;
		 case 7:
			 cout << "Nhap gia tri can xoa: ";
			 cin >> x;
			 i = searchAndDelete(a,n,x);
			 if( i == 1)
			 {
				 cout << "Tim va xoa thanh cong\n";
				 cout << "Danh sach sau khi tim va xoa la: ";
				 output(a,n);
			 }
			 else
				 cout << "Tim va xoa that bai\n";
			 break;
		 case 8:
			 break;
		 default:
			 break;
		 }
	 }while( choice != 8);
	 system("pause");
	 return 0;
 }