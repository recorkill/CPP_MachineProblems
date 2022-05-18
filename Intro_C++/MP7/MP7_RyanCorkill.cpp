#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//This struct will allow us to store each diver's name with their total scores.
struct competition
{
    string names[7];
    double total_scores[7];
};


void competition_report(string path)
{
    cout << "Diver " << "   Difficulty " << " \t\t Sorted Scores " << "\t\t Points" << endl;
    ifstream infile; //Our infile path is provided when the function is called.
    infile.open(path);
    string line, name; //We declare our variables.
    double difficulty, s1, s2, s3, s4, s5, s6, s7, s8 ,s9;
    competition this_competition;
    int diver_number = 0; //This will allow us to match the index numbers of diver names and scores.
    while(infile >> name >> difficulty >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8 >> s9 && infile.good())
        //For each line in the text file (representing each diver) we assign our variables accordingly.
    {
        double total_points = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + s9;
        double total_score = total_points * difficulty; // Calculate the diver's total score.
        double judges_scores[]  = {s1, s2, s3, s4, s5, s6, s7, s8, s9};
        sort(judges_scores, judges_scores + 9); //Sort the array of judges' scores.
        this_competition.names[diver_number] = name; //We now assign the name and total scores to the arrays in our struct, using diver_number to properly index them.
        this_competition.total_scores[diver_number] = total_score;
        string scores_sorted = ""; //We would like the judges' scores as a string to print for the user.
        for(int i = 0; i < 9; i++)
        {
            string loop_val = to_string(judges_scores[i]);
            loop_val.erase(loop_val.end()-5, loop_val.end()); //to_string innately adds too many digits when converting doubles, so trimming is necessary.
            scores_sorted += loop_val; //Add the score (as a string), as well as a space.
            scores_sorted += " ";
        }
        string between_name_and_difficulty = "";
        for(int i = 0; i < (10 - name.length()); i++) //we know the max name length is 10, and can make the output cleaner by starting the numbers at the same place for each diver
        {
            between_name_and_difficulty += " ";
        }
        cout << setprecision(2) << this_competition.names[diver_number] << between_name_and_difficulty << setw(5) << showpoint << difficulty << "  " << scores_sorted << "|" << setprecision(4) << this_competition.total_scores[diver_number] << endl;

        diver_number += 1;
    }
    
    //We will now check for the winning diver and their score.
    string winning_diver = this_competition.names[0]; //We start with the first diver
    double winning_score = this_competition.total_scores[0];
    for(int i = 0; i < 7; i++)
    {
        string test_name = this_competition.names[i]; //We compare each diver sequentially
        double test_score = this_competition.total_scores[i];
        if(test_score > winning_score) //Whenever a diver's score is greater than the current "winning" diver, they are updated to be the winning diver and their score is what's compared to.
        {
            winning_score = test_score;
            winning_diver = test_name;
        }
        
    }
    cout << "\nThe winner of this competition is " << winning_diver << " with a score of " << winning_score << " points.\nCongratulations, " << winning_diver << "!\n" << endl;

    
}

int main()
{
    cout << "MP7, Diving Competition by Ryan Corkill\nFebruary 2nd, 2022\n" << endl;
    competition_report("mp7divers.txt");
}
