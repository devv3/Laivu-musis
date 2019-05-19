#include "pch.h"
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

class laivai
{
private:
	const static int eil = 10;
	const static int stulp = 10;
	const static int cpueil = 10;
	const static int cpustulp = 10;
	const static int atteil = 10;
	const static int attstulp = 10;
	int cpu_eil;
	string vardas;
	int cpu_stulp;
	int p_eil;
	int ivestis;
	int p_stulp;
	int att_eil;
	int att_stulp;
	int kord;
	int mLaivai = 0;
	int p_LaivuKiekis = 14;
	int cpuLaivai = 0;
	int cpuLaivuKiekis = 14;
	int x, y;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	int p_patrol_size = 2;
	int cpu_patrol_size = 2;
	int p_sub_size = 3;
	int cpu_sub_size = 3;
	int p_dest_size = 4;
	int cpu_dest_size = 4;
	int p_carr_size = 5;
	int cpu_carr_size = 5;
	bool tinka;
	bool cpuTinka;
	bool p_pultiTinka;
	bool cpu_pultiTinka;
	bool patrol_hit = false;
	bool sub_hit = false;
	bool dest_hit = false;
	bool carr_hit = false;
	char kryptis;
	int cpuKryptis;
	int p_puolKoord_x;
	int p_puolKoord_y;
	int cpu_puolKoord_x;
	int cpu_puolKoord_y;
	char grid[eil][stulp];
	char gridcpu[cpueil][cpustulp];
	char gridatt[atteil][attstulp];
	char p_l_koord[10];
	char hv[10];
public:
	laivai()
	{
		for (int x = 0; x < eil; x++) // player boardas
		{
			for (int y = 0; y < stulp; y++)
			{
				grid[x][y] = '*';
			}
		}
		for (int x = 0; x < cpueil; x++) // cpu boardas
		{
			for (int y = 0; y < cpustulp; y++)
			{
				gridcpu[x][y] = '*';
			}
		}
		for (int x = 0; x < atteil; x++) // attack boardas
		{
			for (int y = 0; y < attstulp; y++)
			{
				gridatt[x][y] = '*';
			}
		}
	}
	void menu()
	{
		system("CLS");
		cout << setw(70) << "SVEIKI!";
		cout << endl;
		cout << setw(70) << "IVESKITE SAVO VARDA: ";
		cin >> vardas;
		system("CLS");
		cout << endl;
		cout << setw(70) << "NOREDAMI PRADETI SPAUSKITE 1: " << endl;
		cin >> ivestis;
		if (ivestis == 1)
		{
			system("CLS");
			print_pBoard_AttackBoard();
			laivu_ivedimas();
			cpu_laivai_ivedimas();
			p_puolimas_tikr();
			cpu_laivai_ivedimas();
		}
		else if (ivestis != 1)
		{
			exit;
		}

	}
	void informacija()
	{
		system("CLS");
		cout << setw(25) << vardas << " Laivu gyvybes" << setw(50) << "Kompiuterio " << "Laivu gyvybes" << endl;
		cout << setw(23) << "Patrulis: " << p_patrol_size << setw(48) << "Patrulis: " << cpu_patrol_size << endl;
		cout << setw(23) << "Povandeninis laivas: " << p_sub_size << setw(48) << "Povandeninis laivas: " << cpu_sub_size << endl;
		cout << setw(23) << "Naikintojas: " << p_dest_size << setw(48) << "Naikintojas: " << cpu_dest_size << endl;
		cout << setw(23) << "Lektuvnesis: " << p_carr_size << setw(48) << "Lektuvnesis: " << cpu_carr_size << endl;

	}
	void pBoard()
	{
		int k = 0;
		cout << "  0 1 2 3 4 5 6 7 8 9" << endl; // horizontalus skaiciai
		for (int x = 0; x < eil; x++)
		{
			cout << k << " "; // vertikalus skaiciai
			k++;
			for (int y = 0; y < stulp; y++)
			{
				cout << grid[x][y] << " "; // tarpai
			}
			cout << endl;
		}
	}
	void cpuBoard()
	{
		int k = 0;
		cout << "  0 1 2 3 4 5 6 7 8 9" << endl; // horizontalus skaiciai
		for (int x = 0; x < cpueil; x++)
		{
			cout << k << " "; // vertikalus skaiciai
			k++;
			for (int y = 0; y < cpustulp; y++)
			{
				cout << gridcpu[x][y] << " "; // tarpai
			}
			cout << endl;
		}
	}
	void attackBoard()
	{
		int k = 0;
		cout << "  0 1 2 3 4 5 6 7 8 9" << endl; // horizontalus skaiciai
		for (int x = 0; x < atteil; x++)
		{
			cout << k << " "; // vertikalus skaiciai
			k++;
			for (int y = 0; y < attstulp; y++)
			{
				cout << gridatt[x][y] << " "; // tarpai
			}
			cout << endl;
		}
	}
	void laivu_ivedimas()
	{
		do
		{
			tinka = true;
			if (mLaivai == 0)
			{
				cout  <<"Iveskite 1 laivo koordinates (2vietos): ";
				cin >> p_eil >> p_stulp;
			}
			else if (mLaivai == 1)
			{
				cout << "Iveskite 2 laivo koordinates (3vietos): ";
				cin >> p_eil >> p_stulp;
			}
			else if (mLaivai == 2)
			{
				cout << "Iveskite 3 laivo koordinates (4vietos): ";
				cin >> p_eil >> p_stulp;
			}
			else if (mLaivai == 3)
			{
				cout << "Iveskite 4 laivo koordiantes (5vietos): ";
				cin >> p_eil >> p_stulp;
			}
			ribos();
			print_pBoard_AttackBoard();
			if (tinka == true)
			{
				mLaivai++;
			}
		} while (!tinka || mLaivai < 4);
	}
	void ribos()
	{
		if (p_eil < 0 || p_eil >= 10 || p_stulp < 0 || p_stulp >= 10)
		{
			tinka = false;
			print_pBoard_AttackBoard();
			cout << "Negalima del ribu" << endl;
		}
		else
		{
			laivu_statymas();
		}
	}
	void laivu_statymas()
	{
		if (grid[p_eil][p_stulp] == '*')
		{
			if (mLaivai == 0)
			{
				grid[p_eil][p_stulp] = 'P';
			}
			else if (mLaivai == 1)
			{
				grid[p_eil][p_stulp] = 'S';
			}
			else if (mLaivai == 2)
			{
				grid[p_eil][p_stulp] = 'D';
			}
			else if (mLaivai == 3)
			{
				grid[p_eil][p_stulp] = 'C';
			}
			hor_ar_vert();
		}
		else
		{
			print_pBoard_AttackBoard();
			tinka = false;
		}
	}
	void hor_ar_vert()
	{
		print_pBoard_AttackBoard();
		cout << "Spauskite (h) noredami padeti laiva horizontaliai arba (v) noredami padeti vertikaliai: ";
		cin >> kryptis;
		if (kryptis == 'h')
		{
			if (mLaivai == 0 && grid[p_eil][p_stulp + 1] == '*' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil][p_stulp + 1] = 'P';
			}
			else if (mLaivai == 1 && grid[p_eil][p_stulp + 1] == '*' && grid[p_eil][p_stulp + 2] == '*' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil][p_stulp + 1] = 'S';
				grid[p_eil][p_stulp + 2] = 'S';
			}
			else if (mLaivai == 2 && grid[p_eil][p_stulp + 1] == '*' && grid[p_eil][p_stulp + 2] == '*' && grid[p_eil][p_stulp + 3] == '*' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil][p_stulp + 1] = 'D';
				grid[p_eil][p_stulp + 2] = 'D';
				grid[p_eil][p_stulp + 3] = 'D';
			}
			else if (mLaivai == 3 && grid[p_eil][p_stulp + 1] == '*' && grid[p_eil][p_stulp + 2] == '*' && grid[p_eil][p_stulp + 3] == '*' && grid[p_eil][p_stulp + 4] == '*' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil][p_stulp + 1] = 'C';
				grid[p_eil][p_stulp + 2] = 'C';
				grid[p_eil][p_stulp + 3] = 'C';
				grid[p_eil][p_stulp + 4] = 'C';
				grid[p_eil][p_stulp + 5] = '*';
			}
			else
			{
				print_pBoard_AttackBoard();
				grid[p_eil][p_stulp] = '*';
				tinka = false;
			}

		}
		else if (kryptis == 'v')
		{
			if (mLaivai == 0 && grid[p_eil + 1][p_stulp] == '*' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil + 1][p_stulp] = 'P';
			}
			else if (mLaivai == 1 && grid[p_eil + 1][p_stulp] == '*' && grid[p_eil + 2][p_stulp] == '*' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil + 1][p_stulp] = 'S';
				grid[p_eil + 2][p_stulp] = 'S';
			}
			else if (mLaivai == 2 && grid[p_eil + 1][p_stulp] == '*' && grid[p_eil + 2][p_stulp] == '*' && grid[p_eil + 3][p_stulp] == '*' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil + 1][p_stulp] = 'D';
				grid[p_eil + 2][p_stulp] = 'D';
				grid[p_eil + 3][p_stulp] = 'D';
			}
			else if (mLaivai == 3 && grid[p_eil + 1][p_stulp] == '*' && grid[p_eil + 2][p_stulp] == '*' && grid[p_eil + 3][p_stulp] == '*' && grid[p_eil + 4][p_stulp] == '*' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil + 1][p_stulp] = 'C';
				grid[p_eil + 2][p_stulp] = 'C';
				grid[p_eil + 3][p_stulp] = 'C';
				grid[p_eil + 4][p_stulp] = 'C';
			}
			else
			{
				print_pBoard_AttackBoard();
				grid[p_eil][p_stulp] = '*';
				tinka = false;
			}
		}
		else
		{
			print_pBoard_AttackBoard();
			grid[p_eil][p_stulp] = '*';
			tinka = false;
		}
		system("cls");
	}
	void cpu_laivai_ivedimas()
	{
		do
		{
			cpuTinka = true;
			srand(time(0));
			cpu_eil = rand() % 10;
			cpu_stulp = rand() % 10;
			cpu_g_ribos();
			if (cpuTinka == true)
			{
				cpuLaivai++;
			}
		} while (cpuLaivai < 4 || !cpuTinka);
	}
	void cpu_g_ribos()
	{
		if (cpu_eil < 0 || cpu_eil >= 10 || cpu_stulp < 0 || cpu_stulp >= 10)
		{
			tinka = false;
		}
		else
		{
			cpu_statymas();
		}
	}
	void cpu_statymas()
	{
		if (gridcpu[cpu_eil][cpu_stulp] == '*')
		{
			if (cpuLaivai == 0)
			{
				gridcpu[cpu_eil][cpu_stulp] = 'P';
			}
			else if (cpuLaivai == 1)
			{
				gridcpu[cpu_eil][cpu_stulp] = 'S';
			}
			else if (cpuLaivai == 2)
			{
				gridcpu[cpu_eil][cpu_stulp] = 'D';
			}
			else if (cpuLaivai == 3)
			{
				gridcpu[cpu_eil][cpu_stulp] = 'C';
			}
			cpu_hort_ar_vert();
		}
		else
		{
			cpuTinka = false;
		}
	}
	void cpu_ribos()
	{
		start_x = gridcpu[cpu_eil - 1][cpu_stulp];
		start_y = gridcpu[cpu_eil][cpu_stulp - 1];
		end_x = gridcpu[cpu_eil + cpuLaivai][cpu_stulp];
		end_y = gridcpu[cpu_eil][cpu_stulp + 1];
		for (int i = start_y; i <= end_y; i++)
		{
			for (int j = start_x; j <= end_x; i++)
			{
				if (gridcpu[cpu_eil][cpu_stulp] != '*')
				{
					cpuTinka = false;
				}
			}
		}
	}
	void cpu_hort_ar_vert()
	{
		//cpu_ribos();
		cpuKryptis = 1 + rand() % 2;
		if (cpuKryptis == 1)
		{
			if (cpuLaivai == 0 && gridcpu[cpu_eil][cpu_stulp + 1] == '*' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil][cpu_stulp + 1] = 'P';
			}
			else if (cpuLaivai == 1 && gridcpu[cpu_eil][cpu_stulp + 1] == '*' && gridcpu[cpu_eil][cpu_stulp + 2] == '*' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil][cpu_stulp + 1] = 'S';
				gridcpu[cpu_eil][cpu_stulp + 2] = 'S';
			}
			else if (cpuLaivai == 2 && gridcpu[cpu_eil][cpu_stulp + 1] == '*' && gridcpu[cpu_eil][cpu_stulp + 2] == '*' && gridcpu[cpu_eil][cpu_stulp + 3] == '*'&& cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil][cpu_stulp + 1] = 'D';
				gridcpu[cpu_eil][cpu_stulp + 2] = 'D';
				gridcpu[cpu_eil][cpu_stulp + 3] = 'D';
			}
			else if (cpuLaivai == 3 && gridcpu[cpu_eil][cpu_stulp + 1] == '*' && gridcpu[cpu_eil][cpu_stulp + 2] == '*' && gridcpu[cpu_eil][cpu_stulp + 3] == '*' && gridcpu[cpu_eil][cpu_stulp + 4] == '*'&& cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil][cpu_stulp + 1] = 'C';
				gridcpu[cpu_eil][cpu_stulp + 2] = 'C';
				gridcpu[cpu_eil][cpu_stulp + 3] = 'C';
				gridcpu[cpu_eil][cpu_stulp + 4] = 'C';
			}
			else
			{
				gridcpu[cpu_eil][cpu_stulp] = '*';
				cpuTinka = false;
			}
		}
		else if (cpuKryptis == 2)
		{
			if (cpuLaivai == 0 && gridcpu[cpu_eil + 1][cpu_stulp] == '*' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil + 1][cpu_stulp] = 'P';
			}
			else if (cpuLaivai == 1 && gridcpu[cpu_eil + 1][cpu_stulp] == '*' && gridcpu[cpu_eil + 2][cpu_stulp] == '*' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil + 1][cpu_stulp] = 'S';
				gridcpu[cpu_eil + 2][cpu_stulp] = 'S';
			}
			else if (cpuLaivai == 2 && gridcpu[cpu_eil + 1][cpu_stulp] == '*' && gridcpu[cpu_eil + 2][cpu_stulp] == '*' && gridcpu[cpu_eil + 3][cpu_stulp] == '*' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil + 1][cpu_stulp] = 'D';
				gridcpu[cpu_eil + 2][cpu_stulp] = 'D';
				gridcpu[cpu_eil + 3][cpu_stulp] = 'D';
			}
			else if (cpuLaivai == 3 && gridcpu[cpu_eil + 1][cpu_stulp] == '*' && gridcpu[cpu_eil + 2][cpu_stulp] == '*' && gridcpu[cpu_eil + 3][cpu_stulp] == '*' && gridcpu[cpu_eil + 4][cpu_stulp] == '*' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil + 1][cpu_stulp] = 'C';
				gridcpu[cpu_eil + 2][cpu_stulp] = 'C';
				gridcpu[cpu_eil + 3][cpu_stulp] = 'C';
				gridcpu[cpu_eil + 4][cpu_stulp] = 'C';
			}
			else
			{
				gridcpu[cpu_eil][cpu_stulp] = '*';
				cpuTinka = false;
			}
		}
	}
	void print_pBoard_AttackBoard()
	{
		informacija();
		cout << setw(15) << vardas << endl;;
		pBoard();
		cout << setw(15) << "Kompiuteris" << endl;
		attackBoard();
	}
	void p_puolimas_tikr()
	{
		do
		{
			p_pultiTinka = true;
			print_pBoard_AttackBoard();
			cout << "Iveskite puolimo koordinates: ";
			cin >> p_puolKoord_x >> p_puolKoord_y;
			p_puolKoord_ribos();
			if (cpuLaivuKiekis == 0)
			{
				system("CLS");
				cout << setw(82) << "EZ";
				cout << setw(82) << "EZ";
				cout << setw(82) << "EZ";
				cout << setw(82) << "EZ";
				cout << setw(82) << "EZ";
				cout << setw(82) << "EZ";
			}
			else if (p_pultiTinka = true)
			{
				print_pBoard_AttackBoard();
				cpu_puolimas_tikr();
			}
		} while (!p_pultiTinka || cpuLaivuKiekis > 0);
	}
	void p_puolKoord_ribos()
	{
		if (p_puolKoord_x < 0 || p_puolKoord_x >= 10 || p_puolKoord_y < 0 || p_puolKoord_y >= 10)
		{
			p_pultiTinka = false;
			system("CLS");
			print_pBoard_AttackBoard();
			cout << setw(82) << "Negalima del ribu" << endl;
		}
		else
		{
			p_puol_attack();
		}
	}
	void p_puol_attack()
	{
		if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'X' || gridcpu[p_puolKoord_x][p_puolKoord_y] == '#')
		{
			print_pBoard_AttackBoard();
			cout << setw(82) << "Jus jau atakavote sia vieta!" << endl;
			p_pultiTinka = false;
		}
		else if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'P')
		{
			print_pBoard_AttackBoard();
			cout << setw(82) << "Jus pataikete i Patruli" << endl;
			gridcpu[p_puolKoord_x][p_puolKoord_y] = 'X';
			cpu_patrol_size--;
			cpuLaivuKiekis--;
		}
		else if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'S')
		{
			print_pBoard_AttackBoard();
			cout << setw(82) << "Jus pataikete i Povandenini Laiva!" << endl;
			gridatt[p_puolKoord_x][p_puolKoord_y] = 'X';
			cpu_sub_size--;
			cpuLaivuKiekis--;
		}
		else if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'D')
		{
			print_pBoard_AttackBoard();
			cout << setw(82) << "Jus pataikete i Naikintoja!" << endl;
			gridatt[p_puolKoord_x][p_puolKoord_y] = 'X';
			cpu_dest_size--;
			cpuLaivuKiekis--;
		}
		else if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'C')
		{
			print_pBoard_AttackBoard();
			cout << setw(82) << "Jus pataikete i Lektuvnesi!" << endl;
			gridatt[p_puolKoord_x][p_puolKoord_y] = 'X';
			cpu_carr_size--;
			cpuLaivuKiekis--;
		}
		else
		{
			print_pBoard_AttackBoard();
			cout << setw(82) << "Nepataikete!" << endl;
			gridatt[p_puolKoord_x][p_puolKoord_y] = '#';
		}
	}
	void cpu_puolimas_tikr()
	{
		do
		{
			cpu_pultiTinka = true;
			cpu_puolKoord_x = rand() % 10;
			cpu_puolKoord_y = rand() % 10;
			if (patrol_hit == true)
			{
				if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'P')
				{
					cpu_puolimas();
				}
				else
				{
					cpu_pultiTinka = false;
				}
			}
			else if (sub_hit == true)
			{
				if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'S')
				{
					cpu_puolimas();
				}
				else
				{
					cpu_pultiTinka = false;
				}
			}
			else if (dest_hit == true)
			{
				if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'D')
				{
					cpu_puolimas();
				}
				else
				{
					cpu_pultiTinka = false;
				}
			}
			else if (carr_hit == true)
			{
				if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'C')
				{
					cpu_puolimas();
				}
				else
				{
					cpu_pultiTinka = false;
				}
			}
			if (patrol_hit == false && sub_hit == false && dest_hit == false && carr_hit == false)
			{
				cpu_puolimas();
			}
		} while (!cpu_pultiTinka || p_LaivuKiekis > 0);
	}
	void cpu_puolimas()
	{
		if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'P')
		{
			cout << setw(82) << "Kompiuteris pataike i jusu Patruli";
			patrol_hit = true;
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'X';
			p_patrol_size--;
			p_LaivuKiekis--;
		}
		else if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'S')
		{
			cout << setw(82) << "Kompiuteris pataike i jusu Povandenini lava";
			sub_hit = true;
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'X';
			p_sub_size--;
			p_LaivuKiekis--;
		}
		else if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'D')
		{
			cout << setw(82) << "Kompiuteris pataike i jusu Naikintoja";
			dest_hit = true;
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'X';
			p_dest_size--;
			p_LaivuKiekis--;
		}
		else if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'C')
		{
			cout << setw(82) << "Kompiuteris pataike i jusu Lektuvnesi";
			carr_hit = true;
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'X';
			p_carr_size--;
			p_LaivuKiekis--;
		}
		else
		{
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = '#';
			cpu_pultiTinka = false;
		}
		c_h();
		if (p_LaivuKiekis == 0)
		{
			system("CLS");
			cout << setw(82) << "Prapisai";
			cout << setw(82) << "Prapisai";
			cout << setw(82) << "Prapisai";
			cout << setw(82) << "Prapisai";
			cout << setw(82) << "Prapisai";

		}
		else if (cpu_pultiTinka = true)
		{
			p_puolimas_tikr();
		}
	}
	void c_h()
	{
		if (p_patrol_size == 0)
		{
			grid[p_eil][p_stulp] = 'R';
			grid[p_eil][p_stulp+1] = 'R';
			patrol_hit = false;
		}
		if (p_carr_size == 0)
		{
			carr_hit = false;
		}
		if (p_dest_size == 0)
		{
			dest_hit = false;
		}
		if (p_sub_size == 0)
		{
			sub_hit = false;
		}
	}
};

int main()
{
	laivai g;
	g.menu();
}
