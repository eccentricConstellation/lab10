/*
 *        File: extremetemps.cc
 *      Author: Emma Rice
 *        Date: March 26, 2019
 * Description: ADD DESCRIPTION.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

//function prototypes
int findMaxPrice(const int array[], int size);
// function: findMaxPrice
// purpose: finds the maximum value in an array
// parameters: array[] - array of type int
//             size - the number of elements stored in array[]
// pre conditions: array has values stored in number of elements
//                 provided by size
// post conditions: returns maximum value stored in array
int findMinPrice(const int array[], int size);
// function: findMinPrice
// purpose: finds the minimum value in an array
// parameters: array[] - arrayof type int
//             size - the number of elements stored in array[]
// pre conditions: array has values stored in number of elements
//                 provided by size
// post conditions: returns minimum value stored in array


int main(int argc, char const *argv[])
{

    int price[6];
    int size(30), temp, index;

    ifstream priceStream, objectStream;
    string inFile = "athens_low_temps.txt";
    inStream.open(inFile.c_str());

    if (inStream.fail())
    {
      cout << "Error: unable to open file.\n";
      return 0;
    }

    inStream >> temp;
    for (index = 0; index < size; index++)
    {
      dailyLow[index] = temp;
      inStream >> temp;
    }

    inStream.close();

    cout << "Highest temp was " << findMax(dailyLow, size) << " degrees.\n";
    cout << "Lowest temp was " << findMin(dailyLow, size) << " degrees.\n";
    cout.setf(ios::fixed);
	  cout.setf(ios::showpoint);
	  cout.precision(1);
    cout << "Average low temp was " << findAverage(dailyLow, size) << " degrees.\n";

    return 0;
}// main


int findMaxPrice(const int array[], int size)
{
	int max(0), maxIndex, i(0);

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
    {
      max = array[i];
      maxIndex = i;
    }
	}

	return maxIndex;
} //findMaxPrice

int findMinPrice(const int array[], int size)
{
	int min = array[0], minIndex, i(0);

	for (i = 0; i < size; i++)
	{
		if (array[i] < min)
    {
      min = array[i];
      minIndex = i;
    }
	}

	return minIndex;
} //findMinPrice
