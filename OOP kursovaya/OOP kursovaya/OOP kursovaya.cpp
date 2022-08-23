#include <iostream>
#include <cmath>
#include <Windows.h>
#include <vector>

using namespace std;

void RussianLocalization() {
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);// Вывод на консоль в кодировке 1251. 
    //Нужно будет только изменить шрифт консоли на Lucida Console или Consolas
    setlocale(LC_ALL, "rus");
}

class Vector 
{
    int x, y, z;
public:
    Vector(int x1, int y1, int z1) : x(x1) , y(y1), z(z1) {}
    Vector() {}
    int get_x() { return x; };
    int get_y() { return y; };
    int get_z() { return z; };
    void operation1(Vector a, Vector b) 
    {
        int x, y, z;
        x = a.get_x() + b.get_x();
        y = a.get_y() + b.get_y();
        z = a.get_z() + b.get_z();
        cout << "Вектор, получившийся при сложении векторов <<a>> и <<b>>: x = " << x << "; y = " << y << "; z = " << z << endl;
    }
    void operation2(Vector a, Vector b)
    {
        int x, y, z;
        x = a.get_x() - b.get_x();
        y = a.get_y() - b.get_y();
        z = a.get_z() - b.get_z();
        cout << "Вектор, получившийся при разности векторов <<a>> и <<b>>: x = " << x << "; y = " << y << "; z = " << z << endl;
    }
    void operation3(int a, Vector b) 
    {
        cout << "Вектор, домноженный на введенное число: x = " << a * b.get_x() << "; y = " << a * b.get_y() << "; z = " << a * b.get_z() << endl;
    }
    void operation4(int a, Vector b)
    {
        cout << "Вектор, поделенный на введенное число: x = " << b.get_x() / a << "; y = " << b.get_y() / a << "; z = " << b.get_z() / a << endl;
    }
    int operation5(Vector a)
    {
        int vec_length;
        vec_length = sqrt(pow(a.get_x(), 2) + pow(a.get_y(), 2) + pow(a.get_z(), 2));
        return vec_length;
    }
    int operation6(Vector a, Vector b)
    {
        int scalar;
        scalar = a.get_x() * b.get_x() + a.get_y() * b.get_y() + a.get_z() * b.get_z();
        return scalar;
    }
    void operation7(Vector a, Vector b)
    {
        if (operation6(a, b) == 0)
        {
            cout << "Два выбранных вектора ортогональны" << endl;
        }
        else cout << "Два выбранных вектора не ортогональны" << endl;
    }
    Vector operation8(Vector a, Vector b)
    {
        int x, y, z;
        x = a.get_y() * b.get_z() - a.get_z() * b.get_y();
        y = a.get_z() * b.get_x() - a.get_x() * b.get_z();
        z = a.get_x() * b.get_y() - a.get_y() * b.get_x();
        return Vector(x, y, z);
    }
    void operation9(Vector a, Vector b) {
        int x, x2, y, y2, z, z2;
        Vector c(0, 0, 0);
        x = a.get_x();
        y = a.get_y();
        z = a.get_z();
        x2 = b.get_x();
        y2 = b.get_y();
        z2 = b.get_z();
        if (x == 0 or y == 0 or z == 0 or x2 == 0 or y2 == 0 or z2 == 0)
        {
            c = operation8(a, b);
            if (c.get_x() == 0 and c.get_y() == 0 and c.get_z() == 0)
            {
                cout << "Векторы коллинеарны" << endl;
            }
            else cout << "Векторы не коллинеарны" << endl;
        }
        else
        {
            if (x / x2 == y / y2 and x / x2 == z / z2)
            {
                cout << "Векторы коллинеарны" << endl;
            }
            else cout << "Векторы не коллинеарны" << endl;
        }
    }
    int operation10(Vector a, Vector b, Vector c)
    {
        int opr_plus, opr_minus;
        opr_plus = a.get_x() * b.get_y() * c.get_z() + a.get_y() * 
            b.get_z() * c.get_x() + a.get_z() * b.get_x() * c.get_y();
        opr_minus = -1 * (a.get_z() * b.get_y() * c.get_x()) - 1 * 
            (a.get_x() * b.get_z() * c.get_y()) - 1 * (a.get_y() * b.get_x() * c.get_z());
        return opr_plus + opr_minus;
    }
    void operation11(Vector a, Vector b, Vector c)
    {
        if (operation10(a, b, c) == 0)
        {
            cout << "Векторы компланарны" << endl;
        }
        else cout << "Векторы не компланарны" << endl;
    }
    void operation12(Vector a, Vector b)
    {
        int cosinus;
        cosinus = operation6(a, b) / (operation5(a) * operation5(b));
        cout << "косинус угла между векторами = " << cosinus << endl;
    }
};

auto two_vectors_init()
{
    int x, y, z;
    cout << "Введите координаты 2х векторов:\n";
    cout << " Вектор <<a>>:\n";
    cout << "\tx = ";
    cin >> x;
    cout << "\ty = ";
    cin >> y;
    cout << "\tz = ";
    cin >> z;
    Vector a(x, y, z);
    cout << " Вектор <<b>>:\n";
    cout << "\tx = ";
    cin >> x;
    cout << "\ty = ";
    cin >> y;
    cout << "\tz = ";
    cin >> z;
    Vector b(x, y, z);
    Vector vec_list[2] = { a,b };
    return vec_list;
}

void programm()
{
    RussianLocalization();
    int ans;
    Vector* obj = nullptr;
    while (true)
    {
        cout << "Выберите действие:" << endl;
        cout << "\t1.  Сложение векторов \n";
        cout << "\t2.  Разность векторов\n";
        cout << "\t3.  Умножение вектора на число\n";
        cout << "\t4.  Деление вектора на число\n";
        cout << "\t5.  Длина вектора по модулю\n";
        cout << "\t6.  Скалярное произведение векторов\n";
        cout << "\t7.  Ортогональность векторов\n";
        cout << "\t8.  Векторное произведение\n";
        cout << "\t9.  Коллинеарность векторов\n";
        cout << "\t10. Смешанное произведение векторов\n";
        cout << "\t11. Компланарность векторов\n";
        cout << "\t12. Угол между векторами\n";
        cout << "\t13. Выход из программы\n";
        cin >> ans;
        if (ans == 1)
        {
            Vector* vec_list = two_vectors_init();
            obj->operation1(vec_list[0], vec_list[1]);
        }
        if (ans == 2)
        {
            Vector* vec_list = two_vectors_init();
            obj->operation2(vec_list[0], vec_list[1]);
        }
        if (ans == 3)
        {
            int x, y, z, d;
            cout << "Введите координаты вектора:\n";
            cout << " Вектор <<a>>:\n";
            cout << "\tx = ";
            cin >> x;
            cout << "\ty = ";
            cin >> y;
            cout << "\tz = ";
            cin >> z;
            Vector a(x, y, z);
            cout << "Введите число, на которое необходимо домножить вектор: ";
            cin >> d;
            obj->operation3(d, a);
        }
        if (ans == 4)
        {
            int x, y, z, d;
            cout << "Введите координаты вектора:\n";
            cout << " Вектор <<a>>:\n";
            cout << "\tx = ";
            cin >> x;
            cout << "\ty = ";
            cin >> y;
            cout << "\tz = ";
            cin >> z;
            Vector a(x, y, z);
            cout << "Введите число, на которое необходимо поделить вектор: ";
            cin >> d;
            if (d == 0)
            {
                cout << "Делить на ноль нельзя! Введите любое другое число." << endl;
            }
            else obj->operation4(d, a);
        }
        if (ans == 5)
        {
            int x, y, z;
            cout << "Введите координаты вектора:\n";
            cout << " Вектор <<a>>:\n";
            cout << "\tx = ";
            cin >> x;
            cout << "\ty = ";
            cin >> y;
            cout << "\tz = ";
            cin >> z;
            Vector a(x, y, z);
            cout << "Длина вектора <<a>> = " << obj->operation5(a) << endl;
        }
        if (ans == 6)
        {
            Vector* vec_list = two_vectors_init();
            cout << "Скалярное произведение векторов <<a>> и <<b>> = " << obj->operation6(vec_list[0], vec_list[1]) << endl;
        }
        if (ans == 7)
        {
            Vector* vec_list = two_vectors_init();
            obj->operation7(vec_list[0], vec_list[1]);
        }
        if (ans == 8)
        {
            Vector* vec_list = two_vectors_init();
            Vector c = obj->operation8(vec_list[0], vec_list[1]);
            cout << "Вектор полученный в результате произведения вектора <<a>> на вектор <<b>>: X = " << c.get_x() << "; Y = " << c.get_y() << "; Z = " << c.get_z() << endl;
        }
        if (ans == 9)
        {
            Vector* vec_list = two_vectors_init();
            obj->operation9(vec_list[0], vec_list[1]);
        }
        if (ans == 10)
        {
            int x, y, z;
            cout << "Введите координаты 3х векторов:\n";
            Vector* vec_list = two_vectors_init();
            cout << " Вектор <<c>>:\n";
            cout << "\tx = ";
            cin >> x;
            cout << "\ty = ";
            cin >> y;
            cout << "\tz = ";
            cin >> z;
            Vector c(x, y, z);
            cout << "Смешанное произведение векторов <<a>>, <<b>>, <<c>> = " << obj->operation10(vec_list[0], vec_list[1], c) << endl;
        }
        if (ans == 11)
        {
            int x, y, z;
            cout << "Введите координаты 3х векторов:\n";
            Vector* vec_list = two_vectors_init();
            cout << " Вектор <<c>>:\n";
            cout << "\tx = ";
            cin >> x;
            cout << "\ty = ";
            cin >> y;
            cout << "\tz = ";
            cin >> z;
            Vector c(x, y, z);
            obj->operation11(vec_list[0], vec_list[1], c);
        }
        if (ans == 12)
        {
            Vector* vec_list = two_vectors_init();
            obj->operation12(vec_list[0], vec_list[1]);
        }
        if (ans == 13)
        {
            break;
        }
    }
}

int main()
{
    programm();
    return 0;
}
