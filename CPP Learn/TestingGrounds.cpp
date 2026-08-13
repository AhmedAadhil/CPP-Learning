#include <iostream>

//enum class MyEnum
//{
//	A=1,
//	B=2
//};

//enum class Colors
//{
//	Red=1,Blue,Green
//};

void printArray(int arr[], int size);
//int factorial(int n);


class AbstractEmployee {
	virtual void AddBonus()=0;
};


class Employee:AbstractEmployee
{	
	public:
		std::string name;

		void empDetails()
		{
			std::cout << name << "\n";
			std::cout << getBalance() << "\n";
		}
		Employee(std::string name)
		{
			this->name = name;
		}
		void setBalance(int amount)
		{
			if (amount < 0) {
				bankBalance = 0;
			}
			else
			{
				bankBalance = amount;
			}

		}	
		int getBalance()
		{
			return bankBalance;
		}
		virtual void AddBonus() {
			if (bankBalance < 100) {
				bankBalance += 10;
			}
		}
	protected :
		int globalId = 100;
	private:
		int bankBalance;
};

class Developer:public Employee {
	public:
		std::string language;
		Developer(std::string name,std::string language):Employee(name)	
		{
			this->name = name;
			this->language = language;
		}
		void testProtected()
		{
			std::cout << "Global ID : " << globalId << "\n";
		}
		void devDetails()
		{
			std::cout << name << "\n";
			//std::cout << getBalance() << "\n";
			std::cout << "Language : " << this->language << "\n";
		}
};

int main()
{
	//enum MyEnum var = B;
	//std::cout << var << "\n";
	//Colors redColor = Colors::Red;
	//std::cout << (int)redColor << "\n";

	//int array[5] = {10,20,30,40,50};
	//int size = sizeof(array) / sizeof(int);
	//printArray(array, size);
	Employee emp1("John Helldiver"); // or Employee emp1 = Employee("ABC");
	Employee emp2("McGregor");
	emp1.setBalance(100);
	emp2.setBalance(50);
	emp1.AddBonus();
	emp2.AddBonus();
;	emp1.empDetails();
	emp2.empDetails();
	std::cout << "=============" << "\n";
	Developer d1=Developer("Alpha", "C++");
	d1.setBalance(99);
	d1.AddBonus();
	d1.empDetails();
	d1.devDetails();
	d1.testProtected();
	//polymorphism : Example
	//create pointer for two objects of a class
	Employee *e1 = &emp1;
	Employee* e2 = &emp2;
	// access object methods using  ->
	std::cout << "=============" << "\n";
	e1->empDetails();
	e2->empDetails();
	return 0;
}

//int factorial(int n)
//{
//	if (n > 0)
//	{
//		return n * factorial(n - 1);
//	}
//	return 1;
//}

void printArray(int arr[], int size)
{
	int *ptr = arr;
	for (int i = 0; i < size; i++)
	{
		std::cout << *ptr << "\n";
		ptr += 1;
	}
}

