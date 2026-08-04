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

// function to print the 2D array of random numbers
void PrintMatrixArrayThatRandomNumbers(short arr[3][3], short rows, short columns) {

    // Print the 2D array of random numbers
    cout << "Following are the random numbers: \n" << endl;
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {
            cout << setw(4) << arr[position_x][position_y] << " ";
        }
        cout << endl;
    }

}

// function to calculate and print the sum of each row in the 2D array
void FillArrayBySumOfRows(short arr[3][3], short sumArray[3], short rows, short columns) {

    short sumEachRow = 0;
	// Calculate the sum of each row and store it in sumArray
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {
            sumEachRow += arr[position_x][position_y];
        }
		// Store the sum of the current row in the sumArray
        sumArray[position_x] = sumEachRow;
        sumEachRow = 0;
    }

}

// function to print the sum of each row in the 2D array
void PrintFullArrayThatSumOfRows(short arr[3][3], short sumArray[3], short rows, short columns) {
	
    //print array that contains the sum of each row
	cout << "\nFollowing are the full array elements: \n" << endl;
    for (short position_x = 0; position_x < rows; position_x++) {
        cout << "The element " << position_x + 1 << " is = " << setw(3) << sumArray[position_x] << endl;
    }

}

// main function to execute the program
int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));

	// Declare a 2D array and an array to hold the sum of each row
    short arr[3][3];
	short sumArray[3];

	// Fill the 2D array with random numbers
    FillMatrixArrayByRandomNumbers(arr, 3, 3);

	// Print the 2D array of random numbers
    PrintMatrixArrayThatRandomNumbers(arr, 3, 3);

	// Calculate the sum of each row and store it in sumArray
    FillArrayBySumOfRows(arr, sumArray, 3, 3);

	// Print the sum of each row in the 2D array and the corresponding elements in sumArray
    PrintFullArrayThatSumOfRows(arr, sumArray, 3, 3);

    // Return 0 to indicate successful execution
    return 0;
}

