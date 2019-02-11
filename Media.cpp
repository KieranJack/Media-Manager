#include "Media.h"

void Media::setName(std::string name)
{
	this->Name = name;
	while (this->Name.length() < 20)
	{
		this->Name = this->Name + " ";
	}
}

std::string Media::getName()
{
	return this->Name;
}

void Media::setGenre(std::string genre)
{
	this->Genre = genre;
	while (this->Genre.length() < 20)
	{
		this->Genre = this->Genre + " ";
	}
}

std::string Media::getGenre()
{
	return this->Genre;
}

void Media::setDesc(std::string desc)
{
	this->Desc = desc;
}

std::string Media::getDesc()
{
	return this->Desc;
}