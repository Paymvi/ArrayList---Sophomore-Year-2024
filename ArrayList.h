#pragma once

#include <iostream>
using namespace std;
#include <string>

// defines student with info
struct StudentInfo {
	int id;
	string name;
	string phone;
	string address;
};

class ArrayList {


private:
	StudentInfo* student_list_;		//Pointer to the array 
	short num_entries_;				//Number of inserted students 
	short current_pos_;				//index of the current position 
	short capacity_;				//Array size, i.e., maximum number of students s

public:

	ArrayList(short);															//Constructor to initialize the data members of an object 
	//~ArrayList();

	short GetCap();																//Returns the maximum array size (capacity_) 
	short GetNumOfItems();														//Returns the number of inserted students in the array (num_entries_) 
	StudentInfo GetStudentInfo();												//Gets a student's info from the user 
	void AddStudentInfo(StudentInfo temp_Student, unsigned short position);		//Inserts a student's info into the array at certain position 
	void DelStudentInfo(unsigned short position);								//Deletes a student's info from certain position in the array 
	void UpdateStudentInfo(StudentInfo temp_Student, unsigned short position);	//Updates a student's info at certain position

	void DisplayStudentInfo(unsigned short position);							//Displays info of a student at certain position. 
	StudentInfo RetrieveStudentInfo(unsigned short position);					//Returns a student's info from certain position 
	void PushStudentInfo(unsigned short position);								//Moves down (one position) all students start from a certain position 
	void PopStudentInfo(unsigned short position);								//Moves up (one position) all students start from a certain position 


	// ---------------------------------- getters and setters ----------------------------------

	//gets and sets num entries
	short GetNum_Entries();
	void SetNum_Entries(short numEntries);


	//gets and sets current pos
	short GetCurrent_Pos();
	void SetCurrent_Pos(short currPos);

	//gets and sets capacity
	short GetCapacity();
	void SetCapacity(short capacity);

	//gets the student list
	StudentInfo* GetStudent_List();


	// ---------------------------------- extra methods ----------------------------------

	
	void ClearList();										//clears the list
	bool StudentIsReal(unsigned short position);			//checks if student is real

	short FindIndexOfFirstStudent();						//checks the index of first student

	short FindIndexOfLastStudent();							//checks index of last student

	short FindNextLegitimateStudent(short position);		//checks index of next legit student

	short FindPreviousLegitimateStudent(short position);	//checks index of previous legit student

	void DiagnosticTest();									//displays high level summary



}; //dnot forget the semicolon

