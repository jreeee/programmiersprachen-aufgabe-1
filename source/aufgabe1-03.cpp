#include <iostream>

int main()
{
	int number_ = 1;
	int counter_ = 2;

	while (true) {
		while (number_%counter_ == 0) {
			if (counter_ == 20) {
				std::cout << number_ << std::endl;
				return 0;
			}
			counter_++;
		}
		number_++;
		counter_ = 1;
	}
	
}
