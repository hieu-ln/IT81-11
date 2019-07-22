#include<iostream>
#include<stdio.h>
using namespace std;

#define Max 100
// Cau 1.1
int a[Max];
int n;
// Cau 1.2
void input(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap phan tu cua danh sach: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}
// Cau 1.3
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
// Cau 1.4: tim mot phan tu
int search (int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}
// Cau 1.5: Them mot phan tu vao cuoi dannh sach
int insert_last(int a[], int &n, int x)
{
	if (n < Max)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}
// Cau 1.6: Xoa mot phan tu cuoi danh sach
int delete_last(int a[], int &n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}
// Cau 1.7: Xoa mot phan tu tai vi tri i
int Delete(int a[], int &n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}// Cau 1.8: Tim 1 phan tu trong danh sach, neu tim thay xoa phan tu do
int searchAndDelete(int a[], int& n, int x)
{
	for(int i = 0; i < n; i++)
		if (a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	return 0;
}
int main()
{
	int x, i;
	int choice = 0;
	
	cout << "		 BT 1, CHUONGN 2: DANH SACH DON\n";
	cout << "1. Nhap danh sach" << endl
		<< "2. Xuat danh sach" << endl
		<< "3. Tim mot phan tu trong danh sach" << endl
		<< "4. Them mot phan tu vao cuoi danh sach" << endl
		<< "5. Xoa phan tu vao cuoi danh sach" << endl
		<< "6. Xoa phan tu tai vi tri thu i" << endl
		<< "7. Tim va xoa phan tu do trong danh sach" << endl
		<< "8. Thoat" << endl;
	do {
		cout << "Ban chon: " ;
		cin >> choice;
		switch (choice)
		{
		case 1:
			input(a, n);
			cout << "Ban da nhap thanh cong\n";
			break;
		case 2:
			cout << "Danh sach hien co: \n";
			output(a, n);
			break;
		case 3:
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			if (search(a, n, x) == -1)
				cout << "Khong tim thay \n";
			else
				cout << "Tim thay phan tu " << x << " tai vi tri: " << search(a, n, x) + 1 << endl;
			break;
		case 4:
			cout << "Nhap vao phan tu can them vao cuoi danh sach: ";
			cin >> x;
			i = insert_last(a, n, x);
			if (i == 0)
				cout << "Danh sach da day khong them vao duoc\n";
			else
			{
				cout << "Da them " << i << " vao cuoi danh sach" << endl;
				cout << "Danh sach sau khi them: ";
				output(a, n);
			}
			break;
		case 5:
			i = delete_last(a, n);
			if (i <= 0)
				cout << "Danh sach khong con phan tu nao!\n";
			else
			{
				cout << "Da xoa thanh cong!\n";
				cout << "Danh sach sau khi xoa:";
				output(a, n);
			}
			break;
		case 6:
			cout << "Nhap vao vi tri can xoa:";
			cin >> x;
			i = Delete(a, n, x);
			if (i > 0)
			{
				cout << "Xoa thanh cong!\n";
				cout << "Danh sach sau khi xoa:";
				output(a, n);
			}
			else
				cout << "Khong co phan tu nao de xoa!\n";
			break;
		case 7:
			cout << "Nhap vao phan tu can tim va xoa: ";
			cin >> x;
			i = searchAndDelete(a, n, x);
			if (i == 1)
			{
				cout << "Xoa thang cong phan tu co gia tri x = " << x << endl;
				cout << "Danh sach sau khi xoa: ";
				output(a, n);
			}
			else
				cout << "Khong tim thay!\n";
			break;
		default:
			break;
		}
	} while (choice <= 8);
	return 0;
}