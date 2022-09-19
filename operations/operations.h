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
    double bookCost;
    string bookAuthor;
    string bookPublisher;
    string bookCategory;
    int bookStock;

public:
    void addProduct();
    void displayProducts();
    void deleteProduct();
    void searchProduct();
    void updateProduct();
    void saveToFile();
    void retrieveFromFile();
   
    
};
typedef class bookDetails
{
public:
    string bookId;
    string bookName;
    double bookCost;
    string bookAuthor;
    string bookPublisher;
    int bookStock;
public:
    bookDetails(string& Id,string& name,double& cost,string& author, string& publisher, int& stock)
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
