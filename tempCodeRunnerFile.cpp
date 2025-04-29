#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
using namespace std;
class student{
	private:
		string name,roll_no,course,address,email_id,contact_no;
		int marks;
	public:
		void menu();
		void insert();
		void display();
		void modify();
		void search();
		void Delete();
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
				cout<<"Add another student address (y/n): ";
				cin>>x;
				cin.ignore();
			}while(x=='y' || x=='Y');
			break;
		case 2:
			display();
			break;
		case 3:
			modify();
			break;
		case 4:
		    search();
			break;
		case 5:
			Delete();
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
	fstream file,file2;
	string duplicateRoll;
	int count=0;
	cout<<"\n-------------------Add Student Details-------------------"<<endl;
	cout<<"\t\tEnter Roll Number: ";
	cin>>duplicateRoll;


	file2.open("StudentRecord.txt", ios::in);
	string tempName,tempRoll,tempCourse,tempEmail,tempContact,tempAddress;
	int tempMarks;
	bool isDuplicate=false;
	while(file2 >> tempName >> tempRoll >> tempCourse >> tempEmail >> tempContact >> tempAddress >> tempMarks){
		if(duplicateRoll==tempRoll){
			isDuplicate=true;
			break;
		}
	}
	file2.close();

	if(isDuplicate){
		cout<<"\n\tError: Duplicate Roll Number...Entry Of Details Failed..."<<endl;
		return;
	}
	roll_no=duplicateRoll;
	cin.ignore();
	cout<<"\t\tEnter Name: ";
	getline(cin,name);
	cout<<"\t\tEnter Course: ";
	getline(cin,course);
	cout<<"\t\tEnter Email ID: ";
	getline(cin,email_id);
	cout<<"\t\tEnter Contact Number: ";
	getline(cin,contact_no);
	cout<<"\t\tEnter Address: ";
	getline(cin,address);

	do{
		cout<<"\t\tEnter Marks(0-100): ";
		cin>>marks;
		if(marks<0 || marks>100){
			cout<<"\n\t\tInvalid...Enter Marks Again..."<<endl;
		}
	}while(marks<0 || marks>100);

	file.open("StudentRecord.txt",ios::app | ios::out);
	file.seekp(0,ios::end);
	if(file.tellp()>0){
		file<<"\n";
	}
	file<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<" "<<marks<<"\n";
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
		
		while(file>> name >> roll_no >> course >> email_id >> contact_no >> address >> marks){
			cout<<"\n\t\t\t Student Number: "<<++total<<endl;
			cout<<"\t\t\t Student Name: "<<name<<endl;
			cout<<"\t\t\t Student Roll Number: "<<roll_no<<endl;
			cout<<"\t\t\t Student Course: "<<course<<endl;
			cout<<"\t\t\t Student Email ID.: "<<email_id<<endl;
			cout<<"\t\t\t Student Contact Number: "<<contact_no<<endl;
			cout<<"\t\t\t Student Address: "<<address<<endl;
			cout<<"\t\t\t Student Marks: "<<marks<<endl;
			cout<<"\t\t\t Performance: "<<(marks>=40 ? "Pass" : "Fail")<<endl;
			
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
	cout<<"\n-------------------Modify Student Details-------------------"<<endl;
	file.open("StudentRecord.txt", ios::in);
	if(!file){
		cout<<"\n\t\t\tNo Data Is Present"<<endl;
		return;
	}
		cout<<"\nEnter the roll number of the student you want to modify";
		cin>>rollNo;
		file1.open("Record.txt", ios::out);
		
		while(file>> name >> roll_no >> course >> email_id >> contact_no >> address >> marks){
			if(rollNo==roll_no){
				cout<<"\n\t\tRecord Found.Enter New Details:\n";
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

				do{
					cout<<"\t\tEnter Marks (0-100): ";
					cin>>marks;
					if(marks<0 || marks>100){
						cout<<"\t\tInvalid Marks! Please Enter Between 0 and 100"<<endl;
					}
				}while(marks<0 || marks>100);
				found=1;
			}
			file1 << name <<" "<< roll_no <<" "<< course <<" "<< email_id <<" "<< contact_no <<" "<< address <<" "<< marks <<"\n";
		}
		
		file1.close();
	file.close();

	if(found==0){
		cout<<"\n\t\tStudent Roll Number Not Found..."<<endl;
	}else{
		cout<<"\n\t\tRecord Updated Successfully!"<<endl;
	}
	remove("StudentRecord.txt");
	rename("Record.txt","StudentRecord.txt");
	
}
void student::search(){
	system("cls");
	fstream file;
	int found=0;
	file.open("StudentRecord.txt", ios::in);
	if(!file){
		cout<<"\n\t\t\tNo Data Found..."<<endl; 
		return;
	}
	string rollno;
	cout<<"\n-------------------Search Student Data-------------------"<<endl;
	cout<<"Enter Roll number of student which you want to search: "<<endl;
	cin>>rollno;

	while(file>> name >> roll_no >> course >> email_id >> contact_no >> address >> marks){
		if(rollno==roll_no){
			cout<<"\t\t\t Student Name: "<<name<<endl;
			cout<<"\t\t\t Student Roll Number: "<<roll_no<<endl;
			cout<<"\t\t\t Student Course: "<<course<<endl;
			cout<<"\t\t\t Student Email ID.: "<<email_id<<endl;
			cout<<"\t\t\t Student Contact Number: "<<contact_no<<endl;
			cout<<"\t\t\t Student Address: "<<address<<endl;
			cout<<"\t\t\t Student Marks: "<<marks<<endl;
			found=1;
			break;
		}
	}
	if(found==0){
		cout<<"\n\t\t\tStudent Roll Number Not Found..."<<endl;
	}
	file.close();	
}
void student::Delete(){
	system("cls");
	fstream file,file1;
	string rollno;
	int found=0;
	cout<<"\n-------------------Delete Student Details-------------------"<<endl;
	file.open("StudentRecord.txt", ios::in);
	if(!file){
		cout<<"\n\t\t\tNo Data Found..."<<endl;
		return;
	}
	cout<<"\nEnter Roll Number Of Student Which You Want To Delete: "<<endl;
	cin>>rollno;
	file1.open("Record.txt",ios::out);

	while(file>> name >> roll_no >> course >> email_id >> contact_no >> address >> marks){
		if(rollno!=roll_no){
			file1<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<" "<<marks<<"\n";
		}else{
			found=1;
		}
	}
	file1.close();
	file.close();
	if(found==0){
		cout<<"\n\t\t\tStudent Roll Number Not Found..."<<endl;
	}else{
		remove("StudentRecord.txt");
	    rename("Record.txt","StudentRecord.txt");
		cout<<"\n\t\tRecord Deleted Successfully!"<<endl;
	}	  
}
int main(){
	student project;
	project.menu();
	return 0;
}
