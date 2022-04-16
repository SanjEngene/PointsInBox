// PointsInBox.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

struct Point {
public:
    double x;
    double y;
    double z;

    Point(double x, double y) : x(x), y(y), z(0) { }
};

class Box {
public:
    int x;
    int y;
    int z;

    Box(int x, int y, int z) : x(x), y(y), z(z) { }

    void get_together(Point* points) {

        for (int i = 0; i < 2; i++) {
            if (((points + i)->x > z && (points + i)->x < z + x) || (points + i)->x == z || (points + i)->x == z + x) {
                if ((points + i)->y <= y) {
                    (points + i)->y = (points + i)->y + (y - (points + i)->y) * 2 + z;
                    (points + i)->z = z;
                }
                else if ((points + i)->y > y && (points + i)->y < y + z && (points + i)->y == y + z) {
                    (points + i)->z = (y + z) - (points + i)->y;
                    (points + i)->y = y + z;
                }
                else if ((points + i)->y > y * 2 + z && (points + i)->y < y * 2 + z * 2) {
                    (points + i)->z = (points + i)->y - (y * 2 + z);
                    (points + i)->y = y * 2 + z;
                }
                else if ((points + i)->y == y * 2 + z * 2) {
                    (points + i)->z = z;
                    (points + i)->y = y * 2 + z;
                }
            }
            else if ((points + i)->x < z || (points + i)->x == 0) {
                (points + i)->z = z - (points + i)->x;
                (points + i)->x = z;
            }
            else if (((points + i)->x > x + z && (points + i)->x < z * 2 + x) || (points + i)->x == z * 2 + y) {
                (points + i)->z = (points + i)->x - (z + x);
                (points + i)->x = z + y;
            }
        }
    }

    ~Box() { }
};

class Solution {
public:
    double hypotenuse;

    Solution() { 
        hypotenuse = 0;
    }

    void calculate(Point a, Point b) {
        this->hypotenuse = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2));
    }

    ~Solution() { }
};
int main()
{
    Point points[] = {
        Point(2, 4),
        Point(8, 10)
    };

    Box box(6, 4, 2);
    box.get_together(points);
    
    Solution solution = Solution();
    solution.calculate(points[0], points[1]);
    std::cout << solution.hypotenuse;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
