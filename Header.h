#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class Student
{
private:
	string firstName;
	string lastName;
	int Class;
	int rollNo;
	string registrationDate;
	string Gender;
	string contactNo;
	string fatherName;
	string fatherProfession;
	string parentContact;
	string feeSubmitted;
	string bloodGroup;
	string Address;
public:
	void enterData();
	void edit_StudentData(string);
	void diaplay_student();
	void feeStatus();
	void log_in_admin();
	void log_in_student();
	virtual void display();
	void showMarks_Student();
	bool check_number(string str);
};

class Teacher :public Student
{
public:
	string FirstName;
	string LastName;
	string Email;
	string JoiningDate;
	string Password;
	string ConfirmPassword;
	string CNIC;
	string gender;
	string Qualification;
	string ContactNo;
	string DOB;
	string address;
	string Salary;
	void enter_TeacherData();
	bool chkpass(string pass, string conpass);
	void edit_TeacherData(string);
	void diaplay_teacher();
	virtual void display();
};

//Third Class
class Course
{
private:
	string CourseName;
	string CourseCode;
	string SelectClass; //(Pre - nursery to matric)
	string ParentCourse; //(selected from general courses)
public:
	void enter_CourseData();
	virtual void display();
	void assignCourses();
	void view_teacher_courses();
};

class marks
{
public:
	string English;
	string OOP;
	string DLD;
	string PS;
	marks();		//Default Constructor 	
	void updateMarks();
	void showMarks();
	void updategrade();
	virtual void display();
};

//This class has all the function which we used to print menu in the program
class function
{
public:
	void starting_display(char& op);
	void display_fun2(char& option);
	void student_menu(char& student_option);
	void edit_student_menu();
	void teacher_menu(char& teacher_option);
	void student_edit_menu();
	void display_final();
	void module2_menu_student(char& opp);
	void module2_fun2();
	void teacher_mod(char& teacher_option);
	void edit_student_display();
	void edit_teacher_display();
	void loading();
};