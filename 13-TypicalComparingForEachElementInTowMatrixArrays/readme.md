# 🚀 Random 3×3 Matrix — Typical Comparison

> **Developer:** [Ebrahim Bin-Goher]
> **Project Category:** Random Number Generation, 2D Arrays & Matrix Comparison

---

## 📌 Project Objective

A C++ program that generates two separate **3×3 two-dimensional arrays**, fills both arrays with random numbers between **1 and 99**, and checks whether the corresponding elements of both arrays are exactly equal.

Unlike comparing the **sum** of two matrices, this program performs a **position-by-position comparison**.

The two matrices are considered **typical (equal)** only when every corresponding element has the same value.

This project demonstrates several fundamental C++ programming concepts:

* Two-dimensional arrays (2D Arrays).
* Functions.
* Random number generation.
* Nested loops.
* Passing arrays to functions.
* Boolean functions.
* Element-by-element comparison.
* Early `return false`.
* Conditional statements.
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

1. Initialize the random number generator.
2. Create the first `3×3` array.
3. Create the second `3×3` array.
4. Fill both arrays with random numbers.
5. Call `isTypicalComparison()`.
6. Compare every corresponding element in the two arrays.
7. If any pair of elements is different, immediately return `false`.
8. If all corresponding elements are equal, return `true`.
9. Print both matrices.
10. Call `printTypicalComparisonResult()`.
11. Display whether the two matrices are typical or untypical.

---

## 📤 Outputs

The program produces:

### 1. First Random Matrix

A `3×3` matrix containing random numbers from `1` to `99`.

### 2. Second Random Matrix

Another `3×3` matrix containing random numbers from `1` to `99`.

### 3. Comparison Result

The program checks:

```cpp
arr1[position_x][position_y] ==
arr2[position_x][position_y]
```

for every position.

If **all elements are equal**:

```text
The elements are equal (typical).
```

If **at least one element is different**:

```text
The elements are not equal (untypical).
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

// Function to compare two 2D arrays element by element
bool isTypicalComparison(
    short arr1[3][3],
    short arr2[3][3],
    short rows,
    short columns)
{
    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            if (arr1[position_x][position_y] !=
                arr2[position_x][position_y])
            {
                return false;
            }
        }
    }

    return true;
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

// Function to print the comparison result
void printTypicalComparisonResult(bool isTypical)
{
    if (isTypical == true)
    {
        cout << "\nThe elements are equal (typical)." << endl;
    }
    else
    {
        cout << "\nThe elements are not equal (untypical)." << endl;
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

    // Fill both 2D arrays with random numbers
    FillMatrixArrayByRandomNumbers(arr1, 3, 3);
    FillMatrixArrayByRandomNumbers(arr2, 3, 3);

    // Compare both arrays element by element
    bool checkValue =
        isTypicalComparison(arr1, arr2, 3, 3);

    // Print both arrays
    printMatrixArrayThatRandomNumbers(arr1, 3, 3);
    printMatrixArrayThatRandomNumbers(arr2, 3, 3);

    // Print the comparison result
    printTypicalComparisonResult(checkValue);

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

The possible range is:

```text
1 → 99
```

---

### `FillMatrixArrayByRandomNumbers()`

Fills every position in a `3×3` array with a random number.

The nested loops visit all positions:

```text
(0,0)  (0,1)  (0,2)
(1,0)  (1,1)  (1,2)
(2,0)  (2,1)  (2,2)
```

---

## ⭐ `isTypicalComparison()`

This is the core function of the project.

It compares the two matrices **element by element**.

The comparison is performed using:

```cpp
if (arr1[position_x][position_y] !=
    arr2[position_x][position_y])
```

If a difference is found:

```cpp
return false;
```

The function immediately stops checking the remaining elements.

If the function reaches the end without finding any difference:

```cpp
return true;
```

Therefore:

```text
true  → Every corresponding element is equal
false → At least one corresponding element is different
```

---

## 🧠 Why `return false` Is Inside the Loop

This is an important programming concept.

Suppose we have:

```text
Array 1:
10  20  30
40  50  60
70  80  90

Array 2:
10  20  30
40  55  60
70  80  90
```

The program reaches:

```text
Array 1 → 50
Array 2 → 55
```

Since:

```text
50 != 55
```

the function immediately executes:

```cpp
return false;
```

There is no reason to continue checking because the arrays can no longer be completely equal.

This is more efficient than checking every remaining element.

---

## 🔄 Comparison Logic

The program essentially performs:

```text
arr1[0][0] == arr2[0][0] ?
        ↓
arr1[0][1] == arr2[0][1] ?
        ↓
arr1[0][2] == arr2[0][2] ?
        ↓
arr1[1][0] == arr2[1][0] ?
        ↓
       ...
        ↓
arr1[2][2] == arr2[2][2] ?
```

If every comparison is equal:

```text
TRUE
```

If even one comparison fails:

```text
FALSE
```

---

## 🧩 Example of Typical Arrays

Two arrays are **typical/equal** when they contain the same values in the same positions.

### Array 1

```text
10   20   30
40   50   60
70   80   90
```

### Array 2

```text
10   20   30
40   50   60
70   80   90
```

Result:

```text
The elements are equal (typical).
```

---

## ❌ Example of Untypical Arrays

### Array 1

```text
10   20   30
40   50   60
70   80   90
```

### Array 2

```text
10   20   30
40   55   60
70   80   90
```

Only one element is different:

```text
50 != 55
```

Therefore:

```text
The elements are not equal (untypical).
```

---

## 🎯 Important Difference from the Previous Project

The previous project compared the **sum** of the two matrices:

```cpp
sum1 == sum2
```

This project compares the **actual elements**:

```cpp
arr1[position_x][position_y] ==
arr2[position_x][position_y]
```

This makes the current comparison much stricter.

For example:

```text
Array 1:
10  20
30  40

Array 2:
5   25
30  40
```

Both sums are:

```text
100
```

So a **sum comparison** would say they are equal.

But the matrices themselves are clearly different.

The current program correctly identifies them as:

```text
untypical
```

---

## 📸 Project Output

Because both matrices are generated randomly, they will usually contain different numbers.

Example:

```text
The 2D array is:

  12   45   78
  23   56   89
  34   67   91

The 2D array is:

  12   45   78
  23   55   89
  34   67   91

The elements are not equal (untypical).
```

> The output above is only an example. Since both matrices are randomly generated, the actual values will change every time the program runs.

---

## ⚠️ Common Mistakes to Avoid

### 1. Comparing Only the Sum

Do not use:

```cpp
sum1 == sum2
```

if the goal is to determine whether the matrices themselves are identical.

The current program compares every corresponding element.

---

### 2. Forgetting `return false`

When a different element is found, the function must immediately return:

```cpp
return false;
```

---

### 3. Forgetting `return true`

If no differences are found after checking the entire matrix:

```cpp
return true;
```

is required.

---

### 4. Confusing `!=` and `==`

The condition:

```cpp
arr1[position_x][position_y] !=
arr2[position_x][position_y]
```

means:

> If the two elements are **not equal**, the arrays are untypical.

---

### 5. Confusing `=` with `==`

```text
=   → Assignment
==  → Equality comparison
!=  → Not equal comparison
```

---

### 6. Unnecessary Variable

The function originally contained:

```cpp
short sumOfElements = 0;
```

but it is not used anywhere in `isTypicalComparison()`.

It can safely be removed.

---

### 7. Unnecessary `<random>` Library

The program includes:

```cpp
#include <random>
```

but actually uses:

```cpp
rand()
```

Therefore, `<random>` is currently unnecessary.

For a modern C++ implementation, `std::random_device`, `std::mt19937`, and `std::uniform_int_distribution` would be preferable.

---

### 8. Missing Explicit Headers

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

rather than depending on indirect header inclusion.

---

## 💡 Ideas for Further Development

* [ ] Display the first position where the matrices differ.
* [ ] Count the number of different elements.
* [ ] Count the number of equal elements.
* [ ] Compare matrices element-by-element.
* [ ] Check whether the matrices have the same dimensions.
* [ ] Compare matrices regardless of element order.
* [ ] Check whether one matrix is the transpose of the other.
* [ ] Compare the main diagonals.
* [ ] Compare the secondary diagonals.
* [ ] Calculate the percentage of matching elements.
* [ ] Highlight different elements when displaying the matrices.
* [ ] Allow the user to enter the matrices manually.
* [ ] Allow the user to choose the matrix size.
* [ ] Replace `rand()` with modern C++ `<random>`.

---

## 📬 Contact

* **GitHub:** `abnjawher25-art`
* **Email:** `abnjawher25@gmail.com`
* **Phone:** `+967739758085`
* **LinkedIn:** [Add LinkedIn profile]
