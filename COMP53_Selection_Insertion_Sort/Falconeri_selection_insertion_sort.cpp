#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <chrono> 
#include <ctime>
using namespace std;
void SelectionSort(vector<int>& v, int const start, int const end);
void InsertionSort(vector<int>& v, int const start, int const end);
void randomizer(vector<int>& v, int count);
void PrintVector(vector<int> v, int start, int end);


int main()
{
	srand(time(0));

	int size = 15;

	cout << "Enter a number for the size of the array: ";
	cin >> size;

	vector<int> v;
	randomizer(v, size);
	
	PrintVector(v, 0, size);
	PrintVector(v, size, size * 2);
	PrintVector(v, 0, size * 2);

	auto startSelection = chrono::high_resolution_clock::now();

	//Selection Sort
	SelectionSort(v, 0, size);

	auto endSelection = chrono::high_resolution_clock::now();
	
	auto startInsertion = chrono::high_resolution_clock::now();

	//Insertion Sort
	InsertionSort(v, size, size*2);

	auto endInsertion = chrono::high_resolution_clock::now();

	PrintVector(v, 0, size);
	PrintVector(v, size, size * 2);
	PrintVector(v, 0, size * 2);

	cout << "Selection Sort Runtime: " << chrono::duration_cast<chrono::nanoseconds>(endSelection - startSelection).count() << " nanoseconds" << endl;

	cout << "Insertion Sort Runtime: " << chrono::duration_cast<chrono::nanoseconds>(endInsertion - startInsertion).count() << " nanoseconds" << endl;

	return 0;
}

void SelectionSort(vector<int>& v, int const start, int const end)
{
	for (int i = start; i < end; ++i)
	{
		int minIndex = i;

		for (int j = i + 1; j < end; ++j)
		{
			if (v.at(j) < v.at(minIndex))
			{
				minIndex = j;
			}
		}

		swap(v.at(i), v.at(minIndex));
	}

}

void InsertionSort(vector<int>& v, int const start, int const end)
{

	for (int i = start + 1; i < end; ++i)
	{
		int key = v.at(i);
		int j = i - 1;

		while (j >= start && v.at(j) > key)
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
	v.resize(count*2);
	for (int i = 0; i < count; i++)
	{
		v.at(i) = rand() % 99;
		v.at(i + count) = v.at(i);
	}
}

void PrintVector(vector<int> v, int start, int end)
{
	cout << v.at(start);
	for (int i = start + 1; i < end; ++i)
	{
		cout << ", " << v.at(i);
	}
	cout << endl;
}
