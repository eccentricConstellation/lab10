/*
 *        File: prices.cc
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
int findMaxPrice(const double array[], int size);
// function: findMaxPrice
// purpose: finds the maximum value in an array
// parameters: array[] - array of type double
//             size - the number of elements stored in array[]
// pre conditions: array has values stored in number of elements
//                 provided by size
// post conditions: returns maximum value's index stored in array
int findMinPrice(const double array[], int size);
// function: findMinPrice
// purpose: finds the minimum value in an array
// parameters: array[] - arrayof type double
//             size - the number of elements stored in array[]
// pre conditions: array has values stored in number of elements
//                 provided by size
// post conditions: returns minimum value's index stored in array


int main(int argc, char const *argv[])
{

    double prices[6], price;
    string objects[6], object;
    int size(6), index;
    

    ifstream priceStream, objectStream;
    string inFile = "data1.txt";            //putting together price array
    priceStream.open(inFile.c_str());

    if (priceStream.fail())
    {
      cout << "Error: unable to open file.\n";
      return 0;
    }

    priceStream >> price;
    for (index = 0; index < size; index++)
    {
      prices[index] = price;
      priceStream >> price;
    }

    priceStream.close();

    inFile = "data2.txt";              //putting together object array
    objectStream.open(inFile.c_str());

    if (objectStream.fail())
    {
      cout << "Error: unable to open file.\n";
      return 0;
    }

    objectStream >> object;
    for (index = 0; index < size; index++)
    {
      objects[index] = object;
      objectStream >> object;
    }

    objectStream.close();

    cout.setf(ios::fixed);            //show 2 decimal places
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "The most expensive part is the " << objects[findMaxPrice(prices, size)] << " ($" << prices[findMaxPrice(prices, size)] << ")\n";
    cout << "The least expensive part is the " << objects[findMinPrice(prices, size)] << " ($" << prices[findMinPrice(prices, size)] << ")\n";

    return 0;
}// main


int findMaxPrice(const double array[], int size)
{
	double max = array[0];
  int maxIndex, i(0);

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

int findMinPrice(const double array[], int size)
{
	double min = array[0];
  int minIndex(0), i(0);

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
