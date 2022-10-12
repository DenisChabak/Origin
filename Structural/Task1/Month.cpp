#include <iostream>

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");

    enum Month 
    {January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, 
     August = 8, September = 9, October = 10, November = 11, December = 12,};
    
        int select;
        do
        {
            std::cout << " Введите номер месяца: ";
            std::cin >> select;
        
        switch (select)
        {
        case 0:
            std::cout << " До свидания" << std::endl;
            break;
        case static_cast <int> (January):
            std::cout << " Январь" << std::endl;
            break;
        case static_cast <int> (February):
            std::cout << " Февраль" << std::endl;
            break;
        case static_cast <int> (March):
            std::cout << " Март" << std::endl;
            break;
        case static_cast <int> (April):
            std::cout << " Апрель" << std::endl;
            break;
        case static_cast <int> (May):
            std::cout << " Май" << std::endl;
            break;
        case static_cast <int> (June):
            std::cout << " Июнь" << std::endl;
            break;
        case static_cast <int> (July):
            std::cout << " Июль" << std::endl;
            break;
        case static_cast <int> (August):
            std::cout << " Август" << std::endl;
            break;
        case static_cast <int> (September):
            std::cout << " Сентябрь" << std::endl;
            break;
        case static_cast <int> (October):
            std::cout << " Октябрь" << std::endl;
            break;
        case static_cast <int> (November):
            std::cout << " Ноябрь" << std::endl;
            break;
        case static_cast <int> (December):
            std::cout << " Декабрь" << std::endl;
            break;
        default:
            std::cout << " Неправильный номер!" << std::endl;
        }
        } while (select > 0);
    return 0;
}

