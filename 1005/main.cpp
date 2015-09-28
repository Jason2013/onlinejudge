#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
    int ge, gi;
    int k[5];
};

student students[40000];
int student_no[40000];

vector<int> schools[100];
unsigned int school_quota[100];

int n,m,k;

void get_school_quota(int n)
{
    for (int i=0; i<n; ++i)
    {
        scanf("%d", &school_quota[i]);
        schools[i].clear();
    }

}

void get_students(int n, int k)
{
    for (int i=0; i<n; ++i)
    {
        scanf("%d %d", &students[i].ge, &students[i].gi);
        for (int j=0; j<k; ++j)
            scanf("%d", &students[i].k[j]);

        student_no[i]=i;
    }
}

bool compare(int a, int b)
{
    int age, bge, asum, bsum;

    age = students[a].ge;
    bge = students[b].ge;

    asum = age + students[a].gi;
    bsum = bge + students[b].gi;

    return asum > bsum || (asum == bsum && age > bge);
//
//    return (students[a].ge + students[a].gi > students[b].ge + students[b].gi) ||
//     (students[a].ge > students[b].ge);
}

bool student_equal(int a, int b)
{
    const student & sa = students[a];
    const student & sb = students[b];
    return sa.ge == sb.ge &&  sa.gi == sb.gi;
}

void admit_school(int student_no)
{
    for (int i=0; i<k; ++i)
    {
        int school_no = students[student_no].k[i];
        vector<int> & school = schools[school_no];
        if (school.size() < school_quota[school_no] ||
                (school.size()>0 && student_equal(school.back(), student_no)))
        {
            school.push_back(student_no);
            break;
        }
    }
}

inline void output_num(int n)
{
    printf(" %d", n);
}

void output_school(const vector<int> & school)
{
    vector<int>::const_iterator it = school.begin();
    if (it != school.end())
    {
        printf("%d", *it);
        ++it;
        for_each(it, school.end(),output_num);
    }
    printf("\n");
}

void sort_school(vector<int> & school)
{
    sort(school.begin(), school.end());
}

void admit(int n, int m, int k)
{
    sort(student_no, student_no+n, compare);
    for_each(student_no, student_no+n, admit_school);
    for_each(schools, schools+m, sort_school);
    for_each(schools, schools+m, output_school);
}

int main()
{
    while (scanf("%d %d %d", &n, &m, &k) != EOF)
    {
        get_school_quota(m);
        get_students(n,k);
        admit(n,m,k);
    }
    return 0;
}
