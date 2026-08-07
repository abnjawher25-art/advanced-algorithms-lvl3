#include <iostream>
#include <random>
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

// function to get min item in array
short MinElementsInMatrixArray(short arr[3][3], short rows, short columns)
{
    short MinElement= arr[0][0];
   
    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
           
            if (MinElement > arr[position_x][position_y])
            {

                MinElement = arr[position_x][position_y];

            }

        }
    }

    return MinElement;

}

// function to get max item in array
short MaxElementsInMatrixArray(short arr[3][3], short rows, short columns)
{
    short MaxElement= arr[0][0];
   
    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
           
            if (MaxElement < arr[position_x][position_y])
            {

                MaxElement = arr[position_x][position_y];

            }

        }
    }

    return MaxElement;

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

// function to print max and min value in matrix array.
void PrintMaxAndMinValueInMatrixArray(short MinValue, short MaxValue)
{
    printf("\nThe Min Item in matrix array: %0*d", 2, MinValue);
    printf("\nThe Max Item in matrix array: %0*d", 2, MaxValue);
    printf("\n");

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
   
    // get the min value of elements in matrix array 
    short minValue = MinElementsInMatrixArray(arr,3, 3);

    // get the max value of elements in matrix array 
    short maxValue = MaxElementsInMatrixArray(arr,3, 3);

    // print the values of min and max .
    PrintMaxAndMinValueInMatrixArray(minValue, maxValue);

    // Return 0 to indicate successful execution
    return 0;
}


