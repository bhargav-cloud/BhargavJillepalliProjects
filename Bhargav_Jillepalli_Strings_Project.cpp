// Bhargav Jillepalli
// Lab #7 - CS 115 Section 002
// April 9, 2021

#include <iostream>

#include <string>

#include<cstring>

using namespace std;
int main()

{

string str;

int count_char[26]={0};

int count_words=1;

cout << "Enter a Line of Text: ";

getline (cin, str);

for(int i=0;str[i]!='\0';i++)

{

str[i]=toupper(str[i]);

}

for(int i=0;str[i]!='\0';i++)

{

if(str[i]>=65&&str[i]<=90)

count_char[str[i]-65]++;

else if(str[i]=='.'||str[i]==','||str[i]==' '||str[i]=='\n')

{

if(str[i+1]!='.'&&str[i+1]!=','&&str[i+1]!=' '&&str[i+1]!='\n')
count_words++;
}

}

cout<<"Words: "<<count_words<<endl;

cout<<"Letters:"<<endl;

for(int i=0;i<26;i++)

{

if(count_char[i]>0)

{

char c=(char)(i+65);

cout<<c<<" "<<count_char[i]<<endl;

}

}

return 0;

}