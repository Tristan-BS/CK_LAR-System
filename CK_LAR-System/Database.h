#pragma once
#include <iostream>
#include <string>
using namespace std;

class Database {
public:
	bool ConnectToDatabase();
	bool CheckUsernameExistance(string Username);
};
