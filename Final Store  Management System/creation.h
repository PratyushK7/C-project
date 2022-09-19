//
//  creator.cpp
//  StoreManagementSystem
//
//  Created by Rahul Bisht on 10/08/22.
//  Copyright © 2022 Adobe. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

//class to create new data
class createfiles
{
private:
    /* data */
public:
    void create_emp_worker();
    void create_emp_admin();
    void create_product_data();
    void create_customer_data();

} cf;






//class to read all the files stored
class readfiles
{
private:
    /* data */
public:
    void read_data_worker();
    void read_data_admin();
    void read_product_data();
    void read_customer_data();
    
} rf;








 


