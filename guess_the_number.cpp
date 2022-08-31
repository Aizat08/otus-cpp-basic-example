#include <iostream>
#include <fstream>
#include <string>
#include "random_number.h"

int main() {

	const std::string high_scores_filename = "high_scores.txt";

	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	int attempts_count = 0;

	random_guess(attempts_count);

	// Write new high score to the records table
	{
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		// Append new results to the table:
		out_file << user_name << ' ';
		out_file << attempts_count;
		out_file << std::endl;
	} 

	// Read the high score file and print all results
	{
		std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		std::cout << "\n" << "High scores table:" << std::endl;

		std::string username;
		int high_score = 0;
		while (true) {
			in_file >> username;
			in_file >> high_score;
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
	}

	return 0;
}