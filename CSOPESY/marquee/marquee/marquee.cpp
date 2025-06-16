// marquee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <atomic>

//g++ -std=c++17 -o threaded threaded.cpp

std::string currCommand;
std::vector<std::string> commands;
int x = 0;
int y = 0;
int sizeX = 100;
int sizeY = 15;
int yCount = 1;
int xCount = 1;
std::atomic<bool> running(true);

void pollKeyboard() {
    while (running) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 13) {
                currCommand.push_back('\n');
                // Remove trailing newline for command comparison
                std::string trimmed = currCommand;
                if (!trimmed.empty() && trimmed.back() == '\n') trimmed.pop_back();

                if (trimmed == "exit") {
                    running = false;
                    return;
                } else if (trimmed == "clear") {
                    commands.clear();
                } else {
                    commands.push_back(currCommand);
                }
                currCommand = "";
            }
            else if (key == 8) {
                if (currCommand.length() > 0) {
                    currCommand.pop_back();
                }
            }
            else {
                currCommand.push_back(key);
            }
        }
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
    }
}

void drawScreen() {
    while (running) {
        system("cls");
        std::cout << "*****************************************************\n"
            << "*\tDisplaying a Marquee Console!\t*\n"
            << "*****************************************************\n";

        //set coords
        if (y == 1 && yCount < 0) {
            yCount = -yCount;
        }
        else if (y == sizeY - 1 && yCount > 0) {
            yCount = -yCount;
        }
        y += yCount;

        if (x == 1 && xCount < 0) {
            xCount = -xCount;
        }
        else if (x == sizeX && xCount > 0) {
            xCount = -xCount;
        }
        x += xCount;

        for (int i = 1; i < y; i++) {
            std::cout << "\n";
        }
        std::cout << std::setw(23 + x) << "Hello world in Marquee!";
        for (int i = y; i < sizeY; i++) {
            std::cout << "\n";
        }

        std::cout << "Enter a command for MARQUEE CONSOLE: " << currCommand << "\n";
        std::reverse(commands.begin(), commands.end());
        for (std::string command : commands) {
            std::cout << "Command processed in MARQUEE_CONSOLE: " << command;
        }
        std::reverse(commands.begin(), commands.end());
        std::this_thread::sleep_for(std::chrono::microseconds(5000));
    }
}

int main()
{
    std::thread polling(pollKeyboard);
    std::thread drawing(drawScreen);
    polling.join();
    drawing.join();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
