/***************************************************************
  Student Name: Thomas, Arthur
  File Name: userinterface.cpp
  Assignment number: Project 3

  Building adjacency matrix, handling input from the user, and getting the results
***************************************************************/

#include "mainMenu.hpp"

MainMenu::MainMenu(string fileName)
{
    ifstream inFile(fileName);
    if (inFile.is_open())
    {
        double weight;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i == j)
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    inFile >> weight;
                    matrix[i][j] = weight;
                }
            }
        }
        inFile.close();
        struct timeval *t = (struct timeval *)malloc(sizeof(struct timeval));
        struct timezone *z = (struct timezone *)malloc(sizeof(struct timezone));
        int numCities = 0, numTours = 0, numGenerations = 0, percentMutate = 0;
        long double startTime = 0, endTime = 0;
        cout << "Input desired number of cities to run " << endl;
        cin >> numCities;
        cout << "Input desired number of tours per generation " << endl;
        cin >> numTours;
        cout << "Input desired number of generations to run " << endl;
        cin >> numGenerations;
        cout << "Input percentage of generation to mutate " << endl;
        cin >> percentMutate;
        route = new int[numCities];
        for (int i = 0; i < numCities; i++)
        {
            route[i] = i;
        }
        gettimeofday(t, z);
        startTime = t->tv_sec;
        Permutate bruteForce((double *)matrix, SIZE, route, numCities);
        bruteForce.GetCost(route, numCities);
        bruteForce.Permute(route, numCities);
        gettimeofday(t, z);
        endTime = t->tv_sec;
        cout << "\nThe number of cities run is: " << numCities << endl;
        cout << "The optimal cost from brute force is: " << bruteForce.GetMinCost() << endl;
        cout << "Run time of brute force algoritm is: ";
        if (endTime - startTime < 1.0)
        {
            cout << " less than 1 second" << endl;
        }
        else
        {
            cout << endTime - startTime << " seconds" << endl;
        }
        endTime = 0;
        startTime = 0;
        for (int i = 0; i < numCities; i++)
        {
            route[i] = i;
        }
        gettimeofday(t, z);
        startTime = t->tv_usec;
        Mutate mutate((double *)matrix, SIZE, route, numCities, numTours, numGenerations, percentMutate);
        gettimeofday(t, z);
        endTime = t->tv_usec;
        cout << "The cost found by the genetic alg is: " << mutate.GetMinCost() << endl;
        cout << "Run time for the genetic alg (GA) is: " << endTime - startTime << " micro seconds" << endl;
        cout << "% of optimal that the GA produced is: ";
        cout << fixed << setprecision(2) << ((mutate.GetMinCost() / bruteForce.GetMinCost()) * 100) << "%\n";
        free(t);
        free(z);
    }
    else
        cout << "Failed to open Text File." << endl;
}

MainMenu::~MainMenu()
{
    delete[] route;
}