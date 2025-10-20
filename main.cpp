#include <iostream>
#include "Tclass.h"

typedef struct exclusion_index
{
	std::vector<int16_t> exclusion;

	void add_exclusion(std::int16_t k)
	{
		exclusion.push_back(k);
	}

	void show_exclusion(void) const
	{
		std::cout << "Hey you cant place you input on a taken place !" << std::endl;
		std::cout << "[[";
		for (int i = 0; i < exclusion.size(); i++)
		{
			std::cout << " " << exclusion[i];
		}
		std::cout << "]]" << std::endl;
	}
}t_exclusion_index;            


typedef struct avaliable_pos
{
	std::vector<int16_t> pos;
	void find_and_replace(std::int16_t n)
	{
		for (int i = 0; i < pos.size(); i++)
		{
			if (pos[i] == n)
			{
				pos[i] = -1;
			}
		}
	}
	void show_avaliable_pos(void) const
	{
		std::cout << std::endl;
		std::cout << "if you see -1 this pos is no long avaliable all avaliable pos are here" << std::endl;
		std::cout << "[[";
		for (int i = 0; i < pos.size(); i++)
		{
			std::cout << " " << pos[i];
		}
		std::cout << "]]" << std::endl;
	}
}t_avaliable_pos;


int main()
{
	d dt1;
	avaliable_pos avp1;
	dt1.init_gride();
	dt1.show_gride();

	exclusion_index e;
	e.exclusion = dt1.Exclusion_Index();
	
	int round = dt1.round();


	std::int16_t sk = 0;
	std::int16_t user_round = 0;

	avp1.pos = dt1.avaliable_pos();

	while (true)
	{
		if (dt1.victory_checker() == 1)
		{
			break;
		}
		avp1.show_avaliable_pos();
		if (user_round == 9)
		{
			//start checking;

			break;
		}
		std::int16_t pos = 0;
		if (sk % 2 == 0)
		{
			//player 1; X
			std::cout << "Player 1 : ";
			std::cin >> pos;

			if (dt1.is_avaliable(pos, e.exclusion) != 0)
			{
				avp1.find_and_replace(pos);
				dt1.add_input_user(pos, "X");
				e.add_exclusion(pos);
				sk++;
				user_round++;
			}
			else
			{
				//e.show_exclusion();
			}
		}
		else
		{
			//player 2; O
			std::cout << "Player 2 : ";
			std::cin >> pos;
			std::cout << pos << std::endl;
			
			if (dt1.is_avaliable(pos, e.exclusion) != 0)
			{
				avp1.find_and_replace(pos);
				dt1.add_input_user(pos, "O");
				e.add_exclusion(pos);
				sk++;
				user_round++;
			}
			else
			{
				//e.show_exclusion();
			}
		}
	}

}
