#include <iostream>
#include <vector>
using namespace std;

class Solution_BF{
public:

    string longestCommonPrefix(vector<string>& strs){
       
        if (strs.empty()) return "";
       
        string prefix = "";
       
        for(int i=0; i<strs[0].size();i++){
            char c_f = strs[0][i];
            for(int j=1; j<strs.size();j++){
                if (i>=strs[j].size() || c_f != strs[j][i]){
                    return prefix;  // return inside the loop early if a mismatch exists !
                }
            }
            prefix+=c_f;
        }
       
        return prefix;  // if all the characters match !
 
    }
};


class Solution{

public:


    // Custom swap function
    void swap(string& a, string& b){
       
        string temp = a ;
        a = b;
        b = temp;
    }
   
   
    // Bubble Sort using custom swap
    void BubbleSort(vector<string>& str){
       
        int n = str.size();
       
        for(int i=0; i<n-1; i++){
            for (int j=0; j < n-i-1; j++){
                if (str[j]>str[j+1]){
                    swap(str[j],str[j+1]);
                }
            }
        }
    }
   
   
   
   
    // Longest Common Prefix using sorted array
    string longestCommonPrefix(vector<string>& strs){
        if (strs.empty()) return "";
       
        // sort(strs.begin(), strs.end());
       
        BubbleSort(strs);
       
       
       
        string first = strs[0];
        string last = strs[strs.size()-1];
       
        int i=0;
        while(i < first.size() && i < last.size() &&  first[i]==last[i]){
            i++;
        }
       
        string result ="";
        for(int k=0; k<i ; k++){
            result += first[k];
        }
       
        return result;
       

 
    }
};








int main(){
    Solution object;
    vector<string> strs = {"flower","flow","flight"};
    cout << object.longestCommonPrefix(strs) << endl;
    return 0;
   
   
   
   
}

