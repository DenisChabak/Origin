#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

class Figure
{
protected:
    int sides_count;
    double* sides;
    double* angles;
public:
    Figure(int sides_count) : sides_count(sides_count), sides(new double[sides_count]), angles(new double[sides_count]) {
        for (int i = 0; i < sides_count; i++)
        {
            sides[i] = 0;
            angles[i] = 0;
        }
    }
    virtual ~Figure()
    {
        delete[] sides;
        delete[] angles;
    }
    virtual void display()
    {
        cout << "Фигура:\n";
        cout << (is_correct() ? "Правильная" : "Неправильная") << endl;
        cout << "  Стороны:";
        for (int i = 0; i < sides_count; i++)
        {
            cout << " " << sides[i];
        }
        cout << endl;
        cout << "  Углы:";
        for (int i = 0; i < sides_count; i++)
        {
            cout << " " << angles[i];
        }
        cout << endl;

    }
    virtual bool is_correct()
    {
        return true;
    }
};

class Triangle : public Figure
{
public:
    Triangle(double a, double b, double c) : Figure(3) { sides[0] = a; sides[1] = b; sides[2] = c; }
    ~Triangle() {}
    void display() override
    {
        cout << "Треугольник:\n";
        cout << (is_correct() ? "Правильная" : "Неправильная") << endl;
        cout << "  Стороны: " << sides[0] << ", " << sides[1] << ", " << sides[2] << endl;
        cout << "  Углы: " << angles[0] << ", " << angles[1] << ", " << angles[2] << endl;

    }
    bool is_correct() override
    {
        double sum_angles = 0;
        for (int i = 0; i < 3; i++)
        {
            angles[i] = acos((sides[(i + 2) % 3] * sides[(i + 2) % 3] + sides[(i + 1) % 3] * sides[(i + 1) % 3] - sides[i] * sides[i]) / (2 * sides[(i + 2) % 3] * sides[(i + 1) % 3]));
            sum_angles += angles[i];
        }
        return sum_angles == M_PI;
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(double a, double b) : Triangle(a, b, sqrt(a* a + b * b)) {}
    ~RightTriangle() {}
    void display() override {
        cout << "Прямоугольный треугольник:\n";
        cout << (is_correct() ? "Правильный" : "Неправильный") << endl;
        cout << "  Стороны: " << sides[0] << ", " << sides[1] << ", " << sides[2] << endl;
        cout << "  Углы: " << angles[0] << ", " << angles[1] << ", " << angles[2] << endl;

    }
    bool is_correct() override {
        angles[0] = acos(sides[0] / sides[2]);
        angles[1] = acos(sides[1] / sides[2]);
        return angles[0] + angles[1] == M_PI / 2;
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");

    Figure* fig1 = new Figure(4);
    fig1->display();
    delete fig1;

    Triangle* tri1 = new Triangle(10, 20, 30);
    tri1->display();
    delete tri1;

    RightTriangle* rtri1 = new RightTriangle(3, 4);
    rtri1->display();
    delete rtri1;

    RightTriangle* rtri2 = new RightTriangle(5, 12);
    rtri2->display();
    delete rtri2;



    return 0;
}
