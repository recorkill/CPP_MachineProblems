#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;


//This function displays the cipher when called.
void show_array(char array[5][5])
{
    cout << "   0 1 2 3 4\n   - - - - -\n";
    for(int x = 0; x < 5; x++)
    {
        cout << x << "| ";
        for(int y = 0; y < 5; y++)
        {
            cout << array[x][y] << " ";
        }
        cout << "\n";
    }
}

//This function takes a character and an array, and checks if that character exists in the array.
bool already_in_array(char character, char array[5][5])
{
    bool is_in_array = false;
    for(int x = 0; x < 5; x++)
    {
        for(int y = 0; y < 5; y++)
        {
            if(array[x][y] == character)
            {
                is_in_array = true; //True if the character matches any value in any location.
            }
        }
    }
    return is_in_array;
}

//This function takes a row number (x), column number (y), and an array and checks if the spot is filled.
bool spot_filled(int x, int y, char array[5][5])
{
    bool filled = false;
    if(array[x][y] != 0)
    {
        filled = true;
    }
    return filled;
}


//This function takes a character as an argument and returns the mirrored character in the array (thus it can both encrypt and decrypt)
char encrypt_letter(char in_letter, char array[5][5])
{
    int mirror_column = 0;
    int mirror_row = 0;
    for(int x = 0; x < 5; x++)
    {
        for(int y = 0; y < 5; y++) //We find the column and row that the argument letter matches the array.
        {
            if(array[x][y] == in_letter)
            {
                mirror_column = x; //We switch the column and row where the match is found.
                mirror_row = y;
            }
        }
    }
    //We find the character located at the switched column and row numbers.
    char out_letter = array[mirror_row][mirror_column];
    return out_letter;
}

//This function will make use of the encrypt_letter function to encrypt/decrypt entire phrases.
string encrypt(string input, char array[5][5])
{
    string return_string = "";
    for(char& c : input) //For each character in the input string, encrypt (if the character is also in the cipher) and add it to the return_string
    {
        if(already_in_array(c, array) == true)
        {
            char new_letter = encrypt_letter(c, array);
            return_string += new_letter;
        }
        
        else //This accounts for characters that are not in the cipher (such as Z or punctuation marks).
        {
            return_string += c;
        }
    }
    return return_string;
}

int main()
{
    cout << "Machine Problem 5, Arrays\nRyan Corkill\nFebruary 1st, 2022\n\n";
    char Array[5][5]; //Create the array

    ifstream infile;
    infile.open("mp5infile.txt"); //Import and open the input file
    string keyword;
    getline(infile, keyword);
    
    // CREATE THE KEYWORD AT THE START OF THE MATRIX
    int ticker = 0;
    for (char& c: keyword)
    {
        if(already_in_array(c, Array) == false)
        {
            int loop_ticker = ticker;
            int x = 0; // Row number
            int y = 0; // Column number
            while(loop_ticker >= 5) //This while loop increases the row number after every five entries.
            {
                x += 1;
                loop_ticker -= 5;
            }
            y = loop_ticker; //Whatever number (less than five) is left over is the column number.
            Array[x][y] = c;
            ticker += 1; //Keeps track of the number of entries to adjust the row number accordingly.
        }
    }
    
    
    //FILLING THE REST OF THE ARRAY
    char fill_letter = 'A'; //Start at the beginning of the alphabet.
    for(int x = 0; x < 5; x++) //We will begin at the first row, first column
    {
        for(int y = 0; y < 5; y++)
        {
            bool already_filled = spot_filled(x, y, Array); //Check to see if the spot is alrady filled.
            bool letter_taken = already_in_array(fill_letter, Array);
            
            //Check to see if the fill_letter is alrady in the array, and increase it until it isn't.
            while(letter_taken == true)
            {
                fill_letter += 1;
                letter_taken = already_in_array(fill_letter, Array);
            }
            if(already_filled == false) //If spot is not filled, fill it.
            {
                Array[x][y] = fill_letter;
            }
            else //If spot is filled, do not change it.
            {
                Array[x][y] = Array[x][y];
            }
        }
    }
    
    //Print the keyword and the accompanying cipher
    cout << "The keyword is " << keyword << endl;
    cout << "Encryption Cipher: \n********************" << endl;
    show_array(Array);
    cout << "********************\n";
    
    string line;
    while(getline(infile, line, '\n') &&infile.good())
    {
        //Because the encrypt function can encrypt and decrypt, it's important to known which is happening (in order to print the phrase in all upper-case (encrypted) or lower-case letters (decrypted).
        bool decrypt = false; //Start with the assumption that we are encrpyting.
        char first_letter;
        first_letter = line.at(0);
        if(first_letter == 'D') //Check the first letter of the line which denotes decrypting or encrpyting
        {
            decrypt = true; //If decrypting, change the boolean to true
        }
        string capitalized_line = "";
        line.erase(0,2); //The line will begin with either E or D and a space, so we can get rid of that.
        for(char& c: line)
        {
            char C;
            C = toupper(c);
            capitalized_line += C; //We are now working with a universally capitalized string (all characters in the cipher are capitalized as well).
        }
        string converted_line = encrypt(capitalized_line, Array);
        string final_line = converted_line;
        string middle_line = "encrypts to:";
        if(decrypt == true) //If we are decrypting, we'll change our returned phrase back to lower-case.
        {
            middle_line = "decrypts to:";
            final_line = "";
            for(char& c: converted_line)
            {
                char C = tolower(c);
                final_line += C;
            }
        }
        //Now we can print the encryption/decryption for each phrase.
        cout << line << "\n" << middle_line << "\n" << final_line << "\n********************\n";
    }
}
