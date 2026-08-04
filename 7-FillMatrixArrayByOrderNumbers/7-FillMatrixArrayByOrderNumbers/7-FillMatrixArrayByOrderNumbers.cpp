#include <iostream>
#include <random>
#include<iomanip>
using namespace std;

// function to generate order numbers between 1 and 9
short GetOrderNumbers() {
   

   const short from = 1;
   const short to = 10;


   static short CurrentRankingNumber = 0;


   CurrentRankingNumber ++;

    
   if (CurrentRankingNumber == to) {

       CurrentRankingNumber = from;
   }
      

   return CurrentRankingNumber;
   
}

// function to fill a 2D array with order numbers
void FillMatrixArrayByOrderNumbers(short arr[3][3], short rows, short columns) {

    // Fill the 2D array with order numbers
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {

            arr[position_x][position_y] = GetOrderNumbers();
        }
    }

}

// function to print the 2D array of order numbers
void PrintMatrixArrayThatOrderNumbers(short arr[3][3], short rows, short columns) {

    // Print the 2D array of order numbers
    cout << "Following are the order numbers: \n" << endl;
    for (short position_x = 0; position_x < rows; position_x++) {
        for (short position_y = 0; position_y < columns; position_y++) {
            cout << setw(4) <<"0" << arr[position_x][position_y] << " ";
        }
        cout << endl;
    }

}

// main function to execute the program
int main()
{
   
    // Declare a 2D array and an array to hold the sum of each row
    short arr[3][3];
   
    // Fill the 2D array with random numbers
    FillMatrixArrayByOrderNumbers(arr, 3, 3);

    // Prshort the 2D array of random numbers
    PrintMatrixArrayThatOrderNumbers(arr, 3, 3);
  
    // Return 0 to indicate successful execution
    return 0;
}

