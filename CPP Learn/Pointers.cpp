//// ============================================================
//// POINTERS IN C++
//// &, *, Pointer Behavior, Arrays, Pointer Arithmetic
//// Naming Convention: pName (pointer variables)
//// ============================================================
//
//#include <iostream>
//using namespace std;
//
//
//// ============================================================
//// 1️⃣ ADDRESS-OF OPERATOR (&)
//// ============================================================
//// &variable  → returns memory address of variable
////
//
//void addressOperatorDemo()
//{
//    int number = 42;
//
//    cout << "\n--- ADDRESS OPERATOR (&) ---\n";
//    cout << "Value of number        : " << number << endl;
//    cout << "Address of number      : " << &number << endl;
//}
//
//
//// ============================================================
//// 2️⃣ POINTER DECLARATION (*)
//// ============================================================
//// int* pNumber;
//// * means "pointer to int"
////
//// Important:
////   * in declaration ≠ dereference
////
//
//void pointerDeclarationDemo()
//{
//    int number = 100;
//
//    int* pNumber = &number;   // store address of number
//
//    cout << "\n--- POINTER DECLARATION ---\n";
//    cout << "number value           : " << number << endl;
//    cout << "number address         : " << &number << endl;
//
//    cout << "pNumber (stored addr)  : " << pNumber << endl;
//    cout << "*pNumber (dereference) : " << *pNumber << endl;
//}
//
//
//// ============================================================
//// 3️⃣ DEREFERENCE OPERATOR (*)
//// ============================================================
//// *pNumber → go to address stored inside pointer
////
//
//void dereferenceDemo()
//{
//    int number = 50;
//    int* pNumber = &number;
//
//    cout << "\n--- DEREFERENCE ---\n";
//    cout << "Before modification: " << number << endl;
//
//    *pNumber = 999;   // modifies original value
//
//    cout << "After modification : " << number << endl;
//}
//
//
//// ============================================================
//// 4️⃣ POINTERS AND ARRAYS
//// ============================================================
//// Arrays are stored in contiguous memory.
//// Array name behaves like pointer to first element.
////
//
//void arrayPointerDemo()
//{
//    int arr[4] = { 10, 20, 30, 40 };
//
//    int* pArr = arr;  // same as &arr[0]
//
//    cout << "\n--- ARRAY & POINTER BEHAVIOR ---\n";
//
//    cout << "arr (base address)     : " << arr << endl;
//    cout << "&arr[0]                : " << &arr[0] << endl;
//    cout << "pArr                   : " << pArr << endl;
//
//    cout << "\nAccess using index:\n";
//    cout << "arr[2]                 : " << arr[2] << endl;
//
//    cout << "\nAccess using pointer arithmetic:\n";
//    cout << "*(pArr + 2)            : " << *(pArr + 2) << endl;
//
//    cout << "\nAddresses:\n";
//    for (int i = 0; i < 4; i++)
//    {
//        cout << "Address of arr[" << i << "] : "
//            << &arr[i] << endl;
//    }
//}
//
//
//// ============================================================
//// 5️⃣ POINTER ARITHMETIC
//// ============================================================
//// If sizeof(int) = 4 bytes
//// p + 1 moves 4 bytes forward
////
//
//void pointerArithmeticDemo()
//{
//    int arr[3] = { 5, 10, 15 };
//    int* pArr = arr;
//
//    cout << "\n--- POINTER ARITHMETIC ---\n";
//
//    cout << "pArr        : " << pArr << endl;
//    cout << "pArr + 1    : " << pArr + 1 << endl;
//    cout << "pArr + 2    : " << pArr + 2 << endl;
//
//    cout << "*pArr       : " << *pArr << endl;
//    cout << "*(pArr + 1) : " << *(pArr + 1) << endl;
//    cout << "*(pArr + 2) : " << *(pArr + 2) << endl;
//}
//
//
//// ============================================================
//// 6️⃣ DIFFERENCE: &variable vs &pointer
//// ============================================================
//
//void pointerAddressDemo()
//{
//    int number = 77;
//    int* pNumber = &number;
//
//    cout << "\n--- POINTER ADDRESS vs VALUE ---\n";
//
//    cout << "Address of number (&number): " << &number << endl;
//    cout << "Value inside pNumber       : " << pNumber << endl;
//    cout << "Address of pointer (&pNumber): " << &pNumber << endl;
//}
//
//
//// ============================================================
//// 7️⃣ COMMON WARNINGS
//// ============================================================
////
//// 1. Uninitialized pointer → undefined behavior
////
////      int* p;   // ❌ Dangerous
////
//// 2. Always initialize:
////
////      int* p = nullptr;
////
//// 3. Never dereference nullptr:
////
////      *p   // ❌ if p == nullptr
////
//// 4. Arrays decay to pointer in most contexts.
////
//// 5. sizeof(arr) works only in same scope.
////
//
//// ============================================================
//
//int main()
//{
//    addressOperatorDemo();
//    pointerDeclarationDemo();
//    dereferenceDemo();
//    arrayPointerDemo();
//    pointerArithmeticDemo();
//    pointerAddressDemo();
//
//    return 0;
//}
//
//
//// ============================================================
//// DEEP THEORY SECTION
//// ============================================================
////
//// MEMORY MODEL
//// -------------
//// Every variable occupies memory.
//// Memory is byte-addressable.
//// Pointers store memory addresses.
////
////
//// SYMBOL MEANINGS
//// ----------------
//// &  → address-of operator
//// *  → 
////       (1) pointer declaration
////       (2) dereference operator
////
//// CONTEXT MATTERS.
////
////
//// DECLARATION vs DEREFERENCE
//// ---------------------------
////
//// int* pNumber;    // declaration
//// *pNumber = 10;   // dereference
////
////
//// ARRAY FORMULA
//// --------------
////
//// arr[i]  ==  *(arr + i)
////
//// address = base + (i * sizeof(type))
////
////
//// POINTER SIZE
//// -------------
//// sizeof(int*) usually 8 bytes on 64-bit systems.
//// Pointer size depends on architecture,
//// NOT the type it points to.
////
////
//// VERY IMPORTANT CONCEPT
//// -----------------------
//// arr        → pointer to first element
//// &arr       → pointer to entire array
////
//// Example:
//// int arr[4];
////
//// arr       → type: int*
//// &arr      → type: int (*)[4]
////
//// They are NOT the same type.
////
////
//// ============================================================