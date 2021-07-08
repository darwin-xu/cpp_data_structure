#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <typeinfo>

using namespace std;

void swap_element(string* p1, string* p2)
{
    string x = *p1;
    *p1      = *p2;
    *p2      = x;
}

int compare_string(string str1, string str2, int num)
{
    if (num == 4)
    {
        return 0;
    }
    else
    {
        if ((char)str1[num] > (char)str2[num])
        {
            return 1;
        }
        else if ((char)str1[num] < (char)str2[num])
        {
            return 0;
        }
        else
        {
            return compare_string(str1, str2, num + 1);
        }
    }
}

/*
 * Return: -1 if str1 < str2
 *          0 if str1 = str2
 *          1 if str1 > str2
 */
int compare_string2(const string& str1, const string& str2)
{
    int l = std::min(str1.length(), str2.length());
    for (int i = 0; i < l; ++i)
    {
        if (str1[i] < str2[i])
            return -1;
        else if ((str1[i] == str2[i]))
            return 0;
        else
            return 1;
    }
}

void print_string(string str[], int strlen)
{
    for (int i = 0; i < strlen; i++)
    {
        cout << str[i] << endl;
    }
}

string getRandomStr()
{
    srand((unsigned)time(NULL));
    string ans;
    for (int i = 0; i < 20; i++)
    {
        ans += 'a' + rand() % 26;
    }
    return ans;
}

void input_string(string list[], string str)
{
    char carry[5];
    carry[4] = (char)0;
    for (int i = 0; i < 5; i++)
    {
        carry[0] = str[i * 4 + 0];
        carry[1] = str[i * 4 + 1];
        carry[2] = str[i * 4 + 2];
        carry[3] = str[i * 4 + 3];
        list[i]  = carry;
    }
}

void sort_string(string str[])
{
    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (compare_string(str[j], str[j + 1], 0) == 1)
                swap_element(&str[j], &str[j + 1]);
        }
    }
}

int main()
{
    string str = getRandomStr();
    cout << str << endl;
    string list[10];
    input_string(list, str);

    cout << "ORIGIN: " << endl;
    print_string(list, 5);

    sort_string(list);

    cout << "MATCHED:" << endl;
    print_string(list, 5);

    std::cout << "=======" << std::endl;
    std::cout << compare_string("1234", "1235", 0) << std::endl;
    std::cout << compare_string("1234", "1234", 0) << std::endl;
    std::cout << compare_string("1234", "1233", 0) << std::endl;

    return 0;
}
