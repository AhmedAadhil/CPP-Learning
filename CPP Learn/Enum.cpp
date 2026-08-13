///*
//============================================================
//ENUM NOTES (C++20) – Single File Version
//============================================================
//
//WHY STRING CANNOT BE USED IN SWITCH?
//
//- switch works only with:
//    * integral types (int, char, etc.)
//    * enum types
//
//- std::string is a class object.
//- case labels must be compile-time constant integral expressions.
//- Therefore string cannot be used inside switch.
//
//============================================================
//1) TRADITIONAL ENUM
//============================================================
//
//- Implicitly integer based.
//- First value = 0 (unless manually assigned).
//- Automatically increments.
//- Implicit conversion to int is allowed.
//- Pollutes global scope (enumerator names leak).
//
//SYNTAX:
//    enum Name { VALUE1, VALUE2 };
//
//============================================================
//2) SCOPED ENUM (enum class)  (Modern C++)
//============================================================
//
//- Strongly typed.
//- No implicit conversion to int.
//- Does NOT pollute global scope.
//- Must use scope resolution operator (::).
//- Preferred in C++20+.
//
//SYNTAX:
//    enum class Name { VALUE1, VALUE2 };
//
//============================================================
//*/
//
//
//#include <iostream>
//#include <string>
//
///* ----------------------------
//   Traditional Enum
//---------------------------- */
//enum Direction
//{
//    LEFT,   // 0
//    RIGHT   // 1
//};
//
///* ----------------------------
//   Scoped Enum (enum class)
//---------------------------- */
//enum class Status
//{
//    OK,     // 0
//    ERROR   // 1
//};
//
//
//int main()
//{
//    std::cout << "=== Traditional Enum ===\n";
//
//    Direction dir = LEFT;   // No scope required
//
//    // Implicit conversion allowed
//    int dirValue = dir;
//
//    std::cout << "Direction as int: " << dirValue << "\n";
//
//    switch (dir)
//    {
//    case LEFT:
//        std::cout << "Going LEFT\n";
//        break;
//
//    case RIGHT:
//        std::cout << "Going RIGHT\n";
//        break;
//    }
//
//
//    std::cout << "\n=== Scoped Enum (enum class) ===\n";
//
//    Status s = Status::OK;
//
//    // int x = s;  // ❌ ERROR (no implicit conversion)
//
//    int statusValue = static_cast<int>(s);  // explicit conversion required
//    std::cout << "Status as int: " << statusValue << "\n";
//
//    switch (s)
//    {
//    case Status::OK:
//        std::cout << "Status OK\n";
//        break;
//
//    case Status::ERROR:
//        std::cout << "Status ERROR\n";
//        break;
//    }
//
//
//    std::cout << "\n=== Why string cannot be used in switch ===\n";
//
//    std::string input = "OK";
//
//    // switch (input)   // ❌ ERROR: not integral type
//    // {
//    //     case "OK":   // ❌ Not allowed
//    // }
//
//    std::cout << "Switch does not support std::string directly.\n";
//
//    return 0;
//}
//
///*
//============================================================
//KEY WARNINGS
//============================================================
//
//1) Prefer enum class in modern C++.
//2) Always use static_cast<int>() if integer needed.
//3) Avoid traditional enum in large systems (name conflicts).
//4) enum values are compile-time constants.
//5) enum class improves type safety significantly.
//
//============================================================
//SUMMARY
//============================================================
//
//Traditional enum:
//    - Weak typing
//    - Implicit int conversion
//    - Global name leakage
//
//enum class:
//    - Strong typing
//    - No implicit conversion
//    - Scoped and safer
//    - Recommended for C++20+
//
//============================================================
//*/