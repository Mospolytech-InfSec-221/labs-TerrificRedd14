#include <iostream> 
using namespace std;

void task1()
{
	int n;
	cout << "Enter number n: ";
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << j << " ";
		}
		cout << "\n";
	}
}

void task2()
{
	int n;
	cin >> n;
	long double c = n;
	for (int k = 1; k <= n; k++)
	{
		cout << c << " ";
		c *= (n - k);
		c /= (k + 1);
	}
	cout << endl;
}

void task3()
{
	int s = 0, k = 0, n; 
	cin >> n;
	while (n != 0) {
		s += n;
		k++;
		cin >> n;
	}
	cout << (double)s / k << endl;
}
 
int main()
{
	int choice = 0;  
	while (true) 
	{
		cout << "What do you want to do? \n1. Task 1\n2. Task 2\n3. Task 3\n4. Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			task1();
			break;
		}
		case 2:
		{
			task2();
			break;
		}
		case 3:
		{
			task3();
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}