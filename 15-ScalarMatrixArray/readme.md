# 🚀 Random 3×3 Matrix — Scalar Matrix Checker

> **Developer:** [Ebrahim Bin-Goher]
> **Project Category:** 2D Arrays, Matrix Validation & Scalar Matrix

---

## 📌 Project Objective

A C++ program that generates a random `3×3` two-dimensional array and checks whether the generated matrix is a **Scalar Matrix**.

A Scalar Matrix is a special type of diagonal matrix where:

* All elements outside the **main diagonal** must be `0`.
* All elements on the **main diagonal** must have the **same value**.

For example:

```text
5  0  0
0  5  0
0  0  5
```

The value `5` is the scalar value of the matrix.

This project demonstrates several fundamental C++ programming concepts:

* Two-dimensional arrays (2D Arrays).
* Functions.
* Random number generation.
* Nested loops.
* Passing arrays to functions.
* Boolean functions.
* Matrix validation.
* Main diagonal identification.
* Scalar matrix detection.
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
* **Random Value Range:** Intended `1 → 100`

---

## 🧠 Project Algorithm

### 1. Inputs

The program does not require direct user input.

It automatically creates:

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
2. Create a `3×3` matrix.
3. Fill the matrix with random numbers.
4. Store the first element `arr[0][0]` as the reference diagonal value.
5. Call `isIScalarMatrixArray()`.
6. Traverse all rows and columns using nested loops.
7. For every main diagonal element, compare it with the first element.
8. For every element outside the main diagonal, check that its value is `0`.
9. If any condition fails, return `false`.
10. If all conditions pass, return `true`.
11. Print the matrix.
12. Print whether the matrix is Scalar or not Scalar.

---

## 📤 Outputs

The program produces:

### 1. Generated Matrix

A `3×3` matrix containing randomly generated numbers.

### 2. Scalar Matrix Result

If the matrix satisfies the Scalar Matrix rules:

```text
The matrix array is Scalar.
```

Otherwise:

```text
The matrix array is not Scalar.
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

// Function to check if a matrix is Scalar
bool isIScalarMatrixArray(
    short arr[3][3],
    short rows,
    short columns)
{
    // Store the first diagonal element
    // as the reference value
    short FirstElement = arr[0][0];

    for (short position_x = 0;
         position_x < rows;
         position_x++)
    {
        for (short position_y = 0;
             position_y < columns;
             position_y++)
        {
            // Check diagonal elements
            if ((position_x == position_y) &&
                (arr[position_x][position_y] != FirstElement))
            {
                return false;
            }

            // Check elements outside the diagonal
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

// Function to print the Scalar Matrix result
void printcalarMatrixArrayResult(bool isScalar)
{
    if (isScalar == true)
    {
        cout << "\nThe matrix array is Scalar."
             << endl;
    }
    else
    {
        cout << "\nThe matrix array is not Scalar."
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

    // Check if the matrix is Scalar
    bool checkValue =
        isIScalarMatrixArray(arr, 3, 3);

    // Print the matrix
    printMatrixArrayThatRandomNumbers(arr, 3, 3);

    // Print the check result
    printcalarMatrixArrayResult(checkValue);

    // Return 0 to indicate successful execution
    return 0;
}
```

---

## 🔍 Code Explanation

### `GetRandomNumber()`

This function generates a random number.

The intended range is:

```text
1 → 100
```

However, the current return statement:

```cpp
return rand() % (to - from + 1);
```

actually produces:

```text
0 → 100
```

because `from` is not added to the result.

If the intended range is truly `1 → 100`, it should be:

```cpp
return rand() % (to - from + 1) + from;
```

---

## ⭐ `isIScalarMatrixArray()`

This is the core function of the project.

The function first stores:

```cpp
short FirstElement = arr[0][0];
```

This value becomes the **reference value** for all elements on the main diagonal.

For example:

```text
7  0  0
0  7  0
0  0  7
```

The first diagonal element is:

```text
7
```

Therefore, every other diagonal element must also be `7`.

---

## 🔵 Main Diagonal Rule

The main diagonal is identified by:

```cpp
position_x == position_y
```

For a `3×3` matrix:

```text
(0,0)
(1,1)
(2,2)
```

These elements must all equal:

```cpp
FirstElement
```

The program checks this with:

```cpp
if ((position_x == position_y) &&
    (arr[position_x][position_y] != FirstElement))
{
    return false;
}
```

If any diagonal element is different, the matrix is immediately rejected.

---

## ⚪ Outside the Main Diagonal

Every element outside the main diagonal must be:

```text
0
```

The program identifies these positions using:

```cpp
position_x != position_y
```

and checks:

```cpp
arr[position_x][position_y] != 0
```

If any outside-diagonal element is not zero:

```cpp
return false;
```

---

## 🧩 Structure of a Scalar Matrix

A valid `3×3` Scalar Matrix looks like:

```text
5  0  0
0  5  0
0  0  5
```

Another valid example:

```text
10  0   0
0  10   0
0   0  10
```

The scalar value can be any non-zero or zero value, as long as:

1. The diagonal elements are identical.
2. All non-diagonal elements are zero.

---

## 🆚 Scalar Matrix vs Identity Matrix

This project is closely related to the previous **Identity Matrix** project.

### Identity Matrix

The diagonal must specifically contain `1`:

```text
1  0  0
0  1  0
0  0  1
```

### Scalar Matrix

The diagonal elements only need to be equal:

```text
7  0  0
0  7  0
0  0  7
```

Therefore:

> **Every Identity Matrix is a Scalar Matrix, but not every Scalar Matrix is an Identity Matrix.**

For example:

```text
5  0  0
0  5  0
0  0  5
```

is Scalar but **not** Identity.

---

## 🧠 Core Logic

The algorithm can be summarized as:

```text
             Start
               ↓
       Get arr[0][0]
               ↓
       Check every element
               ↓
       ┌──── Is diagonal? ────┐
       ↓                       ↓
      Yes                      No
       ↓                       ↓
  Must equal               Must equal
  FirstElement                  0
       ↓                       ↓
    Valid?                   Valid?
       ↓                       ↓
      No → false             No → false
       ↓
   Continue
       ↓
 All elements valid
       ↓
     true
```

---

## 📊 Example 1 — Scalar Matrix

```text
5  0  0
0  5  0
0  0  5
```

Diagonal:

```text
5  5  5
```

All equal.

Outside diagonal:

```text
0  0  0  0  0  0
```

All zero.

Result:

```text
The matrix array is Scalar.
```

---

## ❌ Example 2 — Not Scalar

```text
5  0  0
0  7  0
0  0  5
```

The diagonal is:

```text
5  7  5
```

The values are not equal.

Therefore:

```text
The matrix array is not Scalar.
```

---

## ❌ Example 3 — Not Scalar

```text
5  0  3
0  5  0
0  0  5
```

The diagonal is correct:

```text
5  5  5
```

But:

```text
arr[0][2] = 3
```

is outside the diagonal and must be `0`.

Therefore:

```text
The matrix array is not Scalar.
```

---

## 📸 Project Output

Because the matrix is randomly generated, a typical execution will almost always produce a matrix that is **not Scalar**.

Example:

```text
The 2D array is:

  12   45   78
  23   56   89
  34   67   91

The matrix array is not Scalar.
```

A valid Scalar Matrix would look like:

```text
The 2D array is:

  05   00   00
  00   05   00
  00   00   05

The matrix array is Scalar.
```

> With completely random values, generating a Scalar Matrix naturally is extremely unlikely because six specific positions must be `0` and three diagonal positions must contain exactly the same value.

---

## ⚠️ Common Mistakes to Avoid

### 1. Forgetting the First Element

The program uses:

```cpp
short FirstElement = arr[0][0];
```

as the reference value.

Every diagonal element must match it.

---

### 2. Checking Only the Diagonal

A matrix is not Scalar simply because its diagonal elements are equal.

For example:

```text
5  3  0
0  5  0
0  0  5
```

has equal diagonal elements, but it is **not Scalar** because `3` is outside the diagonal.

---

### 3. Confusing Scalar with Identity

Scalar:

```text
7  0  0
0  7  0
0  0  7
```

Identity:

```text
1  0  0
0  1  0
0  0  1
```

The Scalar Matrix does not require the diagonal to be `1`.

---

### 4. Incorrect Random Number Range

The current expression:

```cpp
return rand() % (to - from + 1);
```

does not use `from`.

For `1 → 100`, use:

```cpp
return rand() % (to - from + 1) + from;
```

---

### 5. Unnecessary `<random>` Library

The code includes:

```cpp
#include <random>
```

but uses:

```cpp
rand()
```

instead of the modern `<random>` facilities.

---

### 6. Unused Parameter Relationship

The function receives both:

```cpp
short rows,
short columns
```

but the scalar condition assumes a square matrix because it relies on the main diagonal.

A true Scalar Matrix must be a **square matrix**.

---

### 7. Function Naming

The current function:

```cpp
isIScalarMatrixArray()
```

contains an extra `I`.

A cleaner name would be:

```cpp
isScalarMatrixArray()
```

Similarly:

```cpp
printcalarMatrixArrayResult()
```

would be clearer as:

```cpp
printScalarMatrixArrayResult()
```

---

## 💡 Ideas for Further Development

* [ ] Generate a Scalar Matrix directly.
* [ ] Allow the user to enter a matrix manually.
* [ ] Check whether the matrix is Identity.
* [ ] Check whether the matrix is Diagonal.
* [ ] Check whether the matrix is Symmetric.
* [ ] Check whether the matrix is Upper Triangular.
* [ ] Check whether the matrix is Lower Triangular.
* [ ] Check whether the matrix is Sparse.
* [ ] Display the scalar value when the matrix is valid.
* [ ] Detect the first invalid element.
* [ ] Count invalid elements.
* [ ] Allow different matrix sizes.
* [ ] Replace `rand()` with modern C++ `<random>`.
* [ ] Build a menu for different matrix-validation operations.

---

## 📬 Contact

* **GitHub:** `abnjawher25-art`
* **Email:** `abnjawher25@gmail.com`
* **Phone:** `+967739758085`
* **LinkedIn:** [Add LinkedIn profile]
