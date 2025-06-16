#include <conio.h>
#include <bits/stdc++.h>
#include <unistd.h>

std::string currCommand;
std::vector<std::string> commands;
int x = 0;
int y = 0;
int sizeX = 100;
int sizeY = 15;
int yCount = 1;
int xCount = 1;

void pollKeyboard() {
    if (_kbhit()) {
        char key = _getch();
        if (key==13) {
            currCommand.push_back('\n');
            commands.push_back(currCommand);
            currCommand = "";
        } else if (key==8) {
            if (currCommand.length()>0) {
                currCommand.pop_back();
            }
        } else {
            currCommand.push_back(key);
        }
    }
}

void drawScreen() {
    system("cls");
    std::cout << "*****************************************************\n"
              << "*\tDisplaying a Marquee Console!\t*\n"
              << "*****************************************************\n";

    //set coords
    if (y == 1 && yCount < 0) {
        yCount = -yCount;
    } else if (y==sizeY-1 && yCount > 0) {
        yCount = -yCount;
    }
    y+=yCount;


    if (x == 1 && xCount < 0) {
        xCount = -xCount;
    } else if (x==sizeX && xCount > 0) {
        xCount = -xCount;
    }
    x+=xCount;

    for(int i = 1;i<y;i++) {
        std::cout << "\n";
    }
    std::cout << std::setw(23+x) << "Hello world in Marquee!";
    for(int i = y;i<sizeY;i++) {
        std::cout << "\n";
    }

    std::cout << "Enter a command for MARQUEE CONSOLE: " << currCommand << "\n";
    std::reverse(commands.begin(), commands.end());
    for(std::string command:commands) {
        std::cout << "Command processed in MARQUEE_CONSOLE: " << command;
    }
    std::reverse(commands.begin(), commands.end());
}

int main() {
    while(true) {
        pollKeyboard();
        usleep(3000);
        drawScreen();
    }
    return 0;
}