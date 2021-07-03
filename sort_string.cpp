#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <typeinfo>

using namespace std;

void print_string(string str[])
{
    for(int i =0;i<str.length();i++)
    {
        cout<<str[i]<<endl;
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

void input_string(string list[],string str)
{
    char carry[5];
    carry[4]=(char)0;
    for (int i = 0; i < 5; i++)
    {
        carry[0]=str[i*4+0];
        carry[1]=str[i*4+1];
        carry[2]=str[i*4+2];
        carry[3]=str[i*4+3];
        list[i]=carry;
    }
}

void remove_element(string str,int num)
{
    int strlen = 0;
    strlen = str.length();
    for(int i=0;i<strlen-num-1;i++)
    {
        str[num+i]=str[num+i+1];
    }
    str[strlen-1]=(char)0;
}















int main()
{
    string str=getRandomStr();
    cout<<str<<endl;
    string list[10];
    input_string(list, str);
    cout<<"ORIGIN: "<<endl;
    print_string(list);
    cout<<"MATCHED"<<endl;
    string a="abc";
    remove_element(a,0);
    print_string(a);
    return 0;
}