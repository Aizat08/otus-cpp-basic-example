#include <iostream>
#include <fstream>
#include <string>
#include "scores_table.h"

void high_scores_table(std::string& name, int attempts) {

	const std::string high_scores_filename = "high_scores.txt";

	// Write new high score to the records table
	{
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cerr << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		}

		// Append new results to the table:
		out_file << name << ' ';
		out_file << attempts;
		out_file << std::endl;
	} 

	// Read the high score file and print all results
	{
		std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cerr << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
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


}