


// ArrayList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ArrayList.h"
#include <iostream>
using namespace std;


int main()
{

    short capacity;
    int userChoice;
    bool runningProgram = true;

    cout << "Hello! Welcome to the program that allows you to store student information into an ArrayList (list)!\n";

    cout << "Please enter the capacity (max number of students) in your list: \n";
    cin >> capacity;
    
    ArrayList a = ArrayList(capacity); 

    cout << "Awesome! Your list is made.\n" << endl;

    userChoice = 0;
    a.ClearList();

    while (runningProgram) {

        
        //cout << "\nuserChoice: " << userChoice << endl;
        
        if (userChoice == 1) {

            unsigned short position;

            

            // Ask where they would like to position the student
            cout << "Where would you like to position the student in the list? (input a number: 1, 2, 3... to the capacity of the list)" << endl;
            cin >> position;

            position--;



            StudentInfo s = a.GetStudentInfo();

            a.AddStudentInfo(s, position);
            a.SetNum_Entries(a.GetNum_Entries()+1);

            cout << "Your student has been added to the ArrayList!\n" << endl;

            
            userChoice = 0;

        } 
        else if (userChoice == 2) {

            unsigned short position;

            // Ask which student they want to delete
            cout << "Which student would you like to delete? (input position: 1, 2, 3... to the capacity of the list)" << endl;
            cin >> position;
            position--;
            a.DelStudentInfo(position);

            userChoice = 0;

        }
        else if (userChoice == 3) {
            // [3] Clear the list (delete all students)

            a.ClearList();
            a.SetNum_Entries(0);

            userChoice = 0;

        }
        else if (userChoice == 4) {
            // [4] Find and display a student (and have the option to display the next/previous student)

            unsigned short position;
            // Ask which student they want to display
            cout << "Which student would you like to display? (input position)" << endl;
            cin >> position;

            position--;

            a.SetCurrent_Pos(position);

            
            a.DisplayStudentInfo(position);         // display student info

            // Have the option to display the previous or the next student

            int options = 0;

            
            if (position == a.FindIndexOfFirstStudent()) {
                cout << "\tNote: Your position is the first student in the list so there is no 'previous' student" << endl;
                options = 1;
            }
            if (position == a.FindIndexOfLastStudent()) { // ****************
                cout << "\tNote: Your position is the last student entry in the list, so there is no 'next' student" << endl;
                options = 2;
            }
            if (a.GetNum_Entries() == 1) {
                cout << "There is only one student in the list so there is no option of viewing the previous or next student" << endl;
                options = 3;
            }


            if (options == 0 || options == 1 || options == 2) {
                cout << "Would you like to have the option of viewing the previous or next student in the list? (y/n)" << endl;

                string answer;
                cin >> answer;

                if (answer == "y") {

                    if (options == 1) {
                        cout << "I will be displaying the next student as there is no 'previous' student" << endl;

                        short index;

                        index = a.FindNextLegitimateStudent(position);
                        a.SetCurrent_Pos(index);
                        a.DisplayStudentInfo(index);
                        a.DisplayStudentInfo(index);

                    }
                    else if (options == 2) {
                        cout << "I will be displaying the previous student as there is no 'next' student" << endl;

                        short index;

                        index = a.FindPreviousLegitimateStudent(position);
                        a.SetCurrent_Pos(index);
                        a.DisplayStudentInfo(index);

                    }
                    else {

                        cout << "Would you like to see the previous or next student? (\"p\" or \"n\")" << endl;
                        string answer2;
                        cin >> answer2;

                        short index;

                        if (answer2 == "p") {
                            index = a.FindPreviousLegitimateStudent(position);
                            a.SetCurrent_Pos(index);
                            a.DisplayStudentInfo(index);
                        }
                        else if (answer2 == "n") {
                            index = a.FindNextLegitimateStudent(position);
                            a.SetCurrent_Pos(index);
                            a.DisplayStudentInfo(index);
                        }
                        else {
                            cout << "Invalid input" << endl;
                        }

                        
                    }

                }
                else {
                    cout << "Invalid input";
                }

            }


            userChoice = 0;

        }
        else if (userChoice == 5) {
            // [5] Find and display the first student

            a.DisplayStudentInfo(a.FindIndexOfFirstStudent());  // displays student info
            userChoice = 0;
        }
        else if (userChoice == 6) {
            // [6] Find and display the last student


            a.DisplayStudentInfo(a.FindIndexOfLastStudent());       // displays student info
            userChoice = 0;

        }
        else if (userChoice == 7) {
            // Stops the loop

            runningProgram = false;

        } 
        
        else if (userChoice == 0) {

            cout << "Now choose what action you'd like to do next:" << endl;
            cout << "[1] Add a student" << endl;
            cout << "[2] Delete a student" << endl;
            cout << "[3] Clear the list (delete all students)" << endl;
            cout << "[4] Find and display a student (and have the option to display the next/previous student)" << endl;
            cout << "[5] Find and display the first student" << endl;
            cout << "[6] Find and display the last student" << endl;
            cout << "[7] Exit" << endl;
            cin >> userChoice;


        } /* old diagnostic test
        else if (userChoice == 8) {
            
            for (int i = 0; i < a.GetNum_Entries(); i++) {
                cout << "----------------------------------" << endl;

                cout << i + 1 << ": " << endl;

                if (a.StudentIsReal(i)) {
                    a.DisplayStudentInfo(i);
                }
                else {
                    cout << "Student doesn't exist" << endl;
                }
                


            }

            cout << "GetNum_Entries(): " << a.GetNum_Entries() << endl;
            cout << "GetCurrent_Pos(): " << a.GetCurrent_Pos() << endl;
            cout << "GetCapacity(): " << a.GetCapacity() << endl;


            userChoice = 0;

        } */
        else
        {
            //For invalid input
            cout << "INVALID INPUT!!!" << endl;
            userChoice = 7;

        }

        a.DiagnosticTest();

        
    
    }
    

}