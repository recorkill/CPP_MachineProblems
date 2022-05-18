#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 This program seeks to assess whether applicants will be accepted into a university based on the criteria provided. Each applicant's profile is given in an input file, which contains the school they're applying to ("school"), their GPA ("GPA"), their math and verbal SAT scores ("math" and "verbal", respectively), and if they had parents that attended the University/are legacy ("legacy").
 
 The approach taken in this program is to read the input text file, and for each line (equivalent to each applicant), comparing their values (GPA, SAT scores, etc.) to the criteria set out by the schools. Each category has an associated boolean value (true if the applicant is sufficient in that category, false if they are not). As the applicant is assessed, each sufficient category changes that categorie's boolean to true. If the applicant meets all criteria for admission, the program will print that they have been accepted into the school they are applying for.
 */


int main()
{

    cout << "MP2, University Acceptance Program by Ryan Corkill" << endl;
    cout << "January 31st, 2022\n\n********************" << endl;
    
    //First, we open the input file stream
    ifstream infile;
    infile.open("mp2accept.txt");

    //Next, we declare/initialize variables that will be used in the program
    char school, legacy;
    float GPA;
    int math, verbal, music_acceptances = 0, lib_acceptances = 0, applicants = 0;

    //We create a while loop to run over each line in the text file, as each line corresponds to an applicant
    while(infile >> school >> GPA >> math >> verbal >> legacy && infile.good())
    {
        applicants++; //updates the total number of applicants

        bool music_SAT = false, lib_SAT = false, lib_GPA = false, is_legacy = false, accepted = false, applicants_full = false, apply_music = false, apply_lib = false;
        //This program assumes each student will NOT get in, until evidence is provided that they will (setting the variables to true)

        int SAT_total = (math + verbal);
        string apply_phrase = "", acceptance_phrase = "Rejected - ", reason = ""; //strings to be used when printing if the student was accepted
        

        //This set of if statements checks the values of the variables for each student and, if they meet a certain criteria, sets the accompanying boolean to true
        if(school == 'M') //Checks which school is being applied to.
        {
            apply_music = true;
            apply_phrase = "Applying to Music";
        }
        else
        {
            apply_lib = true;
            apply_phrase = "Applying to Liberal Arts";
        }
        if(legacy == 'Y') //Checks if the student has legacy at the University.
        {
            is_legacy = true;
        }
        
        if(GPA >= 3.5 || (is_legacy == true && GPA >= 3.0)) //Checks if the GPA meets liberal art standard.
        {
            lib_GPA = true;
        }
        if((verbal >= 500) && (math >= 500)) //Checks SAT scores
        {
            music_SAT = true;
        }
            
        if(SAT_total >= 1200 || (is_legacy == true && SAT_total >= 1000))
        {
            lib_SAT = true;
        }
        
        //Checks if the school is already full, and sets the "reason" phrase, if it is.
        if((apply_music == true && music_acceptances >= 3) || (apply_lib == true && lib_acceptances >= 5))
        {
            applicants_full = true;
            reason = "The school is full";
        }
        //If the student is applying to music, their acceptance status is assessed.
        if(apply_music == true && music_SAT == true && applicants_full == false)
        {
            accepted = true;
            music_acceptances++;
            acceptance_phrase = "Accepted to Music!";
        }
        //If the student is applying to liberal art, their acceptance status is assessed.
        if(apply_lib == true && lib_GPA == true && lib_SAT == true && applicants_full == false)
        {
            accepted = true;
            lib_acceptances++;
            acceptance_phrase = "Accepted to Liberal Arts!";
        }
        //Checks if the SAT scores don't meet their departmental requirement.
        if((apply_lib == true && lib_SAT == false) || (apply_music == true && music_SAT == false))
        {
            reason = "SAT is too low";
        }
        //Checks if the GPA doesn't meet their departmental requirement.
        if(apply_lib == true && lib_GPA == false)
            reason = "GPA is too low";
        
        //The following cout statements provide the application decision for each student.
        cout << "Applicant #: " << applicants << endl;
        cout << "School = " << school <<" GPA = " << GPA << " math = " << math << " verbal = " << verbal << " Alumnus = " << legacy << endl;
        cout << apply_phrase << endl;
        cout << acceptance_phrase << reason << endl;
        cout << "********************\n\n";
    }
    
    //The following cout statements provide the total number of applicants, and acceptances to each school.
    cout << "There were " << applicants << " applicants in the file" << endl;
    cout << "There were " << lib_acceptances << " acceptances to Liberal Arts" << endl;
    cout << "There were " << music_acceptances << " acceptances to Music\n" << endl;
}
