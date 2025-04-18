#include <iostream>
#include <vector>
#include <math.h>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    vector<int> tape(10, 0);
    char state = 'A';
    int head = 5;

    for (int i = 0; i < (int)tape.size(); i++) {
        cout << tape[i];
    }
    cout << endl;

    while (true)
    {
        int symbol = 0;
        if (state == 'A')
        {
            if (symbol == 0)
            {
                tape[head] = 1;
                head += 1;
                state = 'B';
            }
        }
        if (state == 'A')
        {
            if (symbol == 1)
            {
                tape[head] = 1;
                head -= 1;
                state = 'B';
            }
        }
        if (state == 'B')
        {
            if (symbol == 0)
            {
                tape[head] = 1;
                head -= 1;
                state = 'A';
            }
        }
        if (state == 'B')
        {
            if (symbol == 1)
            {
                tape[head] = 1;
                head += 1;
                state = 'H';
                break;
            }
        }
        for (int i = 0; i < (int)tape.size(); i++) {
            cout << tape[i];
        }
        cout << endl;
        std::this_thread::sleep_for(2000ms);
    }

    return 0;
}