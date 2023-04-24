#include <iostream>
#include <fstream>
#include <string> // for string conversion
#include <sstream>
#include <vector>
#include <cmath>
#include <map> // for map containers
#include <cctype> // for toupper()
#include <iomanip>
#include <windows.h> // only works for windows, for sleep() function

using namespace std;
ifstream infile;
ofstream outfile;
ofstream HTML;
int i = 0;
int column;
string id,age,sub1,sub2,sub3;
vector<long>ID;
vector<int>AGE;
vector<float>SUB1;
vector<float>SUB2;
vector<float>SUB3;
char choice[1], choice_computeStats[2];
float x = 0.0, y = 0.0;
int res1 = 1, res2 = 1, res3 = 1;

class data
{
    private:
    float mean1 = 0.0, mean2 = 0.0, mean3 = 0.0;
    float variance1 = 0.0, variance2 = 0.0, variance3 = 0.0;
    float stddev1 = 0.0, stddev2 = 0.0, stddev3 = 0.0;
    float covariance1 = 0.0, covariance2 = 0.0, covariance3 = 0.0;
    float corr1 = 0.0, corr2 = 0.0, corr3 = 0.0;
    public:
    void findMean(vector<string> &v, int rows);
    void findVariance(vector<string> &v, int rows);
    void findStd(vector<string> &v, int rows);
    void belowMean3(vector<string> &v, int rows);
    void belowMean2(vector<string> &v, int rows);
    void belowMean1(vector<string> &v, int rows);
    void aboveMean3(vector<string> &v, int rows);
    void aboveMean2(vector<string> &v, int rows);
    void aboveMean1(vector<string> &v, int rows);
    void printMean(vector<string> &v, int rows);
    void printVariance(vector<string> &v, int rows);
    void printStd(vector<string> &v, int rows);
    void findCorr1(vector<string> &v, int rows);
    void findCorr2(vector<string> &v, int rows);
    void findCorr3(vector<string> &v, int rows);
    void findLinear1(vector<string> &v, int rows);
    void findLinear2(vector<string> &v, int rows);
    void findLinear3(vector<string> &v, int rows);
    void computeStatsChoice(vector<string> &v, int rows);
    void printCorr(vector<string> &v, char ch[], int rows);
    void printLinear(vector<string> &v, char c[], int rows);
    void StatsAbove1(vector<string> &v);
    void StatsAbove2(vector<string> &v);
    void StatsAbove3(vector<string> &v);
    void StatsBelow1(vector<string> &v);
    void StatsBelow2(vector<string> &v);
    void StatsBelow3(vector<string> &v);
    void findStatsMean(vector<string> &v, int rows);
    void findStatsVar(vector<string> &v, int rows);
    void findStatsStd(vector<string> &v, int rows);
    void findStatsCorr(vector<string> &v, int rows);
    void findStatsLinear1(vector<string> &v, int rows);
    void findStatsLinear2(vector<string> &v, int rows);
    void findStatsLinear3(vector<string> &v, int rows);
    void meanHTML(vector<string> &v, int rows);
    void varianceHTML(vector<string> &v, int rows);
    void stdHTML(vector<string> &v, int rows);
    void Above1HTML(vector<string> v, int rows);
    void Above2HTML(vector<string> v, int rows);
    void Above3HTML(vector<string> v, int rows);
    void Below1HTML(vector<string> v, int rows);
    void Below2HTML(vector<string> v, int rows);
    void Below3HTML(vector<string> v, int rows);
    void CorrHTML(vector<string> v, int rows);
    void L_HTML(vector<string> v, int rows);
};
data C;

/***************************************************************
Programmer:	Hii Jyn Tong
Name: 		Info
task:		To make sure our screen output would look the same
****************************************************************/
void Info()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t Please follow this instruction before starting this application!" << endl;
    cout << "\t\t\t\t\t\t\t 1. Screen Buffer Size (Width: 166, Height: 1000)" << endl;
    cout << "\t\t\t\t\t\t\t 2. Window Size (Width: 166, Height: 38)" << endl;
    cout << "\t\t\t\t\t\t\t 3. Font Size: 18 " << endl;
    cout << "\t\t\t\t\t\t\t 4. Font type: Consolas " << endl;
    cout << "\t\t\t\t\t\t\t 5. Maximize your screen! " << endl;
    cout << "\t\t\t\t\t\t\t Done! Please Enter. " << endl;
    cout << "\t\t\t\t\t\t\t Press enter to continue.";
    cin.ignore(100, '\n');
    system("cls");
}

/*************************
Programmer:	Hii Jyn Tong
Name: 		Intro
task:		Loading
**************************/
void Intro()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t    __                     ___" << endl;
    cout << "\t\t\t\t\t\t\t\t   / /   ____   ____ _____/ (_)___ ____ _" << endl;
    cout << "\t\t\t\t\t\t\t\t  / /   / __ \\/ __ `/ __  / / __ \\/ __ `/" << endl;
    cout << "\t\t\t\t\t\t\t\t / /___/ /_/ / /_/ / /_/ / / / / / /_/ /_ _ _" << endl;
    cout << "\t\t\t\t\t\t\t\t/_____/\\____/\\__,_/\\__,_/_/_/ /_/\\__,  (_|_|_)" << endl;
    cout << "\t\t\t\t\t\t\t\t                                /____/" << endl;
    Sleep(1000);
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t    __                     ___" << endl;
    cout << "\t\t\t\t\t\t\t\t   / /   ____   ____ _____/ (_)___ ____ _" << endl;
    cout << "\t\t\t\t\t\t\t\t  / /   / __ \\/ __ `/ __  / / __ \\/ __ `/" << endl;
    cout << "\t\t\t\t\t\t\t\t / /___/ /_/ / /_/ / /_/ / / / / / /_/ /_ _ _ _ _" << endl;
    cout << "\t\t\t\t\t\t\t\t/_____/\\____/\\__,_/\\__,_/_/_/ /_/\\__,  (_|_|_|_|_)" << endl;
    cout << "\t\t\t\t\t\t\t\t                                /____/" << endl;
    Sleep(1000);
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t    __                     ___" << endl;
    cout << "\t\t\t\t\t\t\t\t   / /   ____   ____ _____/ (_)___ ____ _" << endl;
    cout << "\t\t\t\t\t\t\t\t  / /   / __ \\/ __ `/ __  / / __ \\/ __ `/" << endl;
    cout << "\t\t\t\t\t\t\t\t / /___/ /_/ / /_/ / /_/ / / / / / /_/ /_ _ _ _ _ _ _" << endl;
    cout << "\t\t\t\t\t\t\t\t/_____/\\____/\\__,_/\\__,_/_/_/ /_/\\__,  (_|_|_|_|_|_|_)" << endl;
    cout << "\t\t\t\t\t\t\t\t                                /____/" << endl;
    Sleep(1000);
    system("cls");
}

/*********************************************************************
Programmer:	Wong Yi Teng
Name: 		readFile
task:		Reading the file name and open the file.
            If file is not found, an error message will be displayed
data in:	File name
**********************************************************************/
void readFile(string &file)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t Please enter the file name : " ;
    cin >> file;
    cout << endl;
    infile.open(file);
    system("cls");
    if(!infile.is_open())
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "ERROR : File Can't Open..." << endl;
        exit(1);
    }
}

/************************************************************************************************
Programmer:	Wong Yi Teng
Name: 		readTitles
task:		Read titles from file,
            create string stream from the string
data in:	Get first string delimited by comma (titles)
Referred to:	https://www.tutorialspoint.com/parsing-a-comma-delimited-std-string-in-cplusplus
*************************************************************************************************/
void readTitles(vector<string> &v,int &cols)
{
    string line;
    infile >> cols;
    infile >> line;
    stringstream s(line);
    while(s.good())
    {
        string substr;
        getline(s , substr , ',');
        v.push_back(substr);
    }
}

/***************************************************************************************
Programmer:	Wong Yi Teng
Name: 		readData
task:		Read data from file, converting strings to long, int, float and close file
data in:	Get strings delimited by comma (data)
Referred to: https://www.youtube.com/watch?v=vuuICE_bGRo
****************************************************************************************/
void readData()
{
    while(getline(infile,id,',')&&getline(infile,age,',')&&getline(infile,sub1,',')&&
         getline(infile,sub2,',')&&getline(infile,sub3))
    {
        ID.push_back(stol(id));
        AGE.push_back(stoi(age));
        SUB1.push_back(stof(sub1));
        SUB2.push_back(stof(sub2));
        SUB3.push_back(stof(sub3));
        i += 1;
    }
    infile.close();
}

/******************************
Programmer:	Wong Yi Teng
Name: 		showMenu
task:	    Show main menu
data in:    Choices
*******************************/
void showMenu()
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t -----------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t : * * * * * * * * * * * * * * * * * * * * * * :\n";
    cout << "\t\t\t\t\t\t\t : * <-------------------------------------> * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                     : * :\n";
    cout << "\t\t\t\t\t\t\t : * :         Main Menu                   : * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                     : * :\n";
    cout << "\t\t\t\t\t\t\t : * :         1. Load Data                : * :\n";
    cout << "\t\t\t\t\t\t\t : * :         2. Compute Statistics       : * :\n";
    cout << "\t\t\t\t\t\t\t : * :         3. Statistical Report       : * :\n";
    cout << "\t\t\t\t\t\t\t : * :         4. HTML Document            : * :\n";
    cout << "\t\t\t\t\t\t\t : * :         5. Exit                     : * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                     : * :\n";
    cout << "\t\t\t\t\t\t\t : * <-------------------------------------> * :\n";
    cout << "\t\t\t\t\t\t\t : * * * * * * * * * * * * * * * * * * * * * * :\n";
    cout << "\t\t\t\t\t\t\t ----------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t Please enter your choice : " ;
    cin >> choice;
}

/**************************************************************
Programmer:	Hii Jyn Tong
Name: 		Invalid
task:		For invalid choices
**************************************************************/
void Invalid()
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t Invalid choice! Please enter the given choice only.\n";
    cout << "\t\t\t\t\t\t Press enter to try again.";
    cin.get();
    cin.ignore(100, '\n');
}

/*****************************************************
Programmer:	Wong Yi Teng, Nurul Marsha Binti Zulkifli
Name: 		printData
task:		Print titles and data from file
data in:	Choice to go back to main menu or exit
data out:   Titles and data
******************************************************/
void printData(vector<string> &v)
{
    char c[1];
    system ("cls");
    cout << setprecision(2) << fixed << showpoint;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t <---------------------------------DATA------------------------------>\n";
    cout << "\t\t\t\t\t\t  |";
    for(auto e:v)
        cout << "    " << e << "    |";
    cout << endl;
    cout << "\t\t\t\t\t\t  -------------------------------------------------------------------\n";
    for(int j=0;j<i;j++)
    {
        cout << "\t\t\t\t\t\t  | " << ID[j] << " |    " << AGE[j] << "     |   " << SUB1[j] << "    |     "
             << SUB2[j] << "     |    " << SUB3[j] << "    |\n";
    }
    cout << "\t\t\t\t\t\t <------------------------------------------------------------------->\n";
    cout << "\t\t\t\t\t\t Press Y to go back to main menu and N to exit: ";
    cin >> c;
    c[0]=toupper(c[0]);
    if (c[0] == 'Y' && c[1] == '\0')
        showMenu();
    else if (c[0] == 'N' && c[1] == '\0')
        exit(1);
    else
    {
        Invalid();
        printData(v);
    }
}

/******************************************************
Programmer:	Wong Yi Teng, Nurul Marsha Binti Zulkifli
Name: 		showMenuComputeStats
task:		Show compute statistics menu
data in:	Choices
*******************************************************/
void showMenuComputeStats(vector<string> &v, int rows)
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t -----------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t : * * * * * * * * * * * * * * * * * * * * * * * * * * * * :\n";
    cout << "\t\t\t\t\t\t\t : * <-------------------------------------------------> * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                                 : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             Compute Statistics                  : * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                                 : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             1. Minimum                          : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             2. Maximum                          : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             3. Median                           : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             4. Mean                             : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             5. Variance                         : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             6. Standard Deviation               : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             7. Pearson's Correlation            : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             8. Linear Regression Line           : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             9. Frequency and Distinct numbers   : * :\n";
    cout << "\t\t\t\t\t\t\t : * :            10. Histogram                        : * :\n";
    cout << "\t\t\t\t\t\t\t : * :             0. Main Menu                        : * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                                 : * :\n";
    cout << "\t\t\t\t\t\t\t : * <-------------------------------------------------> * :\n";
    cout << "\t\t\t\t\t\t\t : * * * * * * * * * * * * * * * * * * * * * * * * * * * * :\n";
    cout << "\t\t\t\t\t\t\t -----------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t Please enter your choice : " ;
    cin >> choice_computeStats;
    C.computeStatsChoice(v, rows);
}

/**************************************************************
Programmer:	Hii Jyn Tong
Name: 		goback
task:		Go back to compute statistics menu
**************************************************************/
void goback(vector<string> &v, int rows)
{
    cout << "\t\t\t\t\t\t\t Press enter to go back to compute statistics menu.";
    cin.get();
    cin.ignore(100, '\n');
    showMenuComputeStats(v, rows);
}

/**********************************************************************************
Programmer:	Nurul Marsha Binti Zulkifli
Name: 		countDistinct
task:		To count distinct numbers
data in:	Data from file
data out:	Distinct numbers
Referred to:	https://www.geeksforgeeks.org/count-distinct-elements-in-an-array/
***********************************************************************************/
void countDistinct(vector<string> &v, int rows)
{
    for (int j=1;j<rows; j++)
    {
        int n = 0;
        for (n = 0; n < j; n++)
            if (SUB1[j] == SUB1[n])
                break;
        if (j == n)
            res1++;
    }

    for (int j=1;j<rows; j++)
    {
        int n = 0;
        for (n = 0; n < j; n++)
            if (SUB2[j] == SUB2[n])
                break;
        if (j == n)
            res2++;
    }

    for (int j=1;j<rows; j++)
    {
        int n = 0;
        for (n = 0; n < j; n++)
            if (SUB3[j] == SUB3[n])
                break;
        if (j == n)
            res3++;
    }
}

/*****************************************
Programmer:	Nurul Marsha Binti Zulkifli
Name: 		printDistinct
task:		To print distinct numbers
data in:	Distinct numbers
data out:	Distinct numbers
******************************************/
void printDistinct(vector<string> &v, int rows)
{
    system ("cls");
    countDistinct(v, rows);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t <------DISTINCT NUMBERS----->\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(2) << "      |    " << res1 << "    |\n";
    cout << "\t\t\t\t\t\t\t\t  ---------------------------\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(3) << "   |    " << res2 << "    |\n";
    cout << "\t\t\t\t\t\t\t\t  ---------------------------\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(4) << "     |    " << res3 << "    |\n";
    cout << "\t\t\t\t\t\t\t\t  ---------------------------\n";
    goback(v, rows);
}

/*******************************************************************************************************************
Programmer:	Wong Yi Teng
Name: 		printFrequency3
task:		To calculate and print frequency for third subject
data in:	Data from file
data out:	Frequency for third subject
Referred to:	https://www.geeksforgeeks.org/program-to-find-frequency-of-each-element-in-a-vector-using-map-in-c/
********************************************************************************************************************/
void printFrequency3(vector<string> &v, int rows)
{
    system ("cls");
    cout << setprecision(2) << fixed << showpoint;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    char c[1];
    map<int, int> M;
    for (int i=0; i<rows; i++)
    {
        if (M.find(SUB3[i]) == M.end())
            M[SUB3[i]] = 1;
        else
            M[SUB3[i]]++;
    }
    cout << "\t\t\t\t\t\t\t\t <-------------FREQUENCY------------->\n";
    cout << "\t\t\t\t\t\t\t\t  |     " << v.at(4) << "    |    Occurrences   |\n";
    cout << "\t\t\t\t\t\t\t\t  -----------------------------------\n";
    for (auto& it : M)
        cout << "\t\t\t\t\t\t\t\t  |      " << it.first << "      |         " << it.second << "        |" << endl;
    cout << "\t\t\t\t\t\t\t\t  -----------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t Press Y to view distinct numbers," << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if(c[0] == 'Y' && c[1] == '\0')
        printDistinct(v, rows);
    else if(c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        printFrequency3(v, rows);
    }
}

/*******************************************************************************************************************
Programmer:	Wong Yi Teng
Name: 		printFrequency2
task:		To calculate and print frequency for second subject
data in:	Data from file
data out:	Frequency for second subject
Referred to:	https://www.geeksforgeeks.org/program-to-find-frequency-of-each-element-in-a-vector-using-map-in-c/
********************************************************************************************************************/
void printFrequency2(vector<string> &v, int rows)
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    char c[1];
    map<int, int> M;
    for (int i=0; i<rows; i++)
    {
        if (M.find(SUB2[i]) == M.end())
            M[SUB2[i]] = 1;
        else
            M[SUB2[i]]++;
    }
    cout << "\t\t\t\t\t\t\t\t <-------------FREQUENCY------------->\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(3) << "   |    Occurrences   |\n";
    cout << "\t\t\t\t\t\t\t\t  -----------------------------------\n";
    for (auto& it : M)
        cout << "\t\t\t\t\t\t\t\t  |      " << it.first << "      |         " << it.second << "        |" << endl;
    cout << "\t\t\t\t\t\t\t\t  -----------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t Press Y to view frequency for " << v.at(4) << ", " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if(c[0] == 'Y' && c[1] == '\0')
        printFrequency3(v, rows);
    else if(c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        printFrequency2(v, rows);
    }
}

/*******************************************************************************************************************
Programmer:	Wong Yi Teng
Name: 		printFrequency1
task:		To calculate and print frequency for first subject
data in:	Data from file
data out:	Frequency for first subject
Referred to:	https://www.geeksforgeeks.org/program-to-find-frequency-of-each-element-in-a-vector-using-map-in-c/
********************************************************************************************************************/
void printFrequency1(vector<string> &v, int rows)
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    char c[1];
    map<int, int> M;
    for (int i=0; i<rows; i++)
    {
        if (M.find(SUB1[i]) == M.end())
            M[SUB1[i]] = 1;
        else
            M[SUB1[i]]++;
    }
    cout << "\t\t\t\t\t\t\t\t <-------------FREQUENCY------------->\n";
    cout << "\t\t\t\t\t\t\t\t  |     " << v.at(2) << "     |     Occurrences  |\n";
    cout << "\t\t\t\t\t\t\t\t  -----------------------------------\n";
    for (auto& it : M)
        cout << "\t\t\t\t\t\t\t\t  |      " << it.first << "      |         " << it.second << "        |" << endl;
    cout << "\t\t\t\t\t\t\t\t  -----------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t Press Y to view frequency for " << v.at(3) << ", " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if(c[0] == 'Y' && c[1] == '\0')
        printFrequency2(v, rows);
    else if(c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        printFrequency1(v, rows);
    }
}

/*******************************************************
Programmer:	Wong Yi Teng
Name: 		findMin
task:		To find the minimum of all three subjects
data in:	Data from file
data returned:	Minimum
*******************************************************/
// to find minimum
float findMin(vector<float> v)
{
    cout << setprecision(2) << fixed << showpoint;
    float mn = 0;
    int j = 1;
	for (j=1;j<v.size();j++)
    {
        if (v[j] < v[mn])
		    mn = j;
    }
    return v[mn];
}

/*******************************************************
Programmer:	Wong Yi Teng
Name: 		findMax
task:		To find the maximum of all three subjects
data in:	Data from file
data returned:	Maximum
*******************************************************/
float findMax(vector<float> v)
{
    cout << setprecision(2) << fixed << showpoint;
    float mx = 0;
    int j = 1;
	for (j=1;j<v.size();j++)
    {
        if (v[j] > v[mx])
		    mx = j;
    }
    return v[mx];
}

/*******************************************************
Programmer:	Wong Yi Teng
Name: 		findMedian
task:		To find the median of all three subjects
data in:	Data from file
data returned:	Median
*******************************************************/
float findMedian(vector<float> v)
{
    cout << setprecision(2) << fixed << showpoint;
    if(v.size()%2 == 0 )
        return (v[v.size()/2] + v[v.size()/2-1])/2;
    else
        return v[v.size()/2];
}

/********************************************************
Programmer:	Wong Yi Teng, Nurul Marsha Binti Zulkifli
Name: 		findMean
task:		To calculate the mean of all three subjects
data in:	Data from file
********************************************************/
void data::findMean(vector<string> &v, int rows)
{
    float sum1 = 0.0, sum2 = 0.0, sum3 = 0.0;
    int recordCount = 0;
    for (int j=0;j<i;j++)
    {
        if (recordCount<rows)
        {
            sum1 += SUB1[j];
            sum2 += SUB2[j];
            sum3 += SUB3[j];
            recordCount++;
        }
    }
    mean1 = sum1 / rows;
    mean2 = sum2 / rows;
    mean3 = sum3 / rows;
}

/************************************************************************************************************************
Programmer:	Nurul Marsha Binti Zulkifli
Name: 		findVariance
task:		To calculate the variance of all three subjects
data in:	Data from file, mean
Referred to: https://www.sciencebuddies.org/science-fair-projects/science-fair/variance-and-standard-deviation (formula)
*************************************************************************************************************************/
void data::findVariance(vector<string> &v, int rows)
{
    findMean(v, rows);
    float v1 = 0.0, v2 = 0.0, v3 = 0.0;
    for(int j=0;j<i;j++)
    {
        v1 += pow((SUB1[j]-mean1),2);
        v2 += pow((SUB2[j]-mean2),2);
        v3 += pow((SUB3[j]-mean3),2);
    }
    variance1 = v1/i;
    variance2 = v2/i;
    variance3 = v3/i;
}

/************************************************************************************************************************
Programmer:	Nurul Marsha Binti Zulkifli
Name: 		findStd
task:		To calculate the standard deviation of all three subjects
data in:	Data from file, variance
Referred to: https://www.sciencebuddies.org/science-fair-projects/science-fair/variance-and-standard-deviation (formula)
*************************************************************************************************************************/
void data::findStd(vector<string> &v, int rows)
{
    findVariance(v, rows);
    stddev1 = sqrt(variance1);
    stddev2 = sqrt(variance2);
    stddev3 = sqrt(variance3);
}

/*********************************************************************
Programmer:	Hii Jyn Tong
Name: 		belowMean3
task:		To find and print data below mean for the third subject
data in:	Data from file, if the number is smaller than the mean
data out:	Data below mean for the third subject
**********************************************************************/
void data::belowMean3(vector<string> &v, int rows)
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << setprecision(2) << fixed << showpoint;
    cout << "\t\t\t\t\t\t\t\t <--------BELOW MEAN-------->\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(0) << "    | " << v.at(1) << " | " << v.at(4) << " |\n";
    cout << "\t\t\t\t\t\t\t\t  --------------------------\n";
    for (int j=0;j<i;j++)
        if (SUB3[j]<mean3)
            cout << "\t\t\t\t\t\t\t\t  | " << ID[j] << " |  " << AGE[j] << " | " << SUB3[j] << " |\n";
    cout << "\t\t\t\t\t\t\t\t  --------------------------\n";
    goback(v, rows);
}

/*********************************************************************
Programmer:	Hii Jyn Tong
Name: 		belowMean2
task:		To find and print data below mean for the second subject
data in:	Data from file, if the number is smaller than the mean
data out:	Data below mean for the second subject
**********************************************************************/
void data::belowMean2(vector<string> &v, int rows)
{
    char c[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << setprecision(2) << fixed << showpoint;
    cout << "\t\t\t\t\t\t\t\t <---------BELOW MEAN--------->\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(0) << "    | " << v.at(1) << " | " << v.at(3) << " |\n";
    cout << "\t\t\t\t\t\t\t\t  ----------------------------\n";
    for (int j=0;j<i;j++)
        if (SUB2[j]<mean2)
            cout << "\t\t\t\t\t\t\t\t  | " << ID[j] << " |  " << AGE[j] << " |  " << SUB2[j] << "  |\n";
    cout << "\t\t\t\t\t\t\t\t  ----------------------------\n";
    cout << "\t\t\t\t\t\t\t\t Press Y to continue, " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if (c[0] == 'Y' && c[1] == '\0')
        C.belowMean3(v, rows);
    else if (c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        C.belowMean2(v, rows);
    }
}

/*********************************************************************
Programmer:	Hii Jyn Tong
Name: 		belowMean1
task:		To find and print data below mean for the first subject
data in:	Data from file, if the number is smaller than the mean
data out:	Data below mean for the first subject
**********************************************************************/
void data::belowMean1(vector<string> &v, int rows)
{
    char c[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << setprecision(2) << fixed << showpoint;
    cout << "\t\t\t\t\t\t\t\t <--------BELOW MEAN-------->\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(0) << "    | " << v.at(1) << " | " << v.at(2) << "  |\n";
    cout << "\t\t\t\t\t\t\t\t  --------------------------\n";
    for (int j=0;j<i;j++)
        if (SUB1[j]<mean1)
            cout << "\t\t\t\t\t\t\t\t  | " << ID[j] << " |  " << AGE[j] << " | " << SUB1[j] << " |\n";
    cout << "\t\t\t\t\t\t\t\t  --------------------------\n";
    cout << "\t\t\t\t\t\t\t\t Press Y to continue, " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if (c[0] == 'Y' && c[1] == '\0')
        C.belowMean2(v, rows);
    else if (c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        C.belowMean1(v, rows);
    }
}

/*********************************************************************
Programmer:	Hii Jyn Tong
Name: 		aboveMean3
task:		To find and print data above mean for the third subject
data in:	Data from file, if the number is greater than the mean
data out:	Data above mean for the third subject
**********************************************************************/
void data::aboveMean3(vector<string> &v, int rows)
{
    char c[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << setprecision(2) << fixed << showpoint;
    cout << "\t\t\t\t\t\t\t\t <--------ABOVE MEAN-------->\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(0) << "    | " << v.at(1) << " | " << v.at(4) << " |\n";
    cout << "\t\t\t\t\t\t\t\t  --------------------------\n";
    for (int j=0;j<i;j++)
        if (SUB3[j]>mean3)
            cout << "\t\t\t\t\t\t\t\t  | " << ID[j] << " |  " << AGE[j] << " | " << SUB3[j] << " |\n";
    cout << "\t\t\t\t\t\t\t\t  --------------------------\n";
    cout << "\t\t\t\t\t\t\t\t Press Y to continue, " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if (c[0] == 'Y' && c[1] == '\0')
        C.belowMean1(v, rows);
    else if (c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        C.aboveMean3(v, rows);
    }
}

/*********************************************************************
Programmer:	Hii Jyn Tong
Name: 		aboveMean2
task:		To find and print data above mean for the second subject
data in:	Data from file, if the number is greater than the mean
data out:	Data above mean for the second subject
**********************************************************************/
void data::aboveMean2(vector<string> &v, int rows)
{
    char c[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << setprecision(2) << fixed << showpoint;
    cout << "\t\t\t\t\t\t\t\t <---------ABOVE MEAN---------->\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(0) << "    | " << v.at(1) << " | " << v.at(3) << " |\n";
    cout << "\t\t\t\t\t\t\t\t  ----------------------------\n";
    for (int j=0;j<i;j++)
        if (SUB2[j]>mean2)
            cout << "\t\t\t\t\t\t\t\t  | " << ID[j] << " |  " << AGE[j] << " |  " << SUB2[j] << "  |\n";
    cout << "\t\t\t\t\t\t\t\t  ----------------------------\n";
    cout << "\t\t\t\t\t\t\t\t Press Y to continue, " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if (c[0] == 'Y' && c[1] == '\0')
        C.aboveMean3(v, rows);
    else if (c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        C.aboveMean2(v, rows);
    }
}

/*********************************************************************
Programmer:	Hii Jyn Tong
Name: 		aboveMean1
task:		To find and print data above mean for the first subject
data in:	Data from file, if the number is greater than the mean
data out:	Data above mean for the first subject
**********************************************************************/
void data::aboveMean1(vector<string> &v, int rows)
{
    char c[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << setprecision(2) << fixed << showpoint;
    cout << "\t\t\t\t\t\t\t\t <--------ABOVE MEAN-------->\n";
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(0) << "    | " << v.at(1) << " | " << v.at(2) << "  |\n";
    cout << "\t\t\t\t\t\t\t\t  --------------------------\n";
    for (int j=0;j<i;j++)
        if (SUB1[j]>mean1)
            cout << "\t\t\t\t\t\t\t\t  | " << ID[j] << " |  " << AGE[j] << " | " << SUB1[j] << " |\n";
    cout << "\t\t\t\t\t\t\t\t  --------------------------\n";
    cout << "\t\t\t\t\t\t\t\t Press Y to continue, " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if (c[0] == 'Y' && c[1] == '\0')
        C.aboveMean2(v, rows);
    else if (c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        C.aboveMean1(v, rows);
    }
}

/**********************************************
Programmer:	Wong Yi Teng
Name: 		printMinimum
task:		To print minimum for all subjects
data in:	Minimum
data out:	Minimum
***********************************************/
void printMinimum(vector<string> &v, int rows)
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t <------MINIMUM------>\n";
    cout << "\t\t\t\t\t\t\t\t  |           Marks |\n";
    cout << "\t\t\t\t\t\t\t\t  -------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(2) << "    | " << findMin(SUB1) << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t  -------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(3) << " | " << findMin(SUB2) << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t  -------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(4) << "   | " << findMin(SUB3) << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t <------------------->\n";
    goback(v, rows);
}

/*********************************************
Programmer:	Wong Yi Teng
Name: 		printMaximum
task:		To print maximum of all subjects
data in:	Maximum
data out:	Maximum
**********************************************/
void printMaximum(vector<string> &v, int rows)
{
    system ("cls"); // clears screen
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t <------MAXIMUM------>\n";
    cout << "\t\t\t\t\t\t\t\t  |           Marks |\n";
    cout << "\t\t\t\t\t\t\t\t  -------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(2) << "    | " << findMax(SUB1) << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t  -------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(3) << " | " << findMax(SUB2) << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t  -------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(4) << "   | " << findMax(SUB3) << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t <------------------->\n";
    goback(v, rows);
}

/*********************************************
Programmer:	Wong Yi Teng
Name: 		printMedian
task:		To print median of all subjects
data in:	Median
data out:	Median
**********************************************/
void printMedian(vector<string> &v, int rows)
{
    system ("cls"); // clears screen
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t <-------MEDIAN------>\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(2) << "    | " << findMedian(SUB1) << " |\n";
    cout << "\t\t\t\t\t\t\t\t  -------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(3) << " | " << findMedian(SUB2) << " |\n";
    cout << "\t\t\t\t\t\t\t\t  -------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(4) << "   | " << findMedian(SUB3) << " |\n";
    cout << "\t\t\t\t\t\t\t\t <------------------->\n";
    goback(v, rows);
}

/*****************************************************
Programmer:	Wong Yi Teng, Nurul Marsha Binti Zulkifli
Name: 		printMean
task:		To print mean of all subjects
data in:	Mean
data out:	Mean
******************************************************/
void data::printMean(vector<string> &v, int rows)
{
    char option[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t <--------MEAN-------->\n";
    cout << setprecision(2) << showpoint << fixed;
    C.findMean(v, rows);
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(2) << " | " << mean1 << "  |" << endl;
    cout << "\t\t\t\t\t\t\t\t  --------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(3) << " | " << mean2 << "  |" << endl;
    cout << "\t\t\t\t\t\t\t\t  --------------------\n";
    cout << "\t\t\t\t\t\t\t\t  |   " << v.at(4) << " | " << mean3 << "  |" << endl;
    cout << "\t\t\t\t\t\t\t\t <-------------------->\n";
    cout << "\t\t\t\t\t\t\t\t Press Y to view data above and below mean, " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> option;
    option[0]=toupper(option[0]);
    if(option[0] == 'Y' && option[1] == '\0')
    {
        C.aboveMean1(v, rows);
        showMenuComputeStats(v, rows);
    }
    else if(option[0] == 'N' && option[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        C.printMean(v, rows);
    }
}

/**********************************************
Programmer:	Nurul Marsha Binti Zulkifli
Name: 		printVariance
task:		To print variance of all subjects
data in:	Variance
data out:	Variance
***********************************************/
void data::printVariance(vector<string> &v, int rows)
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t <-------VARIANCE------->\n";
    cout << setprecision(4) << fixed << showpoint;
    C.findVariance(v, rows);
    cout << "\t\t\t\t\t\t\t\t  |    " << v.at(2) << " | " << variance1 << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t  ----------------------\n";
    cout << "\t\t\t\t\t\t\t\t  | " << v.at(3) << " | " << variance2 << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t  ----------------------\n";
    cout << "\t\t\t\t\t\t\t\t  |   " << v.at(4) << " | " << variance3 << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t <---------------------->\n";
    goback(v, rows);
}

/*******************************************************
Programmer:	Nurul Marsha Binti Zulkifli
Name: 		printStd
task:		To print standard deviation of all subjects
data in:	Standard deviation
data out:	Standard deviation
********************************************************/
void data::printStd(vector<string> &v, int rows)
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t <---STANDARD DEVIATION--->\n";
    cout << setprecision(4) << fixed << showpoint;
    C.findStd(v, rows);
    cout << "\t\t\t\t\t\t\t\t    |    " << v.at(2) << " | " << stddev1 << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t    ---------------------\n";
    cout << "\t\t\t\t\t\t\t\t    | " << v.at(3) << " | " << stddev2 << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t    ---------------------\n";
    cout << "\t\t\t\t\t\t\t\t    |   " << v.at(4) << " | " << stddev3 << " |" << endl;
    cout << "\t\t\t\t\t\t\t\t <------------------------>\n";
    goback(v, rows);
}

/******************************************************************************************************************
Programmer:	Hii Jyn Tong
Name: 		findCorr1
task:		To find correlation between the first subject and the second subject
data in:	Mean
Referred to: https://www.statisticshowto.com/probability-and-statistics/correlation-coefficient-formula/ (formula)
             https://www.statisticshowto.com/covariance/ (formula)
*******************************************************************************************************************/
void data::findCorr1(vector<string> &v, int rows)
{
    C.findStd(v, rows);
    float c1 = 0.0;
    cout << setprecision(4) << fixed << showpoint;
    for(int j=0;j<i;j++)
        c1 += SUB1[j]*SUB2[j];
    covariance1 = c1/i - (mean1*mean2);
    corr1 = covariance1/(stddev1*stddev2);
}

/*******************************************************************************************************************
Programmer:	Hii Jyn Tong
Name: 		findCorr2
task:		To find correlation between the first subject and the third subject
data in:	Mean
Referred to: https://www.statisticshowto.com/probability-and-statistics/correlation-coefficient-formula/ (formula)
             https://www.statisticshowto.com/covariance/ (formula)
********************************************************************************************************************/
void data::findCorr2(vector<string> &v, int rows)
{
    C.findStd(v, rows);
    float c2 = 0.0;
    cout << setprecision(4) << fixed << showpoint;
    for(int j=0;j<i;j++)
        c2 += SUB1[j]*SUB3[j];
    covariance2 = c2/i - (mean1*mean3);
    corr2 = covariance2/(stddev1*stddev3);
}

/******************************************************************************************************************
Programmer:	Hii Jyn Tong
Name: 		findCorr3
task:		To find correlation between the second subject and the third subject
data in:	Mean
Referred to: https://www.statisticshowto.com/probability-and-statistics/correlation-coefficient-formula/ (formula)
             https://www.statisticshowto.com/covariance/ (formula)
*******************************************************************************************************************/
void data::findCorr3(vector<string> &v, int rows)
{
    C.findStd(v, rows);
    float c3 = 0.0;
    cout << setprecision(4) << fixed << showpoint;
    for(int j=0;j<i;j++)
        c3 += SUB2[j]*SUB3[j];
    covariance3 = c3/i - (mean2*mean3);
    corr3 = covariance3/(stddev2*stddev3);
}

/************************************************
Programmer:	Hii Jyn Tong
Name: 		corrMenu
task:		Show menu for Pearson's Correlation
data in:	Choices
*************************************************/
void corrMenu(vector<string> &v, int rows)
{
    char ch[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t -----------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t : * * * * * * * * * * * * * * * * * * * * * * :\n";
    cout << "\t\t\t\t\t\t\t : * <-------------------------------------> * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                     : * :\n";
    cout << "\t\t\t\t\t\t\t : * :        Pearson's Correlation        : * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                     : * :\n";
    cout << "\t\t\t\t\t\t\t : * :        1. " << v.at(2) << " and " << v.at(3) << "          : * :\n";
    cout << "\t\t\t\t\t\t\t : * :        2. " << v.at(2) << " and " << v.at(4) << "            : * :\n";
    cout << "\t\t\t\t\t\t\t : * :        3. " << v.at(3) << " and " << v.at(4) << "         : * :\n";
    cout << "\t\t\t\t\t\t\t : * :        0. Compute Statistics Menu   : * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                     : * :\n";
    cout << "\t\t\t\t\t\t\t : * <-------------------------------------> * :\n";
    cout << "\t\t\t\t\t\t\t : * * * * * * * * * * * * * * * * * * * * * * :\n";
    cout << "\t\t\t\t\t\t\t -----------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t Please enter your choice : ";
    cin >> ch;
    C.printCorr(v, ch, rows);
}

/*********************************************************************************
Programmer:	Hii Jyn Tong
Name: 		gobackC
task:		Go back to correlation menu
*********************************************************************************/
void gobackC(vector<string> &v, int rows)
{
    cout << "\t\t\t\t\t\t\t\t Press enter to go back to correlation menu.";
    cin.get();
    cin.ignore(100, '\n');
    corrMenu(v, rows);
}

/****************************************************************
Programmer:	Hii Jyn Tong
Name: 		printCorr
task:		To print Pearson's correlation between two subjects
data in:	Pearson's Correlation
data out:	Pearson's Correlation
*****************************************************************/
void data::printCorr(vector<string> &v, char ch[], int rows)
{
    char cc[1];
    if (ch[0] == '1' && ch[1] == '\0')
    {
        system ("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t <--------Pearson's Correlation-------->\n\n";
        cout << "\t\t\t\t\t\t\t\t   between " << v.at(2) << " and " << v.at(3) << ":\n";
        C.findCorr1(v, rows);
        cout << "\t\t\t\t\t\t\t\t   " << corr1 << endl;
        cout << "\t\t\t\t\t\t\t\t <------------------------------------->\n";
        gobackC(v, rows);
    }
    else if (ch[0] == '2' && ch[1] == '\0')
    {
        system ("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t <--------Pearson's Correlation-------->\n\n";
        cout << "\t\t\t\t\t\t\t\t   between " << v.at(2) << " and " << v.at(4) << ":\n";
        C.findCorr2(v, rows);
        cout << "\t\t\t\t\t\t\t\t   " << corr2 << endl;
        cout << "\t\t\t\t\t\t\t\t <------------------------------------->\n";
        gobackC(v, rows);
    }
    else if (ch[0] == '3' && ch[1] == '\0')
    {
        system ("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t <--------Pearson's Correlation-------->\n\n";
        cout << "\t\t\t\t\t\t\t\t   between " << v.at(3) << " and " << v.at(4) << ":\n";
        C.findCorr3(v, rows);
        cout << "\t\t\t\t\t\t\t\t   " << corr3 << endl;
        cout << "\t\t\t\t\t\t\t\t <------------------------------------->\n";
        gobackC(v, rows);
    }
    else if (ch[0] == '0' && ch[1] == '\0')
    {
        showMenuComputeStats(v, rows);
    }
    else
    {
        Invalid();
        corrMenu(v, rows);
    }
}

/***********************************************
Programmer:	Hii Jyn Tong
Name: 		LMenu
task:		To show menu of linear regression
data in:	Choices
***********************************************/
void LMenu(vector<string> &v, int rows)
{
    char c[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t -----------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t : * * * * * * * * * * * * * * * * * * * * * * * * * * * * :\n";
    cout << "\t\t\t\t\t\t\t : * <-------------------------------------------------> * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                                 : * :\n";
    cout << "\t\t\t\t\t\t\t : * :              Linear Regression Line             : * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                                 : * :\n";
    cout << "\t\t\t\t\t\t\t : * :              1. " << v.at(2) << "                            : * :\n";
    cout << "\t\t\t\t\t\t\t : * :              2. " << v.at(3) << "                         : * :\n";
    cout << "\t\t\t\t\t\t\t : * :              3. " << v.at(4) << "                           : * :\n";
    cout << "\t\t\t\t\t\t\t : * :              0. Compute Statistics Menu         : * :\n";
    cout << "\t\t\t\t\t\t\t : * :                                                 : * :\n";
    cout << "\t\t\t\t\t\t\t : * <-------------------------------------------------> * :\n";
    cout << "\t\t\t\t\t\t\t : * * * * * * * * * * * * * * * * * * * * * * * * * * * * :\n";
    cout << "\t\t\t\t\t\t\t -----------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t Please enter your choice : " ;
    cin >> c;
    C.printLinear(v, c, rows);
}

/****************************************************************************************************************************************
Programmer:	Hii Jyn Tong
Name: 		findLinear1
task:		To find the equation of linear regression line for the first subject
data in:	mean, covariance
data out:	linear regression
Referred to: https://www.statisticshowto.com/probability-and-statistics/regression-analysis/find-a-linear-regression-equation/ (formula)
*****************************************************************************************************************************************/
void data::findLinear1(vector<string> &v, int rows)
{
    C.findCorr1(v, rows);
    float a1 = 0.0, b1 = 0.0;
    cout << setprecision(4) << fixed << showpoint;
    b1 = covariance1/variance1;
    a1 = mean2-(b1*mean1);
    cout << "\t\t\t\t\t\t\t\t    y'= " << a1 << " + " << b1 << "x\n";
}

/****************************************************************************************************************************************
Programmer:	Hii Jyn Tong
Name: 		findLinear2
task:		To find the equation of linear regression line for the third subject
data in:	mean, covariance
data out:	linear regression
Referred to: https://www.statisticshowto.com/probability-and-statistics/regression-analysis/find-a-linear-regression-equation/ (formula)
*****************************************************************************************************************************************/
void data::findLinear2(vector<string> &v, int rows)
{
    C.findCorr2(v, rows);
    float a2 = 0.0, b2 = 0.0;
    cout << setprecision(4) << fixed << showpoint;
    b2 = covariance2/variance2;
    a2 = mean1-(b2*mean3);
    cout << "\t\t\t\t\t\t\t\t    y'= " << a2 << " + " << b2 << "x\n";
}

/***************************************************************************************************************************************
Programmer:	Hii Jyn Tong
Name: 		findLinear3
task:		To find the equation of linear regression line for the second subject
data in:	mean, covariance
data out:	linear regression
Referred to: https://www.statisticshowto.com/probability-and-statistics/regression-analysis/find-a-linear-regression-equation/ (formula)
*****************************************************************************************************************************************/
void data::findLinear3(vector<string> &v, int rows)
{
    C.findCorr3(v, rows);
    float a3 = 0.0, b3 = 0.0;
    cout << setprecision(4) << fixed << showpoint;
    b3 = covariance3/variance3;
    a3 = mean3-(b3*mean2);
    cout << "\t\t\t\t\t\t\t\t    y'= " << a3 << " + " << b3 << "x\n";
}

/***********************************************
Programmer:	Hii Jyn Tong
Name: 		gobackL
task:		Go back to linear regression menu
***********************************************/
void gobackL(vector<string> &v, int rows)
{
    cout << "\t\t\t\t\t\t\t\t Press enter to go back to regression menu.";
    cin.get();
    cin.ignore(100, '\n');
    LMenu(v, rows);
}

/*************************************************************
Programmer:	Hii Jyn Tong
Name: 		printLinear
task:		To print the equations of linear regression line
data in:	linear regression
data out:	linear regression
**************************************************************/
void data::printLinear(vector<string> &v, char c[], int rows)
{
    if (c[0] == '1' && c[1] == '\0')
    {
        system ("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t <--------Linear Regression Line-------->\n\n";
        cout << "\t\t\t\t\t\t\t\t    " << v.at(2) << ":\n";
        C.findLinear1(v, rows);
        cout << "\t\t\t\t\t\t\t\t <------------------------------------->\n";
        gobackL(v, rows);
    }
    else if (c[0] == '2' && c[1] == '\0')
    {
        system ("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t <--------Linear Regression Line-------->\n\n";
        cout << "\t\t\t\t\t\t\t\t    " << v.at(3) << ":\n";
        C.findLinear3(v, rows);
        cout << "\t\t\t\t\t\t\t\t <------------------------------------->\n";
        gobackL(v, rows);
    }
    else if (c[0] == '3' && c[1] == '\0')
    {
        system ("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t <--------Linear Regression Line-------->\n\n";
        cout << "\t\t\t\t\t\t\t\t    " << v.at(4) << ":\n";
        C.findLinear2(v, rows);
        cout << "\t\t\t\t\t\t\t\t <------------------------------------->\n";
        gobackL(v, rows);
    }
    else if (c[0] == '0' && c[1] == '\0')
    {
        showMenuComputeStats(v, rows);
    }
    else
    {
        Invalid();
        LMenu(v, rows);
    }
}

/******************************************************************************************
Programmer:	Wong Yi Teng
Name: 		findHistogram
task:		Find y-axis of histogram
data in:	maximum, data from file, frequency
data out:	y-axis of histogram
Referred to: https://www.worldbestlearningcenter.com/index_files/cpp-example-histogram.htm
*******************************************************************************************/
void findHistogram(vector<float> subj, int rows)
{
    float mx = findMax(subj);
    int n, fsize;
    n = subj.size();
    if(mx > n)
        fsize = mx + 1;
    else
        fsize = n;
    vector <int> freq(fsize);
    for(int i = 0;i < fsize;i++)
        freq[i] = 0;
    for(int i = 0;i < n;i++)
        freq[subj[i]]++;
    for(int i = 1;i < fsize;i++)
    {
        cout << setw(5) << "\t\t\t\t\t\t\t\t " << i << "| ";
        for(int j = 1;j <= freq[i];j++)
            cout << "*   ";
        cout << endl;
    }
}

/****************************************
Programmer:	Nurul Marsha Binti Zulkifli
Name: 		findHistogram2
task:		Find x-axis of histogram
data in:    data from file, frequency
data out:	x-axis of histogram
*****************************************/
void findHistogram2(vector<float> subj)
{
    int x = 0;
    for (int j = 0; j < i; j++)
    {
        int found = 0;
        for (int n = 0; n < j; n++)
        {
            if (subj[j] == subj[n])
                found++;
        }
        if (found == 0)
        {
            int count = 1;
            for (int n = j + 1; n < i; n++)
            {
                if (subj[j] == subj[n])
                    count++;
            }
            if (x < count)
                x = count;
        }
    }
    cout << "\t\t\t\t\t\t\t\t    ";
    for (int i = 0; i < x + 1; i++)
        cout << "---";
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t     ";
    for (int j = 1; j <= x; j++)
        cout << j << "   ";
    cout << endl;
}

/*********************************************
Programmer:	Wong Yi Teng
Name: 		printHistogram3
task:		Print histogram of third subject
data out:	Histogram
**********************************************/
void printHistogram3(vector<string> &v, int rows)
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t Histogram for " << v.at(4) << endl << endl;
    findHistogram(SUB3, rows);
    findHistogram2(SUB3);
    goback(v, rows);
}

/*********************************************
Programmer:	Wong Yi Teng
Name: 		printHistogram2
task:		Print histogram of second subject
data out:	Histogram
**********************************************/
void printHistogram2(vector<string> &v, int rows)
{
    char c[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t Histogram for " << v.at(3) << endl << endl;
    findHistogram(SUB2, rows);
    findHistogram2(SUB2);
    cout << "\t\t\t\t\t\t\t\t Press Y to view histogram for " << v.at(4) << ", " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if(c[0] == 'Y' && c[1] == '\0')
        printHistogram3(v, rows);
    else if(c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        printHistogram2(v, rows);
    }
}

/*********************************************
Programmer:	Wong Yi Teng
Name: 		printHistogram1
task:		Print histogram of first subject
data out:	Histogram
**********************************************/
void printHistogram1(vector<string> &v, int rows)
{
    char c[1];
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t Histogram for " << v.at(2) << endl << endl;
    findHistogram(SUB1, rows);
    findHistogram2(SUB1);
    cout << "\t\t\t\t\t\t\t\t Press Y to view histogram for " << v.at(3) << ", " << endl;
    cout << "\t\t\t\t\t\t\t\t press N to go back to compute statistics menu. ";
    cin >> c;
    c[0]=toupper(c[0]);
    if(c[0] == 'Y' && c[1] == '\0')
        printHistogram2(v, rows);
    else if(c[0] == 'N' && c[1] == '\0')
        showMenuComputeStats(v, rows);
    else
    {
        Invalid();
        printHistogram1(v, rows);
    }
}

/***********************************************
Programmer:	Hii Jyn Tong
Name: 		computeStatsChoice
task:		Choices of compute statistics menu
data out:	Choices
************************************************/
void data::computeStatsChoice(vector<string> &v, int rows)
{
    if (choice_computeStats[0] == '1' && choice_computeStats[1] == '\0')
        printMinimum(v, rows);
    else if (choice_computeStats[0] == '2' && choice_computeStats[1] == '\0')
        printMaximum(v, rows);
    else if (choice_computeStats[0] == '3' && choice_computeStats[1] == '\0')
        printMedian(v, rows);
    else if (choice_computeStats[0] == '4' && choice_computeStats[1] == '\0')
        C.printMean(v, rows);
    else if (choice_computeStats[0] == '5' && choice_computeStats[1] == '\0')
        C.printVariance(v, rows);
    else if (choice_computeStats[0] == '6' && choice_computeStats[1] == '\0')
        C.printStd(v, rows);
    else if (choice_computeStats[0] == '7' && choice_computeStats[1] == '\0')
        corrMenu(v, rows);
    else if (choice_computeStats[0] == '8' && choice_computeStats[1] == '\0')
        LMenu(v, rows);
    else if (choice_computeStats[0] == '9' && choice_computeStats[1] == '\0')
        printFrequency1(v, rows);
    else if (choice_computeStats[0] == '1' && choice_computeStats[1] == '0' && choice_computeStats[2] == '\0')
       printHistogram1(v, rows);
    else if (choice_computeStats[0] == '0' && choice_computeStats[1] == '\0')
        showMenu();
    else
    {
        Invalid();
        showMenuComputeStats(v, rows);
    }
}

/*****************************************
Programmer:	Maria Mithi
Name: 		bubbleSort
task:		To sort the data from file
data in:	data from file
*****************************************/
void bubbleSort(vector<float>& a)
{
    bool swapp = true;
    while(swapp)
    {
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++)
        {
            if (a[i]>a[i+1] )
            {
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}

/********************************************************
Programmer:	Maria Mithi
Name: 		sortData
task:		To print sorted data for statistical report
data in:	sorted data
data out: sorted data
*********************************************************/
void sortData(vector<string> &v)
{
    outfile << "<---------Sorted Data---------->\n";
    outfile << "  | " << v.at(2) << "  | " << v.at(3) << " | " << v.at(4) << " |" << endl;
    bubbleSort(SUB1);
    bubbleSort(SUB2);
    bubbleSort(SUB3);
    for(int j=0;j<i;j++)
        outfile << "  | " << SUB1[j] << " | " << SUB2[j] << "    | " << SUB3[j] << " |" << endl;
    outfile << "<----------------------------------->\n";
    outfile << endl;
}

/**************************************************************************
Programmer:	Maria Mithi
Name: 		statsFrequency1
task:		To print frequency of the first subject for statistical report
data in:	Frequency for first subject
data out: Frequency for first subject
***************************************************************************/
void statsFrequency1(vector<string> &v, int rows)
{
    map<int, int> M;
    for (int i=0; i<rows; i++)
    {
        if (M.find(SUB1[i]) == M.end())
            M[SUB1[i]] = 1;
        else
            M[SUB1[i]]++;
    }
    outfile << "Frequency of " << v.at(2) << endl;
    for (auto& it : M)
        outfile << it.first << " occurred " << it.second << " times" << endl;
    outfile << endl;
}

/***************************************************************************
Programmer:	Maria Mithi
Name: 		statsFrequency2
task:		To print frequency of the second subject for statistical report
data in:	Frequency for second subject
data out: Frequency for second subject
****************************************************************************/
void statsFrequency2(vector<string> &v, int rows)
{
    map<int, int> M;
    for (int i=0; i<rows; i++)
    {
        if (M.find(SUB2[i]) == M.end())
            M[SUB2[i]] = 1;
        else
            M[SUB2[i]]++;
    }
    outfile << "Frequency of " << v.at(3) << endl;
    for (auto& it : M)
        outfile << it.first << " occurred " << it.second << " times" << endl;
    outfile << endl;
}

/**************************************************************************
Programmer:	Maria Mithi
Name: 		statsFrequency3
task:		To print frequency of the third subject for statistical report
data in:	Frequency for third subject
data out: Frequency for third subject
***************************************************************************/
void statsFrequency3(vector<string> &v, int rows)
{
    map<int, int> M;
    for (int i=0; i<rows; i++)
    {
        if (M.find(SUB3[i]) == M.end())
            M[SUB3[i]] = 1;
        else
            M[SUB3[i]]++;
    }
    outfile << "Frequency of " << v.at(4) << endl;
    for (auto& it : M)
        outfile << it.first << " occurred " << it.second << " times" << endl;
    outfile << endl;
}

/***************************************************************************
Programmer:	Maria Mithi
Name: 		statsDistinct
task:		To print distinct numbers of all subject for statistical report
data in:	Distinct numbers
data out:   Distinct numbers
****************************************************************************/
void statsDistinct(vector<string> &v, int rows)
{
    countDistinct(v, rows);
    outfile << "Distinct Numbers\n";
    outfile << v.at(2) << " : " << res1 << endl;
    outfile << v.at(3) << " : " << res2 << endl;
    outfile << v.at(4) << " : " << res3 << endl << endl;
}

/******************************************************************************
Programmer:	Maria Mithi
Name: 		StatsHistogram
task:		To print y-axis of histogram of all subject for statistical report
data in:	y-axis of Histogram
data out:   y-axis of Histogram
*******************************************************************************/
void StatsHistogram(vector<float> subj, int rows)
{
    float mx = findMax(subj);
    int n, fsize;
    n = subj.size();
    if(mx > n)
        fsize = mx + 1;
    else
        fsize = n;
    vector <int> freq(fsize);
    for(int i = 0;i < fsize;i++)
        freq[i] = 0;
    for(int i = 0;i < n;i++)
        freq[subj[i]]++;
    for(int i = 1;i < fsize;i++)
    {
        outfile << setw(5) << i << "| ";
        for(int j = 1;j <= freq[i];j++)
            outfile << "*   ";
        outfile << endl;
    }
}

/******************************************************************************
Programmer:	Maria Mithi
Name: 		StatsHistogram2
task:		To print x-axis of histogram of all subject for statistical report
data in:	x-axis of Histogram
data out:   x-axis of Histogram
*******************************************************************************/
void StatsHistogram2(vector<float> subj)
{
    int x = 0;
    for (int j = 0; j < i; j++)
    {
        int found = 0;
        for (int n = 0; n < j; n++)
        {
            if (subj[j] == subj[n])
                found++;
        }
        if (found == 0)
        {
            int count = 1;
            for (int n = j + 1; n < i; n++)
            {
                if (subj[j] == subj[n])
                    count++;
            }
            if (x < count)
                x = count;
        }
    }
    outfile << "         ";
    for (int i = 0; i < x + 1; i++)
        outfile << "---";
    outfile << endl;
    outfile << "          ";
    for (int j = 1; j <= x; j++)
        outfile << j << "   ";
    outfile << endl << endl;
}

/*********************************************************************************
Programmer:	Maria Mithi
Name: 		StatsAbove1
task:		To print data above mean of the first subject for statistical report
data in:	Data above mean of first subject
data out:   Data above mean of first subject
**********************************************************************************/
void data::StatsAbove1(vector<string> &v)
{
    outfile << "Above Mean\n";
    for (int j=0;j<i;j++)
        if (SUB1[j]>mean1)
        {
            outfile << v.at(0) << ": " << ID[j] << "  "
                    << v.at(1) << ": " << AGE[j] << "  "
                    << v.at(2) << ": " << SUB1[j] << endl;
        }
    outfile << endl;
}

/*********************************************************************************
Programmer:	Maria Mithi
Name: 		StatsAbove2
task:		To print data above mean of the second subject for statistical report
data in:	Data above mean of second subject
data out:   Data above mean of second subject
**********************************************************************************/
void data::StatsAbove2(vector<string> &v)
{
    outfile << "Above Mean\n";
    for (int j=0;j<i;j++)
        if (SUB2[j]>mean2)
        {
            outfile << v.at(0) << ": " << ID[j] << "  "
                    << v.at(1) << ": " << AGE[j] << "  "
                    << v.at(3) << ": " << SUB2[j] << endl;
        }
    outfile << endl;
}

/*********************************************************************************
Programmer:	Maria Mithi
Name: 		StatsAbove3
task:		To print data above mean of the third subject for statistical report
data in:	Data above mean of third subject
data out:   Data above mean of third subject
**********************************************************************************/
void data::StatsAbove3(vector<string> &v)
{
    outfile << "Above Mean\n";
    for (int j=0;j<i;j++)
        if (SUB3[j]>mean3)
        {
            outfile << v.at(0) << ": " << ID[j] << "  "
                    << v.at(1) << ": " << AGE[j] << "  "
                    << v.at(4) << ": " << SUB3[j] << endl;
        }
    outfile << endl;
}

/*********************************************************************************
Programmer:	Maria Mithi
Name: 		StatsBelow1
task:		To print data below mean of the first subject for statistical report
data in:	Data below mean of first subject
data out:   Data below mean of first subject
**********************************************************************************/
void data::StatsBelow1(vector<string> &v)
{
    outfile << "Below Mean\n";
    for (int j=0;j<i;j++)
        if (SUB1[j]<mean1)
        {
            outfile << v.at(0) << ": " << ID[j] << "  "
                    << v.at(1) << ": " << AGE[j] << "  "
                    << v.at(2) << ": " << SUB1[j] << endl;
        }
    outfile << endl;
}

/*********************************************************************************
Programmer:	Maria Mithi
Name: 		StatsAbove2
task:		To print data below mean of the second subject for statistical report
data in:	Data below mean of second subject
data out:   Data below mean of second subject
**********************************************************************************/
void data::StatsBelow2(vector<string> &v)
{
    outfile << "Below Mean\n";
    for (int j=0;j<i;j++)
        if (SUB2[j]<mean2)
        {
            outfile << v.at(0) << ": " << ID[j] << "  "
                    << v.at(1) << ": " << AGE[j] << "  "
                    << v.at(3) << ": " << SUB2[j] << endl;
        }
    outfile << endl;
}

/*********************************************************************************
Programmer:	Maria Mithi
Name: 		StatsAbove3
task:		To print data below mean of the third subject for statistical report
data in:	Data below mean of third subject
data out:   Data below mean of third subject
**********************************************************************************/
void data::StatsBelow3(vector<string> &v)
{
    outfile << "Below Mean\n";
    for (int j=0;j<i;j++)
        if (SUB3[j]<mean3)
        {
            outfile << v.at(0) << ": " << ID[j] << "  "
                    << v.at(1) << ": " << AGE[j] << "  "
                    << v.at(4) << ": " << SUB3[j] << endl;
        }
    outfile << endl;
}

/*********************************************************************
Programmer:	Maria Mithi
Name: 		StatsMin
task:		To print minimum of all subjects for statistical report
data in:	Minimum
data out:   Minimum
**********************************************************************/
void StatsMin(vector<string> &v)
{
    outfile << "Minimum" << endl;
    outfile << v.at(2) << ": " << findMin(SUB1) << endl;
    outfile << v.at(3) << ": " << findMin(SUB2) << endl;
    outfile << v.at(4) << ": " << findMin(SUB3) << endl << endl;
}

/*********************************************************************
Programmer:	Maria Mithi
Name: 		StatsMax
task:		To print maximum of all subjects for statistical report
data in:	Maximum
data out:   Maximum
**********************************************************************/
void StatsMax(vector<string> &v)
{
    outfile << "Maximum" << endl;
    outfile << v.at(2) << ": " << findMax(SUB1) << endl;
    outfile << v.at(3) << ": " << findMax(SUB2) << endl;
    outfile << v.at(4) << ": " << findMax(SUB3) << endl << endl;
}

/*********************************************************************
Programmer:	Maria Mithi
Name: 		findStatsMedian
task:		To print median of all subjects for statistical report
data in:	Median
data out:   Median
**********************************************************************/
float findStatsMedian(vector<string> &v)
{
    outfile << "Median" << endl;
    outfile << v.at(2) << ": " << findMedian(SUB1) << endl;
    outfile << v.at(3) << ": " << findMedian(SUB2) << endl;
    outfile << v.at(4) << ": " << findMedian(SUB3) << endl << endl;
}

/*********************************************************************
Programmer:	Maria Mithi
Name: 		findStatsMean
task:		To print mean of all subjects for statistical report
data in:	Mean
data out:   Mean
**********************************************************************/
void data::findStatsMean(vector<string> &v, int rows)
{
    C.findMean(v, rows);
    outfile << "Mean" << endl;
    outfile << v.at(2) << ": " << mean1 << endl;
    outfile << v.at(3) << ": " << mean2 << endl;
    outfile << v.at(4) << ": " << mean3 << endl << endl;
}

/*********************************************************************
Programmer:	Maria Mithi
Name: 		findStatsVar
task:		To print variance of all subjects for statistical report
data in:	Variance
data out:   Variance
**********************************************************************/
void data::findStatsVar(vector<string> &v, int rows)
{
    C.findVariance(v, rows);
    outfile << "Variance" << endl;
    outfile << v.at(2) << ": " << variance1 << endl;
    outfile << v.at(3) << ": " << variance2 << endl;
    outfile << v.at(4) << ": " << variance3 << endl << endl;
}

/******************************************************************************
Programmer:	Maria Mithi
Name: 		findStatsStd
task:		To print standard deviation of all subjects for statistical report
data in:	Standard deviation
data out:   Standard deviation
*******************************************************************************/
void data::findStatsStd(vector<string> &v, int rows)
{
    C.findStd(v, rows);
    outfile << "Standard Deviation" << endl;
    outfile << v.at(2) << ": " << stddev1 << endl;
    outfile << v.at(3) << ": " << stddev2 << endl;
    outfile << v.at(4) << ": " << stddev3 << endl << endl;
}

/*****************************************************************
Programmer:	Maria Mithi
Name: 		findStatsCorr
task:		To print Pearson's correlation for statistical report
data in:	Pearson's correlation
data out:   Pearson's correlation
******************************************************************/
void data::findStatsCorr(vector<string> &v, int rows)
{
    outfile << "Pearson's Correlation" << endl;
    C.findCorr1(v, rows);
    outfile << v.at(2) << " and " << v.at(3) << ": " << corr1 << endl;
    C.findCorr2(v, rows);
    outfile << v.at(2) << " and " << v.at(4) << ": " << corr2 << endl;
    C.findCorr3(v, rows);
    outfile << v.at(3) << " and " << v.at(4) << ": " << corr3 << endl << endl;
}

/***********************************************************************************
Programmer:	Maria Mithi
Name: 		findStatsLinear1
task:		To print linear regression of the first subject for statistical report
data in:	Linear regression of the first subject
data out:   Linear regression of the first subject
************************************************************************************/
void data::findStatsLinear1(vector<string> &v, int rows)
{
    C.findCorr1(v, rows);
    x = covariance1/variance1;
    y = mean2-(x*mean1);
}

/***********************************************************************************
Programmer:	Maria Mithi
Name: 		findStatsLinear2
task:		To print linear regression of the second subject for statistical report
data in:	Linear regression of the second subject
data out:   Linear regression of the second subject
************************************************************************************/
void data::findStatsLinear2(vector<string> &v, int rows)
{
    C.findCorr2(v, rows);
    x = covariance2/variance2;
    y = mean1-(x*mean3);
}

/***********************************************************************************
Programmer:	Maria Mithi
Name: 		findStatsLinear3
task:		To print linear regression of the third subject for statistical report
data in:	Linear regression of the third subject
data out:   Linear regression of the third subject
************************************************************************************/
void data::findStatsLinear3(vector<string> &v, int rows)
{
    C.findCorr3(v, rows);
    x = covariance3/variance3;
    y = mean3-(x*mean2);
}

/************************************************
Programmer:	Maria Mithi
Name: 		printStats
task:		To open and print statistical report
*************************************************/
void printStats(vector<string> &v, int rows)
{
    char c[1];
    system("cls");
    outfile.open("statistical report.txt");
    statsFrequency1(v, rows);
    statsFrequency2(v, rows);
    statsFrequency3(v, rows);
    statsDistinct(v, rows);
    outfile << "   Histogram of " << v.at(2) << endl;
    StatsHistogram(SUB1, rows);
    StatsHistogram2(SUB1);
    outfile << "   Histogram of " << v.at(3) << endl;
    StatsHistogram(SUB2, rows);
    StatsHistogram2(SUB2);
    outfile << "   Histogram of " << v.at(4) << endl;
    StatsHistogram(SUB3, rows);
    StatsHistogram2(SUB3);
    outfile << setprecision(2) << fixed << showpoint;
    sortData(v);
    StatsMin(v);
    StatsMax(v);
    findStatsMedian(v);
    C.findStatsMean(v, rows);
    C.StatsAbove1(v);
    C.StatsAbove2(v);
    C.StatsAbove3(v);
    C.StatsBelow1(v);
    C.StatsBelow2(v);
    C.StatsBelow3(v);
    outfile << setprecision(4) << fixed << showpoint;
    C.findStatsVar(v, rows);
    C.findStatsStd(v, rows);
    C.findStatsCorr(v, rows);
    outfile << "Linear Regression Line Equation" << endl;
    C.findStatsLinear1(v, rows);
    outfile << v.at(2) << ": y'= " << x << " + " << y << "x" << endl;
    C.findStatsLinear2(v, rows);
    outfile << v.at(3) << ": y'= " << x << " + " << y << "x" << endl;
    C.findStatsLinear3(v, rows);
    outfile << v.at(4) << ": y'= " << x << " + " << y << "x" << endl;
    outfile.close();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t Statistical Report generated!\n";
    cout << "\t\t\t\t\t\t\t Press Y to go back to main menu and N to exit \n";
    cout << "\t\t\t\t\t\t\t ";
    cin >> c;
    c[0]=toupper(c[0]);
    if (c[0] == 'Y' && c[1] == '\0')
        showMenu();
    else if (c[0] == 'N' && c[1] == '\0')
        exit(1);
    else
    {
        Invalid();
        printStats(v, rows);
    }
}

/****************************************
Programmer: Wong Yi Teng
Name: 		dataHTML
task:		To generate HTML document
data in:	Data from file
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void dataHTML(vector<string> v,int cols)
{
    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<style>" << endl;
    HTML << "table,th {width:20%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th{padding: 5px; text-align:center;}" << endl;
    HTML << "body {background-color: lightblue;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<h2 style=\"font-size:300%;text-align:center;\"> Report</h2>" << endl;
    HTML << " <link rel=\"stylesheet\" href=\"https://www.w3schools.com/w3css/4/w3.css\">" << endl;
    HTML << "<style>" << endl;
    HTML << "td{padding: 5px; text-align:center;}" << endl;
    HTML << "</style>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;

    HTML << "<tr>" << endl;
    for (int j=0;j<cols;j++)
        HTML << "<th>" << v[j] << "</th>" << endl;
    HTML << "</tr>" << endl;

    HTML << "<tr>" << endl;
    for (int j=0;j<i;j++)
    {
        HTML << "<td>" << ID[j] << "</td>" <<  "<td>" << AGE[j] << "</td>" << "<td>" << SUB1[j] << "</td>" ;
        HTML << "<td>" << SUB2[j] << "</td>" << "<td>" << SUB3[j] << "</td>" << endl;
        HTML << "</tr>" << endl;
    }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Maria Mithi
Name: 		HTMLSorted
task:		To generate HTML document
data in:	Sorted data
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void HTMLSorted(vector<string> &v)
{
    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<style>" << endl;
    HTML << "table,th {width:20%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th{padding: 5px; text-align:center;}" << endl;
    HTML << "body {background-color: lightblue;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Sorted Data</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td scope=\"col\"><strong>" << v.at(2) << "</strong></td>\n" ;
    HTML << " <td scope=\"col\"><strong>" << v.at(3) << "</strong></td>\n";
    HTML << " <td scope=\"col\"><strong>" << v.at(4) << "</strong></td>\n";
    HTML << "</tr>" << endl;

    bubbleSort(SUB1);
    bubbleSort(SUB2);
    bubbleSort(SUB3);
    HTML << "<tr>" << endl;
    for(int j=0;j<i;j++)
    {
        HTML << "<td>" << SUB1[j] << "</td>" << "<td>" << SUB2[j]
             << "</td>" << "<td>" << SUB3[j] << "</td>" << endl;
        HTML << "</tr>" << endl;
    }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Maria Mithi
Name: 		HTMLFreq1
task:		To generate HTML document
data in:	Frequency of first subject
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void HTMLFreq1(vector<string> &v, int rows)
{
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Frequency of " << v.at(2) << "</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td scope=\"col\"><strong>MARKS</strong></td>\n" ;
    HTML << " <td scope=\"col\"><strong>OCCURENCES</strong></td>\n";
    HTML << "</tr>" << endl;

    HTML << setprecision(2) << fixed << showpoint;
    map<int, int> M;
    for (int i=0; i<rows; i++)
    {
        if (M.find(SUB1[i]) == M.end())
            M[SUB1[i]] = 1;
        else
            M[SUB1[i]]++;
    }

    for (auto& it : M)
    {
        HTML << "<td>" << it.first << "</td>" << "<td>" << it.second << "</td>";
        HTML << "</tr>" << endl;
    }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Maria Mithi
Name: 		HTMLFreq2
task:		To generate HTML document
data in:	Frequency of second subject
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void HTMLFreq2(vector<string> &v, int rows)
{
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Frequency of " << v.at(3) << "</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td scope=\"col\"><strong>MARKS</strong></td>\n" ;
    HTML << " <td scope=\"col\"><strong>OCCURENCES</strong></td>\n";
    HTML << "</tr>" << endl;

    HTML << setprecision(2) << fixed << showpoint;
    map<int, int> M;
    for (int i=0; i<rows; i++)
    {
        if (M.find(SUB2[i]) == M.end())
            M[SUB2[i]] = 1;
        else
            M[SUB2[i]]++;
    }

    for (auto& it : M)
    {
        HTML << "<td>" << it.first << "</td>" << "<td>" << it.second << "</td>";
        HTML << "</tr>" << endl;
    }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Maria Mithi
Name: 		HTMLFreq3
task:		To generate HTML document
data in:	Frequency of third subject
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void HTMLFreq3(vector<string> &v, int rows)
{
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Frequency of " << v.at(4) << "</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td scope=\"col\"><strong>MARKS</strong></td>\n" ;
    HTML << " <td scope=\"col\"><strong>OCCURENCES</strong></td>\n";
    HTML << "</tr>" << endl;

    HTML << setprecision(2) << fixed << showpoint;
    map<int, int> M;
    for (int i=0; i<rows; i++)
    {
        if (M.find(SUB3[i]) == M.end())
            M[SUB3[i]] = 1;
        else
            M[SUB3[i]]++;
    }

    for (auto& it : M)
    {
        HTML << "<td>" << it.first << "</td>" << "<td>" << it.second << "</td>";
        HTML << "</tr>" << endl;
    }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Maria Mithi
Name: 		HTMLDistinct
task:		To generate HTML document
data in:	Distinct numbers
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void HTMLDistinct(vector<string> &v, int rows)
{
    countDistinct(v, rows);
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Distinct Numbers</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;

    HTML << "<td>" << "<strong>" << v.at(2) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << res1 << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(3) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << res2 << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(4) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << res3 << "</td>";
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Wong Yi Teng
Name: 		maxHTML
task:		To generate HTML document
data in:	Maximum
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void maxHTML(vector<string> v)
{
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Maximum</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td></td>" << endl;
    HTML << "<td><strong>MARKS</strong></td>" << endl;
    HTML << "</tr>" << endl;

    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<tr>";
    HTML << "<td>" << "<strong>" << v.at(2) << "</strong>" << "</td>";
    HTML << "<td>" << findMax(SUB1) << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<tr>";
    HTML << "<td>" << "<strong>" << v.at(3) << "</strong>" << "</td>";
    HTML << "<td>" << findMax(SUB2) << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<tr>";
    HTML << "<td>" << "<strong>" << v.at(4) << "</strong>" << "</td>";
    HTML << "<td>" << findMax(SUB3) << "</td>";
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Wong Yi Teng
Name: 		minHTML
task:		To generate HTML document
data in:	Minimum
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void minHTML(vector<string> v)
{
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Minimum</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td></td>" << endl;
    HTML << "<td><strong>MARKS</strong></td>" << endl;
    HTML << "</tr>" << endl;

    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<tr>";
    HTML << "<td>" << "<strong>" << v.at(2) << "</strong>" << "</td>";
    HTML << "<td>" << findMin(SUB1) << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<tr>";
    HTML << "<td>" << "<strong>" << v.at(3) << "</strong>" << "</td>";
    HTML << "<td>" << findMin(SUB2) << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<tr>";
    HTML << "<td>" << "<strong>" << v.at(4) << "</strong>" << "</td>";
    HTML << "<td>" << findMin(SUB3) << "</td>";
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Wong Yi Teng
Name: 		medianHTML
task:		To generate HTML document
data in:	Median
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void medianHTML(vector<string> v)
{
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Median</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td scope=\"col\"><strong>SUBJECTS</strong></td>\n" ;
    HTML << " <td scope=\"col\"><strong>MARKS</strong></td>\n";
    HTML << "</tr>" << endl;

    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<td>" << "<strong>" << v.at(2) << "</strong>" << "</td>";
    HTML <<  "<td>" << findMedian(SUB1) << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(3) << "</strong>" << "</td>";
    HTML <<  "<td>" << findMedian(SUB2) << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(4) << "</strong>" << "</td>";
    HTML <<  "<td>" << findMedian(SUB3) << "</td>";
    HTML << " </tr>" << endl;
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		meanHTML
task:		To generate HTML document
data in:	Mean
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::meanHTML(vector<string> &v, int rows)
{
    C.findMean(v, rows);
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Mean</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td scope=\"col\"><strong>SUBJECTS</strong></td>\n" ;
    HTML << " <td scope=\"col\"><strong>MARKS</strong></td>\n";
    HTML << "</tr>" << endl;

    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<td>" << "<strong>" << v.at(2) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << mean1 << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(3) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << mean2 << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(4) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << mean3 << "</td>";
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		varianceHTML
task:		To generate HTML document
data in:	Variance
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::varianceHTML(vector<string> &v, int rows)
{
    C.findVariance(v, rows);
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Variance</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td scope=\"col\"><strong>SUBJECTS</strong></td>\n" ;
    HTML << " <td scope=\"col\"><strong>MARKS</strong></td>\n";
    HTML << "</tr>" << endl;

    HTML << setprecision(4) << fixed << showpoint;
    HTML << "<td>" << "<strong>" << v.at(2) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << variance1 << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(3) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << variance2 << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(4) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << variance3 << "</td>";
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		stdHTML
task:		To generate HTML document
data in:	Standard deviation
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::stdHTML(vector<string> &v, int rows)
{
    C.findStd(v, rows);
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Standard Deviation</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<td scope=\"col\"><strong>SUBJECTS</strong></td>\n" ;
    HTML << " <td scope=\"col\"><strong>MARKS</strong></td>\n";
    HTML << "</tr>" << endl;

    HTML << setprecision(4) << fixed << showpoint;
    HTML << "<td>" << "<strong>" << v.at(2) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << stddev1 << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(3)<< "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << stddev2 << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(4) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << stddev3 << "</td>";
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		Above1HTML
task:		To generate HTML document
data in:	Above mean of first subject
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::Above1HTML(vector<string> v, int rows)
{
    C.findMean(v, rows);
    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Above Mean</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << " <td scope=\"col\"><strong>ID</strong></td>\n";
    HTML << " <td scope=\"col\"><strong>AGE</strong></td>\n";
    HTML << " <td scope=\"col\">" << "<strong>" << v.at(2) << "</strong>" << "</td>\n";
    HTML << "</tr>" << endl;

    HTML << "<tr> " << endl;
    for (int j=0;j<i;j++)
        if (SUB1[j]>mean1)
        {
            HTML << "<td>" << ID[j] << "</td>" << "<td>" << AGE[j] << "</td>" << "<td>" << SUB1[j] << "</td>" << endl;
            HTML << "</tr>" << endl;
        }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		Above2HTML
task:		To generate HTML document
data in:	Above mean of second subject
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::Above2HTML(vector<string> v, int rows)
{
    C.findMean(v, rows);
    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Above Mean</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << " <td scope=\"col\"><strong>ID</strong></td>\n";
    HTML << " <td scope=\"col\"><strong>AGE</strong></td>\n";
    HTML << " <td scope=\"col\">" << "<strong>" << v.at(3) << "</strong>" << "</td>\n";
    HTML << "</tr>" << endl;

    HTML << "<tr> " << endl;
    for (int j=0;j<i;j++)
        if (SUB2[j]>mean2)
        {
            HTML << "<td>" << ID[j] << "</td>" << "<td>" << AGE[j] << "</td>" << "<td>" << SUB2[j] << "</td>" << endl;
            HTML << "</tr>" << endl;
        }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		Above3HTML
task:		To generate HTML document
data in:	Above mean of third subject
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::Above3HTML(vector<string> v, int rows)
{
    C.findMean(v, rows);
    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Above Mean</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << " <td scope=\"col\"><strong>ID</strong></td>\n";
    HTML << " <td scope=\"col\"><strong>AGE</strong></td>\n";
    HTML << " <td scope=\"col\">" << "<strong>" << v.at(4) << "</strong>" << "</td>\n";
    HTML << "</tr>" << endl;

    HTML << "<tr> " << endl;
    for (int j=0;j<i;j++)
        if (SUB3[j]>mean3)
        {
            HTML << "<td>" << ID[j] << "</td>" << "<td>" << AGE[j] << "</td>" << "<td>" << SUB3[j] << "</td>" << endl;
            HTML << "</tr>" << endl;
        }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		Below1HTML
task:		To generate HTML document
data in:	Below mean of first subject
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::Below1HTML(vector<string> v, int rows)
{
    C.findMean(v, rows);
    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Below Mean</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << " <td scope=\"col\"><strong>ID</strong></td>\n";
    HTML << " <td scope=\"col\"><strong>AGE</strong></td>\n";
    HTML << " <td scope=\"col\">" << "<strong>" << v.at(2) << "</strong>" << "</td>\n";
    HTML << "</tr>" << endl;

    HTML << "<tr> " << endl;
    for (int j=0;j<i;j++)
        if (SUB1[j]<mean1)
        {
            HTML << "<td>" << ID[j] << "</td>" << "<td>" << AGE[j] << "</td>" << "<td>" << SUB1[j] << "</td>" << endl;
            HTML << "</tr>" << endl;
        }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		Below2HTML
task:		To generate HTML document
data in:	Below mean of second subject
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::Below2HTML(vector<string> v, int rows)
{
    C.findMean(v, rows);
    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Below Mean</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << " <td scope=\"col\"><strong>ID</strong></td>\n";
    HTML << " <td scope=\"col\"><strong>AGE</strong></td>\n";
    HTML << " <td scope=\"col\">" << "<strong>" << v.at(3) << "</strong>" << "</td>\n";
    HTML << "</tr>" << endl;

    HTML << "<tr> " << endl;
    for (int j=0;j<i;j++)
        if (SUB2[j]<mean2)
        {
            HTML << "<td>" << ID[j] << "</td>" << "<td>" << AGE[j] << "</td>" << "<td>" << SUB2[j] << "</td>" << endl;
            HTML << "</tr>" << endl;
        }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		Below3HTML
task:		To generate HTML document
data in:	Below mean of third subject
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::Below3HTML(vector<string> v, int rows)
{
    C.findMean(v, rows);
    HTML << setprecision(2) << fixed << showpoint;
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Below Mean</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << " <td scope=\"col\"><strong>ID</strong></td>\n";
    HTML << " <td scope=\"col\"><strong>AGE</strong></td>\n";
    HTML << " <td scope=\"col\">" << "<strong>" << v.at(4) << "</strong>" << "</td>\n";
    HTML << "</tr>" << endl;

    HTML << "<tr> " << endl;
    for (int j=0;j<i;j++)
        if (SUB3[j]<mean3)
        {
            HTML << "<td>" << ID[j] << "</td>" << "<td>" << AGE[j] << "</td>" << "<td>" << SUB3[j] << "</td>" << endl;
            HTML << "</tr>" << endl;
        }
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		CorrHTML
task:		To generate HTML document
data in:	Pearson's correlation
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::CorrHTML(vector<string> v, int rows)
{
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Pearson's Correlation</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;
    HTML << setprecision(4) << fixed << showpoint;

    C.findCorr1(v, rows);
    HTML << "<td>" << "<strong>" << v.at(2) << " and " << v.at(3) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << corr1 << "</td>";
    HTML << "</tr>" << endl;

    C.findCorr2(v, rows);
    HTML << "<td>" << "<strong>" << v.at(2) << " and " << v.at(4) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << corr2 << "</td>";
    HTML << "</tr>" << endl;

    C.findCorr3(v, rows);
    HTML << "<td>" << "<strong>" << v.at(3) << " and " << v.at(4) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << corr3 << "</td>";
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
}

/****************************************
Programmer: Hii Jyn Tong
Name: 		L_HTML
task:		To generate HTML document
data in:	Linear regression
data out:   HTML Document
Referred to: https://www.w3schools.com/
*****************************************/
void data::L_HTML(vector<string> v, int rows)
{
    HTML << "<style>" << endl;
    HTML << "table{width:50%;margin-left:auto;margin-right:auto;}" << endl;
    HTML << "table, th, td {border: 1px solid black;border-collapse: collapse;}" << endl;
    HTML << "th, td {padding: 5px; text-align: center;}" << endl;
    HTML << "th {background-color: #90EE90;color: black;}" << endl;
    HTML << "th, td {font-size: 15px;}" << endl;
    HTML << "tr:nth-child(even){background-color: #f2f2f2}" << endl;
    HTML << "tr:nth-child(odd){background-color: #FFFFFF}" << endl;
    HTML << "</style>" << endl;
    HTML << "<br></br>" << endl;

    HTML << "<table style=\"width:50%\">" << endl;
    HTML << "<tr>" << endl;
    HTML << "<th>Linear Regression Line Equation</th>" << endl;
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
    HTML << "<table style=\"width:50%\">" << endl;

    C.findCorr1(v, rows);
    C.findCorr2(v, rows);
    C.findCorr3(v, rows);
    float a1 = 0.0, b1 = 0.0;
    float a2 = 0.0, b2 = 0.0;
    float a3 = 0.0, b3 = 0.0;
    HTML << setprecision(4) << fixed << showpoint;
    b1 = covariance1/variance1;
    a1 = mean2-(b1*mean1);
    b2 = covariance2/variance2;
    a2 = mean1-(b2*mean3);
    b3 = covariance3/variance3;
    a3 = mean3-(b3*mean2);

    HTML << "<td>" << "<strong>" << v.at(2) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << "y'= " << a1 << " + " << b1 << "x" << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(3) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << "y'= " << a3 << " + " << b3 << "x" << "</td>";
    HTML << "</tr>" << endl;

    HTML << "<td>" << "<strong>" << v.at(4) << "</strong>" << "</td>";
    HTML << "</td>";
    HTML <<  "<td>" << "y'= " << a2 << " + " << b2 << "x" << "</td>";
    HTML << "</tr>" << endl;
    HTML << "</table>" << endl;
}

/***********************************************
Programmer: Wong Yi Teng, Hii Jyn Tong
Name: 		printHTML
task:		To open and generate HTML document
************************************************/
void printHTML(vector<string> &v ,int cols, int rows)
{
    char c[1];
    system ("cls");
    HTML.open("report.html");
    dataHTML(v, cols);
    HTMLSorted(v);
    HTMLFreq1(v, rows);
    HTMLFreq2(v, rows);
    HTMLFreq3(v, rows);
    HTMLDistinct(v, rows);
    maxHTML(v);
    minHTML(v);
    medianHTML(v);
    C.meanHTML(v, rows);
    C.varianceHTML(v, rows);
    C.stdHTML(v, rows);
    C.Above1HTML(v, rows);
    C.Above2HTML(v, rows);
    C.Above3HTML(v, rows);
    C.Below1HTML(v, rows);
    C.Below2HTML(v, rows);
    C.Below3HTML(v, rows);
    C.CorrHTML(v, rows);
    C.L_HTML(v, rows);
    HTML.close();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t HTML Report generated!\n";
    cout << "\t\t\t\t\t\t\t Press Y to go back to main menu and N to exit \n";
    cout << "\t\t\t\t\t\t\t ";
    cin >> c;
    c[0]=toupper(c[0]);
    if (c[0] == 'Y' && c[1] == '\0')
        showMenu();
    else if (c[0] == 'N' && c[1] == '\0')
        exit(1);
    else
    {
        Invalid();
        printHTML(v ,cols, rows);
    }
}

int main()
{
    Info();
    Intro();
    string file;
    vector<string>titles;
    int rows;
    readFile(file);
    readTitles(titles,column);
    infile >> rows;
    readData();
    showMenu();
    do
    {
        if (choice[0] == '1' && choice[1] == '\0')
            printData(titles);
        else if (choice[0] == '2' && choice[1] == '\0')
            showMenuComputeStats(titles, rows);
        else if (choice[0] == '3' && choice[1] == '\0')
            printStats(titles, rows);
        else if (choice[0] == '4' && choice[1] == '\0')
            printHTML(titles,column, rows);
        else if (choice[0] == '5' && choice[1] == '\0')
            exit(1);
        else
        {
            Invalid();
            showMenu();
        }
    }while (choice);
    return 0;
}
