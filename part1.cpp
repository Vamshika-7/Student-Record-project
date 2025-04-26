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
		void display();
		void modify();
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
		case 2:
			display();
			break;
		case 3:
			modify();
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
void student::display(){
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------Student Record Table-------------------"<<endl;
	file.open("StudentRecord.txt", ios::in);
	if(!file){
		cout<<"\n\t\t\tNo Data Found..."<<endl;
		file.close();
	}else{
		file>> name >> roll_no >> course >> email_id >> contact_no >> address ;
		while(!file.eof()){
			cout<<"\n\t\t\t Student Number: "<<total++<<endl;
			cout<<"\t\t\t Student Name: "<<name<<endl;
			cout<<"\t\t\t Student Roll Number: "<<roll_no<<endl;
			cout<<"\t\t\t Student Course: "<<course<<endl;
			cout<<"\t\t\t Student Email ID.: "<<email_id<<endl;
			cout<<"\t\t\t Student Address: "<<address<<endl;
			file>> name >> roll_no >> course >> email_id >> contact_no >> address ;
		}
		if(!total){
			cout<<"\n\t\t\tNo Data Found..."<<endl;
		}
	}
	file.close();
}
void student::modify(){
	system("cls");
	fstream file,file1;
	int found=0;
	string rollNo;
	cout<<"\n-------------------MOdify Student Details-------------------"<<endl;
	file.open("StudentRecord.txt", ios::in);
	if(!file){
		cout<<"\n\t\t\tNo Data Is Present"<<endl;
		file.close();
		return;
	}else{
		cout<<"\nEnter the roll number of the student you want to modify"<<endl;
		cin>>rollNo;
		file1.open("Record.txt", ios::app | ios::out);
		file>> name >> roll_no >> course >> email_id >> contact_no >> address ;
		while(!file.eof()){
			if(rollNo!=roll_no){
				file1<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<"\n";
			}else{
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
				file1<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<"\n";
				found++;
			}
			file>> name >> roll_no >> course >> email_id >> contact_no >> address ;
			
		}
		if(found==0){
			cout<<"\n\t\t\tStudent Roll Number Not Found..."<<endl;
		}
		file1.close();
		file.close();
		remove("StudentRecord.txt");
		rename("Record.txt","StudentRecord.txt");
	}

}
int main(){
	student project;
	project.menu();
	return 0;
}
