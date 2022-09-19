//
//  driver.cpp
//  StoreManagementSystem
//
//  Created by Kailasa Vennela on 14/08/22.
//  Copyright © 2022 Adobe. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <filesystem>
using namespace std;
#include "exception.h"
#include "creation.h"
#include "login.cpp"
#include "billling.cpp"

#include "customer.cpp"
#include "operations.cpp"

void Admin::accessProductdata()
{
    start();
}

void Worker::accessCustomerdata()
{
    cd.open_Customer_module();
}

bool check_correct(string& book_id,string& cust_id,string& demand,string& membeship,string& category)
{
    try
    {
        if((!checkint(book_id))||(!checkint(cust_id))||(!checkint(demand))||!checkint(membeship))
        {
            throw(WrongInputException());
        }
    }
    catch(WrongInputException& w)
    {
        w.get_message();
        return false;
    }
    for(auto& it:m[category])
    {
        if(it.bookId==book_id)
        {
            try
            {
                if(stoi(demand)>stoi(it.bookStock))
                {
                    throw(WrongInputException());
                }
                else{
                    return true;
                }
            }
            catch(WrongInputException& w)
            {
                w.get_message_insufficent();
                return false;
            }
        }
    }
    cout<<"Book does not exist\n";
    return false;
}

void Worker::create_bill()
{
    vector<Item> v;
    string customer_name;
    string cust_id;
    string membership;
    
    
    bool early_check = false; 
    while(!early_check)
    {
        cout<<"Enter Customer name\n";
        cin>>customer_name;

        cout<<"Enter customer id\n";
        cin>>cust_id;

        cout<<"Enter membership\n";
        cin>>membership;
        
        try
        {
            if(checkint(cust_id)==0||checkint(membership)==0)
            {
                throw(WrongInputException());

            }
            else
            {
                early_check = true;
            }
        }
        catch(WrongInputException& w)
        {
            w.get_message();
        }
        
    }
    
    char ch;
    do
    {
        string book_id;
        string category;
        string demand;
        
        cout<<"Enter Book category\n";
        cin>>category;

        cout<<"Enter Book Id\n";
        cin>>book_id;

        cout<<"Enter number of items needed\n";
        cin>>demand;
        

        bool val_check = check_correct(book_id,cust_id,demand,membership,category);
        if(val_check)
        {
            v.push_back(Item(book_id,category,demand,customer_name,cust_id,membership));
        }
        cout<<"Press y to enter another entry\n";
        cin>>ch;
    } while (ch=='y');
    
    double bill_val = b.calculateBill(v,stoi(membership));
    
}

void Worker::access_worker_module()
{
    char ch = 'y';
    do
    {
        
        string choice;
        cout<<" Welcome to Worker module\n";
        cout<<" Enter 1. Accessing customer data 2. Creating bills for the user 3. View reports\n";
        cin>>choice;
        try
        {
            if(!checkint(choice))
            {
                throw (WrongInputException());
            }
        }
        catch(WrongInputException& w)
        {
            w.get_message();
        }
        if(ch == 'y')
        {
            switch (stoi(choice))
            {
            case 1:
                accessCustomerdata();
                break;
            
            case 2:
                create_bill();
                break;

            case 3:
                view_report();
                break;
            default:
                cout<<"Inavlid choice\n";
                break;
            }
        }
        cout<<"Press y to continue\n";
        cin>>ch;
    } while (ch=='y');
    
    
}

void Worker::view_report()
{
    fstream fin;
    cout<<"Bill reports\n";
    cout<<"-----------------\n";
    fin.open("bills.csv",ios::in);
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
        if(store.size()==1)
        {
            cout<<"Total Bill:"<<store[0]<<"\n";
            cout<<"-----------------\n";
        }
        else if(store.size()==7)
        {
            cout<<"Category: "<<store[0]<<" \n"<<"Book ID: "<<store[1]<<" \n Demand: "<<store[2]<<" \n Customer name: "<<store[3]<<" \n Customer ID: "<<store[4];
            cout<<"\n Membership: "<<store[5]<<" \n Total: "<<store[6]<<"\n\n";
        }
        else
        {
            continue;
        }
    }
    fin.close();
}

void Admin::access_admin_module()
{
    char ch = 'y';
    do
    {
        
        string choice;
        cout<<" Welcome to Admin module\n";
        cout<<" Enter 1. Accessing product data 2. Creating bills for the user 3. View reports 4. Access Customer data\n";
        cin>>choice;
        try
        {
            if(!checkint(choice))
            {
                throw (WrongInputException());
            }
        }
        catch(WrongInputException& w)
        {
            w.get_message();
        }
        if(ch == 'y')
        {
            switch (stoi(choice))
            {
            case 1:
                accessProductdata();
                break;
            
            case 2:
                create_bill();
                break;

            case 3:
                view_report();
                break;
            case 4:
                accessCustomerdata();
                break;
            default:
            cout<<"Inavlid choice\n";
                break;
            }
        }
        cout<<"Press y to continue\n";
        cin>>ch;
    } while (ch=='y');
    
}

void Billing::applyDiscount(int membership_category){
      int discount = 0;
      switch (membership_category) {
        case NO_MEMBERSHIP:
          discount = 0;
          break;
        case CLASSIC:
          discount = 5;
          break;
        case GOLD:
          discount = 10;
          break;
        case PREMIUM:
          discount = 15;
          break;
        default:
          discount = 0;
          break;
      }
      (this->billAmount) *= (100-discount)/100.0;
    }

double Billing::calculateBill(vector<Item>& order, int membership_category){
      fstream fout;
      fout.open("bills.csv",ios::out|ios::app);
      vector<string> toBeDeleted;
      for(auto& it: order){
        
        for(auto& it2:m[it.category])
        {
            if(it2.bookId==it.book_id)
            {
              this->billAmount += stoi(it.demand)*stoi(it2.bookCost);
            fout<<it.category<<","<<it.book_id<<","<<it.demand<<","<<it.customer_name<<","<<it.cust_id<<","<<it.membership<<","<<stoi(it.demand)*stoi(it2.bookCost)<<"\n";
              it2.bookStock=to_string(stoi(it2.bookStock)-stoi(it.demand));
              if(it2.bookStock=="0")
              {
                swap(it2,m[it.category].back());
                m[it.category].pop_back();

              } 
            }

        }
      }
      applyDiscount(membership_category);
      fout << this->billAmount << "\n";
      fout.close();
      return this->billAmount;
    }


int main()
{
    cout<<" ------------  Welcome to Store Management System ----------\n";
    rf.read_data_admin();
    rf.read_product_data();
    rf.read_data_worker();
    rf.read_customer_data();
    
    int ch=0;
    do
    {
        cout<<" 1. Login \n 2. Register \n 3. Exit"<<endl;
        cout<<"Enter choice: ";
            
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                bool b = l.login();
                if(!b)cout<<"Invalid Credentials\n";
                break;
            }
            case 2:
                l.Register();
                break;
            case 3:
                goto ending;
                break;
            default:
                cout<<"Enter valid choice\n";
                break;
        }

        // cout<<"Enter 1 to continue\n";
        // cin>>ch;
    
    } while(1);

    ending:
    cf.create_emp_admin();
    cf.create_emp_worker();
    cf.create_product_data();
    cf.create_customer_data();
    return 0;
}

