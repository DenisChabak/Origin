#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count;
    std::string name;
public:
    Figure() : sides_count(0), name("Фигура") {}
    int get_sides_count() const { return sides_count; }
    std::string get_name() const { return name; }
};

class Triangle : public Figure {
public:
    Triangle() : Figure() {
        sides_count = 3;
        name = "Треугольник";
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral() : Figure() {
        sides_count = 4;
        name = "Четырёхугольник";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Figure fig;
    Triangle tri;
    Quadrilateral quad;
    std::cout << "Количество сторон:\n"
        << fig.get_name() << ": " << fig.get_sides_count() << '\n'
        << tri.get_name() << ": " << tri.get_sides_count() << '\n'
        << quad.get_name() << ": " << quad.get_sides_count() << '\n';
    return 0;
}
