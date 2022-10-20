#include <iostream>
#include <string>

class Calculator
{
public:
	float Num1;
	float Num2;

		double add(float Num1, float Num2)
		{
			std::cout << "Num1 + Num2 = " << Num1 + Num2 << std::endl;
			return Num1 + Num2;
		}

		double multiply(float Num1, float Num2)
		{
			std::cout << "Num1 * Num2 = " << Num1 * Num2 << std::endl;
			return Num1 * Num2;
		}

		double subtract_1_2(float Num1, float Num2)
		{
			std::cout << "Num1 - Num2 = " << Num1 - Num2 << std::endl;
			return Num1 - Num2;
		}

		double subtract_2_1(float Num1, float Num2)
		{
			std::cout << "Num2 - Num1 = " << Num2 - Num1 << std::endl;
			return Num2 - Num1;
		}

		double divide_1_2(float Num1, float Num2)
		{
			std::cout << "Num1 / Num2 = " << Num1 / Num2 << std::endl;
			return Num1 / Num2;
		}

		double divide_2_1(float Num1, float Num2)
		{
			std::cout << "Num2 / Num1 = " << Num2 / Num1 << std::endl;
			return Num2 / Num1;
		}

		bool set_num1(double Num1)
		{
			this->Num1 = Num1;
			if (Num1 == 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			
		}

		bool set_num2(double Num2)
		{
			this->Num2 = Num2;
			if (Num2 == 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}

		}
	
};


int main()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{


		float Num1, Num2;
		Calculator Num;

		Input:
		std::cout << "Введите Num1: ";
		std::cin >> Num1;

		if (!Num.set_num1(Num1))
		{
			std::cout << "Неверный ввод!" << std::endl;
			goto Input;
		}

		Input2:
		std::cout << "Введите Num2: ";
		std::cin >> Num2;

		if (!Num.set_num2(Num2))
		{
			std::cout << "Неверный ввод!" << std::endl;
			goto Input2;
		}
					
		
		Num.add(Num1, Num2);
		Num.multiply(Num1, Num2);
		Num.subtract_1_2(Num1, Num2);
		Num.subtract_2_1(Num1, Num2);
		Num.divide_1_2(Num1, Num2);
		Num.divide_2_1(Num1, Num2);
		

	}
}

