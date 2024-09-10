#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <chrono> 
#include <ctime>
using namespace std;
void SelectionSort(vector<int>& v);
void InsertionSort(vector<int>& v);
void PrintVector(vector<int> v);
void PrintTime(chrono::high_resolution_clock::time_point start, chrono::high_resolution_clock::time_point end);

int main()
{
	vector<int> selection{ 12, 23, 1, 54, 13, 43, 21, 38, 92, 8 };
	vector<int> insertion{ 12, 23, 1, 54, 13, 43, 21, 38, 92, 8 };

	PrintVector(selection);

	auto startSelection = chrono::high_resolution_clock::now();

	SelectionSort(selection);

	auto endSelection = chrono::high_resolution_clock::now();

	auto startInsertion = chrono::high_resolution_clock::now();

	InsertionSort(insertion);

	auto endInsertion = chrono::high_resolution_clock::now();

	PrintVector(insertion);
	PrintTime(startSelection, endSelection);

	PrintVector(selection);
	PrintTime(startInsertion, endInsertion);

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

void PrintTime(chrono::high_resolution_clock::time_point start, chrono::high_resolution_clock::time_point end)
{
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

	cout << "Runtime: " << duration.count() << " nanoseconds" << endl;
}