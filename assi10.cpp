#include<iostream>
#include<string>
#include <sstream>
#include<fstream>
using namespace std;

struct stud
{ public:
    int roll_no;
    char name[10];
    char div;
    char address[20];
};
class Student
{public:
    struct stud records;
    fstream myfile;
    void Clear();
    void New_file();
    void Add();
    void Display_data();
    void Delete_student();
    void modify_data();   
};
void Student::Clear()
{ myfile.open("Studentdatabase.txt",ios::out|ios::trunc);
    myfile.close();}
void Student::New_file()
{myfile.open("Studentdatabase.txt");
    myfile<<"Rollno"<<"\t\t"<<"Name"<<"\t\t"<<"Division"<<"\t\t"<<"Address"<<endl;
    myfile.close();}
void Student::Add()
{ cout<<"\nEnter Roll no: "<<endl;
    cin>>records.roll_no;
    cout<<"Enter name: "<<endl;
    cin>>records.name;
    cout<<"Enter division: "<<endl;
    cin>>records.div;
    cout<<"Enter address: "<<endl;
    cin>>records.address; 
    myfile.open("Studentdatabase.txt",ios::app);
    myfile<<records.roll_no<<"\t\t\t"<<records.name<<"\t\t\t"<<records.div<<"\t\t\t"<<records.address<<endl;
    myfile.close();}
void Student::Display_data()
{string line;
    myfile.open("Studentdatabase.txt",ios::in);
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,line);
            cout<<"\n"<<line;} }
    else{cout<<"The file is not open for read"<<endl;}
    myfile.close();}
void Student::Delete_student()
{fstream temp;
    int roll;
    temp.open("temp.txt",ios::out);
    myfile.open("Studentdatabase.txt",ios::in);
     cout<<"Enter roll no.to delete records: "<<endl; cin>>roll;
    if(myfile.is_open()){
        string line;
        while(getline(myfile,line)){
           string linearray[4];
           int i=0;
           stringstream input (line);
           while(input.good () && i<4){
                  input >>linearray[i];
                  i++;}
           if (to_string(roll) != linearray[0]){
                temp<< line<<endl;}
            }}
    myfile.close();
    temp.close();
    remove("Studentdatabase.txt");
    rename("temp.txt","Studentdatabase.txt");}

void Student::modify_data()
{fstream temp; int roll;string line;
    temp.open("temp.txt",ios::out);
    myfile.open("Studentdatabase.txt",ios::in);
    cout<<"Enter roll no.to modify records: "<<endl;cin>>roll;
     if(myfile.is_open()){
        string line;
        while(getline(myfile,line)){
           string linearray[4];
           int i=0;
           stringstream input (line);
           while(input.good() && i<4){
                  input >>linearray[i];
                  i++;}
           if (to_string(roll) !=linearray[0]){
                temp << line<<endl;}
            else { cout<<"enetr the new roll number :"; cin>>linearray[0];
            cout<<"enetr the new name :";cin>>linearray[1];
            cout<<"enter the new division :";cin>>linearray[2];
            cout<<"enetr the new address :";cin>>linearray[3];
            temp<< linearray[0]<<"\t\t"<<linearray[1]<<"\t\t"<<linearray[2]<<"\t\t"<<linearray[3]<<endl;}
        }}myfile.close();
    temp.close();
    remove("Studentdatabase.txt");
    rename("temp.txt","Studentdatabase.txt");
}
int main()
{ fstream myfile;Student st;int chose,enter;
   while(true){
  cout<<"0.new file \n 1.add database \n 2.clear file \n 3.display student \n 4.delete \n 5.modify ";cin>>chose;
  switch(chose){
    case 0:
     st.New_file();
     break;
    case 1:
         st.Add();
         break;
    case 2:
        st.Clear();
        break;
     case 3:
        st.Display_data();
        break;
     case 4:
    st.Delete_student();
     break;
    case 5:
     st.modify_data();
     break;
     default:
     break;
  }cout<<"enter 1 if you want to perform again";cin>>enter;
  if(enter==1){ continue; }
  else{break;}
  } return 0;
}
