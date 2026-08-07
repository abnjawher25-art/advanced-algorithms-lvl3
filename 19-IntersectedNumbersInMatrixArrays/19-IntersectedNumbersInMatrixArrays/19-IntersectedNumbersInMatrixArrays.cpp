#include <iostream>
#include <random>
#include <vector>
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

//function to check numbers in array.
bool isElementInMatrixArray(short arr1[3][3],short Number, short rows, short columns)
{
   
    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
           
            if (Number == arr1[position_x][position_y])
            {
                return true;
            }

        }
    }
    return false;
}

// Function to collect all common items in matrices arrays
void IntersectedElementsInArrays(short arr1[3][3], short arr2[3][3], short rows, short columns)
{
    short currentElement;
    bool displayMessage = true;

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            currentElement = arr1[position_x][position_y];

            if (isElementInMatrixArray(arr2, currentElement,3,3))
            {
                
                if (displayMessage == true)
                {
                    cout << "\nthe common items in matrices arrays:\n";
                }
               
                displayMessage = false;

                printf(" %0*d ",2, currentElement);
               
            }

        }
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

    // Print elements of array
    printMatrixArrayThatRandomNumbers(arr1, 3, 3);
    printMatrixArrayThatRandomNumbers(arr2, 3, 3);


    // collect all common items in matrices arrays
    IntersectedElementsInArrays(arr1, arr2, 3, 3);

    // Return 0 to indicate successful execution
    return 0;
}


