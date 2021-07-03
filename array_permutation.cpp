#include <iostream>
using namespace std;

int factorial(int);						//Find the number of permutations
void fill(int **, int , int );		//Enter array and fill lists
void permutate(int **, int *, int, int, int, int );	//Find all permutations
void print(int **, int , int );		//Output all permutations

int main() {
	int **list1;
	int sizeofarray;

	cout << "Size of array: ";
	cin >> sizeofarray;

	int totalarrays = factorial(sizeofarray);
	list1 = new int*[totalarrays];

	for (int row = 0; row < totalarrays; row++)
		list1[row] = new int[sizeofarray];
	cout << endl;
	
	fill(list1, totalarrays, sizeofarray); 
	cout << endl;


	permutate(list1, *list1,0,0, totalarrays, sizeofarray);

	cout << "Permutations:" << endl; 		  
	print(list1, totalarrays, sizeofarray);

	system("pause");
	
	return 0;
}

int factorial(int s)
{
	if (s == 0)
		return 1;
	else
		return s * factorial(s - 1);
}

void fill(int **l, int t, int s)
{
	cout << "Enter your array: ";
	for (int col = 0; col < s; col++)
		cin >> l[0][col];

	for (int row = 1; row < t; row++)
	{
		for (int col = 0; col < s; col++)
			l[row][col]=l[0][col];
	}
}

void print(int **l, int t, int s)
{
	for (int row = 0; row < t; row++)
	{
		for (int col = 0; col < s; col++)
			cout << l[row][col] << " ";
		cout << endl;
	}
}

void permutate(int **a, int *l,int i, int j, int t, int s)
{
	if (i == s)
	{
		for (int row = j; row <= j; row++)
			for (int col = 0; col < s; col++) 
			{
				a[row][col] = l[col];
				cout <<row<<" "<<col<<": "<< a[row][col] <<" ";
				//cout << a[row][col] << " ";
			}
 	}
	else
	{
		for (int col = 0; col < s; col++)
		{
			cout << endl;
			cout << j << "---------------------------";
			cout << endl;
			swap(l[i], l[col]);
			permutate(a, l, i + 1, j, t, s);
			swap(l[i], l[col]);
			j++;
			cout << j;
			cout << endl;
		}
	}
}