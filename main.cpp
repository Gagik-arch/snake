#include <iostream>
#include "snake/snake.cpp"
#include <Windows.h>
#include "enums/enums.cpp"
#include <conio.h>
#include "map/map.cpp"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void cursor()
{
	COORD pos = { 0, 0 };
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	Snake snake = Snake();
	cursor();
	snake.update();

	do {
		cursor();
		if (snake.isKilled) {
			snake.update();
			std::cout << "Eaten apple count - " << snake.eatenAppleCount << std::endl;
			std::cout << "Snake is killed" << std::endl;
		}
		else {
			if (GetKeyState('W') < 0) {
				snake.changeDirection('u');
			}
			else if (GetKeyState('S') < 0) {
				snake.changeDirection('d');
			}
			else if (GetKeyState('A') < 0) {
				snake.changeDirection('l');
			}
			else if (GetKeyState('D') < 0) {
				snake.changeDirection('r');
			}
			snake.move();
			snake.update();
			std::cout << "Eaten apple count - " << snake.eatenAppleCount << std::endl;
		}
		std::cout << "Controls"  << std::endl;
		std::cout << "up - W"  << std::endl;
		std::cout << "down - S"  << std::endl;
		std::cout << "left - A"  << std::endl;
		std::cout << "right - R"  << std::endl;
		std::cout << "press <ESC> to close the app!"  << std::endl;
		Sleep(80);

	} while (GetKeyState(VK_ESCAPE) >= 0);

	return 0;
}