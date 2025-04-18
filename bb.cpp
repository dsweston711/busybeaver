#include <iostream>
#include <vector>
#include <math.h>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    vector<int> tape(100, 0);
    char state = 'A';
    int head = 50;
    int sum = 0;

    for (int i = 0; i < (int)tape.size(); i++)
    {
        cout << tape[i];
    }
    cout << endl;

    while (true)
    {
        int symbol = tape[head];
        if (state == 'A')
        {
            if (symbol == 0)
            {
                tape[head] = 1;
                head += 1;
                state = 'B';
            }
            else if (symbol == 1)
            {
                tape[head] = 1;
                head -= 1;
                state = 'B';
            }
        }
        else if (state == 'B')
        {
            if (symbol == 0)
            {
                tape[head] = 1;
                head -= 1;
                state = 'A';
            }
            else if (symbol == 1)
            {
                tape[head] = 1;
                head += 1;
                state = 'H';
            }
        }

        // Display the tape
        for (int i = 0; i < (int)tape.size(); i++)
        {
            if (i == head)
                cout << "[" << tape[i] << "]";
            else
                cout << " " << tape[i] << " ";
        }
        cout << "\nHead at: " << head << ", State: " << state << endl;

        if (state == 'H')
            break;
        this_thread::sleep_for(1000ms);
    }

    for (int i = 0; i < (int)tape.size(); i++)
    {
        if (tape[i] == 1)
        {
            sum++;
        }
    }

    cout << "Total numer of 1s: " << sum << endl;

    return 0;
}