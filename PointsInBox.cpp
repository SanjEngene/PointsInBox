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
    Box(int x, int y, int z) {
        _x = x;
        _y = y;
        _z = z;
    }

    void put_points(Point* points) {
        _points = points;
    }

    void get_together() {

        for (int i = 0; i < 2; i++) {
            if (((_points + i)->x > _z && (_points + i)->x < _z + _x) || (_points + i)->x == _z || (_points + i)->x == _z + _x) {
                if ((_points + i)->y <= _y) {
                    (_points + i)->y = (_points + i)->y + (_y - (_points + i)->y) * 2 + _z;
                    (_points + i)->z = _z;
                }
                else if (((_points + i)->y > _y && (_points + i)->y < _y + _z) || (_points + i)->y == _y + _z) {
                    (_points + i)->z = (_y + _z) - (_points + i)->y;
                    (_points + i)->y = _y + _z;
                }
                else if ((_points + i)->y > _y * 2 + _z && (_points + i)->y < _y * 2 + _z * 2) {
                    (_points + i)->z = (_points + i)->y - (_y * 2 + _z);
                    (_points + i)->y = _y * 2 + _z;
                }
                else if ((_points + i)->y == _y * 2 + _z * 2) {
                    (_points + i)->z = _z;
                    (_points + i)->y = _y * 2 + _z;
                }
            }
            else if ((_points + i)->x < _z || (_points + i)->x == 0) {
                (_points + i)->z = _z - (_points + i)->x;
                (_points + i)->x = _z;
            }
            else if (((_points + i)->x > _x + _z && (_points + i)->x < _z * 2 + _x) || (_points + i)->x == _z * 2 + _y) {
                (_points + i)->z = (_points + i)->x - (_z + _x);
                (_points + i)->x = _z + _y;
            }

            std::cout << "x: " << (_points + i)->x << " y: " << (_points + i)->y << std::endl;
        }
    }

    int get_x() {
        return _x;
    }
    int get_y() {
        return _y;
    }
    int get_z() {
        return _z;
    }

    ~Box() { }

private:
    int _x;
    int _y;
    int _z;
    Point* _points;
};

class PointsWithinBoxValidator {
public:
    PointsWithinBoxValidator(Box& box) : _box(box) { }

    bool validate(Point* points) {

        bool within = true;
        for (int i = 0; i < 2; i++) {
            if ((points + i)->x < 0 || (points + i)->x > 2 * _box.get_z() + _box.get_x()) {
                within = false;
            }
            else if ((points + i)->x >= 0 && (points + i)->x < _box.get_z()) {
                if ((points + i)->y < _box.get_y() + _box.get_z() || (points + i)->y > 2 * _box.get_y() + _box.get_z())
                    within = false;
            }
            else if ((points + i)->x > _box.get_z() + _box.get_x() && (points + i)->x <= 2 * _box.get_z() + _box.get_x()) {
                if ((points + i)->y < _box.get_y() + _box.get_z() || (points + i)->y > 2 * _box.get_y() + _box.get_z())
                    within = false;
            }
        }

        return within;
    }

    ~PointsWithinBoxValidator() { }
private:
    Box _box;
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
        Point(3.00, 3.00),
        Point(5.00, 5.00)
    };

    Box box(2, 2, 2);
    PointsWithinBoxValidator validator(box);
    if (validator.validate(points)) {
        box.put_points(points);
        box.get_together();

        Solution solution = Solution();
        solution.calculate(points[0], points[1]);
        std::cout << solution.hypotenuse;

        return 0;
    }
    
    std::cout << "points not in the box";
    return 0;
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
