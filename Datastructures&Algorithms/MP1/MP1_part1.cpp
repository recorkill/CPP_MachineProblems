#include <iostream>
#include <stack>
#include <string>


using namespace std;



//This function addresses part 1 of the assignment, where we will check if two patterns match (in reverse)
void check_pattern(string input)
{
    auto center = input.find('#');
    
    if (center == string::npos) //check to make sure the # character is present
    {cout << "Invalid Entry, no # present in string." << endl; return;}
    
    
    bool at_center = false;
    bool matches = false;
    stack<char> pre_center;
    
    for(int i = 0; i < input.size(); i++)
    {
        char val = input[i];
        
        if(val == '#') {at_center = true; continue;}
        
        if(at_center == false) {pre_center.push(val);} //fill the stack before '#' is reached
        
        if(at_center == true)
        {
            if(pre_center.empty()) {matches = false;}
            
            if(val == pre_center.top())  {pre_center.pop(); matches = true;}
        }
    }

    
    
    if(matches == true && pre_center.empty())
        cout << "\nThe pattern " << input << " matches.\n\n";
    else
        cout <<"\nThe pattern " << input << " does not match.\n\n";

}



int main()
{
    cout << "Ryan Corkill\nCPS 272\nApril 8, 2022\nMachine Problem 1, Stacks" << endl;
    
    //Testing part 1, matching string pattern
    string partOne = ".";
    while(! partOne.empty())
    {
        cout << "Please enter a string (or press 'Enter' to end the program): ";
        getline(cin, partOne);
        if(! partOne.empty()) {check_pattern(partOne);}
    }
    
    
    
    
    
    
    
    
    
    
}
