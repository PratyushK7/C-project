//
//  Product.cpp
//  StoreManagementSystem
//
//  Created by Pratyush Kumar on 09/08/22.
//  Copyright © 2022 Adobe. All rights reserved.
//

#include <iostream>
using namespace std;

class Product{
    string product_type;
    string product_name;

public:
    Product(string p_type, string p_name):product_type(p_type), product_name(p_name){}
    
    string getProductDetails(){
        return "Product Name: " + product_name + "Product Type: " + product_type;
    }
};

// TODO:Should be implemented as Interface
