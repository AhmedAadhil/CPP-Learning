//// ==========================================
//// TOPIC: std::fill() Function (Without Vector)
//// ==========================================
//
//#include <iostream>
//#include <algorithm>   // Required for std::fill
//#include <array>
//
//// --------------------------------------------------
//// MAIN
//// --------------------------------------------------
//
//int main()
//{
//    // --------------------------------------------------
//    // 1) Using std::fill with Raw Array
//    // --------------------------------------------------
//
//    int arr[5];
//
//    std::fill(arr, arr + 5, 100);
//    // Fills elements from arr[0] to arr[4]
//
//    std::cout << "Raw array:\n";
//    for (int i = 0; i < 5; ++i)
//        std::cout << arr[i] << " ";
//
//
//    // --------------------------------------------------
//    // 2) Using std::fill with std::array
//    // --------------------------------------------------
//
//    std::array<int, 4> stdArr;
//
//    std::fill(stdArr.begin(), stdArr.end(), 50);
//
//    std::cout << "\n\nstd::array:\n";
//    for (size_t i = 0; i < stdArr.size(); ++i)
//        std::cout << stdArr[i] << " ";
//
//
//    return 0;
//}
//
//
///*
//==================================================
//BASIC SYNTAX
//==================================================
//
//std::fill(start, end, value);
//
//- start  -> inclusive
//- end    -> exclusive
//- Works with pointers or iterators
//
//
//==================================================
//HOW IT WORKS WITH RAW ARRAY
//==================================================
//
//std::fill(arr, arr + 5, 100);
//
//arr         -> pointer to first element
//arr + 5     -> pointer one past last element
//
//Equivalent manual loop:
//
//for (int i = 0; i < 5; ++i)
//    arr[i] = 100;
//
//
//==================================================
//KEY WARNINGS
//==================================================
//
//1) End is NOT included.
//   arr + 5 fills index 0 to 4.
//
//2) Do NOT write:
//   std::fill(arr, arr + sizeof(arr), value);
//   sizeof(arr) gives bytes, NOT element count.
//
//3) For element count safely:
//   sizeof(arr) / sizeof(arr[0])
//
//
//==================================================
//STANDARD PRACTICES
//==================================================
//
//✔ Prefer std::fill over manual loops.
//✔ Use std::array when size is fixed at compile time.
//✔ Avoid magic numbers — compute size safely.
//
//
//==================================================
//TIME COMPLEXITY
//==================================================
//
//O(n)
//
//==================================================
//WHEN TO USE
//==================================================
//
//- Reinitializing arrays
//- Resetting buffers
//- Reusing memory blocks
//- Setting default values
//
//*/