#include "LoginDetails.h"

void LoginDetails::setUsername(std::string username)
{
	this->Username = username;
}

std::string LoginDetails::getUsername()
{
	return this->Username;
}

void LoginDetails::setPassword(std::string password)
{
	this->Password = password;
}

std::string LoginDetails::getPassword()
{
	return this->Password;
}

std::string LoginDetails::getErrorRetry()
{
	return this->ErrorRetry;
}

std::string LoginDetails::getErrorNew()
{
	return this->ErrorNew;
}

std::string LoginDetails::getErrorLogin()
{
	return this->ErrorLogin;
}

std::string LoginDetails::initialDisplay()
{
	std::string resp;
	do
	{
		system("cls");
		std::cout << "Welcome To Media Manager Database, Enter '" + this->ErrorLogin + "' to login or '" + this->ErrorNew + "' to create a new user\n";
		std::getline(std::cin, resp);
	} while (resp != this->ErrorLogin && resp != this->ErrorNew);
	return resp;
}

void LoginDetails::loginDisplay()
{
	system("cls");
	std::cout << "Please Enter Login Details:\n";
	std::cout << "\nUsername: ";
	std::getline(std::cin, this->Username);
	std::cout << "\nPassword: ";
	std::getline(std::cin, this->Password);
}

bool LoginDetails::validUsername(std::vector<std::string> usernames)
{
	bool valid = false;
	for (int i = 0; i < usernames.size(); i++)
	{
		if (usernames.at(i) == this->Username)
		{
			valid = true;
		}
	}
	return valid;
}

bool LoginDetails::validPassword(std::string password)
{
	bool valid = false;
	
	if (password == this->Password)
	{
		valid = true;
	}
	return valid;
}

std::string LoginDetails::error()
{
	std::string resp;
	do
	{
		system("cls");
		std::cout << "Incorrect Login Details entered:\n";
		std::cout << "\nEnter '" + this->ErrorRetry + "' to retry or '" + this->ErrorNew + "' to create new user\n";
		std::getline(std::cin, resp);
	} while (resp != this->ErrorRetry && resp != this->ErrorNew);	
	return resp;
}

void LoginDetails::newDisplay(std::vector<std::string> usernames)
{
	bool existingUser = false;
	do
	{
		system("cls");
		if (existingUser) 
		{
			std::cout << "Username already taken\n";
		}
		existingUser = false;
		std::cout << "Please Enter New User Login Details:\n";
		std::cout << "\nUsername: ";
		std::getline(std::cin, this->Username);
		for (int i = 0; i < usernames.size(); i++)
		{
			if (this->Username == usernames.at(i))
			{
				existingUser = true;
				std::cout << "Username already taken\n";
			}
		}
	} while (existingUser);
	std::cout << "\nPassword: ";
	std::getline(std::cin, this->Password);
}