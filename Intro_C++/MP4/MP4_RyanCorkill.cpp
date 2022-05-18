#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 This program will seek to read a file, perform a mathmatical operation, and convert between roman numerals and numbers. To accomplosh this, we will need a function for the following purposes:
 
 1) Converting between a numeral character and the number associated with is. (numeral_to_number)
 2) Summing these values for multi-chartacter numerals. (summed_numbers)
 3) Performing a calclation when given two numbers and an operator. (calculation)
 4) Converting a number back to a numeral. (number_to_numeral)
 5) Applying functions 1-4 to a set of values from the input file. (roman_numeral_calculator)
 */


//This switch case function allows us to translate a character to a value
int numeral_to_number(char numeral)
{
    switch (numeral)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L': return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return 0;
    }
}


//When dealing with multi-character numerals, this function allows us to sum the individual character values.
int summed_numbers(string numerals)
{
    int sum = 0; //We start with a value of 0
    for(char& c: numerals)
    {
        int loop_val = numeral_to_number(c);
        sum += loop_val;
        //For each character in the numeral (a string), we call the numeral to number function and add this to the total
    }
    return sum;
}


//This function performs the mathematical calculation. Knowing we have four possible operations to perform, a switch case is appropiroate for matching the operator character with the correct expression.
int calculation(int first_int, int second_int, char operand) //We will be performing integer operations.
{
    switch (operand)
    {
        case '+' : return first_int + second_int;
        case '-' : return first_int - second_int;
        case '/' : return first_int / second_int;
        case '*' : return first_int * second_int;
        default : return 0;
    }
}


//This function (while the number is greater than zero) will continuously remove the largest possible value associated with a roman numeral, and add that roman numeral to the output string.
string number_to_numeral(int number)
{
    string return_numeral = "";
    while(number>0)
    {
        if(number>=1000)
        {
            number -= 1000;
            return_numeral += 'M';
        }
        else if(number>=500)
        {
            number -= 500;
            return_numeral += 'D';
        }
        else if(number>=100)
        {
            number -= 100;
            return_numeral += 'C';
        }
        else if(number>=50)
        {
            number -= 50;
            return_numeral += 'L';
        }
        else if(number>=10)
        {
            number -= 10;
            return_numeral += 'X';
        }
        else if(number>=5)
        {
            number -= 5;
            return_numeral += 'V';
        }
        else if(number>=1)
        {
            number -= 1;
            return_numeral += 'I';
        }
        else break;
    }
    return return_numeral;
}


//This void function does not need to return anything, rather it gathers the information for each line of the input file and calls the appropriate functions to execute the primary purpose of this program.
void roman_numeral_calculator(string path)
{
    ifstream infile;
    infile.open(path);
    string numeral1, numeral2; //Declaration of infile variables.
    char op;
    while (infile >> numeral1 >> numeral2 >> op && infile.good()) //Assignment of infile variables.
    {
        int number1 = summed_numbers(numeral1); //We initialize the two numbers using our functions.
        int number2 = summed_numbers(numeral2);
        int result_number = calculation(number1, number2, op); //We perform the accompanying calculation.
        string result_numeral = number_to_numeral(result_number); //We get the resultant numeral.
        cout << "The first number is " << numeral1 << " ( " << number1 << " )." << endl;
        cout << "The second number is " << numeral2 << " ( " << number2 << " )." << endl;
        cout << "The operator is " << op << endl;
        cout << "The result is " << result_numeral << " ( " << result_number << " )." << endl;
        cout <<"************************************************\n" << endl;
    }
}

//Having assembled all the functions necessary for this porogram, main() can be shortened significantly.
int main()
{
    cout << "MP4, Roman Numeral Calculator by Ryan Corkill\nFebruary 1, 2022\n" << endl;
    roman_numeral_calculator("mp4romanletrdata.txt");
}
