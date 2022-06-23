#include <iostream>
#include <string>
#include <conio.h>
#include "Header.h"
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
	int input;
	string adminUser = "admin";
	string adminPass = "1234";
	string hrUser = "hr";
	string hrPass = "1234";

	Tutor t;
	int tutorChoice;

	t.predefRecord();

	m:

		system("cls");
		cout << "------------------------------------" << endl;
		cout << "  Please insert OPTION to continue  " << endl;
		cout << "  1) Login as Admin                 " << endl;
		cout << "  2) Rate Tutor Performance         " << endl;
		cout << "  3) Login as HR Manager            " << endl;
		cout << "  4) Exit                           " << endl;
		cout << "------------------------------------" << endl;
		cout << "  Option : ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if(cin.fail()){			
		 	cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			// cout<<"----------------------------"<<endl;
			// cout<<"  Key in 1 , 2 or 3 only !  "<<endl;
			// cout<<"----------------------------"<<endl;
			goto m;
		}

	switch (input)
	{
		case 1:{
			cout << "Please enter the username: " ;
			cin >> adminUser;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter the password: " ;
			cin >> adminPass;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (adminUser == "admin" && adminPass == "1234")
			{
				
				p:
				system("cls");
				int adminChoice;
				cout << "-------------------------------------------------------------------------" << endl;
				cout << "  1)  Add a Tutor Record                                                 " << endl;
				cout << "  2)  Display All Records                                                " << endl;
				cout << "  3)  Search a Tutor by Tutor ID                                         " << endl;
				cout << "  4)  Search Tutors by overall performance (Rating)                      " << endl;
				cout << "  5)  Sort and display by Tutors ID in ascending order                   " << endl;
				cout << "  6)  Sort and display by Tutors Hourly Pay Rate in ascending order      " << endl;
				cout << "  7)  Sort and display by Tutors Overall Performance in ascending order  " << endl;
				cout << "  8)  Modify a Tutor Record                                              " << endl;
				cout << "  9)  Delete a Tutor Record                                              " << endl;
				cout << "  10) Exit                                                               " << endl;
				cout << "-------------------------------------------------------------------------" << endl;
				cout << "  Please enter Your Choice : ";
				cin >> adminChoice;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if(cin.fail()){			
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					goto p;
				}

				switch (adminChoice)
				{
					case 1:
						system("cls");
						t.add_record();
						break;
					case 2:
						system("cls");
						t.displayRecordInTable();
						break;
					case 3:
						system("cls");
						t.search_byID();
						break;
					case 4:
						system("cls");
						t.searchByRating();
						break;
					case 5:
						system("cls");
						t.insertionSort(t.head);
						t.displayRecordInTable();
						break;
					case 6:
						system("cls");
						t.insertionSortByPayRate(t.head);
						t.displayRecordInTable();
						break;
					case 7:
						system("cls");
						t.insertionSortByRating(t.head);
						t.displayRecordInTable();
						break;
					case 8:
						system("cls");
						t.modify_record();
						break;
					case 9:
						system("cls");
						t.delete_record();
						break;
					case 10:
						goto m;
						break;
					default:
						cout<<"----------------------------------------"<<endl;
						cout<<"  Invalid Choice.. Please Try Again...  "<<endl;
						cout<<"----------------------------------------"<<endl;
						break;
				}

				_getch();
				goto p;
			} else{
				cout<<"----------------------------------"<<endl;
				cout<<"  Invalid Username or Password !  "<<endl;
				cout<<"----------------------------------"<<endl;
			}
			break;
		}
		
		case 2:{
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "             TUTOR LIST              " << endl;
			cout << "-------------------------------------" << endl;
			cout << "ID      Name                         " << endl;
			cout << "-------------------------------------" << endl;
			t.displayTutorList();
			cout << "-------------------------------------" << endl;
			t.searchTutor();
			
			break;
		}

		case 3:{			
			cout << "Please enter the username: " ;
			cin >> hrUser;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter the password: " ;
			cin >> hrPass;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (hrUser == "hr" && hrPass == "1234")
			{
				h:
					system("cls");
					int hrChoice;
					cout << "-----------------------------" << endl;
					cout << "  1)  Modify Tutor Record    " << endl;
					cout << "  2)  Delete Tutor Record    " << endl;
					cout << "  3)  Exit                   " << endl;
					cout << "-----------------------------" << endl;
					cout << "  Please enter Your Choice : ";
					cin >> hrChoice;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if(cin.fail()){			
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						goto h;
					}

					switch (hrChoice)
					{
						case 1:
							system("cls");
							t.hrModifyTutor();
							break;
						case 2:
							system("cls");
							t.delete_record();
							break;
						case 3:
							goto m;
							break;
						default:
							cout<<"----------------------------------------"<<endl;
							cout<<"  Invalid Choice.. Please Try Again...  "<<endl;
							cout<<"----------------------------------------"<<endl;
							break;
					}
			} else {
				cout<<"----------------------------------"<<endl;
				cout<<"  Invalid Username or Password !  "<<endl;
				cout<<"----------------------------------"<<endl;
			}

			break;
		}

		case 4:{
			system("cls");
			cout << "--------------------------------------" << endl;
			cout << "      Application Exit! Goodbye!      " << endl;
			cout << "--------------------------------------" << endl;

			exit(0);
			break;
		}
		
		default:
			cout<<"-----------------------------"<<endl;
			cout<<"  Key in 1, 2, 3 or 4 only ! "<<endl;
			cout<<"-----------------------------"<<endl;
			break;

	}
	_getch();
	goto m;
}

