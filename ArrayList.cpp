
#include "ArrayList.h"
#include <iostream>
using namespace std;



// Constructor to initialize the data members of an object
ArrayList::ArrayList(short cap) {

    capacity_ = cap;
    num_entries_ = 0;
    current_pos_ = -1;

    student_list_ = new StudentInfo[cap];
    
}

// Returns the maximum array size (capacity_)
short ArrayList::GetCap() {
    return capacity_;
}

//Returns the number of inserted students in the array (num_entries_) 
short ArrayList::GetNumOfItems() {
    return num_entries_;
}



//Gets a student's info from the user
StudentInfo ArrayList::GetStudentInfo() {


    // Make a new student
    StudentInfo newStudent;

    int id;
    string name, phone, address;

    cout << "What is the new student's id?" << endl;
    cin >> id;
    cout << "What is the new student's name?" << endl;
    cin >> name;
    cout << "What is the new student's phone?" << endl;
    cin >> phone;
    cout << "What is the new student's address?" << endl;
    cin >> address;

    newStudent.id = id;
    newStudent.name = name;
    newStudent.phone = phone;
    newStudent.address = address;

    return newStudent;

}


//Inserts a student's info into the array at certain position
void ArrayList::AddStudentInfo(StudentInfo temp_Student, unsigned short position) {

    student_list_[position] = temp_Student;
}



//Deletes a student's info from certain position in the array 
void ArrayList::DelStudentInfo(unsigned short position) {

    PopStudentInfo(position);
    num_entries_--;

}



//Updates a student's info at certain position
void ArrayList::UpdateStudentInfo(StudentInfo temp_Student, unsigned short position) {
    student_list_[position] = temp_Student;
}

//Displays info of a student at certain position. 
void ArrayList:: DisplayStudentInfo(unsigned short position) {

    StudentInfo chosenStudent;

    chosenStudent = student_list_[position];
    
    cout << "student id: " << chosenStudent.id << endl;
    cout << "student name: " << chosenStudent.name << endl;
    cout << "student phone: " << chosenStudent.phone << endl;
    cout << "student address: " << chosenStudent.address << endl;
    
}


//Returns a student's info from certain position 
StudentInfo ArrayList::RetrieveStudentInfo(unsigned short position) {
    return student_list_[position];
}

//Moves down (one position) all students start from a certain position 
void ArrayList::PushStudentInfo(unsigned short position) {


    for (position; position < GetNum_Entries(); position++) {

        student_list_[position + 1] = student_list_[position];


    }

}

//Moves up (one position) all students start from a certain position 
void ArrayList::PopStudentInfo(unsigned short position) {


    for (position; position < capacity_-1; position++) {

        if (position != 0) {
            student_list_[position - 1] = student_list_[position];
        }


    }


}


// -------------------- Getters and Setters --------------------


// gets the number of entries
short ArrayList:: GetNum_Entries(){
    return num_entries_;
}

// sets the number of entries
void ArrayList::SetNum_Entries(short numEntries) {
    num_entries_ = numEntries;
}


//gets the current position
short ArrayList::GetCurrent_Pos() {
    return num_entries_;
}


//sets the current position
void ArrayList::SetCurrent_Pos(short currPos) {
    current_pos_ = currPos;
}


//gets the capacity
short ArrayList::GetCapacity() {
    return capacity_;
}

//sets the capacity
void ArrayList::SetCapacity(short capacity) {
    capacity_ = capacity;
}

//gets the student list
StudentInfo* ArrayList:: GetStudent_List() {
    return student_list_;
}


// -------------------- Extra Methods --------------------

//clears the list
void ArrayList::ClearList() {


    for (int i = 0; i < GetCapacity(); i++) {

        
        StudentInfo newStudent;

        int id = -923368;
        string name, phone, address;

        name = "";
        phone = "";
        address = "";

        newStudent.id = id;
        newStudent.name = name;
        newStudent.phone = phone;
        newStudent.address = address;

        AddStudentInfo(newStudent, i);

    }

}

// checks if there is a legitimate student
bool ArrayList::StudentIsReal(unsigned short position) {

    StudentInfo chosenStudent;

    chosenStudent = student_list_[position];


    if (chosenStudent.id == -923368) {
        return false;
    }
    else {
        return true;
        
    }

}

//finds the index of the first student
short ArrayList::FindIndexOfFirstStudent() {

    short index = -1;
    
    for (int i = 0; i < capacity_; i++) {

        if (StudentIsReal(i) && index == -1) {
            index = i;
        }
    }

    return index;

}

//finds the index of the alst student
short ArrayList::FindIndexOfLastStudent() {

    short index = -1;

    for (int i = 0; i < capacity_; i++) {

        if (StudentIsReal(i)) {
            index = i;
        }
    }
    return index;

}

//finds the next legitimate student given the position
short ArrayList::FindNextLegitimateStudent(short position) {

    short index = -1;

    for (++position; position < capacity_; position++) {


        if (StudentIsReal(position) && index == -1) {
            index = position;
        }
    }



    return index;

}

//finds the previous legitimate student given the position
short ArrayList::FindPreviousLegitimateStudent(short position) {


    short index = -1;

    for (--position; position >= 0; position--) {

        //cout << "Testing... position is" << position << endl;

        if (StudentIsReal(position) && index == -1) {
            //cout << "  FOUND LEGIT STUDENT: " << position << endl;
            index = position;
        }
    }

    //cout << "index: " << index << endl;

    return index;

}

// gives high level summary of array list
void ArrayList:: DiagnosticTest() {

    StudentInfo chosenStudent;

    cout << "HIGH LEVEL SUMMARY OF LIST: " << endl;

    for (int i = 0; i < capacity_; i++) {
        chosenStudent = student_list_[i];
        if (chosenStudent.id != -923368) {
            cout << "i: " << i+1 << "       student id:" << chosenStudent.id << endl;
        }
        else {
            cout << "i: " << i+1 << "       student id: N/A (there is no student)"<< endl;
        }
        
    }

}