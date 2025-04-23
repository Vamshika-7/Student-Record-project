#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
using namespace std;
class student{
	private:
		string name,roll_no,course,address,email_id,contact_no;
	public:
		void menu();
		void insert();
};
void student::menu(){
	menustart:
	int choice;
	char x;
	cout<<"\t\t\t---------------------------"<<endl;
	cout<<"\t\t\t|STUDENT RECORD MANAGEMENT|"<<endl;
	cout<<"\t\t\t---------------------------"<<endl;
	cout<<"1. Enter New Record"<<endl;
	cout<<"2. Display Record"<<endl;
	cout<<"3. Modify Record"<<endl;
	cout<<"4. Search Record"<<endl;
	cout<<"5. Delete Record"<<endl;
	cout<<"6. Exit"<<endl;
	
	cout<<"\t\t\t---------------------------"<<endl;
	cout<<"\t\t\tChoose Option:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t---------------------------"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;

	switch(choice){
		case 1:
		do{
			insert();
			cout<<"Add another student address (y/n): "<<endl;
			cin>>x;
		}while(x=='y' || x=='Y');
			break;
		case 6:
			exit(0);
		default:
			cout<<"\n\t\t  Invalid Choice...Please Try Again...";
	}
	getch();
	goto menustart;
}
void student::insert(){
	system("cls");
	fstream file;
	cout<<"\n-------------------Add Student Details-------------------"<<endl;
	cout<<"\t\tEnter Name: ";
	cin>>name;
	cout<<"\t\tEnter Roll Number: ";
	cin>>roll_no;
	cout<<"\t\tEnter Course: ";
	cin>>course;
	cout<<"\t\tEnter Email ID: ";
	cin>>email_id;
	cout<<"\t\tEnter Contact Number: ";
	cin>>contact_no;
	cout<<"\t\tEnter Address: ";
	cin>>address;
	file.open("StudentRecord.txt",ios::app | ios::out);
	file<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<"\n";
	file.close();
}
int main(){
	student project;
	project.menu();
	return 0;
}
