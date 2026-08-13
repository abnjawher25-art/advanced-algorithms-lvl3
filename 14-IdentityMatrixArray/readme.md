# 🚀 Random 3×3 Matrix — Identity Matrix Checker

> **Developer:** [Ebrahim Bin-Goher]
> **Project Category:** 2D Arrays, Matrix Validation & Identity Matrix

---

## 📌 Project Objective

A C++ program that generates a random `3×3` two-dimensional array and checks whether the generated matrix is an **Identity Matrix**.

An Identity Matrix follows two rules:

* Every element on the **main diagonal** must be `1`.
* Every element outside the **main diagonal** must be `0`.

For a `3×3` matrix, the Identity Matrix has the following form:

```text
1  0  0
0  1  0
0  0  1
```

The program examines every element of the matrix and determines whether it satisfies these two conditions.

This project demonstrates several fundamental C++ programming concepts:

* Two-dimensional arrays (2D Arrays).
* Functions.
* Random number generation.
* Nested loops.
* Passing arrays to functions.
* Boolean functions.
* Matrix validation.
* Main diagonal identification.
* Conditional statements.
* Early `return false`.
* Formatted output using `printf()`.

---

## 💻 Programming Languages & Technologies

* **Programming Language:** C++
* **Libraries:** `iostream`, `random`, `iomanip`
* **Functions & Features:** `rand()`, `srand()`, `time()`, `printf()`
* **Data Structures:** 2D Array
* **Matrix Size:** `3×3`
* **Random Range:** `0 → 99`

---

## 🧠 Project Algorithm

### 1. Inputs

The program does not require direct user input.

It automatically creates one:

```cpp
short arr[3][3];
```

The matrix contains:

```text
3 rows
3 columns
9 elements
```

---

### 2. Processing Steps

1. Initialize the random number generator using the current system time.
2. Create a `3×3` two-dimensional array.
3. Fill every element with a random number.
4. Call `isIdentityMatrixArray()`.
5. Traverse every element using nested loops.
6. Check whether the current position belongs to the main diagonal.
7. If it is on the diagonal, verify that its value is `1`.
8. If it is outside the diagonal, verify that its value is `0`.
9. If any condition fails, return `false`.
10. If all elements satisfy the Identity Matrix rules, return `true`.
11. Print the matrix.
12. Print the validation result.

---

## 📤 Outputs

The program produces two main outputs:

### 1. Generated Matrix

A `3×3` matrix containing randomly generated numbers.

### 2. Identity Matrix Result

The program determines whether the matrix is an Identity Matrix.

If valid:

```text
The matrix array is Identity.
```

If invalid:

```text
The matrix array is not Identity.
```

---

## 📝 Project Code

```cpp
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

    // Generate a random number between 'from' and 'to'
    return rand() % (to - from + 1);
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
            arr[position_x][position_y] =
                GetRandomNumber();
        }
    }
}

// Function to check if a 2D array is an Identity Matrix
bool isIdentityMatrixArray(
    short arr[3][3],
    short rows,
    short columns)
{
    for (short position_x = 0;
         position_x < rows;
         position_x++)
    {
        for (short position_y = 0;
             position_y < columns;
             position_y++)
        {
            // Check main diagonal elements
            if ((position_x == position_y) &&
                (arr[position_x][position_y] != 1))
            {
                return false;
            }

            // Check elements outside the main diagonal
            if ((position_x != position_y) &&
                (arr[position_x][position_y] != 0))
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

// Function to print the Identity Matrix result
void printIdentityMatrixArrayResult(bool isIdentity)
{
    if (isIdentity == true)
    {
        cout << "\nThe matrix array is Identity."
             << endl;
    }
    else
    {
        cout << "\nThe matrix array is not Identity."
             << endl;
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

    // Check if the matrix is an Identity Matrix
    bool checkValue =
        isIdentityMatrixArray(arr, 3, 3);

    // Print the matrix
    printMatrixArrayThatRandomNumbers(arr, 3, 3);

    // Print the Identity Matrix result
    printIdentityMatrixArrayResult(checkValue);

    // Return 0 to indicate successful execution
    return 0;
}
```

---

## 🔍 Code Explanation

### `GetRandomNumber()`

This function generates random numbers.

The defined range is:

```cpp
const short from = 1;
const short to = 100;
```

However, the actual expression is:

```cpp
return rand() % (to - from + 1);
```

which produces values from:

```text
0 → 100
```

⚠️ **Important:** The comment says `1 → 100`, but the current implementation does **not** actually generate that range.

If the intended range is `1 → 100`, the correct expression is:

```cpp
return rand() % (to - from + 1) + from;
```

This is an important correction to make in the project.

---

## ⭐ `isIdentityMatrixArray()`

This is the core function of the project.

It checks every element according to its position.

The main diagonal is identified using:

```cpp
position_x == position_y
```

For a `3×3` matrix, the main diagonal positions are:

```text
(0,0)
(1,1)
(2,2)
```

These positions must contain:

```text
1
```

---

## 🔵 Main Diagonal

For example:

```text
1  0  0
0  1  0
0  0  1
```

The diagonal elements are:

```text
1
   1
      1
```

The program identifies them with:

```cpp
if (position_x == position_y)
```

Then checks:

```cpp
arr[position_x][position_y] != 1
```

If the diagonal element is not `1`:

```cpp
return false;
```

---

## ⚪ Elements Outside the Diagonal

Every element that is **not** on the main diagonal must be `0`.

The program identifies these elements using:

```cpp
position_x != position_y
```

Then checks:

```cpp
arr[position_x][position_y] != 0
```

If an outside-diagonal element is not `0`:

```cpp
return false;
```

---

## 🧩 Identity Matrix Structure

A valid `3×3` Identity Matrix looks like:

```text
1  0  0
0  1  0
0  0  1
```

Positionally:

```text
(0,0) → 1
(0,1) → 0
(0,2) → 0

(1,0) → 0
(1,1) → 1
(1,2) → 0

(2,0) → 0
(2,1) → 0
(2,2) → 1
```

---

## 🧠 The Core Logic

The function essentially implements:

```text
             Is position on diagonal?
                    /       \
                  Yes        No
                   ↓          ↓
             Value == 1?   Value == 0?
                /   \         /   \
              Yes   No      Yes   No
               ↓     ↓        ↓     ↓
            Continue False  Continue False
```

If all 9 elements pass their conditions:

```cpp
return true;
```

Therefore:

```text
true  → Identity Matrix
false → Not an Identity Matrix
```

---

## 📊 Example 1 — Identity Matrix

Suppose the matrix is:

```text
1  0  0
0  1  0
0  0  1
```

All diagonal elements are `1`.

All other elements are `0`.

Therefore:

```text
The matrix array is Identity.
```

---

## ❌ Example 2 — Not an Identity Matrix

Suppose the matrix is:

```text
1  0  0
0  5  0
0  0  1
```

The center element should be:

```text
1
```

but it is:

```text
5
```

Therefore:

```text
The matrix array is not Identity.
```

---

## ❌ Example 3 — Not an Identity Matrix

```text
1  0  7
0  1  0
0  0  1
```

The element:

```text
arr[0][2] = 7
```

is outside the main diagonal.

It must be:

```text
0
```

Therefore the matrix is not an Identity Matrix.

---

## 📸 Project Output

Because the program generates random values, a typical execution will almost always produce a matrix that is **not** an Identity Matrix.

Example:

```text
The 2D array is:

  12   45   78
  23   56   89
  34   67   91

The matrix array is not Identity.
```

A valid Identity Matrix would produce:

```text
The 2D array is:

  01   00   00
  00   01   00
  00   00   01

The matrix array is Identity.
```

> Since the matrix is randomly generated, getting an Identity Matrix naturally is extremely unlikely.

---

## 🎯 Important Observation

There is a logical mismatch between the **random generation** and the **Identity Matrix test**.

The program generates arbitrary random values from roughly `0` to `100`, then asks:

> "Is this matrix an Identity Matrix?"

Since an Identity Matrix requires **six zeros and three ones**, the probability of randomly generating one is extremely tiny.

If the random generator produces values from `0 → 100`, the approximate probability is:

```text
(1 / 101)^9
```

which is effectively negligible.

So the current program is excellent for **learning how to detect an Identity Matrix**, but not for generating Identity Matrices.

---

## ⚠️ Common Mistakes to Avoid

### 1. Incorrect Random Number Range

The current code:

```cpp
return rand() % (to - from + 1);
```

does not add `from`.

For a true `1 → 100` range:

```cpp
return rand() % (to - from + 1) + from;
```

---

### 2. Confusing Main Diagonal with Secondary Diagonal

The main diagonal uses:

```cpp
position_x == position_y
```

Example:

```text
1  0  0
0  1  0
0  0  1
```

The secondary diagonal would use:

```cpp
position_x + position_y == columns - 1
```

Example:

```text
0  0  1
0  1  0
1  0  0
```

These are different concepts.

---

### 3. Forgetting the Two Identity Rules

A matrix is an Identity Matrix only if:

```text
Main diagonal     → 1
Other elements    → 0
```

Checking only the diagonal is not enough.

---

### 4. Using `=` Instead of `==`

Correct:

```cpp
position_x == position_y
```

Not:

```cpp
position_x = position_y
```

Remember:

```text
=   → Assignment
==  → Comparison
!=  → Not equal
```

---

### 5. Unnecessary Variable

The original function does not need:

```cpp
short sumOfElements = 0;
```

because the function does not calculate a sum.

It can be removed.

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

instead.

Therefore, `<random>` is currently unnecessary.

---

### 7. Missing Explicit Headers

Since the program uses:

```cpp
rand()
srand()
time()
printf()
```

better practice is to explicitly include:

```cpp
#include <cstdlib>
#include <ctime>
#include <cstdio>
```

rather than relying on indirect inclusion.

---

## 💡 Ideas for Further Development

* [ ] Generate an Identity Matrix directly.
* [ ] Ask the user to enter a matrix and check whether it is an Identity Matrix.
* [ ] Compare two matrices to determine whether both are Identity Matrices.
* [ ] Check matrices of different sizes.
* [ ] Check whether a matrix is diagonal.
* [ ] Check whether a matrix is scalar.
* [ ] Check whether a matrix is symmetric.
* [ ] Check whether a matrix is upper triangular.
* [ ] Check whether a matrix is lower triangular.
* [ ] Check whether a matrix is sparse.
* [ ] Detect and display the first invalid element.
* [ ] Count the number of invalid elements.
* [ ] Replace `rand()` with modern C++ `<random>`.
* [ ] Allow the user to choose the matrix dimensions.

---

## 📬 Contact

* **GitHub:** `abnjawher25-art`
* **Email:** `abnjawher25@gmail.com`
* **Phone:** `+967739758085`
* **LinkedIn:** [Add LinkedIn profile]
