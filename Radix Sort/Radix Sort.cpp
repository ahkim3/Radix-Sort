/*
Name: Andrew Kim
Date: May 13, 2021
Program: Radix Sort

I hereby certify that this program represents my
work and that the design and logic was completed
without outside assistance.

Signature: Andrew Kim
*/

#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

void insertionSort(vector<unsigned int>&, const unsigned int);


int main()
{
	unsigned int max = 0, divisor = 1, digit, index;
	unsigned int* nums = new unsigned int[200];
	vector<vector<unsigned int>> buckets(10); // Create 10 buckets for digits
	//vector<unsigned int> bucket;

	srand((unsigned)time(NULL));

	// Create 200 pieces of random data between 1 and randmax
	for (unsigned int i = 0; i < 200; i++)
		nums[i] = (rand() % RAND_MAX) + 1;

	// Print unsorted numbers
	cout << "Unsorted numbers:" << endl;
	for (unsigned int i = 0; i < 200; i++)
		cout << nums[i] << " ";
	cout << endl << endl;

	// Find maximum value
	for (unsigned int i = 0; i < 200; i++)
		if (nums[i] > max)
			max = nums[i];

	// Iterate through each digit starting from the least significant digit
	while (max > 0)
	{
		cout << max << endl; //delete

		// Iterate through each number
		for (unsigned int i = 0; i < 200; i++)
		{
			digit = nums[i] % divisor; // Determine current digit
			buckets.at(digit).push_back(nums[i]); // Place element in bucket
		}

		index = 0;
		for (unsigned int j = 0; j <= 9; j++)
		{
			for (unsigned int i = 0; i < buckets.at(j).size(); i++)
			{
				nums[index] = buckets.at(j).at(i);
				if (index < 199)
					index++;
			}

			buckets.at(j).clear(); // Clear bucket
		}

		// Move onto next power of 10
		max /= 10;
		divisor *= 10;
	}


	// Print sorted numbers
	cout << endl << "Sorted numbers:" << endl;
	for (unsigned int i = 0; i < 200; i++)
		cout << nums[i] << " ";

	// Deallocate memory
	delete[] nums;
}


// Sorts elements in array via insertion sort
void insertionSort(vector<unsigned int>& nums, const unsigned int size)
{
	int j, limit;

	for (unsigned int i = 1; i < size; i++)
	{
		limit = nums.at(i); // Selects first unsorted element
		j = i - 1;

		// Shifts elements of array to the right
		while (j >= 0 && nums.at(j) > limit)
		{
			nums.at(j + 1) = nums.at(j);
			j = j - 1;
		}

		nums.at(j + 1) = limit; // Places unsorted element in sorted position
	}
}
