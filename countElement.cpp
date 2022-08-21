#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAX 25;

int countElement(string chem, int c, vector <string>& li){
    string str;
    if (chem.length() == 0)
    {
        return c;
    }
    if (isupper(chem[0])){
        str.append(1,chem[0]);
        li.push_back(str);
        return countElement(chem.substr(1), c+1, li);
    }
    else if (islower(chem[0])) {
        str.append(1,chem[0]);
        li.back() = li.back() + str;
        return countElement(chem.substr(1), c, li);
    }
    else{
        return countElement(chem.substr(1), c, li);
    }
}


int main(void)
{
    string cheFomula;
    int count = 0;
    vector <string> answer;
    set <string> myset;
    cout << "Enter a Chemical formula: ";
    getline(cin, cheFomula);
    //cheFomula = "NaHCO3";
    if (cheFomula.length() > 25){
        cout << "Invalid Length" << endl;
        return 1;
    }
    countElement(cheFomula, count, answer);
    for (auto i = answer.begin(); i != answer.end(); ++i){
        //cout << *i << " ";
        myset.insert(*i);
    }
    for (auto it = myset.begin(); it != myset.end(); ++it)
        cout << ' ' << *it;
    cout << "\n";
    cout << myset.size() << endl;
    return 0;
}