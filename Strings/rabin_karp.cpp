/*
    Problem:
        Rabin Karp Algo

    Input:
        patt: string pattern
        text: string text

    Output:
        matched indices: vector of indices

    TC: Avg case: O(m + n)
        Worst case: O(mn)
        m: length of pattern
        n; legth of text
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

/*
    The idea behind Rabin Karp is we use a hash function to compute the
    hash value of the pattern and text window. When the hash value of the
    window matches that of the pattern, then we check if the pattern is actually
    present or not.

    For hash function we use the decimal no. formed by the chars mod some prime number
*/
vector<int> rabinKarp(string& text, string& patt){
    if(patt.size() > text.size())
           return vector<int>{};
    // base for the 26 alphabatical chars
    int base = 26;
    // base ^ length of (pattern)
    long int power_patt = 1;
    // length of the pattern
    int M = patt.length();
    // length of txt
    int N = text.length();
    // hash value of pattern
    long int hash_patt = 0;
    // hash value of text
    long int hash_text = 0;
    
    // for storing the matched indices
    vector<int> indices;

    // find the hash value of the pattern and the first window of text
    for(int i = 0; i < M; i++){
        power_patt = i ? base * power_patt:1;
        hash_patt = hash_patt * base + patt[i];
        hash_text = hash_text * base + text[i];
    }
   
    // traverse through the text using the window
    for(int i = 0; i <= N - M; i++){
        // check if the hash values match
        if(hash_patt == hash_text){
            // check if it actually matches text
            if(text.compare(i, M, patt) == 0){
                indices.emplace_back(i);
            }
        }

        // adjust the hash value for the new window
        hash_text = hash_text - (power_patt * text[i]);
        hash_text = (hash_text * base + text[i + M]) ;

    }

    return indices;
}

int main(){
    string text = "abaacab", patt = "a";
    vector<int> indices = rabinKarp(text, patt);
    for(int i = 0; i< indices.size(); i++)
        cout << indices[i] << " ";
    return 0;
}
