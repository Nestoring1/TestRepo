#include <iostream>
#include <windows.h>

using namespace std;

///--------BUGS--------
/**     TO-DO
 *
 *  #1 Game does not start.
 *  #2 If player 1 is the last to pick, he cannot win.
 *  #3 Number of sticks after player 2 does not correspond to the number of sticks left.
 *
 *  NOTE: You can find the bug by their corresponding number
 *  in the following code.
 */


int main()
{
    ///The following two lines are only for color effects in code
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(screen, 14);

    /// Bug #1 found with in the next 5 lines
    cout << "Welcome to NIM!" << endl;
    bool playing = false;
    int move, numSticks = 16;

    cout << "Current game looks like this:" << endl;
    cout << endl;
    for (int i = 0; i < numSticks; i++)
    {
        cout << "| ";
    }
    cout << endl;
    cout << endl;

    ///Game starts after the following condition is tested
    while ( playing )
    {
        SetConsoleTextAttribute(screen, 12);
        cout << "Player 1, it's your turn!" << endl;
        cin >> move;
        cout << endl;

        /// Bug #2 found with in the next 10 lines
        while (move < 1 || move > 3 || move >= numSticks)
        {
            cout << "Invalid number, please try again: " << endl;
            cin >> move;
            cout << endl;
        }

        numSticks -= move;
        for (int i = 0; i < numSticks; i++)
        {
            cout << "| ";
        }
        cout << endl;

        if (numSticks == 0)
        {
            cout << "You've won Player 1!" << endl;
            break;
        }

        SetConsoleTextAttribute(screen, 11);
        cout << "Player 2, it's your turn!" << endl;
        cin >> move;
        cout << endl;

        while (move < 1 || move > 3 || move > numSticks)
        {
            cout << "Invalid number, please try again: " << endl;
            cin >> move;
            cout << endl;
        }
        numSticks -= move;
        /// Bug #3 found with in the next 15 lines
        for (int i = 0; i <= numSticks; i++)
        {
            cout << "| ";
        }
        cout << endl;

        if (numSticks == 0)
        {
            cout << "You've won Player 2!" << endl;
            break;
        }
    }
    SetConsoleTextAttribute(screen, 7);
    return 0;
}

