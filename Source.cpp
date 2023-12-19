#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include"Header.h"
void Student::enterData()
{
	string str1 = "M";
	string str2 = "F";
	ofstream stfile("student_data.txt", ios::app);
	int op;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\t\t\t\t\t--------------------------------" << endl;
		cout << "\t\t\t\t\t| Entering New Student Data    |" << endl;
		cout << "\t\t\t\t\t--------------------------------" << endl << endl;
		cout << "\t\t\t\t\t Enter First Name  : ";		cin.ignore(); getline(cin, firstName);
		cout << "\t\t\t\t\t Enter Last Name   : ";		cin.ignore(); getline(cin, lastName);
		cout << "\t\t\t\t\t Enter Class       : ";	//	cin >> Class;
		while (!(cin >> Class))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		cout << "\t\t\t\t\t Enter Roll Num    : " << Class << "-"; 	//cin >> rollNo;
		while (!(cin >> rollNo))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		cout << "\t\t\t\t\t Enter Regis Date  : ";		cin.ignore(); getline(cin, registrationDate);
		cout << "\t\t\t\t\t Enter Gender(M/F) : ";		cin >> Gender;

		//cout << "\t\t\t\t\t Enter Contact Num : ";		//cin >> contactNo;
		do
		{
			cout << "\t\t\t\t\t Enter Contact Num : ";		//cin >> contactNo;
			cin >> contactNo;
			if (contactNo.length() != 11)
			{
				cout << "\t\t\t\t\tPlease Enter 11 Digits !" << endl;
			}
		} while (contactNo.length() != 11);
		cout << "\t\t\t\t\t Enter Father Name : ";		cin.ignore(); getline(cin, fatherName);
		cout << "\t\t\t\t\t Father Profession : ";		cin.ignore(); getline(cin, fatherProfession);

		//cout << "\t\t\t\t\t Father Contact No.: ";	//	cin >> contactNo;
		//cout << "\t\t\t\t\t Father Contact No.: ";		cin.ignore(); getline(cin, parentContact);
		do
		{
			cout << "\t\t\t\t\t Father Contact No.: ";		cin >> parentContact;

			if (parentContact.length() != 11)
			{
				cout << "\t\t\t\t\tPlease Enter 11 Digits !" << endl;
			}
		} while (parentContact.length() != 11);

		cout << "\t\t\t\t\t Fee Submitted     : ";		cin.ignore(); getline(cin, feeSubmitted);


		cout << "\t\t\t\t\t Enter Blood Group : ";		cin >> bloodGroup;
		cout << "\t\t\t\t\t Enter Address     : ";		cin.ignore();	getline(cin, Address);
		cout << endl;

		/*
		////////////////following is code to input in file
		*/
		if (stfile.is_open())		//Checking for if the file is open or not
		{
			stfile << "\n					student # " << rollNo << endl << endl;
			stfile << " First-Name        : ";		 stfile << firstName << endl;
			stfile << " Last-Name         : ";		 stfile << lastName << endl;
			stfile << " Class             : ";		 stfile << Class << endl;
			stfile << " Roll#             : "; 	     stfile << rollNo << endl;
			stfile << " Regis-Date        : ";		 stfile << registrationDate << endl;
			stfile << " Gender(M/F)       : ";		 stfile << Gender << endl;
			stfile << " Contact NO        : ";		 stfile << contactNo << endl;
			stfile << " Father-Name       : ";		 stfile << fatherName << endl;
			stfile << " Father Profession : ";		 stfile << fatherProfession << endl;
			stfile << " Father Contact No.: ";		 stfile << contactNo << endl;
			stfile << " Fee Submitted     : ";		 stfile << feeSubmitted << endl;
			stfile << " Blood Group       : ";		 stfile << bloodGroup << endl;
			stfile << " Enter Address     : ";		 stfile << Address << endl;
		}
		else
		{
			cout << "\t\t\t\t\ Unable to open file" << endl;
		}
		/////////////////////////////////////////////////////////////
		cout << "\t\t\t\t\t Enter More Students ? " << endl;
		cout << "\t\t\t\t\t Yes=1 ; No=0 : ";				//cin >> op;

		while (!(cin >> op))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		if (op == 0)
		{
			system("cls");
			break;
		}
	} while (exit);
}


void Student::edit_StudentData(string roll)
{
	bool z = 0;
	int count = 0;
	string var[7];
	var[5] = roll;
	string sort = "\t\t\t\t\tstudent # " + var[5];

	//declaring files
	ifstream oldfile("student_data.txt");   //it will open file to read data
	ofstream newfile("new_student_file.txt", ios::app);   //it will make new file 
	while (oldfile)
	{

		getline(oldfile, var[6]);			// this will read lines from old file
		if (newfile.is_open())				//condition to check either file is open or not
		{
			if (var[6] == sort)
			{
				z = 1;
			}
			if (z)
			{
				if (count != 15)
				{
					if (count == 2 || count == 3 || count == 8 || count == 12 || count == 14)
					{
						if (count == 2)
						{
							cout << "\t\t\t\t\t Enter First-Name   : ";		cin.ignore(); getline(cin, var[0]);
							newfile << " First-Name  : ";		 newfile << var[0] << endl;
						}
						else if (count == 3)
						{
							cout << "\t\t\t\t\t Enter Last-Name    : ";		cin.ignore(); getline(cin, var[1]);
							newfile << " Last-Name   : ";		 newfile << var[1] << endl;
						}
						else if (count == 8)
						{
							cout << "\t\t\t\t\t Enter Contact No.  : ";		cin.ignore(); getline(cin, var[2]);
							newfile << " Contact NO : ";		 newfile << var[2] << endl;
						}
						else if (count == 12)
						{
							cout << "\t\t\t\t\t Enter Fee Submitted: ";		cin.ignore(); getline(cin, var[3]);
							newfile << " Fee Submitted     : ";		 newfile << var[3] << endl;
						}
						else if (count == 14)
						{
							cout << "\t\t\t\t\t Enter Address      : ";		cin.ignore(); getline(cin, var[4]);
							newfile << " Enter Address     : ";		 newfile << var[4] << endl;
						}
						count++;
					}
					else
					{
						count++;
						newfile << var[6] << endl;
					}

				}
				else if (count == 15)
				{
					count++;
					newfile << var[6] << endl;
				}
			}
			else
			{
				newfile << var[6] << endl;
			}
		}
		else
		{
			cout << "\t\t\t\t\tUnable to open file" << endl;
		}
	}

	oldfile.close();
	newfile.close();
	remove("student_data.txt");     //This will delete the old file
	rename("new_student_file.txt", "student_data.txt");
}
void Student::diaplay_student()
{
	ifstream stfile("student_data.txt");
	string line;
	while (stfile)
	{
		getline(stfile, line);
		cout << "\t\t\t\t\t" << line << endl;
	}
	stfile.close();
	cout << "\n\n";
	char op;
	cout << "\t\t\t\t\tPress 1 to go back to menu : ";
	do
	{

		while (!(cin >> op))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}
		if (op == 0)
		{
			break;
		}


	} while (op != '1');
	system("cls");
}
void Student::feeStatus()
{
	string roll;
	cout << "\n\n\n" << endl;
	cout << "\t\t\t\t\t -------------------------" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t| Input Valid Roll Number |" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t -------------------------" << endl;
	cout << "\t\t\t\t\t| Enter  : ";	cin >> roll;

	cout << endl << endl;
	string sort = "\t\t\t\t\tstudent # " + roll;
	string line;
	bool z = 0;
	int count = 0;
	//This will display all the students :
	// 1. Full Name 
	// 2. Roll
	// 3. Fee Status
	ifstream file("student_data.txt");
	while (file)
	{
		getline(file, line);
		if (line == sort)
		{
			z = 1;
			cout << sort << endl;
		}
		if (z)
		{
			if (count != 15)
			{
				if (count == 2 || count == 3 || count == 12)
				{
					if (count == 2)
					{
						cout << "\t\t\t\t\t" << line << endl;
					}
					else if (count == 3)
					{
						cout << "\t\t\t\t\t" << line << endl;
					}
					else if (count == 12)
					{
						cout << "\t\t\t\t\t" << line << endl;
					}

				}
				count++;
			}
		}

	}
	char choicex;
	cout << "\t\t\t\t\tEnter 1 to go back to menu" << endl;
	do
	{
		cout << "\t\t\t\t\tEnter : ";		cin >> choicex;
	} while (choicex != '1');
}
void Student::log_in_admin()
{
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t -------------------------" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t|         SIGN IN         |" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t -------------------------" << endl;

	string user, pass;
	string username, password;

	cout << "\t\t\t\t\t Enter User name : ";		cin >> user;
	cout << "\t\t\t\t\t Enter Password  : ";		cin >> pass;

	ifstream admin_file("admin_password.txt");
	getline(admin_file, username);
	getline(admin_file, password);

	while (true)
	{
		if (username == user && password == pass)
		{
			cout << "\t\t\t\t\tuser /password match \n";
			admin_file.close();
			system("cls");
			break;
		}
		else {
			cout << "\t\t\t\t\t   Password Unmatch ! " << endl;
			cout << "\t\t\t\t\t     Enter Again !" << endl;
			cout << endl;
			cout << "\t\t\t\t\t Enter User name : ";		cin >> user;
			cout << "\t\t\t\t\t Enter Password  : ";		cin >> pass;
			system("cls");

		}
		admin_file.close();
	}
}
void Student::log_in_student()
{
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t -------------------------" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t|         SIGN IN         |" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t -------------------------" << endl;

	string user, pass;
	string username, password;

	cout << "\t\t\t\t\t Enter User name : ";		cin >> user;
	cout << "\t\t\t\t\t Enter Password  : ";		cin >> pass;

	ifstream admin_file("student_login.txt");
	getline(admin_file, username);
	getline(admin_file, password);

	while (true)
	{
		if (username == user && password == pass)
		{
			cout << "\t\t\t\t\tuser /password match \n";
			admin_file.close();
			system("cls");
			break;
		}
		else {
			cout << "\t\t\t\t\t   Password Unmatch ! " << endl;
			cout << "\t\t\t\t\t     Enter Again !" << endl;
			cout << endl;
			cout << "\t\t\t\t\t Enter User name : ";		cin >> user;
			cout << "\t\t\t\t\t Enter Password  : ";		cin >> pass;
			system("cls");

		}
		admin_file.close();
	}
}

void Student::display()				//This is a virtual void display function
{
	cout << "\n\n";
	cout << "\t\t\t\t\t\t |  Welcome Admin  |" << endl << endl;
}

void Student::showMarks_Student()
{

	string claaas, rol;
	string line, sort;
	int count = 0;
	bool a = 0;
	cout << "\n\n\n";
	cout << "\t\t\t\t\t -------------------------" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t| Input Valid Roll Number |" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t -------------------------" << endl;
	cout << "\t\t\t\t\t| Enter  : ";	cin >> rol;

	sort = "\t\t\t\t\tstudent # " + rol;
	ifstream marks("marks_file.txt");
	while (marks)
	{
		getline(marks, line);
		{
			if (line == sort)
			{
				a = 1;
			}
			if (a)
			{
				cout << "\t\t\t\t\t" << line << endl;
				count++;
				if (count == 7)
				{
					a = 0;
					count == 0;
				}
			}
		}
	}
	marks.close();
	char choicex;
	cout << "\t\t\t\t\tEnter 1 to go back to the menu" << endl;
	cout << "\t\t\t\t\tEnter : ";
	do
	{
		cin >> choicex;

	} while (choicex != '1');

}

bool Student::check_number(string str)
{
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

//Input function of Teacher
void Teacher::enter_TeacherData()
{
	ofstream stfile("teacher_data.txt", ios::app);

	int op;
	while (1)
	{
		cout << "\n\n";
		cout << "\t\t\t\t\t--------------------------------" << endl;
		cout << "\t\t\t\t\t|   Entering New Teacher Data  |" << endl;
		cout << "\t\t\t\t\t--------------------------------" << endl << endl;
		cout << "\t\t\t\t\t Enter First Name   : ";		cin.ignore();	getline(cin, FirstName);
		cout << "\t\t\t\t\t Enter Last Name    : ";		cin.ignore();	getline(cin, LastName);
		cout << "\t\t\t\t\t Enter Email        : ";		cin.ignore();	getline(cin, Email);
		cout << "\t\t\t\t\t Enter Joining Date : ";		cin.ignore();	getline(cin, JoiningDate);
		cout << "\t\t\t\t\t Enter Password     : ";		cin.ignore();	getline(cin, Password);
		cout << "\t\t\t\t\t Enter Confirm Pass : ";		cin.ignore();	getline(cin, ConfirmPassword);
		while (chkpass(Password, ConfirmPassword) != true)
		{
			chkpass(Password, ConfirmPassword);
		}
		cout << "\t\t\t\t\t Enter Teacher CNIC  : ";		cin >> CNIC;

		cout << "\t\t\t\t\t Enter Teacher Gender: ";		cin >> gender;
		cout << "\t\t\t\t\t Enter Qualification : ";		cin.ignore(); getline(cin, Qualification);
		;
		do
		{
			cout << "\t\t\t\t\t Enter Contact Num   : ";	cin >> ContactNo;
			if (ContactNo.length() != 11)
			{
				cout << "\t\t\t\t\tPlease Enter 11 Digits !" << endl;
			}
		} while (ContactNo.length() != 11);

		cout << "\t\t\t\t\t Enter Date of Birth : ";		cin.ignore();	getline(cin, DOB);
		cout << "\t\t\t\t\t Enter Address       : ";		cin.ignore();	getline(cin, address);
		cout << "\t\t\t\t\t Enter Teacher Salary: Rs/-";		cin >> Salary;

		cout << endl;

		if (stfile.is_open())		//Checking for if the file is open or not
		{
			stfile << "\n					Teacher # " << CNIC << endl << endl;
			stfile << " First-Name   : ";		 stfile << FirstName << endl;
			stfile << " Last-Name    : ";		 stfile << LastName << endl;
			stfile << " Email        : ";		 stfile << Email << endl;
			stfile << " Joining-Date : "; 	     stfile << JoiningDate << endl;
			stfile << " Password     : ";		 stfile << Password << endl;
			stfile << " CNIC         : ";		 stfile << CNIC << endl;
			stfile << " Gender       : ";		 stfile << gender << endl;
			stfile << " Qualification: ";		 stfile << Qualification << endl;
			stfile << " Contact-No   : ";		 stfile << ContactNo << endl;
			stfile << " Date OF Birth: ";		 stfile << DOB << endl;
			stfile << " Address      : ";		 stfile << address << endl;
			stfile << " Salary       : ";		 stfile << Salary << endl;
		}
		else
		{
			cout << "\t\t\t\t\tUnable to open file";
		}

		cout << "\t\t\t\t\t Enter More Teacher ? " << endl;
		cout << "\t\t\t\t\t Yes=1 ; No=0 : ";			//	cin >> op;

		while (!(cin >> op))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}
		if (op == 0)
		{
			break;
		}
	}
}

bool Teacher::chkpass(string pass, string conpass)
{
	if (Password.compare(ConfirmPassword) == 0)
	{
		return true;
	}
	else
	{
		cout << endl;
		cout << "\t\t\t\t\tIncorrect Password !" << endl;
		cout << "\t\t\t\t\tEnter Pass Again : ";		cin.ignore();	getline(cin, ConfirmPassword);
	}
}

void Teacher::diaplay_teacher()
{
	ifstream stfile("teacher_data.txt");
	string line;
	while (stfile)
	{
		getline(stfile, line);
		cout << "\t\t\t\t\t" << line << endl;
	}
	stfile.close();
	cout << "\n\n";
	//cout << "\t\t\t\t\tPress 1 to go back to menu " << endl;
	char op;
	cout << "\t\t\t\t\tPress 1 to go back to menu : ";
	do
	{

		while (!(cin >> op))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}
		if (op == 0)
		{
			break;
		}

	} while (op != '1');
	system("cls");
}

void Teacher::display()				//This is a virtual void display function
{
	cout << "\n\n";
	cout << "\t\t\t\t\t     |  Hello Student  |" << endl << endl;
}

void Course::enter_CourseData()
{
	ofstream stfile("course_data.txt", ios::app);
	do
	{
		cout << " Enter Course Name : ";		cin.ignore();	getline(cin, CourseName);
		cout << " Enter Cousre Code : ";		cin.ignore();	getline(cin, CourseCode);
		cout << " Enter Class       : ";		cin.ignore();	getline(cin, SelectClass);
		cout << " Parent Course     : ";		cin.ignore();	getline(cin, ParentCourse);

		int op;

		if (stfile.is_open())		//Checking for if the file is open or not
		{
			stfile << "\n					Course # " << CourseCode << endl << endl;
			stfile << " Course-Name  : ";		 stfile << CourseName << endl;
			stfile << " Course-Code  : ";		 stfile << CourseCode << endl;
			stfile << " Class        : ";		 stfile << SelectClass << endl;
			stfile << " Parent-Code  : "; 	     stfile << ParentCourse << endl;
		}
		else
		{
			cout << "Unable to open file";
		}

		cout << " Enter More Course ? " << endl;
		cout << " Yes=1 ; No=0 : ";				cin >> op;
		while (!(cin >> op))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		if (op == 0)
		{
			break;
		}
	} while (1);
}

void Course::assignCourses()
{

	cout << "\n\n";
	cout << "\t\t\t\t\t------------------------------------------" << endl;
	cout << "\t\t\t\t\t|      Assigning Courses to Teachers     |" << endl;
	cout << "\t\t\t\t\t------------------------------------------" << endl << endl;

	string cour[99], teac[99];
	string line = "Course-Name";
	int size_c = 0, size_t = 0, x = 0, y = 0, a = 0, b = 0;
	bool m = 0, n = 0;
	ifstream teacher_file("teacher_data.txt");
	string sort = "First-Name";
	ifstream course_file("course_data.txt");
	ofstream file("course_teacher.txt", ios::app);
	while (course_file)
	{
		course_file >> cour[a];
		if (cour[a] == line)
		{
			n = 1;
		}
		if (n)
		{
			x++;
			if (x == 3)
			{

				size_c++;
				n = 0;
				a++;
				x = 0;
			}
		}
	}


	while (teacher_file)
	{
		teacher_file >> teac[b];
		if (teac[b] == sort)
		{
			m = 1;
		}
		if (m)
		{
			y++;
			if (y == 3)
			{
				size_t++;
				m = 0;
				b++;
				y = 0;
			}
		}

	}


	cout << "\t\t\t\t\t\t  -----------------------" << endl;
	cout << "\t\t\t\t\t\t  |       Teachers      |" << endl;
	cout << "\t\t\t\t\t\t  -----------------------" << endl;
	for (int i = 0; i < size_t; i++)
	{
		int j = i;
		cout << "\t\t\t\t\t\t     " << (++j) << "." << "    " << teac[i] << endl;
	}


	cout << "\n";
	cout << "\t\t\t\t\t\t  -----------------------" << endl;
	cout << "\t\t\t\t\t\t  |       Courses       |" << endl;
	cout << "\t\t\t\t\t\t  -----------------------" << endl;

	for (int i = 0; i < size_c; i++)
	{
		int j = i;
		cout << "\t\t\t\t\t\t    " << (++j) << "." << "    " << cour[i] << endl;
	}

	while (file)
	{
		int tn;
		int cn;
		cout << endl << "\t\t\t\t\t | Enter Number of Teacher | : ";
		while (!(cin >> tn))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		cout << endl << "\t\t\t\t\t | Enter Number of Course  | : ";
		while (!(cin >> cn))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		file << "teacher name :" << teac[tn - 1] << endl;
		file << "course name :" << cour[cn - 1] << endl;

		int opp;
		cout << "\n";
		cout << "\t\t\t\t\t  Press 1 to assign more courses\n";
		cout << "\t\t\t\t\t  Press 0 to go back to the menu\n";
		cout << "\t\t\t\t\t  Enter : ";

		while (!(cin >> opp))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		if (opp == 0)
		{
			break;
		}
	}
}


void Course::view_teacher_courses()
{

	cout << "\n\n";
	cout << "\t\t\t\t\t-----------------------------------" << endl;
	cout << "\t\t\t\t\t|     Teacher Assigned Course      |" << endl;
	cout << "\t\t\t\t\t-----------------------------------" << endl << endl;

	string line;
	ifstream file("course_teacher.txt ");
	int i = 0;
	while (file)
	{
		getline(file, line);
		cout << "\t\t\t\t\t" << line << endl;
		i++;
		if (i == 2)
		{
			cout << endl;
			i = 0;
		}

	}
	int optionx = 0;
	cout << "\n";
	cout << "\t\t\t\t\t Enter 1 to go back to the menu" << endl;

	do
	{
		cout << "\n";
		cout << "\t\t\t\t\tEnter Again : ";
		while (!(cin >> optionx))
		{
			cout << endl;

			cout << "\t\t\t\t\tError! Enter again : ";
			system("color 4");

			cin.clear();
			cin.ignore(123, '\n');
		}
		if (optionx == 1)
		{
			break;
		}
	} while (exit);
}

void Course::display()				//This is a virtual void display function
{
	cout << "\n\n";
	cout << "\t\t\t\t\t| Welcome to update Courses |" << endl;
}

marks::marks()
{
	//Initializing with zero
	English = "";
	OOP = "";
	DLD = "";
	PS = "";
}

void marks::updateMarks()
{

	//string classs;
	//cout << "Enter Class : ";	cin >> classs;
	char opp;
	char marks_var;
	do
	{
		opp = '/0';
		cout << "\n\n\n";
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   1. Update By Class     |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   2. Update By Roll      |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|  Enter : ";	cin >> opp;

	} while (opp != '1' && opp != '2');

	switch (opp)
	{
	case '1':

	{
		string var[18];

		cout << "\n\n\n";
		cout << "\n\n\n";
		cout << "\t\t\t\t\t ---------------------------" << endl;
		cout << "\t\t\t\t\t | Enter A Valid Class     |" << endl;
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t |                         |" << endl;
		cout << "\t\t\t\t\t |  Enter  : ";
		cin >> var[16];

		cout << "\n";
		string sort = " Class             : " + var[16];
		int i = 0;
		ifstream student_file("student_data.txt");
		ofstream marks_file("marks_file.txt", ios::app);
		int a, b;
		system("cls");
		while (student_file)
		{
			getline(student_file, var[17]);

			var[i] = var[17];
			if (var[17] == sort)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t --------------------------" << endl;
				cout << "\t\t\t\t\t|                          |" << endl;
				cout << "\t\t\t\t\t| Input Assignment Numbers |" << endl;
				cout << "\t\t\t\t\t|          __/50           |" << endl;
				cout << "\t\t\t\t\t --------------------------" << endl;
				cout << "\n";
				cout << "\t\t\t\t\t" << var[3] << endl;
				cout << "\t\t\t\t\t  Assignment 1 : " << endl;

				//Check if the marks is greater than 50 or not
				do
				{
					cout << "\t\t\t\t\t  Enter : ";
					while (!(cin >> a))
					{
						cout << endl;
						cout << "\t\t\t\t\tError! Enter again : ";

						cin.clear();
						cin.ignore(123, '\n');
					}
					if (a > 50) ////////ya condition theek karo 50 say neechay b enter karo toh b cout kar dayta ha     a<=50 lagao
					{
						cout << "\t\t\t\t\tMarks should be less than or equal to 50 ! " << endl;
					}
				} while (a > 50);

				cout << "\t\t\t\t\t  Assignment 2 : " << endl;

				//Check if the marks is greater than 50 or not 
				do
				{
					cout << "\t\t\t\t\t  Enter : ";
					while (!(cin >> b))
					{
						cout << endl;
						cout << "\t\t\t\t\tError! Enter again : ";

						cin.clear();
						cin.ignore(123, '\n');
					}

					if (b > 50)
					{
						cout << "\t\t\t\t\tMarks should be less than or equal to 50 ! " << endl;
					}
				} while (b > 50);

				for (int j = 0; j < 6; j++)
				{
					marks_file << var[j] << endl;
				}
				marks_file << " assignment 1 :" << a << "/50" << endl;
				marks_file << " assignment 2 :" << b << "/50" << endl;
				marks_file << " total marks " << a + b << "/100 " << endl;
			}
			i++;
			if (i == 16)
			{
				i = 0;
			}

		}
		marks_file.close();
		student_file.close();

	}
	break;

	case '2':
	{
		string var[18];

		cout << "\n\n";
		cout << "\t\t\t\t\t------------------------------" << endl;
		cout << "\t\t\t\t\t|   Updating Student Marks   |" << endl;
		cout << "\t\t\t\t\t------------------------------" << endl;
		cout << "\t\t\t\t\t Enter Roll :";
		cin >> var[16];

		string sort = "\t\t\t\t\tstudent # " + var[16];
		int i = 0;
		ifstream student_file("student_data.txt");
		ofstream marks_file("marks_file.txt", ios::app);
		while (student_file)
		{
			getline(student_file, var[17]);
			int a, b;
			var[i] = var[17];
			if (var[17] == sort)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t --------------------------" << endl;
				cout << "\t\t\t\t\t|                          |" << endl;
				cout << "\t\t\t\t\t| Input Assignment Numbers |" << endl;
				cout << "\t\t\t\t\t|          __/50           |" << endl;
				cout << "\t\t\t\t\t --------------------------" << endl;
				cout << "\n";
				cout << "\t\t\t\t\t  Assignment 1 : " << endl;

				//Check if the marks is greater than 50 or not
				do
				{
					cout << "\t\t\t\t\t  Enter : ";
					while (!(cin >> a))
					{
						cout << endl;
						cout << "\t\t\t\t\tError! Enter again : ";

						cin.clear();
						cin.ignore(123, '\n');
					}
					if (a > 50) ////////ya condition theek karo 50 say neechay b enter karo toh b cout kar dayta ha     a<=50 lagao
					{
						cout << "\t\t\t\tMarks should be less than or equal to 50 ! " << endl;
					}
				} while (a > 50);

				cout << "\t\t\t\t\t  Assignment 2 : " << endl;

				//Check if the marks is greater than 50 or not 
				do
				{
					cout << "\t\t\t\t\t  Enter : ";
					while (!(cin >> b))
					{
						cout << endl;
						cout << "\t\t\t\t\tError! Enter again : ";

						cin.clear();
						cin.ignore(123, '\n');
					}
					if (b > 50) 
					{
						cout << "\t\t\t\tMarks should be less than or equal to 50 ! " << endl;
					}
				} while (b > 50);

				for (int j = 0; j < 6; j++)
				{
					marks_file << var[j] << endl;
				}
				marks_file << " assignment 1 :" << a  << endl;
				marks_file << " assignment 2 :" << b << endl;
				marks_file << " total marks " << a + b  << endl;
				//i = 0;
			}
			i++;
			if (i == 16)
			{
				i = 0;
			}

		}
		marks_file.close();
		student_file.close();
	}
	break;

	}
}

void marks::showMarks()
{
	string claaas, rol;

	char opp;
	//Now it will display all the students marks of the specific class
	do
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t| 1. Display Individually  |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t| 2. Display Whole Class   |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|  Enter : ";	cin >> opp;

	} while (opp != '1' && opp != '2');

	switch (opp)
	{
	case ('1'):
	{
		string line, sort;
		int count = 0;
		bool a = 0;
		cout << "\n\n\n";
		cout << "\t\t\t\t\t -------------------------" << endl;
		cout << "\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t| Input Valid Roll Number |" << endl;
		cout << "\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t|-------------------------|" << endl;
		cout << "\t\t\t\t\t| Enter  : ";	cin >> rol;

		sort = "\t\t\t\t\tstudent # " + rol;
		ifstream marks("marks_file.txt");
		while (marks)
		{
			getline(marks, line);
			{
				if (line == sort)
				{
					a = 1;
				}
				if (a)
				{
					cout << "\t\t\t\t\t" << line << endl;
					count++;
					if (count == 7)
					{
						a = 0;
						count == 0;
					}
				}
			}
		}
		marks.close();
		cout << "\t\t\t\t\tEnter 1 to go back to menu" << endl;
		char choicex;
		do
		{
			cout << "\t\t\t\t\t Enter : ";		cin >> choicex;
			if (choicex != '1')
			{
				cout << "\t\t\t\t\t Invalid Option !" << endl;
			}
		} while (choicex != '1');
		break;
	}
	case ('2'):
	{
		string var[6];
		string line;
		int i = 0;
		bool a = 0;

		cout << "\n\n\n" << endl;
		cout << "\t\t\t\t\t -------------------------" << endl;
		cout << "\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t|    Input Valid Class    |" << endl;
		cout << "\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t|-------------------------|" << endl;
		cout << "\t\t\t\t\t| Enter  : ";	cin >> claaas;

		ifstream marks("marks_file.txt");
		string sort = " Class             : " + claaas;
		while (marks)
		{
			getline(marks, line);
			{
				var[i] = line;
				if (line == sort)
				{
					a = 1;
				}
				if (a)
				{
					for (int j = 0; j < 6; j++)
					{
						cout << "\t\t\t\t\t" << var[j] << endl;
					}
					if (i == 6 || i == 7 || i == 8)
					{
						cout << "\t\t\t\t\t" << line << endl;

					}
					i++;
					if (i == 8)
					{
						a = 0;
						i = 0;
					}
				}
				if (!a)
				{
					i++;
				}
			}

		}
	}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void marks::updategrade()
{
	string claaas, rol;

	char opp;
	//Now it will display all the students marks of the specific class
	do
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t| 1. grade   Individually  |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|  Enter : ";	cin >> opp;

	} while (opp != '1' && opp != '2');

	switch (opp)
	{
	case ('1'):
	{
		string line, sort, line_2;
		int grading;
		int count = 0;
		bool a = 0;
		cout << "\n\n\n";
		cout << "\t\t\t\t\t -------------------------" << endl;
		cout << "\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t| Input Valid Roll Number |" << endl;
		cout << "\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t|-------------------------|" << endl;
		cout << "\t\t\t\t\t| Enter  : ";	cin >> rol;

		sort = "\t\t\t\t\tstudent # " + rol;
		ifstream marks("marks_file.txt");
		ofstream grade("grade_file.txt", ios::app);
		while (marks)
		{
			marks >> line;
			/*getline(marks, line);*/
			{
				if (line == "total_marks")
				{
					a = 1;
				}
				if (a)
				{
					marks >> line_2 >> grading;
					if (grading >= 90)
					{
						grade << rol << endl;
						grade << "A+" << endl;
					}
					else if (grading >= 85)
					{
						grade << rol << endl;
						grade << "A" << endl;
					}
					else if (grading >= 75)
					{
						grade << rol << endl;
						grade << "B+" << endl;
					}
					else if (grading >= 70)
					{
						grade << rol << endl;
						grade << "B" << endl;
					}
					else if (grading >= 65)
					{
						grade << rol << endl;
						grade << "C+" << endl;
					}
					else if (grading > 60)
					{
						grade << rol << endl;
						grade << "C" << endl;
					}
					else if (grading >= 55)
					{
						grade << rol << endl;
						grade << "C-" << endl;
					}
					else
					{
						grade << rol << endl;
						grade << "F" << endl;
					}
					count++;
					if (count == 7)
					{
						a = 0;
						count == 0;
					}
				}
			}
		}
		marks.close();
		grade.close();
		cout << "\t\t\t\t\tEnter 1 to go back to menu" << endl;
		char choicex;
		do
		{
			cout << "\t\t\t\t\t Enter : ";		cin >> choicex;
			if (choicex != '1')
			{
				cout << "\t\t\t\t\t Invalid Option !" << endl;
			}
		} while (choicex != '1');
		break;
	}


	}
}

//////////////////
void marks::display()				//This is a virtual void display function
{
	cout << "\n\n";
	cout << "\t\t\t\t\t|   Welcome to update Marks |" << endl;
}

void function::starting_display(char& op)
{
	do
	{
		cout << endl << "\t\t\t\t  | Welcome to School Manamgment System |" << endl << endl;
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   1. Enter Admin         |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   2. Enter Student       |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   3. Enter Teacher       |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   Enter : ";		cin >> op;
		if (op != '1' && op != '2' && op != '3')
		{
			cout << "\n\t\t\t\t\t    Invalid Input !" << endl;
		}

		system("cls");
	} while (op != '1' && op != '2' && op != '3');

}

void function::display_fun2(char& option)
{
	do
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\t --------------------------------------" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;
		cout << "\t\t\t\t\t|          Choose One Option           |" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;
		cout << "\t\t\t\t\t|--------------------------------------|" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;
		cout << "\t\t\t\t\t|  1. Edit Student Details             |" << endl;
		cout << "\t\t\t\t\t|  2. Edit Teacher Details             |" << endl;
		cout << "\t\t\t\t\t|  3. View All Students                |" << endl;
		cout << "\t\t\t\t\t|  4. View All Teachers                |" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;
		cout << "\t\t\t\t\t|  7. View Fee Status                  |" << endl;
		cout << "\t\t\t\t\t|  8. Assign Courses                   |" << endl;
		cout << "\t\t\t\t\t|  9. Exit                             |" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;
		cout << "\t\t\t\t\t|--------------------------------------|" << endl;
		cout << "\t\t\t\t\t|                                      |" << endl;
		cout << "\t\t\t\t\t|   Enter : ";		cin >> option;
		cout << "\t\t\t\t\t---------------------------------------" << endl << endl;

		if (option != '1' && option != '2' && option != '3' && option != '4' && option != '5'
			&& option != '6' && option != '7' && option != '8' && option != '9')
		{
			cout << "\t\t\t\t\t Invalid Input" << endl;
		}
		system("cls");
	} while (option != '1' && option != '2' && option != '3' && option != '4' && option != '5'
		&& option != '6' && option != '7' && option != '8' && option != '9');
}

void function::student_menu(char& student_option)
{
	do
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   1. Edit Saved Data     |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   2. Enter New Data      |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|  Enter : ";	cin >> student_option;

		if (student_option != '1' && student_option != '2')
		{
			cout << "'\t\t\t\t\t Invalid Input" << endl;
		}
		system("cls");
	} while (student_option != '1' && student_option != '2');
}

void function::edit_student_menu()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t -----------------------------" << endl;
	cout << "\t\t\t\t\t | Enter A Valid Roll Number |" << endl;
	cout << "\t\t\t\t\t ----------------------------" << endl;
	cout << "\t\t\t\t\t |                           |" << endl;
	cout << "\t\t\t\t\t |  Enter  : ";
}

void function::teacher_menu(char& teacher_option)
{
	do
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   1. Edit Saved Data     |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   2. Enter New Data      |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|  Enter : ";	cin >> teacher_option;

		if (teacher_option != '1' && teacher_option != '2')
		{
			cout << "\t\t\t\t\t Invalid Input" << endl;
		}
		system("cls");
	} while (teacher_option != '1' && teacher_option != '2');
}

void function::student_edit_menu()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t --------------------------" << endl;
	cout << "\t\t\t\t\t |   Enter A Valid CNIC   |" << endl;
	cout << "\t\t\t\t\t --------------------------" << endl;
	cout << "\t\t\t\t\t |                        |" << endl;
	cout << "\t\t\t\t\t |  Enter  : ";
}

void function::display_final()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t -----------------------" << endl;
	cout << "\t\t\t\t\t|                       |" << endl;
	cout << "\t\t\t\t\t|         Good bye      |" << endl;
	cout << "\t\t\t\t\t|                       |" << endl;
	cout << "\t\t\t\t\t -----------------------" << endl;
}

void function::module2_menu_student(char& opp)
{
	do
	{
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|    1. View Marks         |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|    2. View Fee Status    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|    3. Exit               |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   Enter : ";		cin >> opp;

		if (opp != '1' && opp != '2' && opp != '3')
		{
			cout << "\t\t\t\t\t Invalid Input" << endl;
		}
		system("cls");
	} while (opp != '1' && opp != '2' && opp != '3');

}

void function::module2_fun2()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t -------------------------" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t|     Input Your Data     |" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t -------------------------" << endl;
}

void function::teacher_mod(char& teacher_option)
{
	do
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t| 1. View Your timetable   |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t| 2. Update Student Marks  |" << endl;
		cout << "\t\t\t\t\t| 3. update student grade  |" << endl;
		cout << "\t\t\t\t\t| 4. Exit                  |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|  Enter : ";	cin >> teacher_option;

		if (teacher_option != '1' && teacher_option != '2' && teacher_option != '3')
		{
			cout << "\t\t\t\t\t Invalid Input" << endl;
		}
		system("cls");
	} while (teacher_option != '1' && teacher_option != '2' && teacher_option != '3');
}


void function::edit_student_display()
{
	cout << "\n\n";
	cout << "\t\t\t\t\t--------------------------------" << endl;
	cout << "\t\t\t\t\t|      Editing Student Data    |" << endl;
	cout << "\t\t\t\t\t--------------------------------" << endl << endl;
}

void function::edit_teacher_display()
{
	cout << "\n\n";
	cout << "\t\t\t\t\t--------------------------------" << endl;
	cout << "\t\t\t\t\t|      Editing Teacher Data    |" << endl;
	cout << "\t\t\t\t\t--------------------------------" << endl << endl;
}
void Teacher::edit_TeacherData(string cnic)
{

	string var[6];
	bool z = 0;
	int count = 0;
	var[4] = cnic;
	string sort = "\t\t\t\t\tTeacher # " + var[4];

	//Declaring files
	ifstream oldfile("teacher_data.txt");					//It will open file to read data
	ofstream newfile("new_teacher_data.txt", ios::app);		//It will make new file 

	while (oldfile)
	{
		getline(oldfile, var[5]);		// This will read lines from old file
		if (newfile.is_open())			// Condition to check either file is open or not
		{
			if (var[5] == sort)
			{
				z = 1;
			}
			if (z)
			{
				if (count != 15)
				{
					if (count == 9 || count == 10 || count == 12 || count == 13)
					{
						if (count == 9)
						{
							cout << "\t\t\t\t\t Enter new Qualification : ";		/*cin >> var[0];*/ cin.ignore();	getline(cin, var[0]);
							newfile << " Qualification: ";		 newfile << var[0] << endl;
						}
						else if (count == 10)
						{
							cout << "\t\t\t\t\t Enter new Contact-No    : ";		/*cin >> var[1];*/ cin.ignore();	getline(cin, var[1]);
							newfile << " Contact-No   : ";		 newfile << var[1] << endl;
						}
						else if (count == 12)
						{
							cout << "\t\t\t\t\t Enter new Address       : ";		/*cin >> var[2];*/ cin.ignore();	getline(cin, var[2]);
							newfile << " nee Address  : ";		 newfile << var[2] << endl;
						}
						else if (count == 13)
						{
							cout << "\t\t\t\t\t Enter new Salary        : ";		/*cin >> var[3];*/ cin.ignore();	getline(cin, var[3]);
							newfile << " Salary       : ";		 newfile << var[3] << endl;
						}
						count++;
					}
					else
					{
						count++;
						newfile << var[5] << endl;
					}
				}
				else if (count == 15)		//This case will execute only when count will be 15 
				{
					count++;
					newfile << var[5] << endl;
				}
			}
			else
			{
				newfile << var[5] << endl;
			}
		}
		else
		{
			cout << "\t\t\t\t\tUnable to open file" << endl;
		}
	}

	oldfile.close();
	newfile.close();
	remove("teacher_data.txt");     //It will delete the old file
	rename("new_teacher_data.txt", "teacher_data.txt");   //This will change the name of the file
}

void function::loading()
{
	cout << "\n\n";
	cout << "\t\t\t\t\t\t" << "   |     starting        |\n" << "\t\t";

	for (int i = 0; i < 75; i++)
	{

		cout << "|";
		system("color 3");
		Sleep(15);

	}
	cout << endl;
	system("color 7");
	system("cls");

}