#pragma once
#include <iostream>
#include <vector>
class d {
private:
	std::string gride;
public:
	
	void init_gride()
	{
		std::cout << "Gride init" << std::endl;
		gride = " . | . | . ----------  . | . | . ----------   . | . | .";
	}
	void show_gride(void) const
	{
		for (int i = 0; i < gride.size(); i++)
		{
			if (i == 11 || i == 22 || i == 33 || i == 45)
			{
				std::cout << std::endl;
			}
			std::cout << gride[i];
		}
		std::cout << std::endl;
	}

	std::vector<int16_t> Exclusion_Index(void)
	{
		std::vector<int16_t> pos;
		pos.resize(1);
		std::int16_t p = 0;
		for (int i = 0; i < gride.size(); i++)
		{
			if (gride[i] != '.')
			{
				pos[p] = i;
				p++;
				pos.resize(p + 1);
			}
		}
		return (pos);
	}

	int round(void)
	{
		int round = 0;
		for (int i = 0; i < gride.size(); i++)
		{
			if (gride[i] == '.')
			{
				round++;
			}
		}
		return (round);
	}

	std::vector<int16_t> avaliable_pos(void)
	{
		std::vector<int16_t> pos;
		for (int i = 0; i < gride.size(); i++)
		{
			if (gride[i] == '.')
			{
				pos.push_back(i);
			}
		}
		return (pos);
	}

	int is_avaliable(std::int16_t a, std::vector<int16_t> input_pos)
	{
		for (int u = 0; u < input_pos.size(); u++)
		{
			if (input_pos[u] == a || a == 0)
			{
				return (0);
			}
		}
		return (1);
	}
	void add_input_user(std::int16_t p, std::string XO)
	{

		gride[p] = XO[0];

		show_gride();
		std::cout << std::endl;
	}

	std::int16_t victory_checker(void)
	{
		std::string cc = "XO";
		std::int16_t p = 0;
		while (p <= 1)
		{
			
			if (gride[1] == cc[p] && gride[5] == cc[p] && gride[9] == cc[p]) {std::cout << "Player " << cc[p] << "Win !" << std::endl;return 1;}
			if (gride[23] == cc[p] && gride[27] == cc[p] && gride[31] == cc[p]){std::cout << "Player " << cc[p] << "Win !" << std::endl;return 1;}
			if (gride[46] == cc[p] && gride[50] == cc[p] && gride[54] == cc[p]){std::cout << "Player " << cc[p] << "Win !" << std::endl;return 1;}

			if (gride[1] == cc[p] && gride[23] == cc[p] && gride[46] == cc[p]){std::cout << "Player " << cc[p] << "Win !" << std::endl;return 1;}
			if (gride[5] == cc[p] && gride[27] == cc[p] && gride[50] == cc[p]){std::cout << "Player " << cc[p] << "Win !" << std::endl;return 1;}
			if (gride[9] == cc[p] && gride[31] == cc[p] && gride[54] == cc[p]){std::cout << "Player " << cc[p] << "Win !" << std::endl;return 1;}

			if (gride[1] == cc[p] && gride[27] == cc[p] && gride[54] == cc[p]){std::cout << "Player " << cc[p] << "Win !" << std::endl;return 1;}
			if (gride[9] == cc[p] && gride[27] == cc[p] && gride[46] == cc[p]){std::cout << "Player " << cc[p] << "Win !" << std::endl;return 1;}
			p++;
		}
		return (0);
	}
};
