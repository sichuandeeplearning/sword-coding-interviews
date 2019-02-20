//两个以排序的字符串a1和a2;
//将a2加入到a1中，是的a1也是以排序的

#include <bits/stdc++.h>

using namespace std;

void addS2S(string& a1, string& a2)
{
    int sz1 = a1.size();
    int sz2 = a2.size();

    a1.resize(sz1 + sz2);
    int i = sz1 - 1;
    int j = sz2 - 1;
    sz1 += sz2 - 1;

    while(sz1 >= 0)
    {
        if(j < 0)
            break;
        if(i < 0)
        {
            a1[sz1] = a2[j];
            --j;
            --sz1;
        }
        if(a1[i] > a2[j])
        {
            a1[sz1] = a1[i];
            --i;
            --sz1;
        }
        else
        {
            a1[sz1] = a2[j];
            --j;
            --sz1;
        }
    }

}

int main()
{
    string a1("acdtz");
    string a2("fhikmx");

    addS2S(a1, a2);

    cout << a1 << endl;

    return 0;
}

