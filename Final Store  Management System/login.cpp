
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class Worker
{
    protected:
    void accessCustomerdata();
    void create_bill();
    void view_report();
    public:
    void access_worker_module();
};



class Admin:public Worker
{
    protected:
    void accessProductdata();
    public:
    void access_admin_module();
};


class Login
{
        /* File handling
        username
        password
        role   teacher, student admin    */
        public:
            map<string,string> m_admin;
            map<string,string> m_worker;
        public:
            
            void Register()
            {
               
                string username,password;
                int role;
                char ch = 0;
                do
                {
                    cout<<"Enter username\n";
                    getline(cin>>ws,username);
                    if(m_worker.count(username)||m_admin.count(username))
                    {
                        cout<<"Username exists\n";
                    }
                    else{
                        ch = 1;
                    }
                    
                }while(!ch);
                cout<<"Enter password\n";
                getline(cin>>ws,password);
                cout<<"Enter 1. worker 2. Admin\n";
                cin>>role;
                switch (role)
                {
                case 1:
                    m_worker[username] = password; 
                    cout<<"Worker registered\n";
                    break;
                
                case 2:
                    m_admin[username] = password;
                    cout<<"Admin registered\n";
                    break;
                default:
                    cout<<"Inavlid role\n";
                    break;
                }
            }
            bool login()
            {
                string un,pw;
                int found = 0;
                do
                {
                    cout<<"Enter username\n";
                    getline(cin>>ws,un);
                    cout<<"Enter password\n";
                    cin>>pw;
                    if(m_worker.count(un)&&m_worker[un]==pw)
                    {
                        cout<<"Welcome to worker: "<<un<<endl;
                        
                        found = 1;
                    }
                    else if(m_admin.count(un)&&m_admin[un]==pw)
                    {
                        cout<<"Welcome to admin: "<<un<<endl;
                        found = true;
                        found = 2;
                    }
                    else
                    {
                        cout<<"Invalid username or password"<<endl;
                    }
                } while(found==0);
                if(found == 1)
                {
                    Worker w;
                    w.access_worker_module();
                    return true;
                }
                else if(found==2)
                {
                    Admin a;
                    a.access_admin_module();
                    return true;
                }
                // fin.close();
                // return found;
                return 0;
            }
            
            friend void create_emp_worker();
            friend void create_emp_admin();
            friend void read_data_worker();
            friend void read_data_admin();
} l;

void createfiles::create_emp_worker()
{
    fstream fout;
    fout.open("empdataworker.csv", ios::out);
  
    string username;
    string password;
    int role;
    // Read the input
    
    for (auto it:l.m_worker)
    {
  
  
        // Insert the data to file
        fout << it.first << ","
             << it.second << ","
             << "1"<< "\n";
    }

    fout.close();
}

void createfiles::create_emp_admin()
{
    fstream fout;
    fout.open("empdataadmin.csv", ios::out);
  
    string username;
    string password;
    int role;
    // Read the input
    
    for (auto it:l.m_admin)
    {
  
  
        // Insert the data to file
        fout << it.first << ","
             << it.second << ","
             << "2"<< "\n";
    }

    fout.close();
}


void readfiles::read_data_worker()
{
    fstream fin;
    fin.open("empdataworker.csv",ios::in);
    string temp;
    while(!fin.eof())
    {
        getline(fin,temp);
        stringstream ss(temp);
        string word;
        vector<string> store;
        while(getline(ss,word,','))
        {
            store.push_back(word);
        }
        if(store.size()<3)
        {
            continue;
        }
        string username,password;
        int role;
        username = store[0];
        password = store[1];
        l.m_worker[username] = password;

    }
    fin.close();

}

void readfiles::read_data_admin()
{
    fstream fin;
    fin.open("empdataadmin.csv",ios::in);
    string temp;
    while(!fin.eof())
    {
        getline(fin,temp);
        stringstream ss(temp);
        string word;
        vector<string> store;
        while(getline(ss,word,','))
        {
            store.push_back(word);
        }
        if(store.size()<3)
        {
            continue;
        }
        string username,password;
        int role;
        username = store[0];
        password = store[1];
        l.m_admin[username] = password;

    }
    fin.close();

}
