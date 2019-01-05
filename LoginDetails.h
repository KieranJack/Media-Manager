#pragma once
#include <string>
#include <iostream>
#include <vector>

class LoginDetails
{
public:
	void setUsername(std::string);
	std::string getUsername();
	void setPassword(std::string);
	std::string getPassword();
	std::string getErrorRetry();
	std::string getErrorNew();
	std::string getErrorLogin();

	std::string initialDisplay();
	void loginDisplay();
	void newDisplay(std::vector<std::string>);
	bool validUsername(std::vector<std::string>);
	bool validPassword(std::string);
	std::string error();

private:
	std::string Username;
	std::string Password;
	std::string ErrorRetry = "Retry";
	std::string ErrorNew = "New";
	std::string ErrorLogin = "Login";
};