#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
       
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> smoothed(rows, vector<int>(cols, 0));
       
       

       
        for(int i=0; i < rows ; i++){
            for(int j=0; j < cols; j++){
                int cell = img[i][j];
                int count = 1;
                int sum=img[i][j];
                // neighbor : (i-1,j-1)
                if(i-1 >= 0 && j-1 >= 0){
                    count++;
                    sum+=img[i-1][j-1];
                }
                // neighbor : (i-1,j)
                if(i-1 >= 0){
                    count++;
                    sum+=img[i-1][j];
                }
                // neighbor : (i-1,j+1)
                if(i-1 >= 0  && j+1 < cols){
                    count++;
                    sum+=img[i-1][j+1];
                }
                // neighbor : (i,j-1)
                if( j-1 >=0 ){
                    count++;
                    sum+=img[i][j-1];
                }
                // neighbor : (i,j+1)
                if( j+1 < cols){
                    count++;
                    sum+=img[i][j+1];
                }
                // neighbor : (i+1,j-1)
                if(i+1 < rows && j-1 >= 0){
                    count++;
                    sum+=img[i+1][j-1];
                }
                // neighbor : (i+1,j)
                if(i+1<rows){
                    count++;
                    sum+=img[i+1][j];
                }
                // neighbor : (i+1,j+1)
                if(i+1<rows && j+1<cols){
                    count++;
                    sum+=img[i+1][j+1];
                }
               
               
                int average = sum / count;
               
                smoothed[i][j]=average;
 
            }
           
           
        }
       
        return smoothed;
       
       
       
       
       
       
    }
};




int main(){
   
    vector<vector<int>> image = {{1, 1, 1} , {1, 0, 1} ,  {1, 1, 1}};
   
    Solution obj;
   
   
    vector<vector<int>>  Res = obj.imageSmoother(image);
   
    for(auto &row : Res){
        for(auto &val : row){
            cout << val << " ";
    }
    cout << endl;
    }
   
   
   
   
}
