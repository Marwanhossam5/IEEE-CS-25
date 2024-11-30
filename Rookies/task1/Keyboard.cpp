#include <iostream>

using namespace std;
int main()
{
    string text;
    string origin_text = "";
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char direction;
    cin >> direction >> text;
    for (int i = 0; i < text.size(); i++)
    {
        char currentChar = text[i];
        int pos = 0;

        while (keyboard[pos] != currentChar)
        {
            pos++;
        }
        if (direction == 'R')
        {
            origin_text += keyboard[pos - 1];
        }
        else
        {
            origin_text += keyboard[pos + 1];
        }
    }
    cout << origin_text;

    return 0;
}