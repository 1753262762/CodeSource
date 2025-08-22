#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
int Next[maxn];
void Get_next();
void Kmp(char *source, char *pattern) // 源串 模串
{
    int len_pattern, len_source;
    len_source = strlen(source), len_pattern = strlen(pattern);
    Get_next();
    int i = 0, j = 0;
    while (i < len_source and j < len_pattern)
    {
        if (source[i] == pattern[j] or j == -1)
        {
            ++i, ++j;
        }
        else
        {
            j = Next[j];
        }
    }
}
void Get_Kmp(char *source, char *pattern) // 源串 模串
{
    int source_len, pattern_len;
    source_len = strlen(source), pattern_len = strlen(pattern);
    int i = 0, j = -1;
    while (i < source_len - 1)
    {
        if (source[i] == pattern[j] or j == -1)
        {
            i++, j++;
            Next[j] = j;
        }
        else
        {
            j = Next[j];
        }
    }
    return;
}