#include <iostream>
#include <random>
#include<iomanip>
using namespace std;

// function to generate random numbers between 1 and 99
short GetRandomNumber() {

    // define the range for random numbers
    const short from = 1;
    const short to = 100;

    // Generate a random number between 'from' and 'to' (inclusive)
    return rand() % (to - from + 1);
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

// Function check if sparce array
bool isSpraceMatrixArray(short arr[3][3], short rows, short columns)
{
    short Calculator = 0;
    short CompareValue = (rows * columns) / 2;

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            if (arr[position_x][position_y] == 0)
            {
                Calculator++;
            }

        }
    }

    if (Calculator > CompareValue) {
        return true;
    }
    else
    {
        return false;
    }

    
}

// Function to print a 2D array
void printMatrixArrayThatRandomNumbers(short arr[3][3], short rows, short columns)
{
    // Print the 2D array
    cout << "\nThe 2D array is:\n" << endl;
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {
            printf("  %0*d ", 2, arr[position_x][position_y]);
        }
        cout << endl;
    }

}

// Function to print the sparce result 2D array
void printSpraceMatrixArrayResult(bool sparceValue)
{
    if (sparceValue== true) {
        cout << "\n\t\tit is sparce array\n";
    }
    else
    {
        cout << "\n\t\tit is not sparce array\n";
    }
}


// Main function
int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));
    short arr[3][3] ;

    // Fill the 2D arrays with random numbers
    FillMatrixArrayByRandomNumbers(arr, 3, 3);

    // Print elements of array
    printMatrixArrayThatRandomNumbers(arr, 3, 3);

    // get if sparce or not.
    bool sparceValue = isSpraceMatrixArray(arr,3, 3);

    // Print the check result
    printSpraceMatrixArrayResult(sparceValue);

    // Return 0 to indicate successful execution
    return 0;
}


