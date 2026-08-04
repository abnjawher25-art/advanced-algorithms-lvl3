#include <iostream>
#include <random>
#include<iomanip>
using namespace std;

// function to generate random numbers between 1 and 99
short GetRandomNumber() {

    // define the range for random numbers
    const short from = 1;
    const short to = 99;

    // Generate a random number between 'from' and 'to' (inclusive)
    return rand() % (to - from + 1) + from;
}

// function to fill a 2D array with random numbers
void FillMatrixArrayByRandomNumbers(short arr[3][3], short rows, short columns) {

    // Fill the 2D array with random numbers
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {

            arr[position_x][position_y] = GetRandomNumber();
        }
    }

}

// Function to get sum of all elements in a 2D array
short FindSumOfElementsInMatrixArray(short arr[3][3], short rows, short columns)
{
	short sumOfElements = 0;

    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {
            sumOfElements += arr[position_x][position_y];
        }
    }

    return sumOfElements;
}

// Function to print a 2D array
void printMatrixArrayThatRandomNumbers(short arr[3][3], short rows, short columns)
{
	// Print the 2D array
	cout << "The 2D array is:\n" << endl;
	for (short position_x = 0; position_x < rows; position_x++) {
		for (short position_y = 0; position_y < columns; position_y++) {
			cout << setw(4) << arr[position_x][position_y] << " ";
		}
		cout << endl;
	}
	
}

// Main function
int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));
    short arr[3][3];

    // Fill the 2D array with random numbers,
    // print the array, 
    // and print the sum of each column in the array
    FillMatrixArrayByRandomNumbers(arr, 3, 3);
    printMatrixArrayThatRandomNumbers(arr, 3, 3);

	short sumOfElements = FindSumOfElementsInMatrixArray(arr, 3, 3);

    cout << "\n\nThe sum of all elements in the  matrix array is: " << sumOfElements << endl;

    // Return 0 to indicate successful execution
    return 0;
}

