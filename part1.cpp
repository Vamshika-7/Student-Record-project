#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
class student{
	private:
		
	public:
		void menu();
};
void student::menu(){
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
	
}
int main(){
	student project;
	project.menu();
	return 0;
}
