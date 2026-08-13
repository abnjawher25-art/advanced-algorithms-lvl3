# 🚀 Random 3×3 Matrix — Sum of All Elements

> **Developer:** [Ebrahim Bin-Goher]
> **Project Category:** Random Number Generation, 2D Arrays & Mathematical Operations

---

## 📌 Project Objective

A C++ program that generates random numbers between **1 and 99**, stores them in a **3×3 two-dimensional array**, displays the generated matrix, and calculates the **sum of all elements** inside the matrix.

This project demonstrates several fundamental C++ programming concepts:

* Two-dimensional arrays (2D Arrays).
* Functions.
* Random number generation.
* Nested loops.
* Passing arrays to functions.
* Accumulating values.
* Returning values from functions.
* Mathematical operations.
* Output formatting using `setw()`.

---

## 💻 Programming Languages & Technologies

* **Programming Language:** C++
* **Libraries:** `iostream`, `random`, `iomanip`
* **Functions & Features:** `rand()`, `srand()`, `time()`, `setw()`
* **Data Structures:** 2D Array
* **Matrix Size:** `3×3`

---

## 🧠 Project Algorithm

### 1. Inputs

The program does not require direct user input.

It automatically creates a `3×3` array containing **9 elements**.

---

### 2. Processing Steps

1. Initialize the random number generator using the current system time.
2. Create a `3×3` two-dimensional array.
3. Call `FillMatrixArrayByRandomNumbers()`.
4. Generate random numbers between `1` and `99`.
5. Store each generated number inside the matrix.
6. Call `printMatrixArrayThatRandomNumbers()`.
7. Display the complete `3×3` matrix.
8. Call `FindSumOfElementsInMatrixArray()`.
9. Traverse all rows and columns using nested `for` loops.
10. Add every matrix element to `sumOfElements`.
11. Return the final sum.
12. Display the total sum of all matrix elements.

---

## 📤 Outputs

The program produces two main outputs:

### 1. Random 3×3 Matrix

A matrix containing **9 random numbers**, where every number is between **1 and 99**.

### 2. Sum of All Elements

The program calculates the total of all 9 elements.

For example:

```text
10  20  30
40  50  60
70  80  90
```

The sum is:

```text
450
```

---

## 📝 Project Code

```cpp
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// function to generate random numbers between 1 and 99
short GetRandomNumber()
{
    // define the range for random numbers
    const short from = 1;
    const short to = 99;

    // Generate a random number between 'from' and 'to' (inclusive)
    return rand() % (to - from + 1) + from;
}

// function to fill a 2D array with random numbers
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

// Function to get sum of all elements in a 2D array
short FindSumOfElementsInMatrixArray(
    short arr[3][3],
    short rows,
    short columns)
{
    short sumOfElements = 0;

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            sumOfElements += arr[position_x][position_y];
        }
    }

    return sumOfElements;
}

// Function to print a 2D array
void printMatrixArrayThatRandomNumbers(
    short arr[3][3],
    short rows,
    short columns)
{
    // Print the 2D array
    cout << "The 2D array is:\n" << endl;

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            cout << setw(4) << arr[position_x][position_y] << " ";
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

    // Fill the 2D array with random numbers
    FillMatrixArrayByRandomNumbers(arr, 3, 3);

    // Print the 2D array
    printMatrixArrayThatRandomNumbers(arr, 3, 3);

    // Find the sum of all elements in the matrix
    short sumOfElements =
        FindSumOfElementsInMatrixArray(arr, 3, 3);

    // Print the sum of all elements
    cout << "\n\nThe sum of all elements in the matrix array is: "
         << sumOfElements << endl;

    // Return 0 to indicate successful execution
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

The result will always be within:

```text
1 → 99
```

---

### `FillMatrixArrayByRandomNumbers()`

This function fills every element of the `3×3` matrix with a random number.

It uses two nested loops:

```cpp
for (short position_x = 0; position_x < rows; position_x++)
```

The outer loop controls the **rows**.

```cpp
for (short position_y = 0; position_y < columns; position_y++)
```

The inner loop controls the **columns**.

Together, they visit all 9 elements.

---

### `FindSumOfElementsInMatrixArray()`

This is the main mathematical function of the project.

It starts with:

```cpp
short sumOfElements = 0;
```

Then every matrix element is added:

```cpp
sumOfElements += arr[position_x][position_y];
```

After processing all elements, the function returns the total:

```cpp
return sumOfElements;
```

---

### Example of the Calculation

If the matrix is:

```text
10   20   30
40   50   60
70   80   90
```

The function calculates:

```text
10 + 20 + 30
+ 40 + 50 + 60
+ 70 + 80 + 90
```

Result:

```text
450
```

---

### `printMatrixArrayThatRandomNumbers()`

This function displays the complete matrix.

The following statement:

```cpp
cout << setw(4) << arr[position_x][position_y] << " ";
```

uses:

```cpp
setw(4)
```

to give each number a fixed output width, making the matrix more organized and readable.

---

### `main()`

The `main()` function controls the entire program.

It performs the following operations:

```text
1. Seed random generator
        ↓
2. Create 3×3 array
        ↓
3. Fill array with random numbers
        ↓
4. Print array
        ↓
5. Calculate sum
        ↓
6. Print total sum
```

---

## 🧩 Matrix Structure

The program creates:

```cpp
short arr[3][3];
```

This means:

* **3 rows**
* **3 columns**
* **9 total elements**

Example:

```text
        Column
       0    1    2

Row 0  12   45   78
Row 1  23   56   89
Row 2  34   67   91
```

The sum is:

```text
12 + 45 + 78 +
23 + 56 + 89 +
34 + 67 + 91
```

```text
= 485
```

---

## 📊 Time Complexity

The program traverses every element of the `3×3` matrix.

For a matrix with:

* `rows`
* `columns`

the algorithm performs approximately:

```text
rows × columns
```

operations.

Therefore, the time complexity is:

```text
O(rows × columns)
```

For this specific project:

```text
O(3 × 3) = O(9)
```

---

## 📸 Project Output

An example output could be:

```text
The 2D array is:

  12   45   78
  23   56   89
  34   67   91


The sum of all elements in the matrix array is: 485
```

> The numbers are only an example. The actual matrix and sum will normally change each time the program runs.

---

## ⚠️ Common Mistakes to Avoid

### 1. Forgetting to Seed the Random Generator

The program uses:

```cpp
srand(time(nullptr));
```

before generating random numbers.

---

### 2. Incorrect Sum Initialization

The accumulator should start from zero:

```cpp
short sumOfElements = 0;
```

Otherwise, the calculation may start with an unintended value.

---

### 3. Forgetting to Return the Sum

The function must return the calculated value:

```cpp
return sumOfElements;
```

Without `return`, the result cannot be received by `main()`.

---

### 4. Accessing Invalid Array Positions

For a `3×3` matrix, valid indexes are:

```text
Rows:    0 → 2
Columns: 0 → 2
```

Accessing an index such as:

```cpp
arr[3][3]
```

is invalid and can cause undefined behavior.

---

### 5. Confusing Rows and Columns

Remember:

```cpp
arr[row][column]
```

In this project:

```text
position_x → row
position_y → column
```

---

### 6. Unnecessary `<random>` Library

The code includes:

```cpp
#include <random>
```

but does not actually use the modern C++ random-number facilities.

If the program continues using:

```cpp
rand()
```

then `<random>` is unnecessary.

A future improvement would be replacing `rand()` with modern C++ `<random>` facilities.

---

### 7. Possible Integer Range Limitation

The function returns a `short`:

```cpp
short FindSumOfElementsInMatrixArray(...)
```

For the current `3×3` matrix with values from `1` to `99`, the maximum possible sum is:

```text
99 × 9 = 891
```

so `short` is more than sufficient here.

If the matrix becomes much larger or the random-number range increases significantly, using `int` would be safer.

---

## 💡 Ideas for Further Development

* [ ] Calculate the sum of each row separately.
* [ ] Calculate the sum of each column separately.
* [ ] Find the largest element.
* [ ] Find the smallest element.
* [ ] Calculate the average of all elements.
* [ ] Count even and odd numbers.
* [ ] Count positive and negative numbers.
* [ ] Search for a specific number.
* [ ] Find the middle element.
* [ ] Calculate the sum of the main diagonal.
* [ ] Calculate the sum of the secondary diagonal.
* [ ] Compare the sums of rows and columns.
* [ ] Allow the user to choose the matrix size.
* [ ] Allow the user to define the random-number range.
* [ ] Replace `rand()` with modern C++ `<random>`.
* [ ] Add a menu to perform different matrix operations.

---

## 📬 Contact

* **GitHub:** `abnjawher25-art`
* **Email:** `abnjawher25@gmail.com`
* **Phone:** `+967739758085`
* **LinkedIn:** [Add LinkedIn profile]
