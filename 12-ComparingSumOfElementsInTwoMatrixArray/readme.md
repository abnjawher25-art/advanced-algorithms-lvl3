.

# 🚀 Random 3×3 Matrix — Comparing the Sum of Two Arrays

> **Developer:** [Ebrahim Bin-Goher]
> **Project Category:** Random Number Generation, 2D Arrays & Array Comparison

---

## 📌 Project Objective

A C++ program that generates two separate **3×3 two-dimensional arrays**, fills both arrays with random numbers between **1 and 99**, calculates the sum of the elements in each array, and compares the two sums to determine whether they are equal.

This project demonstrates several fundamental C++ programming concepts:

* Two-dimensional arrays (2D Arrays).
* Functions.
* Random number generation.
* Nested loops.
* Passing arrays to functions.
* Returning values from functions.
* Boolean functions.
* Comparing data from two arrays.
* Mathematical operations.
* Output formatting using `setw()`.

---

## 💻 Programming Languages & Technologies

* **Programming Language:** C++
* **Libraries:** `iostream`, `random`, `iomanip`
* **Functions & Features:** `rand()`, `srand()`, `time()`, `setw()`
* **Data Structures:** 2D Arrays
* **Array Size:** `3×3`
* **Random Range:** `1 → 99`

---

## 🧠 Project Algorithm

### 1. Inputs

The program does not require direct user input.

It automatically creates two `3×3` arrays:

```text
arr1[3][3]
arr2[3][3]
```

Each array contains **9 randomly generated numbers**.

---

### 2. Processing Steps

1. Initialize the random number generator using the current system time.
2. Create the first `3×3` array.
3. Create the second `3×3` array.
4. Fill the first array with random numbers.
5. Fill the second array with random numbers.
6. Calculate the sum of all elements in the first array.
7. Calculate the sum of all elements in the second array.
8. Print the first matrix.
9. Print the second matrix.
10. Display the sum of the first matrix.
11. Display the sum of the second matrix.
12. Compare both sums.
13. Display whether the sums are equal or not.

---

## 📤 Outputs

The program produces:

### 1. First Random Matrix

A `3×3` matrix containing random numbers from `1` to `99`.

### 2. Second Random Matrix

Another independent `3×3` matrix containing random numbers from `1` to `99`.

### 3. Sum of the First Matrix

The total of all 9 elements in `arr1`.

### 4. Sum of the Second Matrix

The total of all 9 elements in `arr2`.

### 5. Comparison Result

The program determines whether:

```text
sum1 == sum2
```

If they are equal:

```text
The sum of elements in both matrix arrays is equal.
```

Otherwise:

```text
The sum of elements in both matrix arrays is not equal.
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
    cout << "\nThe 2D array is:\n" << endl;

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            cout << setw(4)
                 << arr[position_x][position_y]
                 << " ";
        }

        cout << endl;
    }
}

// Function to check if the sum of elements
// in two 2D arrays is equal
bool isSumOfElementsInMatrixArrayEqual(
    short arr1[3][3],
    short arr2[3][3],
    short rows,
    short columns)
{
    // Get the sum of elements in both arrays
    short sum1 =
        FindSumOfElementsInMatrixArray(arr1, rows, columns);

    short sum2 =
        FindSumOfElementsInMatrixArray(arr2, rows, columns);

    // Compare the sums
    return sum1 == sum2;
}

// Function to print the comparison result
// of two 2D arrays
void printComparisonResult(
    short arr1[3][3],
    short arr2[3][3],
    short rows,
    short columns)
{
    // Check if the sums of elements
    // in both arrays are equal
    if (isSumOfElementsInMatrixArrayEqual(
            arr1, arr2, rows, columns))
    {
        cout << "\nThe sum of elements in both matrix arrays is equal."
             << endl;
    }
    else
    {
        cout << "\nThe sum of elements in both matrix arrays is not equal."
             << endl;
    }
}

// Main function
int main()
{
    // Seed the random number generator
    // with the current system time
    srand(time(nullptr));

    short arr1[3][3];
    short arr2[3][3];

    // Fill the 2D arrays with random numbers
    FillMatrixArrayByRandomNumbers(arr1, 3, 3);
    FillMatrixArrayByRandomNumbers(arr2, 3, 3);

    // Calculate the sum of elements
    // in both arrays
    short sum1 =
        FindSumOfElementsInMatrixArray(arr1, 3, 3);

    short sum2 =
        FindSumOfElementsInMatrixArray(arr2, 3, 3);

    // Print both arrays
    printMatrixArrayThatRandomNumbers(arr1, 3, 3);
    printMatrixArrayThatRandomNumbers(arr2, 3, 3);

    // Print the sum of elements
    // in both arrays
    cout << "\nthe sum of elements in the first matrix array is: "
         << sum1 << endl;

    cout << "\nthe sum of elements in the second matrix array is: "
         << sum2 << endl;

    // Print the comparison result
    printComparisonResult(arr1, arr2, 3, 3);

    // Return 0 to indicate successful execution
    return 0;
}
```

---

## 🔍 Code Explanation

### `GetRandomNumber()`

Generates a random number between `1` and `99`.

```cpp
return rand() % (to - from + 1) + from;
```

The generated value is within:

```text
1 → 99
```

---

### `FillMatrixArrayByRandomNumbers()`

Fills every element of a `3×3` matrix with a random number.

The nested loops visit all 9 positions:

```text
(0,0) (0,1) (0,2)
(1,0) (1,1) (1,2)
(2,0) (2,1) (2,2)
```

---

### `FindSumOfElementsInMatrixArray()`

Calculates the total sum of all elements inside a matrix.

It starts with:

```cpp
short sumOfElements = 0;
```

Then accumulates every element:

```cpp
sumOfElements += arr[position_x][position_y];
```

Finally:

```cpp
return sumOfElements;
```

returns the calculated sum.

---

### `printMatrixArrayThatRandomNumbers()`

Displays a complete `3×3` matrix.

The statement:

```cpp
setw(4)
```

provides consistent spacing between the numbers.

Example:

```text
  12   45   78
  23   56   89
  34   67   91
```

---

### `isSumOfElementsInMatrixArrayEqual()`

This function is responsible for the actual comparison.

First, it calculates the sum of the first matrix:

```cpp
short sum1 =
    FindSumOfElementsInMatrixArray(arr1, rows, columns);
```

Then it calculates the sum of the second matrix:

```cpp
short sum2 =
    FindSumOfElementsInMatrixArray(arr2, rows, columns);
```

Finally, it compares them:

```cpp
return sum1 == sum2;
```

The result is a Boolean value:

```text
true  → sums are equal
false → sums are different
```

---

## 🔄 Boolean Comparison

The key expression in the project is:

```cpp
sum1 == sum2
```

It produces one of two results:

```text
true
false
```

For example:

```text
sum1 = 450
sum2 = 450

450 == 450
       ↓
      true
```

But:

```text
sum1 = 450
sum2 = 510

450 == 510
       ↓
      false
```

---

## 🧩 `printComparisonResult()`

This function takes the Boolean result and converts it into a readable message.

```cpp
if (isSumOfElementsInMatrixArrayEqual(...))
```

If the function returns `true`:

```text
The sum of elements in both matrix arrays is equal.
```

Otherwise:

```text
The sum of elements in both matrix arrays is not equal.
```

This separates the **comparison logic** from the **display logic**, making the program more organized.

---

## 🔢 Example

Suppose the first matrix is:

```text
10   20   30
40   50   60
70   80   90
```

Its sum:

```text
450
```

And the second matrix is:

```text
10   20   30
40   50   60
70   80   90
```

Its sum:

```text
450
```

The comparison becomes:

```text
450 == 450
```

Therefore:

```text
The sum of elements in both matrix arrays is equal.
```

---

## 📸 Project Output

An example output could be:

```text
The 2D array is:

  12   45   78
  23   56   89
  34   67   91

The 2D array is:

  15   42   73
  21   61   88
  39   64   95

the sum of elements in the first matrix array is: 485

the sum of elements in the second matrix array is: 498

The sum of elements in both matrix arrays is not equal.
```

> The numbers are only an example. Because the program generates random numbers, the matrices and sums will normally change on every execution.

---

## ⚠️ Common Mistakes to Avoid

### 1. Comparing the Arrays Instead of Their Sums

The goal of this program is to compare:

```cpp
sum1 == sum2
```

not the memory addresses or the arrays directly.

---

### 2. Forgetting to Return the Boolean Result

The comparison function must return:

```cpp
return sum1 == sum2;
```

This returns either `true` or `false`.

---

### 3. Confusing `=` with `==`

Remember:

```cpp
=   → Assignment
==  → Comparison
```

Correct:

```cpp
sum1 == sum2
```

---

### 4. Calculating Only One Matrix Sum

Both matrices need to be processed:

```cpp
sum1 = FindSumOfElementsInMatrixArray(arr1, 3, 3);
sum2 = FindSumOfElementsInMatrixArray(arr2, 3, 3);
```

---

### 5. Accessing Invalid Array Positions

For both `3×3` matrices:

```text
Rows:    0 → 2
Columns: 0 → 2
```

---

### 6. Unnecessary `<random>` Library

The program includes:

```cpp
#include <random>
```

but uses:

```cpp
rand()
```

instead of the modern `<random>` facilities.

Therefore, `<random>` is currently unnecessary.

---

### 7. Missing Explicit Headers

Because the program uses:

```cpp
rand()
srand()
time()
```

it is better practice to explicitly include:

```cpp
#include <cstdlib>
#include <ctime>
```

rather than relying on indirect inclusion through other headers.

---

## 💡 Ideas for Further Development

* [ ] Compare the two matrices element-by-element.
* [ ] Check whether the two matrices are completely identical.
* [ ] Calculate the difference between the two sums.
* [ ] Find which matrix has the larger sum.
* [ ] Find the largest element in each matrix.
* [ ] Find the smallest element in each matrix.
* [ ] Calculate the average of each matrix.
* [ ] Calculate the sum of each row.
* [ ] Calculate the sum of each column.
* [ ] Compare corresponding rows between the matrices.
* [ ] Compare corresponding columns between the matrices.
* [ ] Count equal elements at the same positions.
* [ ] Allow the user to choose the matrix size.
* [ ] Allow the user to specify the random-number range.
* [ ] Replace `rand()` with modern C++ `<random>`.
* [ ] Add a menu for multiple matrix comparison operations.

---

## 📬 Contact

* **GitHub:** `abnjawher25-art`
* **Email:** `abnjawher25@gmail.com`
* **Phone:** `+967739758085`
* **LinkedIn:** [Add LinkedIn profile]
