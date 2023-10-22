#include <iostream>
#include <fstream>
#include <limits>
#include <cmath>

//дифференцируемая функция
template <typename T>
T u(T x) {return std::sin(x);}

//производная функции
template <typename T>
T du(T x) {return std::cos(x);}

//численное дифференцирование с шагом h
template <typename T>
T Du(T x, T h)
{return (u(x+h)-u(x))/h;}

//вычисление ошибки
template <typename T>
T err(T v_true, T v_pred)
{return 1-v_true/v_pred;}

int main()
{
    std::ofstream file("output.txt");
    file << "h\terr\n";

    double x0 = 1, h;
    for (int k = 3; k >= -3; k -= 1)
    {
        h = std::pow(std::numeric_limits<double>::epsilon(), 1.0/2)*std::pow(10.0, k);
        file << h << "\t" << err(du(x0), Du(x0, h)) << "\n";
    }

    file.close();
    return 0;
}