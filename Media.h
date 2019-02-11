#pragma once
#include <string>

class Media
{
public:
	void setName(std::string);
	std::string getName();
	void setGenre(std::string);
	std::string getGenre();
	void setDesc(std::string);
	std::string getDesc();

private:
	std::string Name;
	std::string Genre;
	std::string Desc;
};