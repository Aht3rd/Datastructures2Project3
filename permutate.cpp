/***************************************************************
  Student Name: Thomas, Arthur
  File Name: permutate.cpp
  Assignment number: Project 3

  Permutate class to handle permutating
***************************************************************/

#include "permutate.hpp"

Permutate::Permutate(double *matrix, int size, int *route, int numCities)
{
    this->adjacencyMatrix = matrix;
    this->size = size;
    this->numCities = numCities;
    this->minPath = new int[numCities];
}

void Permutate::Permute(int *route, int numPerms)
{
    int m, k, p, q;
    unsigned long long int i;
    unsigned long long int permsThisCall = numPerms;
    if (numPerms == numCities)
    {
        permsThisCall = Factorial(numCities);
    }
    for (i = 1; i < permsThisCall; i++)
    {
        m = numCities - 2;
        while (route[m] > route[m + 1])
        {
            m = m - 1;
        }
        k = numCities - 1;
        while (route[m] > route[k])
        {
            k = k - 1;
        }
        Swap(route, m, k);
        p = m + 1;
        q = numCities - 1;
        while (p < q)
        {
            Swap(route, p, q);
            p++;
            q--;
        }
        GetCost(route, numCities);
    }
}

unsigned long long int Permutate::Factorial(int num)
{
    unsigned long long int fact = 1;
    for (int i = 2; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}

void Permutate::Swap(int *route, int i, int j)
{
    int s = route[i];
    route[i] = route[j];
    route[j] = s;
}

void Permutate::GetCost(int *route, int numCities)
{
    double cost = 0;
    for (int i = 0; i < numCities; i++)
    {
        if (i == numCities - 1)
        {
            cost += adjacencyMatrix[route[i] * size + route[0]];
        }
        else
        {
            cost += adjacencyMatrix[route[i] * size + route[i + 1]];
        }
    }
    if (cost < minCost)
    {
        minCost = cost;
        for (int i = 0; i < numCities; i++)
        {
            minPath[i] = route[i];
        }
    }
}

int *Permutate::GetElite()
{
    return this->minPath;
}

double Permutate::GetMinCost()
{
    return minCost;
}

Permutate::~Permutate()
{
    delete[] this->minPath;
}