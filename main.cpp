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
    vector<int>::iterator maxIt;
    string line;
    int i, j, max, index;

    while (getline(cin, line))
    {
        istringstream ss(line);
        ss >> i >> j;
        for (int it = i; it <= j; it++)
        {
            numbersCycleLength.push_back(getCycleLength(it));
        }

        maxIt = max_element(numbersCycleLength.begin(), numbersCycleLength.end());
        index = distance(numbersCycleLength.begin(), maxIt);
        max = numbersCycleLength[index];
        cout << i << " " << j << " " << max << endl;
        numbersCycleLength.clear();
    }

    return EXIT_SUCCESS;
}

int getCycleLength(int n)
{
    int count = 0;
    while (true)
    {
        count++;
        if (n == 1)
        {
            break;
        }
        else
        {
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = 3 * n + 1;
            }
        }
    }
    return count;
}