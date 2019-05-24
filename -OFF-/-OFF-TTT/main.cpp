#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

void scv(bool show) {
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	cursor.bVisible = show;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void scp(int y, int x) {
	COORD cursor = { x,y + 3 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void stc(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void StartSettings() // Setzt die Start settings der console
{
	scv(false);
	SetConsoleTitle(TEXT("Tic Tac Toe"));
	system("mode 21, 20");
}
void logo() // Zeichnet das Logo
{
	int rgb;
	srand(time(NULL));
	rgb = rand() % 14 + 1;
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	stc(rgb);
	printf("     \xC4\xC2\xC4 \xC4\xC2\xC4 \xC4\xC2\xC4\n");
	stc(rgb);
	printf("      \xB3   \xB3   \xB3 \n");
	stc(rgb);
	printf("      \xB3   \xB3   \xB3 \n");
	stc(7);
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
}
void draw(char map[7][8],char &spieler) // Zeichnet die "Map"
{
	system("cls");
	logo();
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			scp(y+3, x+7);
			if (map[y][x] == '1') { printf(" "); }
			if (map[y][x] == '0') { printf(" "); }
			if (map[y][x] == 'X') { printf("X"); }
			if (map[y][x] == 'O') { printf("O"); }
			if (map[y][x] == '3') { printf("\xB3"); }
			if (map[y][x] == '4') { printf("\xC4"); }
		}
		printf("\n"); 
	}
	scp(9, 15);
	stc(12);
	printf("%c <-", spieler);
	stc(7);
}
void sw(char &spieler) // Spieler Wechsel
{
	if (spieler == 'X')
	{
		spieler = 'O';
	}
	else
	{
		spieler = 'X';
	}
}
void sp(char &spieler) // zufälliger spieler
{
	int rng;
	srand(time(NULL));
	rng = rand() % 2 + 1;
	if (rng == 1) { spieler = 'X'; }
	if (rng == 2) { spieler = 'O'; }
}
void drawNumbers(char map[7][8]) // Hier werden die nummern gezeichnet, wenn eine nummer schon vergeben ist wird diese mit einem "-" makiert
{
	char auswahl[4][4] = { "123","456","789" };
	printf("\n\n\t");
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (map[1][1] == 'X' || map[1][1] == 'O') { auswahl[0][0] = '-'; }
			if (map[1][3] == 'X' || map[1][3] == 'O') { auswahl[0][1] = '-'; }
			if (map[1][5] == 'X' || map[1][5] == 'O') { auswahl[0][2] = '-'; }
			if (map[3][1] == 'X' || map[3][1] == 'O') { auswahl[1][0] = '-'; }
			if (map[3][3] == 'X' || map[3][3] == 'O') { auswahl[1][1] = '-'; }
			if (map[3][5] == 'X' || map[3][5] == 'O') { auswahl[1][2] = '-'; }
			if (map[5][1] == 'X' || map[5][1] == 'O') { auswahl[2][0] = '-'; }
			if (map[5][3] == 'X' || map[5][3] == 'O') { auswahl[2][1] = '-'; }
			if (map[5][5] == 'X' || map[5][5] == 'O') { auswahl[2][2] = '-'; }
			printf("%c ", auswahl[y][x]);
		}
		printf("\n\t");
	}
}
void pinput(char& spieler, char map[7][8]) // hier wird der playerinput geregelt
{
	int ausw;
	int succ = 0;
	
	do {
		draw(map, spieler);
		drawNumbers(map);
		printf("  ");
		scanf_s("%d", &ausw);
		if (ausw == 1 && map[1][1] != 'X' && map[1][1] != 'O') { map[1][1] = spieler; succ = 1; }
		if (ausw == 2 && map[1][3] != 'X' && map[1][3] != 'O') { map[1][3] = spieler; succ = 1; }
		if (ausw == 3 && map[1][5] != 'X' && map[1][5] != 'O') { map[1][5] = spieler; succ = 1; }
		if (ausw == 4 && map[3][1] != 'X' && map[3][1] != 'O') { map[3][1] = spieler; succ = 1; }
		if (ausw == 5 && map[3][3] != 'X' && map[3][3] != 'O') { map[3][3] = spieler; succ = 1; }
		if (ausw == 6 && map[3][5] != 'X' && map[3][5] != 'O') { map[3][5] = spieler; succ = 1; }
		if (ausw == 7 && map[5][1] != 'X' && map[5][1] != 'O') { map[5][1] = spieler; succ = 1; }
		if (ausw == 8 && map[5][3] != 'X' && map[5][3] != 'O') { map[5][3] = spieler; succ = 1; }
		if (ausw == 9 && map[5][5] != 'X' && map[5][5] != 'O') { map[5][5] = spieler; succ = 1; }
	} while (succ == 0);
}
void checkwin(int& run, char& spieler, char map[7][8])
{
	// Spieler 1 Check ob gewonnen X

	if (map[1][1] == 'X' && map[1][3] == 'X' && map[1][5] == 'X') { run = 0; }
	if (map[3][1] == 'X' && map[3][3] == 'X' && map[3][5] == 'X') { run = 0; }
	if (map[5][1] == 'X' && map[5][3] == 'X' && map[5][5] == 'X') { run = 0; }

	if (map[1][1] == 'X' && map[3][1] == 'X' && map[5][1] == 'X') { run = 0; }
	if (map[1][3] == 'X' && map[3][3] == 'X' && map[5][3] == 'X') { run = 0; }
	if (map[1][5] == 'X' && map[3][5] == 'X' && map[5][5] == 'X') { run = 0; }

	if (map[1][1] == 'X' && map[3][3] == 'X' && map[5][5] == 'X') { run = 0; }
	if (map[5][1] == 'X' && map[3][3] == 'X' && map[1][5] == 'X') { run = 0; }

	// Spieler 2 Check ob gewonnen O

	if (map[1][1] == 'O' && map[1][3] == 'O' && map[1][5] == 'O') { run = 0; }
	if (map[3][1] == 'O' && map[3][3] == 'O' && map[3][5] == 'O') { run = 0; }
	if (map[5][1] == 'O' && map[5][3] == 'O' && map[5][5] == 'O') { run = 0; }

	if (map[1][1] == 'O' && map[3][1] == 'O' && map[5][1] == 'O') { run = 0; }
	if (map[1][3] == 'O' && map[3][3] == 'O' && map[5][3] == 'O') { run = 0; }
	if (map[1][5] == 'O' && map[3][5] == 'O' && map[5][5] == 'O') { run = 0; }

	if (map[1][1] == 'O' && map[3][3] == 'O' && map[5][5] == 'O') { run = 0; }
	if (map[5][1] == 'O' && map[3][3] == 'O' && map[1][5] == 'O') { run = 0; }

}

void winnerX()
{
	char winnerX[23][22] = { "111111111111111111111","111211121111111111111","111211121111111111111","111222221222212112111","111112111211212112111","111112111222212222111","111111111111111111111","111211121111111111111","111212121222212221111","111212121211212112111","111222221222212112111","111111111111111111111","111111111111111111111","111111113111311111111","111111111313111111111","111111111131111111111","111111111313111111111","111111113111311111111","111111111111111111111","111111111111111111111" };

	for (int y = 0; y < 26; ++y)
	{
		for (int x = 0; x < 22; ++x)
		{
			if (winnerX[y][x] == '1') printf("\xDB");
			if (winnerX[y][x] == '2') { stc(11); printf("\xDB"); stc(7); }
			if (winnerX[y][x] == '3') { stc(12); printf("\xDB"); stc(7); }
		}
	}
}
void winnerO()
{
	{
		char winnerX[23][22] = { "111111111111111111111","111211121111111111111","111211121111111111111","111222221222212112111","111112111211212112111","111112111222212222111","111111111111111111111","111211121111111111111","111212121222212221111","111212121211212112111","111222221222212112111","111111111111111111111","111111111111111111111","111111111333111111111","111111113111311111111","111111113111311111111","111111113111311111111","111111111333111111111","111111111111111111111","111111111111111111111" };

		for (int y = 0; y < 26; ++y)
		{
			for (int x = 0; x < 22; ++x)
			{
				if (winnerX[y][x] == '1') printf("\xDB");
				if (winnerX[y][x] == '2') { stc(11); printf("\xDB"); stc(7); }
				if (winnerX[y][x] == '3') { stc(12); printf("\xDB"); stc(7); }
			}
		}
	}
}

void winner(char &spieler)
{
	sw(spieler);
	system("CLS");
	if (spieler == 'X') winnerX();
	if(spieler == 'O') winnerO();
	_getch();
}

int main()
{
	char map[7][8] = { 
		"1414141",
		"3030303",
		"1414141",
		"3030303",
		"1414141",
		"3030303",
		"1414141" };

	char spieler = 'X';
	int run = 1;

	StartSettings();

	sp(spieler);
	draw(map, spieler);

	while (run == 1)
	{
		
		draw(map,spieler);
		pinput(spieler, map);
		checkwin(run, spieler, map);
		sw(spieler);
	}

	winner(spieler);

	system(" PAUSE ");
	return 1;

}