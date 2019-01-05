#include <iostream>
#include <string>
#include <vector>
#include "LoginDetails.h"
#include "sqlite3.h"

void main()
{
	
	LoginDetails m_Login;
	sqlite3 *m_MediaDB;
	sqlite3_stmt *stmt;
	std::vector<std::string> m_Usernames;
	std::string m_Password;
	bool m_LoginError;
	std::string m_LoginErrorChoice;
	
	//Connect to database
	int rc = sqlite3_open("MediaManager.db", &m_MediaDB);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_MediaDB));
		return;
	}
	m_LoginErrorChoice = m_Login.initialDisplay();
	if (m_LoginErrorChoice == m_Login.getErrorLogin())
	{
		do
		{
			m_LoginErrorChoice = "";
			m_Login.loginDisplay();

			//Get all usernames from database and store in m_Usernames
			const char *sqlU = "SELECT Username FROM LoginDetails";
			rc = sqlite3_prepare_v2(m_MediaDB, sqlU, -1, &stmt, NULL);
			if (rc != SQLITE_OK) {
				std::cout << ("error: ", sqlite3_errmsg(m_MediaDB));
				return;
			}
			while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
				m_Usernames.push_back(std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
			}
			if (rc != SQLITE_DONE) {
				std::cout << ("error: ", sqlite3_errmsg(m_MediaDB));
			}
			sqlite3_finalize(stmt);

			//Check if Username Valid
			if (m_Login.validUsername(m_Usernames))
			{

				//Get password from database for entered username, if valid username
				std::string tempStrP = ("SELECT Password FROM LoginDetails Where Username='" + m_Login.getUsername() + "'");
				const char *tempChrP = tempStrP.c_str();
				const char *sqlP = (char*)tempChrP;
				rc = sqlite3_prepare_v2(m_MediaDB, sqlP, -1, &stmt, NULL);
				if (rc != SQLITE_OK) {
					std::cout << ("error: ", sqlite3_errmsg(m_MediaDB));
					return;
				}
				while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
					m_Password = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
				}
				if (rc != SQLITE_DONE) {
					std::cout << ("error: ", sqlite3_errmsg(m_MediaDB));
				}
				sqlite3_finalize(stmt);

				//Check if valid password
				if (!m_Login.validPassword(m_Password))
				{
					m_LoginErrorChoice = m_Login.error();
				}
			}
			else {
				m_LoginErrorChoice = m_Login.error();
			}
		} while (m_LoginErrorChoice == m_Login.getErrorRetry());
	}
	if (m_LoginErrorChoice == m_Login.getErrorNew())
	{
		m_Login.newDisplay(m_Usernames);
		
		//Create table for new user
		std::string tempStrN = ("CREATE TABLE " + m_Login.getUsername() + "(Name STRING, Genre STRING, Description STRING)");
		const char *tempChrN = tempStrN.c_str();
		const char *sqlN = (char*)tempChrN;
		rc = sqlite3_prepare_v2(m_MediaDB, sqlN, -1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			std::cout << ("error: ", sqlite3_errmsg(m_MediaDB));
			return;
		}
		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		}
		if (rc != SQLITE_DONE) {
			std::cout << ("error: ", sqlite3_errmsg(m_MediaDB));
		}
		sqlite3_finalize(stmt);

		//Add new user to login database
		std::string tempStrA = ("INSERT INTO LoginDetails VALUES ('" + m_Login.getUsername() + "', '" + m_Login.getPassword() + "')");
		const char *tempChrA = tempStrA.c_str();
		const char *sqlA = (char*)tempChrA;
		rc = sqlite3_prepare_v2(m_MediaDB, sqlA, -1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			std::cout << ("error: ", sqlite3_errmsg(m_MediaDB));
			return;
		}
		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		}
		if (rc != SQLITE_DONE) {
			std::cout << ("error: ", sqlite3_errmsg(m_MediaDB));
		}
		sqlite3_finalize(stmt);
	}
	return;
}