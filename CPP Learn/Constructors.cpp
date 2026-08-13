///*
//============================================================
//CONSTRUCTORS IN C++ (C++20)
//Syntax | Types | Member Initializer List
//When to use "this" keyword
//============================================================
//
//------------------------------------------------------------
//1) WHAT IS A CONSTRUCTOR?
//------------------------------------------------------------
//
//- Special member function.
//- Same name as class.
//- No return type.
//- Automatically called when object is created.
//- Used to initialize members.
//
//------------------------------------------------------------
//2) BASIC SYNTAX
//------------------------------------------------------------
//
//class ClassName
//{
//public:
//    ClassName(parameters)
//    {
//        // initialization logic
//    }
//};
//
//------------------------------------------------------------
//3) TYPES OF CONSTRUCTORS
//------------------------------------------------------------
//
//1) Default constructor
//2) Parameterized constructor
//3) Constructor with member initializer list
//4) Delegating constructor
//5) Explicit constructor
//6) Deleted constructor
//
//============================================================
//EXAMPLE CLASS
//============================================================
//*/
//
//#include <iostream>
//#include <string>
//
//class Person
//{
//private:
//    std::string m_name;
//    int m_age;
//
//public:
//
//    /* ----------------------------------------------------
//       1) DEFAULT CONSTRUCTOR
//       ---------------------------------------------------- */
//    Person()
//    {
//        m_name = "Unknown";
//        m_age = 0;
//    }
//
//    /* ----------------------------------------------------
//       2) PARAMETERIZED CONSTRUCTOR
//       ----------------------------------------------------
//       When parameter name equals member name,
//       we MUST use "this" to differentiate.
//    */
//    Person(std::string m_name, int m_age)
//    {
//        // Without "this", it assigns parameter to itself.
//        this->m_name = m_name;
//        this->m_age = m_age;
//    }
//
//    /* ----------------------------------------------------
//       3) MEMBER INITIALIZER LIST (Preferred)
//       ----------------------------------------------------
//       Best practice in modern C++.
//       More efficient.
//       Required for:
//           - const members
//           - reference members
//           - base class initialization
//    */
//    Person(const std::string& name, int age, bool)
//        : m_name(name), m_age(age)
//    {
//        // Body can remain empty
//    }
//
//    /* ----------------------------------------------------
//       4) DELEGATING CONSTRUCTOR
//       ----------------------------------------------------
//       One constructor calling another.
//    */
//    Person(std::string name)
//        : Person(name, 0, true)   // calls above constructor
//    {
//    }
//
//    /* ----------------------------------------------------
//       5) EXPLICIT CONSTRUCTOR
//       ----------------------------------------------------
//       Prevents implicit conversions.
//    */
//    explicit Person(int age)
//    {
//        m_name = "OnlyAge";
//        m_age = age;
//    }
//
//    /* ----------------------------------------------------
//       6) DELETED CONSTRUCTOR
//       ----------------------------------------------------
//       Prevent object creation in certain ways.
//    */
//    Person(double) = delete;
//
//    void print() const
//    {
//        std::cout << "Name: " << m_name
//            << " | Age: " << m_age << "\n";
//    }
//};
//
//
///*
//============================================================
//WHEN DO WE NEED "this" KEYWORD?
//============================================================
//
//You need "this" when:
//
//1) Parameter name = member name
//2) Returning current object (*this)
//3) Inside templates or advanced scenarios
//
//Example:
//
//    Person(std::string m_name)
//    {
//        this->m_name = m_name;   // Required
//    }
//
//If parameter name is DIFFERENT:
//
//    Person(std::string name)
//    {
//        m_name = name;   // "this" NOT needed
//    }
//
//------------------------------------------------------------
//IMPORTANT:
//------------------------------------------------------------
//
//- Prefer different parameter names to avoid needing "this".
//- Or use member initializer list (best practice).
//
//============================================================
//MAIN FUNCTION
//============================================================
//*/
//
//int main()
//{
//    std::cout << "=== Default Constructor ===\n";
//    Person p1;
//    p1.print();
//
//    std::cout << "\n=== Parameterized (using this) ===\n";
//    Person p2("Alice", 25);
//    p2.print();
//
//    std::cout << "\n=== Member Initializer List ===\n";
//    Person p3("Bob", 30, true);
//    p3.print();
//
//    std::cout << "\n=== Delegating Constructor ===\n";
//    Person p4("Charlie");
//    p4.print();
//
//    std::cout << "\n=== Explicit Constructor ===\n";
//    Person p5(40);   // Allowed
//    p5.print();
//
//    // Person p6 = 50;  // ❌ Not allowed (explicit prevents implicit conversion)
//
//    // Person p7(3.14); // ❌ Deleted constructor
//
//    return 0;
//}
//
//
///*
//============================================================
//KEY WARNINGS
//============================================================
//
//1) Always prefer MEMBER INITIALIZER LIST.
//2) Required for:
//       const members
//       reference members
//       base classes
//3) Avoid heavy logic inside constructor.
//4) Use explicit for single-argument constructors.
//5) If you define ANY constructor, compiler will NOT
//   generate default constructor automatically.
//
//============================================================
//ADVANCED AWARENESS
//============================================================
//
//If no constructor defined:
//    Compiler generates default constructor.
//
//If parameterized constructor defined:
//    Default constructor NOT auto-generated.
//
//To force default:
//    Person() = default;
//
//============================================================
//SUMMARY
//============================================================
//
//Best Practice Pattern:
//
//class Example
//{
//private:
//    int m_value;
//
//public:
//    explicit Example(int value)
//        : m_value(value)
//    {
//    }
//};
//
//Modern C++ favors:
//    initializer lists
//    explicit constructors
//    minimal constructor logic
//
//============================================================
//*/