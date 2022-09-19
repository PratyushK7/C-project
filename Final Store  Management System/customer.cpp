#include <iostream>
#include <map>
#include <vector>
#include <string> 
// #include "exception.h"
// #include "creation.h"
using namespace std;


class Customer
{
public:
    string customer_name;
    string cust_id;
    string cust_mobile;
    string membership;

    Customer(string& customer_name,string& cust_id,string& cust_mobile,string& membership):customer_name(customer_name),
    cust_id(cust_id),cust_mobile(cust_mobile),membership(membership){}
    
    Customer(Customer& c)
    {
        customer_name = c.customer_name;
        cust_id = c.cust_id;
        cust_mobile = c.cust_mobile;
        membership = c.membership;
    }
    Customer()
    {
        customer_name = "";
        cust_id = "";
        cust_mobile = "";
        membership = "";
    }
};

class Customerdata : public Customer
{
private:
    /* data */
    map<string,Customer> m; //map to store the customer data
    void take_input_id(string& s);
    void take_input_mobile(string& s);
    void take_input_membership(string& s);
    void display_customer_data();
    void add_Customer();
    void update_product_data();
    void delete_Customer();
    void find_Customer();
    

public:
    friend void createfiles::create_customer_data();
    friend void readfiles::read_customer_data();
    friend bool check_correct(string& a,string& b);
    void open_Customer_module();
    friend class Worker;
    friend class Admin;
} cd;


bool checkint(string& s)
{
    for(auto& it:s)
    {
        if(!isdigit(it))
        {
            return false;
        }
    }
    return true;
}

bool checkmobile(string& s)
{
    if(s.size()!=10)
    {
        return false;
    }
    for(auto& it:s)
    {
       if(!isdigit(it))
        {
            return false;
        }
    }
    return true;
}

void Customerdata::take_input_id(string& cust_id)
{
    char lab = 1;
    do
    {
        cout<<"\nEnter customer id:\n";
        try
        {
            cin>>cust_id;
            if(!checkint(cust_id))
            {
                lab = 0;
                throw(WrongInputException());
            }
            else
            {
                lab = 1;
            }
        }
        catch(WrongInputException& w)
        {
            cout<<"Wrong Input entered\n";
        }
    }
    while(!lab);
}

void Customerdata::take_input_mobile(string& cust_mobile)
{
    char lab = 1;
    do
    {
        cout<<"\nEnter customer mobile number:\n";
        try
        {
            cin>>cust_mobile;

            if(!checkmobile(cust_mobile))
            {
                lab = 0;
                throw(WrongInputException());
            }
            else
            {
                lab = 1;
            }
        }
        catch(WrongInputException& w)
        {
            w.get_message2();
        }
    }
    while(!lab);
}

void Customerdata::take_input_membership(string& membership)
{
    char lab = 1;

    do
    {
        cout<<"\nEnter customer membership:\n";
        try
        {
            cin>>membership;
            if(!checkint(membership))
            {
                lab = 0;
                throw(WrongInputException());
            }
            else
            {
                lab = 1;
            }
        }
        catch(WrongInputException& w)
        {
            w.get_message();
        }
    }
    while(!lab);
}

void Customerdata::add_Customer()
{
    char con;
    do
    {
        string customer_name, cust_id, cust_mobile, membership;
        cout<<"Enter customer name:\n";
        getline(cin>>ws,customer_name);
        
        take_input_id(cust_id);
        
        if(m.count(cust_id))
        {
            cout<<"Customer already exists with that Customer Id\n";
        }
        else
        {
            take_input_mobile(cust_mobile);
            take_input_membership(membership);
            Customer c(customer_name,cust_id,cust_mobile,membership);
            m[c.cust_id] = c;
            
        }
        cout<<"\nPress y to add another customer\n";
        cin>>con;
    }
    while (con=='y');
}

void Customerdata::display_customer_data()
{
    cout<<"----------------\n";

    for(auto& it:m)
    {
        cout<<"Customer Id : "<<it.first<<endl;
        cout<<"Customer Name : "<<it.second.customer_name<<endl;
        cout<<"Customer Mobile Number : "<<it.second.cust_mobile<<endl;
        int k = stoi(it.second.membership);
        switch (k)
        {
        case 0:
            cout<<"Customer Membership : No Membership"<<endl;
            break;
        
        case 1:
            cout<<"Customer Membership : Classic"<<endl;
            break;
            
        case 2:
            cout<<"Customer Membership : Gold"<<endl;
            break;

        case 3:
            cout<<"Customer Membership : Preminum"<<endl;
            break;
        default:
            cout<<"Customer Membership : No Membership"<<endl;
            break;
        }
        cout<<"----------------\n";
        
    }
}

void Customerdata::update_product_data()
{
    char con;
    do
    {
        
        string new_cust_id;
        string new_customer_name;
        string new_cust_mobile;
        string new_membership;
        string cust_id;
        take_input_id(cust_id);
        char ch; 
        if(m.count(cust_id)==0)
        {
            cout<<"Customer Id does not exist\n";
            goto endstep;
        }
        new_cust_id = cust_id;
        new_customer_name = m[cust_id].customer_name;
        new_cust_mobile = m[cust_id].cust_mobile;
        new_membership = m[cust_id].membership;
        cout<<"Press y to change the customer_id\n";
        cin>>ch;
        if(ch=='y')
        {
            take_input_id(new_cust_id);
            m[new_cust_id] = m[cust_id];
            m.erase(cust_id);
        }

        cout<<"Press y to change the customer_name\n";
        cin>>ch;
        if(ch=='y')
        {
        
            cout<<"Enter customer name:\n";
            getline(cin>>ws,new_customer_name);
            m[new_cust_id].customer_name = new_customer_name;
        }

        cout<<"Press y to change the customer_mobile\n";
        cin>>ch;
        if(ch=='y')
        {
        
            take_input_mobile(new_cust_mobile);
            m[new_cust_id].cust_mobile = new_cust_mobile;
        }
        
        cout<<"Press y to change the membership\n";
        cin>>ch;
        if(ch=='y')
        {
        
            take_input_membership(new_membership);
            m[new_cust_id].membership = new_membership;
        }
        
        endstep:
            cout<<"Press y to update another user data\n";
            cin>>con;
    }
    while(con=='y');

    
}

void Customerdata::delete_Customer()
{
    char con;
    do
    {
        string cust_id;
        take_input_id(cust_id);
        if(m.count(cust_id)==0)
        {
            cout<<"Customer does not exist\n";
            return;
        }
        m.erase(cust_id);
        cout<<"Customer deleted successfully\n\n";
        cout<<"\nPress y to delete another user\n";
        cin>>con;

    }
    while (con=='y');
    

}

void Customerdata::find_Customer()
{
    char con;
    do
    {
        string cust_id;
        take_input_id(cust_id);
        if(m.count(cust_id))
        {
            cout<<"Customer exists:\n";
            cout<<"Customer Id : "<<cust_id<<endl;
            cout<<"Customer Name : "<<m[cust_id].customer_name<<endl;
            cout<<"Customer Mobile Number : "<<m[cust_id].cust_mobile<<endl;
            switch (stoi(m[cust_id].membership))
            {
            case 0:
                cout<<"Customer Membership : No Membership"<<endl;
                break;
            
            case 1:
                cout<<"Customer Membership : Classic"<<endl;
                break;
                
            case 2:
                cout<<"Customer Membership : Gold"<<endl;
                break;

            case 3:
                cout<<"Customer Membership : Preminum"<<endl;
                break;
            default:
                cout<<"Customer Membership : No Membership"<<endl;
                break;
            }
        }
        else
        {
            cout<<"Customer does not exist\n";
        }

        cout<<"\nPress y to search for another user\n";
        cin>>con;

    }
    while (con=='y');
    
}

void Customerdata::open_Customer_module()
{
    
    string choice;
    char ch;
    do
    {
        cout<<"Enter a choice \n";
        cout<<" 1. To add data   2. To display customer data     3. To update existing customer data    4. Search for a customer 5. Delete a customer"<<endl;
        bool ct = true;
        do
        {
            cin>>choice;
            ct = checkint(choice);
            if(!ct)
            {
                cout<<"\nIncorrect input \n\n";
                cout<<"\nEnter a choice \n";
        cout<<" 1. To add data   2. To display customer data     3. To update existing customer data    4. Search for a customer 5. Delete a customer"<<endl;
            }
        }
        while(!ct);
        switch(stoi(choice))
        {
            case 1:
                cd.add_Customer();
                break;
            case 2:
                cd.display_customer_data();
                break;
            case 3:
                cd.update_product_data();
                break;
            case 4:
                cd.find_Customer();
                break;
            case 5:
                cd.delete_Customer();
                break;
            default:
                cout<<"Enter valid option\n";
                break;
               
        }
        cout<<"\nEnter y to continue with the choices\n";
        cin>>ch;
    } while (ch == 'y');
    
}

void createfiles::create_customer_data()
{
    fstream fout;
    fout.open("customerdata.csv", ios::out);
    string customer_name;
    string cust_id;
    string cust_mobile;
    string membership;
    // Read the input
    
    for (auto it:cd.m ){
  
        // Insert the data to file
        fout << it.first << ","
             << it.second.customer_name<< ","
             << it.second.cust_mobile <<","
             << it.second.membership << "\n";
    }
    fout.close();
}

void readfiles::read_customer_data()
 {
    fstream fin;
    fin.open("customerdata.csv",ios::in);
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
        string cust_id,customer_name,cust_mobile,membership;
        cust_id = store[0];
        customer_name = store[1];
        cust_mobile = store[2];
        membership = store[3];
        cd.m[cust_id] = Customer(customer_name,cust_id,cust_mobile,membership);
        // cout<<<<" "<<password<<" "<<role<<"\n";


    }
 }

//  int main()
//  {
//     cd.open_Customer_module();
//  }



