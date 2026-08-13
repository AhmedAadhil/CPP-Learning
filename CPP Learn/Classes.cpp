///*
//============================================================
//CLASSES IN C++ (C++20)
//Declaration | Syntax | Access Specifiers
//Difference Between struct and class
//When To Use Each
//============================================================
//
//------------------------------------------------------------
//1) WHAT IS A CLASS?
//------------------------------------------------------------
//
//- User-defined type.
//- Combines:
//    * Data (variables)
//    * Behavior (functions)
//- Supports encapsulation.
//
//Syntax:
//
//    class ClassName
//    {
//        // members
//    };
//
//NOTE:
//- Semicolon after closing brace is mandatory.
//
//------------------------------------------------------------
//2) ACCESS SPECIFIERS
//------------------------------------------------------------
//
//private:     (default in class)
//    - Accessible only inside the class.
//
//public:
//    - Accessible from outside.
//
//protected:
//    - Used in inheritance (later topic).
//
//------------------------------------------------------------
//3) BASIC CLASS EXAMPLE
//------------------------------------------------------------
//*/
//
//#include <iostream>
//#include <string>
//
//class Car
//{
//private:
//    std::string m_brand;     // naming convention: m_ for member variable
//    int m_speed;
//
//public:
//    // Constructor
//    Car(const std::string& brand, int speed)
//    {
//        m_brand = brand;
//        m_speed = speed;
//    }
//
//    // Public method
//    void accelerate(int amount)
//    {
//        m_speed += amount;
//    }
//
//    void print() const
//    {
//        std::cout << "Brand: " << m_brand
//            << " | Speed: " << m_speed << "\n";
//    }
//
//    // Getter (controlled access)
//    int getSpeed() const
//    {
//        return m_speed;
//    }
//};                     // if u need immediate object delcartion you can specify before semi-colon like  } Car1,Car2;
//
//
///*
//------------------------------------------------------------
//4) STRUCT VS CLASS
//------------------------------------------------------------
//
//Primary Difference:
//
//struct:
//    - Default access = public
//
//class:
//    - Default access = private
//
//That is the ONLY technical difference.
//
//Everything else (functions, constructors, inheritance)
//works exactly the same.
//
//------------------------------------------------------------
//5) STRUCT EXAMPLE
//------------------------------------------------------------
//*/
//
//struct Point
//{
//    // Default is public
//    int x;
//    int y;
//
//    void print() const
//    {
//        std::cout << "Point(" << x << ", " << y << ")\n";
//    }
//};
//
//
///*
//------------------------------------------------------------
//6) WHEN TO USE struct VS class
//------------------------------------------------------------
//
//Use struct when:
//    - It is just a data structure.
//    - No heavy logic.
//    - All members can be public.
//    - Example: coordinates, config data, packets.
//
//Use class when:
//    - You need encapsulation.
//    - Data should not be directly modified.
//    - Business logic involved.
//    - You want invariants protected.
//
//Modern Convention:
//
//    struct → passive data
//    class  → behavior + logic + protection
//
//------------------------------------------------------------
//7) MAIN FUNCTION
//------------------------------------------------------------
//*/
//
//int main()
//{
//    std::cout << "=== Class Example ===\n";
//
//    Car car("BMW", 120);	
//    car.print();
//
//    car.accelerate(30);
//    car.print();
//
//    std::cout << "Speed via getter: "
//        << car.getSpeed() << "\n";
//
//
//    std::cout << "\n=== Struct Example ===\n";
//
//    Point p{ 10, 20 };   // aggregate initialization
//    p.print();
//
//    // Direct access allowed (public by default)
//    p.x = 50;
//    p.print();
//
//    return 0;
//}
//
//
///*
//============================================================
//IMPORTANT WARNINGS
//============================================================
//
//1) In class:
//       Members are PRIVATE by default.
//
//2) In struct:
//       Members are PUBLIC by default.
//
//3) Always prefer private members + public methods
//   for real-world systems.
//
//4) Use const after member function if it does not
//   modify object state.
//
//       void print() const;
//
//5) Encapsulation prevents invalid states.
//
//
//============================================================
//ADVANCED AWARENESS
//============================================================
//
//- class and struct have identical memory layout rules.
//- Both support:
//      constructors
//      destructors
//      inheritance
//      templates
//      operator overloading
//
//Difference is semantic + design intent.
//
//============================================================
//SUMMARY
//============================================================
//
//struct  → data holder
//class   → protected logic-driven object
//
//In modern C++:
//    Prefer class for OOP design.
//    Use struct for plain data models.
//
//============================================================
//*/