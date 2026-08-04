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
    cout << "\nThe 2D array is:\n" << endl;
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {
            cout << setw(4) << arr[position_x][position_y] << " ";
        }
        cout << endl;
    }

}

// Function to check if the sum of elements in two 2D arrays is equal
bool isSumOfElementsInMatrixArrayEqual(short arr1[3][3], short arr2[3][3], short rows, short columns)
{
	// Get the sum of elements in both arrays
	short sum1 = FindSumOfElementsInMatrixArray(arr1, rows, columns);
	short sum2 = FindSumOfElementsInMatrixArray(arr2, rows, columns);
	// Compare the sums and return true if they are equal, false otherwise
	return sum1 == sum2;
}

// Function to print the comparison result of two 2D arrays
void printComparisonResult(short arr1[3][3], short arr2[3][3], short rows, short columns)
{
	// Check if the sums of elements in both arrays are equal
	if (isSumOfElementsInMatrixArrayEqual(arr1, arr2, rows, columns))
	{
		cout << "\nThe sum of elements in both matrix arrays is equal." << endl;
	}
	else
	{
		cout << "\nThe sum of elements in both matrix arrays is not equal." << endl;
	}
}


// Main function
int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));
    short arr1[3][3];
    short arr2[3][3];

    // Fill the 2D arrays with random numbers
    FillMatrixArrayByRandomNumbers(arr1, 3, 3);
    FillMatrixArrayByRandomNumbers(arr2, 3, 3);

	// Calculate the sum of elements in both arrays
	short sum1 = FindSumOfElementsInMatrixArray(arr1, 3, 3);
	short sum2 = FindSumOfElementsInMatrixArray(arr2, 3, 3);

    // Print both arrays
    printMatrixArrayThatRandomNumbers(arr1, 3, 3);
    printMatrixArrayThatRandomNumbers(arr2, 3, 3);

	// Print the sum of elements in both arrays
	cout << "\nthe sum of elements in the first matrix array is: " << sum1 << endl;
	cout << "\nthe sum of elements in the second matrix array is: " << sum2 << endl;

   
    // Print the comparison result
    printComparisonResult(arr1, arr2, 3, 3);

    // Return 0 to indicate successful execution
    return 0;
}
   

