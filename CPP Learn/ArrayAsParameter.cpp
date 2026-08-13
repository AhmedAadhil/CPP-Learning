//// ==========================================================
//// topic: passing arrays as function parameters (modern + safe practices)
//// ==========================================================
//
//#include <iostream>
//#include <string>
//#include <array>
//#include <vector>
//#include <span>        // c++20 (recommended modern solution)
//
//// ----------------------------------------------------------
//// 1) raw array parameter (decays to pointer) — legacy style
//// ----------------------------------------------------------
//
//// ❗ important:
//// when passing raw arrays, they decay to pointers.
//// size information is lost.
//
//void printraw(const std::string arr[], size_t size)
//{
//    // arr is actually: const std::string*
//    for (size_t i = 0; i < size; ++i)
//        std::cout << arr[i] << "\n";
//}
//
///*
//⚠ warnings:
//- sizeof(arr) inside this function = size of pointer (not full array)
//- no bounds checking
//- must manually pass size
//- easy to misuse
//*/
//
//
//// ----------------------------------------------------------
//// 2) pointer explicit style (same as above, more honest)
//// ----------------------------------------------------------
//
//void printpointer(const std::string* arr, size_t size)
//{
//    for (size_t i = 0; i < size; ++i)
//        std::cout << arr[i] << "\n";
//}
//
///*
//best practice:
//if you use raw arrays → be explicit with pointer syntax.
//more readable and accurate.
//*/
//
//
//// ----------------------------------------------------------
//// 3) template reference (size safe, no decay)
//// ----------------------------------------------------------
//
//template <size_t n>
//void printsafe(const std::string(&arr)[n])
//{
//    // n is known at compile time
//    for (size_t i = 0; i < n; ++i)
//        std::cout << arr[i] << "\n";
//}
//
///*
//✔ no decay
//✔ size known at compile-time
//✔ safer
//✖ only works with raw arrays (not vectors)
//*/
//
//
//// ----------------------------------------------------------
//// 4) std::array (preferred over raw arrays)
//// ----------------------------------------------------------
//
//void printstdarray(const std::array<std::string, 3>& arr)
//{
//    for (const auto& name : arr)
//        std::cout << name << "\n";
//}
//
///*
//✔ fixed size
//✔ safer than raw array
//✔ knows its own size
//✔ works well with stl
//*/
//
//
//// ----------------------------------------------------------
//// 5) std::vector (most common in real code)
//// ----------------------------------------------------------
//
//void printvector(const std::vector<std::string>& vec)
//{
//    for (const auto& name : vec)
//        std::cout << name << "\n";
//}
//
///*
//✔ dynamic size
//✔ safest general-purpose container
//✔ standard professional approach
//✔ use const& unless modifying
//*/
//
//
//// ----------------------------------------------------------
//// 6) std::span (c++20 — modern best practice)
//// ----------------------------------------------------------
//
//void printspan(std::span<const std::string> span)
//{
//    for (const auto& name : span)
//        std::cout << name << "\n";
//}
//
///*
//✔ accepts:
//    - raw arrays
//    - std::array
//    - std::vector
//✔ no copy
//✔ size preserved
//✔ extremely flexible
//✔ recommended in modern c++20+
//*/
//
//
//// ==========================================================
//// main
//// ==========================================================
//
//int main()
//{
//    std::string raw[] = { "alice", "bob", "charlie" };
//    std::array<std::string, 3> arr = { "dave", "eve", "frank" };
//    std::vector<std::string> vec = { "grace", "hank", "ivy" };
//
//    printraw(raw, 3);
//    printpointer(raw, 3);
//    printsafe(raw);
//    printstdarray(arr);
//    printvector(vec);
//    printspan(raw);
//    printspan(arr);
//    printspan(vec);
//
//    return 0;
//}
//
///*
//==========================================================
//professional best practices summary
//==========================================================
//
//1) avoid raw arrays in modern c++ unless necessary.
//2) prefer std::vector for dynamic size.
//3) prefer std::array for fixed compile-time size.
//4) use const & for read-only parameters.
//5) use std::span in c++20 for generic array-like parameters.
//6) never rely on sizeof() inside array parameter functions.
//
//==========================================================
//interview / advanced notes
//==========================================================
//
//• raw array parameter:
//    void func(int arr[])
//  is identical to:
//    void func(int* arr)
//
//• arrays cannot be passed by value.
//• passing large containers by value causes full copy.
//• if modification is required:
//    std::vector<t>&
//• if optional modification:
//    std::span<t>
//
//modern guideline:
//    "prefer containers over raw arrays."
//    "prefer span when writing generic apis."
//
//*/