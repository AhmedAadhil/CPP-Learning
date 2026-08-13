//// ============================================================
//// NULL POINTER IN C++
//// Definition, Usage, Safety Rules
//// ============================================================
//
//#include <iostream>
//using namespace std;
//
//
//// ============================================================
//// 1️⃣ WHAT IS A NULL POINTER?
//// ============================================================
////
//// A null pointer:
////   → Points to NOTHING
////   → Does not hold a valid memory address
////   → Represents absence of object
////
//// Modern C++ keyword: nullptr
////
//
//
//// ============================================================
//// 2️⃣ HOW TO DEFINE NULL POINTER
//// ============================================================
//
//void definitionDemo()
//{
//    int* pNumber = nullptr;   // ✅ Correct (C++11+)
//
//    cout << "\n--- NULL POINTER DEFINITION ---\n";
//    cout << "Value inside pNumber: " << pNumber << endl;
//
//    if (pNumber == nullptr)
//    {
//        cout << "pNumber is null (safe check)\n";
//    }
//}
//
//
//// ============================================================
//// 3️⃣ WHY nullptr INSTEAD OF NULL?
//// ============================================================
////
//// Old C-style:
////     int* p = NULL;
////
//// Problem:
////     NULL is just 0 (integer literal)
////
//// nullptr:
////     Has its own type (std::nullptr_t)
////     Safer in function overloading
////
//
//void overload(int* p)
//{
//    cout << "Pointer version called\n";
//}
//
//void overload(int value)
//{
//    cout << "Integer version called\n";
//}
//
//void nullptrDemo()
//{
//    cout << "\n--- nullptr vs NULL ---\n";
//
//    overload(nullptr);  // Calls pointer version
//    overload(0);        // Calls integer version
//}
//
//
//// ============================================================
//// 4️⃣ DANGEROUS BEHAVIOR
//// ============================================================
////
//// Dereferencing null pointer = Undefined Behavior
////
//
//void dangerousDemo()
//{
//    int* pNumber = nullptr;
//
//    cout << "\n--- DANGEROUS EXAMPLE ---\n";
//
//    // cout << *pNumber;  // ❌ CRASH / Undefined Behavior
//
//    if (pNumber != nullptr)
//    {
//        cout << *pNumber;
//    }
//    else
//    {
//        cout << "Pointer is null, not dereferencing.\n";
//    }
//}
//
//
//// ============================================================
//// 5️⃣ COMMON USAGE SCENARIOS
//// ============================================================
////
//// 1. Default initialization
//// 2. Indicating optional object
//// 3. After delete (avoid dangling pointer)
////
//
//void usageDemo()
//{
//    cout << "\n--- COMMON USAGE ---\n";
//
//    int* pData = nullptr;   // default safe state
//
//    // simulate dynamic allocation
//    pData = new int(500);
//
//    cout << "Value after allocation: " << *pData << endl;
//
//    delete pData;
//
//    pData = nullptr;   // VERY IMPORTANT (avoid dangling pointer)
//
//    if (pData == nullptr)
//    {
//        cout << "Pointer safely reset after delete.\n";
//    }
//}
//
//
//// ============================================================
//// 6️⃣ MEMORY THEORY
//// ============================================================
////
//// nullptr typically equals address 0x0
//// OS protects that memory region.
//// Dereferencing it triggers segmentation fault.
////
////
//// Stack pointer example:
//// int* p;          // uninitialized (dangerous)
//// int* p = nullptr;  // safe
////
//
//
//// ============================================================
//
//int main()
//{
//    definitionDemo();
//    nullptrDemo();
//    dangerousDemo();
//    usageDemo();
//
//    return 0;
//}
//
//
//// ============================================================
//// SUMMARY
//// ============================================================
////
//// nullptr:
////   - Represents no object
////   - Safe modern null pointer
////
//// Always initialize pointers:
////   int* p = nullptr;
////
//// Always check before dereferencing:
////
////   if (p != nullptr)
////
//// After delete:
////   p = nullptr;
////
//// Never dereference null pointer.
////
//// ============================================================