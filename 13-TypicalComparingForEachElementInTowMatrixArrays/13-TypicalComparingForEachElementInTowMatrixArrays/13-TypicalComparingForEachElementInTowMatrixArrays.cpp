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
bool isTypicalComparison(short arr1[3][3],short arr2[3][3], short rows, short columns)
{
    short sumOfElements = 0;

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            if (arr1[position_x][position_y] != arr2[position_x][position_y])
            {
                return false;
            }
        }
    }

    return true;
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

// Function to print the comparison result of two 2D arrays
void printTypicalComparisonResult(bool isTypical)
{
    // Check if the sums of elements in both arrays are equal
    if (isTypical == true)
    {
        cout << "\nThe elements are equal (typical)." << endl;
    }
    else
    {
        cout << "\nThe elements are not equal (untypical)." << endl;
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
    bool checkValue = isTypicalComparison(arr1, arr2, 3, 3);
 

    // Print both arrays
    printMatrixArrayThatRandomNumbers(arr1, 3, 3);
    printMatrixArrayThatRandomNumbers(arr2, 3, 3);



	// Print the comparison result
    printTypicalComparisonResult(checkValue);

    // Return 0 to indicate successful execution
    return 0;
}


