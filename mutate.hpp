/***************************************************************
  Student Name: Thomas, Arthur
  File Name: mutate.hpp
  Assignment number: Project 3

  Header file for the mutate class
***************************************************************/

#ifndef MUTATE_HPP
#define MUTATE_HPP
#include <iostream>
#include <iomanip>
#include <limits>
#include <ctime>
#include "permutate.hpp"

class Mutate
{
private:
	Permutate *object = nullptr;
	double *matrix = nullptr;
	int size = 0;
	int *bestPath = nullptr;
	int numCities = 0;
	int numTours = 0;
	int numGenerations = 0;
	int percentMutate = 0;
	int numMutations = 0;
	int numPermutations = 0;
	double minCost = numeric_limits<double>::max();
	void MutateRoute(int *route, int numMutations);
	int FindMinEdge(int *route, int numCities);

public:
	Mutate(double *matrix, int size, int *route, int numCities, int numTours, int numGenerations, int percentMutate);
	double GetMinCost();
	~Mutate();
};
#endif