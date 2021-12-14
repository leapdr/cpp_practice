#include <iostream>

using namespace std;

int main(){
	float grade;
	string grade_letter;
	string name;
	string course;

	// name prompt
	cout << "Enter name: ";
	cin >> name;

	// course prompt
	cout << "Enter course: ";
	cin >> course;

	// grade prompt
	cout << "Enter grade: ";
	cin >> grade;

	if(grade > 95 && grade <= 100){
		grade_letter = "A+";
	}
	else if(grade > 90){
		grade_letter = "A";
	}
	else if(grade > 85){
		grade_letter = "B+";
	}
	else if(grade > 80){
		grade_letter = "B";
	}
	else if(grade > 70){
		grade_letter = "C";
	}
	else if(grade >= 60){
		grade_letter = "D";
	}
	else if(grade < 60 && grade > 0){
		grade_letter = "F";
	}
	else {
		cout << "Invalid grade!" << endl;
		return 0;
	}

	cout << endl << "BICOL UNIVERSITY - COLLEGE OF SCIENCE" << endl;
	cout << "=====================================" << endl;
	cout << "Name: " << name << endl;
	cout << "Course: " << course << endl;
	cout << "Grade: " << grade << endl;
	cout << grade_letter << endl;

	return 0;
}
