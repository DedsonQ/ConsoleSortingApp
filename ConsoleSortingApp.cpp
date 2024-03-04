#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;


void sort(int tab[], int n, int z) {
    int i, j, x;
    if (z == 1) {
        for (j = 0; j < n - 1; j++) {
            for (i = 0; i < n - j - 1; i++) {
                if (tab[i] > tab[i + 1]) {
                    x = tab[i];
                    tab[i] = tab[i + 1];
                    tab[i + 1] = x;
                }
            }
        }
    }
    else if (z == 2) {
        for (j = 0; j < n - 1; j++) {
            for (i = 0; i < n - j - 1; i++) {
                if (tab[i] < tab[i + 1]) {
                    x = tab[i];
                    tab[i] = tab[i + 1];
                    tab[i + 1] = x;
                }
            }
        }
    }
    else {
        cout << "Error: You have chosen wrong sorting type.";
    }
}


void higlow(int tab[], int& lowest, int& highest, int n) {
    int minn, maxn, i;
    lowest = tab[0];
    highest = tab[0];
    for (i = 0; i < n; i++) {
        if (lowest > tab[i]) {
            lowest = tab[i];
            minn = i;
        }
        else if (highest < tab[i]) {
            highest = tab[i];
            maxn = i;
        }
    }
}


int main()
{
    const int n = 10;
    int c, i, x, z, randomnumber, highest, lowest, maxnumber;
    int tab[n];
    srand(time(NULL));

    cout << "Choose a type for entering numbers:";
    cout << "\n1. Automatic 2. Manual\n";
    cin >> x;

    cout << "\nChoose a type of sorting:";
    cout << "\n1. Ascending 2. Descending\n";
    cin >> z;

    if (x == 1) {
        cout << "Write cap for sorting:\n";
        cin >> maxnumber;
        for (i = 0; i < n; i++) {
            randomnumber = rand() % maxnumber + 1;
            tab[i] = randomnumber;
        }
    }
    else if (x == 2) {
        cout << "Type in 10 numbers\n";
        for (i = 0; i < n; i++) {
            cin >> c;
            tab[i] = c;
        }
    }
    else {
        cout << "You have chosen wrong type of entering numbers.";
    }

    cout << "Before sorting:\n";

    for (i = 0; i < n; i++) {
        cout << tab[i] << ", ";
    }

    cout << "\nAfter sorting:\n";
    sort(tab, n, z);
    for (i = 0; i < n; i++) {
        cout << tab[i] << ", ";
    }

    higlow(tab, lowest, highest, n);
    cout << "\nHighest number: " << highest << "\n" << "Lowest number: " << lowest;
}
