//// =============================================================
//// STRUCTS IN C++ (C++20+)
//// Declaration, Default Values, Usage Examples
//// =============================================================
//
//#include <iostream>
//#include <string>
//using namespace std;
//
///*
//=============================================================
//EXAMPLE 1 — Struct WITHOUT Default Values
//=============================================================
//*/
//
//struct Person
//{
//    string name;   // no default value
//    int age;       // no default value
//    double height; // no default value
//};
//
///*
//NOTES:
//- No in-class initialization.
//- Members must be initialized explicitly.
//- If left uninitialized → undefined values (for primitive types).
//*/
//
//
///*
//=============================================================
//EXAMPLE 2 — Struct WITH Default Member Values
//=============================================================
//*/
//
//struct Rectangle
//{
//    double width = 1.0;   // default value
//    double height = 1.0;  // default value
//
//    // Constructor (overrides default if arguments passed)
//    Rectangle(double w, double h)
//    {
//        width = w;
//        height = h;
//    }
//
//    double area() const
//    {
//        return width * height;
//    }
//};
//
///*
//NOTES:
//- Default values apply if no explicit initialization given.
//- If constructor assigns values → defaults are overridden.
//*/
//
//
//// =============================================================
//// MAIN
//// =============================================================
//
//int main()
//{
//    // ----------------------------
//    // Example 1 Usage (No Defaults)
//    // ----------------------------
//
//    Person p1{ "JOHN Helldiver", 25, 5.9 };  // must initialize
//
//    cout << "Person:\n";
//    cout << "Name: " << p1.name << endl;
//    cout << "Age: " << p1.age << endl;
//    cout << "Height: " << p1.height << endl;
//
//
//    // ----------------------------
//    // Example 2 Usage (With Defaults)
//    // ----------------------------
//
//    Rectangle r1(5.0, 3.0);
//
//    cout << "\nRectangle:\n";
//    cout << "Width: " << r1.width << endl;
//    cout << "Height: " << r1.height << endl;
//    cout << "Area: " << r1.area() << endl;
//
//    return 0;
//}
//
//
///*
//=============================================================
//IMPORTANT TECHNICAL NOTES
//=============================================================
//
//1) Memory Layout:
//   Struct members are contiguous (subject to padding).
//
//2) If no initialization is done:
//   - Primitive types → undefined values.
//   - std::string → default constructs safely.
//
//3) struct vs class:
//   struct  → default public
//   class   → default private
//
//4) Default Member Initialization:
//   Introduced in C++11.
//   Recommended for safer code.
// 
// 5) Structs when passed as arguments are pass-by-value (the current function use copy of struct, not the original one)
//
//=============================================================
//*/
//
///*
//=============================================================
//PASSING STRUCTS TO FUNCTIONS — IMPORTANT NOTES
//=============================================================
//
//1) PASS-BY-VALUE (Default Behavior)
//------------------------------------
//
//void printPerson(Person p);
//
//- Entire struct is copied.
//- Modifications inside function do NOT affect original.
//- Copy cost depends on struct size.
//- For small structs → acceptable.
//- For large structs → inefficient.
//
//Memory:
//Original object → stack
//Function parameter → separate copy on stack
//
//Risk:
//Large structs → performance overhead.
//
//
//2) PASS-BY-REFERENCE
//---------------------
//
//void modifyPerson(Person& p);
//
//- No copy is made.
//- Function works on original object.
//- Any modification affects caller.
//- Efficient for large structs.
//
//Memory:
//Only reference (alias) is passed.
//No duplicate object created.
//
//Use when:
//- You need to modify original object.
//- Struct is large and copy is expensive.
//
//
//3) PASS-BY-CONST-REFERENCE (Recommended for Read-Only)
//-------------------------------------------------------
//
//void printPerson(const Person& p);
//
//- No copy.
//- Cannot modify object.
//- Safe + efficient.
//- Industry standard for large objects.
//
//Best practice:
//Use const reference unless modification is required.
//
//
//4) WHEN TO USE WHAT?
//---------------------
//
//Small struct (few ints/doubles):
//    → Pass by value is fine.
//
//Large struct (strings, vectors, arrays, many members):
//    → Pass by const reference.
//
//Need to modify original:
//    → Pass by non-const reference.
//
//
//5) WHY THIS MATTERS
//
//Struct copy includes:
//- All primitive members
//- All object members (which may internally allocate memory)
//
//Example:
//If struct contains std::string,
//copying means string copy operation is triggered.
//
//So blindly passing by value can be expensive.
//
//
//=============================================================
//SUMMARY
//=============================================================
//
//Default in C++ = Pass-by-value.
//But for structs in real-world code:
//
//    const StructType&  → most common
//    StructType&        → when modifying
//    StructType         → only when small or intentional copy
//
//=============================================================
//*/