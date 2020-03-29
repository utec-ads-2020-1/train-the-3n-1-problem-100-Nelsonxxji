#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int getCycleLength(int n);

int main()
{
    vector<int> numbersCycleLength;
    string line;
    int i, j, max;

    while (getline(cin, line))
    {
        istringstream ss(line);
        ss >> i >> j;
        if (i < j)
        {
            for (int it = i; it <= j; it++)
            {
                numbersCycleLength.push_back(getCycleLength(it));
            }
        }
        else
        {
            for (int it = j; it <= i; it++)
            {
                numbersCycleLength.push_back(getCycleLength(it));
            }
        }

        max = *max_element(numbersCycleLength.begin(), numbersCycleLength.end());
        cout << i << " " << j << " " << max << endl;
        numbersCycleLength.clear();
    }

    return EXIT_SUCCESS;
}

int getCycleLength(int n)
{
    int count = 1;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        count++;
    }
    return count;
}