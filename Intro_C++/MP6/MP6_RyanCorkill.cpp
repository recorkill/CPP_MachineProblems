#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
This program seeks to take a series of unformatted names and automatically reformat them, with correct titles assigned. This is accomplished by separating the task into two components. The first of these components, assigning the proper title, is accomplished by reading the marital status and gender of the person, and generating the appropriate title.
 
 The second component, cleaning up the names and isolating the first and last names (and middle initial, if applicable), was accomplished using string functions. Knowing that a comma would separate the first and last names, and that a period would be present if the middle initial was given, it was possible to isolate each of these names individually and reformat them.
 */



//Married values will be positive and non-married values will be negative.
enum marital_status {single = -1, divorced = -1, married = 1};

//This function will take a character and assign it to the marital_status data type.
marital_status get_marital_status(char c)
{
    marital_status status;
    if(c == 'S')
    {
        status = single;
    }
    else if(c == 'M')
    {
        status = married;
    }
    else
    {
        status = divorced;
    }
    return status;
}

//This function makes use of the get_marital_status function to assign a person's title.
string get_title(int marital_status, char gender)
{
    string title = "Mr."; //We start with all titles being "Mr.", and change it as needed.
    if((gender == 'F') && (marital_status < 0))
    {
        title = "Ms.";
    }
    else if((gender == 'F') && marital_status > 0)
    {
        title = "Mrs.";
    }
    return title;
}


//This function will uniformly organize each passenger's name
string name_cleaner(string input)
{
    //We define our name variables and initialize the spaceless name that will be used.
    string last_name, first_name, middle_initial = " ", spaceless_input = "";
    for(char &c: input)
    {
        if(c != ' ') //Every character that is not a space will be passed to a new, spaceless string.
        {
            spaceless_input += c;
        }
    }


    long comma_location = spaceless_input.find(','), period_location = spaceless_input.find('.');
    //There will be a comma between first and last name. Additionally, if a middle initial is present, a period will also be present.
    
    last_name = spaceless_input.substr(0, comma_location); //Last name is start to comma location

    long last_name_length = last_name.length(), string_length = spaceless_input.length();
    //Knowing the last name length and string length will allow us to get the first name.

    if(spaceless_input.find('.') != string::npos) //If a period IS found in the string
    {
        first_name = spaceless_input.substr((comma_location+1), (string_length-(last_name_length+3)));
        middle_initial = " " + spaceless_input.substr((period_location-1), 2) + " ";
    }
    else //If a period is NOT found in the string
    {
        first_name = spaceless_input.substr((comma_location+1));
    }

    //We have now isolated the first name, last name, and middle initial (if present) of the person.
    string cleaned_name = first_name + middle_initial + last_name;
    return cleaned_name;
}


// Finally, we can create a function to bring the previous functions together, by getting both the title and the cleaned name and combinging them to be our final output.
void get_names(string path)
{
    ifstream infile;
    infile.open(path);
    char gender, marital_status;
    string line, rest_of_name;
    

    while(getline(infile, line, '\n') && infile.good())
    {
        gender = line[0];
        marital_status = line[1];
        rest_of_name = line.substr(2);
        string cleaned_name = name_cleaner(rest_of_name);
        string title = get_title(get_marital_status(marital_status), gender);
        line.erase(0, 2); //This gets rid of the gender and marital status characters
        int first_letter = line.find_first_not_of(" "); //We now want to find where the leading blankspace ends to that we can trim it to be visually more presentable.
        line.erase(0, first_letter);
        cout << left << setw(30) << line << "\t" << title << " " << cleaned_name << endl;
    }
}



int main()
{
    cout << "MP6, Standardizing Name Strings by Ryan Corkill\nFebruary 2nd, 2022\n" << endl;
    cout << left << setw(31) << "Original name" << " " << "Standardized name" << endl << endl;
    get_names("mp6Names.txt");
    cout << endl;
}
