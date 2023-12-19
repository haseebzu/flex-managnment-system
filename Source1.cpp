#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"header.h"
#include<SFML/GRAPHICS.hpp>
using namespace sf;
using namespace std;
int main()
{
	char op = '\0';
	function f;
	marks h;
	string cnic;
	Student w;
	Teacher x;
	Course y;
	marks z;
	string roll;
	RenderWindow window(VideoMode(1300, 850), "Flex");
	while (window.isOpen())
	{
		Font f;
		if (!f.loadFromFile("Bebas-Regular.ttf"))
		{
			std::cout << "failed";
		}
		//window design
		Text welcome, choose;
		welcome.setFont(f);
		welcome.setFillColor(Color::White);
		welcome.setCharacterSize(50.f);
		welcome.setPosition(Vector2f(400, 0));
		welcome.setString("Welcome To Flex");
		choose.setFont(f);
		choose.setFillColor(Color::White);
		choose.setCharacterSize(25.f);
		choose.setPosition(Vector2f(400, 650));
		choose.setString("press any key to continue");

		window.draw(welcome);
		window.draw(choose);
		window.display();

		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				window.close();
		}

	}

	cout << "\n\n\n";
	cout << "\t\t\t\t\t ||  Flex Managment system  || " << endl;

	//f.show_progress_bar(clog);	//For displaying loading function
	f.loading();
	f.starting_display(op);		//For displaying starting menu

	switch (op)
	{
	case ('1'):

		cout << endl;
		w.log_in_admin();		//For logging into admin
		w.display();			//For displaying welcome message

		char student_option;
		char teacher_option;


		do
		{
			char option;
			f.display_fun2(option);		//Print menu for admin
			switch (option)
			{
			case '1':

			{
				f.student_menu(student_option);		//Print menu for weather edit or add students

				switch (student_option)
				{
				case '1':
				{

					f.edit_student_menu();		// Print menu for edit student detail
					cin >> roll;				// Taking roll number as input
					f.edit_student_display();
					w.edit_StudentData(roll);	// Function for editing student from a file

					cout << "\t\t\t\t\tEdited Successfully !" << endl;
					system("cls");
					break;
				}

				case ('2'):
				{
					w.enterData();				//Function for adding new students
					break;
				}
				}
				break;

			}


			case '2':
			{
				f.teacher_menu(teacher_option);		//Print menu for weather edit or add teacher

				switch (teacher_option)
				{
				case ('1'):

					f.student_edit_menu();
					cin >> cnic;
					x.edit_TeacherData(cnic);
					cout << "\t\t\t\t\tEdited Successfully !" << endl;
					system("cls");
					break;

				case ('2'):

					f.edit_teacher_display();
					x.enter_TeacherData();			//Function for adding new teachers
					system("cls");
					break;
				}

				break;
			
			}
			case ('3'):

				w.diaplay_student();			//Function for displaying student details
				break;

			case ('4'):

				x.diaplay_teacher();			//Function for displaying teacher details
				break;

			case ('5'):

				marks();						//First it will intialize all with zero
				z.updateMarks();				//Function for updating marks
				cout << "\t\t\t\t\t Updated Successfully !" << endl;
				system("cls");
				break;

			case ('6'):

				z.showMarks();					//Function for displaying marks
				system("cls");
				break;

			case ('7'):

				w.feeStatus();					//Function for displaying fee
				system("cls");
				break;

			case ('8'):

				y.assignCourses();				//Function for assigning courses to teacher
				system("cls");
				break;

			case ('9'):

				f.display_final();				//Function for displaying Credits
				exit(0);
				break;
			}
		} while (exit);

		break;

		//////////////////////////////////////////////////////////////////////
		//																	//
		//                          Module ( 2 )                            //
		//																	//
		//////////////////////////////////////////////////////////////////////

	case ('2'):


		w.log_in_student();				//Function for logging in student
		system("cls");


		do
		{
			char opp;
			string rr;
			cout << "\n\n";
			x.display();
			f.module2_menu_student(opp);	//Function for displaying menu for student
			switch (opp)
			{
			case ('1'):

				w.showMarks_Student();	//This will show student marks
				system("cls");
				break;

			case ('2'):

				w.feeStatus();			//This will show student fee
				system("cls");
				break;

			case ('3'):

				f.display_final();		//Function for displaying credits
				exit(0);
				break;
			}
		} while (exit);
		break;

		//////////////////////////////////////////////////////////////////////
		//																	//
		//                          Module ( 3 )                            //
		//																	//
		//////////////////////////////////////////////////////////////////////

	case ('3'):
	{

		do
		{
			char option9;

			f.teacher_mod(option9);
			switch (option9)
			{
			case ('1'):

				y.view_teacher_courses();
				system("cls");
				break;
			case ('2'):

				z.updateMarks();
				system("cls");
				break;
			
			case('3'):
				z.updategrade();
				system("cls");
				break;
			case ('4'):

				f.display_final();		//For displaying Credits
				exit(0);
				break;
			}
		} while (exit);
	}
	}

	system("pause");
	return 0;
}


