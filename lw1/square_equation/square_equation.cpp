#include <cstdio>
#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Please enter a, b and c for `ax^2 + bc + c = 0`: ";

    float a = 0;
    float b = 0;
    float c = 0;

    std::scanf("%f %f %f", &a, &b, &c);

    float d = (b * b) - (4 * a * c);

    float x1 = 0;
    float x2 = 0;

    if (d < 0)
    {
        std::cout << "no roots" << std::endl;
        return 0;
    }

    if (d == 0)
    {
        x1 = (-b + std::sqrt(d)) / (2 * a);
        std::cout << "x1, x2: " << x1 << std::endl;
        return 0;
    }

    if (d > 0)
    {
        x1 = (-b + std::sqrt(d)) / (2 * a);
        x2 = (-b - std::sqrt(d)) / (2 * a);
        std::cout << "x1: " << x1 << " x2: " << x2 << std::endl;
        return 0;
    }

    return 1;
}