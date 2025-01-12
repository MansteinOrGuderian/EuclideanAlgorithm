#include "Header.h"

int main() {
	//Euclidean_Algorithm_Info();
	Extended_Euclidean_Algorithm_Info();
	long long int first_number(0), second_number(0);
	std::cout << "Enter numbers\n";
	std::cin >> first_number >> second_number;
	std::cout << Extended_Euclidean_Algorithm(first_number, second_number);
	//
	//
	//
	//
	return 0;
}