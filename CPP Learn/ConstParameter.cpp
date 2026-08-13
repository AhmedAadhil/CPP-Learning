//// ==========================================================
//// CONST PARAMETERS IN C++
//// Why & How To Use Them
//// ==========================================================
//
//#include <iostream>
//using namespace std;
//
//
//// ==========================================================
//// 1. CONST WITH PASS BY VALUE
//// ==========================================================
//// Prevents accidental modification inside the function.
//// Mostly documentation-level safety for primitives.
////
//	
//void printValue(const int x)
//{
//    // x = 100;   // ❌ ERROR: cannot modify const parameter
//
//    cout << "[printValue] Value: " << x << endl;
//}
//
//
//// ==========================================================
//// 2. CONST WITH PASS BY REFERENCE  (VERY IMPORTANT)
//// ==========================================================
//// Prevents modification of original object.
//// Avoids copying large objects.
//// This is the most common real-world usage.
////
//
//void printByReference(const int& x)
//{
//    // x = 200;   // ❌ ERROR: cannot modify referenced value
//
//    cout << "[printByReference] Value: " << x << endl;
//    cout << "Address inside function: " << &x << endl;
//}
//
//
//// ==========================================================
//// 3. WITHOUT CONST (for comparison)
//// ==========================================================
//
//void modifyValue(int& x)
//{
//    x = 999;   // Allowed
//}
//
//
//// ==========================================================
//// 4. CONST WITH ARRAYS
//// ==========================================================
//// Prevents modification of array elements.
////
//
//void printArray(const int arr[], int size)
//{
//    // arr[0] = 100;   // ❌ ERROR: cannot modify
//
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//
//// ==========================================================
//
//int main()
//{
//    int num = 10;
//
//    cout << "Original num value  : " << num << endl;
//    cout << "Original num address: " << &num << endl;
//
//
//    cout << "\n--- Pass by VALUE (const) ---\n";
//    printValue(num);
//
//
//    cout << "\n--- Pass by REFERENCE (const) ---\n";
//    printByReference(num);
//    cout << "Address in main     : " << &num << endl;
//
//
//    cout << "\n--- Pass by REFERENCE (non-const) ---\n";
//    modifyValue(num);
//    cout << "After modification  : " << num << endl;
//
//
//    cout << "\n--- CONST Array Parameter ---\n";
//    int arr[3] = { 1, 2, 3 };
//    printArray(arr, 3);
//
//
//    return 0;
//}
//
//
//// ==========================================================
//// THEORY EXPLANATION
//// ==========================================================
////
//// WHY USE CONST PARAMETERS?
////
//// 1. Prevent accidental modification
//// 2. Makes intent clear
//// 3. Enables compiler optimizations
//// 4. Required for passing temporaries (rvalues)
////
//// ----------------------------------------------------------
////
//// IMPORTANT DIFFERENCE:
////
//// const int x        -> Copy, cannot modify inside function
////
//// int& x             -> Reference, CAN modify original
////
//// const int& x       -> Reference, CANNOT modify original
////                        (Best practice for large objects)
////
//// ----------------------------------------------------------
////
//// REAL-WORLD BEST PRACTICE:
////
//// For primitives (int, char, bool):
////     pass by value is fine.
////
//// For large objects (arrays, structs, classes, strings):
////     use const reference:
////
////     void func(const MyClass& obj);
////
//// Avoids copy + prevents modification.
////
//// ----------------------------------------------------------
////
//// ADVANCED NOTE:
////
//// const reference allows binding to rvalues:
////
////     printByReference(100);   // Works only because it's const&
////
//// Non-const reference cannot bind to temporary:
////
////     void test(int& x);
////     test(100);   // ❌ ERROR
////
//// ==========================================================