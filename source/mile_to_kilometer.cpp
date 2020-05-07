#include <iostream>
#include <string>

double mtk(double mile)
{
    const double FACTOR = 1.609344;
    double res = FACTOR * mile;
     if (res >= 0) return res;
     return -1;
}

int main()
{
    bool loop = true;
    while (loop) {
        std::cout << "Please enter the number of miles you want to convert into kilometers\n";
        double num = 0;
        std::cin >> num;
        num = mtk(num);
        if (num == -1) {
            std::cout << "You entered a negative number\n";
        }
        std::cout << "The amount equivalent is " << num << "km\n";
        std::cout << "\nTry a different number[0] or quit[any other number]\n";
        int play = 0;
        std::cin >> play;
        if (play != 0) loop = false;
    }
    std::cout << "Goodbye\n";
    return 0;
}
