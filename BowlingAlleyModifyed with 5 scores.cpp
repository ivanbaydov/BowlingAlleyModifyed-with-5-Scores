//---------------------------------------------------------------------------------
//
// Title:          BowlingAlleyModifyed with 5 scores
// Lab Course:     ITCS 2530 V0801 2021FA
// Author:         Ivan Baydov
// Date:           12/12/2021
// Description:    This Program will read the txt file and count each players name and each players points. After that it would collect the total from each indivdual person and print the 
//                 Avrage Score.
//---------------------------------------------------------------------------------

#include <iostream> // Inputs and Outputs stream.
#include <fstream> // File handling.
#include <iomanip> // Formatted inputs and Outputs.
#include <string> // For String data type.
#include <algorithm> // For Transfrom Method.

using namespace std;

// These Varables are used to format the output in a cleaner way
const int WIDTH = 60;
const int NAME_WIDTH = 10;
const int SCORES_WIDTH = 4;
const int AVG_SCORE_WIDTH = 6;

// These Varables are use for the for loops.
const int NUM_SCORES = 5;
const int NUM_PLAYERS = 10;

struct Bowler
{
    double AvgScore = 0; // to store the Avrage Score.
    double Points[5]; // array for the points in the array to count, also a one part of the double parelile array.
    string Name;  // to store Name.
};

// this function is checking if the file can be reached and inputs the players names and scores in the array list.
bool GetBowlingData(string filename, Bowler Bowlers[])
{
    // Create output file stream
    ifstream inputStream; // we use in to input the file into our code insted of outputing the file.
    // Open output file stream
    inputStream.open(filename); // inpustStream will open the filename called BowlingScores.txt.

    while (inputStream.good()) // this while loop will only loop to check if the file is good.
    {
        for (int i = 0; i < NUM_PLAYERS; i++) // this for loop will count the players from i which is 10 meaining it would loop 10 times adding each players name each time it loops into a new array box.
        {
            inputStream >> Bowlers[i].Name; // inputs data into the Players array.

            for (int j = 0; j < NUM_SCORES; j++) // this loop will each player and there 4 points for each round.
            {
                inputStream >> Bowlers[i].Points[j]; // inputs data into the points array.
            }
        }
    }
    return 0;
}

// this function is used to get the points of each player then add it in a sum deviding the number of rounds by 4 and displaying the total in the AvgScore array.
void GetAverageScore(Bowler Bowlers[])
{
    for (int i = 0; i < NUM_PLAYERS; i++) // this for loop will loop the inside for loop 10 times.
    {
        double sum = 0; // declare sum to to devide the total of 5 rounds.

        for (int j = 0; j < NUM_SCORES; j++) // this for loop will loop 4 times for each box in the points array so like box 0 would have 15 and box 1 would have 35 and so on.

        {
            sum = sum + Bowlers[i].Points[j]; //Bowlers[i] is saying that in Bowlers player 1 - 10 becuse of the first for loop
                                              //.Points[j] stores the first number then loops 5 tims to get the total numbers in the file.
                                              // The sum is then calculclated from all the 5 points stored into the points array adding it into the sum.                             
        }
        Bowlers[i].AvgScore = sum / NUM_SCORES; // in Bowlers[i] Bowlers[i] is saying that in Bowlers player 1 - 10 becuse of the first for loop.
                                                // it is then storing the avrage from sum / numscores in the .AvgScore Varaible listed as a double in the struct.
    }
}

// This function displays the output of the program of every players name, plays points, Avg string text, and the avrage score.
void PrettyPrintResults(const Bowler Bowlers[])
{
    // displays a table for the scores.
    cout << setfill(' ') << "Scores" << endl
        << setfill('-') << setw(NAME_WIDTH) << "-" << endl
        << setfill(' ');

    // This for loops will display each indivadule player name then there 5 points then it will add | Avg to seperate it from the points after that it displays the avrage points.
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        cout << left << setw(NAME_WIDTH) << Bowlers[i].Name << ":";

        for (int j = 0; j < NUM_SCORES; j++)
        {
            cout << setprecision(0) << right << setw(SCORES_WIDTH) << Bowlers[i].Points[j];

        }
        cout << setprecision(1) << " | Avg:" << setw(AVG_SCORE_WIDTH) << Bowlers[i].AvgScore << endl;
    }
}
int main()
{
    Bowler Bowlers[NUM_PLAYERS]; // we are calling the strucutre then giving it a new variable called Bowleres
                                 // so then we could add inside the array NUM_Players making it a array of 10 slot for the 10 players.
    cout << fixed; // is used to fix the decimal points in double

    // Displays the title of the program
    cout << setfill('*') << setw(WIDTH) << "*" << endl
        << setw(5) << "*" << " Welcome To The Bowling Alley in Sterling Heights " << setw(5) << "*" << endl
        << setw(WIDTH) << "*" << endl << endl;

    GetBowlingData("BowlingScores.txt", Bowlers); // Calls the function GetBowlingData.
    GetAverageScore(Bowlers); // Calls the function GetAverageScore.
    PrettyPrintResults(Bowlers); //Calls the function PreettyPrintResults.


    return 0;

}
