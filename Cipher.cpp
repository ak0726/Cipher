//
//  main.cpp
//  cipher
//
//  Created by Ayush Khurana on 9/14/23.
//
//
#include <iostream>
#include<string>
// #include<conio.h>
#include<vector>
#include<stdlib.h>
#include<map>
#pragma GCC target("c++17")

using namespace std;

string cipher()
{
    string s;
    cout<<"Enter your string"<<endl;
    cin>>s;
    int shift;
    cout<<"Enter your shift value"<<endl;
    cin>>shift;
    for (int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i]))
        {
            char base = islower(s[i]) ? 'a' : 'A';
            s[i] = ((s[i] - base + shift) % 26) + base;
        }
    }
    return s;
}

 string monoalphabetic()
 {
     string s;
     cout<<"Enter your string"<<endl;
     cin>>s;
     string plaintextAlphabet = "abcdefghijklmnopqrstuvwxyz";
     string ciphertextAlphabet = "mnbvcxzasdfghjklpoiuytrewq";
     for (int i = 0; i < s.size(); i++)
     {
         if (isalpha(s[i]))
         {
             
             size_t index = plaintextAlphabet.find(tolower(s[i]));
             if (index != string::npos)
             {
                 s[i] = islower(s[i]) ? tolower(ciphertextAlphabet[index]):toupper(ciphertextAlphabet[index]);
             }
         }
     }
     return s;
 }

 string homophonic()
 {
     string s;
     cout<<"Enter your string"<<endl;
     cin>>s;
     string res="";
     map<char, vector<string>> substitutionMap;
     substitutionMap['a'] = {"01", "02"};
     substitutionMap['b'] = {"03", "04"};
     
     substitutionMap['c'] = {"05", "06"};
     substitutionMap['d'] = {"07", "08"};
     
     substitutionMap['e'] = {"09", "10"};
     substitutionMap['f'] = {"11", "12"};
     
     substitutionMap['g'] = {"13", "14"};
     substitutionMap['h'] = {"15", "16"};
     
     substitutionMap['i'] = {"17", "18"};
     substitutionMap['j'] = {"19", "20"};
     
     substitutionMap['k'] = {"21", "22"};
     substitutionMap['l'] = {"23", "24"};
     
     substitutionMap['m'] = {"25", "26"};
     substitutionMap['n'] = {"27", "28"};
     
     substitutionMap['o'] = {"29", "30"};
     substitutionMap['p'] = {"31", "32"};
     
     substitutionMap['q'] = {"33", "34"};
     substitutionMap['r'] = {"35", "36"};
     
     substitutionMap['s'] = {"27", "28"};
     substitutionMap['t'] = {"29", "40"};
     
     substitutionMap['u'] = {"41", "42"};
     substitutionMap['v'] = {"43", "44"};
     
     substitutionMap['w'] = {"45", "46"};
     substitutionMap['x'] = {"47", "48"};
     
     substitutionMap['y'] = {"49", "50"};
     substitutionMap['z'] = {"51", "52"};
     for (int i = 0; i < s.size(); i++)
     {
         if (isalpha(s[i]))
         {
             char letter = tolower(s[i]);
             if (substitutionMap.count(letter) > 0)
             {
                 int index = rand() % substitutionMap[letter].size();
                 res += substitutionMap[letter][index];
             }
         }
         else
         {
             res += s[i];
         }
     }
     return res;
 }

 string TripleDES()
 {
     string s;
     cout<<"Enter your string"<<endl;
     cin>>s;
     int key1;
     int key2;
     int key3;
     cout<<"Enter Key1"<<endl;
     cin>>key1;
     cout<<"Enter Key2"<<endl;
     cin>>key2;
     cout<<"Enter Key3"<<endl;
     cin>>key3;
     for (int i = 0; i < s.size(); i++)
     {
         if(isalpha(s[i]))
         {
             char base = islower(s[i]) ? 'a' : 'A';
             s[i] = ((s[i] - base + key1) % 26) + base;
         }
     }
     for (int i = 0; i < s.size(); i++)
     {
         if(isalpha(s[i]))
         {
             char base = islower(s[i]) ? 'a' : 'A';
             s[i] = ((s[i] - base + key2) % 26) + base;
         }
     }
     for (int i = 0; i < s.size(); i++)
     {
         if(isalpha(s[i]))
         {
             char base = islower(s[i]) ? 'a' : 'A';
             s[i] = ((s[i] - base + key3) % 26) + base;
         }
     }
     return s;
 }

 string Polyalphabetic()
 {
     string s;
     cout<<"Enter your string"<<endl;
     cin>>s;
     string res="";
     int i=3;
     for(auto c:s)
     {
         if (isalpha(c))
         {
             char base = islower(c) ? 'a' : 'A';
             char encryptedChar = ((c - base + i) % 26) + base;
             i++;
             res += encryptedChar;
         }
         else
         {
             res+=c;
         }
     }
     return res;
 }

int main() {
    int sel=0;
    help:
    cout<<"0. Exit"<<endl;
    cout<<"1. Caesar Cipher"<<endl;
    cout<<"2. Monoalphabetic Cipher"<<endl;
    cout<<"3. Homophonic Substitution Cipher"<<endl;
    cout<<"4. Triple DES Cipher"<<endl;
    cout<<"5. Polyalphabetic Substitution Cipher"<<endl;
    cout<<"Enter your option: "<<endl;
    while(true)
    {
        cin>>sel;
        if(sel==0) return 0;
        if(sel==1)
        {
            cout<<cipher()<<endl;
            // cout << "\x1b[2J\x1b[1;1H" << flush;
            cout<<"Press any key to continue: "<<endl;
            // char ch;
            // cin>>ch;
            cin.ignore();
            cin.get();
            // getch();
            system("clear");
            goto help;
        }
        if(sel==2)
        {
            cout<<monoalphabetic()<<endl;
            // cout << "\x1b[2J\x1b[1;1H" << flush;
            cout<<"Press any key to continue: "<<endl;
            // char ch;
            // cin>>ch;
            cin.ignore();
            cin.get();
            // getch();
            system("clear");
            goto help;
        }
        if(sel==3)
        {
            cout<<homophonic()<<endl;
            // cout << "\x1b[2J\x1b[1;1H" << flush;
            // cout << "\x1b[2J\x1b[1;1H" << flush;
            cout<<"Press any key to continue: "<<endl;
            cin.ignore();
            cin.get();
            // char ch;
            // cin>>ch;
            // getch();
            system("clear");
            goto help;
        }
         if(sel==4)
         {
             cout<<TripleDES()<<endl;
             // cout << "\x1b[2J\x1b[1;1H" << flush;
             cout<<"Press any key to continue: "<<endl;
             // char ch;
             // cin>>ch;
             cin.ignore();
            cin.get();
             system("clear");
             goto help;
         }
         if(sel==5)
         {
             cout<<Polyalphabetic()<<endl;
             // cout << "\x1b[2J\x1b[1;1H" << flush;
             cout<<"Press any key to continue: "<<endl;
            //  char ch;
            // cin>>ch;
             cin.ignore();
            cin.get();
            // getch();
             system("clear");
             goto help;
         }
    }
    return 0;
}
