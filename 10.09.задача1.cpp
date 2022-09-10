

#include <iostream>
using namespace std;



class Rect {
private: 
    double x1, y1, x2, y2;
public:
    Rect(double x1, double y1, double x2, double y2): x1(x1), y1 (y1), x2(x2), y2(y2) {}
    Rect() : x1(0), y1(0), x2(0), y2(0) {}
    Rect move(const double x, const double y) //x,y - координаты конца вектора
    {
        return Rect(x1 + x, y1 + y, x2 + x, y2 + y);
    }
    void print() 
    {
        cout << "(" << x1 << "," << y1 << "); " << "(" << x1 << "," << y2 << "); " << "(" << x2 << "," << y2 << "); " << "(" << x2 << "," << y1 << "); \n";
    }
    Rect compression(const double x, const double y) //x,y - координаты конца вектора, на который смещается верхняя правая точка
    {
        if (x1 <= x2 && y1 <= y2)
        {
            return Rect(x1, y1, x2 + x, y2 + y);
        }
        else return Rect(x1 + x, y1 + y, x2, y2);
    }
    Rect normal() 
    {
        if (x1 <= x2 && y1 <= y2)
        {
            return Rect(x1,y1,x2,y2);
        }
        else return Rect(x2,y2,x1,y1);
    }
    Rect cover(Rect Rect1, Rect Rect2)
    {
        Rect1 = Rect1.normal();
        Rect2 = Rect2.normal();
        return Rect(min(Rect1.x1, Rect2.x1), min(Rect2.y1, Rect1.y1), max(Rect1.x2, Rect2.x2), max(Rect2.y2, Rect1.y2));
    }
    Rect cross(Rect Rect1, Rect Rect2)
    {
        Rect1 = Rect1.normal();
        Rect2 = Rect2.normal();
        if (max(Rect1.x1, Rect2.x1) < min(Rect1.x2, Rect2.x2) && max(Rect2.y1, Rect1.y1) < min(Rect2.y2, Rect1.y2)) {
            return Rect(max(Rect1.x1, Rect2.x1), max(Rect2.y1, Rect1.y1), min(Rect1.x2, Rect2.x2), min(Rect2.y2, Rect1.y2));
        }
        else return Rect(0, 0, 0, 0);
    }
};

int main()
{
    double x1, y1, x2, y2, x, y, x0, y0;
    cin >> x1 >> y1 >> x2 >> y2;
    Rect rect(x1, y1, x2, y2);//создали первый
    rect.print();//тест печати
    cin >> x >> y;//вектор сдвига
    rect = rect.move(x, y);
    rect.print();//тест сдвига
    cin >> x0 >> y0;//вектор изменения
    rect = rect.compression(x0, y0);
    rect.print();//тест изменения
    double x10, y10, x20, y20;
    cin >> x10 >> y10 >> x20 >> y20;
    Rect rect1(x10, y10, x20, y20);//создали второй для теста пересечения с первым
    rect = rect.cross(rect, rect1);
    rect.print();//тест пересечения
    cin >> x1 >> y1 >> x2 >> y2;
    Rect rect2(x1, y1, x2, y2);//создали первый для теста накрывающего
    cin >> x10 >> y10 >> x20 >> y20;
    Rect rect3(x10, y10, x20, y20);//создали второй для теста накрытия
    rect = rect.cover(rect2, rect3);
    rect.print();//тест накрытия
}

