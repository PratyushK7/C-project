#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>
using namespace std;
class Login
{
        /* File handling
        username
        password
        role   teacher, student admin    */
        protected:
            string username;
            string password;
            int role;
        public:
            void Register()
            {
               
                fstream fout;
                fout.open("logindata.csv",ios::out | ios::app);
                cout<<"Enter username\n";
                cin>>username;
                cout<<"Enter password\n";
                cin>>password;
                cout<<"Enter 1. worker 2. Admin\n";
                cin>>role;
                fout<<username<<","<<password<<","<<role<<"\n";
                cout<<"Registered successfully\n";
                fout.close();
            }
            bool login()
            {
                string un,pw;
                fstream fin;
                fin.open("logindata.csv",ios::in);
                cout<<"Enter usernmae\n";
                cin>>un;
                cout<<"Enter password\n";
                cin>>pw;
                bool found=false;
                vector<string>row;
                string line,word,temp;
                while(fin)
                {
                    row.clear();
                    getline(fin,line);
                    stringstream s(line);
                    while(getline(s,word,','))
                        row.push_back(word);
                    username=row[0];
                    password=row[1];
                    role=stoi(row[2]);
                    //cout<<username<<" "<<password<<"\n";
                    if(un==username && pw==password)
                    {
                        found=true;
                        if(role==1)
                        {
                            cout<<"Welcome to representative : "<<username<<"\n";
                        }
                        else if(role==2)
                        {
                            cout<<"Welcome to admin : "<<username<<"\n";
                        }
                        break;
                    }
                }
                fin.close();
                return found;
                
            }
};
int main()
{
    cout<<" ------------  Welcome to Store Management System ----------\n";
   Login l1;
    int ch=0;
   do
    {
    cout<<"1. Login \n 2. Register \n 3. Exit"<<endl;
    cout<<"Enter choice: ";
        
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            bool b = l1.login();
            if(!b)cout<<"Invalid Credentials\n";
            break;
        }
        case 2:
            l1.Register();
            break;
        case 3:
            exit(1);
            break;
        default:
            cout<<"Enter valid choice\n";
            break;
    }
        cout<<"Enter 1 to continue\n";
        cin>>ch;
    }while(ch==1);
}
