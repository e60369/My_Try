//---------------------------------------------------------------------------------------------------
// EGR 126 ELI   Fall 2017
//---------------------------------------------------------------------------------------------------
// Developer: Rich MURPHY
// Project: Project #3
// Submission Date: 11/5/17
// Complier Info: Xcdoe, MacOS
// Purpose: The purpose of this program is to compare 3 signals to a reference
// signal, compute their relative differences and output a file to the user
// containing a qualitative analysis.
//---------------------------------------------------------------------------------------------------

#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// This function computes the distance between two arrays.-------------------------------------------
double myEDistance (double a[], double b[], int size )
    {
    double dist=0;
    for (int i=0; i<size; i++)
        {
        dist += pow(a[i]-b[i],2);
        }
    return sqrt(dist);
    }

// This function decides on the report output based on the distance calculated-----------------------
string myDecision (double Dist)
    {
    string decision;
    
    if(Dist <= .5)
        decision = "Best";
        else if(Dist <= 1)
            decision = "Good";
            else if (Dist <= 3)
                decision = "Last Option";
                    else
                        decision = "Not Good";
    return decision;
    }

int main()
{
    int theSize=57;
    double Ref[57],Sig1[57],Sig2[57],Sig3[57],Dist1=0, Dist2=0, Dist3=0;
    
    cout << "--------------------------------------------" << endl;
    cout << "    Rich MURPHY" << endl;
    cout << "    Solution for Project #3" << endl;
    cout << "--------------------------------------------" << endl;
    
// Here we open/check the files and feed the data into arrays on which we'll perform operations.-----
    ifstream Reference;
    Reference.open ("ReferenceSignal.txt");
    if (!Reference.is_open())
        {
        cerr << "Could not open ReferenceSignal.txt" << endl;
        system("pause");
        exit(1);
        }
            for (int i=0; i<theSize; i++)
                {
                Reference >> Ref[i];
                }
    Reference.close();
    
    ifstream Chan1;
    Chan1.open ("Channel_1_output.txt");
    if (!Chan1.is_open())
        {
        cerr << "Could not open Channel_1_output.txt" << endl;
        system("pause");
        exit(1);
        }
            for (int i=0; i<theSize; i++)
                {
                Chan1 >> Sig1[i];
                }
    Chan1.close();
    
    ifstream Chan2;
    Chan2.open ("Channel_2_output.txt");
    if (!Chan2.is_open())
        {
        cerr << "Could not open Channel_2_output.txt" << endl;
        system("pause");
        exit(1);
        }
            for (int i=0; i<theSize; i++)
                {
                Chan2 >> Sig2[i];
                }
    Chan2.close();
    
    ifstream Chan3;
    Chan3.open ("Channel_3_output.txt");
    if (!Chan3.is_open())
        {
        cerr << "Could not open Channel_3_output.txt" << endl;
        system("pause");
        exit(1);
        }
            for (int i=0; i<theSize; i++)
                {
                Chan3 >> Sig3[i];
                }
    Chan3.close();
    
//Here we compute the distances between the signals using our function.-----------------------------
    
    Dist1 = myEDistance (Ref, Sig1, theSize);
    Dist2 = myEDistance (Ref, Sig2, theSize);
    Dist3 = myEDistance (Ref, Sig3, theSize);
    
// Here we output the results of the classification to a file.--------------------------------------
    ofstream fout;
    fout.open("Murphy_ChannelReport.txt");
    if (!fout.is_open())
        {
        cerr << "Could not open Murphy_ChannelReport.txt" << endl;
        system("pause");
        exit(1);
        }
    fout << "Rich Murphy" << endl;
    fout << "Channel Classification Report" << endl;
    fout << "Channel  1  "  << myDecision(Dist1) << endl;
    fout << "Channel  2  "  << myDecision(Dist2) << endl;
    fout << "Channel  3  "  << myDecision(Dist3) << endl;
 
// This is our message to the user letting them know we've succesfully completed the task.----------
    cout << endl;
    cout << "Channel idendfication and classification was completed" << endl;
    cout << "Please see output data file named as Murphy_ChannelReport on your computer" << endl;
    cout << endl;
    
    system("pause");
    
    return 0;
}
