#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {

    int n;
    cout<<"Enter number of variables : ";
    cin>>n;

    vector<char> variables;

    cout<<"Enter variables : ";

    while (variables.size()<n){
        char c;
        cin>>c;
        /*
        for (int i = 0 ; i < variables.size(); i++) {
            if (variables[i] == c) {
                break;
            }
            variables.push_back(c);
        }
        */
        variables.push_back(c);
    }

    cout<<endl<<"Assumption: "<<endl;
    cout<<"Col - ";
    for (int i = (n+1)/2 - 1; i >= 0 ; i--){
        cout<<variables[i];
    }
    cout<<endl;

    cout<<"Row - ";
    for (int i = n-1; i >= (n+1)/2; i--){
        cout<<variables[i];
    }
    cout<<endl<<endl;
    cout<<"Enter K-Map:"<<endl;

    int Kmap[(int)pow(2,(n+1)/2)][(int)pow(2,n/2)];
    string expn;

    for (int i = 0; i < pow(2,(n+1)/2); i++) {
        for (int j = 0; j < pow(2,n/2); j++) {
            cin>>Kmap[i][j];
        }
    }

    for (int i = 0; i < (int)pow(2,n); i++) {
        int a = i & ((int)pow(2,(n+1)/2)-1);
        int b = i>>((n+1)/2);

        int x = a ^ (a>>1);
        int y = b ^ (b>>1);

        if (Kmap[x][y] == true) {
            int vl = i;
            if (expn.length()!=0){
                expn = expn + " + ";
            }
            for (int j = 0; j < variables.size(); j++) {
                expn = expn + variables[j];
                if ((vl&1)==0){
                    expn = expn + '\'';
                }
                vl=vl>>1;
            }
        }
    }

    cout<<endl<<"Expression : "<<expn<<endl;

}

/* Anikesh Parashar - 21114012*/