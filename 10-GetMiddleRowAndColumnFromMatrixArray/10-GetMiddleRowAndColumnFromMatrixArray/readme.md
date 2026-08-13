*.

# 🚀 Random 3×3 Matrix — Middle Row & Column Extractor

> **Developer:** [Ebrahim Bin-Goher]
> **Project Category:** Random Number Generation, 2D Arrays & Array Processing

---

## 📌 Project Objective

A C++ program that generates random numbers between **1 and 99**, stores them in a **3×3 two-dimensional array**, displays the generated matrix, then extracts and displays the **middle row** and **middle column** of the matrix.

This project demonstrates several fundamental C++ programming concepts:

* Two-dimensional arrays (2D Arrays).
* One-dimensional arrays (1D Arrays).
* Functions.
* Random number generation.
* Nested loops.
* Passing arrays to functions.
* Extracting specific rows and columns.
* Conditional statements.
* Output formatting with leading zeros.
* Processing data from a 2D array into 1D arrays.

---

## 💻 Programming Languages & Technologies

* **Programming Language:** C++
* **Libraries:** `iostream`, `random`, `iomanip`
* **Functions & Features:** `rand()`, `srand()`, `time()`
* **Data Structures:** 2D Arrays and 1D Arrays
* **Array Size:** `3×3`

---

## 🧠 Project Algorithm

### 1. Inputs

The program does not require direct user input.

It automatically creates:

* One `3×3` two-dimensional array.
* One `3`-element array for the middle row.
* One `3`-element array for the middle column.

---

### 2. Processing Steps

1. Initialize the random number generator.
2. Create a `3×3` array.
3. Create two `1D` arrays to store the middle row and middle column.
4. Call `FillMatrixArrayByRandomNumbers()`.
5. Generate random numbers between `1` and `99`.
6. Store the generated numbers inside the `3×3` matrix.
7. Call `PrintMatrixArrayThatRandomNumbers()`.
8. Display the complete matrix.
9. Call `FillArrayByMiddleRowAndColumn()`.
10. Determine the middle position using:

```cpp
rows / 2
```

11. Extract the middle row into `MiddleRowsArrary`.
12. Extract the middle column into `MiddleColumnsArrary`.
13. Call `PrintArrayElement()` for the middle row.
14. Call `PrintArrayElement()` for the middle column.
15. Display the extracted elements.

---

## 📤 Outputs

The program produces three main outputs:

### 1. Random 3×3 Matrix

A matrix containing **9 random numbers**, where each number is between **1 and 99**.

### 2. Middle Row

The three elements located in the center row of the matrix.

### 3. Middle Column

The three elements located in the center column of the matrix.

---

## 📝 Project Code

```cpp
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// Function to generate a random number between 1 and 99
short GetRandomNumber()
{
    const short from = 1;
    const short to = 99;

    // Generate a random number between 'from' and 'to' (inclusive)
    return rand() % (to - from + 1) + from;
}

// Function to fill a 2D array with random numbers
void FillMatrixArrayByRandomNumbers(
    short arr[3][3],
    short rows,
    short columns)
{
    // Fill the 2D array with random numbers
    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            arr[position_x][position_y] = GetRandomNumber();
        }
    }
}

// Function to print the 2D array
void PrintMatrixArrayThatRandomNumbers(
    short arr[3][3],
    short rows,
    short columns)
{
    // Print the 2D array
    cout << "Following are the random numbers: \n" << endl;

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            if (arr[position_x][position_y] < 10)
            {
                cout << "0" << arr[position_x][position_y] << "    ";
            }
            else
            {
                cout << arr[position_x][position_y] << "    ";
            }
        }

        cout << endl;
    }
}

// Function to fill arrays with the middle row and middle column
// of a 2D array
void FillArrayByMiddleRowAndColumn(
    short arr[3][3],
    short MiddleRowsArrary[3],
    short MiddleColumnsArrary[3],
    short rows,
    short columns)
{
    short middleRowAndColumn = rows / 2;

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            if (position_x == middleRowAndColumn)
            {
                MiddleRowsArrary[position_y] =
                    arr[position_x][position_y];
            }

            if (position_y == middleRowAndColumn)
            {
                MiddleColumnsArrary[position_x] =
                    arr[position_x][position_y];
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
        if (arr[position_x] < 10)
        {
            cout << "element(" << position_x + 1
                 << "): 0" << arr[position_x] << endl;
        }
        else
        {
            cout << "element(" << position_x + 1
                 << "): " << arr[position_x] << endl;
        }
    }

    cout << endl;
}

// Main function
int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));

    // Declare a 2D array and two 1D arrays
    // to hold the middle row and column
    short arr[3][3];
    short MiddleRowsArrary[3];
    short MiddleColumnsArrary[3];

    // Fill the 2D array with random numbers
    FillMatrixArrayByRandomNumbers(arr, 3, 3);

    // Print the 2D array
    PrintMatrixArrayThatRandomNumbers(arr, 3, 3);

    // Fill the 1D arrays with the middle row and column
    // of the 2D array
    FillArrayByMiddleRowAndColumn(
        arr,
        MiddleRowsArrary,
        MiddleColumnsArrary,
        3,
        3
    );

    // Print the middle row
    PrintArrayElement(MiddleRowsArrary, 3);

    // Print the middle column
    PrintArrayElement(MiddleColumnsArrary, 3);

    return 0;
}
```

---

## 🔍 Code Explanation

### `GetRandomNumber()`

This function generates a random number between **1 and 99**.

```cpp
return rand() % (to - from + 1) + from;
```

The formula produces a value within the specified range:

```text
1 → 99
```

---

### `FillMatrixArrayByRandomNumbers()`

This function receives the `3×3` matrix and fills every element with a randomly generated number.

It uses two nested loops:

* `position_x` → controls the rows.
* `position_y` → controls the columns.

For every position:

```cpp
arr[position_x][position_y] = GetRandomNumber();
```

a random number is generated and stored.

---

### `PrintMatrixArrayThatRandomNumbers()`

This function displays the complete `3×3` matrix.

It also checks whether the number is less than `10`:

```cpp
if (arr[position_x][position_y] < 10)
```

If it is, the program adds a leading zero:

```text
05
09
```

instead of:

```text
5
9
```

This makes the matrix visually consistent.

---

### `FillArrayByMiddleRowAndColumn()`

This is the main new feature of the project.

The function extracts:

* The **middle row**.
* The **middle column**.

The middle position is calculated using:

```cpp
short middleRowAndColumn = rows / 2;
```

For a `3×3` matrix:

```text
3 / 2 = 1
```

Therefore, index `1` represents the middle row and middle column.

For example:

```text
[ 12  45  78 ]
[ 23  56  89 ]
[ 34  67  91 ]
       ↑
   middle row
```

The middle row is:

```text
23  56  89
```

And the middle column is:

```text
45
56
67
```

---

### Extracting the Middle Row

The following condition identifies the middle row:

```cpp
if (position_x == middleRowAndColumn)
```

Then the values are copied into:

```cpp
MiddleRowsArrary
```

For example:

```text
MiddleRowsArrary

[23][56][89]
```

---

### Extracting the Middle Column

The following condition identifies the middle column:

```cpp
if (position_y == middleRowAndColumn)
```

Then the values are copied into:

```cpp
MiddleColumnsArrary
```

For example:

```text
MiddleColumnsArrary

[45]
[56]
[67]
```

---

### `PrintArrayElement()`

This function receives a `1D` array and prints its elements.

It also adds a leading zero for values smaller than `10`.

For example:

```text
element(1): 05
element(2): 42
element(3): 87
```

The same function is reused to print both:

* Middle row.
* Middle column.

This demonstrates **function reuse**.

---

## 🧩 Array Structure

The project uses three arrays.

### 1. Main 2D Array

```cpp
short arr[3][3];
```

Contains:

```text
[ 12  45  78 ]
[ 23  56  89 ]
[ 34  67  91 ]
```

---

### 2. Middle Row Array

```cpp
short MiddleRowsArrary[3];
```

Contains:

```text
[ 23 ][ 56 ][ 89 ]
```

---

### 3. Middle Column Array

```cpp
short MiddleColumnsArrary[3];
```

Contains:

```text
[ 45 ]
[ 56 ]
[ 67 ]
```

---

## 🎯 Middle Row & Column Concept

For a `3×3` matrix:

```text
        Column
         ↓
    0    1    2

0   12   45   78
1   23   56   89
2   34   67   91
    ↑
   Row
```

The center element is:

```text
56
```

The middle row is:

```text
23  56  89
```

The middle column is:

```text
45
56
67
```

The center element belongs to **both** the middle row and middle column.

---

## 📸 Project Output

An example output could be:

```text
Following are the random numbers:

12    45    78
23    56    89
34    67    91

Following are the middle elemnts:

element(1): 23
element(2): 56
element(3): 89


Following are the middle elemnts:

element(1): 45
element(2): 56
element(3): 67
```

> The numbers are only an example. The actual values will change when the program runs.

---

## ⚠️ Common Mistakes to Avoid

### 1. Forgetting to Initialize the Random Generator

The program uses:

```cpp
srand(time(nullptr));
```

before generating random numbers.

---

### 2. Accessing Invalid Array Positions

The `3×3` matrix has valid indexes:

```text
Rows:    0 → 2
Columns: 0 → 2
```

The middle index is:

```text
1
```

---

### 3. Confusing Row and Column

Remember:

```cpp
arr[row][column]
```

Therefore:

```cpp
position_x
```

represents the row, while:

```cpp
position_y
```

represents the column.

---

### 4. Forgetting That Indexing Starts From Zero

For a `3×3` array:

```text
Index 0 → First
Index 1 → Middle
Index 2 → Last
```

So:

```cpp
rows / 2
```

returns:

```text
3 / 2 = 1
```

which is the middle index.

---

### 5. Using the Wrong Array Size

The functions expect arrays compatible with:

```cpp
short arr[3][3]
```

and:

```cpp
short arr[3]
```

Therefore, the dimensions should match the function declarations.

---

### 6. Unnecessary `<random>` Library

The code includes:

```cpp
#include <random>
```

but does not use anything from the `<random>` library.

If the program continues using:

```cpp
rand()
srand()
```

then `<random>` can be removed.

For modern C++, however, replacing `rand()` with `<random>` would be a better future improvement.

---

## 💡 Ideas for Further Development

* [ ] Allow the user to specify the matrix dimensions.
* [ ] Allow the user to specify the minimum and maximum random values.
* [ ] Replace `rand()` with the modern C++ `<random>` library.
* [ ] Find the center element automatically.
* [ ] Calculate the sum of the middle row.
* [ ] Calculate the sum of the middle column.
* [ ] Calculate the average of the middle row.
* [ ] Calculate the average of the middle column.
* [ ] Find the largest value in the matrix.
* [ ] Find the smallest value in the matrix.
* [ ] Search for a specific number.
* [ ] Extract both diagonals.
* [ ] Calculate the sum of both diagonals.
* [ ] Add matrix transposition.
* [ ] Add a menu to regenerate the matrix.
* [ ] Allow the user to choose the matrix size.
* [ ] Build a graphical interface for the project.

---

## 📬 Contact

* **GitHub:** `abnjawher25-art`
* **Email:** `abnjawher25@gmail.com`
* **Phone:** `+967739758085`
* **LinkedIn:** [Add LinkedIn profile]
