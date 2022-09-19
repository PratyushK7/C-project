//
//  Billing.cpp
//  StoreManagementSystem
//
//  Created by Pratyush Kumar on 10/08/22.
//  Copyright © 2022 Adobe. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

enum membership_type{
    NO_MEMBERSHIP,
    CLASSIC,
    GOLD,
    PREMIUM
};

class Item{
public:
    string book_id;
    string category;
    string demand;
    string customer_name;
    string cust_id;
    string membership;
    Item(string& book_id,string& category, string& demand,string& customer_name,string& cust_id,string& membership):book_id(book_id),category(category),demand(demand),customer_name(customer_name),cust_id(cust_id),membership(membership)
    {

    }
    friend class Worker;
    friend class Admin;

};


class Billing{
    double billAmount;

    
public:
    Billing():billAmount(0){
    }
    void applyDiscount(int membership_category);
    double calculateBill(vector<Item>& order, int membership_category);
} b;

