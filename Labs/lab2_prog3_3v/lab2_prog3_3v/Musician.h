#pragma once

#include <ctime>
#include <string>

enum class Gender
{
	Man,
	Woman
};

enum class Tool
{
	Keyboarder,
	Stringer
};


class Musician
{
	char* name;
	char* surname;
	Gender gender;
	tm datebirthday;
	Tool tool;
	double rate;

	void splitset(char* str);



public:
	char* getname();
	char* getsurname();
	Gender getgender();
	int getdatebirthday();
	Tool gettool();
	double getrate();
	
	void setname(char* inner_name);
	void setsurname(char* inner_surname);
	void setgender(Gender inner_gender);
	void setdatebirthday(int inner_year);
	void settool(Tool inner_tool);
	void setrate(double inner_rate);

	void print();

	void serialize();
	void serialize(std::string path);

	void deserialize();
	void deserialize(std::string path);

	std::string getstringuniqname();
	char getsplitstr(char* start, int count);


	Musician(char* inner_name, char* inner_surname, Gender inner_gender, int inner_year, Tool inner_tool, double inner_rate);
	Musician();
	~Musician();
};