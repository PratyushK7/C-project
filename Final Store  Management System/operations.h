//
//  operations.hpp
//  StoreManagementSystem
//
//  Created by Kailasa Vennela on 10/08/22.
//  Copyright © 2022 Adobe. All rights reserved.
//

#ifndef operations_hpp
#define operations_hpp


class crudOperations
{
private:
    string bookId;
    string bookName;
    string bookCost;
    string bookAuthor;
    string bookPublisher;
    string bookCategory;
    string bookStock;

public:
    void addProduct();
    void displayProducts();
    void deleteProduct();
    void searchProduct();
    void updateProduct();
    friend void readfiles::read_product_data();
    friend void createfiles::create_product_data();
    friend bool check_correct(string& ,string& b);
    friend class Admin;
    friend double Billing::calculateBill(vector<Item>& order,int membership);
};
typedef class bookDetails
{
public:
    string bookId;
    string bookName;
    string bookCost;
    string bookAuthor;
    string bookPublisher;
    string bookStock;
public:
    bookDetails(string& Id,string& name,string& cost,string& author, string& publisher, string& stock)
    {
        this->bookId=Id;
        this->bookName=name;
        this->bookCost=cost;
        this->bookAuthor=author;
        this->bookPublisher=publisher;
        this->bookStock=stock;
    }
    virtual ~bookDetails()
    {}
    
}bD;

#endif /* operations_hpp */
