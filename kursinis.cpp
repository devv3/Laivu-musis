#include "pch.h"
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<string>
#include<ctime>
#include<cstdlib>
#include <thread>
#include <chrono>
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
	int cpu_stulp;
	int p_eil;
	int ivestis;
	int p_stulp;
	int att_eil;
	int att_stulp;
	int kord;
	int mLaivai = 0;
	int p_LaivuKiekis = 18;
	int cpuLaivai = 0;
	int cpuLaivuKiekis = 18;
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
	int p_crei_size = 4;
	int cpu_crei_size = 4;
	int cpu_patrol_done;
	int cpu_sub_done;
	int cpu_carr_done;
	int cpu_dest_done;
	int cpu_crei_done;
	int p_patrol_done;
	int p_sub_done;
	int p_carr_done;
	int p_dest_done;
	int p_crei_done;
	int cpuKryptis;
	int p_puolKoord_x;
	int p_puolKoord_y;
	int cpu_puolKoord_x;
	int cpu_puolKoord_y;
	bool game_on = false;
	bool zpabaiga;
	bool tinka;
	bool cpuTinka;
	bool p_pultiTinka;
	bool cpu_pultiTinka;
	bool patrol_hit = false;
	bool sub_hit = false;
	bool dest_hit = false;
	bool carr_hit = false;
	bool crei_hit = false;
	char kryptis;
	char grid[eil][stulp];
	char gridcpu[cpueil][cpustulp];
	char gridatt[atteil][attstulp];
	char p_l_koord[10];
	char hv[10];
	string vardas;
public:
	laivai()
	{
		for (int x = 0; x < eil; x++) // player boardas
		{
			for (int y = 0; y < stulp; y++)
			{
				grid[x][y] = '-';
			}
		}
		for (int x = 0; x < cpueil; x++) // cpu boardas
		{
			for (int y = 0; y < cpustulp; y++)
			{
				gridcpu[x][y] = '-';
			}
		}
		for (int x = 0; x < atteil; x++) // attack boardas
		{
			for (int y = 0; y < attstulp; y++)
			{
				gridatt[x][y] = '-';
			}
		}
	}
	void menu() // meniu funkcija kuri leidzia ivesti savo varda ir pradeti zaidima
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
			game_on = true;
			system("CLS");
			print_pBoard_AttackBoard();
			laivu_ivedimas();
			cpu_laivai_ivedimas();
			p_puolimas_tikr();
			cpu_laivai_ivedimas();
			zaidimo_pabaiga();
		}
		else if (ivestis != 1)
		{
			exit;
		}

	}
	void informacija() // informacijos funkcija kuri parodo kiek kiekvienas laivas turi likusiu "gyvybiu" tiek kompiuteriui tiek zaidejui
	{
		system("CLS");
		cout << setw(25) << vardas << " Laivu gyvybes" << setw(50) << "Kompiuterio " << "Laivu gyvybes" << endl;
		cout << setw(23) << "Patrulis: " << p_patrol_size << setw(48) << "Patrulis: " << cpu_patrol_size << endl;
		cout << setw(23) << "Povandeninis laivas: " << p_sub_size << setw(48) << "Povandeninis laivas: " << cpu_sub_size << endl;
		cout << setw(23) << "Zvalgas: " << p_dest_size << setw(48) << "Zvalgas: " << cpu_dest_size << endl;
		cout << setw(23) << "Kreiseris:" << p_crei_size << setw(48) << "Kreiseris: " << cpu_crei_size << endl;
		cout << setw(23) << "Lektuvnesis: " << p_carr_size << setw(48) << "Lektuvnesis: " << cpu_carr_size << endl;
		cout << setw(23) << "Laivu gyvybes: " << p_LaivuKiekis << setw(48) << "Laivu gyvybes: " << cpuLaivuKiekis << endl;
	}
	void pBoard() // zaidejo boardas
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
	void cpuBoard() // kompiuterio boardas
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
	void attackBoard() // atakavimo boardas
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
	void laivu_ivedimas() // laivu deliojimas zaidejui
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
				cout << "Iveskite 4 laivo koordinates(4 vietos): ";
				cin >> p_eil >> p_stulp;
			}
			else if (mLaivai == 4)
			{
				cout << "Iveskite 5 laivo koordiantes (5vietos): ";
				cin >> p_eil >> p_stulp;
			}
			ribos();
			print_pBoard_AttackBoard();
			if (tinka == true)
			{
				mLaivai++;
			}
		} while (!tinka || mLaivai < 5);
	}
	void ribos() // tikrinimas jog laivas nebutu padetas uz grido
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
	void laivu_statymas() // laivu statymas ir tikrinimas ar ta  vieta laisva bei kvietimas funkcijos kuri leidzia pasirinkti horizontaliai ar vertikaliai noriu statyti laiva
	{
		if (grid[p_eil][p_stulp] == '-')
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
				grid[p_eil][p_stulp] = 'K';
			}
			else if (mLaivai == 4)
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
	void hor_ar_vert() // funkcija leidzianti pasirinkti ar horizontaliai ar vertikaliai noriu statyti savo laiva, tikrinima jog laivas butu grido ribose
	{
		print_pBoard_AttackBoard();
		cout << "Spauskite (h) noredami padeti laiva horizontaliai arba (v) noredami padeti vertikaliai: ";
		cin >> kryptis;
		if (kryptis == 'h') // pasirinkus horizontalia krypti
		{
			if (mLaivai == 0 && grid[p_eil][p_stulp + 1] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil][p_stulp + 1] = 'P';
			}
			else if (mLaivai == 1 && grid[p_eil][p_stulp + 1] == '-' && grid[p_eil][p_stulp + 2] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil][p_stulp + 1] = 'S';
				grid[p_eil][p_stulp + 2] = 'S';
			}
			else if (mLaivai == 2 && grid[p_eil][p_stulp + 1] == '-' && grid[p_eil][p_stulp + 2] == '-' && grid[p_eil][p_stulp + 3] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil][p_stulp + 1] = 'D';
				grid[p_eil][p_stulp + 2] = 'D';
				grid[p_eil][p_stulp + 3] = 'D';
			}
			else if (mLaivai == 3 && grid[p_eil][p_stulp + 1] == '-' && grid[p_eil][p_stulp + 2] == '-' && grid[p_eil][p_stulp + 3] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil][p_stulp + 1] = 'K';
				grid[p_eil][p_stulp + 2] = 'K';
				grid[p_eil][p_stulp + 3] = 'K';
			}
			else if (mLaivai == 4 && grid[p_eil][p_stulp + 1] == '-' && grid[p_eil][p_stulp + 2] == '-' && grid[p_eil][p_stulp + 3] == '-' && grid[p_eil][p_stulp + 4] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil][p_stulp + 1] = 'C';
				grid[p_eil][p_stulp + 2] = 'C';
				grid[p_eil][p_stulp + 3] = 'C';
				grid[p_eil][p_stulp + 4] = 'C';

			}
			else
			{
				print_pBoard_AttackBoard();
				grid[p_eil][p_stulp] = '-';
				tinka = false;
			}

		}
		else if (kryptis == 'v') // pasirinkus vertikalia krypti
		{
			if (mLaivai == 0 && grid[p_eil + 1][p_stulp] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil + 1][p_stulp] = 'P';
			}
			else if (mLaivai == 1 && grid[p_eil + 1][p_stulp] == '-' && grid[p_eil + 2][p_stulp] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil + 1][p_stulp] = 'S';
				grid[p_eil + 2][p_stulp] = 'S';
			}
			else if (mLaivai == 2 && grid[p_eil + 1][p_stulp] == '-' && grid[p_eil + 2][p_stulp] == '-' && grid[p_eil + 3][p_stulp] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil + 1][p_stulp] = 'D';
				grid[p_eil + 2][p_stulp] = 'D';
				grid[p_eil + 3][p_stulp] = 'D';
			}
			else if (mLaivai == 3 && grid[p_eil][p_stulp + 1] == '-' && grid[p_eil+2][p_stulp] == '-' && grid[p_eil+3][p_stulp] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil+1][p_stulp] = 'K';
				grid[p_eil+2][p_stulp] = 'K';
				grid[p_eil+3][p_stulp] = 'K';
			}
			else if (mLaivai == 4 && grid[p_eil + 1][p_stulp] == '-' && grid[p_eil + 2][p_stulp] == '-' && grid[p_eil + 3][p_stulp] == '-' && grid[p_eil + 4][p_stulp] == '-' && p_eil < 9 && p_stulp < 9)
			{
				grid[p_eil + 1][p_stulp] = 'C';
				grid[p_eil + 2][p_stulp] = 'C';
				grid[p_eil + 3][p_stulp] = 'C';
				grid[p_eil + 4][p_stulp] = 'C';
			}
			else
			{
				print_pBoard_AttackBoard();
				grid[p_eil][p_stulp] = '-';
				tinka = false;
			}
		}
		else
		{
			print_pBoard_AttackBoard();
			grid[p_eil][p_stulp] = '-';
			tinka = false;
		}
		system("cls");
	}
	void cpu_laivai_ivedimas() // gaunamos reiksmes norint ivesti kompiuterio laivus random padetimis
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
		} while (cpuLaivai < 5 || !cpuTinka);
	}
	void cpu_g_ribos() // tikrinama jog pasirinkti skaiciai butu ribose
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
	void cpu_statymas() // cpu laivu statymas bei tikrinimas jog nebutu statoma vienas ant kito
	{
		if (gridcpu[cpu_eil][cpu_stulp] == '-')
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
				gridcpu[cpu_eil][cpu_stulp] = 'K';
			}
			else if (cpuLaivai == 4)
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
	void cpu_hort_ar_vert() // funkcija kuri parenka laivu krypti su rand() 1 is 2 variantu ir juos pastato atitinkamai koks yra laivo ilgis
	{
		//cpu_ribos();
		cpuKryptis = 1 + rand() % 2;
		if (cpuKryptis == 1)
		{
			if (cpuLaivai == 0 && gridcpu[cpu_eil][cpu_stulp + 1] == '-' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil][cpu_stulp + 1] = 'P';
			}
			else if (cpuLaivai == 1 && gridcpu[cpu_eil][cpu_stulp + 1] == '-' && gridcpu[cpu_eil][cpu_stulp + 2] == '-' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil][cpu_stulp + 1] = 'S';
				gridcpu[cpu_eil][cpu_stulp + 2] = 'S';
			}
			else if (cpuLaivai == 2 && gridcpu[cpu_eil][cpu_stulp + 1] == '-' && gridcpu[cpu_eil][cpu_stulp + 2] == '-' && gridcpu[cpu_eil][cpu_stulp + 3] == '-'&& cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil][cpu_stulp + 1] = 'D';
				gridcpu[cpu_eil][cpu_stulp + 2] = 'D';
				gridcpu[cpu_eil][cpu_stulp + 3] = 'D';
			}
			else if (cpuLaivai == 3 && gridcpu[cpu_eil][cpu_stulp + 1] == '-' && gridcpu[cpu_eil][cpu_stulp + 2] == '-' && gridcpu[cpu_eil][cpu_stulp + 3] == '-'&& cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil][cpu_stulp + 1] = 'K';
				gridcpu[cpu_eil][cpu_stulp + 2] = 'K';
				gridcpu[cpu_eil][cpu_stulp + 3] = 'K';
			}
			else if (cpuLaivai == 4 && gridcpu[cpu_eil][cpu_stulp + 1] == '-' && gridcpu[cpu_eil][cpu_stulp + 2] == '-' && gridcpu[cpu_eil][cpu_stulp + 3] == '-' && gridcpu[cpu_eil][cpu_stulp + 4] == '-'&& cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil][cpu_stulp + 1] = 'C';
				gridcpu[cpu_eil][cpu_stulp + 2] = 'C';
				gridcpu[cpu_eil][cpu_stulp + 3] = 'C';
				gridcpu[cpu_eil][cpu_stulp + 4] = 'C';
			}
			else
			{
				gridcpu[cpu_eil][cpu_stulp] = '-';
				cpuTinka = false;
			}
		}
		else if (cpuKryptis == 2)
		{
			if (cpuLaivai == 0 && gridcpu[cpu_eil + 1][cpu_stulp] == '-' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil + 1][cpu_stulp] = 'P';
			}
			else if (cpuLaivai == 1 && gridcpu[cpu_eil + 1][cpu_stulp] == '-' && gridcpu[cpu_eil + 2][cpu_stulp] == '-' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil + 1][cpu_stulp] = 'S';
				gridcpu[cpu_eil + 2][cpu_stulp] = 'S';
			}
			else if (cpuLaivai == 2 && gridcpu[cpu_eil + 1][cpu_stulp] == '-' && gridcpu[cpu_eil + 2][cpu_stulp] == '-' && gridcpu[cpu_eil + 3][cpu_stulp] == '-' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil + 1][cpu_stulp] = 'D';
				gridcpu[cpu_eil + 2][cpu_stulp] = 'D';
				gridcpu[cpu_eil + 3][cpu_stulp] = 'D';
			}
			else if (cpuLaivai == 3 && gridcpu[cpu_eil + 1][cpu_stulp] == '-' && gridcpu[cpu_eil + 2][cpu_stulp] == '-' && gridcpu[cpu_eil + 3][cpu_stulp] == '-' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil + 1][cpu_stulp] = 'K';
				gridcpu[cpu_eil + 2][cpu_stulp] = 'K';
				gridcpu[cpu_eil + 3][cpu_stulp] = 'K';
			}
			else if (cpuLaivai == 4 && gridcpu[cpu_eil + 1][cpu_stulp] == '-' && gridcpu[cpu_eil + 2][cpu_stulp] == '-' && gridcpu[cpu_eil + 3][cpu_stulp] == '-' && gridcpu[cpu_eil + 4][cpu_stulp] == '-' && cpu_eil < 7 && cpu_stulp < 7)
			{
				gridcpu[cpu_eil + 1][cpu_stulp] = 'C';
				gridcpu[cpu_eil + 2][cpu_stulp] = 'C';
				gridcpu[cpu_eil + 3][cpu_stulp] = 'C';
				gridcpu[cpu_eil + 4][cpu_stulp] = 'C';
			}
			else
			{
				gridcpu[cpu_eil][cpu_stulp] = '-';
				cpuTinka = false;
			}
		}
		cpuBoard();
	}
	void print_pBoard_AttackBoard() // atspauzdinama informacija, zaidejo, bei atakos lenteles
	{
		informacija();
		cout << setw(15) << vardas << endl;;
		pBoard();
		cout << setw(15) << "Kompiuteris" << endl;
		attackBoard();
		zaidimo_pabaiga();
	}
	void p_puolimas_tikr() // tikrinama ar gali zaidejas pulti bei paprastoma ivesti koordinates, galima pulti tol kol kompiuterio laivu kiekis yra didesnis uz nuli
	{
		do
		{
			p_pultiTinka = true;
			print_pBoard_AttackBoard();
			cout << "Iveskite puolimo koordinates: ";
			cin >> p_puolKoord_x >> p_puolKoord_y;
			p_puolKoord_ribos();
			if (cpuLaivuKiekis <= 0)
			{
				system("CLS");
				zaidimo_pabaiga();
			}
			else if (p_pultiTinka = true)
			{
				print_pBoard_AttackBoard();
				cpu_puolimas_tikr();
			}
		} while (!p_pultiTinka || cpuLaivuKiekis > 0);
	}
	void p_puolKoord_ribos() // tikrinama jog ivestos reikmes butu grido ribose
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
	void p_puol_attack() // puolimo funkcija, jeigu pataikoma i vieta kurioje yra vienas is laivu,  isvedamas pranesimas, atnaujinamas boardas, padedamas X simbolis bei sumazinami visi kompiuterio laivai, bei laivas i kuri buvo pataikyta
	{
		if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'X' || gridcpu[p_puolKoord_x][p_puolKoord_y] == 'O')
		{
			cout << setw(82) << "Jus jau atakavote sia vieta!" << endl;
			Sleep(1000);
			print_pBoard_AttackBoard();
			p_pultiTinka = false;
		}
		else if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'P')
		{
			cout << setw(82) << "Jus pataikete i Patruli" << endl;
			Sleep(1000);
			print_pBoard_AttackBoard();
			gridatt[p_puolKoord_x][p_puolKoord_y] = 'X';
			cpu_patrol_size--;
			cpuLaivuKiekis--;
		}
		else if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'S')
		{
			cout << setw(82) << "Jus pataikete i Povandenini Laiva!" << endl;
			Sleep(1000);
			print_pBoard_AttackBoard();
			gridatt[p_puolKoord_x][p_puolKoord_y] = 'X';
			cpu_sub_size--;
			cpuLaivuKiekis--;
		}
		else if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'D')
		{
			cout << setw(82) << "Jus pataikete i zvalga!" << endl;
			Sleep(1000);
			print_pBoard_AttackBoard();
			gridatt[p_puolKoord_x][p_puolKoord_y] = 'X';
			cpu_dest_size--;
			cpuLaivuKiekis--;
		}
		else if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'K')
		{
		cout << setw(82) << "Jus pataikete i Kreiseri!" << endl;
		Sleep(1000);
		print_pBoard_AttackBoard();
		gridatt[p_puolKoord_x][p_puolKoord_y] = 'X';
		cpu_crei_size--;
		cpuLaivuKiekis--;
		}
		else if (gridcpu[p_puolKoord_x][p_puolKoord_y] == 'C')
		{
			cout << setw(82) << "Jus pataikete i Lektuvnesi!" << endl;
			Sleep(1000);
			print_pBoard_AttackBoard();
			gridatt[p_puolKoord_x][p_puolKoord_y] = 'X';
			cpu_carr_size--;
			cpuLaivuKiekis--;
		}
		else if (cpuLaivuKiekis <= 0)
		{
			game_on = false;
		}
		else
		{
			cout << setw(82) << "Nepataikete!" << endl;
			Sleep(1000); 
			print_pBoard_AttackBoard();
			gridatt[p_puolKoord_x][p_puolKoord_y] = 'O';
		}
		if (cpu_patrol_size == 0 && cpu_patrol_done != 1) // if'as naudojamas isvesti pranesimui jog nuskanditas vienas ar kitas kompiuterio laivas
		{
			cout << setw(82) << "Jus nuskandinote kompiuterio patruli" << endl;
			Sleep(1000);
			cpu_patrol_done = 1;
			print_pBoard_AttackBoard();
		}
		else if (cpu_carr_size == 0 && cpu_carr_done != 1)
		{
			cout << setw(82) << "Jus nuskandinote kompiuterio lektuvnesi" << endl;
			Sleep(1000);
			cpu_carr_done = 1;
			print_pBoard_AttackBoard();
		}
		else if (cpu_dest_size == 0 && cpu_dest_done != 1)
		{
			cout << setw(82) << "Jus nuskandinote kompiuterio zvalga" << endl;
			Sleep(1000);
			cpu_dest_done = 1;
			print_pBoard_AttackBoard();
		}
		else if (cpu_crei_size == 0 && cpu_crei_done != 1)
		{
			cout << setw(82) << "Jus nuskandinote kompiuterio kreiseri" << endl;
			Sleep(1000);
			cpu_crei_done = 1;
			print_pBoard_AttackBoard();
		}
		else if (cpu_sub_size == 0 && cpu_sub_done != 1)
		{
			cout << setw(82) << "Jus nuskandinote kompiuterio povandenini laiva" << endl;
			Sleep(1000);
			cpu_sub_done = 1;
			print_pBoard_AttackBoard();
		}
	}
	void cpu_puolimas_tikr() // kompiuterio puolimo tikrinimas, bei random reiksmiu priskyrimas. Puolimas veikia do/while cikle, pataikius i viena is zaidejo laivu jo reiksme pasikeicia i true, per kita puolima ciklas pirmiausia iesko true reikmes, jei tokia randa atakuoja i P/S/D/K/C koordinate
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
			else if (crei_hit == true)
			{
				if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'K')
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
			if (patrol_hit == false && sub_hit == false && dest_hit == false && carr_hit == false && crei_hit == false) // jeigu ir nebuvo pataikyta kompiuteris atakuoja
			{
				cpu_puolimas();
			}
		} while (!cpu_pultiTinka || p_LaivuKiekis > 0);
	}
	void cpu_puolimas() // kompiuterio atakavimas bei pranesimo isvedimas jog buvo pataikyta
	{
		if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'P')
		{
			cout << setw(82) << "Kompiuteris pataike i jusu Patruli" << endl;
			Sleep(1000);
			patrol_hit = true;
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'X';
			p_patrol_size--;
			p_LaivuKiekis--;
		}
		else if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'S')
		{
			cout << setw(82) << "Kompiuteris pataike i jusu Povandenini lava" << endl;
			Sleep(1000);
			sub_hit = true;
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'X';
			p_sub_size--;
			p_LaivuKiekis--;
		}
		else if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'D')
		{
			cout << setw(82) << "Kompiuteris pataike i jusu zvalga" << endl;
			Sleep(1000);
			dest_hit = true;
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'X';
			p_dest_size--;
			p_LaivuKiekis--;
		}
		else if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'K')
		{
			cout << setw(82) << "Kompiuteris pataike i jusu kreiseri" << endl;
			Sleep(1000);
			dest_hit = true;
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'X';
			p_crei_size--;
			p_LaivuKiekis--;
		}
		else if (grid[cpu_puolKoord_x][cpu_puolKoord_y] == 'C')
		{
			cout << setw(82) << "Kompiuteris pataike i jusu Lektuvnesi" << endl;
			Sleep(1000);
			carr_hit = true;
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'X';
			p_carr_size--;
			p_LaivuKiekis--;
		}
		else
		{
			cout << setw(82) << "Kompiuteris nepataike!" << endl;
			Sleep(1000);
			grid[cpu_puolKoord_x][cpu_puolKoord_y] = 'O';
			cpu_pultiTinka = false;
		}
		if (p_patrol_size == 0 && p_patrol_done != 1)
		{
			cout << setw(82) << "Kompiuteris nuskandino jusu Patruli" << endl;
			Sleep(1500);
			p_patrol_done = 1;
			print_pBoard_AttackBoard();
		}
		if (p_dest_size == 0 && p_dest_done != 1)
		{
			cout << setw(82) << "Kompiuteris nuskandino jusu Zvalga" << endl;
			Sleep(1500);
			p_dest_done = 1;
			print_pBoard_AttackBoard();
		}
		if (p_carr_size == 0 && p_carr_done != 1)
		{
			cout << setw(82) << "Kompiuteris nuskandino jusu Lektuvnesi" << endl;
			Sleep(1500);
			p_carr_done = 1;
			print_pBoard_AttackBoard();
		}
		if (p_sub_size == 0 && p_sub_done != 1)
		{
			cout << setw(82) << "Kompiuteris nuskandino jusu Povandenini laiva" << endl;
			Sleep(1500);
			p_sub_done = 1;
			print_pBoard_AttackBoard();
		}
		if (p_crei_size == 0 && p_crei_done != 1)
		{
			cout << setw(82) << "Kompiuteris nuskandino jusu Kreiseri" << endl;
			Sleep(1500);
			p_crei_done = 1;
			print_pBoard_AttackBoard();
		}
		c_h();
		if (p_LaivuKiekis <= 0)
		{
			system("CLS");
			cout << setw(82) << "Atleiskite, " << vardas << "Jus pralaimejote";

		}
		else if (cpu_pultiTinka = true)
		{
			p_puolimas_tikr();
		}
	}
	void c_h() // funkcija kuri nuskendus kompiuterio laivui pataikymo reiksme grazina i false jog nebebutu saudoma i nuskendusio laivo vieta
	{
		if (p_patrol_size == 0)
		{
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
		if (p_crei_size == 0)
		{
			crei_hit = false;
		}
	}
	void zaidimo_pabaiga()
	{
		if (game_on == false)
		{
			cout << setw(58) <<  "Sveikiname " << vardas << " nugalėjo!";
		}
	}
	void zaidimo_pabaiga2()
	{
		if (game_on == false)
		{
			cout << setw(58) << "Nugalejo Kompiuteris!";
		}
	}
	~laivai()
	{}
};

int main()
{
	laivai g; // objekto incinizavimas
	g.menu(); // meniu iskvietimas
}
