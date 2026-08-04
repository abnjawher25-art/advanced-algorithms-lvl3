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

// function to read positive number.
short readPositiveNumber(string message) {

    short number;
    do {
        cout << endl << message;
        cin >> number;

        if (number < 0 || number >99) {
            cout << "must entered number between 0-99\n";
        }

    } while (number < 0 || number >99);

    return number;
}

// Function check if scalar array
bool isItemInArray(short arr[3][3], short number, short rows, short columns)
{

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            if (number == arr[position_x][position_y])
            {
                return true;
            }

        }
    }

    return false;
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

// Function to print the scalar result 2D array
void printLookingForResult(bool result)
{
    if (result == true) {
        cout << "\n\t\tthe element is in array.\n";
    }
    else
    {
        cout << "\n\t\tthe element is not in array.\n";
    }
}


// Main function
int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));
    short arr[3][3];

    // Fill the 2D arrays with random numbers
    FillMatrixArrayByRandomNumbers(arr, 3, 3);

    // Print elements of array
    printMatrixArrayThatRandomNumbers(arr, 3, 3);

    // read number to look for it.
    short number = readPositiveNumber("enter number to look for it: ");

    // calculate time of repeation.
    bool itemResult = isItemInArray(arr, number, 3, 3);

    // Print the check result
    printLookingForResult(itemResult);

    // Return 0 to indicate successful execution
    return 0;
}


