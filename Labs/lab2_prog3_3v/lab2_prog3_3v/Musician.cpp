#include "Musician.h"

#include <iostream>
#include <fstream>
#include <sstream>

Musician::Musician(char* inner_name, char* inner_surname, Gender inner_gender, int inner_year, Tool inner_tool, double inner_rate)
{
	gender = inner_gender;
	name = inner_name;
	surname = inner_surname;
	datebirthday.tm_year = inner_year;
	tool = inner_tool;
	rate = inner_rate;

}
Musician::Musician() { }
Musician::~Musician() { }

char* Musician::getname()
{
	return name;
}
char* Musician::getsurname()
{
	return surname;
}
Gender Musician::getgender()
{
	return gender;
}

int Musician::getdatebirthday()
{
	return datebirthday.tm_year;
}
Tool Musician::gettool()
{
	return tool;
}
double Musician::getrate()
{
	return rate;
}

void Musician::setname(char* inner_name)
{
	name = inner_name;
}
void Musician::setsurname(char* inner_surname)
{
	surname = inner_surname;
}
void Musician::setgender(Gender inner_gender)
{
	gender = inner_gender;
}
void Musician::setdatebirthday(int inner_year)
{
	datebirthday.tm_year = inner_year;
}
void Musician::settool(Tool inner_tool)
{
	tool = inner_tool;
}
void Musician::setrate(double inner_rate)
{
	rate = inner_rate;
}

void Musician::print()
{
	std::cout << getname() << " " << getsurname() << " " << getdatebirthday() << " " << ((int)getgender() ? "W" : "M") << " " << ((int)gettool() ? "S" : "K") << " " << getrate() << std::endl;
}
std::string Musician::getstringuniqname()
{
	std::ostringstream ss;
	ss << getname() << getsurname();
	return ss.str();
}

void Musician::serialize()
{
	std::string path = "data" + getstringuniqname() + ".txt";
	std::ofstream fout(path, std::ios_base::trunc);
	fout << name << ";" << surname << ";" << (int)gender << ";"
		<< (int)tool << ";" << rate << std::endl;
	fout.close();
}

void Musician::serialize(std::string path)
{
	std::ofstream fout(path, std::ios_base::out, std::ios_base::trunc);
	fout << name << ";" << surname << ";" << (int)gender << ";"
		<< (int)tool << ";" << rate << std::endl;
	fout.close();
}

void Musician::deserialize()
{
	std::string path = "data" + getstringuniqname() + ".txt";
	std::ifstream fin(path, std::ios_base::in);
	char s[255];
	fin.getline(s, 255);
	splitset(s);
}

void Musician::deserialize(std::string path)
{
	std::ifstream fin(path, std::ios_base::in);
	char s[255];
	fin.getline(s, 255);
	splitset(s);
}

void Musician::splitset(char* str)
{
	char splitchar = ';';
	char* pointStart = str;
	char* pointNow = str;
	char* pointEnd = str;
	int countMark = 0;

	for (int i = 0; i < 255; i++)
	{
		if (*(pointEnd++) == splitchar)
		{
			switch (countMark++)
			{
			case 0:
				setname((char*)getsplitstr(pointNow, (pointEnd - pointNow)));
				break;
			case 1:
				setsurname((char*)(getsplitstr(pointNow, (pointEnd - pointNow))));
				break;
			case 2:
				setgender((Gender)(int)getsplitstr(pointNow, (pointEnd - pointNow)));
				break;
			case 3:
				settool((Tool)(int)getsplitstr(pointNow, (pointEnd - pointNow)));
				break;
			case 4:
				setrate((int)getsplitstr(pointNow, (pointEnd - pointNow)));
				break;
			default:
				break;
			}
			pointNow = pointEnd;
		}
	}
}

char Musician::getsplitstr(char* start, int count)
{
	char return_tmp[255];
	for (int i = 0; i < count; i++)
	{
		return_tmp[i] = *(start + i);
	}
	return_tmp[count - 1] = '\0';
	return *return_tmp;
}



