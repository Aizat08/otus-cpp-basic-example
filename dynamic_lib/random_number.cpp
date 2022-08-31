#include <iostream>
#include <cstdlib>
#include <ctime>
#include "random_number.h"


void random_guess(int &attempts){

	const int max_value = 100;

	std::srand(std::time(nullptr)); 

	const int target_value = std::rand() % 100;

	int current_value = 0;
	
	std::cout << "Enter your guess:" << std::endl;
     
	do {
		std::cin >> current_value;
		++attempts;

		if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << " attempts: " << attempts << std::endl;
			break;
		}

	} while(true);

}