/***************************************************************
  Student Name: Thomas, Arthur
  File Name: userinterface.hpp
  Assignment number: Project 3

  Header file for main menu
***************************************************************/

#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "permutate.hpp"
#include "mutate.hpp"

class MainMenu
{
private:
    static const int SIZE = 20;
    double matrix[SIZE][SIZE];
    int *route = nullptr;

public:
    MainMenu(string fileName);
    ~MainMenu();
};
#endif
