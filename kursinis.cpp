#include "pch.h"
#include <iostream>
#include<ctime>
using namespace std;

class laivai
{
private:
	const static int eil = 10;
	const static int stulp = 10;
	const static int cpueil = 10;
	const static int cpustulp = 10;
	int cpu_eil;
	int cpu_stulp;
	int p_eil;
	int p_stulp;
	int kord;
	int mLaivai = 0;
	int cpuLaivai = 0;
	int x, y;
	bool tinka;
	bool cpuTinka;
	char kryptis;
	int cpuKryptis;
	char grid[eil][stulp];
	char gridcpu[cpueil][cpustulp];
	char p_l_koord[10];
	char hv[10];
public:
	laivai()
	{
		for (int x = 0; x < eil; x++)
		{
			for (int y = 0; y < stulp; y++)
			{
				grid[x][y] = '*';
			}
		}
		for (int x = 0; x < cpueil; x++)
		{
			for (int y = 0; y < cpustulp; y++)
			{
				gridcpu[x][y] = '*';
			}
		}
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
	void laivu_ivedimas()
	{
		do
		{
			tinka = true;
			if (mLaivai == 0)
			{
				cout << "Iveskite 1 laivo koordinates (2vietos): ";
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
			if (tinka == true)
			{
				mLaivai++;
			}
		} while (mLaivai < 4 || !tinka);
	}
	void ribos()
	{
		if (p_eil < 0 || p_eil >= 10 || p_stulp < 0 || p_stulp >= 10)
		{
			tinka = false;
			pBoard();
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
				grid[p_eil][p_stulp] = 'H';
			}
			hor_ar_vert();
		}
		else 
		{
			grid[p_eil][p_stulp] = '*';
			tinka = false;
		}
	}
	void hor_ar_vert()
	{
		if (mLaivai < 4)
		{
			cout << "Spauskite (h) noredami padeti laiva horizontaliai arba (v) noredami padeti vertikaliai: ";
			cin >> kryptis;
			if (kryptis == 'h')
			{
				if (mLaivai == 0 && grid[p_eil][p_stulp + 1] == '*' && p_eil < 8 && p_stulp < 8)
				{
					grid[p_eil][p_stulp + 1] = 'P';
				}
				else if (mLaivai == 1 && grid[p_eil][p_stulp + 1] == '*' && grid[p_eil][p_stulp + 2] == '*' && p_eil < 8 && p_stulp < 8)
				{
					grid[p_eil][p_stulp + 1] = 'S';
					grid[p_eil][p_stulp + 2] = 'S';
				}
				else if (mLaivai == 2 && grid[p_eil][p_stulp + 1] == '*' && grid[p_eil][p_stulp + 2] == '*' && grid[p_eil][p_stulp + 3] == '*' && p_eil < 8 && p_stulp < 8)
				{
					grid[p_eil][p_stulp + 1] = 'D';
					grid[p_eil][p_stulp + 2] = 'D';
					grid[p_eil][p_stulp + 3] = 'D';
				}
				else if (mLaivai == 3 && grid[p_eil][p_stulp + 1] == '*' && grid[p_eil][p_stulp + 2] == '*' && grid[p_eil][p_stulp + 3] == '*' && grid[p_eil][p_stulp + 4] == '*' && p_eil < 8 && p_stulp < 8)
				{
					grid[p_eil][p_stulp + 1] = 'H';
					grid[p_eil][p_stulp + 2] = 'H';
					grid[p_eil][p_stulp + 3] = 'H';
					grid[p_eil][p_stulp + 4] = 'H';
				}
				else
				{
					grid[p_eil][p_stulp] = '*';
					tinka = false;
				}

			}
			else if (kryptis == 'v')
			{
				if (mLaivai == 0 && grid[p_eil + 1][p_stulp] == '*' && p_eil < 8 && p_stulp < 8)
				{
					grid[p_eil + 1][p_stulp] = 'P';
				}
				else if (mLaivai == 1 && grid[p_eil + 1][p_stulp] == '*' && grid[p_eil + 2][p_stulp] == '*' && p_eil < 8 && p_stulp < 8)
				{
					grid[p_eil + 1][p_stulp] = 'S';
					grid[p_eil + 2][p_stulp] = 'S';
				}
				else if (mLaivai == 2 && grid[p_eil + 1][p_stulp] == '*' && grid[p_eil + 2][p_stulp] == '*' && grid[p_eil + 3][p_stulp] == '*' && p_eil < 8 && p_stulp < 8)
				{
					grid[p_eil + 1][p_stulp] = 'D';
					grid[p_eil + 2][p_stulp] = 'D';
					grid[p_eil + 3][p_stulp] = 'D';
				}
				else if (mLaivai == 3 && grid[p_eil + 1][p_stulp] == '*' && grid[p_eil + 2][p_stulp] == '*' && grid[p_eil + 3][p_stulp] == '*' && grid[p_eil + 4][p_stulp] == '*' && p_eil < 8 && p_stulp < 8)
				{
					grid[p_eil + 1][p_stulp] = 'H';
					grid[p_eil + 2][p_stulp] = 'H';
					grid[p_eil + 3][p_stulp] = 'H';
					grid[p_eil + 4][p_stulp] = 'H';
				}
				else
				{
					grid[p_eil][p_stulp] = '*';
					tinka = false;
				}
			}
			else
			{
				grid[p_eil][p_stulp] = '*';
				tinka = false;
			}
			system("cls");
			pBoard();
		}
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
				gridcpu[cpu_eil][cpu_stulp] = 'H';
			}
			cpu_hort_ar_vert();
		}
		else
		{
			cpuTinka = false;
		}
	}
	void cpu_hort_ar_vert()
	{
		if (cpuLaivai < 4)
		{
			cpuKryptis = 1 + rand() % 2;
			if (cpuKryptis == 1)
			{
				if (cpuLaivai == 0 && gridcpu[cpu_eil][cpu_stulp + 1] == '*' && cpu_eil < 7 && cpu_stulp < 7)
				{
					gridcpu[cpu_eil][cpu_stulp + 1] = 'P';
				}
				else if (cpuLaivai == 1 && gridcpu[cpu_eil][cpu_stulp + 1] == '*' && gridcpu[cpu_eil][cpu_stulp + 2] == '*' && cpu_eil <7 && cpu_stulp < 7)
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
					gridcpu[cpu_eil][cpu_stulp + 1] = 'H';
					gridcpu[cpu_eil][cpu_stulp + 2] = 'H';
					gridcpu[cpu_eil][cpu_stulp + 3] = 'H';
					gridcpu[cpu_eil][cpu_stulp + 4] = 'H';
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
					gridcpu[cpu_eil + 1][cpu_stulp] = 'H';
					gridcpu[cpu_eil + 2][cpu_stulp] = 'H';
					gridcpu[cpu_eil + 3][cpu_stulp] = 'H';
					gridcpu[cpu_eil + 4][cpu_stulp] = 'H';
				}
				else
				{
					gridcpu[cpu_eil][cpu_stulp] = '*';
					cpuTinka = false;
				}
			}
		}
	}
};

int main()
{
	laivai player;
	laivai computer;
	cout << "	Zaidejas" << endl;
	player.pBoard();
	player.laivu_ivedimas();
	player.laivu_statymas();
	player.hor_ar_vert();
	cout << endl;
	computer.cpuBoard();
	computer.cpu_laivai_ivedimas();
	computer.cpu_g_ribos();
	computer.cpu_statymas();
	computer.cpu_hort_ar_vert();
	system("cls");
	cout << "SW NX" << endl;
	player.pBoard();
	cout << endl;
	cout << "	Kompiuteris" << endl;
	computer.cpuBoard();


}

