#include <iostream>
using namespace std;

// function to get max item in array
void PrintElementsInMatrixArray(short arr[3][3], short rows, short columns)
{
    short MaxElement = arr[0][0];

    cout << "\nthe elements in matrix array:\n\n";
    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            printf("  %0*d", 2, arr[position_x][position_y]);

        }
        printf("\n");
    }

}

// function to get min item in array
bool isPalindromNumber(short arr[3][3], short rows, short columns)
{

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {

            if (arr[position_x][position_y] != arr[position_x][columns -1- position_y])
            {

                return false;

            }

        }
    }

    return true;

}

// Function to print a 2D array
void printIsPalindromMatrixArray(bool result)
{
    if (result == true)
    {
        cout << "\nIs Palindrom Matrix Array? \n- Yes, it is Palimdrom Matrix array.\n";
    }
    else {
        cout << "\nIs Palindrom Matrix Array? \n- No, it is not Palimdrom Matrix array.\n";
    }

}

// Main function
int main()
{

    short arr[3][3] = { {19,74,19}, {72,97,72}, {95,84,95} };

    // Print elements of array
    PrintElementsInMatrixArray(arr, 3, 3);

    // get the value if it is Palindrom matrix array 
    bool isPalindrom = isPalindromNumber(arr, 3, 3);

    // print the values of Palindrom .
    printIsPalindromMatrixArray(isPalindrom);

    // Return 0 to indicate successful execution
    return 0;
}


