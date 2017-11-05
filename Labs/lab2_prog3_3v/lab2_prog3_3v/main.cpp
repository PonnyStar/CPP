
#include "Musician.h"
#include <random>
#include <ctime>
#include <stdlib.h>

int main()
{
	Musician music[3];
	music[0].setname("Alex");
	music[0].setsurname("Kolin");
	music[0].setdatebirthday(1987);
	music[0].setgender(Gender::Man);
	music[0].setrate(2);
	music[0].settool(Tool::Stringer);

	music[1].setname("Max");
	music[1].setsurname("Lokorini");
	music[1].setdatebirthday(1981);
	music[1].setgender(Gender::Man);
	music[1].setrate(4);
	music[1].settool(Tool::Keyboarder);

	music[2].setname("Scout");
	music[2].setsurname("Zenger");
	music[2].setdatebirthday(1987);
	music[2].setgender(Gender::Man);
	music[2].setrate(2);
	music[2].settool(Tool::Stringer);

	Musician* newmusic = new Musician("Bob","Singer",Gender::Man,1992,Tool::Keyboarder,2);

	Musician* allmusican[4] = { &music[0], &music[1], &music[2], newmusic };


	srand(time(0));


	//concert
	for (int i = 0; i < 4; i++)
	{
		int crand = rand() % 5 + 1;
		allmusican[i]->setrate(allmusican[i]->getrate() + crand);
	}

	//sort (keyborder : singer) and count Keyboarder

	int cKeyBoarder = 0;

	for (int i = 0; i < 4; i++)
	{
		if (allmusican[i]->gettool() == Tool::Keyboarder)
		{
			std::swap(allmusican[i], allmusican[cKeyBoarder++]);
		}
	}

	//sort all (include Keyboard)
	for (int i = 0; i < 4; i++)
	{
		if (i < cKeyBoarder)
		{
			for (int j = 0; j < cKeyBoarder; j++)
			{
				if (allmusican[i]->getrate() > allmusican[j]->getrate() && i != j)
				{
					std::swap(allmusican[i], allmusican[j]);
				}
			}

		}
		else
		{
			for (int j = cKeyBoarder; j < 4; j++)
			{

				if (allmusican[i]->getrate() > allmusican[j]->getrate() && i != j)
				{
					std::swap(allmusican[i], allmusican[j]);
				}
			}
		}
	}


	for (int i = 0; i < 4; i++)
	{
		allmusican[i]->print();
	}
	system("pause");

	delete newmusic;

	return 0;
}