#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <chrono> 
using namespace std;
void SelectionSort(vector<int>& v);
void InsertionSort(vector<int>& v);
void PrintVector(vector<int> v);

int main()
{
	vector<int> selection{ 12, 23, 1, 54, 13, 43, 21, 38, 92, 8 };
	vector<int> insertion{ 12, 23, 1, 54, 13, 43, 21, 38, 92, 8 };

	PrintVector(selection);

	SelectionSort(selection);

	InsertionSort(insertion);

	PrintVector(insertion);

	PrintVector(selection);

	return 0;
}

void SelectionSort(vector<int>& v)
{
	int size = v.size();

	for (int i = 0; i < size; ++i)
	{
		int low = v.at(i);
		int lowi = i;

		for (int j = i + 1; j < size; ++j)
		{
			if (v.at(j) < low)
			{
				low = v.at(j);
				lowi = j;
			}
		}

		int temp = v.at(i);
		v.at(i) = low;
		v.at(lowi) = temp;
	}

}

void InsertionSort(vector<int>& v)
{
	int size = v.size();

	for (int i = 1; i < size; ++i)
	{
		int key = v.at(i);

		for (int j = i - 1; j >= 0; --j)
		{
			if (v.at(j) > key)
			{
				v.at(j + 1) = v.at(j);
				v.at(j) = key;
			}
			else
			{
				break;
			}
		}
	}

}



void PrintVector(vector<int> v)
{
	cout << v.at(0);
	for (int i = 1; i < v.size(); ++i)
	{
		cout << ", " << v.at(i);
	}
	cout << endl;
}