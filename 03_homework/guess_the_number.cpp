#include <iostream>
#include "random_number.h" 
#include "scores_table.h"

int main(){

	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	int attempts_count = 0;

	random_guess(attempts_count);

	high_scores_table(user_name, attempts_count);
}