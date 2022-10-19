// DS_Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Employee.h"
#include <iostream>
//Forward Declaring 
void ProcessCommands(Professional pro, NonProfessional np);
void Do_DisplayEmployeeData(Employee& e);
int ProcessInputInt();

int main()
{
	Professional pro(5, 8000, 14); //Creating instance of Professional, passing in values for healthPercent, salary, and vacation
	NonProfessional np(3, 38, 20, 55); //Creating instance of NonProfessional, passing in values for healthPercent, salary (hourly rate), vacation, and hours worked
	ProcessCommands(pro, np); //Starting input loop, passing in the Professional and NonProfessional instances from above
}

//Function for user input loop, allows user to decide which type of employee to display. 
void ProcessCommands(Professional pro, NonProfessional np)
{
	//String array for commands
	std::string commands[] = {
		"Professional",
		"Non-Profesional",
		"Exit"
	};
	const int NumberOfCommands = 3;
	int choice;
	do {
		//Print command number folowed by name followed by new line
		for (int i = 0; i != NumberOfCommands; i++) {
			std::cout << "Select: " << i << " " << commands[i] << std::endl;
		}
		//Use process input to get input, prevents user from entering incorrect data type
		choice = ProcessInputInt();
		//Switch case for choices, each choice calls function to get and pass input into member functions
		switch (choice) {
		case 0: {Do_DisplayEmployeeData(pro); break; }
		case 1: {Do_DisplayEmployeeData(np); break; }
		case 2: return;
		default: {
			std::cout << "Input does not correspond to a command." << std::endl;
			continue;
		}
		}
	} while (choice != 2);
}

//Calls PrintEmployeeDataFunction for Employee sub-class passed into the function
void Do_DisplayEmployeeData(Employee& e)
{
	e.PrintEmployeeData();
}

//Called when user input is needed, prevents incorrect data types from being entered
int ProcessInputInt()
{
	int input;
	std::cin >> input;
	while (std::cin.fail()) { //While cin fails, ask for input again
		std::cout << "Invalid input, use integers only!" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Try again: ";
		std::cin >> input;
	}
	return input;
}
