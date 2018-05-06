#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool safe(vector<string> & brd, int size, int x, int y)
{
    assert (x>=0 && x<size);
    assert (y>=0 && y<size);

    char c;

    // check left
    for (int p=x-1; p>=0; --p)
    {
        c = brd[y][p];
        if (c == 'O')
            return false;
        if (c == 'X')
            break;
    }

    // check right
    for (int p=x+1; p<size; ++p)
    {
        c = brd[y][p];
        if (c == 'O')
            return false;
        if (c == 'X')
            break;
    }

   // check top
    for (int p=y-1; p>=0; --p)
    {
        c = brd[p][x];
        if (c == 'O')
            return false;
        if (c == 'X')
            break;
    }

    // check bottom
    for (int p=y+1; p<size; ++p)
    {
        c = brd[p][x];
        if (c == 'O')
            return false;
        if (c == 'X')
            break;
    }
    return true;
}

void check(vector<string> &brd, int size, int num, int & max)
{
    for (int y=0; y<size; ++y)
    {
        for (int x=0; x<size; ++x)
        {
            if (brd[y][x] == '.' && safe(brd, size, x, y))
            {
                brd[y][x] = 'O';
                ++num;
                if (num>max)
                    max=num;
                check(brd, size, num, max);
                --num;
                brd[y][x] = '.';
            }
        }
    }
}

int main()
{
    vector<string> brd;
    int size;
    while(true)
    {
        cin >> size;
        if (!size) break;

        for (int i=0; i<size; ++i)
        {
            string ln;
            cin >> ln;
            brd.push_back(ln);

        }
        int max=0;
        check(brd, size, 0, max);
        cout << max << endl;
        brd.clear();
    }
    return 0;
}
