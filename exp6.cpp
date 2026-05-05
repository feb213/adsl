#include<iostream>
#include<ios>
#include<limits> 
#include <cstring>
#define BSIZE 5
using namespace std;


typedef struct Client{
	 long int phoneNo;
	 string name;
}CLIENT;



class TelephoneDirectory
{
	private:
		CLIENT LPHashTable[BSIZE];
		CLIENT QPHashTable[BSIZE];
		CLIENT cObj;
	public:
		TelephoneDirectory(){
			for(int i=0;i<BSIZE;i++){
				LPHashTable[i].phoneNo=-1;
				QPHashTable[i].phoneNo=-1;
			}
		}
		void init(){
			for(int i=0;i<BSIZE;i++){
				LPHashTable[i].phoneNo=-1;
				QPHashTable[i].phoneNo=-1;
			}
		}
		
		
		void readData();
		void printData();
		
		
		void insertRecordLP();
		void displayRecordsLP();
		void searchRecordLP(long int);
		
		
		void insertRecordQP();
		void displayRecordsQP();
		void searchRecordQP(long int);
};

void TelephoneDirectory::readData(){
	long int telephone;
	string name;
	cout<<"\nEnter client telephone No.::";
	cin>>cObj.phoneNo;
	
	cout<<"\nEnter client name::";
	cin>>cObj.name;
}

void TelephoneDirectory::printData(){
	cout<<"\nThe client telephone No.::"<<cObj.phoneNo;
	cout<<"\nThe client name::"<<cObj.name;
}

void TelephoneDirectory::insertRecordLP(){
	int hi,noc,i;
	readData();
	hi=cObj.phoneNo%BSIZE;
	if(LPHashTable[hi].phoneNo == -1)
		LPHashTable[hi]=cObj;
	else{
		 i=(hi+1)%BSIZE;
		 while(i != hi){
			if(LPHashTable[i].phoneNo==-1){
				LPHashTable[i]=cObj;
				break;
			}
			i=(i+1)%BSIZE;
		 }
		if(i==hi)
			cout<<"\nHash Table Full!!";
	}
}

void TelephoneDirectory::searchRecordLP(long int telephoneNo){
	int hi,noc,i;
	hi=telephoneNo%BSIZE;
	noc=0;
	if(LPHashTable[hi].phoneNo == telephoneNo){
		noc++;
		cout<<"\nRecord found after "<<noc<<" comparisons!";
	}
	else{
		 i=(hi+1)%BSIZE;
		 while(i != hi){
			noc++;
			if(LPHashTable[i].phoneNo==telephoneNo){
				cout<<"\nRecord found after "<<noc<<" comparisons!";
				break;
			}
			i=(i+1)%BSIZE;
		 }
		if(i==hi)
			cout<<"\nRecord NOT found even after "<<noc<<" comparisons!";
	}
}

void TelephoneDirectory::displayRecordsLP(){
	cout<<"\nTelephone No."<<"\t"<<"Name  ";
	for (int i=0;i<BSIZE;i++)
		cout<<"\n"<<LPHashTable[i].phoneNo<<"\t\t"<<LPHashTable[i].name;
}


void TelephoneDirectory::insertRecordQP(){
	int hi,noc,i,newHI,j;
	readData();
	i=1;
	hi=(cObj.phoneNo+i*i)%BSIZE;
	if(QPHashTable[hi].phoneNo == -1)
		QPHashTable[hi]=cObj;
	else{
		 for (int j=1;j<=BSIZE;j++){
			newHI=(hi+i*i)%BSIZE;//new hash index
			noc++;
			if(QPHashTable[newHI].phoneNo==-1){
				QPHashTable[newHI]=cObj;
				break;
			}
			i++;
		 }
		if(j>BSIZE)
			cout<<"\nRecord could not be stored!!";
	}
}

void TelephoneDirectory::searchRecordQP(long int phoneNo){
	int hi,noc,i,j;
	int newHI;
	hi=phoneNo%BSIZE;
	noc=0;
	if(LPHashTable[hi].phoneNo == phoneNo){
		noc++;
		cout<<"\nRecord found after "<<noc<<" comparisons!";
	}
	else{
		 for (int j=1;j<=BSIZE;j++){
			newHI=(hi+i*i)%BSIZE;
			noc++;
			if(QPHashTable[newHI].phoneNo==phoneNo){
				cout<<"\nRecord found after "<<noc<<" comparisons!";
				break;
			}
			i++;
		 }
		if(j>BSIZE)
			cout<<"\nRecord NOT found even after "<<noc<<" comparisons!";
	}
}

void TelephoneDirectory::displayRecordsQP(){
	cout<<"\nTelephone No."<<"\t"<<"   Name  ";
	for (int i=0;i<BSIZE;i++)
		cout<<"\n"<<QPHashTable[i].phoneNo<<"\t"<<QPHashTable[i].name;
}
int main(){
	TelephoneDirectory t1;
	string name;
	int ch=0,ch1,phoneNo;
	
	while(ch!=6)
	{
		cout<<"\n*******  HASH TABLE - LINEAR & QUADRATIC PROBING********** \n\n";
		cout<<"\n1.INSERT RECORD\n2.DISPLAY All RECORD\n3.SEARCH RECORD\n4.EXIT.";
		cout<<"\nWhat operations:";
		cin >> ch;
		switch(ch)
		{
		case 1:
			cout<<"\n1. Linear Probing";
			cout<<"\n2. Quadratic Probing";
			cout<<"\nWhich Probing:";
			cin>>ch1;
			if (ch1==1)
				t1.insertRecordLP();
			else 
				t1.insertRecordQP();
			
			break;
		case 2:
			cout<<"\n1. Linear Probing";
			cout<<"\n2. Quadratic Probing";
			cout<<"\nWhich Probing:";
			cin>>ch1;
			if (ch1==1)
				t1.displayRecordsLP();
			else 
				t1.displayRecordsQP();
			
			break;
		case 3:
			cout<<"\nEnter the telephone number to be searched::";
			cin>>phoneNo;
			cout<<"\n1. Linear Probing";
			cout<<"\n2. Quadratic Probing";
			cout<<"\nWhich Probing:";
			cin>>ch1;
			if (ch1==1)
				t1.searchRecordLP(phoneNo);
			else 
				t1.searchRecordQP(phoneNo);
			break;
		case 4:
			exit(0);
			break;
		
		default:
			cout<<"\nWrong Choice!!";
		}
	}
	return 0;
}