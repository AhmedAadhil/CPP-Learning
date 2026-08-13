//// ==========================================
//// TOPIC: Linear Search Using Function
//// ==========================================
//
//#include <iostream>
//
//// --------------------------------------------------
//// Linear Search Function
//// Returns index if found
//// Returns -1 if not found
//// --------------------------------------------------
//
//int linearSearch(const int arr[], int size, int target)
//{
//    // Standard iterative approach
//    for (int i = 0; i < size; ++i)
//    {
//        if (arr[i] == target)
//            return i;   // Early exit when found
//    }
//
//    return -1;  // Not found
//}
//
//
//// --------------------------------------------------
//// Advanced Variant (Using const reference style)
//// Works same as above but shows modern parameter intent
//// --------------------------------------------------
//
//int linearSearchModern(const int* arr, int size, int target)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        if (*(arr + i) == target)   // Pointer arithmetic form
//            return i;
//    }
//
//    return -1;
//}
//
//
//// --------------------------------------------------
//// MAIN
//// --------------------------------------------------
//
//int main()
//{
//    int numbers[] = { 4, 7, 1, 9, 3, 6 };
//    int size = sizeof(numbers) / sizeof(numbers[0]);
//
//    int target = 9;
//
//    int index = linearSearch(numbers, size, target);
//
//    if (index != -1)
//        std::cout << "Element found at index: " << index << "\n";
//    else
//        std::cout << "Element not found\n";
//
//    return 0;
//}
//
//
///*
//==================================================
//KEY NOTES
//==================================================
//
//1) Time Complexity:
//   O(n)
//
//2) Space Complexity:
//   O(1)
//
//3) Early return improves best-case to O(1).
//
//4) Array decays to pointer in function parameter:
//      int arr[]  ==  int* arr
//
//5) Must pass size separately (raw array limitation).
//
//6) For modern C++, prefer:
//      std::vector<int>
//   or
//      std::span<int>  (C++20)
//
//==================================================
//COMMON MISTAKES
//==================================================
//
//- Forgetting to pass correct size.
//- Using sizeof(arr) inside function (WRONG).
//- Not returning -1 when not found.
//
//==================================================
//WHEN TO USE LINEAR SEARCH
//==================================================
//
//- Small datasets
//- Unsorted arrays
//- When insertion/deletion is frequent
//- When simplicity > performance
//
//For sorted large datasets -> Use Binary Search.
//
//*/