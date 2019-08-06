/*
Programming Environment: C++ 11
IDE: Dev-C++ on Windows
Created by Rishabh Jain on 12/04/19.
*/



#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
struct node{
    string s;
    int f;
};
typedef struct node node;
bool compare(const node a, const node b){
    
    if(a.f!=b.f){
        return a.f<b.f;
    }
    else {
        int min1=a.s[0],min2=b.s[0];
        for(int i=1; i<a.s.length(); i++){
            if(min1>a.s[i]){
                min1=a.s[i];
            }
        }
        for(int i=1; i<b.s.length(); i++){
            if(min2>b.s[i]){
                min2=b.s[i];
            }
        }
        return min1<min2;
    }
}
int main(int argm, char* argv[]){
    string fname = argv[1];
    ifstream fil;
    ofstream fcode;
    ofstream fencodemsg;
    fil.open(fname);
    if(fil.fail()){
        cout<<"Failed to open input file"<<endl;
        exit(1);
    }
    fcode.open("code.txt");
    fencodemsg.open("encodemsg.txt");
    string b="";
    while(!fil.eof()){
        string line;
        getline(fil, line);
        b+=line;
    }
    map<char,node> lst;
    map<char,node> :: iterator itr1;
    vector<node> tree;
    vector<node> ::iterator itr2;
    for(int i=0; i<b.length(); i++){
        if(lst.count(b[i])>0){
            lst[b[i]].f++;
        } else {
            node a;
            a.s="";
            a.f=1;
            lst[b[i]]=a;
        }
        
    }
    fil.close();
    for(itr1=lst.begin(); itr1!=lst.end(); itr1++){
        node tmp2;
        tmp2.s=(*itr1).first;
        tmp2.f=(*itr1).second.f;
        tree.push_back(tmp2);
    }
    sort(tree.begin(),tree.end(), compare);
    while(tree.size()>1){
        node t3;
        string left = tree[0].s, right=tree[1].s;
        int min1 = left[0], min2 = right[0];
        for( int i = 1; i<left.length(); i++){
            if(min1>left[i]){
                min1=left[i];
            }
        }
        for(int j = 1; j<right.length(); j++){
            if(min2>right[j]){
                min2=right[j];
            }
        }
        if(min1>min2){
            string tmp = left;
            left=right;
            right=tmp;
        }
        t3.s = left + right;
        t3.f = tree[0].f + tree[1].f;
        tree.push_back(t3);
        for(int i=0; i<left.length(); i++){
            lst[left[i]].s="0"+lst[left[i]].s;
        }
        for(int j=0; j<right.length(); j++){
            lst[right[j]].s="1"+lst[right[j]].s;
        }
        tree.erase(tree.begin(), tree.begin()+2);
        sort(tree.begin(), tree.end(), compare);
    }
    double nbits=0;
    double nsymbols=0;
    for(int i=0; i<b.length();i++){
        nsymbols+=1;
        nbits+=lst[b[i]].s.length();
    }
    map <char,node> :: iterator itrr;
    for ( itrr = lst.begin() ; itrr!= lst.end() ; itrr++)
    {
        string nm;
        nm = (*itrr).first;
        if(nm==" ")
        {
            nm = "Space";
        }
        fcode<<nm<<": "<<(*itrr).second.s<<endl;
    }
    fcode<<"Ave = "<<setprecision(3)<<nbits/nsymbols<<" bits per symbol";
    string finalcode="";
    for(int i=0; i<b.length(); i++){
        finalcode+=lst[b[i]].s;
    }
    int n = 0;
    for(int i=0; i<finalcode.length(); i++){
        if(n==80){
            fencodemsg<<endl;
            n=0;
        }
        fencodemsg<<finalcode[i];
        n++;
        
    }
    fencodemsg.close();
    fcode.close();
    return 0;
}