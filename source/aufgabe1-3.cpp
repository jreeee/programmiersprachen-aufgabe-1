#include <iostream>

int main()
{
	int x = 1;
	int i = 2;

	while (true) {
		while (x%i == 0) {
			if (i == 20) {
				std::cout << x"\n";
				return 0;
			}
			i++;
		}
		x++;
	}
	
}