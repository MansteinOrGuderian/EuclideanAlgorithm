#include "Header.h"

int main() {
	std::cout << "Hello! What you what to calculate today?\n";
	std::cout << "Enter '0', to use Euclidean Algorithm\nEnter '1', to use Extended Euclidean Algorithm\n";
	bool variant;
	std::cin >> variant;
	switch (variant) {
	case 0: {
		Euclidean_Algorithm_Info();
		long long int first_number(0), second_number(0);
		std::cout << "Enter numbers\n";
		std::cin >> first_number >> second_number;
		std::cout << Euclidean_Algorithm(first_number, second_number);
	}
	case 1: {
		Extended_Euclidean_Algorithm_Info();
		long long int first_number(0), second_number(0);
		std::cout << "Enter numbers\n";
		std::cin >> first_number >> second_number;
		Extended_Euclidean_Algorithm(first_number, second_number);
	}
	default: {
		std::cout << "No such variant. Restart program\n";
		break; 
	}
	}
	return 0;
}