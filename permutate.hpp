/***************************************************************
  Student Name: Thomas, Arthur
  File Name: permutate.hpp
  Assignment number: Project 3

  Header file for the permutation class
***************************************************************/

#ifndef PERMUTATE_HPP
#define PERMUTATE_HPP
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

class Permutate
{
private:
    int *minPath = nullptr;
    double *adjacencyMatrix = nullptr;
    int size = 0;
    int numCities = 0;
    double minCost = numeric_limits<double>::max();

public:
    Permutate(double *matrix, int size, int *route, int numCities);
    void Permute(int *route, int numPerms);
    unsigned long long int Factorial(int num);
    void Swap(int *route, int i, int j);
    void GetCost(int *route, int numCities);
    int *GetElite();
    double GetMinCost();
    ~Permutate();
};
#endif