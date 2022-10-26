#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
using namespace std;

class doctor{
	private:
	int doctor_number;
	string first_name;
	string last_name;
	string city;
	string speciality;
	string department;
	string phone_number;
	int salary;
	int date;
	int month;
	int year;
	public:
	void input_data();
	void store();
	void diaplay_all();
	void diaplay_with_first_name();
	void display_with_city();
	void display_with_phone_number();
	void update_record();
	void delete_record();
};

void doctor::input_data(){
	cout<<"Enter Doctor Number  "<<endl;
	cin>>doctor_number;
	cout<<"Enter First Name  "<<endl;
	cin>>first_name;
	cout<<"Enter Last Name  "<<endl;
	cin>>last_name;
	cout<<"Enter City  "<<endl;
	cin>>city;
	cout<<"Enter your Speciality  "<<endl;
	cin>>speciality;
	cout<<"Enter your Department  "<<endl;
	cin>>department;
	cout<<"Enter your phone number  "<<endl;
	cin>>phone_number;
	cout<<"Enter your Salary  "<<endl;
	cin>>salary;
	cout<<"Enter Your Date Of Joining  "<<endl;
	cout<<"Enter Date  "<<endl;
	cin>>date;
	cout<<"Enter month  "<<endl;
	cin>>month;
	cout<<"Enter year  "<<endl;
	cin>>year;
	cout<<endl;
}

void doctor::store(){
	ofstream write;
	write.open("doctor.txt",ios::app);
	write<<doctor_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<speciality<<"\t"<<department<<"\t"<<phone_number<<"\t"<<salary<<"\t"<<date<<"-"<<month<<"-"<<year<<endl;
    write.close(); 
}

void doctor::diaplay_all(){
	ifstream read;
	read.open("doctor.txt");
	if(!read){
		cout<<"File for the display All cannot Open "<<endl; 
	}
	else{
		while(read>>doctor_number>>first_name>>last_name>>city>>speciality>>department>>phone_number>>salary>>date>>month>>year){
			cout<<doctor_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<speciality<<"\t"<<department<<"\t"<<phone_number<<"\t"<<salary<<"\t"<<date<<"-"<<month<<"-"<<year<<endl;
		}
	}
}

void doctor::delete_record(){
		int count;
		ifstream read("doctor.txt");
	ofstream write("temp.txt");
	if(!read){
		cout<<"File for the updation cannot open "<<endl;
	}
	else{
		
		string first_name_to_delete;
		cout<<"Enter First Name of the Doctor To update the record "<<endl;
		cin>>first_name_to_delete;
		while(read>>doctor_number>>first_name>>last_name>>city>>speciality>>department>>phone_number>>salary>>date>>month>>year){
			if(first_name_to_delete.compare(first_name)==0){
				   count++;
				   continue;
				   write<<doctor_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<speciality<<"\t"<<department<<"\t"<<phone_number<<"\t"<<salary<<"\t"<<date<<"-"<<month<<"-"<<year<<endl; 
				}
			    else{
			    write<<doctor_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<speciality<<"\t"<<department<<"\t"<<phone_number<<"\t"<<salary<<"\t"<<date<<"-"<<month<<"-"<<year<<endl;
				}
		    }
		}
		if(count==0){
			cout<<"Your Record Cannot  DELETE Beacuse Record Not Found "<<endl;
		}
		else{
			cout<<"Your Record DELETED sucessfully "<<endl;
		}
		read.close();
		write.close();
		remove("doctor.txt");
		rename("temp.txt","doctor.txt");
	
}

void doctor::update_record(){
	char count=0;
	ifstream read("doctor.txt");
	ofstream write("temp.txt");
	if(!read){
		cout<<"File for the updation cannot open ";
	}
	else{
		string first_name_to_update;
		cout<<"Enter First Name of the Doctor To update the record "<<endl;
		cin>>first_name_to_update;
		while(read>>doctor_number>>first_name>>last_name>>city>>speciality>>department>>phone_number>>salary>>date>>month>>year){
			if(first_name_to_update.compare(first_name)==0){
				input_data();
				write<<doctor_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<speciality<<"\t"<<department<<"\t"<<phone_number<<"\t"<<salary<<"\t"<<date<<"-"<<month<<"-"<<year<<endl;
				count++;
				}    
			}
		}
		if(count==0){
			cout<<"Your record is not UPDATED  Because No Record Found"<<endl;
		}
		else{
			cout<<"Your Record is UPDATED sucessfully "<<endl;
		}
		read.close();
		write.close();
		remove("doctor.txt");
		rename("temp.txt","doctor.txt");
	}

void doctor::display_with_phone_number(){
	ifstream read;
	read.open("doctor.txt");
	if(!read){
		cout<<"File for the search by phone number cannot open "<<endl; 
	}
	else{
		string phone_number_to_search;
		cout<<"Enter the First Name of the Person to Find the record "<<endl;
		cin>>phone_number_to_search;
		while(read>>doctor_number>>first_name>>last_name>>city>>speciality>>department>>phone_number>>salary>>date>>month>>year){
			if(phone_number_to_search.compare(phone_number)==0){
			cout<<doctor_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<speciality<<"\t"<<department<<"\t"<<phone_number<<"\t"<<salary<<"\t"<<date<<"-"<<month<<"-"<<year<<endl;
			}
		}
	}
}

void doctor::display_with_city(){
	ifstream read;
	read.open("doctor.txt");
	if(!read){
		cout<<"File for the search From City cannot Open "; 
	}
	else{
		string city_to_search;
		cout<<"Enter the city to Find the record  "<<endl;
		cin>>city_to_search;
		while(read>>doctor_number>>first_name>>last_name>>city>>speciality>>department>>phone_number>>salary>>date>>month>>year){
			if(city_to_search.compare(city)==0){
			cout<<doctor_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<speciality<<"\t"<<department<<"\t"<<phone_number<<"\t"<<salary<<"\t"<<date<<"-"<<month<<"-"<<year<<endl;
			}
		}
	}
}

void doctor::diaplay_with_first_name(){
	ifstream read;
	read.open("doctor.txt");
	if(!read){
		cout<<"File for the display All cannot Open "; 
	}
	else{
		string first_name_to_search;
		cout<<"Enter the First Name of the Person to Find the record "<<endl;
		cin>>first_name_to_search;
		while(read>>doctor_number>>first_name>>last_name>>city>>speciality>>department>>phone_number>>salary>>date>>month>>year){
			if(first_name_to_search.compare(first_name)==0){
			cout<<doctor_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<speciality<<"\t"<<department<<"\t"<<phone_number<<"\t"<<salary<<"\t"<<date<<"-"<<month<<"-"<<year<<endl;
			}
		}
	}
}


class patient{
	private:
	int patient_number;
	string first_name;
	string last_name;
	string city;
	string problem;
	string type;
	string phone_number;
	int date_of_adm;
	int month_of_adm;
	int year_of_adm;
	int date_of_discharge;
	int month_of_discharge;
	int year_of_discharge;
	public:
	void input_data();
	void store();
	void diaplay_all();
	void diaplay_with_first_name();
	void display_with_city();
	void display_with_phone_number();
	void update_record();
	void delete_record();
};

void patient::input_data(){
	cout<<"Enter patient Number  "<<endl;
	cin>>patient_number;
	cout<<"Enter First Name  "<<endl;
	cin>>first_name;
	cout<<"Enter Last Name  "<<endl;
	cin>>last_name;
	cout<<"Enter City  "<<endl;
	cin>>city;
	cout<<"Enter your problem  "<<endl;
	cin>>problem;
	cout<<"Enter your type  "<<endl;
	cin>>type;
	cout<<"Enter your phone number  "<<endl;
	cin>>phone_number;
	cout<<"Enter Your date_of ADMISSION  "<<endl;
	cout<<"Enter date "<<endl;
	cin>>date_of_adm;
	cout<<"Enter month  "<<endl;
	cin>>month_of_adm;
	cout<<"Enter year  "<<endl;
	cin>>year_of_adm;
	cout<<"Enter Your date of DISCHARGE  "<<endl;
	cout<<"Enter Date "<<endl;
	cin>>date_of_discharge;
	cout<<"Enter month  "<<endl;
	cin>>month_of_discharge;
	cout<<"Enter year "<<endl;
	cin>>year_of_discharge;
	cout<<endl;
}

void patient::store(){
	ofstream write;
	write.open("patient.txt",ios::app);
	write<<patient_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<problem<<"\t"<<type<<"\t"<<phone_number<<"\t"<<date_of_adm<<"-"<<month_of_adm<<"-"<<year_of_adm<< "\t "<<date_of_discharge<<"-"<<month_of_discharge<<"-"<<year_of_discharge<<endl;
    write.close(); 
}

void patient::diaplay_all(){
	ifstream read;
	read.open("patient.txt");
	if(!read){
		cout<<"File for the display All cannot Open "<<endl; 
	}
	else{
		while(read>>patient_number>>first_name>>last_name>>city>>problem>>type>>phone_number>>date_of_adm>>month_of_adm>>year_of_adm>>date_of_discharge>>month_of_discharge>>year_of_discharge){
			cout<<patient_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<problem<<"\t"<<type<<"\t"<<phone_number<<"\t"<<date_of_adm<<"-"<<month_of_adm<<"-"<<year_of_adm<<" \t "<<date_of_discharge<<"-"<<month_of_discharge<<"-"<<year_of_discharge<<endl;
		}
	}
}

void patient::delete_record(){
	int count=0;
	ifstream read("patient.txt");
	ofstream write("temp.txt");
	if(!read){
		cout<<"File for the deletion cannot open "<<endl;
	}
	else{
		string first_name_to_delete;
		cout<<"Enter First Name of the patient To delete  the record "<<endl;
		cin>>first_name_to_delete;
		while(read>>patient_number>>first_name>>last_name>>city>>problem>>type>>phone_number>>date_of_adm>>month_of_adm>>year_of_adm>>date_of_discharge>>month_of_discharge>>year_of_discharge){
			if(first_name_to_delete.compare(first_name)==0){
				   count++;
				   continue;
				   write<<patient_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<problem<<"\t"<<type<<"\t"<<phone_number<<"\t"<<date_of_adm<<"-"<<month_of_adm<<"-"<<year_of_adm<<" \t "<<date_of_discharge<<"-"<<month_of_discharge<<"-"<<year_of_discharge<<endl; 
			    }
			    else {
			    	write<<patient_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<problem<<"\t"<<type<<"\t"<<phone_number<<"\t"<<date_of_adm<<"-"<<month_of_adm<<"-"<<year_of_adm<<" \t "<<date_of_discharge<<"-"<<month_of_discharge<<"-"<<year_of_discharge<<endl;
				}
		    }
		}
		if(count==0){
			cout<<"Your Record Cannot be DELETE Because No Record Found "<<endl;
		}
		else{
			cout<<"Your Record DELETED sucessfully "<<endl;
		}
		read.close();
		write.close();
		remove("patient.txt");
		rename("temp.txt","patient.txt");
}

void patient::update_record(){
	int count=0;
	ifstream read("patient.txt");
	ofstream write("temp.txt");
	if(!read){
		cout<<"File for the updation cannot open ";
	}
	else{
		string first_name_to_update;
		cout<<"Enter First Name of the patient To update the record "<<endl;
		cin>>first_name_to_update;
		while(read>>patient_number>>first_name>>last_name>>city>>problem>>type>>phone_number>>date_of_adm>>month_of_adm>>year_of_adm>>date_of_discharge>>month_of_discharge>>year_of_discharge){
			if(first_name_to_update.compare(first_name)==0){
				input_data();
				write<<patient_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<problem<<"\t"<<type<<"\t"<<phone_number<<"\t"<<date_of_adm<<"-"<<month_of_adm<<"-"<<year_of_adm<<" \t "<<date_of_discharge<<"-"<<month_of_discharge<<"-"<<year_of_discharge<<endl;
				count++;
				}
				else{
		        write<<patient_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<problem<<"\t"<<type<<"\t"<<phone_number<<"\t"<<date_of_adm<<"-"<<month_of_adm<<"-"<<year_of_adm<<" \t "<<date_of_discharge<<"-"<<month_of_discharge<<"-"<<year_of_discharge<<endl;
				}    
			}
		}
		if(count==0){
			cout<<"Your record is not UPDATED Because No Record Found"<<endl;
		}
		else{
			cout<<"Your Record is UPDATED sucessfully "<<endl;
		}
		read.close();
		write.close();
		remove("patient.txt");
		rename("temp.txt","patient.txt");
}

void patient::display_with_phone_number(){
	ifstream read;
	read.open("patient.txt");
	if(!read){
		cout<<"File for the search by phone number cannot open "<<endl; 
	}
	else{
		string phone_number_to_search;
		cout<<"Enter the First Name of the Person to Find the record "<<endl;
		cin>>phone_number_to_search;
		while(read>>patient_number>>first_name>>last_name>>city>>problem>>type>>phone_number>>date_of_adm>>month_of_adm>>year_of_adm>>date_of_discharge>>month_of_discharge>>year_of_discharge){
			if(phone_number_to_search.compare(phone_number)==0){
			cout<<patient_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<problem<<"\t"<<type<<"\t"<<phone_number<<"\t"<<date_of_adm<<"-"<<month_of_adm<<"-"<<year_of_adm<<" \t "<<date_of_discharge<<"-"<<month_of_discharge<<"-"<<year_of_discharge<<endl;
			}
		}
	}
}

void patient::display_with_city(){
	ifstream read;
	read.open("patient.txt");
	if(!read){
		cout<<"File for the search From City cannot Open "; 
	}
	else{
		string city_to_search;
		cout<<"Enter the city to Find the record  "<<endl;
		cin>>city_to_search;
		while(read>>patient_number>>first_name>>last_name>>city>>problem>>type>>phone_number>>date_of_adm>>month_of_adm>>year_of_adm>>date_of_discharge>>month_of_discharge>>year_of_discharge){
			if(city_to_search.compare(city)==0){
			cout<<patient_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<problem<<"\t"<<type<<"\t"<<phone_number<<"\t"<<date_of_adm<<"-"<<month_of_adm<<"-"<<year_of_adm<<" \t "<<date_of_discharge<<"-"<<month_of_discharge<<"-"<<year_of_discharge<<endl;
			}
		}
	}
}

void patient::diaplay_with_first_name(){
	ifstream read;
	read.open("patient.txt");
	if(!read){
		cout<<"File for the display All cannot Open "; 
	}
	else{
		string first_name_to_search;
		cout<<"Enter the First Name of the Person to Find the record "<<endl;
		cin>>first_name_to_search;
		while(read>>patient_number>>first_name>>last_name>>city>>problem>>type>>phone_number>>date_of_adm>>month_of_adm>>year_of_adm>>date_of_discharge>>month_of_discharge>>year_of_discharge){
			if(first_name_to_search.compare(first_name)==0){
			cout<<patient_number<<"\t"<<first_name<<"\t"<<last_name<<"\t"<<city<<"\t"<<problem<<"\t"<<type<<"\t"<<phone_number<<"\t"<<date_of_adm<<"-"<<month_of_adm<<"-"<<year_of_adm<<" \t "<<date_of_discharge<<"-"<<month_of_discharge<<"-"<<year_of_discharge<<endl;
			}
		}
	}
	
}


class Allocation{
	private:
	string doc_name;
	int patient_number;
	string patient_name;
	public:
	void input_data();
	void store_data();
	void display_data();
	void search_with_doctor_name();
	void search_with_patient_name();
	void search_with_patient_number();
	void update_data();
	void delete_data();
};
void Allocation::input_data(){
	cout<<"Enter patient Number "<<endl;
	cin>>patient_number;
	cout<<"Enter Patient Name "<<endl;
	cin>>patient_name;
	cout<<"Enter   Doctor Name  "<<endl;
	cin>>doc_name;
	
}
void Allocation::store_data(){
	ofstream file;
	file.open("Allocation.txt",ios::app);
	file<<patient_number<<"\t"<<patient_name<<"\t"<<doc_name<<"\t"<<endl;
	file.close();
}
void Allocation::display_data(){
	ifstream file;
	file.open("Allocation.txt");
	if(!file){
		cout<<"File Cannot open for the Display All function "<<endl;
	}
	else{
		while(file>>patient_number>>patient_name>>doc_name){
			cout<<patient_number<<"\t"<<patient_name<<"  Allocated to  "<<doc_name<<"\t"<<endl;
		}
	}
	file.close();
}
void Allocation::search_with_doctor_name(){
	string doctor_name_search;
	ifstream file;
	file.open("Allocation.txt");
	if(!file){
		cout<<"File For the Search with doctor name cannot open "<<endl;
	}
	else{
		cout<<"Enter Doctor Name to Search ";
		cin>>doctor_name_search;
		while(file>>patient_number>>patient_name>>doc_name){
			if(doctor_name_search.compare(doc_name)==0){
				cout<<patient_number<<"\t"<<patient_name<<"  Allocated to  "<<doc_name<<"\t"<<endl;
			}
		}
		{	
	}
}
}
void Allocation::search_with_patient_name(){
	string patient_name_search;
	ifstream file;
	file.open("Allocation.txt");
	if(!file){
		cout<<"File For the Search with doctor name cannot open "<<endl;
	}
	else{
		cout<<"Enter Patient name to search  ";
		cin>>patient_name_search;
		while(file>>patient_number>>patient_name>>doc_name){
			if((patient_name_search.compare(patient_name)==0)){
				cout<<patient_number<<"\t"<<patient_name<<"  Allocated to  "<<doc_name<<"\t"<<endl;
			}
		}
	}
}
void Allocation::search_with_patient_number(){
    int patient_number_search;
	ifstream file;
	file.open("Allocation.txt");
	if(!file){
		cout<<"File For the Search with doctor name cannot open "<<endl;
	}
	else{
		cout<<"Enter Patient Number to search ";
		cin>>patient_number_search;
		while(file>>patient_number>>patient_name>>doc_name){
			if(patient_number_search==patient_number){
				cout<<patient_number<<"\t"<<patient_name<<"  Allocated to  "<<doc_name<<"\t"<<endl;
			}
		}
	}
}
void Allocation::delete_data(){
	int count=0;
	ifstream read("Allocation.txt");
	ofstream write("temp.txt");
	if(!read){
		cout<<"File for the deletion cannot open "<<endl;
	}
	else{
		
		string  patient_name_to_delete;
		cout<<"Enter First Name of the Doctor To Delete the record "<<endl;
		cin>>patient_name_to_delete;
		while(read>>patient_number>>patient_name>>doc_name){
			if(patient_name_to_delete.compare(patient_name)==0){
				   count++;
				   continue;
				   write<<patient_number<<"\t"<<patient_name<<"\t"<<doc_name<<"\t"<<endl;
				}
			    else{
				write<<patient_number<<"\t"<<patient_name<<"\t"<<doc_name<<"\t"<<endl;
				}
		    }
		}
		if(count==0){
			cout<<"Your Record Cannot be DELETE Beacuse no Record found  "<<endl;
		}
		else{
			cout<<"Your Record DELETED sucessfully "<<endl;
		}
		read.close();
		write.close();
		remove("Allocation.txt");
		rename("temp.txt","Allocation.txt");
}
void Allocation::update_data(){
	char count=0;
	ifstream read("Allocation.txt");
	ofstream write("temp.txt");
	if(!read){
		cout<<"File for the updation cannot open ";
	}
	else{
		string  patient_name_to_update;
		cout<<"Enter First Name of the Doctor To update the record "<<endl;
		cin>>patient_name_to_update;
		while(read>>patient_number>>patient_name>>doc_name){
			if(patient_name_to_update.compare(patient_name)==0){
				input_data();
				write<<patient_number<<"\t"<<patient_name<<"\t"<<doc_name<<"\t"<<endl;
				count++;
				}    
			}
		}
		if(count==0){
			cout<<"Your record is not UPDATED Because no record found "<<endl;
		}
		else{
			cout<<"Your Record is UPDATED sucessfully "<<endl;
		}
		read.close();
		write.close();
		remove("Allocation.txt");
		rename("temp.txt","Allocation.txt");
}


int main(){
	while(true){
	int number;
cout<<endl<<endl<<"\t\t\t\t WELCOME TO HOSPITAL MANAGEMENT SYSTEM "<<endl<<endl<<endl;
cout<<"\t\t\t\t Press 1--------To Enter in DOCTOR Block "<<endl;
cout<<"\t\t\t\t Press 2--------To Enter in Patient Block"<<endl;
cout<<"\t\t\t\t Press 3--------To ALLOCATE a Patient with Specific DOCTOR"<<endl;
cout<<"\t\t\t\t Press 4--------To Exit form Hospital Management System "<<endl;
cout<<"Enter Your Choise------- ";
cin>>number;
system("cls");

if(number==1){
	doctor d1;
	int num=0;
	while(true){
	cout<<endl<<endl<<"\t\t\t\t\t WELCOME TO DOCTOR BLOCK  "<<endl<<endl<<endl;
	cout<<"\t\t\t\t Press 1----------Input Record of Doctor "<<endl;
	cout<<"\t\t\t\t Press 2----------Display All Records of Doctor "<<endl;
	cout<<"\t\t\t\t Press 3----------Search Doctor with First name "<<endl;
	cout<<"\t\t\t\t Press 4----------Search Doctor with City "<<endl;
	cout<<"\t\t\t\t Press 5----------Search Doctor with Phone Number "<<endl;
	cout<<"\t\t\t\t Press 6----------Update Record "<<endl;
	cout<<"\t\t\t\t Press 7----------Delete Record "<<endl;
	cout<<"\t\t\t\t Press 8----------Exit From Doctor Block "<<endl<<endl;
	cout<<"ENTER YOUR CHOISE--------- ";
	cin>>num;
	system("cls");
	if(num==1){
	d1.input_data();
	d1.store();	
	}
	if(num==2){
	d1.diaplay_all();
	}
	else if(num==3){
	d1.diaplay_with_first_name();
	}
	else if(num==4){
	d1.display_with_city();
	}
	else if(num==5){
	d1.display_with_phone_number();
	}
	else if(num==6){
	d1.update_record();
	}
	else if(num==7){
	d1.delete_record();
	}
	else if(num==8){
	break;
	}
    
  }
}

if(number==2){
		patient p1;
	int num=0;
	while(true){
	cout<<endl<<endl<<"\t\t\t\t\t WELCOME TO PATIENT BLOCK "<<endl<<endl<<endl;
	cout<<"\t\t\t\t Press 1----------Input Record of patient "<<endl;
	cout<<"\t\t\t\t Press 2----------Display All Records of Patient "<<endl;
	cout<<"\t\t\t\t Press 3----------Search patient with First name "<<endl;
	cout<<"\t\t\t\t Press 4----------Search patient with City "<<endl;
	cout<<"\t\t\t\t Press 5----------Search patient with Phone Number "<<endl;
	cout<<"\t\t\t\t Press 6----------Update Record "<<endl;
	cout<<"\t\t\t\t Press 7----------Delete Record "<<endl;
	cout<<"\t\t\t\t Press 8----------Exit From patient Block "<<endl<<endl;
	cout<<"ENTER YOUR CHOISE--------- ";
	cin>>num;
	system("cls");
	if(num==1){
	p1.input_data();
	p1.store();	
	}
	if(num==2){
		p1.diaplay_all();
	}
	else if(num==3){
		p1.diaplay_with_first_name();
	}
	else if(num==4){
		p1.display_with_city();
	}
	else if(num==5){
		p1.display_with_phone_number();
	}
	else if(num==6){
		p1.update_record();
	}
	else if(num==7){
		p1.delete_record();
	}
	else if(num==8){
		break;
	}
    
  }
}
if(number==3){
		Allocation *a=new Allocation;
	int b;
	while(1){
		cout<<"\t\t\t\t\t WELCOME TO ALLOCATION BLOCK "<<endl<<endl;
		cout<<"\t\t\t\tPress 1----------To Allocate Patient "<<endl;
		cout<<"\t\t\t\tPress 2----------To Display All Data  "<<endl;
		cout<<"\t\t\t\tPress 3----------To Search with Doctor Name "<<endl;
		cout<<"\t\t\t\tPress 4----------To Search With Patient Name "<<endl;
		cout<<"\t\t\t\tPress 5----------To Search With Patient Number  "<<endl;
		cout<<"\t\t\t\tPress 6----------To Update Record  "<<endl;
		cout<<"\t\t\t\tPress 7----------To Delete Record  "<<endl;
		cout<<"\t\t\t\tPress 8----------To Exit From Alloction Block  "<<endl;
		cout<<"ENTER YOUR CHOISE-------- ";
		cin>>b;
		system("cls");
		if(b==1){
			a->input_data();
			a->store_data();
		}
		else if(b==2){
			a->display_data();
		}
		else if(b==3){
			a->search_with_doctor_name();
		}
		else if(b==4){
			a->search_with_patient_name();
		}
		else if(b==5){
		a->search_with_patient_number();
		}
		else if(b==6){
			a->update_data();
		}
		else if(b==7){
			a->delete_data();
		}
		else if(b==8){
			break;
	 }
	}
}
if(number==4){
	break ;
  }
}

return 0;
}
