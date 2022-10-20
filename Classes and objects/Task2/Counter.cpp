#include <iostream>
#include <string>
#include <fstream> 
#include <stdexcept>



class Counter
{
private:
	int count = 1;

public:

	int get_count()
	{
		count = 1;
		return count;
	}

	int set_count(int number)
	{
		this->count = number;
		return count;
	}
	int adder()
	{
		count++;
		return count;
	}

	int subtracter()
	{
		count--;
		return count;
	}

	void show()
	{
		std::cout << count << std::endl;
	}

	void exit()
	{
		std::cout << "До свидания!" << std::endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");

	Counter num;
	int number;
	char command;
	std::string answer;
	std::cout << "Вы хотите указать начальное значение счётчика? Введите 'yes'' или 'no': ";
	std::cin >> answer;
	if (answer == "yes")
	{
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> number;
		num.set_count(number);
	}
	else
	{
		num.get_count();
	}

	while (true)
	{

		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> command;
		if (command == '+')
		{
			num.adder();
		}
		else if (command == '-')
		{
			num.subtracter();
		}
		else if (command == '=')
		{
			num.show();
		}
		else if (command == 'x')
		{
			num.exit();
			break;
		}
		else
		{
			std::cout << "Пожалуйста, вводите только '+', '-', '=' или 'x'" << std::endl;
		}
	}


	return 0;
}

