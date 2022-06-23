#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include <bits/stdc++.h>
#include <regex>
#include <limits>

using namespace std;

struct Rating{
  	
	list<double> tutorList;
	double calRating;
};

class Tutor
{
	int tutorID;
	string tutorName;
	string tutorDateJoined;
	string tutorDateTerminated;
	double tutorHourlyRate;
	string tutorPhone;
	string tutorAddress;
	Rating tutorRating;
	string tuitionCentreCode;
	string tuitionCentreName;
	string subjectCode;
	string subjectName;
	Tutor *sorted;
	Tutor *next;

public:
	Tutor *head = NULL;
	
	//Tutor *tmp = NULL;

	//Validation - check whether phoneNumber is valid
	bool is_tutorPhone_valid(const string& tutorPhone)
	{
	// define a regular expression
		const std::regex pattern
		("[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}");

	// try to match the string with the regular expression
	return std::regex_match(tutorPhone, pattern);
	}

	//Validation - check whether date is valid
	bool is_date_valid(const string& tutorDateJoined)
	{
	// define a regular expression
		const std::regex pattern
		("\\b\\d{2}[-]\\d{2}[-]\\d{4}\\b");

	// try to match the string with the regular expression
	return std::regex_match(tutorDateJoined, pattern);
	}

	
	void predefRecord(){
		Tutor *tutor1 = new Tutor;
		Tutor *tutor2 = new Tutor;
		Tutor *tutor3 = new Tutor;
		Tutor *tutor4 = new Tutor;

		tutor1 ->tutorID=1;
		tutor1 ->tutorName="Jin Yang";
		tutor1 ->tutorDateJoined="1/1/2019";
		tutor1 ->tutorDateTerminated="-";
		tutor1 ->tutorHourlyRate=60;
		tutor1 ->tutorPhone="000-000-0000";
		tutor1 ->tutorAddress="Bukit Jalil";
		//tutor1 ->tutorRating=5;
		tutor1 ->tuitionCentreCode="TC001";
		tutor1 ->tuitionCentreName="APU Tuition Centre";
		tutor1 ->subjectCode="SB001";
		tutor1 ->subjectName="Math";
		tutor1 ->next=tutor2;

		tutor2 ->tutorID=2;
		tutor2 ->tutorName="Ryan";
		tutor2 ->tutorDateJoined="1/1/2019";
		tutor2 ->tutorDateTerminated="-";
		tutor2 ->tutorHourlyRate=30;
		tutor2 ->tutorPhone="000-000-0000";
		tutor2 ->tutorAddress="Cheras";
		//tutor2 ->tutorRating=4;
		tutor2 ->tuitionCentreCode="TC002";
		tutor2 ->tuitionCentreName="APIIT Tuition Centre";
		tutor2 ->subjectCode="SB002";
		tutor2 ->subjectName="Computer";
		tutor2 ->next=tutor3;

		tutor3 ->tutorID=3;
		tutor3 ->tutorName="ZiHao";
		tutor3 ->tutorDateJoined="1/1/2019";
		tutor3 ->tutorDateTerminated="-";
		tutor3 ->tutorHourlyRate=90;
		tutor3 ->tutorPhone="000-000-0000";
		tutor3 ->tutorAddress="Ampang";
		//tutor3 ->tutorRating=3;
		tutor3 ->tuitionCentreCode="TC003";
		tutor3 ->tuitionCentreName="ABU Tuition Centre";
		tutor3 ->subjectCode="SB003";
		tutor3 ->subjectName="Science";
		tutor3 ->next=tutor4;
		
		tutor4 ->tutorID=4;
		tutor4 ->tutorName="Vechi";
		tutor4 ->tutorDateJoined="1/1/2019";
		tutor4 ->tutorDateTerminated="-";
		tutor4 ->tutorHourlyRate=20;
		tutor4 ->tutorPhone="000-000-0000";
		tutor4 ->tutorAddress="Kajang";
		//tutor3 ->tutorRating=3;
		tutor4 ->tuitionCentreCode="TC004";
		tutor4 ->tuitionCentreName="AJU Tuition Centre";
		tutor4 ->subjectCode="SB004";
		tutor4 ->subjectName="English";
		tutor4 ->next=NULL;
		
		head=tutor1;
	}

	void add_record()
	{
		Tutor *new_tutor = new Tutor;

		cout << "Please Enter The Tutor ID : ";
		cin >> tutorID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "------------------------------" << endl;
			cout << "  Please insert number only!  " << endl;
			cout << "------------------------------" << endl; 
			cout << "Please Enter The Tutor ID : ";
			cin >> tutorID;			
		}

		cout << "Please enter the tutor name : ";
		cin >> tutorName;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please enter the tutor date joined : ";
		cin >> tutorDateJoined;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please enter the tutor date teminated : ";
		cin >> tutorDateTerminated;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please enter the tutor hourly rate : ";
		cin >> tutorHourlyRate;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "-------------------------------------" << endl;
			cout << "     Please insert number only!      " << endl;
			cout << "-------------------------------------" << endl; 
			cout << "Please enter the tutor hourly rate : ";
			cin >> tutorHourlyRate;
		}
		
		cout << "Please enter the tutor phone : ";
		cin >> tutorPhone;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while(!is_tutorPhone_valid(tutorPhone)) {
			cout << "-------------------------------------" << endl;
			cout << "         Invalid Phone Number        " << endl;
			cout << "         Format '000-000-0000'       " << endl; 
			cout << "-------------------------------------" << endl;
			cout << "Please insert correct Phone Number : ";
			cin.clear();
			cin >> tutorPhone;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << "Please enter the tutor address : ";
		cin >> tutorAddress;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		// cout << "Please enter the tutor rating: " << endl;
		// cin >> tutorRating;
		// cin.ignore();
		
		cout << "Please enter the tuition centre code : ";
		cin >> tuitionCentreCode;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please enter the tuition centre name : ";
		cin >> tuitionCentreName;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please enter the tuition subject code : ";
		cin >> subjectCode;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please enter the tuition subject name : ";
		cin >> subjectName;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		new_tutor->tutorID = tutorID;
		new_tutor->tutorName = tutorName;
		new_tutor->tutorDateJoined = tutorDateJoined;
		new_tutor->tutorDateTerminated = tutorDateTerminated;
		new_tutor->tutorHourlyRate = tutorHourlyRate;
		new_tutor->tutorPhone = tutorPhone;
		new_tutor->tutorAddress = tutorAddress;
		//new_tutor->tutorRating = tutorRating;
		new_tutor->tuitionCentreCode = tuitionCentreCode;
		new_tutor->tuitionCentreName = tuitionCentreName;
		new_tutor->subjectCode = subjectCode;
		new_tutor->subjectName = subjectName;
		new_tutor->next = NULL;

		if (head == NULL)
		{
			head = new_tutor;

		}
		else
		{
			Tutor* ptr = head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new_tutor;

		}
		writeFile();
		cout << "Tutor Record added successfully ! ";
	}
		
	void writeFile(){

		// Create and open a text file
		ofstream tutorFile("tutor.txt",ofstream::trunc);

		// Write to the file
		Tutor* ptr = head;
		tutorFile<<"ID \t Name \t Date Joined \t Date Terminated \t Hourly Rate \t Phone No \t Address \t Rating \t Centre Code \t Centre Name \t Subject Code \t Subject Name"<<endl;
			while (ptr != NULL)
			{
				tutorFile << ptr->tutorID << "\t"
						  << ptr->tutorName << "\t"
						  << ptr->tutorDateJoined << "\t"
						  << ptr->tutorDateTerminated << "\t"
						  << ptr->tutorHourlyRate << "\t"
						  << ptr->tutorPhone << "\t"
						  << ptr->tutorAddress << "\t"
						  //<< ptr->tutorRating << "\t"
						  << ptr->tuitionCentreCode << "\t"
						  << ptr->tuitionCentreName << "\t"
						  << ptr->subjectCode << "\t"
						  << ptr->subjectName << endl;
						  ptr = ptr->next;
			}

		// Close the file
		tutorFile.close();
	}

	void readFile(){
		string tutorRecord;

		// Read from the text file
		ifstream tutorFile("tutor.txt");

		// Use a while loop together with the getline() function to read the file line by line
		while (getline (tutorFile, tutorRecord)) {
		// Output the text from the file
		cout << tutorRecord;
		}

		// Close the file
		tutorFile.close();
	}
	

	void displayRecordInTable()
	{
		if (head == NULL)
		{
			cout << "The Record is Empty.....";
		}
		else
		{
			Tutor* ptr = head;
			cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<"ID      Name        Date Joined        Date Terminated        Hourly Rate        Phone No        Address        Rating    Centre Code    Centre Name        Subject Code    Subject Name "<<endl;
			cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			while (ptr != NULL)
			{
				cout << left << setw(8) << setfill(' ') << ptr->tutorID 
						  << left << setw(14) << setfill(' ') << ptr->tutorName 
						  << left << setw(22) << setfill(' ') << ptr->tutorDateJoined 
						  << left << setw(20) << setfill(' ') << ptr->tutorDateTerminated 
						  << left << setw(17) << setfill(' ') << ptr->tutorHourlyRate 
						  << left << setw(15) << setfill(' ') << ptr->tutorPhone 
						  << left << setw(19) << setfill(' ') << ptr->tutorAddress 
						  << left << setw(12) << setfill(' ') << (double)ptr->tutorRating.calRating 
						  << left << setw(13) << setfill(' ') << ptr->tuitionCentreCode 
						  << left << setw(20) << setfill(' ') << ptr->tuitionCentreName 
						  << left << setw(17) << setfill(' ') << ptr->subjectCode 
						  << left << setw(17) << setfill(' ') << ptr->subjectName << endl;
						  ptr = ptr->next;
			}
		}
	}

	void searchByRating(){
		if (head == NULL)
		{
			cout << "The Record is Empty....";
		}
		else
		{
			int found = 0;
			double inputRating;

			s:
			cout << "Enter a Rating to Search Tutor by Rating: ";
			cin >> inputRating;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if ((inputRating < 1) || (inputRating > 5))
			{	
				cout << "------------------------" << endl;
				cout << "  Only number 1 to 5 !  " << endl;
				cout << "------------------------" << endl;
				// cout << "Rate Tutor [1 - 5] : ";
				// cin >> studentRate;
				goto s;										
				
			} else {
				Tutor* ptr = head;

				while (ptr != NULL)
				{
					if (inputRating == ptr->tutorRating.calRating)
					{
						cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
						cout<<"ID      Name        Date Joined        Date Terminated        Hourly Rate        Phone No        Address        Rating    Centre Code    Centre Name        Subject Code    Subject Name "<<endl;
						cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
						// cout << "Tutor ID:             " << ptr->tutorID << endl;
						// cout << "Tutor name:           " << ptr->tutorName << endl;
						// cout << "Tutor date joined:    " << ptr->tutorDateJoined << endl;
						// cout << "Tutor date teminated: " << ptr->tutorDateTerminated << endl;
						// cout << "Tutor hourly rate:    " << ptr->tutorHourlyRate << endl;
						// cout << "Tutor phone:          " << ptr->tutorPhone << endl;
						// cout << "Tutor address:        " << ptr->tutorAddress << endl;
						// cout << "Tutor rating:         " << ptr->tutorRating.calRating << endl;
						// cout << "Tuition centre code:  " << ptr->tuitionCentreCode << endl;
						// cout << "Tuition centre name:  " << ptr->tuitionCentreName << endl;
						// cout << "Tuition subject code: " << ptr->subjectCode << endl;
						// cout << "Tuition subject name: " << ptr->subjectName << endl;
						cout << left << setw(8) << setfill(' ') << ptr->tutorID 
							<< left << setw(14) << setfill(' ') << ptr->tutorName 
							<< left << setw(22) << setfill(' ') << ptr->tutorDateJoined 
							<< left << setw(20) << setfill(' ') << ptr->tutorDateTerminated 
							<< left << setw(17) << setfill(' ') << ptr->tutorHourlyRate 
							<< left << setw(15) << setfill(' ') << ptr->tutorPhone 
							<< left << setw(19) << setfill(' ') << ptr->tutorAddress 
							<< left << setw(12) << setfill(' ') << (double)ptr->tutorRating.calRating 
							<< left << setw(13) << setfill(' ') << ptr->tuitionCentreCode 
							<< left << setw(20) << setfill(' ') << ptr->tuitionCentreName 
							<< left << setw(17) << setfill(' ') << ptr->subjectCode 
							<< left << setw(17) << setfill(' ') << ptr->subjectName << endl;
						found++;
					}
					ptr = ptr->next;
				}
				if (found == 0)
				{
					cout << "No Tutor with this Rating ! ";
				}
			}
		}
	}

	void displayTutorList(){
		if (head == NULL)
		{
			cout << "The Record is Empty.....";
		}
		else
		{
			Tutor* ptr = head;

			
			while (ptr != NULL)
			{
				
				cout << left << setw(9) << setfill(' ') << ptr->tutorID 
					 << ptr->tutorName << endl;
				
				ptr = ptr->next;
			}
		}
	}

	void searchTutor()
	{
		double studentRate;
		if (head == NULL)
			{
				cout << "The Record is Empty....";
			}
			else
			{
				int found = 0;
				cout << "Enter a Tutor ID to Rate : ";
				cin >> tutorID;
				Tutor* ptr = head;
				while (ptr != NULL)
				{
					if (tutorID == ptr->tutorID)
					{
						
						cout << "Tutor ID :   " << ptr->tutorID << endl;
						cout << "Tutor name : " << ptr->tutorName << endl;
						r:
						cout << "Rate Tutor [1 - 5] : ";
						cin >> studentRate;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						if ((studentRate < 1) || (studentRate > 5))
						{	
							cout << "------------------------" << endl;
							cout << "  Only number 1 to 5 !  " << endl;
							cout << "------------------------" << endl;
							// cout << "Rate Tutor [1 - 5] : ";
							// cin >> studentRate;
							goto r;
							break;						
							
						} else {
							ptr->tutorRating.tutorList.push_back(double(studentRate));
							cout<<"Thank you for your Feedback ! "<<endl;

							list<double>::iterator it;
							double sumRating;
							for(it=ptr->tutorRating.tutorList.begin(); it!=ptr->tutorRating.tutorList.end(); it++)
							{
								//cout <<  *it << " ";
								sumRating = sumRating + *it;
							}

							ptr->tutorRating.calRating= sumRating / ptr->tutorRating.tutorList.size();
							//cout << ptr->tutorRating.calRating;

							found++;
						}
					}
					ptr = ptr->next;
				}
				if (found == 0)
				{
					cout << "Tutor Doesn't Exist ! ";
				}
			}
	}

	void display_record()
	{
		if (head == NULL)
		{
			cout << "The Record is Empty.....";
		}
		else
		{
			Tutor* ptr = head;
			
			while (ptr != NULL)
			{
				cout << "Tutor ID: " << ptr->tutorID << endl;
				cout << "Tutor name: " << ptr->tutorName << endl;
				cout << "Tutor date joined: " << ptr->tutorDateJoined << endl;
				cout << "Tutor date teminated: " << ptr->tutorDateTerminated << endl;
				cout << "Tutor hourly rate: " << ptr->tutorHourlyRate << endl;
				cout << "Tutor phone: " << ptr->tutorPhone << endl;
				cout << "Tutor address: " << ptr->tutorAddress << endl;
				cout << "Tutor rating: " << ptr->tutorRating.calRating << endl;
				cout << "Tuition centre code: " << ptr->tuitionCentreCode << endl;
				cout << "Tuition centre name " << ptr->tuitionCentreName << endl;
				cout << "Tuition subject code: " << ptr->subjectCode << endl;
				cout << "Tuition subject name: " << ptr->subjectName << endl;
				ptr = ptr->next;
			}
		}
	}

	void search_byID()
	{
		if (head == NULL)
		{
			cout << "The Record is Empty....";
		}
		else
		{
			int found = 0;
			cout << "Enter a Tutor ID for Search: ";
			cin >> tutorID;
			Tutor* ptr = head;
			while (ptr != NULL)
			{
				if (tutorID == ptr->tutorID)
				{
					cout << "Tutor ID:             " << ptr->tutorID << endl;
					cout << "Tutor name:           " << ptr->tutorName << endl;
					cout << "Tutor date joined:    " << ptr->tutorDateJoined << endl;
					cout << "Tutor date teminated: " << ptr->tutorDateTerminated << endl;
					cout << "Tutor hourly rate:    " << ptr->tutorHourlyRate << endl;
					cout << "Tutor phone:          " << ptr->tutorPhone << endl;
					cout << "Tutor address:        " << ptr->tutorAddress << endl;
					cout << "Tutor rating:         " << ptr->tutorRating.calRating << endl;
					cout << "Tuition centre code:  " << ptr->tuitionCentreCode << endl;
					cout << "Tuition centre name:  " << ptr->tuitionCentreName << endl;
					cout << "Tuition subject code: " << ptr->subjectCode << endl;
					cout << "Tuition subject name: " << ptr->subjectName << endl;
					found++;
				}
				ptr = ptr->next;
			}
			if (found == 0)
			{
				cout << "Tutor Doesn't Exist ! ";
			}
		}
	}

	void modify_record()
	{
		// if head is NULL
		if (head == NULL)
		{
			cout << "The Record is Empty....";
		}
		else
		{
			int found = 0;
			cout << "Enter a tutor ID for Modify the record: ";
			cin >> tutorID;
			Tutor* ptr = head;
			while (ptr != NULL)
			{
				if (tutorID == ptr->tutorID)
				{
					// cout << "Tutor ID : " << ptr->tutorID << endl;
					// cin >> ptr->tutorID;

					//cout << "Tutor name : " << ptr->tutorName << endl;
					cout << "New name : ";
					cin >> ptr->tutorName;

					//cout << "Tutor date joined : " << ptr->tutorDateJoined << endl;
					cout << "New date joined : ";
					cin >> ptr->tutorDateJoined;

					//cout << "Tutor date teminated : " << ptr->tutorDateTerminated << endl;
					cout << "New date terminated : ";
					cin >> ptr->tutorDateTerminated;

					//cout << "Tutor hourly rate : " << ptr->tutorHourlyRate << endl;
					cout << "New hourly rate : ";
					cin >> ptr->tutorHourlyRate;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if(cin.fail()){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "------------------------------" << endl;
						cout << "  Please insert number only!  " << endl;
						cout << "------------------------------" << endl; 
						cout << "New hourly rate : ";
						cin >> tutorHourlyRate;
					}

					//cout << "Tutor phone : " << ptr->tutorPhone << endl;
					cout << "New phone : ";
					cin >> ptr->tutorPhone;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					while(!is_tutorPhone_valid(tutorPhone)) {
						cout << "-------------------------------------" << endl;
						cout << "         Invalid Phone Number        " << endl;
						cout << "         Format '000-000-0000'       " << endl; 
						cout << "-------------------------------------" << endl;
						cout << "Please insert correct Phone Number : ";
						cin.clear();
						cin >> tutorPhone;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

					//cout << "Tutor address : " << ptr->tutorAddress << endl;
					cout << "New address : ";
					cin >> ptr->tutorAddress;

					//cout << "Tuition centre code : " << ptr->tuitionCentreCode << endl;
					cout << "New tuition centre code : ";
					cin >> ptr->tuitionCentreCode;

					//cout << "Tuition centre name : " << ptr->tuitionCentreName << endl;
					cout << "New tuition centre name : ";
					cin >> ptr->tuitionCentreName;

					//cout << "Tuition subject code : " << ptr->subjectCode << endl;
					cout << "New subject code : ";
					cin >> ptr->subjectCode;

					//cout << "Tuition subject name : " << ptr->subjectName << endl;
					cout << "New subject name : ";
					cin >> ptr->subjectName;

					cout << "Tutor Record Updated Successfully... ";
					found++;
				}
				ptr = ptr->next;
			}
			if (found == 0)
			{
				cout << "Tutor Doesn't Exist ! ";
			}
		}
	}

	void hrModifyTutor(){
		// if head is NULL
		if (head == NULL)
		{
			cout << "The Record is Empty....";
		}
		else
		{
			int found = 0;
			cout << "Enter a tutor ID for Modify the record: ";
			cin >> tutorID;
			Tutor* ptr = head;
			while (ptr != NULL)
			{
				if (tutorID == ptr->tutorID)
				{					
					
					//cout << "Tutor phone : " << ptr->tutorPhone << endl;
					cout << "New phone : ";
					cin >> ptr->tutorPhone;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					while(!is_tutorPhone_valid(tutorPhone)) {
						cout << "-------------------------------------" << endl;
						cout << "         Invalid Phone Number        " << endl;
						cout << "         Format '000-000-0000'       " << endl; 
						cout << "-------------------------------------" << endl;
						cout << "Please insert correct Phone Number : ";
						cin.clear();
						cin >> tutorPhone;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

					//cout << "Tutor address : " << ptr->tutorAddress << endl;
					cout << "New address : ";
					cin >> ptr->tutorAddress;
					
					cout << "Tutor Record Updated Successfully... ";
					found++;
				}
				ptr = ptr->next;
			}
			if (found == 0)
			{
				cout << "Tutor Doesn't Exist ! ";
			}
		}
	}

	void delete_record()
	{
		if (head == NULL)
		{
			cout << "Tutor Record is Empty....";
		}
		else
		{
			int found = 0;
			cout << "Enter Tutor ID For Deletion : ";
			cin >> tutorID;
			if (tutorID == head->tutorID)
			{
				Tutor* ptr = head;
				head = head->next;
				
				found++;
				delete ptr;
				cout << "Tutor deleted successfully ! ";
			}
			else
			{
				Tutor* pre = head;
				Tutor* ptr = head->next;
				while (ptr != NULL)
				{
					if (tutorID == ptr->tutorID)
					{
						pre->next = ptr->next;
						found++;
						delete ptr;
						break;
					}
					pre = ptr;
					ptr = ptr->next;
				}
			}
			if (found == 0)
			{
				cout << "Tutor Doesn't Exist ! ";
			}
		}
	}

	// function to sort a singly linked list using insertion
	// sort
	void insertionSort(Tutor* headref)
	{
		// Initialize sorted linked list

		sorted = NULL;
		Tutor* current = headref;
		// Traverse the given linked list and insert every
		// node to sorted
		while (current != NULL) {
			// Store next for next iteration
			Tutor* next = current->next;
			// insert current in sorted linked list
			sortedInsert(current);
			// Update current
			current = next;
		}
		// Update head_ref to point to sorted linked list
		head = sorted;

	}

	/*
	 * function to insert a new_node in a list. Note that
	 * this function expects a pointer to head_ref as this
	 * can modify the head of the input linked list
	 * (similar to push())
	 */
	void sortedInsert(Tutor* newnode)
	{
		/* Special case for the head end */
		if (sorted == NULL || 
			sorted->tutorID >= newnode->tutorID) 
		{
			newnode->next = sorted;
			sorted = newnode;
		}
		else 
		{
			Tutor* current = sorted;
			/* Locate the node before the point of insertion
			 */
			while (current->next != NULL && 
				current->next->tutorID < newnode->tutorID) 
			{
				current = current->next;
			}
			newnode->next = current->next;
			current->next = newnode;
		}
	}

	void insertionSortByPayRate(Tutor* headref)
	{
		// Initialize sorted linked list
		sorted = NULL;
		Tutor* current = headref;
		// Traverse the given linked list and insert every
		// node to sorted
		while (current != NULL) {
			// Store next for next iteration
			Tutor* next = current->next;
			// insert current in sorted linked list
			sortedInsertByPayRate(current);
			// Update current
			current = next;
		}
		// Update head_ref to point to sorted linked list
		head = sorted;
	}

	void sortedInsertByPayRate(Tutor* newnode)
	{
		/* Special case for the head end */
		if (sorted == NULL || sorted->tutorHourlyRate >= newnode->tutorHourlyRate) {
			newnode->next = sorted;
			sorted = newnode;
		}
		else {
			Tutor* current = sorted;
			/* Locate the node before the point of insertion
			 */
			while (current->next != NULL
				&& current->next->tutorHourlyRate < newnode->tutorHourlyRate) {
				current = current->next;
			}
			newnode->next = current->next;
			current->next = newnode;
		}
	}

	void insertionSortByRating(Tutor* headref)
	{
		// Initialize sorted linked list

		sorted = NULL;
		Tutor* current = headref;
		// Traverse the given linked list and insert every
		// node to sorted
		while (current != NULL) {
			// Store next for next iteration
			Tutor* next = current->next;
			// insert current in sorted linked list
			sortedInsertByRating(current);
			// Update current
			current = next;
		}
		// Update head_ref to point to sorted linked list
		head = sorted;

	}

	void sortedInsertByRating(Tutor* newnode)
	{
		/* Special case for the head end */
		if (sorted == NULL || 
			sorted->tutorRating.calRating >= newnode->tutorRating.calRating) 
		{
			newnode->next = sorted;
			sorted = newnode;
		}
		else 
		{
			Tutor* current = sorted;
			/* Locate the node before the point of insertion
			 */
			while (current->next != NULL && 
				current->next->tutorRating.calRating < newnode->tutorRating.calRating) 
			{
				current = current->next;
			}
			newnode->next = current->next;
			current->next = newnode;
		}
	}
	
};
Tutor *sorted;