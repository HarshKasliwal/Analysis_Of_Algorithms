#include<iostream>
#include<string.h>
using namespace std;
int p[50];
void LPS(string pattern, int m){
    int k = 0;
    p[0] = 0;
    int i = 1;
    while(i<m){
        if(pattern[k] == pattern[i]){
            k++;
            p[i]=k;
            i++;
        }
        else{
            if(k!=0)
                k=p[k-1];
            else{
                p[i]=0;
                i++;
            }
        }
    }
}

void KMP(string pattern, string text){
    int m = pattern.size();
    int n = text.size();
    LPS(pattern, m);
    int i = 0;
    int j = 0;
    while(i < n){
        if(pattern[j] == text[i])
            i++, j++;
        if(j == m){
            cout<<"Pattern Found at index :"<<i-m<<endl;
            j = p[j-1];
        }
        else if(i<n && pattern[j]!=text[i]){
            if(j!=0)
                j=p[j-1];
            else
                i++;
        }
    }
}

int main(){
    string pattern;
    string text;
    cout<<"Enter the text"<<endl;
    cin>>text;
    cout<<"Enter the pattern"<<endl;
    cin>>pattern;
    KMP(pattern, text);
    return 0;
}