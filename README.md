# Student Record System

    This is a mini-project for a Student Record System developed using C.
    The system stores student records containing their name, total grade, unique id, age, gender, and password.
    
## Features
The system offers two modes:

1. Admin mode:

    This mode is only accessible by entering the correct password. Once authenticated, the user can perform the following operations:

        Add student record
        Remove student record
        View student record
        View all records
        Edit admin password
        Edit student grade

2. User mode:

    This mode requires the student to enter their unique id and password. Once authenticated, the student can perform the following operations:
    
        View their record
        Edit their password
   
## Usage:

    
The program prompts the user to choose a mode at the beginning. Depending on the mode chosen, the user will be prompted to enter their credentials. The system will then display the appropriate menu options, which can be selected by entering the corresponding number.

To compile and run the program, simply navigate to the directory where the source code is located and enter the following commands in the terminal:

    gcc main.c allmethods.c System.c -o main
    ./main  or  main.exe


## Acknowledgements

This project was inspired by the need to manage student records effectively. It was developed as a mini-project and may be improved upon for larger scale use cases.
