#include <bits/stdc++.h>
using namespace std;

int a, b, c;

bool if_it_triangle()
{
    if (a + b <= c)
        return false;
    if (a + c <= b)
        return false;
    if (b + c <= a)
        return false;
    return true;
}

void triangle_type()
{
    if (a == b && b == c)
    {
        cout << "等边三角形" << ' ';
    }
    else if (a == b || a == c || b == c)
    {
        cout << "等腰三角形" << ' ';
    }
    else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
    {
        cout << "直角三角形" << ' ';
    }
    else
    {
        cout << "普通三角形" << ' ';
    }
}

double triangle_area()
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    system("chcp 65001");
    cin >> a >> b >> c;

    if (!if_it_triangle())
    {
        cout << "No right triangle!!";
        return 0;
    }
    triangle_type();
    cout << "its area is : " << triangle_area() << endl;
    return 0;
}
