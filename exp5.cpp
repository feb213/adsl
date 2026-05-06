#include<iostream>
#include<ios>
#include<limits>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;

typedef struct Employee{
    int EID;
    string name;
    string designation;
    int salary;
}EMP;

class SequentialFile{
    private:
        EMP obj;
    public:
        void readData();
        void printData();
        void insertData();
        void displayData();
        void deleteData(string);
        void updateData(string);
        void searchRecord(string);

};

void SequentialFile::readData(){
        cout<<"\nEnter Employee Id";
        cin>>obj.EID;

        cout<<"\nEnter Employee Name";
        cin>>obj.name;

        cout<<"\nEnter Employee designation";
        cin>>obj.designation;

        cout<<"\nEnter Employee salary";
        cin>>obj.salary;

}

void SequentialFile::printData(){
    cout<<"\nEmployee Id"<<obj.EID;
    cout<<"\nEmployee Name"<<obj.name;
    cout<<"\nEmployee designation"<<obj.designation;
    cout<<"\nEmployee salary"<<obj.salary;

}

void SequentialFile::insertData(){
    fstream out;
    out.open("employee.txt",ios::app | ios::binary);
    readData();

    out.write((char*)&obj,sizeof(obj));
    out.close();

}

void SequentialFile::displayData(){
    fstream in;
    in.open("employee.txt", ios::in|ios::binary);
    while(in.read((char*)&obj,sizeof(obj))){
        cout<<"\n"<<obj.EID<< setw(15) <<obj.name<<setw(15)<<obj.designation<< setw(15)<<obj.salary<< setw(15);
    }
    in.close();

}

void SequentialFile::searchRecord(string name){
    fstream in;
    in.open("employee.txt",ios::in|ios::binary);

    while(in.read((char*)&obj,sizeof(obj))){
        if(obj.name == name){
            cout<<"\n Record Found";
            cout<<"\n"<<obj.EID<< setw(15) <<obj.name<<setw(15)<<obj.designation<< setw(15)<<obj.salary<< setw(15);
            return;
        }
    }
    cout<<"\n Record Not found";
    in.close();
}

void SequentialFile::updateData(string name){
    fstream inout;
    int count = 0;
    inout.open("employee.txt",ios::in|ios::out|ios::binary);

    while(inout.read((char*)&obj,sizeof(obj))){
        count++;
        if(obj.name == name){
            cout<<"\n Record Found";
            cout<<"\n"<<obj.EID<< setw(15) <<obj.name<<setw(15)<<obj.designation<< setw(15)<<obj.salary<< setw(15);
            readData();
            inout.seekp(sizeof(obj)*(count-1),ios::beg);
            inout.write((char*)&obj,sizeof(obj));
            return;
        }
    }
    cout<<"\n Record Not found";
    inout.close();


}

void SequentialFile::deleteData(string name){
    fstream in;
    in.open("employee.txt",ios::in|ios::binary);

    fstream out;
    out.open("temp.txt",ios::out|ios::binary);

    while(in.read((char*)&obj,sizeof(obj))){

        if(obj.name != name){
            out.write((char*)&obj,sizeof(obj));
        }
    }
    in.close();
    out.close();
    remove("employee.txt");
    rename("temp.txt","employee.txt");


}

int main(){
    SequentialFile t1;
    string name;
    int ch=0;
    while(true){
        cout<<"\n***************************File access****************************\n";
        cout<<"\n1.Insert Record\n2.Display ALL records\n3.Search Record \n4.update record \n5.Delete Record \n6.Exit.";
        cout<<"\nwhat operation to be perfromed :";
        cin>>ch;
        switch(ch){
            case 1:
                t1.insertData();
                cout<<"\n Record is inserted....\n";
                break;

            case 2:
                t1.displayData();
                break;
            case 3:
                cout<<"\nEnter the name to be searched::";
			    cin>>name;
                t1.searchRecord(name);
                break;
               
            case 4:
                cout<<"\nEnter the name to be updated::";
			    cin>>name;
                t1.updateData(name);
                break;
            case 5:
                cout<<"\nEnter the name to be deleted::";
			    cin>>name;
                t1.deleteData(name);
                break;
               
            case 6:
                exit(0);
            default :
                cout<<"Enter invalid chioce";
        }
    }
}
