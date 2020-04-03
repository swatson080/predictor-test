//============================================================================
// Name        : predictionTest.cpp
// Author      : stephen watson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

void printStats(int count, int countA, int countB);
void makePrediction(int count, int countA, int countB);
std::string getPlayerChoice(std::string message);
std::string getStringInput();
bool quitNow(std::string message);


int main() {

	bool quit = false;

	int count = 0, countA = 0, countB = 0;

	std::string choice;

	do {

		printStats(count, countA, countB);

		if(count != 0) {
			makePrediction(count,countA,countB);
		}

		choice = getPlayerChoice("Choose between A or B");
		if(choice == "A") {
			++countA;
		}
		else if(choice == "B") {
			++countB;
		}

		++count;

		if(quitNow("Do you want to continue?")) {
			quit = true;
		}

	} while(!quit && count < 200);

	return 0;
}

/*******************************************************
 * 					FUNCTION DEFINITIONS
 *******************************************************/

void printStats(int count, int countA, int countB) {
	std::cout << "Loop " << count << std::endl;
	std::cout << "You have chosen A " << countA << " times" << std::endl;
	std::cout << "You have chosen B " << countB << " times" << std::endl;
}

void makePrediction(int count, int countA, int countB) {
	float probA = (float)countA / count;
	float probB = (float)countB / count;

	if(probA > probB) {
		std::cout << "I predict you will choose A" << std::endl;
	}
	else if (probB > probA) {
		std::cout << "I predict you will choose B" << std::endl;
	}
	else {
		std::cout << "Not enough data for a prediction" << std::endl;
	}
}

std::string getPlayerChoice(std::string message) {

	std::string input = "";

	while(true) {
		std::cout << message << std::endl;
		std::string input = getStringInput();
		if(input == "a" || input == "A") {
			std::cout << "You have chosen A" << std::endl;
			return "A";
		}
		else if(input == "b" || input == "B") {
			std::cout << "You have chosen B" << std::endl;
			return "B";
		}
		else {
			std::cout << "That's a bad answer" << std::endl;
		}
	}
}

bool quitNow(std::string message) {
	std::string input = "";

	while(true) {
		std::cout << message << std::endl;
		std::string input = getStringInput();
		if(input == "y" || input == "Y") {
			std::cout << "Initiating next loop" << std::endl;
			return false;
		}
		else if(input == "n" || input == "N") {
			std::cout << "Exiting simulation..." << std::endl;
			return true;
		}
		else {
			std::cout << "That's a bad answer" << std::endl;
		}
	}
}

std::string getStringInput() {
	std::string input;
	getline(std::cin, input);
	return input;
}
