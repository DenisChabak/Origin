#include <iostream>
#include <cmath>

class Shape {
public:
    virtual void print_info() const = 0;
};

class Triangle : public Shape {
public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}
    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    virtual void print_info() const {
        std::cout << "Треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }
private:
    double a, b, c, A, B, C;
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) {}
    virtual void print_info() const {
        std::cout << "Прямоугольный треугольник:\n";
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << "\n";
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=90\n";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double c, double A)
        : Triangle(a, b, c, A, (180 - A) / 2, (180 - A) / 2) {}
    virtual void print_info() const {
        std::cout << "Равнобедренный треугольник:\n";
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << "\n";
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << "\n";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a)
        : Triangle(a, a, a, 60, 60, 60) {}
    virtual void print_info() const {
        std::cout << "Равносторонний треугольник:\n";
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << "\n";
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << "\n";
    }
};

class Quadrilateral : public Shape {
public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}
    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }
    virtual void print_info() const {
        std::cout << "Четырёхугольник:\n";
        std::cout << "Строны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
private:
    double a, b, c, d, A, B, C, D;
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}
    virtual void print_info() const {
        std::cout << "Прямоугольник:\n";
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << "\n";
        std::cout << "углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << "\n";
    }
};

class Square : public Rectangle {
public:
    Square(double a)
        : Rectangle(a, a) {}
    virtual void print_info() const {
        std::cout << "Квадрат:\n";
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << "\n";
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << "\n";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A)
        : Quadrilateral(a, b, a, b, A, 180 - A, A, 180 - A) {}
    virtual void print_info() const {
        std::cout << "Параллелограмм:\n";
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << "\n";
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << "\n";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double A)
        : Parallelogram(a, a, A) {}
    virtual void print_info() const {
        std::cout << "Ромб:\n";
        std::cout << "Строны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << "\n";
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << "\n";
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian");

    Triangle t(3, 4, 5, 90, 53.13, 36.87);
    t.print_info();

    RightTriangle rt(3, 4, 5, 90, 53.13);
    rt.print_info();
       
    IsoscelesTriangle it(3, 3, 4, 72.54);
    it.print_info();
        
    EquilateralTriangle et(5);
    et.print_info();
    
    Quadrilateral q(2, 4, 3, 5, 30, 70, 110, 150);
    q.print_info();
        
    Rectangle r(5, 7);
    r.print_info();
        
    Square s(6);
    s.print_info();

    return 0;
}