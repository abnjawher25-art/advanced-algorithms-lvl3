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
    for (short position_x=0; position_x < rows; position_x++) {
        for (short position_y =0; position_y < columns; position_y++) {
            
            arr[position_x][position_y] = GetRandomNumber();
        }
     }

}

// Function to print the 2D array
void PrintMatrixArrayThatRandomNumbers(short arr[3][3], short rows, short columns) {

	// Print the 2D array
	cout << "Following are the random numbers: \n" << endl;
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {
            cout<<setw(3)<<arr[position_x][position_y]<<" ";
        }
        cout << endl;
    }

}

// Main function
int main()
{
	// Seed the random number generator with the current time
    srand(time(nullptr));
    short arr[3][3];
    
	// Fill the 2D array with random numbers and print it
    FillMatrixArrayByRandomNumbers(arr, 3, 3);
    PrintMatrixArrayThatRandomNumbers(arr, 3, 3);
    
    return 0;
}

