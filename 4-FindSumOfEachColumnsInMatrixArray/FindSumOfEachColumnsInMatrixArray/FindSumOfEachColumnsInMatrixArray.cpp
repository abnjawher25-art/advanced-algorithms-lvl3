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

// function to calculate and print the sum of each column in the 2D array
void PrintSumOfEachColumnsAtMatrixArray(short arr[3][3], short rows, short columns) {

    cout << "\n\nFollowing are the sum of each column: \n" << endl;
    short sumEachColumn = 0;
    for (short position_y = 0; position_y < columns; position_y++) {
        for (short position_x = 0; position_x < rows; position_x++) {
            sumEachColumn += arr[position_x][position_y];
        }
        cout << "the sum of column number " << position_y + 1 << " is =" << setw(4) << sumEachColumn << endl;
        sumEachColumn = 0;
    }

}

// main function to execute the program
int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));
    short arr[3][3];

    // Fill the 2D array with random numbers,
    // print the array, 
	// and print the sum of each column in the array
    FillMatrixArrayByRandomNumbers(arr, 3, 3);
    PrintMatrixArrayThatRandomNumbers(arr, 3, 3);
    PrintSumOfEachColumnsAtMatrixArray(arr, 3, 3);

    // Return 0 to indicate successful execution
    return 0;
}

