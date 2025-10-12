// This program checks whether a given string is a palindrome using a class structure in C++
// palindrome is a word, phrase, or sequence of characters that reads the same forward as it does backward
//  (e.g., "radar", "madam").


#include <iostream>
#include <string>

using namespace std;



class Palindrome{
    public:
        // Function declaration
        bool Check_Palindrome(const std::string& statement);


};


// Function definition using the scope resolution operator ::
bool Palindrome::Check_Palindrome(const std::string& statement) {
    
    for (int i = 0, j = statement.length() - 1; i < j; i++, j--) {
        //cout << "statement[i]=" << statement[i] << endl;
        //cout << "statement[j]=" << statement[j] << endl;
        if (statement[i] != statement[j]){
            cout << "There is a mismatch between:" << statement[i] << " and " << statement[j] << endl;
            return false;
            
        }
    }
    return true;
}





int main() {

    std::cout << "Hello, Welcome to the world of magic!" << std::endl;
    std::cout << "Please give us your string " << std::endl;
    std::string statement;
    std::cin >> statement;

    Palindrome object;
    bool is_palindrome = object.Check_Palindrome(statement);

    if (is_palindrome) {
        std::cout << "This is a palindrome" << std::endl;
    } else {
        std::cout << "This is not a palindrome" << std::endl;
    }



    return 0;
}




// About strings :

// You can use 'using namespace std' to avoid prefixing 'std::' with standard library components.
// For example, 'cout' can be used instead of 'std::cout' if 'using namespace std' is declared.

// To use string functionality, make sure to include the string library:
// #include <string>












