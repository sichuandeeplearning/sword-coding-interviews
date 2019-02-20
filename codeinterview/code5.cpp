//面试题5，解法二
//在原来的基础上进行修改
//第一遍扫描统计空格的数量,第二遍扫描移动字符
//时间复杂度为O(n),空间复杂度为O(1)

#include <bits/stdc++.h>

using namespace std;

void placespace(string& s1)
{
    int count = 0;
    size_t sz = s1.size();
    for(size_t i = 0; i < sz; ++i)
    {
        if(isspace(s1[i]))
        {
            ++count;
        }
    }
    int i = sz - 1;
    sz = sz + count * 2;
    s1.resize(sz);
    --sz;
    for(; i >= 0; --i)
    {
        if(s1[i] == s1[sz])
            break;
        if(isspace(s1[i]))
        {
            s1[sz] = '0';
            --sz;
            s1[sz] = '2';
            --sz;
            s1[sz] = '%';
            --sz;
        }
        else
        {
            s1[sz] = s1[i];
            --sz;
        }
    }
}


int main()
{
    string s1("We are happy");
    placespace(s1);

    cout << s1 << endl;

    return 0;
}

