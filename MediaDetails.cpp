#include "MediaDetails.h"

std::string MediaDetails::mediaInitialDisplay()
{
	std::string resp;
	do
	{
		system("cls");
		std::cout << "Here is your Media Manager Database, Enter '" + this->ErrorView + "' to view your collection or '" + this->ErrorAdd + "' to add a new entry\n";
		std::getline(std::cin, resp);
	} while (resp != this->ErrorView && resp != this->ErrorAdd);
	return resp;
}

Media MediaDetails::mediaAddDisplay()
{
	Media toAdd;
	std::string resp;
	system("cls");
	std::cout << "Please enter the name of the media to add:\n";
	std::getline(std::cin, resp);
	toAdd.setName(resp);

	std::cout << "Please enter the genre of the media to add:\n";
	std::getline(std::cin, resp);
	toAdd.setGenre(resp);

	std::cout << "Please enter the description of the media to add:\n";
	std::getline(std::cin, resp);
	toAdd.setDesc(resp);

	return toAdd;
}

std::string MediaDetails::getErrorView()
{
	return this->ErrorView;
}

std::string MediaDetails::getErrorAdd()
{
	return this->ErrorAdd;
}

void MediaDetails::drawDB(std::vector<Media> DB)
{
	system("cls");
	std::cout << "Name                Genre               Description\n";
	for (int i = 0; i < DB.size(); i++)
	{
		std::cout << DB[i].getName() + DB[i].getGenre() + DB[i].getDesc() + "\n";
	}
}