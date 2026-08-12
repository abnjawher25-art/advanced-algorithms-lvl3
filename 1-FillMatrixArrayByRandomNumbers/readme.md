# 🚀 Random 3×3 Matrix Generator

> **Developer:** [Ebrahim Bin-Goher]
> **Project Category:** Random Number Generation & 2D Arrays

---

## 📌 Project Objective

A C++ program that generates random numbers between **1 and 99**, stores them in a **3×3 two-dimensional array**, and displays the generated numbers in a structured format.

This project demonstrates several fundamental C++ programming concepts:

* Two-dimensional arrays (2D Arrays).
* Functions.
* Random number generation.
* Nested loops.
* Passing arrays to functions.
* Output formatting using `setw()`.

---

## 💻 Programming Languages & Technologies

* **Programming Language:** C++
* **Libraries:** `iostream`, `iomanip`, `ctime`
* **Functions & Features:** `rand()`, `srand()`, `time()`, `setw()`

---

## 🧠 Project Algorithm

### 1. Inputs

The program does not require direct user input.

It automatically creates a `3×3` array.

### 2. Processing Steps

1. Initialize the random number generator using the current system time.
2. Create a `short` 2D array with dimensions `3×3`.
3. Call `FillMatrixArrayByRandomNumbers()`.
4. Iterate through all rows and columns using nested `for` loops.
5. Generate a random number between `1` and `99` using `GetRandomNumber()`.
6. Store each generated number inside the corresponding array element.
7. Call `PrintMatrixArrayThatRandomNumbers()`.
8. Display the matrix using `setw(3)` for better formatting.

### 3. Outputs

A `3×3` matrix containing **9 random numbers**, where each number is between **1 and 99**.

---

## 📝 Project Code

```cpp
#include <iostream>
#include <iomanip>
#include <ctime>

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
    cout << "Following are the random numbers:\n" << endl;

    // Print the 2D array
    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            cout << setw(3) << arr[position_x][position_y] << " ";
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

    // Fill the matrix with random numbers
    FillMatrixArrayByRandomNumbers(arr, 3, 3);

    // Print the matrix
    PrintMatrixArrayThatRandomNumbers(arr, 3, 3);

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

The formula guarantees that the generated value falls within the specified range.

---

### `FillMatrixArrayByRandomNumbers()`

Receives a `3×3` matrix and fills every element with a randomly generated number.

It uses two nested `for` loops:

* The first loop handles the rows.
* The second loop handles the columns.

---

### `PrintMatrixArrayThatRandomNumbers()`

Prints all elements of the matrix.

The following statement:

```cpp
setw(3)
```

sets the output field width to `3`, making the matrix easier to read.

---

### `main()`

The entry point of the program.

It:

1. Seeds the random number generator.
2. Creates the `3×3` matrix.
3. Fills the matrix with random numbers.
4. Prints the generated matrix.

---

### `short arr[3][3]`

Creates a two-dimensional array containing:

* `3` rows.
* `3` columns.
* `9` total elements.

---

### `rand() % (to - from + 1) + from`

Generates a random number within the range:

```text
1 → 99
```

---

### `srand(time(nullptr))`

Initializes the random number generator using the current system time, helping produce a different sequence of numbers each time the program runs.

---

## 📸 Project Output

The output changes each time the program runs because the numbers are randomly generated.

Example:

```text
Following are the random numbers:

 12  87  34
 65   9  71
 43  28  96
```

> The numbers above are only an example. The program will normally generate different values on each execution.

---

## ⚠️ Common Mistakes to Avoid

### 1. Forgetting `<ctime>`

Because the program uses:

```cpp
time(nullptr)
```

the appropriate time library should be included:

```cpp
#include <ctime>
```

---

### 2. Not Seeding the Random Number Generator

Calling:

```cpp
srand(time(nullptr));
```

before using `rand()` helps avoid getting the same random sequence on every execution.

---

### 3. Exceeding Array Bounds

The matrix contains only `3×3` elements.

Valid indexes are:

```text
Rows:    0 → 2
Columns: 0 → 2
```

Accessing indexes outside these ranges can cause undefined behavior.

---

### 4. Mismatching Matrix Dimensions

The functions are designed to receive a matrix declared as:

```cpp
short arr[3][3]
```

Therefore, the matrix dimensions must be compatible with the function parameters.

---

### 5. Including Unused Libraries

The original version included:

```cpp
#include <random>
```

but did not actually use the modern `<random>` library.

The current version removes this unnecessary include.

---

## 💡 Ideas for Further Development

* [ ] Allow the user to specify the number of rows and columns.
* [ ] Allow the user to specify the minimum and maximum random values.
* [ ] Replace `rand()` with the modern C++ `<random>` library.
* [ ] Calculate the sum and average of matrix elements.
* [ ] Find the largest and smallest values.
* [ ] Search for a specific number inside the matrix.
* [ ] Add a menu that allows the user to regenerate the matrix.
* [ ] Add additional matrix operations such as sorting and transposition.
* [ ] Build a simple graphical interface for the project.

---

## 📬 Contact

* **GitHub:** `abnjawher25-art`
* **Email:** `abnjawher25@gmail.com`
* **Phone:** `+967739758085`
* **LinkedIn:** [Add LinkedIn profile]

---
