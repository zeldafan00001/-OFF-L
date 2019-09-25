#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include <time.h>

clock_t cbegin, cend;

void stc(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void scv(bool show) {
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	cursor.bVisible = show;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

struct daten {
	int _d_id;
	char _d_name[20];
	int _d_alter;

	struct daten* next;

};

typedef daten daten;

struct daten* anfang;
struct daten* neu;
struct daten* aktuell = anfang;

void DatenEingeben(int& id)
{
	scv(true);
	system("cls");
	daten* neu;
	char loop = 'q';
	while (loop == 'q')
	{
		system("cls");
		if (anfang == NULL)
		{
			anfang = (daten*)malloc(sizeof(daten));
			//printf("ANFANG");
			//getchar();
			printf("ID(%d)\n", id);
			printf("Name eingeben : ");
			gets_s(anfang->_d_name);

			printf("Alter eingeben : ");
			scanf_s("%d", &anfang->_d_alter);

			anfang->_d_id = id;

			id++;

			anfang->next = NULL;
			aktuell = anfang;

			printf("Weiter? YES(q) / NO(e)");
			loop = _getch();
		}
		else {

			neu = (daten*)malloc(sizeof(daten));
			aktuell->next = neu;

			//printf("NEU");
			aktuell = neu;

			getchar();
			printf("ID(%d)\n", id);
			printf("Name eingeben : ");
			gets_s(aktuell->_d_name);

			printf("Alter eingeben : ");
			scanf_s("%d", &aktuell->_d_alter);

			neu->next = NULL;
			aktuell->_d_id = id;
			id++;

			printf("Weiter? YES(q) / NO(e)");
			loop = _getch();
		}
	}
}

void DatenAusgeben(int id)
{

	daten* aktuell = anfang;

	system("cls");
	if (anfang != NULL)
	{
		do
		{
			printf("ID(%d) %s %d\n", aktuell->_d_id, aktuell->_d_name, aktuell->_d_alter);
			aktuell = (aktuell->next);

		} while (aktuell != NULL);
	}
	else
		printf("Keine Daten vorhanden! press ENTER");
	getchar();
	getchar();
}

void DatenSpeichern()
{

	daten* aktuell = anfang;

	FILE* dat;

	dat = fopen("daten.txt", "w");

	if (anfang != NULL)
	{
		do
		{
			fprintf(dat, "%d\t%s\t%d asdasd", aktuell->_d_id, aktuell->_d_name, aktuell->_d_alter);
			fprintf(dat, "\n");
			aktuell = (aktuell->next);

		} while (aktuell != NULL);
	}

	system("cls"); printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	stc(20); printf("\t\t SAVED "); stc(1);
	printf("."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); stc(7);

}

void end()
{
	double time_spent;

	cend = clock();

	system("CLS");

	printf("Programm Closed\n");
	printf("Runtime ( "); stc(10);  printf("%.2fsec", time_spent = (double)(cend - cbegin) / CLOCKS_PER_SEC); stc(7); printf(" )\n");
	_getch();

	exit(1);
}


void drawMenu(int& x, char menu[4][20]) {
	stc(64); printf(" MALLOC |  SAVE DATA  | by Kevin Schmitz\n"); stc(7);
	printf("\n\n\n\n\n\n\n\n");
	for (int display = 0; display < 5; display++) {
		if (display == x) {
			stc(10); printf("\t     %s\n", menu[display]); stc(7);
		}
		if (display != x) {
			printf("\t     %s\n", menu[display]);
		}
	}
	stc(64); printf("\n\n\n\n\n\n\n\n\n\nSPACE = EINGABE | W = HOCH |  S = RUNTER"); stc(7);
}

void input(int& keyP, int& x) {
	keyP = _getch();
	switch (keyP)
	{
	case 119:
		x--;
		if (x == 0)
			x = 1;
		break;
	case 115:
		x++;
		if (x == 5)
			x = 4;
		break;
	}
}

int main()
{
	system("mode 40, 25");
	int id = 1, aw, x;					// ID - Ist die ID des nutzers im Struct

	int x_menu = 1;
	char keyPressed;
	int keyP;

	char menu[5][20] = { " ",
					"DATEN EINGEBEN",
					"DATEN AUSGEBEN",
					"SPEICHER DATEN",
					"BEENDE ROGRAMM" };

	cbegin = clock();

	while (true) {
		scv(false);
		system("cls");
		drawMenu(x_menu, menu);
		input(keyP, x_menu);
		if (GetAsyncKeyState(VK_SPACE))
		{
			switch (x_menu)
			{
			case 1:
				DatenEingeben(id);
				break;
			case 2:
				DatenAusgeben(id);
				break;
			case 3:
				DatenSpeichern();
				break;
			case 4:
				end();
				break;
			}
		}


	}



	/*
	while (true)
	{
		stc(7);
		system("cls");
		printf("1. Daten Eingeben\n");
		printf("2. Daten Ausgeben\n");
		printf("3. Daten Speichern\n");
		printf("9. Exit\n");
		printf(">> ");
		scanf_s("%d", &aw);

		switch (aw)
		{
		case 1:
			DatenEingeben(id);

			break;
		case 2:
			DatenAusgeben(id);

			break;
		case 3:
			DatenSpeichern();

			break;
		case 9:
			end();
			break;
		default:

			break;
		}

	}
	*/

	return 0;

}



