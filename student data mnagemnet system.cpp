/*
Employee Managment system

Function:
1. This program first display the menu.
2. Allow user to enter the data of employee.
3.Also allow to view the data added till now.
4. allow user to search the employee data via id or name
5. Ask user for exit the data entering module.

*************************

Start of Program
*/

#include <bits/stdc++.h>
#include <fstream>    
#include<conio.h>     
#include<windows.h>     
#include<iomanip>
#include<string>

using namespace std;

/* structure of name employee to
    store the data of diffenet type 
    during the run time and then store 
	it to the .csv file*/
    
struct employee {
	string name;
	string code;
	string designation;
	string exp;
	string age;
};

 //creating the variable of	 
 //structure employee
employee emp;     

/* 
path="D:\\@EE\\project\\file.csv";
*/

void build()
{
		//ofstream
		//This data type represents the output file 
		//stream and is used to create files and to 
		// write information to files.
		ofstream Read;		


		//ios::app
		//Append mode. All output to that file
		//to be appended to the end.
		Read.open("file.csv",ios::app);  			

		
		cout << "Enter the following data:\n";
		
		cout << "Name ";
		getline(cin,emp.name);       
		Read<<emp.name<<",";

		cout << "Employee ID ";
		cin >> emp.code;
		Read<<emp.code<<",";
		
		cin.ignore();
		
		cout << "Designation ";
		getline(cin,emp.designation);
		Read<<emp.designation<<",";

		cout << "Experience ";
		getline(cin,emp.exp);
		Read<<emp.exp<<",";

		cout << "Age ";
		cin >> emp.age;
		Read <<emp.age<<endl;
		
    //closing the file.
	//so that it free up the space
		Read.close();        
								
}

//view funtion to view the data
//enter by the admin.
void view(){				
	string vdata;
	int j=0;
	int k;
	ifstream fi; 
	fi.open("file.csv");
	if(( fi.get(), fi.eof() )){
		cout<<"\n\tEmpty file!\n";
		fi.close();
	}
	
	else{
	ifstream fi;
	fi.open("file.csv");
	while(getline(fi,vdata)){
		int x=0;
		cout<<"\n\n\t\tEmployee "<<++j<<endl<<endl;
		for(int m=0;m<vdata.length();m++){
			
			if(m==0){
				cout<<"Name:\t\t ";
			}   
			                               
			else if(vdata[m]==','){
				x+=1;
				k=x;
				cout<<endl;
				continue;
			}
			else if(k==1){
				cout<<"Employee id:\t ";
				
			}
			else if(k==2){
				cout<<"Designation:\t ";
			}
			else if(k==3){
				cout << "Experience:\t ";
			}
			else if(k==4){
				cout << "Age:\t\t ";
			}
			k=0;
			cout<<vdata[m];
		}
		cout<<endl;
	}
	fi.close();
}
}


void find(string str){
	int v=1;
	ifstream file("file.csv");
	string s;
	int k=0;
	if(( file.get(), file.eof() )){
		cout<<"\n\tEmpty file!\n";
		file.close();
	}
	else{
		ifstream file("file.csv");
	while(getline(file,s)){
		int x=0;
		size_t found=s.find(str);
    	if (found != string::npos){
    		v=0;
    		for(int i=0;i<s.length();i++){
				if(i==0){
					cout<<"Name:\t\t ";
				}
				else if(s[i]==','){
					x+=1;
					k=x;
					cout<<endl;
					continue;
				}
				if(k==1){
					cout<<"Employee id:\t ";
				
				}
				else if(k==2){
					cout<<"Designation:\t ";
				}
				else if(k==3){
					cout << "Experience:\t ";
				}
				else if(k==4){
					cout << "Age:\t\t ";
				}
				k=0;
				cout<<s[i];
			}
			break;
		}
	}
	cout<<endl;
	file.close();
	
	if(v!=0){
		cout<<"\t\t\nData not found!\n";
	}
}
}


void deletedata(string str){
	string line;
	int vv=1;
	ifstream ifs;
	ofstream ofs;
	ifs.open("file.csv");
	ofs.open("file1.csv",ios::app);
	while(getline(ifs,line)){
		
		size_t cv=line.find(str);
		if (cv != string::npos){
			vv=0;
			continue;
		}
		else{
			ofs<<line;
			ofs<<endl;
		}
	}
	ofs.close();
	ifs.close();
	remove("file.csv");
	rename("file1.csv","file.csv");
}



void update(string str){
	int v=0;
	ifstream ifs;
	ofstream ofs;
	ifs.open("file.csv");
	string s,s5;
	int k=0;
	while(getline(ifs,s)){
		int x=0;
		size_t found=s.find(str);
    	if (found != string::npos){
    		v=1;
    		ifs.close();
    		break;
    	}
	}
	
	if(v==1){
	ifstream ifs;
	ofstream ofs;
		ifs.open("file.csv",ios::in);
		ofs.open("file1.csv",ios::app);
		string line;
		int vv=1;
		while(getline(ifs,line)){
			
			size_t cv=line.find(str);
			if (cv != string::npos){
				vv=0;
				cout << "Enter the following data:\n";		
				cout << "Name ";
				getline(cin,emp.name);       

				cout << "Employee ID ";
				cin >> emp.code;
		
				cin.ignore();
				cout << "Designation ";
				getline(cin,emp.designation);

				cout << "Experience ";
				getline(cin,emp.exp);
				
				cout << "Age ";
				cin >> emp.age;
				s5=emp.name+","+emp.code+","+emp.designation+","+emp.exp+","+emp.age;
				ofs<<s5<<endl;			
			}
			else{
				ofs<<line;
				ofs<<endl;
			}
		}
		ofs.close();
		ifs.close();
		remove("file.csv");
		rename("file1.csv","file.csv");
   }
   else{
   	cout<<"\n\n\t\t\tNo Match found!\n";
   }

}


void showMenu(){
	
    cout<<setw(54)<<"\t\tAvailable Options\n"<<endl;
    cout<<setw(52)<<"1.Enter the employee data"<<endl;
    cout<<setw(50)<<"2.View the entered data"<<endl;
    cout<<setw(53)<<"3.Search the employee data"<<endl;
    cout<<setw(53)<<"4.Change the employee data"<<endl;
    cout<<setw(53)<<"5.Delete the employee data"<<endl;
    cout<<setw(33)<<"6.Exit"<<endl;
    cout<<"\t\t\t-----------------------------------------------------"<<endl;
    cout<<"\t\t\t-----------------------------------------------------"<<endl;
    cout<<endl<<endl;
    
	return;
}


void dispp(){
	system("cls");
	cout<<"\n\n\n\n";
				cout<<"\t\t\t\t\t    DEVELOPED ";
				Sleep(600); cout<<" BY ";
				Sleep(800); 
				for (int i=0; i<6; i++){
 					cout<<"."; Sleep(400);
				}
				cout<<"\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t  =====================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t || Maryam Nadeem        2020-EE-353  || \t\t\t\n";
	cout<<"\t\t\t\t\t\t\t\t\t || Ans Rehman           2020-EE-351  || \t\t\t\n";
	cout<<"\t\t\t\t\t\t\t\t\t || Danish Nisar         2020-EE-361  || \t\t\t\n";
    cout<<"\t\t\t\t\t\t\t\t\t  ===================================== \n\n";
    cout<<"\n\n\n\n\t\t\t\t\t";
	cout<<" PRESENTED ";
	Sleep(600); cout<<" TO"; 
    for (int i=0; i<3; i++){
 		cout<<"."; Sleep(400);
	}
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\t @@      @@        @@      @@   @@   @  @   @@@  @  @     @\t @@@  @  @  @@@@@  @@@@    @@@   @@@@@\n";
	cout<<"\t\t\t\t\t @ @    @ @        @ @    @ @  @  @  @  @  @     @  @ @   @\t@     @  @  @      @   @  @   @     @ \n";
	cout<<"\t\t\t\t\t @  @  @  @ @@@@   @  @  @  @  @  @  @@@@   @@   @  @  @  @\t @@   @@@@  @@@@@  @@@@   @@@@@    @  \n";
	cout<<"\t\t\t\t\t @   @    @ @      @   @    @  @  @  @  @     @  @  @   @ @\t   @  @  @  @      @  @   @   @   @   \n";
	cout<<"\t\t\t\t\t @        @ @   o  @        @   @@   @  @  @@@   @  @     @\t@@@   @  @  @@@@@  @   @  @   @  @@@@@\n";
}


void dis(){
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t    WELCOME ";
	Sleep(600); cout<<" TO ";
	Sleep(600); cout<<" EMPLOYEE  ";
	Sleep(600); cout<<" MANAGEMENT ";
	Sleep(600); cout<<" SYSTEM";
	Sleep(800); 
	
	for (int i=0; i<5; i++){
 		cout<<"."; Sleep(400);
	}
	dispp();

}



void admin(){
				system("cls");
				cout<<"\n\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t    WELCOME ";
				Sleep(600); cout<<" TO ";
				Sleep(600); cout<<" AN  ";
				Sleep(600); cout<<" ADMIN ";
				Sleep(600); cout<<" ACCOUNT";
				Sleep(800); 
	
				for (int i=0; i<5; i++){
 					cout<<"."; Sleep(400);
				}
				system("cls");
	string s1,s2,s3;
	int option,a=1;
	while(a!=0){
		
	showMenu();
	cout<<"\n\t\tEnter the option: ";
	cin >> option;
	cin.ignore();
	system("cls");
	switch (option){
	
	case 1: {
		build();
		system("cls");
		break;
	}

	case 2:{
		view();
		break;
	}
	case 3:{
		cout<<"\n\t\tEnter the employee id/name to search record: ";
		getline(cin,s1);
		cout<<endl<<endl;
		find(s1);
		break;
	}
	case 5:{
		cout<<"\n\t\tEnter the employee id/name to delete record: ";
		getline(cin,s2);
		deletedata(s2);
		break;
	}
	case 4:{
		cout<<"\n\t\tEnter the employee id/name to change record: ";
		getline(cin,s3);
		update(s3);
		break;
	}
	
	case 6:{
		system("cls");
			cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tExiting";
			for (int i=0; i<5; i++){
 				cout<<"."; Sleep(400);
			}
		a=0;
		break;
	}
	default: {
		cout << "\n\t\tInalid choice"<<endl;
		break;
	}
}

}
}


void user(){
		system("cls");
				cout<<"\n\n\n\n\n\n\n";
				cout<<"\t\t\t\t\t    WELCOME ";
				Sleep(600); cout<<" TO ";
				Sleep(600); cout<<" AN  ";
				Sleep(600); cout<<" USER ";
				Sleep(600); cout<<" ACCOUNT";
				Sleep(800); 
	
				for (int i=0; i<5; i++){
 					cout<<"."; Sleep(400);
				}
				system("cls");
	cout<<setw(54)<<"\t\tAvailable Options\n"<<endl;
    cout<<setw(50)<<"1.View the entered data"<<endl;
    cout<<setw(53)<<"2.Search the employee data"<<endl;
    cout<<setw(33)<<"3.Exit"<<endl;
    cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
    cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
    cout<<endl<<endl;
    string s1,s2;
	int option,a=1;
	while(a!=0){
	cout<<"\n\n\t\t\t\tEnter the option: ";
	cin >> option;
	cin.ignore();
	switch (option){
		case 1:{
			cout<<setw(54)<<"\t\tAvailable Options\n"<<endl;
    cout<<setw(50)<<"1.View the entered data"<<endl;
    cout<<setw(53)<<"2.Search the employee data"<<endl;
    cout<<setw(33)<<"3.Exit"<<endl;
    cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
    cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
    cout<<endl<<endl;
		view();
		break;
	}
	case 2:{
		cout<<"\n\t\tEnter the employee id/name to search record: ";
		getline(cin,s1);
		system("cls");
		cout<<setw(54)<<"\t\tAvailable Options\n"<<endl;
    cout<<setw(50)<<"1.View the entered data"<<endl;
    cout<<setw(53)<<"2.Search the employee data"<<endl;
    cout<<setw(33)<<"3.Exit"<<endl;
    cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
    cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
    cout<<endl<<endl;
		cout<<endl<<endl;
		cout<<"\t\t\t\tEmployee Data\n\n";
		find(s1);
		break;
	}
		case 3:{
		a=0;
		system("cls");
			cout<<"\n\t\t\t\tExiting";
			for (int i=0; i<5; i++){
 				cout<<".\t"; Sleep(400);
			}
		break;
	}
	default: {
		cout << "\n\t\tInvalid selection"<<endl;
		break;
	}
}
}
}

void login(){
	string log="ans",pass="1234",log1="user",pass1="user",l,p,lp;
	string logpass=log+pass,logpass1=log1+pass1;
	cout<<"\n\n\n\t\t\tEnter the credentials...\n";
	cout<<"\n\t\tLogin: ";
	getline(cin,l);
	cout<<"\n\t\tPassword: ";
	getline(cin,p);
	lp=l+p;
	if(lp==logpass){
		admin();
	}
	else if(lp==logpass1){
		user();
	}
	else{
		char c;
		cout<<"\n\t\tIncorrect password or login...";
		cout<<"\n\t\tlogin again(y/n)..";
		cin>>c;
		cin.ignore();
		if(c=='y'){
			system("cls");
			login();
		}
		else{
		system("cls");
			cout<<"\n\t\t\t\tExiting";
			for (int i=0; i<5; i++){
 				cout<<".\t"; Sleep(4000);
			}
		}
	}
}

int main(){
	dis();
	cout<<"\n\n\t\t\t\t\t\t\t\tPlease wait....\n";
				cout<<"\n\n\t\t\t\t\t    REDIRECTING ";
				Sleep(600); cout<<" TO ";
				Sleep(600); cout<<" THE  ";
				Sleep(600); cout<<" LOGIN ";
				Sleep(600); cout<<" WINDOW";
				Sleep(800); 
	
				for (int i=0; i<5; i++){
 					cout<<"."; Sleep(400);
				}
				system("cls");
	login();
	return 0;
}
