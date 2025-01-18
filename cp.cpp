#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<char, bool> alphabetMap;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        alphabetMap[c] = false;
    }
    // int a;
    // cin >> a;
    string s;
    cin >> s;
    // convert the string to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (int i = 0; i < s.length(); i++)
    {
        alphabetMap[s[i]] = true;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (alphabetMap[c] == false)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}