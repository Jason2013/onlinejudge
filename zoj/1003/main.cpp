#include <iostream>
#include <set>

using namespace std;

typedef long long lint;

void find2(int val, lint num, set<int> & s, const set<int> & cmp, bool & find_w);

void find(int val, lint num, lint num2, set<int> & s, bool & find_c, bool & find_w)
{
    if (find_c && find_w)
        return;

    if (num == 1)
    {
        find_c = true;
        set<int> s2;
        find2(1, num2, s2, s, find_w);
        return;
    }
    if (val > num)
        return;

    while (val <= 100)
    {
        if (num % val ==0)
        {
            // use val
            s.insert (val);
            find(val+1, num/val, num2, s, find_c, find_w);
            s.erase(val);

            // skip val
            find(val+1, num, num2, s, find_c, find_w);

            return ;
        }
        ++val;
    }
}

void find2(int val, lint num, set<int> & s, const set<int> & cmp, bool & find_w)
{
    if (find_w)
        return;

    if (num == 1)
    {
        find_w = true;
        return;
    }
    if (val > num)
        return;

    while (val <= 100)
    {
        if (num % val ==0 && (cmp.find(val) == cmp.end()))
        {
            // use val
            s.insert (val);
            find2(val+1, num/val, s, cmp, find_w);
            s.erase(val);

            // skip val
            find2(val+1, num, s, cmp, find_w);

            return ;
        }
        ++val;
    }
}

void check(lint val_c, lint val_w, bool & find_c, bool & find_w)
{
    set<int> s;
    find(1, val_c, val_w, s, find_c, find_w);
}

int main()
{
    int ai, bi;
    int a, b;

    while (cin >> ai >> bi)
    {
        a = std::min (ai, bi);
        b = std::max(ai, bi);

        bool find_c = false, find_w = false;

        check(a, b, find_c, find_w);

        if (find_c && !find_w)
            cout << a << endl;
        else
            cout << b << endl;
    }

    return 0;
}
