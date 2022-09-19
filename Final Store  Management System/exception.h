#include <iostream>
using namespace std;

class WrongInputException
{
    private:
    string message = "You have entered wrong input\n";
    string message2 = "Invalid Phone number\n";
    string message3 = "Entry Does not Exist\n";
    string message4 = "Insufficient stock";
public:
    void get_message();
    void get_message2();
    void get_message_no_entry();
    void get_message_insufficent();
};

void WrongInputException::get_message()
{
    cout<<message<<"\n";
}

void WrongInputException::get_message2()
{
    cout<<message2<<"\n";
}

void WrongInputException::get_message_no_entry()
{
    cout<<message3<<"\n";
}

void WrongInputException::get_message_insufficent()
{
    cout<<message4<<"\n";
}



