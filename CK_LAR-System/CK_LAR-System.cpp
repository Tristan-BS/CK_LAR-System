#include <iostream>
#include "Database.h"
#include "Password_EDUtility.h"

using namespace std;

Database DB;

int Choice;
string Username;
string Password;
string EMail;
int TFACode;

bool Register(string Username, string Password, string EMail, int TFACode);
bool Login(string Username, string Password);
bool ForgotPassword(string Username, string EMail, int TFACode);

int main() {
	while (true) {
		cout << "----------          MENU          ----------" << endl;

		cout << "1) Login" << endl;
		cout << "2) Register" << endl;
		cout << "3) Forgot Password" << endl;
		cout << "4) Exit" << endl;

		cout << "enter your choice: ";
		cin >> Choice;

		if (!DB.ConnectToDatabase()) {
			cout << "Failed to connect to the database!" << endl;
			cout << "Please establish a connection to the database first!" << endl;
			return 1;
		}
		else {
			switch (Choice) {
			case 1:
				cout << "----------          LOGIN          ----------" << endl;
				cout << "Enter your username: " << endl;
				cin >> Username;

				cout << "Enter your password: " << endl;
				cin >> Password;

				if (Login(Username, Password)) {
					cout << "Successfully logged in!" << endl;
				}
				else {
					cout << "Failed to login!" << endl;
				}

				break;

			case 2:
				cout << "----------          REGISTER          ----------" << endl;
				cout << "Enter your username: " << endl;
				cin >> Username;

				cout << "Enter your password: " << endl;
				cin >> Password;

				cout << "Enter your email: " << endl;
				cin >> EMail;

				cout << "Enter your 2FA Code (Your own PIN-Code): " << endl;
				cin >> TFACode;

				if (Register(Username, Password, EMail, TFACode)) {
					cout << "Successfully registered!" << endl;
				}
				else {
					cout << "Failed to register!" << endl;
				}

				break;
			case 3:
				cout << "----------          FORGOT PASSWORD          ----------" << endl;
				cout << "Enter your username: " << endl;
				cin >> Username;

				cout << "Enter your email: " << endl;
				cin >> EMail;

				cout << "Enter your 2FA Code (Your own PIN-Code): " << endl;
				cin >> TFACode;

				if (ForgotPassword(Username, EMail, TFACode)) {
					cout << "Successfully reset password!" << endl;
				}
				else {
					cout << "Failed to reset password!" << endl;
				}

				break;

			case 4:
				cout << "Saving everything..." << endl;
				cout << "Exiting... Goodbye!!" << endl;
				return 0;
			}
		}
	}
}

bool Register(string Username, string Password, string EMail, int TFACode) {
	cout << "Registering..." << endl;

	DB.CheckUsernameExistance(Username);

	return true;
}

bool Login(string Username, string Password) {
	cout << "Logging in..." << endl;
	return true;
}

bool ForgotPassword(string Username, string EMail, int TFACode) {
	cout << "Forgot Password..." << endl;
	return true;
}