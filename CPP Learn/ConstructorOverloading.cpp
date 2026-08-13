///*
//============================================================
//CONSTRUCTOR OVERLOADING (C++20)
//0, 1, 2 Parameter Constructors
//============================================================
//
//------------------------------------------------------------
//1) WHAT IS CONSTRUCTOR OVERLOADING?
//------------------------------------------------------------
//
//- Multiple constructors in the same class.
//- Same name (class name).
//- Different parameter lists.
//- Compiler selects based on arguments provided.
//
//This is compile-time polymorphism.
//
//------------------------------------------------------------
//RULE:
//Constructors must differ by:
//    - Number of parameters
//    OR
//    - Type of parameters
//------------------------------------------------------------
//*/
//
//#include <iostream>
//#include <string>
//
//class Product
//{
//private:
//    std::string m_name;
//    double m_price;
//
//public:
//
//    /* ----------------------------------------------------
//       1) ZERO PARAMETER (Default Constructor)
//       ---------------------------------------------------- */
//    Product()
//        : m_name("Default Product"), m_price(0.0)
//    {
//        std::cout << "Default constructor called\n";
//    }
//
//    /* ----------------------------------------------------
//       2) ONE PARAMETER
//       ---------------------------------------------------- */
//    explicit Product(const std::string& name)
//        : m_name(name), m_price(0.0)
//    {
//        std::cout << "One-parameter constructor called\n";
//    }
//
//    /* ----------------------------------------------------
//       3) TWO PARAMETERS
//       ---------------------------------------------------- */
//    Product(const std::string& name, double price)
//        : m_name(name), m_price(price)
//    {
//        std::cout << "Two-parameter constructor called\n";
//    }
//
//    void print() const
//    {
//        std::cout << "Name: " << m_name
//            << " | Price: " << m_price << "\n";
//    }
//};
//
//
///*
//============================================================
//MAIN
//============================================================
//*/
//
//int main()
//{
//    std::cout << "=== 0 Parameter ===\n";
//    Product p1;                     // calls default
//    p1.print();
//
//    std::cout << "\n=== 1 Parameter ===\n";
//    Product p2("Keyboard");          // calls 1-param
//    p2.print();
//
//    std::cout << "\n=== 2 Parameters ===\n";
//    Product p3("Mouse", 799.99);     // calls 2-param
//    p3.print();
//
//    // Product p4 = "Monitor";  // ❌ Not allowed (explicit prevents implicit conversion)
//
//    return 0;
//}
//
//
///*
//============================================================
//IMPORTANT NOTES
//============================================================
//
//1) If you define ANY constructor,
//   compiler will NOT auto-generate default constructor.
//
//2) If you still want default:
//       Product() = default;
//
//3) Prefer member initializer list (modern practice).
//
//4) Use explicit for single-argument constructors
//   to prevent unwanted implicit conversions.
//
//============================================================
//COMMON MISTAKE
//============================================================
//
//You CANNOT overload based only on return type.
//Constructors have no return type anyway.
//
//============================================================
//SUMMARY
//============================================================
//
//Constructor overloading allows:
//    Product();
//    Product(string);
//    Product(string, double);
//
//Compiler selects appropriate one
//based on arguments at object creation.
//
//============================================================
//*/