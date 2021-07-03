#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <typeinfo>

using namespace std;

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

void remove_element(string str[], int length, int num)
{
    for (int i = 0; i < length - num - 1; i++)
    {
        str[num + i] = str[num + i + 1];
        cout << str[num + i] << endl;
    }
    str[length - 1] = "";
}

int main()
{
    // int *p;
    string str = getRandomStr();
    cout << str << endl;
    string list[10];
    input_string(list, str);
    cout << "ORIGIN: " << endl;
    print_string(list, 5);
    cout << "MATCHED" << endl;
    string a[5];
    a[0] = "aaa";
    a[1] = "bbb";
    a[2] = "ccc";
    // p = &a;
    remove_element(a, 5, 0);
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}