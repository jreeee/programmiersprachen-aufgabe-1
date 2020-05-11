#include <iostream>
#include <string>

double mtk(double mile_)
{
    const double FACTOR = 1.609344;
    double res_ = FACTOR * mile_;
     if (res_ >= 0) return res_;
     return -1;
}

int main()
{
    bool loop_ = true;
    while (loop_) {
        std::cout << "Please enter the number of miles you want to convert into kilometers\n";
        double num_ = 0;
        std::cin >> num_;
        num_ = mtk(num_);
        if (num_ == -1) {
            std::cout << "You entered a negative number\n";
        }
        std::cout << "The amount equivalent is " << num_ << "km\n";
        std::cout << "\nTo try out another number press [y/Y/0], press any other key to close.\n";
        char again_ = 'f';
        std::cin >> again_;
        if ((again_ != 'y') && (again_ != 'Y') && (again_ != '0')) loop_ = false;
    }
    std::cout << "Goodbye\n";
    return 0;
}
