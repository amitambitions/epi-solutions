/*
	Given an array of strings, find the K most frequent strings.

	Input: array of strings
	Output: array of strings

	Solution:
		Sol1: Use hash table for count and then sort it in non-increasing order. Return first K terms. 

		TC: O(n + mlogm), n: no. of words, m:distinct words
		SC: O(m), m:distinct words
    
    Sol2: Using a min heap to reduce Tc: O(n + mlogk)
           SC: O(m + k)
          We take the frequency count and then create a min-heap of k elements.
          Then start traversing the word array frequencies, if the frequency is larger > heap root:
          remove root and insert the word, in the end we will have k frequent words in heap.
   Sol3: 
      TC: TC: 
          avg: O(n + m), worst: O(n + m^2)
          SC: O(m)
          We create frequency count table. Then we find the kth frequent word, and we prune everything after 'k'.
          Finding 'k' can be done using parition algoritm for finding the pivot position and we use select the pivot randomly
          in the current range. This is similar to https://github.com/susantabiswas/epi-solutions/blob/master/Searching/kth_largest_element.cpp
            
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

// Comparator for sort
struct Comp{
	bool operator()(const pair<string, int> a, const pair<string, int> b) {
		return a.second > b.second;
	}
};

// TC: O(n + mlogm)
vector<pair<string, int>> kFrequentWords(vector<string>& arr, int k) {
	
	unordered_map<string, int> freq_c;

	for(const auto& word: arr) {
		++freq_c[word];
	}
	
	vector<pair<string, int>> freq(freq_c.begin(), freq_c.end()); 
	// sort the words by frequency
	sort(freq.begin(), freq.end(), [](const pair<string, int> a, const pair<string, int> b)-> bool {
		return a.second > b.second;
	});
	

	return vector<pair<string, int>>(freq.begin(), freq.begin() + k);
}

int main() {
	vector<string> arr = {"I", "apple", "banana", "was", "apple", "orange", "apple", "banana", "new",
						"new", "new"};

	vector<pair<string, int>> ans = kFrequentWords(arr, 2);
	for(const auto& w: ans) {
		cout << w.first << endl;
	}
	return 0;
} 
