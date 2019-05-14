#include "pch.h"
#include <iostream>
using namespace std;

class laivai
{
private:
	const static int eil = 10;
	const static int stulp = 10;
	int kord;
	int mLaivai = 0;
	int x, y;
	bool tinka;
	char kryptis;
	char grid[eil][stulp];
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
	void laivu_ivedimas()
	{
		do
		{
			tinka = true;
			if (mLaivai == 0)
			{
				cout << "Iveskite 1 laivo koordinates (2vietos): ";
				cin >> x >> y;
			}
			else if (mLaivai == 1)
			{
				cout << "Iveskite 2 laivo koordinates (3vietos): ";
				cin >> x >> y;
			}
			else if (mLaivai == 2)
			{
				cout << "Iveskite 3 laivo koordinates (4vietos): ";
				cin >> x >> y;
			}
			else if (mLaivai == 3)
			{
				cout << "Iveskite 4 laivo koordiantes (5vietos): ";
				cin >> x >> y;
			}
			ribos();
			if (tinka == true)
			{
				mLaivai++;
			}
		} while (!tinka || mLaivai < 4);
	}
	void ribos()
	{
		if (x < 0 || x > 9 || y < 0 || y > 9)
		{
			tinka = false;
			cout << "Negalima del ribu" << endl;
		}
		else
		{
			laivu_statymas();
		}
	}
	void laivu_statymas()
	{
		if (grid[x][y] == '*')
		{
			if (mLaivai == 0)
			{
				grid[x][y] = 'P';
			}
			else if (mLaivai == 1)
			{
				grid[x][y] = 'S';
			}
			else if (mLaivai == 2)
			{
				grid[x][y] = 'D';
			}
			else if (mLaivai == 3)
			{
				grid[x][y] = 'H';
			}
			hor_ar_vert();
		}
		else
		{
			cout << "Negalima nes vieta uzimta" << endl;
			tinka = false;
		}
	}
	void hor_ar_vert()
	{
		cout << "Spauskite (h) noredami padeti laiva horizontaliai arba (v) noredami padeti vertikaliai: ";
		cin >> kryptis;
		if (kryptis == 'h')
		{
			if (mLaivai == 0 && grid[x][y+1] == '*')
			{
				grid[x][y+1] = 'P';
			}
			else if (mLaivai == 1 && grid[x][y + 1] == '*' && grid[x][y + 2] == '*')
			{
				grid[x][y + 1] = 'S';
				grid[x][y + 2] = 'S';
			}
			else if (mLaivai == 2 && grid[x][y + 1] == '*' && grid[x][y + 2] == '*' && grid[x][y + 3] == '*')
			{
				grid[x][y + 1] = 'D';
				grid[x][y + 2] = 'D';
				grid[x][y + 3] = 'D';
			}
			else if (mLaivai == 3 && grid[x][y + 1] == '*' && grid[x][y + 2] == '*' && grid[x][y + 3] == '*' && grid[x][y + 4] == '*')
			{
				grid[x][y + 1] = 'H';
				grid[x][y + 2] = 'H';
				grid[x][y + 3] = 'H';
				grid[x][y + 4] = 'H';
			}
			else
			{
				cout << "Netelpa nes per mazai horizontalios vietos" << endl;
				grid[x][y] = '*';
				tinka = false;
			}

		}
		if (kryptis == 'v')
		{
			if (mLaivai == 0 && grid[x+1][y] == '*')
			{
				grid[x+1][y] = 'P';
			}
			else if (mLaivai == 1 && grid[x+1][y] == '*' && grid[x+2][y] == '*')
			{
				grid[x + 1][y] = 'S';
				grid[x + 2][y] = 'S';
			}
			else if (mLaivai == 2 && grid[x+1][y] == '*' && grid[x+2][y] == '*' && grid[x+3][y] == '*')
			{
				grid[x + 1][y] = 'D';
				grid[x + 2][y] = 'D';
				grid[x + 3][y] = 'D';
			}
			else if (mLaivai == 3 && grid[x+1][y] == '*' && grid[x+2][y] == '*' && grid[x+3][y] == '*' && grid[x+4][y] == '*')
			{
				grid[x + 1][y] = 'H';
				grid[x + 2][y] = 'H';
				grid[x + 3][y] = 'H';
				grid[x + 4][y] = 'H';
			}
			else
			{
				cout << "Netelpa nes per mazai vertikalios vietos" << endl;
				grid[x][y] = '*';
				tinka = false;
			}
		}
		system("cls");
		pBoard();
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

}

