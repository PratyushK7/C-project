
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