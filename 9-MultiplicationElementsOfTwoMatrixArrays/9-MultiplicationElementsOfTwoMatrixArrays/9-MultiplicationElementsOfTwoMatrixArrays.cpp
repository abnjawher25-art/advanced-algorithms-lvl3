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
    cout << "\nFollowing are the random numbers: \n" << endl;
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {
            cout << setw(3) << arr[position_x][position_y] << " ";
        }
        cout << endl;
    }

}

// Function to multiply two 2D arrays element-wise and store the result in a 1D array
void InterviewerMultiplicationForTwoMatrixArrays(short arr1[3][3], short arr2[3][3], short MultiplicationResult[9], short rows, short columns)
{
	// Multiply the two 2D arrays element-wise and store the result in a 1D array
      short currentMultiplicationResult = 0;
      short currentElement = 0;
      
      for (short position_x = 0; position_x < rows; position_x++) 
      {
          for (short position_y = 0; position_y < columns; position_y++) 
          {
              currentMultiplicationResult = arr1[position_x][position_y] * arr2[position_x][position_y];
              MultiplicationResult[currentElement] = currentMultiplicationResult;
              currentElement++;
          }   
      }
       
}

// Function to print the 1D array containing the multiplication results
void PrintMultiplicationArray(short arr[9], short size) {

    // Print the 2D array
    cout << "\nFollowing are the element in arry: \n" << endl;
   
    for (short element = 0; element < size; element++)
    {
            cout <<"the element("<< element+1<<"): " << setw(3) << arr[element] <<endl;
    }
    

}


// Main function
int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));

	// Declare two 2D arrays and a 1D array to hold the multiplication results
    short arr1[3][3];
    short arr2[3][3];
    short MultiplicatioArr[9];

    // Fill the 2D array with random numbers and print it
    FillMatrixArrayByRandomNumbers(arr1, 3, 3);
    FillMatrixArrayByRandomNumbers(arr2, 3, 3);

	// Print the 2D arrays
    PrintMatrixArrayThatRandomNumbers(arr1, 3, 3);
    PrintMatrixArrayThatRandomNumbers(arr2, 3, 3);

	// Multiply the two 2D arrays element-wise and store the result in a 1D array
    InterviewerMultiplicationForTwoMatrixArrays(arr1, arr2, MultiplicatioArr, 3, 3);

	// Print the 1D array containing the multiplication results
    PrintMultiplicationArray(MultiplicatioArr, 9);

	// Return 0 to indicate successful execution
    return 0;
}

