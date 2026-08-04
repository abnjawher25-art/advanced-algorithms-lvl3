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
            printf("   %0*d",2, arr[position_x][position_y]);
            
        }
        cout << endl;
    }

}

// function to calculate and print the sum of each row in the 2D array
void FillArrayBySumOfColumns(short arr[3][3], short sumArray[3], short rows, short columns) {

    short sumEachColumn = 0;
    // Calculate the sum of each column and store it in sumArray
    for (short position_y = 0; position_y < columns; position_y++) {
        for (short position_x = 0; position_x < rows; position_x++) {
            sumEachColumn += arr[position_x][position_y];
        }
        // Store the sum of the current column in the sumArray
        sumArray[position_y] = sumEachColumn;
        sumEachColumn = 0;
    }

}

// function to print the sum of each column in the 2D array
void PrintFullArrayThatSumOfColumns(short arr[3][3], short sumArray[3], short columns) {

    //print array that contains the sum of each column
    cout << "\nFollowing are the full array elements: \n" << endl;
    for (short position_y = 0; position_y < columns; position_y++)
    {
        cout << "The element " << position_y + 1 << " is = " << setw(3) << sumArray[position_y  ] << endl;
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

    // Calculate the sum of each column and store it in sumArray
    FillArrayBySumOfColumns(arr, sumArray, 3, 3);

    // Print the sum of each column in the 2D array and the corresponding elements in sumArray
    PrintFullArrayThatSumOfColumns(arr, sumArray, 3);

    // Return 0 to indicate successful execution
    return 0;
}

