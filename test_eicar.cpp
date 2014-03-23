#include <string>
#include <fstream>
#include <iostream>

/*
Application Details:
    Executable: test_eicar.exe
    Created Date: December 5, 2010
    Author: Joe Kraxner <joe[\@/]kraxner.net>
    Written and compiled in Microsoft Visual Studio 2010

Background:
    This application was written by Joe Kraxner as a tool
    to test anti-virus software that has the ability to detect
    the EICAR Test Virus (http://www.eicar.org/anti_virus_test_file.htm).

    The primary purpose of the application is to use test_eicar.exe in
    a script that can be manually executed to generate a plain-text file
    named "EICAR_VIRUS_TEST.txt".  The anti-virus software should detect
    the text file and delete.

Usage:
    A single word such as "RUN" or "TEST" must be given as an
    argument for the application to run.  This is a safeguard to keep
    the application from accidentally executing by double-clicking.

Example:
    test_eicar.exe RUN
*/

using namespace std;

void outputFileCheck(ofstream &fout, string filename);

int main()
{
    //Declare output file for EICAR test string
    ofstream eicar_out;

    //check the output file
    outputFileCheck(eicar_out, "eicar_test.txt");

    //Declare the eicarTestString variable
    string eicarTestString = "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*";

    //print the eicarTestString to a file
    eicar_out << eicarTestString << endl;

    //finished with the output, close the file handle
    eicar_out.close();

    //exit safely
    return 0;
}

void outputFileCheck(ofstream &fout, string filename)
{
    //Declare and open output file
    fout.open(filename.c_str());

    //Print an error if that failed
    if(fout.fail())
    {
        cerr << "Unable to open " << filename << endl;
        //Exit with errors
        exit(2);
    }
}


