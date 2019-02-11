#pragma once
#include "Media.h"
#include <iostream>
#include <string>
#include<vector>

class MediaDetails
{
public:
	std::string mediaInitialDisplay();
	Media mediaAddDisplay();
	std::string getErrorView();
	std::string getErrorAdd();
	std::vector<Media> fullDB;
	std::vector<Media> searchResultDB;
	void drawDB(std::vector<Media>);
	

private:
	std::string ErrorView = "View";
	std::string ErrorAdd = "Add";
};