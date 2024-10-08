#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <chrono> 
#include <ctime>
using namespace std;
void SelectionSort(vector<int>& v, int const size);
void InsertionSort(vector<int>& v, int const size);
void randomizer(vector<int>& v, int count);
void PrintVector(vector<int> v);


int main()
{
	srand(time(0));

	int size = 1500;

	cout << "Enter a number for the size of the array: ";
	cin >> size;

	vector<int> base;
	randomizer(base, size);

	vector<int> selection = base;
	vector<int> insertion = base;
	
	auto startSelection = chrono::high_resolution_clock::now();

	//Selection Sort
	SelectionSort(selection, size);

	auto endSelection = chrono::high_resolution_clock::now();
	
	auto startInsertion = chrono::high_resolution_clock::now();

	//Insertion Sort
	InsertionSort(insertion, size);

	auto endInsertion = chrono::high_resolution_clock::now();

	cout << "Selection Sort Runtime: " << chrono::duration_cast<chrono::nanoseconds>(endSelection - startSelection).count() << " nanoseconds" << endl;

	cout << "Insertion Sort Runtime: " << chrono::duration_cast<chrono::nanoseconds>(endInsertion - startInsertion).count() << " nanoseconds" << endl;

	return 0;
}

void SelectionSort(vector<int>& v, int const size)
{
	for (int i = 0; i < size; ++i)
	{
		int minIndex = i;

		for (int j = i + 1; j < size; ++j)
		{
			if (v.at(j) < v.at(minIndex))
			{
				minIndex = j;
			}
		}

		swap(v.at(i), v.at(minIndex));
	}

}

void InsertionSort(vector<int>& v, int const size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = v.at(i);
		int j = i - 1;

		while (j >= 0 && v.at(j) > key)
		{
			v.at(j + 1) = v.at(j);
			j--;
		}

		v.at(j + 1) = key;
	}

}

void randomizer(vector<int>& v, int count)
{
	v.clear();
	for (int i = 0; i < count; i++)
	{
		v.push_back(rand() % 99);
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
