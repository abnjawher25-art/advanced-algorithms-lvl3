🚀 Random 3×3 Matrix — Count Number Repetitions

Developer: [Ebrahim Bin-Goher]
Project Category: 2D Arrays, Searching & Frequency Counting

📌 Project Objective

A C++ program that generates a random 3×3 two-dimensional array, asks the user to enter a number between 0 and 99, and then counts how many times that number appears inside the matrix.

This project demonstrates several fundamental C++ programming concepts:

Two-dimensional arrays (2D Arrays).
Functions.
Random number generation.
Nested for loops.
Passing arrays to functions.
User input validation.
Searching inside a 2D array.
Counting occurrences.
Conditional statements.
Formatted output using printf().
💻 Programming Languages & Technologies
Programming Language: C++
Libraries: iostream, random, iomanip
Functions & Features: rand(), srand(), time(), printf()
Data Structure: 2D Array
Matrix Size: 3×3
Random Number Range: 0 → 100
User Input Range: 0 → 99
🧠 Project Algorithm
1. Inputs

The program asks the user to enter a number:

Enter number to look for it:

The accepted range is:

0 → 99
2. Processing Steps
Initialize the random number generator using the current system time.
Create a 3×3 array.
Fill the array with random numbers.
Print the generated matrix.
Ask the user for a number between 0 and 99.
Search through every element of the matrix.
Compare each element with the number entered by the user.
Increment the counter whenever a match is found.
Display the number of repetitions.
If the number does not exist, display an appropriate message.
📤 Outputs

The program displays:

1. Generated Matrix

Example:

The 2D array is:

  12  45  12
  78  12  33
  91  45  67
2. Search Result

If the user enters:

12

The program displays:

the number 12 repeated 3 times in array.

If the number doesn't exist:

the number 99 is unfound in current array.
📝 Project Code
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// function to generate random numbers between 1 and 100
short GetRandomNumber()
{
    // define the range for random numbers
    const short from = 1;
    const short to = 100;

    // Generate a random number
    // between 'from' and 'to'
    return rand() % (to - from + 1);
}

// function to fill a 2D array with random numbers
void FillMatrixArrayByRandomNumbers(
    short arr[3][3],
    short rows,
    short columns)
{
    // Fill the 2D array with random numbers
    for (short position_x = 0;
         position_x < rows;
         position_x++)
    {
        for (short position_y = 0;
             position_y < columns;
             position_y++)
        {
            arr[position_x][position_y] =
                GetRandomNumber();
        }
    }
}

// function to read a positive number
short readPositiveNumber(string message)
{
    short number;

    do
    {
        cout << endl << message;
        cin >> number;

        if (number < 0 || number > 99)
        {
            cout << "must entered number between 0-99\n";
        }

    } while (number < 0 || number > 99);

    return number;
}

// Function to calculate the repetition
// of an item inside a 2D array
short CalculateRepeationOfItemAtArray(
    short arr[3][3],
    short number,
    short rows,
    short columns)
{
    short Calculator = 0;

    for (short position_x = 0;
         position_x < rows;
         position_x++)
    {
        for (short position_y = 0;
             position_y < columns;
             position_y++)
        {
            if (number == arr[position_x][position_y])
            {
                Calculator++;
            }
        }
    }

    return Calculator;
}

// Function to print a 2D array
void printMatrixArrayThatRandomNumbers(
    short arr[3][3],
    short rows,
    short columns)
{
    cout << "\nThe 2D array is:\n" << endl;

    for (short position_x = 0;
         position_x < rows;
         position_x++)
    {
        for (short position_y = 0;
             position_y < columns;
             position_y++)
        {
            printf("  %0*d ",
                   2,
                   arr[position_x][position_y]);
        }

        cout << endl;
    }
}

// Function to print the repetition result
void printRepeationOfItemResult(
    short repeationTimes,
    short number)
{
    if (repeationTimes > 0)
    {
        cout << "\n\t\tthe number "
             << number
             << " repeated "
             << repeationTimes
             << " times in array.\n";
    }
    else
    {
        cout << "\n\t\tthe number "
             << number
             << " is unfound in current array.\n";
    }
}

// Main function
int main()
{
    // Seed the random number generator
    // with the current system time
    srand(time(nullptr));

    short arr[3][3];

    // Fill the 2D array with random numbers
    FillMatrixArrayByRandomNumbers(arr, 3, 3);

    // Print the matrix
    printMatrixArrayThatRandomNumbers(arr, 3, 3);

    // Read the number to search for
    short number =
        readPositiveNumber(
            "enter number to look for it: ");

    // Calculate the number of repetitions
    short repeationVar =
        CalculateRepeationOfItemAtArray(
            arr,
            number,
            3,
            3);

    // Print the search result
    printRepeationOfItemResult(
        repeationVar,
        number);

    // Return 0 to indicate successful execution
    return 0;
}
🔍 Code Explanation
GetRandomNumber()

Responsible for generating random numbers:

short GetRandomNumber()

The code uses:

return rand() % (to - from + 1);

⚠️ There is a small mismatch here.

Although the variables say:

from = 1
to = 100

the expression actually generates:

0 → 100

because + from is missing.

If you want exactly 1 → 100, use:

return rand() % (to - from + 1) + from;

If you intentionally want 0 → 99, the clean version is:

return rand() % 100;

For this particular project, 0 → 99 makes the most sense because your input is also 0 → 99.

🧩 FillMatrixArrayByRandomNumbers()

This function fills every position in the matrix.

It uses nested loops:

for (short position_x = 0;
     position_x < rows;
     position_x++)

The first loop controls the rows.

The second loop controls the columns:

for (short position_y = 0;
     position_y < columns;
     position_y++)

Then:

arr[position_x][position_y] =
    GetRandomNumber();

stores a random number in each position.

For a 3×3 matrix, the function executes:

3 × 3 = 9

times.

🎯 readPositiveNumber()

This function gets the number the user wants to search for.

It uses a do...while loop:

do
{
    cin >> number;

    ...
}
while (number < 0 || number > 99);

This means the user must enter a value between:

0 → 99

If the user enters:

150

the program displays:

must entered number between 0-99

and asks again.

Why do...while?

Because the program needs to ask the user at least once.

🔎 CalculateRepeationOfItemAtArray()

This is the core function of the project.

Its job is to count how many times a specific number appears.

It starts with:

short Calculator = 0;

This is the counter.

Then it checks every element:

if (number == arr[position_x][position_y])
{
    Calculator++;
}

Every time a match is found:

Calculator = Calculator + 1

At the end:

return Calculator;

returns the total number of occurrences.

📊 Example

Suppose the matrix is:

12  45  12
78  12  33
91  45  67

The user searches for:

12

The program finds:

12 → position (0,0)
12 → position (0,2)
12 → position (1,1)

Therefore:

Calculator = 3

Result:

the number 12 repeated 3 times in array.
🖨️ printMatrixArrayThatRandomNumbers()

This function is responsible only for displaying the matrix.

The important statement is:

printf("  %0*d ", 2, arr[position_x][position_y]);

The:

%0*d

formats the number using two digits.

So:

5

is displayed as:

05

while:

45

remains:

45

This gives the matrix a cleaner appearance.

📢 printRepeationOfItemResult()

This function receives:

short repeationTimes
short number

Then it checks:

if (repeationTimes > 0)
If found:
the number 12 repeated 3 times in array.
If not found:
the number 99 is unfound in current array.

So the function separates calculation from display—which is a good programming habit.

🧠 Program Flow

The complete program works like this:

                START
                  │
                  ▼
       Initialize random generator
                  │
                  ▼
          Create 3×3 matrix
                  │
                  ▼
        Fill matrix randomly
                  │
                  ▼
           Print matrix
                  │
                  ▼
       Ask user for a number
                  │
                  ▼
       Validate input 0 → 99
                  │
                  ▼
       Search entire matrix
                  │
                  ▼
       Count matching elements
                  │
                  ▼
        Was number found?
            /          \
          YES           NO
           │             │
           ▼             ▼
   Print repetition    Print not found
           │             │
           └──────┬──────┘
                  ▼
                 END
📸 Example Output
The 2D array is:

  12  45  12
  78  12  33
  91  45  67

enter number to look for it: 12

        the number 12 repeated 3 times in array.

Another example:

The 2D array is:

  12  45  12
  78  12  33
  91  45  67

enter number to look for it: 99

        the number 99 is unfound in current array.
⚠️ Common Mistakes to Avoid
1. Forgetting to Reset the Counter

The counter should start at:

short Calculator = 0;

before searching.

2. Using else Incorrectly

Don't do:

if (number == arr[x][y])
    Calculator++;
else
    return 0;

That would stop the search at the first non-matching element.

The correct approach is to examine all 9 elements.

3. Stopping After Finding One Match

The purpose of the program isn't:

"Does the number exist?"

It's:

"How many times does the number exist?"

Therefore, you must continue searching after every match.

4. Input Range Mismatch

Your input accepts:

0 → 99

but your comments say:

1 → 99

Keep the documentation consistent with the actual program.

5. Function Naming

This:

CalculateRepeationOfItemAtArray

works, but the English spelling would be cleaner as:

CalculateRepetitionOfItemInArray

Likewise:

repeationTimes

could be:

repetitionTimes

Small thing, but clean naming compounds over time—future-you will thank present-you. 😄

💡 Ideas for Further Development
 Search for multiple numbers.
 Display the positions where the number was found.
 Find the most repeated number.
 Find the least repeated number.
 Count repetitions of every number.
 Sort the matrix before searching.
 Search using a separate function for row and column.
 Allow the user to enter matrix dimensions.
 Allow the user to generate a new matrix.
 Build a menu-driven matrix search system.
 Find duplicate numbers automatically.
 Display the frequency table of all elements.
 Replace rand() with modern C++ <random>.
📬 Contact
GitHub: abnjawher25-art
Email: abnjawher25@gmail.com
Phone: +967739758085
LinkedIn: [Add LinkedIn profile]
