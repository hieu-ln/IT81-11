#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

#define MAX 5000
//cau 1.1
int a[MAX];
int n;

// Nhap danh sach
void init(int a[], int &n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 1000 + 1;
	cout << "Danh sach da duoc sap xep ngau nhien nhu sau: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void input(int a[], int n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
//xuat danh sach
void output(int a[], int n)
{
	for ( int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void copyArray(int a[], int b[], int n)
{
	for ( int i = 0; i < n; i++)
		b[i] = a[i]; 
}
//Insertion sort
void insertion(int a[], int n)
{
	int i, j, x;
	for (i = 1; i < n; i++)
	{
		x = a[i]; //luu gia tri a[i]
		j = i - 1;
		while (j >= 0 && x < a[i])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
//Doi cho 2 so nguyen
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
//Selection sort
void selection(int a[], int n)
{
	int i, j, z;
	for (i = 0; i < n; i++)
	{
		z = i;
		for ( j = i + 1; j < n; j++)
			if (a[j] < a[z])
				z = j;
		swap(a[z], a[i]);
	}
}
//Interchange sort
void interchange(int a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
//Bubble sort
void bubble(int a[], int n)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < n - 1; i++)
	{
		haveSwap = false;
		for ( j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				haveSwap = true;
			}
		}
		if (haveSwap == false)
			break;
	}
}
//cau 1.8
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && a[left] < pivot)
			left++;
		while (right >= left && a[right] > pivot)
			right--;
		if (left >= right)
			break;
		swap(a[left], a[right]);
		left++;
		right--;
	}
	swap(a[left], a[right]);
	return left;
}
//Quick sort
void quick(int a[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(a, low, high);
		//pi la chi so noi phan tu nay dung dung vi tri va la phan tu chia mang lam 2 phan trai va phai 
		quick(a, low, pi - 1);
		quick(a, pi + 1, high);
	}
}
//cau 1.9
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = l; //neu con cuoi ben trai lonws hon goc 
	if (r < n && a[r] > a[largest])
		largest = r; //neu con phai la con lon hon con lon nhat sau cung
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
//Heap sort
void heap(int a[], int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
//Search sequence
void sequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		cout << "Khong tim thay gia tri " << x << endl;
	else
		cout << "Tim thay gia tri " << x << " tai vi tri " << i << endl;
}
//Search binary
int binary(int a[], int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = l + (r - 1) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binary(a, l, mid - 1, x);
		return binary(a, mid + 1, r, x);
	}
	return -1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "------------MENU------------" << endl;
	cout << "1. Khoi tao danh sach ngau nhien " << endl;
	cout << "2. Nhap danh sach " << endl;
	cout << "3. Xuat danh sach " << endl;
	cout << "4. Sap xep tang dan theo selection " << endl;
	cout << "5. Sap xep tang dan theo insertion " << endl;
	cout << "6. Sap xep tang dan theo bubble " << endl;
	cout << "7. Sap xep tang dan theo interchange " << endl;
	cout << "8. Sap xep tang dan theo quick " << endl;
	cout << "9. Sap xep tang dan theo heap " << endl;
	cout << "10. Tim kiem phan tu 1 cach tuan tu " << endl;
	cout << "11. Tim kiem phan tu theo nhi phan " << endl;
	cout << "12. Thoat " << endl;
	do { 
		cout << "Vui long chon so de thuc hien " << endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, n);
			break;
		case 2:
			input(a, n);
			break;
		case 3:
			cout << "Danh sach la: ";
			break;
		case 4:
			copyArray(a, b, n);
			start = clock();
			selection(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep la: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian thuc hien sap xep selection la: " << duration * 1000000 << " Microseconds";
			break;
		case 5:
			copyArray(a, b, n);
			start = clock();
			insertion(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep la: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian thuc hien sap xep insertion la: " << duration * 1000000 << " Microseconds";
			break;

			case 6:
				copyArray(a, b, n);
				start = clock();
				bubble(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep la: ";
					output(b, n);
				}
				if (duration > 0)
					cout << "Thoi gian thuc hien sap xep bubble la: " << duration * 1000000 << " Microseconds";
				break;

			case 7:
				copyArray(a, b, n);
				start = clock();
				interchange(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep la: ";
					output(b, n);
				}
				if (duration > 0)
					cout << "Thoi gian thuc hien sap xep interchange la: " << duration * 1000000 << " Microseconds";
				break;
			case 8:
				copyArray(a, b, n);
				start = clock();
				quick(a, 0, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach sau khi sap xep la: ";
					output(b, n);
				}
				if (duration > 0)
					cout << "Thoi gian thuc hien sap xep quick la: " << duration * 1000000 << " Microseconds";
				break;
				case 9:
					copyArray(a, b, n);
					start = clock();
					heap(b, n);
					duration = (clock() - start) / (double) CLOCKS_PER_SEC;
					if (n < 100)
					{
						cout << "Danh sach sau khi sap xep la: ";
						output(b, n);
					}
					if (duration > 0)
						cout << "Thoi gian thuc hien sap xep heap la: " << duration * 1000000 << " Microseconds";
					break;
				case 10:
					cout << "Nhap gia tri can tim : ";
					cin >> x;
					start = clock();
					sequence(a, n, x);
					duration = (clock() - start) / (double) CLOCKS_PER_SEC;
					if (duration > 0)
						cout << "Thoi gian tim kiem tuan tu la: " << duration * 1000000 << " Microseconds";
					break;
				case 11:
					cout << "Nhap gia tri can tim : ";
					cin >> x;
					start = clock();
					i = binary(b, 0, n, x);
					duration = (clock() - start) / (double) CLOCKS_PER_SEC;
					if (i == -1)
						cout << "Khong tim thay " << x << endl;
					else
						cout << "Tim thay x " << x << " tai vi tri " << i << endl;
					if (duration > 0)
						cout << "Thoi gian tim kiem nhi phan la: " << duration * 1000000 << " Microseconds";
					break;
				case 12:
					cout << "Goodbye.....!";
					break;
				default:
					break;
		}
	} while (choice >= 11);
	return 0;
}