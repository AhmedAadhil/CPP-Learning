// ==========================================================
// TOPIC: Passing Arrays as Function Parameters (Modern + Safe Practices)
// ==========================================================

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <span>        // C++20 (recommended modern solution)

// ----------------------------------------------------------
// 1) RAW ARRAY PARAMETER (Decays to Pointer) — Legacy Style
// ----------------------------------------------------------

// ❗ Important:
// When passing raw arrays, they decay to pointers.
// Size information is LOST.

void printRaw(const std::string arr[], size_t size)
{
    // arr is actually: const std::string*
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << "\n";
}

/*
⚠ Warnings:
- sizeof(arr) inside this function = size of pointer (NOT full array)
- No bounds checking
- Must manually pass size
- Easy to misuse
*/


// ----------------------------------------------------------
// 2) POINTER EXPLICIT STYLE (Same as above, more honest)
// ----------------------------------------------------------

void printPointer(const std::string* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << "\n";
}

/*
Best practice:
If you use raw arrays → be explicit with pointer syntax.
More readable and accurate.
*/


// ----------------------------------------------------------
// 3) TEMPLATE REFERENCE (Size SAFE, No Decay)
// ----------------------------------------------------------

template <size_t N>
void printSafe(const std::string(&arr)[N])
{
    // N is known at compile time
    for (size_t i = 0; i < N; ++i)
        std::cout << arr[i] << "\n";
}

/*
✔ No decay
✔ Size known at compile-time
✔ Safer
✖ Only works with raw arrays (not vectors)
*/


// ----------------------------------------------------------
// 4) std::array (Preferred Over Raw Arrays)
// ----------------------------------------------------------

void printStdArray(const std::array<std::string, 3>& arr)
{
    for (const auto& name : arr)
        std::cout << name << "\n";
}

/*
✔ Fixed size
✔ Safer than raw array
✔ Knows its own size
✔ Works well with STL
*/


// ----------------------------------------------------------
// 5) std::vector (Most Common in Real Code)
// ----------------------------------------------------------

void printVector(const std::vector<std::string>& vec)
{
    for (const auto& name : vec)
        std::cout << name << "\n";
}

/*
✔ Dynamic size
✔ Safest general-purpose container
✔ Standard professional approach
✔ Use const& unless modifying
*/


// ----------------------------------------------------------
// 6) std::span (C++20 — Modern Best Practice)
// ----------------------------------------------------------

void printSpan(std::span<const std::string> span)
{
    for (const auto& name : span)
        std::cout << name << "\n";
}

/*
✔ Accepts:
    - Raw arrays
    - std::array
    - std::vector
✔ No copy
✔ Size preserved
✔ Extremely flexible
✔ Recommended in modern C++20+
*/


// ==========================================================
// MAIN
// ==========================================================

int main()
{
    std::string raw[] = { "Alice", "Bob", "Charlie" };
    std::array<std::string, 3> arr = { "Dave", "Eve", "Frank" };
    std::vector<std::string> vec = { "Grace", "Hank", "Ivy" };

    printRaw(raw, 3);
    printPointer(raw, 3);
    printSafe(raw);
    printStdArray(arr);
    printVector(vec);
    printSpan(raw);
    printSpan(arr);
    printSpan(vec);

    return 0;
}

/*
==========================================================
PROFESSIONAL BEST PRACTICES SUMMARY
==========================================================

1) Avoid raw arrays in modern C++ unless necessary.
2) Prefer std::vector for dynamic size.
3) Prefer std::array for fixed compile-time size.
4) Use const & for read-only parameters.
5) Use std::span in C++20 for generic array-like parameters.
6) Never rely on sizeof() inside array parameter functions.

==========================================================
INTERVIEW / ADVANCED NOTES
==========================================================

• Raw array parameter:
    void func(int arr[])
  is identical to:
    void func(int* arr)

• Arrays cannot be passed by value.
• Passing large containers by value causes full copy.
• If modification is required:
    std::vector<T>&
• If optional modification:
    std::span<T>

Modern guideline:
    "Prefer containers over raw arrays."
    "Prefer span when writing generic APIs."

*/