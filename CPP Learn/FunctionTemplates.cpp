//// ============================================================
//// FUNCTION TEMPLATES IN C++
//// ============================================================
//
//#include <iostream>
//using namespace std;
//
///*
//============================================================
//1) WHAT IS A FUNCTION TEMPLATE?
//============================================================
//
//A function template allows writing a generic function
//that works with multiple data types.
//
//Instead of writing:
//
//    int add(int a, int b)
//    double add(double a, double b)
//
//We write ONE template.
//
//Compiler generates the correct version at compile time.
//
//This is called:
//    Compile-Time Polymorphism
//    Parametric Polymorphism
//
//============================================================
//2) BASIC SYNTAX
//============================================================
//
//template <typename T>
//ReturnType functionName(T param1, T param2)
//
//OR
//
//template <class T>
//
//typename and class are identical here.
//
//*/
//
//
//// ------------------------------------------------------------
//// Example 1: Simple Generic Add
//// ------------------------------------------------------------
//template <typename T>
//T add(T a, T b)
//{
//    return a + b;
//}
//
//
///*
//When you call:
//
//    add(5, 10);        -> T becomes int
//    add(2.5, 3.1);     -> T becomes double
//
//Compiler generates separate versions internally.
//
//*/
//
//
//// ------------------------------------------------------------
//// Example 2: Explicit Template Argument
//// ------------------------------------------------------------
//template <typename T>
//T multiply(T a, T b)
//{
//    return a * b;
//}
//
//
///*
//You can call it two ways:
//
//    multiply(2, 3);          // type deduction
//    multiply<int>(2, 3);     // explicit
//
//Explicit form is useful when deduction fails.
//*/
//
//
//// ------------------------------------------------------------
//// Example 3: Multiple Template Parameters
//// ------------------------------------------------------------
//template <typename T, typename U>
//auto addDifferentTypes(T a, U b)
//{
//    return a + b;   // return type deduced automatically
//}
//
//
///*
//Here:
//    T and U can be different types.
//    auto deduces return type.
//
//*/
//
//
//// ------------------------------------------------------------
//// Example 4: Template with Comparison
//// ------------------------------------------------------------
//template <typename T>
//T getMax(T a, T b)
//{
//    return (a > b) ? a : b;
//}
//
//
///*
//WARNING:
//Type T must support '>' operator.
//Otherwise compilation fails.
//
//Templates are compiled ONLY when used.
//This is called:
//    Lazy Instantiation
//*/
//
//
//// ------------------------------------------------------------
//// Example 5: Template with Reference
//// ------------------------------------------------------------
//template <typename T>
//void swapValues(T& a, T& b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//
//
///*
//Important:
//Using T& avoids copying.
//Works for large objects efficiently.
//*/
//
//
//// ------------------------------------------------------------
//// MAIN
//// ------------------------------------------------------------
//int main()
//{
//    cout << "Add int: " << add(10, 20) << endl;
//    cout << "Add double: " << add(2.5, 3.5) << endl;
//
//    cout << "Multiply explicit: "
//        << multiply<int>(3, 4) << endl;
//
//    cout << "Different types: "
//        << addDifferentTypes(5, 2.5) << endl;
//
//    cout << "Max: " << getMax(15, 9) << endl;
//
//    int x = 10, y = 20;
//    swapValues(x, y);
//    cout << "Swapped x: " << x << " y: " << y << endl;
//
//    return 0;
//}
//
//
///*
//============================================================
//IMPORTANT THEORY (ADVANCED UNDERSTANDING)
//============================================================
//
//1) Templates are resolved at COMPILE TIME.
//
//2) No runtime overhead.
//
//3) Code is generated per type used.
//   (Can increase binary size.)
//
//4) Template errors appear during instantiation,
//   which sometimes makes error messages long.
//
//5) Templates require full definition in header files
//   (because compiler must see implementation).
//
//============================================================
//COMMON WARNINGS
//============================================================
//
//❌ Template functions cannot be separated like normal
//   functions unless fully visible to compiler.
//
//❌ If operator is not defined for type T,
//   compilation will fail.
//
//============================================================
//WHEN TO USE FUNCTION TEMPLATES
//============================================================
//
//- Generic algorithms
//- Utility functions
//- Mathematical operations
//- Reusable components
//- Library design
//
//============================================================
//RELATION TO STL
//============================================================
//
//STL (like std::sort, std::max, etc.)
//is heavily built using templates.
//
//============================================================
//*/