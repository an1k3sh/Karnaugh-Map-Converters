/*
No spaces allowed
Generating K-Map from the SOP form of the expression
*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<char> count_variables(string boolExpn) {

    vector<char> variables;

    for (int i = 0; i < boolExpn.length(); i++){
        if ((boolExpn[i] >= 'A' && boolExpn[i] <= 'Z') || (boolExpn[i] >= 'a' && boolExpn[i] <= 'z')) {
            bool counted = false;
            for (int j = 0; j < variables.size(); j++){
                if (boolExpn[i] == variables[j]) {
                    counted = true;
                    break;
                }
            }
            if (!counted) {
                variables.push_back(boolExpn[i]);
            }
        }
    }

    return variables;

}

map<char, int> vector_to_map(vector<char> variables) {
    
    map<char, int> var_map;

    for (int i = 0; i<variables.size(); i++) {
        var_map[variables[i]]=i;
    }

    return var_map;

}

int main() {

    int n; //Number of variables
    string expn; //Expression

    cout<<"Enter expression : ";
    cin>>expn;

    vector<char> variables = count_variables(expn);
    n = variables.size();

    map<char, int> varMap = vector_to_map(variables);
    bool truth_array[(int)pow(2,n)];

    for (int i = 0; i < expn.length(); i++) {

        map<char, bool> term;

        while (expn[i]!='+' && i<expn.length()) {
            
            if ((expn[i]>='A' && expn[i]<='Z')||(expn[i]>='a' && expn[i]<='z')) {
                if (i!=expn.length()-1 && expn[i+1]=='\''){
                    term[expn[i]] = 0;
                }
                else {
                    term[expn[i]] = 1;
                }
            }

            i++;

        }

        for (int i = 0; i < (int)pow(2,n); i++) {
            bool match = true;
            for (auto j = term.begin(); j != term.end(); j++) {
                match &= (((i>>(varMap[j->first]))&1)==(j->second));
            }
            truth_array[i]|= match;
        }
        
    }

    // for (int i = 0; i < pow(2,n); i++) {
    //     cout<<truth_array[i]<<" ";
    // }
    // cout<<endl;
    
    int Kmap[(int)pow(2,(n+1)/2)][(int)pow(2,n/2)];

    for (int i = 0; i < (int)pow(2,(n+1)/2); i++) {
        for (int j = 0; j < (int)pow(2,n/2); j++) {
            Kmap[i][j] = truth_array[(i^(i>>1)) + (j^(j>>1))*(int)pow(2,(n+1)/2)];
            cout<<Kmap[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Col - ";
    for (int i = 0; i < (n+1)/2 ; i++){
        cout<<variables[i];
    }
    cout<<endl;

    cout<<"Row - ";
    for (int i = (n+1)/2; i < n ; i++){
        cout<<variables[i];
    }
    cout<<endl;

}

/* Anikesh Parashar - 21114012*/