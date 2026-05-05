#include<iostream>
#include<ios> 
#include<limits> 
#include <cstring>
#include<fstream>
#include<iomanip>
#define MAX 20
using namespace std;


typedef struct Employee{
	 int EID;
	 string name;
	 string designation;
	 float salary;
}EMP;


class SequentialFile
{
	private:
		EMP obj;
		
	public:

		void readData();
		void printData();
		void insertRecord();
		void displayRecords();
		void deleteRecord(string);
		void updateRecord(string);
		void searchRecord(string);
};

void SequentialFile::readData(){
			cout<<"\nEnter Employee ID:";
			cin>>obj.EID;
			
			cout<<"\nEnter Employee Name:";
			cin>>obj.name;
			
			cout<<"\nEnter Employee Designation:";
			cin>>obj.designation;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			
			cout<<"\nEnter Employee Salary:";
			cin>>obj.salary;
}

void SequentialFile::printData(){
			cout<<"\nEmployee ID:"<<obj.EID;
			cout<<"\nEmployee Name:"<<obj.name;
			cout<<"\nEmployee Designation:"<<obj.designation;
			cout<<"\nEmployee Salary:"<<obj.salary;
}


void SequentialFile::insertRecord(){
			fstream out;
			out.open("employee1.txt",ios::app|ios::binary);
			readData();

			out.write((char*)&obj,sizeof(obj));
			out.close();
}
				
void SequentialFile::displayRecords(){
			fstream in;
			
			in.open("employee1.txt",ios::in|ios::binary);

			while(in.read((char*)&obj,sizeof(obj))){
					cout<<"\n"<<obj.EID<<setw(15)<<obj.name<<setw(15)<<obj.designation<<setw(15)<<obj.salary;
			}
			
			cout<<"\n";
			in.close();
}


void SequentialFile::searchRecord(string name){
			fstream in;
			
			in.open("employee1.txt",ios::in|ios::binary);

			while(in.read((char*)&obj,sizeof(obj))){

				if(obj.name==name){
					cout<<"\nRecord Found";
					cout<<"\n"<<obj.EID<<setw(15)<<obj.name<<setw(15)<<obj.designation<<setw(15)<<obj.salary;
					return;
				}
			}
			cout<<"\nRecord not found";
			in.close();
}	


void SequentialFile::updateRecord(string name){
			fstream inout;
			int count=0;
			inout.open("employee1.txt",ios::in| ios::out|ios::binary);
			
			while(inout.read((char*)&obj,sizeof(obj))){
				count++;
				if(obj.name==name){
					cout<<"\nRecord Found";
					cout<<"\n"<<obj.EID<<setw(15)<<obj.name<<setw(15)<<obj.designation<<setw(15)<<obj.salary;
					readData();
					inout.seekp(sizeof(obj)*(count-1),ios::beg);
					inout.write((char*)&obj,sizeof(obj));
					return;
				}
			}
			cout<<"\nRecord not found";
			inout.close();
}

void SequentialFile::deleteRecord(string name){
			fstream in;
			in.open("employee1.txt",ios::in|ios::binary);

			fstream out;
			out.open("temp.txt",ios::out|ios::binary);

			while(in.read((char*)&obj,sizeof(obj))){

				if(obj.name != name){
					out.write((char*)&obj,sizeof(obj));
				}
			}
			in.close();
			out.close();
			remove("employee1.txt");
			rename("temp.txt","employee1.txt");
}

int main(){
	SequentialFile t1;
	string name;
	int ch=0;
	
	while(ch!=6)
	{
		cout<<"\n*******  SEQUENTIAL ACCESS FILE PROGRAM USING C++ ********** \n\n";
		cout<<"\n1.INSERT RECORD\n2.DISPLAY All RECORD\n3.SEARCH RECORD\n4.UPDATE RECORD\n5.DELETE RECORD\n6.EXIT.";
		cout<<"\nWhat operations:";
		cin >> ch;
		switch(ch)
		{
		case 1:
 			t1.insertRecord();
			cout<<"\n\nRecord is Inserted..\n\n";
			break;
		case 2:
			t1.displayRecords();
			break;
		case 3:
			cout<<"\nEnter the name to be searched::";
			cin>>name;
			t1.searchRecord(name);
			break;
		case 4:
			cout<<"\nEnter the name to be updated::";
			cin>>name;
			t1.updateRecord(name);
			break;
		case 5:
			cout<<"\nEnter the name to be deleted::";
			cin>>name;
			t1.deleteRecord(name);
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}
