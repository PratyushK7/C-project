//
//  operations.cpp
//  StoreManagementSystem
//
//  Created by Kailasa Vennela on 10/08/22.
//  Copyright © 2022 Adobe. All rights reserved.
//


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
#include "operations.h"

map<string,vector<bD> >m;
map<string,vector<bD> >::iterator i;
vector<bD>::iterator j;



void crudOperations::addProduct()
{
    system("clear");
    cout<<"Enter book ID\n";
    cin>>bookId;
    cout<<"Enter book name\n";
    getline(cin>>ws,bookName);
    cout<<"Enter book cost\n";
    cin>>bookCost;
    cout<<"Enter book Author\n";
    getline(cin>>ws,bookAuthor);
    cout<<"Enter book publisher"<<endl;
    getline(cin>>ws,bookPublisher);
    cout<<"Enter category\n";
    getline(cin>>ws,bookCategory);
    cout<<"Enter book stock\n";
    cin>>bookStock;
    bD data(bookId,bookName,bookCost,bookAuthor,bookPublisher,bookStock);
    m[bookCategory].push_back(data);
    cout<<"Added successfully\n";
    
}

void crudOperations::displayProducts()
{
    cout<<"1. Display all the products\n";
    cout<<"2. Display only technical books\n";
    cout<<"3. Display only management books\n";
    cout<<"4. Display only historical books\n";
    cout<<"5. Display only documentational books\n";
    cout<<"Enter your choice\n";
    string cat="";
    int op;
    cin>>op;
    if(op==1)
        cat="Technical";
    else if(op==2)
        cat="Management";
    else if(op==3)
        cat="Historical";
    else cat="Documentation";
    if(m.size()==0)
        cout<<"Catalog is empty\n";
    else if(op==1)
    {
        for(i=m.begin();i!=m.end();i++)
        {
            
            for(j=m[i->first].begin();j!=m[i->first].end();j++)
            {
                cout<<"Book category: "<<(*i).first<<"\n";
                cout<<"Book ID: "<<(*j).bookId<<"\n";
                cout<<"Book Name: "<<(*j).bookName<<"\n";
                cout<<"Book Cost: "<<(*j).bookCost<<"\n";
                cout<<"Book Author: "<<(*j).bookAuthor<<"\n";
                cout<<"Book Publisher: "<<(*j).bookPublisher<<"\n";
                cout<<"Book stock: "<<(*j).bookStock<<"\n";
                cout<<"--------------------------------\n";
                
            }
        }
    }
    else if(op==2)
    {
        if(m[cat].size()==0)cout<<"There are no technical books\n";
        else
        {
            for(j=m[cat].begin();j!=m[cat].end();j++)
            {
                cout<<"Book category: Technical\n";
                cout<<"Book ID: "<<(*j).bookId<<"\n";
                cout<<"Book Name: "<<(*j).bookName<<"\n";
                cout<<"Book Cost: "<<(*j).bookCost<<"\n";
                cout<<"Book Author: "<<(*j).bookAuthor<<"\n";
                cout<<"Book Publisher: "<<(*j).bookPublisher<<"\n";
                cout<<"Book stock: "<<(*j).bookStock<<"\n";
                cout<<"--------------------------------\n";
            }
        }
    }
    else if(op==3)
    {
        if(m[cat].size()==0)cout<<"There are no management books\n";
        else
        {
            for(j=m[cat].begin();j!=m[cat].end();j++)
            {
                cout<<"Book category: Management\n";
                cout<<"Book ID: "<<(*j).bookId<<"\n";
                cout<<"Book Name: "<<(*j).bookName<<"\n";
                cout<<"Book Cost: "<<(*j).bookCost<<"\n";
                cout<<"Book Author: "<<(*j).bookAuthor<<"\n";
                cout<<"Book Publisher: "<<(*j).bookPublisher<<"\n";
                cout<<"Book stock: "<<(*j).bookStock<<"\n";
                cout<<"--------------------------------\n";
            }
        }
    }
    else if(op==4)
    {
        if(m[cat].size()==0)cout<<"There are no historical books\n";
        else
        {
            for(j=m[cat].begin();j!=m[cat].end();j++)
            {
                cout<<"Book category: Historical\n";
                cout<<"Book ID: "<<(*j).bookId<<"\n";
                cout<<"Book Name: "<<(*j).bookName<<"\n";
                cout<<"Book Cost: "<<(*j).bookCost<<"\n";
                cout<<"Book Author: "<<(*j).bookAuthor<<"\n";
                cout<<"Book Publisher: "<<(*j).bookPublisher<<"\n";
                cout<<"Book stock: "<<(*j).bookStock<<"\n";
                cout<<"--------------------------------\n";
            }
        }
    }
    else if(op==5)
    {
        if(m[cat].size()==0)cout<<"There are no documentational books\n";
        else
        {
            for(j=m[cat].begin();j!=m[cat].end();j++)
            {
                cout<<"Book category: Documentation\n";
                cout<<"Book ID: "<<(*j).bookId<<"\n";
                cout<<"Book Name: "<<(*j).bookName<<"\n";
                cout<<"Book Cost: "<<(*j).bookCost<<"\n";
                cout<<"Book Author: "<<(*j).bookAuthor<<"\n";
                cout<<"Book Publisher: "<<(*j).bookPublisher<<"\n";
                cout<<"Book stock: "<<(*j).bookStock<<"\n";
                cout<<"--------------------------------\n";
            }
        }
    }
    
    cout<<"displayed successfully\n";
}

void crudOperations::updateProduct()
{

    string b_id,nbname,nbauthor,nbpublisher,cat;
    string nbstock;
    int count=0,op;
    string nbcost;
    cout<<"1. Technical 2. Management 3. Historical 4. Documentation\n";
    cout<<"Enter book category number from above\n";
    cin>>op;
    if(op==1)
        cat="Technical";
    else if(op==2)
        cat="Management";
    else if(op==3)
        cat="Historical";
    else cat="Documentation";
    
    cout<<"Enter book id\n";
    cin>>b_id;
    
        for(j=m[cat].begin();j!=m[cat].end();j++)
        {
            if(b_id==(*j).bookId)
            {
                cout<<"Enter book name to update with\n";
                getline(cin>>ws,nbname);
                cout<<"Enter book cost to update with\n";
                cin>>nbcost;
                cout<<"Enter book author to update with\n";
                getline(cin>>ws,nbauthor);
                cout<<"Enter book publisher to update with\n";
                getline(cin>>ws,nbpublisher);
                cout<<"Enter stock to update with\n";
                cin>>nbstock;
                count++;
                (*j).bookName=nbname;
                (*j).bookCost=nbcost;
                (*j).bookAuthor=nbauthor;
                (*j).bookPublisher=nbpublisher;
                (*j).bookStock=nbstock;
                break;
            }
            
        
    }
    if(!count)
        cout<<"Book not found\n";
    cout<<"updated successfully\n";
    
        
}

void crudOperations::deleteProduct()
{
    cout<<"Enter category of book you wish to delete\n";
    cout<<"1. Technical 2. Management 3. Historical 4. Documentation\n";
    int op;
    cin>>op;
    string cat;
    if(op==1)
        cat="Technical";
    else if(op==2)
        cat="Management";
    else if(op==3)
        cat="Historical";
    else cat="Documentation";
    string b_id;
    cout<<"Enter book id you wish to delete\n";
    cin>>b_id;
    bool found=false;
    for(j=m[cat].begin();j!=m[cat].end();j++)
    {
        
            if(b_id==(*j).bookId)
            {
                found=true;
                m[cat].erase(j);
                break;
            }
        
    }
    if(!found)
        cout<<"Book not found\n";
    
    cout<<"deleted successfully\n";
}

void crudOperations::searchProduct()
{
    string cat,id;
    int op;
    cout<<"Enter category of the book\n";
    cout<<"1. Technical 2. Management 3. Historical 4. Documentation\n";
    cin>>op;
    if(op==1)
        cat="Technical";
    else if(op==2)
        cat="Management";
    else if(op==3)
        cat="Historical";
    else cat="Documentation";
    cout<<"Enter book id to be searched\n";
    cin>>id;
    bool found=false;
    for(j=m[cat].begin();j!=m[cat].end();j++)
    {
        if(id==(*j).bookId)
        {
            found=true;
            cout<<"Enter stock required\n";
            int sk;
            cin>>sk;
            if(stoi((*j).bookStock)>=sk)
            {
                cout<<"Stock is available. Would you like to buy it?\n";
                char ch;
                cin>>ch;
                if(ch=='y' || ch=='Y')
                {
                    cout<<"calculating\n";
                }
            }
        }
        
    }
    if(!found)
        cout<<"Book not found\n";
    cout<<"Searchd succesfully\n";
    
}

void createfiles::create_product_data()
{
    fstream file;
   file.open("bookFile.csv",ios::out);
//    cout<<m.size()<<" from save function\n";
   for(i=m.begin();i!=m.end();i++)
   {

       for(j=m[i->first].begin();j!=m[i->first].end();j++)
       {
            file<<(*i).first<<","<<(*j).bookId<<","<<(*j).bookName<<","<<(*j).bookCost<<","<<(*j).bookAuthor<<","<<(*j).bookPublisher<<","<<(*j).bookStock<<"\n";
            // cout<<(*i).first<<","<<(*j).bookId<<","<<(*j).bookName<<","<<(*j).bookCost<<","<<(*j).bookAuthor<<","<<(*j).bookPublisher<<","<<(*j).bookStock<<"\n";
       }
   }
   file.close();
}

void readfiles::read_product_data()
{
   fstream fin;
   fin.open("bookFile.csv",ios::in);
   if(!fin)cout<<"Error in opening the file\n";

   else
   {
   vector<string>row;
   string line,word,temp;
   while(!fin.eof())
   {
       row.clear();
       getline(fin,line);
       stringstream s(line);
       while(getline(s,word,','))
       {
           row.push_back(word);
       }
       if(row.size()!=7)
       continue;
   
       string id=row[1];
       string name=row[2];
       string cost= row[3];
       string author=row[4];
       string pubs=row[5];
       string stk= row[6];
       bD data(id,name,cost,author,pubs,stk);
       m[row[0]].push_back(data);
   }
   fin.close();
   }
}

void start()
{
    int op;
    crudOperations c;
    do{
        
    cout<<"Enter your choice\n";
        cout<<"1.Add product 2. Display products 3. Update product 4. Search Product 5.Delete Product\n";
        cin>>op;
        switch(op)
        {
            case 1:
                c.addProduct();
                break;
            case 2:
                c.displayProducts();
                break;
            case 3:
                c.updateProduct();
                break;
            case 4:
                c.searchProduct();
            case 5:
                c.deleteProduct();
            default:
                cout<<"Enter valid option\n";
                break;
                
        }
        cout<<"Enter 1 to continue\n";
        cin>>op;
    } while(op==1);
    
    
}



