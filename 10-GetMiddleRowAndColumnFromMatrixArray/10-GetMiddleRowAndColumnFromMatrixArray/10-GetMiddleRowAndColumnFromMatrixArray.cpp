#include <iostream>
#include <random>
#include<iomanip>
using namespace std;

// Function to generate a random number between 1 and 99
short GetRandomNumber() {

    const short from = 1;
    const short to = 99;

    // Generate a random number between 'from' and 'to' (inclusive)
    return rand() % (to - from + 1) + from;
}

// Function to fill a 2D array with random numbers
void FillMatrixArrayByRandomNumbers(short arr[3][3], short rows, short columns) {

    // Fill the 2D array with random numbers
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {

            arr[position_x][position_y] = GetRandomNumber();
        }
    }

}

// Function to print the 2D array
void PrintMatrixArrayThatRandomNumbers(short arr[3][3], short rows, short columns) {

    // Print the 2D array
    cout << "Following are the random numbers: \n" << endl;
    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            if (arr[position_x][position_y] < 10) {
                cout << "0" << arr[position_x][position_y] << "    ";
            }
            else {
                cout << arr[position_x][position_y] << "    ";
            }
            
        }
        cout << endl;
    }

}

// Function to fill arrays with the middle row and middle column of a 2D array
void FillArrayByMiddleRowAndColumn(short arr[3][3], short MiddleRowsArrary[3], short MiddleColumnsArrary[3], short rows, short columns)
{
    
    short middleRowAndColumn = rows / 2;

    for (short position_x = 0; position_x < rows; position_x++) 
    {
        for (short position_y = 0; position_y < columns; position_y++) 
        {

            if (position_x == middleRowAndColumn)
            {
                MiddleRowsArrary[position_y] = arr[position_x][position_y];
               
            }
            if (position_y == middleRowAndColumn)
            {
                MiddleColumnsArrary[position_x] = arr[position_x][position_y];
                
            }
            
        }
        
    }

}

// Function to print the elements of a 1D array
void PrintArrayElement(short arr[3], short size)
{
    cout << "\nFollowing are the middle elemnts: \n" << endl;
  
    for (int position_x = 0; position_x < size; position_x++)
    {
        if (arr[position_x] <10) {
            cout << "element(" << position_x + 1 << "): 0" << arr[position_x] << endl;
        }
        else {
            cout << "element(" << position_x + 1 << "): " << arr[position_x] << endl;
        }
            
    }
        cout << endl;
    

}

// Main function
int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));

	// Declare a 2D array and two 1D arrays to hold the middle row and column
    short arr[3][3];
    short MiddleRowsArrary[3];
    short MiddleColumnsArrary[3];

    // Fill the 2D array with random numbers and print it
    FillMatrixArrayByRandomNumbers(arr, 3, 3);

	// Print the 2D array
    PrintMatrixArrayThatRandomNumbers(arr, 3, 3);

	// Fill the 1D arrays with the middle row and column of the 2D array
    FillArrayByMiddleRowAndColumn(arr, MiddleRowsArrary, MiddleColumnsArrary, 3, 3);

	// Print the middle row and column arrays
    PrintArrayElement(MiddleRowsArrary, 3);
    PrintArrayElement(MiddleColumnsArrary, 3);


    return 0;
}

