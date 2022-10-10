#include <iostream>

struct Person
{
    int m_number;
    std::string m_firstname;
    float m_balance;
    float m_newbalance;
};

void changeBalance(Person p)
{
    std::cout << "Введите номер счёта: ";
    std::cin >> p.m_number;
    std::cout << "\n" << "Введите имя владельца: ";
    std::cin >> p.m_firstname;
    std::cout << "\n" << "Введите баланс: ";
    std::cin >> p.m_balance;
    std::cout << "\n" << "Введите новый баланс: ";
    std::cin >> p.m_newbalance;
    std::cout << "Ваш счёт: " << p.m_firstname << " " << p.m_number << " " << p.m_newbalance;
}



int main(int argc, char** argv)
{

    setlocale(LC_ALL, "Rus");
        
    Person p;
    
    changeBalance(p);
    
    return 0;
    
}
