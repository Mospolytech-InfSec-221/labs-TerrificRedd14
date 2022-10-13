#include <iostream>
using namespace std;

int* task1(int* mas1, int len)
{
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (mas1[j] > mas1[j + 1])
			{
				temp = mas1[j];
				mas1[j] = mas1[j + 1];
				mas1[j + 1] = temp;
			}
		}
	}
	return mas1;
}

char* task2(char* mas2, int len)
{
	const int alptemp = 26;
	int count[alptemp] = { 0 };
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		j = int(mas2[i] - 'a');
		count[j]++;
	}
	int i = 0;
	j = 0;
	while (j <= alptemp)
	{
		if (count[j] > 0)
		{
			mas2[i] = char(int('a') + j);
			i++;
			count[j]--;
		}
		else
		{
			j++;
		}
	}
	return mas2;
}

int* Merge(int* mas3, int first, int middle, int last)
{
	int i, j, k;
	int n1 = middle - first + 1;
	int n2 = last - middle;
	int L[500], R[500];
	for (i = 0; i < n1; i++)
	{
		L[i] = mas3[first + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = mas3[middle + j + 1];
	}
	i = 0, j = 0;
	for (k = first; i < n1 && j < n2; k++)
	{
		if (L[i] < R[j])
		{
			mas3[k] = L[i++];
		}
		else
		{
			mas3[k] = R[j++];
		}
	}
	while (i < n1)
	{
		mas3[k++] = L[i++];
	}
	while (j < n2)
	{
		mas3[k++] = R[j++];
	}
	return mas3;
}

void task3(int* mas3, int first, int last)
{
	int middle;
	if (first < last)
	{
		middle = (first + last) / 2;
		task3(mas3, first, middle);
		task3(mas3, middle + 1, last);
		Merge(mas3, first, middle, last);
	}
}

void print_int(int* arr, int len)
{
	cout << "Ascendingly sorted array:" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

void print_char(char* arr, int len)
{
	cout << "Ascendingly sorted array:" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	int ctempoice = 0;
	while (true)
	{
		cout << "What do you want to do? \n"
			<< "1. Bubble sorting algorythm\n"
			<< "2. Counting sorting algorythm\n"
			<< "3. Merge sorting algorythm \n"
			<< "4. Exit\n";
		cin >> ctempoice;
		switch (ctempoice)
		{
		case 1:
		{
			int array1[1000];
			int len;
			cout << "Enter the length of array:" << endl;
			cin >> len;
			cout << "Enter array elements:" << endl;
			for (int i = 0; i < len; i++)
			{
				cin >> array1[i];
			}
			task1(array1, len);
			print_int(array1, len);
			break;
		}
		case 2:
		{
			char array1[1000];
			int len;
			cout << "Enter the length of array:" << endl;
			cin >> len;
			cout << "Enter array elements:" << endl;
			for (int i = 0; i < len; i++)
			{
				cin >> array1[i];
			}
			task2(array1, len);
			print_char(array1, len);
			break;
		}
		case 3:
		{
			int array1[1000];
			int len;
			cout << "Enter the length of array:" << endl;
			cin >> len;
			cout << "Enter array elements:" << endl;
			for (int i = 0; i < len; i++)
			{
				cin >> array1[i];
			}
			task3(array1, 0, len - 1);
			print_int(array1, len);
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}
