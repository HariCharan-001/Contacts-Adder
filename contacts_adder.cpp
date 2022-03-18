#include <bits/stdc++.h>
using namespace std;
#define cout ou
#define cin inn

ofstream ou("contacts_clubbed_final.vcf");
ifstream inn("contacts_input.csv");

void write_to_VCF(string name, string number)
{
    cout<<"BEGIN:VCARD\nVERSION:2.1\n";
    cout<<"N:"<<name<<endl;
    cout<<"TEL;CELL;VOICE:"<<number<<endl;
    cout<<"END:VCARD\n\n";
}

int main()
{
    string s;
    while(1)
    {
        getline(cin, s);
        
        vector<string> v;
        stringstream ss(s);
 
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }

        string name = v[0] + "  " + v[1];
        string number = v[2];
        write_to_VCF(name, number);

        if(inn.eof()) break;
    }
}