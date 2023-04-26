#include <iostream>
#include <unistd.h>
#include <istream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

/*************************************************
 *  PROBLEM IN DECRYPTION *************
 * enc = ((strr[i]-key+235-524/4*54)%28)+'m';
 * ************************/


void ex();


void encrypt(char *str, string strr, char key){

    char *ptr = str;

    //cout<<strr;
    for (int i = 0; i < strr.size(); i++)
    {
        char res = (strr[i]-key+32-'z'-'x');/*temp*/
        str[i] = res;
    }
    

}

void decrypt(char *str, string strr, char key){

    char *ptr = str;

    //cout<<strr;
    for (int i = 0; i < strr.size(); i++)
    {
        char res = (strr[i]+key-32+'z'+'x');
        str[i] = res;
    }
    // cout<<endl<<str;

    string temp2;
    temp2 = str;
    // cout<<temp2;
    replace(temp2.begin(), temp2.end(), '`', ' ');
    strcpy(str, temp2.c_str());

}

void try_again();

int main(){
    cout << "\033[2J\033[1;1H";

    cout<<endl<<"\t\t\t\t|----------------------------|"<<endl;
    cout<<"\t\t\t\t|Encryption Decryption System|"<<endl;
    cout<<"\t\t\t\t|----------------------------|"<<endl<<endl<<endl;
    cout<<"  Choose 0ne :-"<<endl<<endl;
    cout<<"----1. Encrypt"<<endl;
    cout<<"----2. Decrypt"<<endl<<endl;
    cout<<"\t--->";

    int input;
    cin>>input;
    getchar();
    cout<<endl<<endl;

    string str;
    cout<<"Type your string"<<endl<<endl<<"  --> ";
    getline(cin, str);
    char main_str[str.length()+1];

    strcpy(main_str, str.c_str());

    if (input == 1){
        replace(str.begin(), str.end(), ' ', '`');
    }

    char key[50];
    cout<<endl<<"  Type Your key:-\t(key's length must be 1-4)"<<endl<<"  --> ";
    cin>>key;

    switch (input)
    {
    case 1:
        encrypt(main_str, str, *key);
        replace(str.begin(), str.end(), '`', ' ');
        cout<<endl<<"  Your String Was        : "<<str;
        cout<<endl<<"  Your ENCRYPTED String  : "<<main_str;
        cout<<endl<<"  Your KEY               : "<<key;
        ex();
    case 2:
        decrypt(main_str, str, *key);
        cout<<endl<<"  Your String Was         : "<<str;
        cout<<endl<<"  Your DECCRYPTED String  : "<<main_str;
        cout<<endl<<"  Your KEY                : "<<key;
        ex();
    default:
        try_again();
        break;
    }
    cout<<endl;
    return 0;
}

void try_again(){
    cout<<endl<<"\t\t*** INVALID INPUT ***"<<endl;
    cout<<"\t\tTRY AGAIN"<<endl;
    sleep(1);
    main();
}

void ex(){
    cout<<endl<<endl<<"\t\t -----| PRESS 0 TO EXIT OR 1 To Continue |----"<<endl<<endl<<"\t\t >>>>>  ";
    char to_do;
    cin>>to_do;

    if (to_do == '0'){
        exit(0);
    }else{
        main();
    }

}
