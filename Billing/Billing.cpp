//
//  Billing.cpp
//  StoreManagementSystem
//
//  Created by Pratyush Kumar on 10/08/22.
//  Copyright © 2022 Adobe. All rights reserved.
//

#include "Billing.hpp"
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
    string product_name;
    string product_type;
    double price;
    int quantity;
    
    Item(string& p_name, string& p_type, double& p_price, int& p_quantity):product_name(p_name), product_type(p_type), price(p_price), quantity(p_quantity){
        
    }
};

class Billing{
    double billAmount;
    
public:
    Billing():billAmount(0){
    }
    
    void applyDiscount(int membership_category){
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
      }
      (this->billAmount) *= (100-discount)/100.0;
    }


    double calculateBill(vector<Item> order, int membership_category){
      for(Item item: order){
        double quantity = item.quantity;
        double price = item.price;
        this->billAmount += quantity * price;
      }
      applyDiscount(membership_category);
      return this->billAmount;
    }
};


