#include "DataHandler.h"

void DataHandler::ReadData(std::string source)
{
	std::ifstream input; //Creating out ifstream
	input.open(source); //Giving our ifstream the values of our .txt
	if (input) { //If our file exists, initialize array with the data from the file
		int x = 0;
		while (!input.eof()) { //While not at end of file, add values to array
			input >> DataArray[x];
			x++;
		}
	}
	else std::cout << "No input file found."; //Else, output error message and leave the function
	return;

}

void DataHandler::OutputData()
{
	//Uses for loop to print values from the array to the console
	std::cout << "Array:" << std::endl;
	int count = 0;
	for (int i = 0; i < size; i++) {
		std::cout << DataArray[i] << " ";
		count++;
		if (count == 10) {
			std::cout << std::endl;
			count = 0;
		}
	}
	std::cout << std::endl;
	return;
}

void DataHandler::FindInt(int target)
{
	//For loop to search through the elements of the array, if current element value = target value, print that index to the console
	for (int i = 0; i < size; i++) {
		if (DataArray[i] == target) {
			std::cout << target << " is at index " << i << "." << std::endl;
			return;
		}
	}
	std::cout << target <<" is not in the array." << std::endl;
	return;
}

void DataHandler::ModifyArrayByIndex()
{
	int index, num;
	std::cout << "Enter the index of the number you would like to modify: ";
	try {//Try / Catch block to catch exceptions caused by user input (Incorrect data type, array out of bounds)
		std::cin >> index;	
		if (std::cin.fail()) throw "Incorrect data type";
		else if (index > size || index < 0) throw "Array out of bounds"; 

		std::cout << "Enter the new value for the specified index: ";
		std::cin >> num; if (std::cin.fail()) throw "Incorrect data type";

		int temp = DataArray[index]; //Temp variable for element being replaced, for cout use	
		DataArray[index] = num; //Replacing element at specified index
		std::cout << temp << " at index " << index << " has been replaced by " << num << "." << std::endl;
	return;
	}
	catch (const char * ex) {//Catches const char * thrown to specify the exception
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cerr << "Exception: " << ex << std::endl;
	}

}

void DataHandler::Add()
{
	int num;
	try {//Try / Catch block to catch exceptions caused by user input
		std::cout << "Enter the number you would like to add to the end of the array: ";
		std::cin >> num; if (std::cin.fail()) throw "Incorrect data type";

		std::cout << num << " has been added to the end of the array." << std::endl;
		size++; //Increasing array size by one
		DataArray[size - 1] = num; //Setting the last element in array to specified value
		return;
	}
	catch (const char* ex) {//Catches const char * thrown to specify the exception
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cerr << "Exception: " << ex << std::endl;
	}
}

void DataHandler::Remove(int index)
{
	std::cout << DataArray[index] << " at index " << index << " has been removed." << std::endl;
	//For loop to shift elements down one in the array, starting at the specified index, removing that element in th process
	for (int i = index; i < size; ++i) {
		DataArray[i] = DataArray[i + 1];
	}
	size--; //Shrinking array size by one 
	return;
}
