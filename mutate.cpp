/***************************************************************
  Student Name: Thomas, Arthur
  File Name: mutate.cpp
  Assignment number: Project 3

  Mutate class to handle all mutations
***************************************************************/

#include "mutate.hpp"

Mutate::Mutate(double *matrix, int size, int *route, int numCities, int numTours, int numGenerations, int percentMutate)
{
    this->matrix = matrix;
    this->size = size;
    this->numCities = numCities;
    this->numTours = numTours;
    this->numGenerations = numGenerations;
    this->percentMutate = percentMutate;
    this->numMutations = (numTours * percentMutate) / 100;
    this->numPermutations = numTours - numMutations;
    this->object = new Permutate((double *)matrix, size, route, numCities);
    this->object->GetCost(route, numCities);
    this->bestPath = object->GetElite();
    this->minCost = object->GetMinCost();
    MutateRoute(bestPath, numMutations);
}

void Mutate::MutateRoute(int *route, int numMutations)
{
    for (int x = numGenerations; x > 0; x--)
    {
        srand(time(0));
        int minEdge = 0;
        int amountSwap = 6;
        int num[amountSwap];
        for (int y = numMutations; y > 0; y--)
        {
            minEdge = FindMinEdge(route, numCities);
            if (minEdge == numCities - 1)
            {
                object->Swap(route, minEdge, numCities / 2);
                object->Swap(route, 0, numCities / 2 + 1);
            }
            else
            {
                object->Swap(route, minEdge, numCities / 2);
                object->Swap(route, minEdge + 1, numCities / 2 + 1);
            }
            for (int z = 0; z < amountSwap; z++)
            {
                num[z] = (rand() % numCities);
                while (num[z] == numCities / 2 || num[z] == numCities / 2 + 1)
                {
                    num[z] = (rand() % numCities);
                }
            }
            for (int j = 0; j < amountSwap; j += 2)
            {
                if (j == amountSwap - 1)
                {
                    object->Swap(route, num[j], num[0]);
                }
                else
                {
                    object->Swap(route, num[j], num[j + 1]);
                }
            }
            object->GetCost(route, numCities);
            minCost = object->GetMinCost();
            bestPath = object->GetElite();
        }
        object->Permute(object->GetElite(), numPermutations);
        minCost = object->GetMinCost();
        bestPath = object->GetElite();
    }
}

int Mutate::FindMinEdge(int *route, int numCities)
{
    int edge = 0;
    double min = matrix[route[0] * size + route[1]];
    for (int i = 1; i < numCities; i++)
    {
        if (i == numCities - 1)
        {
            if (matrix[route[i] * size + route[0]] < min)
            {
                min = matrix[route[i] * size + route[0]];
                edge = i;
            }
        }
        else
        {
            if (matrix[route[i] * size + route[i + 1]] < min)
            {
                min = matrix[route[i] * size + route[i + 1]];
                edge = i;
            }
        }
    }
    return edge;
}

double Mutate::GetMinCost()
{
    return minCost;
}

Mutate::~Mutate()
{
    delete this->object;
}