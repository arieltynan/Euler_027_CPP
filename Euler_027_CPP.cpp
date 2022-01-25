// Euler_027_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Quadratic Primes
// Started 25 Jan 2022
// Solved 25 Jan 2022

#include <iostream>
#include <vector>

using namespace std;

// binary search
bool searchForPrime(vector<int> primes, const int target)
{
    int size = primes.size();
    int first = 0;
    int last = size - 1;

    while (first <= last)
    {
        int mid = (first + last) / 2;
        int midValue = primes[mid];

        if (target == midValue)
            return true;

        else if (target < midValue)
            last = mid - 1;

        else
            first = mid + 1;

    } //end while
    return false;
}

int main()
{
    // Prime generator taken from 035
    vector<int> primes;
    int num = 10000; //primes less than num
    primes.push_back(2);
    for (int i = 3; i < num; i++)
    {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
        {
            if (i % primes[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.push_back(i);
            //cout << i << " ";
        }
    } // end for loop, prime search

    // Iterate through combinations of a,b
    bool isPrime = true; // checks if output is in list of primes
    int nMax = 0, aMax = 0, bMax = 0;
    for (int a = -1000; a < 1; a++) // iterated through 0 < a < 1000, max is 41
    {
        for (int b = -1000; b < 1000; b++)
        {
            int n = 0; // number of times n is in primes
            while (searchForPrime(primes, n * n + a * n + b)) // while solution is prime for changing n
                n++;

            if (n > nMax) // sets max 
            {
                nMax = n;
                aMax = a;
                bMax = b;
            }
        } // end for loop b
    } // end for loop a

    // cout << "nMax: " << nMax << " aMax: " << aMax << " bMax: " << bMax << endl;
    cout << "Answer: " << aMax * bMax;
} // end int main

// Steps
// Create vector list of primes
// iterate through combinations of a/b
// Check if output is in list of primes
// Count successful outputs
// Send new max to max variable
// Multiply final max positions