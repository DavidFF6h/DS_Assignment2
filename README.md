# DS_Assignment2

# Part 1: (Try and Catch Block)

## Description:
  This program re-uses the code from assignment 1, with the addition of a try and catch block in 2 functions: ModifyArrayByIndex, and Add
  
## How to run:
    1: Get files: Data.txt, DataHandler.h, DataHandler.cpp, and DS_Assignment1.cpp from github
    2: Bring those files into your IDE of choice
    3: Build and run
    
## Differences in DataHandler.h:
  -void ModifyArrayByIndex() no longer takes parameters, the input prompt is now located within the function so the try and catch block is functional and not redundant
  
  -void Add() no longer takes parameters for the above reasoning
  
## Differences in DataHandler.cpp:

   -void DataHandler::ModifyArrayByIndex():
       The function now begins by declaring ints index and num (which were formerly the parameters) and the user is prompted to enter the index of the number to modify; this is where the try and catch block begins. std::cin takes the users input for the index, if the input is the wrong data type, "Incorrect data type" is thrown, if the input is out the bounds of the array, "Array out of bounds" is thrown. Then, the user is prompted to input the new value of the specified index, if the input is the wrong data type, "Incorrect data type" is thrown. The function then is exactly the same as it was previously, aside from the catch statement, which catches the const char* thrown, uses cin.clear and cin.ignore, and prints "Exception: (the exception thrown)" so the user knows what went wrong
       
   -void DataHandler::Add()
        The function now starts by declaring int num (which was formerly the parameter) and the user is prompted to enter the number they would like to add to the end of the array; this is where the try and catch block starts. std::cin takes the users input for num, if the input is the wrong data type, "Incorrect data type" is thrown. The function then is the same as it was before, aside from the catch statement which again catches the const char* thrown, uses cin.clear and cin.ignore, and prints "Exception: (the exception thrown)" so the user knows what went wrong
        
## Differences in DS_Assignment1.cpp:
    -Do_ModifyArrayByIndex() and Do_Add() not longer call ProcessInputInt() to get user input to pass into the functions the call, they now just call their respective fucntions: ModifyArrayByIndex(), and Add()
    
## Input and Output Screenshots:
    -After entering 1 to change a value by its index, we are prompted to enter the index, when "g" is entered for for the index "Exception: Incorrect data type" is printed and we are brought back to the menu. We try again, entering 300 for the index and "Exception: Array out of bounds" is printed. We try again, entering 3 for the index, and we are prompted for the new value for index 3 and "g" is entered, causing "Exception: Incorrect data type" to be printed. We then try again, entering 2 and 3 when prompted, and everything works the same as before:
![ModExceptions](https://user-images.githubusercontent.com/113874835/196589459-7c189a43-ea41-4785-8a8e-fc7567c6a53c.png)

    -After entering 2 to add and integer to the end of the array, we are asked what integer we would like to add. "hi" is entered, causing "Exception: Incorrect data type" to be printed. We try again, entering 76, and everything works the same as before:
![AddException - Copy](https://user-images.githubusercontent.com/113874835/196589963-31176b8f-42dc-46bc-b8ed-1f7d24f18429.png)

# Part 2: (Inheritance and Virtual Functions)

## Description:
      In this program I create an abstract class, Employee, and derive the classes Professional and NonProfesstional from it. 
      
## How to run:
      1: Get files: Employee.h, Professional.cpp, NonProfessional.cpp, and DS_Assignment2 from gethub
      2: Bring those files into your IDE of choice
      3: Build and run
    
## Instructions:
      User will be prompted with 3 choices of commands, each corresponding to a number 0-2
  Type the number corresponding to the desired command and press enter
  
## Employee.h
      This is the programs header file containing the declaration of the abstract class Employee, all of the necessary virtual funtions and variable, and then the derived classes Professional and NonProfessional
### The public section of the Employee abstract class contains definitions for:
        -virtual void PrintEmployeeData() const = 0; Which will be called to print the employee's data
	      -virtual double WeeklySalary() const = 0; Which will calculate and print the employee's data
	      -virtual double HealthCareContribution() const = 0; Which will calculate and print the employee's healthcare contributions
	      -virtual double Vacation()const = 0; Which will either calculate and/or print the number of vacation days or hours earned depending on the subclass
        
### The protected section of the Employee abstract class contains:
        -int salary, which is either the montly salary or hourly rate depending on the subclass
        -int healthcarePercent, which is the percentage of the employees weekly wages that will contribute to their healthcare
        -int vacation, which is either a set number of vacation days or is a number used to calculte the amount of vacation time an employee has earned depending on the subclass
        -double hoursWorked, which is simply the hours worked 
        
### Professional subclass of Employee:
        This class contains a unique constructor, which sets the values for healthcarePercent, salary, and vacation, and the declarations of the overridden virtual functions of the abstract class Employee, all of which will be broken down in the Professional.cpp section
        
      ### NonProfessional subclass of Employee: 
        This class contains a unique constructor, which sets the values for healthcarePercent, salary, vacation, and hourWorked, and the declarations of the overridden virtual functions of the abstract class Employee, all of which will be broken down in the NonProfessional.cpp section
        
## Professional.cpp
        This is the implementation file containing all of the unique function definitions for the Professional subclass of Employee
      
### Professional::Professional(int hc, int sl, int vac)
        This is the constructor, which simply sets the values of the variables healthcarePercent, salary, and vacation depending on the parameters
          
### void Professional::PrintEmployeeData() const
          This function starts by using std::cout << std::fixed and std::cout << std::setprecision(2) to keep the output formatted properly, and then uses std::cout to output the Professional Employee's weekly salary, healthcare contributions, and vacation days
           
### double Professional::WeeklySalary() const
          This function computes and returns the Professional's weekly salary (monthly salary / 4)
           
### double Professional::HealthCareContribution() const
          This function computes and returns the Professional's healthcare contributions ((healthcarePercent * WeeklySalary())/100)
        
### double Professional::Vacation() const
          This function simply returns the amount of vacation days the Professional Employee has
           
## NonProfessional.cpp
          This is the implementation file containing all of the unique function definitions for the NonProfessional subclass of Employee
      
### NonProfessional::NonProfessional(int hc, int sl, int vac, double hrs)
          This is the constructor, which simply sets the values of the variables healthcarePercent, salary, vacation, and hoursWorked depending on the parameters
          
### void NonProfessional::PrintEmployeeData() const
           This function starts by using std::cout << std::fixed and std::cout << std::setprecision(2) to keep the output formatted properly, and then uses std::cout to output the NonProfessional Employee's weekly salary, healthcare contributions, and earned vacation time
           
### double NonProfessional::WeeklySalary() const
           This function computes and returns the NonProfessional's weekly salary (salary * hoursWorked)
           
### double NonProfessional::HealthCareContribution() const
           This function computes and returns the NonProfessional's healthcare contributions ((healthcarePercent * (salary * hoursWorked))/100)
        
### double NonProfessional::Vacation() const
           This function computes and returns the amount of vacation time the NonProfessional Employee has earned (hoursWorked / vacation)
    
## DS_Assignment2.cpp
### This is the test file:
      
        Prior to int main() I forward declare ProcessCommands, which prompts the user to input a number corresponding to the subclass whose data they'd like to see printed, or to exit(Professional, NonProfessional, Exit) and keeps them in a loop until the exit command is used.
        I also forward declare void Do_DisplayEmployeeData(Employee& e) which takes and Employee and calls its respective PrintEmployeeData function, and int ProcessInputInt() which is used to get user input while protecting against error.
        In int main() I create and instance of Professional named pro, passing (5, 8000, 14) into the constructor, and an instance of NonProfessional named np, passing (3, 38, 20, 55) into the constructor
        Then we enter ProccessCommands() and start the command loop
    
## Input and Output screenshots
      -Upon running the program, the user is greeted with:
![Init](https://user-images.githubusercontent.com/113874835/196598843-8608393d-893a-4b74-ac1d-036895496d58.png)
      
      -After pressing 0 to print the data of the Profession, we see:
![0](https://user-images.githubusercontent.com/113874835/196598953-b0ddda59-cab2-4e62-8eae-0bcde32f5e48.png)
      
      -After pressing 1 to print the data of the NonProfessional, we see:
![1](https://user-images.githubusercontent.com/113874835/196599007-8e1432d5-9ae6-47ca-bc97-58125f7e356c.png)
      
      -And finally, after pressing 2 to exit, the program terminates: 
![2](https://user-images.githubusercontent.com/113874835/196599097-83022de6-9b25-4f18-9f2c-0f95d8e458fe.png)
