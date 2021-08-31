#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<conio.h>
using namespace std;
class Vehicle {
	private:
		void doChallan(int wheels) {
			fstream file;
			file.open("challan.txt",ios::in);
			int challan=0;
			char challanChar;
			string challanStr;
			if(!file.fail()) {
				while(file.get(challanChar))
				{
					challanStr+=challanChar;
				}
				stringstream geek(challanStr);
				geek>>challan;
			}

			if(wheels<=2) challan+=5;
			else if(wheels<=4 && wheels>2) challan += 10;
			else if(wheels>5) challan += 20;

			file.close();
			file.open("challan.txt",ios::out);
			file<<challan;
		}
	public:
		Vehicle() {

		}
		void add() {
			string numberPlate,type,color;
			int wheels;
			system("CLS");
			getline(std::cin, numberPlate);
			cout<<"Enter number plate of the vehicle: ";
			getline(std::cin, numberPlate);
			cout<<"Enter type of the vehicle: ";
			getline(std::cin, type);
			cout<<"Enter color of the vehicle: ";
			getline(std::cin, color);
			cout<<"Enter number of wheels of the vehicle: ";
			cin>>wheels;

			fstream file;
			file.open("information.txt",ios::in);
			string content;
			char s;
			size_t pos;
			while(file.get(s))
			{
				content+=s;
			}
			int id=0;
			pos = content.rfind("vehicle id:");
			if(pos!=string::npos) {
				string idstring;
				int i=11;
				while(content.at(pos+i)!='\n')
				{
					idstring+=content.at(pos+i);
					i++;
				}
				stringstream geek(idstring);
				geek>>id;
			}
			file.close();

			file.open("information.txt",ios::app);
			file<<"numberplate:"<<numberPlate<<endl<<"type:"<<type<<endl<<"color:"<<color<<endl<<"wheels:"<<wheels<<endl<<"vehicle id:"<<id+1<<endl<<endl;
			cout<<"Challan Done!!";
			file.close();
			doChallan(wheels);
		}

		bool search() {
			system("CLS");
			string numberPlate;
			cout<<"Enter Number Plate: ";
			getline(cin,numberPlate);
			getline(cin,numberPlate);

			fstream file;
			file.open("information.txt",ios::in);
			string content;
			char s;
			size_t pos;
			while(file.get(s))
			{
				content+=s;
			}
			int id=1;
			pos = content.rfind(numberPlate);
			if(pos!=string::npos) {

				int i=0,j=0;
				string st;
				while(j<5)
				{
					st+=content.at(pos-12+i);
					i++;
					if(content.at(pos-12+i)=='\n')j++;
				}
				cout<<endl<<st<<endl;
				return true;

			}
			else {
				return false;
			}
		}
		void helpline() {
			system("CLS");
			cout<<"Nearby Hospitals:"<<endl<<"LPU Uni Hospital : +91 0182 450 1227"<<endl<<"Chanan Ram Sampla Memorial Hospital: +91 094176 37006"<<endl<<"Cantt General Hospital: +91 0181 226 0028";
		}
		void viewChallan() {
			system("CLS");
			fstream file;
			file.open("challan.txt",ios::in);
			int challan=0;
			char challanChar;
			string challanStr;
			if(!file.fail()) {
				while(file.get(challanChar))
				{
					challanStr+=challanChar;
				}
				stringstream geek(challanStr);
				geek>>challan;
			}
			cout<<"Challan Collected Till now: Rs. "<<challan;
		}
		bool checkPassword(string pwd) {
			if(pwd=="ankit") return true;
			else return false;
		}
};
int showOptions();
void askToContinue(Vehicle vehicle);
void proceed(int,Vehicle);
void enter(Vehicle);
int main() {
	string pwd;
	Vehicle vehicle;
	string user;
	password:
		system("CLS");
		cout<<"enter the user name"<<endl;
		cin>>user;
		cout<<"Enter Password to continue:"<<endl;
		cin>>pwd;
		if(vehicle.checkPassword(pwd)){
			enter(vehicle);
		}
		else {
			cout<<"Your password is incorrect";
			getch();
			goto password;
		}
}
void enter(Vehicle vehicle) {
		int choice = showOptions();
		proceed(choice,vehicle);
}
int showOptions() {
	system("CLS");
	int choice;
	cout<<"*******************************************************************************************************"<<endl;
	cout<<"*                                   *TRAFFIC MANAGEMENT SYSTEM*                                       *"<<endl;
	cout<<"*                     1. Add the information of the person                                            *"<<endl;
	cout<<"*                     2. information Search                                                           *"<<endl;
	cout<<"*                     3. show money collected till now from challan                                   *"<<endl;
	cout<<"*                     4. Helpline number and information                                              *"<<endl;
	cout<<"*                     5. Exit the program                                                             *"<<endl;
	cout<<"*                     Choose an option:                                                               *"<<endl;
	cout<<"*******************************************************************************************************"<<endl;
	cin>>choice;
	return choice;
}
void proceed(int choice,Vehicle vehicle) {
	char opt1;
	switch(choice) {
		case 1:
			vehicle.add();
			askToContinue(vehicle);
			break;
		case 2:
			if(!vehicle.search()) {
				cout<<"No vehicle found with matching number plate";
			}
			askToContinue(vehicle);
			break;
		case 3:
			vehicle.viewChallan();
			askToContinue(vehicle);
			break;
		case 4:
			vehicle.helpline();
			askToContinue(vehicle);
			break;
		case 5:
			cout<<endl<<"Are You Sure?(Y/N)?";
			cin>>opt1;
			if(opt1=='Y' || 'y') exit(0);
			else enter(vehicle);
			break;
		default:
			cout<<"Choose a valid option."<<endl;
			askToContinue(vehicle);
	}
}
void askToContinue(Vehicle vehicle) {
	char a;
	cout<<endl<<"Do you want to continue(Y/N)?";
	cin>>a;
	if(a=='Y' || a=='y') enter(vehicle);
	else return;
}
