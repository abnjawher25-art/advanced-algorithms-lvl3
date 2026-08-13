

```markdown
# 🚀 Random 3×3 Matrix — Count Number Repetitions

**Developer:** Ebrahim Bin-Goher  
**Project Category:** 2D Arrays, Searching & Frequency Counting

---

## 📌 Project Objective

A **C++** program that generates a random 3×3 two-dimensional array, asks the user to enter a number between `0` and `99`, and then counts how many times that number appears inside the matrix.

This project demonstrates several fundamental C++ programming concepts:
* Two-dimensional arrays (2D Arrays)
* Modular programming with functions
* Random number generation
* Nested `for` loops
* Passing multi-dimensional arrays to functions
* User input validation
* Matrix search algorithms and occurrence counting
* Formatting console output using `printf()`

---

## 💻 Languages & Technologies

* **Language:** C++
* **Standard Libraries:** `<iostream>`, `<random>`, `<iomanip>`, `<cstdlib>`, `<ctime>`
* **Key Functions & Features:** `rand()`, `srand()`, `time()`, `printf()`
* **Data Structure:** 2D Array (`short arr[3][3]`)
* **Matrix Dimensions:** 3×3
* **Random Number Range:** 0 → 100
* **User Input Range:** 0 → 99

---

## 🧠 Project Algorithm

### 1. Inputs
The program prompts the user to enter a search query:
```text
Enter number to look for it:

```

* **Validation Constraint:** Only values within `0 → 99` are accepted.

### 2. Execution Flow

1. Initialize the pseudo-random number generator using the system timestamp (`srand(time(nullptr))`).
2. Instantiate a $3 \times 3$ matrix array.
3. Populate the array with random integer values.
4. Render the generated matrix on the console screen with proper formatting.
5. Capture user input and validate it through a standard validation loop.
6. Traverse the $3 \times 3$ grid using nested iterations.
7. Compare each element (`arr[row][col]`) against the user's target number.
8. Increment an occurrence counter upon finding matching elements.
9. Output the total count or display a non-found notification.

---

## 📤 Output Structure

### 1. Generated Matrix Output

```text
The 2D array is:

  12  45  12 
  78  12  33 
  91  45  67 

```

### 2. Search Result Output

* **When matches are found:**
```text
the number 12 repeated 3 times in array.

```


* **When no matches exist:**
```text
the number 99 is unfound in current array.

```



---

## 📝 Project Code

```cpp
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// Function to generate random numbers between 1 and 100
short GetRandomNumber()
{
    // Define the range for random numbers
    const short from = 1;
    const short to = 100;

    // Generate a random number between 'from' and 'to'
    return rand() % (to - from + 1);
}

// Function to fill a 2D array with random numbers
void FillMatrixArrayByRandomNumbers(
    short arr[3][3],
    short rows,
    short columns)
{
    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            arr[position_x][position_y] = GetRandomNumber();
        }
    }
}

// Function to read a valid positive number within range
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

// Function to calculate the repetition of an item inside a 2D array
short CalculateRepeationOfItemAtArray(
    short arr[3][3],
    short number,
    short rows,
    short columns)
{
    short Calculator = 0;

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
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

    for (short position_x = 0; position_x < rows; position_x++)
    {
        for (short position_y = 0; position_y < columns; position_y++)
        {
            printf("  %0*d ", 2, arr[position_x][position_y]);
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

int main()
{
    // Seed the random number generator with current system time
    srand(time(nullptr));

    short arr[3][3];

    // Fill the 2D array with random numbers
    FillMatrixArrayByRandomNumbers(arr, 3, 3);

    // Print the matrix
    printMatrixArrayThatRandomNumbers(arr, 3, 3);

    // Read the search target number
    short number = readPositiveNumber("enter number to look for it: ");

    // Calculate the number of repetitions
    short repeationVar = CalculateRepeationOfItemAtArray(arr, number, 3, 3);

    // Print the final result
    printRepeationOfItemResult(repeationVar, number);

    return 0;
}

```

---

## 🔍 Code Breakdown & Explanation

### `GetRandomNumber()`

Generates pseudo-random values using C-style `rand()` logic:

```cpp
return rand() % (to - from + 1);

```

> **Note on Off-by-One Range Logic:**
> The variable configuration `from = 1` and `to = 100` coupled with `% 100` generates numbers from `0 → 99`.
> * To strictly bound values within `1 → 100`, append `+ from`: `return rand() % (to - from + 1) + from;`
> * To explicitly generate `0 → 99`, simplify to: `return rand() % 100;`
> 
> 

### `FillMatrixArrayByRandomNumbers()`

Traverses $3 \times 3$ storage positions ($N = 9$ operations total) using nested loops:

* **Outer loop (`position_x`):** Iterates over rows.
* **Inner loop (`position_y`):** Iterates over columns.

### `readPositiveNumber()`

Implements an **Input Validation Loop** via a `do...while` structure:

* Guarantees at least one user execution.
* Re-prompts continuously until the input satisfies $0 \le x \le 99$.

### `CalculateRepeationOfItemAtArray()`

Executes linear search across all matrix cells:

* Maintains a local state accumulator (`short Calculator = 0`).
* Increments `Calculator` upon matching value equality (`number == arr[x][y]`).
* Evaluates all 9 grid positions fully without premature termination.

### `printMatrixArrayThatRandomNumbers()`

Formats numerical display utilizing standard IO format specifiers:

```cpp
printf("  %0*d ", 2, arr[position_x][position_y]);

```

Padding numbers with leading zeros (e.g., `5` becomes `05`) ensures uniform column alignment.

---

## 🧠 Program Flowchart

```text
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
        Validate input (0 → 99)
                    │
                    ▼
         Search entire matrix
                    │
                    ▼
         Count matching elements
                    │
                    ▼
           Was number found?
               /         \
             YES          NO
              │            │
              ▼            ▼
      Print repetition   Print not found
              │            │
              └─────┬──────┘
                    │
                    ▼
                   END

```

---

## 📸 Example Execution Log

```text
The 2D array is:

  12  45  12 
  78  12  33 
  91  45  67 

enter number to look for it: 12

		the number 12 repeated 3 times in array.

```

---

## ⚠️ Common Mistakes & Edge Cases to Avoid

1. **Counter State Reset:** Ensure local search accumulators initialize to zero (`short Calculator = 0`) before array iteration starts.
2. **Avoiding Premature Return:** Do not place an `else return` statement inside matrix element check loops, as it halts full traversal after checking only `arr[0][0]`.
3. **Identifier Naming Consistency:** Standardizing spelling across functions improves code maintainability (e.g., `CalculateRepetitionOfItemInArray` vs `CalculateRepeationOfItemAtArray`).

---

## 💡 Ideas for Future Enhancements

* [ ] Add coordinates display for matched values (e.g., `Found at [0][2]`).
* [ ] Support dynamic matrix dimension input ($N \times M$).
* [ ] Integrate modern C++ `<random>` engine primitives (`std::mt19937` and `std::uniform_int_distribution`).
* [ ] Calculate frequency metrics across all matrix values and display a summary report.

---

## 📬 Contact & Links

* **GitHub:** [abnjawher25-art](https://www.google.com/search?q=https://github.com/abnjawher25-art)
* **Email:** abnjawher25@gmail.com
* **Phone:** +967739758085

```

```
