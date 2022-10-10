#include <iostream>

struct Country
{
    std::string m_city;
    std::string m_street;
    int m_hous;
    int m_flat;
    int m_index;

};

void InCountry(Country &p)
{
    std::cout << "Город: ";
    std::cin >> p.m_city;
    std::cout << "Улица: ";
    std::cin >> p.m_street;
    std::cout << "Номер дома: ";
    std::cin >> p.m_hous;
    std::cout << "Номер квартиры: ";
    std::cin >> p.m_flat;
    std::cout << "Индекс: ";
    std::cin >> p.m_index;
}

void print(Country &p)
{
    std::cout << "Город: " << p.m_city << std::endl;
    std::cout << "Улица: " << p.m_street << std::endl;
    std::cout << "Номер дома: " << p.m_hous << std::endl;
    std::cout << "Номер квартиры: " << p.m_flat << std::endl;
    std::cout << "Индекс: " << p.m_index << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    Country m;
    Country k;

    InCountry(m);
    InCountry(k);
    print(m);
    print(k);




    return 0;
}

