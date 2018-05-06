#include <cstdio>
using namespace std;

char buf[1000000];

struct state
{
    int len;
    char c[2];
    int next[2];
    unsigned n;
};

state states[5] =
{
    {
        2,{'o', 'z'}, {0, 1}, 0
    },
    {
        1,{'o', '\0'}, {2, -1}, 0
    },
    {
        2,{'o', 'j'}, {2, 3}, 0
    },
    {
        1,{'o', '\0'}, {3, -1}, 0
    }
};

void init_states()
{
    for (int i=0; i<=4; ++i)
    {
        states[i].n = 0;
    }
}

int run_machine(int cur, char c)
{
    state & s = states[cur];
    for (int i=0; i<s.len; ++i)
    {
        if (s.c[i] == c)
        {
            if (c == 'o') ++s.n;
            return s.next[i];
        }
    }
    return -1;
}

bool judge(const char * s)
{
    init_states();
    int cur = 0;
    while (*s != '\0')
    {
        cur = run_machine(cur, *s);
        if (cur == -1)
            return false;
        ++s;
    }
    return cur == 3 && states[0].n * (states[2].n+1) == states[3].n;
}

int main()
{
    while (scanf("%s", buf) != EOF)
    {
        printf("%s\n", judge(buf) ? "Accepted" : "Wrong Answer");
    }
    return 0;
}
