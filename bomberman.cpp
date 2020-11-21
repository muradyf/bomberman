#include <iostream>
#include <stdlib.h> //FOR RAND/SRAND AND EXIT FUNCTION
#include <conio.h> //FOR _GETCHE FUNCTION
#include <time.h> //FOR RANDOMIZING WITH RESPECT TO TIME
using namespace std;

//PROTOTYPES
void instructions();
void playGame(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore [5], int list);
void generateMap(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y);
void findPlayerPos(char grid5x5[5][5], int gridSize, char player, char &playerPos, int &player_x, int &player_y);
void createDiamond_1(char grid5x5[5][5], int gridSize, char player, char diamond, char &playerPos, int &player_x, int  &player_y);
void createDiamond_2(char grid5x5[5][5], int gridSize, char player, char diamond, char &playerPos, int &player_x, int  &player_y);
void createBomb_1(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int  &player_y);
void createBomb_2(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int  &player_y);
void moveCharacter(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list);
void moveUp(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, int &score, char playerPos, char input, int &player_x, int &player_y, bool &end);
void moveDown(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, int &score, char playerPos, char input, int &player_x, int &player_y, bool &end);
void moveLeft(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, int &score, char playerPos, char input, int &player_x, int &player_y, bool &end);
void moveRight(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, int &score, char playerPos, char input, int &player_x, int &player_y, bool &end);
void resetArray(char grid5x5[5][5], int gridSize);
void resetArrayCont(char grid5x5[5][5], int gridSize);
void gameWon(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list);
void endGame(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list);
void scoreBoard(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list);
void playAgain(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list);
void displayGame(char grid5x5[5][5], int gridSize, int &score);

int main()
{
	//CREATING RANDOM INDEXES FOR DIAMONDS/BOMBS
	srand(time(NULL)); 

	//INITITIALIZING GRID & CHARACTERS
	const int gridSize = 5;
	char grid5x5[5][5] = { {'&','*','*','*','*'},
						   {'*','*','*','*','*'},
						   {'*','*','*','*','*'},
						   {'*','*','*','*','*'},
						   {'*','*','*','*','*'} };
	char player = '&';
	char diamond = '$';
	char bomb = '%';
	int score = 0;
	char playerPos;
	int player_x = 0, player_y = 0;

	//FOR SCOREBOARD

	//ARRAY FOR SCORES
	int highscore[5] = {0};

	//ARRAY FOR NAMES IN SCOREBOARD
	char name1[5] = "\0";
	char name2[5] = "\0";
	char name3[5] = "\0";
	char name4[5] = "\0";
	char name5[5] = "\0";

	//DECLARATION OF SERIAL NUMBER OF PLAYERS
	int list = 0;

	//PLAY AREA
	instructions ();
	playGame(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y, score, name1, name2, name3, name4, name5, highscore, list);
}

void instructions()
{
	cout << "\n ============= Bomber Game ==============\n";
	cout << "\n                & - Player";
	cout << "\n                $ - Diamond";
	cout << "\n                % - Bomb";
	cout << "\n\n  Instructions: You need to collect";
	cout << "\n  diamonds in order to win the game.";
	cout << "\n  Picking up a bomb will end the game.";
	cout << "\n  Picking up a diamond will automatically";
	cout << "\n  reset the positions of the diamonds";
	cout << "\n  and the bombs. Collect 25 diamonds to";
	cout << "\n               win the game.";
	cout << "\n\n ========================================\n";
	
	cout << "\n     Press any key to play the game";
	_getche();
	
	cout << endl << endl;
}

void playGame(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore [5], int list)
{
	generateMap(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y);
	displayGame(grid5x5, gridSize, score);
	moveCharacter(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y, score, name1, name2, name3, name4, name5, highscore, list);
}

void generateMap(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y)
{
	findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);
	createDiamond_1(grid5x5, gridSize, player, diamond, playerPos, player_x, player_y);
	createDiamond_2(grid5x5, gridSize, player, diamond, playerPos, player_x, player_y);
	createBomb_1(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y);
	createBomb_2(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y);
}

void findPlayerPos(char grid5x5[5][5], int gridSize, char player, char &playerPos, int &player_x, int &player_y)
{
	for (int x = 0; x < gridSize; x++)	{
		for (int y = 0; y < gridSize; y++) {
			if (grid5x5[x][y] == player) {
				playerPos = grid5x5[x][y];

				player_x = x;
				player_y = y;

				break;
			}
		}
	}
}

void createDiamond_1(char grid5x5[5][5], int gridSize, char player, char diamond, char &playerPos, int &player_x, int  &player_y)
{
	int x = rand() % 5;  //Diamond 1 (x axis)
	int y = rand() % 5;  //Diamond 1 (y axis)

	while (grid5x5[x][y] != '*') {
		x = rand() % 5;
		y = rand() % 5;
	}

	grid5x5[x][y] = diamond;
}

void createDiamond_2(char grid5x5[5][5], int gridSize, char player, char diamond, char &playerPos, int &player_x, int  &player_y)
{
	int x = rand() % 5;  //Diamond 2 (x axis)
	int y = rand() % 5;  //Diamond 2 (y axis)

	while (grid5x5[x][y] != '*') {
		x = rand() % 5;
		y = rand() % 5;
	}

	grid5x5[x][y] = diamond;
}

void createBomb_1(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int  &player_y)
{
	int x = rand() % 5;  //Bomb 1 (x axis)
	int y = rand() % 5;  //Bomb 1 (y axis)

	while (grid5x5[x][y] != '*') {
		x = rand() % 5;
		y = rand() % 5;
	}

	grid5x5[x][y] = bomb;
}

void createBomb_2(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int  &player_y)
{
	int x = rand() % 5;  //Bomb 2 (x axis)
	int y = rand() % 5;  //Bomb 2 (y axis)

	while ( grid5x5 [x][y] != '*')	{
		x = rand() % 5;
		y = rand() % 5;
	}

	grid5x5[x][y] = bomb;
}

void moveCharacter(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list)
{
	char input;
	bool end = 0;

	score = 0;

	findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);

	while (end == 0) {
		end = 0;

		cout << "      Use wasd to move: ";
		input = _getche();
		cout << endl;
		
		if (input == 'w' || input == 'W') {
			moveUp(grid5x5, gridSize, player, diamond, bomb, score, playerPos, input, player_x, player_y, end);
		}
		else if (input == 's' || input == 'S') {
			moveDown(grid5x5, gridSize, player, diamond, bomb, score, playerPos, input, player_x, player_y, end);
		}
		else if (input == 'a' || input == 'A') {
			moveLeft(grid5x5, gridSize, player, diamond, bomb, score, playerPos, input, player_x, player_y, end);
		}
		else if (input == 'd' || input == 'D') {
			moveRight(grid5x5, gridSize, player, diamond, bomb, score, playerPos, input, player_x, player_y, end);
		}
		else {
			cout << "\n =============================\n";
			cout << "        Invalid Movement!";
			cout << "\n =============================";
		}

		if (score == 25) {
			end = 1;
			gameWon(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y, score, name1, name2, name3, name4, name5, highscore, list);
		}

		if (end == 0) {
			displayGame(grid5x5, gridSize, score);
		}
		else {
			endGame(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y, score, name1, name2, name3, name4, name5, highscore, list);
			end = 1;
		}
	}
}

void moveUp(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, int &score, char playerPos, char input, int &player_x, int &player_y, bool &end)
{
	if (player_x - 1 != -1) {
		if (grid5x5[player_x - 1][player_y] == diamond) {
			score++;

			grid5x5[player_x][player_y] = '*';
			grid5x5[player_x - 1][player_y] = player;

			resetArrayCont(grid5x5, gridSize);
			findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);
			generateMap(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y);
		}
		else if (grid5x5[player_x - 1][player_y] == bomb) {
			end = 1;
		}
		else {
			if (player_x - 1 != -1) {
				grid5x5[player_x][player_y] = '*';
				grid5x5[player_x - 1][player_y] = player;

				findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);
			}
		}
	}
}

void moveDown(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, int &score, char playerPos, char input, int &player_x, int &player_y, bool &end)
{
	if (player_x + 1 != 5) {
		if (grid5x5[player_x + 1][player_y] == diamond) {
			score++;

			grid5x5[player_x][player_y] = '*';
			grid5x5[player_x + 1][player_y] = player;

			resetArrayCont(grid5x5, gridSize);
			findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);
			generateMap(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y);
		}
		else if (grid5x5[player_x + 1][player_y] == bomb) {
			end = 1;
		}
		else {
			if (player_x + 1 != 5)
			{
				grid5x5[player_x][player_y] = '*';
				grid5x5[player_x + 1][player_y] = player;

				findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);
			}
		}
	}
}

void moveLeft(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, int &score, char playerPos, char input, int &player_x, int &player_y, bool &end)
{
	if (player_y - 1 != -1) {
		if (grid5x5[player_x][player_y - 1] == diamond) {
			score++;

			grid5x5[player_x][player_y] = '*';
			grid5x5[player_x][player_y - 1] = player;

			resetArrayCont(grid5x5, gridSize);
			findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);
			generateMap(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y);
		}
		else if (grid5x5[player_x][player_y - 1] == bomb) {
			end = 1;
		}
		else {
			if (player_y - 1 != -1) {
				grid5x5[player_x][player_y] = '*';
				grid5x5[player_x][player_y - 1] = player;

				findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);
			}
		}
	}
}

void moveRight(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, int &score, char playerPos, char input, int &player_x, int &player_y, bool &end)
{
	if (player_y + 1 != 5) {
		if (grid5x5[player_x][player_y + 1] == diamond)
		{
			score++;

			grid5x5[player_x][player_y] = '*';
			grid5x5[player_x][player_y + 1] = player;

			resetArrayCont(grid5x5, gridSize);
			findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);
			generateMap(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y);
		}

		else if (grid5x5[player_x][player_y + 1] == bomb) {
			end = 1;
		}
		else {
			if (player_y + 1 != 5)
			{
				grid5x5[player_x][player_y] = '*';
				grid5x5[player_x][player_y + 1] = player;

				findPlayerPos(grid5x5, gridSize, player, playerPos, player_x, player_y);
			}
		}
	}
}

void resetArray(char grid5x5[5][5], int gridSize)
{
	for (int x = 0; x < gridSize; x++) {
		for (int y = 0; y < gridSize; y++) {
			grid5x5[x][y] = '*';
		}
	}

	grid5x5[0][0] = '&';
}

void resetArrayCont(char grid5x5[5][5], int gridSize)
{
	for (int x = 0; x < gridSize; x++) {
		for (int y = 0; y < gridSize; y++) {
			if (grid5x5[x][y] != '&') {
				grid5x5[x][y] = '*';
			}
		}
	}
}

void gameWon(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list)
{
	system("CLS");
	cout << "\n\n               *";
	cout << "\n             *****";
	cout << "\n           *********";
	cout << "\n         *************";
	cout << "\n       *****************";
	cout << "\n      *******************";
	cout << "\n       *****************";
	cout << "\n         *************";
	cout << "\n           *********";
	cout << "\n             *****";
	cout << "\n               *";

	cout << "\n\n -------------------------------\n";
	cout << "  WINNER WINNER CHICKEN DINNER!";
	cout << "\n -------------------------------\n";
	cout << "     Your final score is: " << score << endl;

	cout << "\n     Press any key to continue ";
	_getche();

	scoreBoard(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y, score, name1, name2, name3, name4, name5, highscore, list);
}

void endGame(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list)
{
	system("CLS");
	cout << "\n\n            **";
	cout << "\n        *   *  *";
	cout << "\n                *";
	cout << "\n      *     *    *";
	cout << "\n        *   ###########";
	cout << "\n            ###########";
	cout << "\n         #################";
	cout << "\n        ###################";
	cout << "\n        ###################";
	cout << "\n       #####################";
	cout << "\n       ################# ###";
	cout << "\n        ################ ##";
	cout << "\n        ############### ###";
	cout << "\n         #################";
	cout << "\n          ###############";
	cout << "\n            ###########";

	cout << "\n\n -----------------------------\n";
	cout << "          GAME OVER!";
	cout << "\n -----------------------------\n";
	cout << "     Your final score is: " << score << endl;

	cout << "\n     Press any key to continue ";
	_getche();

	scoreBoard(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y, score, name1, name2, name3, name4, name5, highscore, list);
}

void scoreBoard(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list)
{
	system("CLS");

	int nameSize = 5;

	cout << "\n  Enter the first five letters of your name: ";

	if (list == 0) {
		for (int i = 0; i < nameSize; i++) {
			name1[i] = _getche();
		}

		highscore[list] = score;
	}
	else if (list == 1) {
		for (int i = 0; i < nameSize; i++) {
			name2[i] = _getche();
		}

		highscore[list] = score;
	}
	else if (list == 2) 	{
		for (int i = 0; i < nameSize; i++) {
			name3[i] = _getche();
		}

		highscore[list] = score;
	}
	else if (list == 3) {
		for (int i = 0; i < nameSize; i++) {
			name4[i] = _getche();
		}

		highscore[list] = score;
	}
	else if (list == 4) {
		for (int i = 0; i < nameSize; i++) {
			name5[i] = _getche();
		}

		highscore[list] = score;
	}
	else if (list > 4) {
		list = 4;

		for (int i = 0; i < nameSize; i++) {
			highscore[i - 1] = highscore[i];
		}

		for (int i = 0; i < nameSize; i++) {
			name1[i] = name2[i];
		}

		for (int i = 0; i < nameSize; i++) {
			name2[i] = name3[i];
		}

		for (int i = 0; i < nameSize; i++) {
			name3[i] = name4[i];
		}

		for (int i = 0; i < nameSize; i++) {
			name4[i] = name5[i];
		}

		for (int i = 0; i < nameSize; i++) {
			name5[i] = _getche();
		}

		highscore[4] = score;
	}

	cout << "\n\n  ___________________________ ";
	cout << "\n |                           |\n";
	cout <<   " |        Score Board        |";
	cout << "\n |---------------------------|";
	cout << "\n |      Names      |  Score  |";
	cout << "\n |-----------------|---------|\n";

	if (list == 0 || list == 1 || list == 2 || list == 3 || list == 4) {
		cout << " |      ";

		for (int i = 0; i < nameSize; i++) {
			cout << name1[i];
		}

		cout << "      |    " << highscore[0];
			
		if (highscore[0] < 10) {
			cout << "    |" << endl;
		}
		else {
			cout << "   |" << endl;
		}
	}

	if (list == 1 || list == 2 || list == 3 || list == 4) {
		cout << " |      ";

		for (int i = 0; i < nameSize; i++) {
			cout << name2[i];
		}

		cout << "      |    " << highscore[1];
			
		if (highscore[1] < 10) {
			cout << "    |" << endl;
		}
		else {
			cout << "   |" << endl;
		}
	}

	if (list == 2 || list == 3 || list == 4) {
		cout << " |      ";

		for (int i = 0; i < nameSize; i++) {
			cout << name3[i];
		}

		cout << "      |    " << highscore[2];
			
		if (highscore[2] < 10) {
			cout << "    |" << endl;
		}
		else {
			cout << "   |" << endl;
		}
	}

	if (list == 3 || list == 4) {
		cout << " |      ";

		for (int i = 0; i < nameSize; i++) {
			cout << name4[i];
		}

		cout << "      |    " << highscore[3];
			
		if (highscore[3] < 10) {
			cout << "    |" << endl;
		}
		else {
			cout << "   |" << endl;
		}
	}

	if (list == 4) {
		cout << " |      ";

		for (int i = 0; i < nameSize; i++) {
			cout << name5[i];
		}

		cout << "      |    " << highscore[4];
			
		if (highscore[4] < 10) {
			cout << "    |" << endl;
		}
		else {
			cout << "   |" << endl;
		}
	}
		
	cout << " |---------------------------|\n";

	playAgain(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y, score, name1, name2, name3, name4, name5, highscore, list);
}

void playAgain(char grid5x5[5][5], int gridSize, char player, char diamond, char bomb, char &playerPos, int &player_x, int &player_y, int &score, char name1[], char name2[], char name3[], char name4[], char name5[], int highscore[5], int list)
{
	char input;

	cout << "\n Do you want to play again? (Y/N): ";
	cin >> input;

	if (input == 'Y' || input == 'y') {
		list++;
		resetArray(grid5x5, gridSize);
		playGame(grid5x5, gridSize, player, diamond, bomb, playerPos, player_x, player_y, score, name1, name2, name3, name4, name5, highscore, list);
	}
	else {
		exit(0);
	}
}

void displayGame(char grid5x5[5][5], int gridSize, int &score)
{
	system("CLS");
	cout << "\n ======== Bomber Game ========\n\n\n";

	for (int x = 0; x < gridSize; x++){
		cout << "    ";

		for (int y = 0; y < gridSize; y++) {
			cout << "   " << grid5x5[x][y];
		}

		cout << endl << endl;
	}

	cout << "\n -----------------------------\n";
	cout << "           Score: " << score;
	cout << "\n -----------------------------\n\n";
}

