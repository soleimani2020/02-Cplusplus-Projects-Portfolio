/******************************************************************************

Test case: MCMXCIV : 1994

*******************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class romanType{
    public:
        void getromannumber(string r);
        int convert_roman_to_decimal();
        void show_roman();
        void show_decimal();
        
    private:
        string roman;
        int decimal=0;
      
};// end of the class 



void romanType::getromannumber(string r){
    roman=r;
}



int romanType::convert_roman_to_decimal(){
    // Map to hold Roman numeral values
    unordered_map<char, int> roman_value = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    decimal =0;
    int n= roman.length();

    
    // The last character (V) will sinmply be added to the total decimal as it does not satisfy the if condition ! 
    for (int i=0; i<n ; i++)
    {
        if ( i<n-1 && roman_value[roman[i]] <  roman_value[roman[i+1]] ){
            decimal-=roman_value[roman[i]];
        }else{
            decimal+=roman_value[roman[i]];
            
        }
    }
    
    return decimal;    
}



void romanType::show_roman(){
    cout << "The roman numeral is:" << roman << endl;   
}



void romanType::show_decimal(){
    cout << "The deciaml is:" << decimal <<  endl;
}


int main()
{
    romanType object;
    cout << "please give us a roman numeral" << endl;
    string roman;
    cin>>roman;
    object.getromannumber(roman);
    object.convert_roman_to_decimal();
    object.show_roman();
    object.show_decimal();
    return 0;
}



