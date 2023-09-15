#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

void cgpa();
void ygpa();
void gpa();

int main()
{

home:
    cout << "===========================" << endl;
    cout << "|     CGPA Calculator     |" << endl;
    cout << "===========================" << endl;
    cout << "   < Dept. of CSE, PUST >   " << endl << endl;

    cout << "Enter the number you want calculate as follows (1 - 3):" << endl
         << "1. Calculate GPA of a semester" << endl
         << "2. Calculate YGPA of an academic year" << endl
         << "3. CGPA of semester you have finished" << endl << endl;

    int select1;
calculate:
    cout << "==> ";
    cin >> select1;
    cout << endl;

    switch(select1)
    {
    case 1:
        gpa();
        break;

    case 2:
        ygpa();
        break;

    case 3:
        cgpa();
        break;

    default:
    {
        cout << endl << "*** Invalid input! Please enter any of 1 - 3 ***" << endl << endl;
        goto calculate;
    }
    }

    string e;
exit:
    cout << endl << endl;
    cout << "Type Home to go to main menu" << endl << "Or type Exit to exit" << endl << endl;
    cout << "   ==> ";
    cin >> e;
    if(e != "Home" || e != "Exit")
    {
        cout << endl << "***      Invalid input!      ***" << endl;
        goto exit;
    }
    if(e == "Home")
        goto home;
    else if(e == "Exit")
    {
        cout << "===========================" << endl;
        cout << "|        Thank You!       |" << endl;
        cout << "===========================" << endl;

        return 0;
    }

}

void cgpa()
{
    vector<pair<float, float>> c(8);

    c[0].first = 19.50;
    c[1].first = 19.50;
    c[2].first = 20.25;
    c[3].first = 19.25;
    c[4].first = 21.00;
    c[5].first = 22.00;
    c[6].first = 21.00;
    c[7].first = 22.50;

    int n, x = 0;
    cout << endl << endl;
    cout << " ==> Enter the number of semesters you have finished (1, 2, 3 ...) : ";
finished:
    cin >> n;
    if(n < 1 || n > 8)
    {
        cout << endl << "*** Invalid input! Please enter any of 1 - 8 ***" << endl << endl << " ==> ";
        goto finished;
    }
    cout << endl << endl;
Cgpa:

    cout << "---------------------------------------" << endl;
    cout << "Year   " << "Semester   " << "Credit   " << "GPA Earned   " << endl;
    cout << "---------------------------------------" << endl;
    cout << "---------------------------------------" << endl;
    int year = 1;
    for(int i = 0; i < n / 2; i++)
    {
        int sem = 1;
        for(int j = 0; j < 2; j++)
        {
            cout << "  " << year << "        " << sem << "   " << "    " << setprecision(4) << c[x].first << "      ";
            cin >> c[x].second;
            if(c[x].second < 0 || c[x].second > 4)
            {
                cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                goto Cgpa;
            }
            cout << "---------------------------------------" << endl;
            sem++;
            x++;
        }
        year++;
    }

    if(n % 2 != 0)
    {
        cout << "  " << year << "        " << "1   " << "    " << setprecision(4) << c[x].first << "      ";
        cin >> c[x].second;
        if(c[x].second < 0 || c[x].second > 4)
        {
            cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
            goto Cgpa;
        }
    }
    cout << "---------------------------------------" << endl;
    cout << "---------------------------------------" << endl;

    float sumCkGk = 0, sumCk = 0;
    for(int i = 0; i < n; i++)
    {
        sumCkGk += (c[i].first * c[i].second);
        sumCk = sumCk + c[i].first;
    }

    float cgpa = sumCkGk / sumCk;

    cout << endl << endl;
    cout << "********************************************" << endl;
    printf("*               CGPA : %0.2f               *\n", cgpa);
    cout << "********************************************" << endl << endl << endl;
}

void ygpa()
{
    vector<pair<float, float>> g(8);

    g[0].first = 19.50;
    g[1].first = 19.50;
    g[2].first = 20.25;
    g[3].first = 19.25;
    g[4].first = 21.00;
    g[5].first = 22.00;
    g[6].first = 21.00;
    g[7].first = 22.50;

    int n, i, j;
    cout << endl << endl;
    cout << " ==> Enter which academic year you want to calculate (1 / 2 / 3 / 4) : ";
year:
    cin >> n;
    if(n < 1 || n > 4)
    {
        cout << endl << "*** Invalid input! Please enter any of 1 - 4 ***" << endl << endl << " ==> ";
        goto year;
    }

    if(n == 1) i = 0;
    else if(n == 2) i = 2;
    else if(n == 3) i = 4;
    else if(n == 4) i = 6;

Ygpa:
    cout << endl << endl;
    cout << "-------------------------------------" << endl;
    cout << "Year   " << "Semester   " << "Credit   " << "GPA Earned   " << endl;
    cout << "-------------------------------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << n << "        " << "1     " << "   " << g[i].first << "       ";
    cin >> g[i].second;
    if(g[i].second < 0 || g[i].second > 4)
    {
        cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
        goto Ygpa;
    }
    cout << "-------------------------------------" << endl;
    cout << n << "        " << "2     " << "   " << g[i + 1].first << "       ";
    cin >> g[i + 1].second;
    if(g[i + 1].second < 0 || g[i + 1].second > 4)
    {
        cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
        goto Ygpa;
    }
    cout << "-------------------------------------" << endl;
    cout << "-------------------------------------" << endl;

    float sumCjGj = (g[i].first * g[i].second) + (g[i + 1].first * g[i + 1].second);
    float sumCj = g[i].first + g[i + 1].first;
    float ygpa = sumCjGj / sumCj;

    cout << endl << endl;
    cout << "********************************************" << endl;
    printf("*               YGPA : %0.2f               *\n", ygpa);
    cout << "********************************************" << endl << endl << endl;
}

void gpa()
{
    cout << "Enter semester (1-8): ";
    int semester;
gpa:
start:
    cin >> semester;
    if(semester < 1 || semester > 8)
    {
        cout << endl << "*** Invalid input! Please enter any of 1 - 8 ***" << endl << endl << " ==> ";
        goto start;
    }
    switch(semester)
    {
    ///Semester 1
    case 1:
    {
        float sumCiGi = 0, sumCi = 19.50;
        vector<pair<float,float>> m(9);
        m[0].first = 3.00;
        m[1].first = 1.50;
        m[2].first = 3.00;
        m[3].first = 1.50;
        m[4].first = 3.00;
        m[5].first = 3.00;
        m[6].first = 3.00;
        m[7].first = 0.75;
        m[8].first = 0.75;

label1:

        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        cout << "  S/N  " << "  Course No.  " << "                   Cousre Title                  " << "    Credit  " << "   Obtained mark  " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 9; i++)
        {
            if(i == 0)
            {
                cout << "   1  "  << "   CSE 1101   " << "  Computer Fundamentals                             " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label1;
                }
            }

            else if(i == 1)
            {
                cout << "   2  "  << "   CSE 1102   " << "  Computer Fundamentals Sessional                    " << "   " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label1;
                }
            }

            else if(i == 2)
            {
                cout << "   3  "  << "   CSE 1103   " << "  Structured Programming Language                   " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label1;
                }
            }

            else if(i == 3)
            {
                cout << "   4  "  << "   CSE 1104   " << "  Structured Programming Language Sessional        " << "     " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label1;
                }

            }

            else if(i == 4)
            {
                cout << "   5  "  << "   MATH 1101  " << "  Differential Calculus and Co-ordinate Geometry   " << "      " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label1;
                }
            }

            else if(i == 5)
            {
                cout << "   6  "  << "   PHY 1101  " << "   Physics                                          " << "      " << m[i].first  << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label1;
                }
            }

            else if(i == 6)
            {
                cout << "   7  "  << "   HUM 1101  " << "   Communicative English                            " << "      " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label1;
                }
            }

            else if(i == 7)
            {
                cout << "   8  "  << "   HUM 1101  " << "   Communicative English Sessional                  " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label1;
                }
            }

            else if(i == 8)
            {
                cout << "   9  "  << "   CSE 1150 " << "     Viva Voce                                       " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label1;
                }
            }
            cout << "--------------------------------------------------------------------------------------------------- " << endl;

        }
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 9; i++)
        {
            if(m[i].second >= 80)
            {
                m[i].second = 4.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 75)
            {
                m[i].second = 3.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 70)
            {
                m[i].second = 3.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 65)
            {
                m[i].second = 3.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 60)
            {
                m[i].second = 3.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 55)
            {
                m[i].second = 2.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 50)
            {
                m[i].second = 2.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 45)
            {
                m[i].second = 2.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 40)
            {
                m[i].second = 2.00;
                sumCiGi += m[i].first * m[i].second;
            }
        }

        float gpa = sumCiGi / sumCi;

        cout << endl << endl;
        cout << "********************************************" << endl;
        printf("*                GPA : %0.2f               *\n", gpa);
        cout << "********************************************" << endl << endl << endl;
    }
    break;

    ///Semester 2
    case 2:
    {
        float sumCiGi = 0, sumCi = 19.50;
        vector<pair<float,float>> m(10);
        m[0].first = 1.00;
        m[1].first = 0.75;
        m[2].first = 3.00;
        m[3].first = 1.50;
        m[4].first = 3.00;
        m[5].first = 3.00;
        m[6].first = 1.50;
        m[7].first = 3.00;
        m[8].first = 2.00;
        m[9].first = 0.75;

label2:

        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        cout << "  S/N  " << "  Course No.  " << "                   Cousre Title                  " << "    Credit  " << "   Obtained mark  " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 10; i++)
        {
            if(i == 0)
            {
                cout << "   1  "  << "   ME 1200  " << "    Engineering Drawing                              " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }
            }

            else if(i == 1)
            {
                cout << "   2  "  << "   CSE 1200   " << "  Structured Programming Language Sessional II       " << "  " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }
            }

            else if(i == 2)
            {
                cout << "   3  "  << "   CSE 1201   " << "  Object Oriented Programming                      " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }
            }

            else if(i == 3)
            {
                cout << "   4  "  << "   CSE 1202   " << "  Object Oriented Programming Sessional           " << "     " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }

            }

            else if(i == 4)
            {
                cout << "   5  "  << "   CSE 1203  " << "   Discrete Mathematics                            " << "      " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }
            }

            else if(i == 5)
            {
                cout << "   6  "  << "   EEE 1201  " << "   Basic Electrical Engineering                    " << "      " << m[i].first  << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }
            }

            else if(i == 6)
            {
                cout << "   7  "  << "   EEE 1202  " << "   Basic Electrical Engineering Sessional         " << "      " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }
            }

            else if(i == 7)
            {
                cout << "   8  "  << "   MATH 1201  " << "  Integral Calculus, Differential Equation and" << endl
                     << "                      Series Solutions                                    " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }
            }

            else if(i == 8)
            {
                cout << "   9  "  << "   HUM 1201 " << "    Economics                                         " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }
            }
            else if(i == 9)
            {
                cout << "  10  "  << "   CSE 1250   " << "   Viva Voce                                        " << "   " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label2;
                }
            }
            cout << "--------------------------------------------------------------------------------------------------- " << endl;

        }
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 10; i++)
        {
            if(m[i].second >= 80)
            {
                m[i].second = 4.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 75)
            {
                m[i].second = 3.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 70)
            {
                m[i].second = 3.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 65)
            {
                m[i].second = 3.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 60)
            {
                m[i].second = 3.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 55)
            {
                m[i].second = 2.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 50)
            {
                m[i].second = 2.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 45)
            {
                m[i].second = 2.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 40)
            {
                m[i].second = 2.00;
                sumCiGi += m[i].first * m[i].second;
            }
        }

        float gpa = sumCiGi / sumCi;

        cout << endl << endl;
        cout << "********************************************" << endl;
        printf("*                GPA : %0.2f               *\n", gpa);
        cout << "********************************************" << endl << endl << endl;
    }
    break;


    ///Semester 3
    case 3:
    {
        float sumCiGi = 0, sumCi = 20.25;
        vector<pair<float,float>> m(9);
        m[0].first = 3.00;
        m[1].first = 1.50;
        m[2].first = 3.00;
        m[3].first = 1.50;
        m[4].first = 3.00;
        m[5].first = 1.50;
        m[6].first = 3.00;
        m[7].first = 3.00;
        m[8].first = 0.75;

label3:

        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        cout << "  S/N  " << "  Course No.  " << "                   Cousre Title                  " << "    Credit  " << "   Obtained mark  " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 9; i++)
        {
            if(i == 0)
            {
                cout << "   1  "  << "   CSE 2101   " << "  Data Structures                                  " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label3;
                }
            }

            else if(i == 1)
            {
                cout << "   2  "  << "   CSE 2102   " << "  Data Structures Sessional                          " << "   " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label3;
                }
            }

            else if(i == 2)
            {
                cout << "   3  "  << "   CSE 2103   " << "  Design Pattern and Java Programming              " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label3;
                }
            }

            else if(i == 3)
            {
                cout << "   4  "  << "   CSE 2104   " << "  Design Pattern and Java Programming Sessional    " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label3;
                }

            }

            else if(i == 4)
            {
                cout << "   5  "  << "   EEE 2101  " << "   Electronic Devices and Circuits                  " << "      " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label3;
                }
            }

            else if(i == 5)
            {
                cout << "   6  "  << "   EEE 2102  " << "   Electronic Devices and Circuits Sessional        " << "      " << m[i].first  << "          ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label3;
                }
            }

            else if(i == 6)
            {
                cout << "   7  "  << "   MATH 2101 " << "   Vector, Matrices and Linear Algebra              " << "      " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label3;
                }
            }

            else if(i == 7)
            {
                cout << "   8  "  << "   STAT 2101  " << "  Elementary Statistics and Probability             " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label3;
                }
            }

            else if(i == 8)
            {
                cout << "   9  "  << "   CSE 2150 " << "    Viva Voce                                        " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label3;
                }
            }
            cout << "--------------------------------------------------------------------------------------------------- " << endl;

        }
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 9; i++)
        {
            if(m[i].second >= 80)
            {
                m[i].second = 4.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 75)
            {
                m[i].second = 3.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 70)
            {
                m[i].second = 3.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 65)
            {
                m[i].second = 3.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 60)
            {
                m[i].second = 3.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 55)
            {
                m[i].second = 2.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 50)
            {
                m[i].second = 2.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 45)
            {
                m[i].second = 2.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 40)
            {
                m[i].second = 2.00;
                sumCiGi += m[i].first * m[i].second;
            }
        }

        float gpa = sumCiGi / sumCi;

        cout << endl << endl;
        cout << "********************************************" << endl;
        printf("*                GPA : %0.2f               *\n", gpa);
        cout << "********************************************" << endl << endl << endl;

    }
    break;


    ///Semester 4
    case 4:
    {
        float sumCiGi = 0, sumCi = 19.25;
        vector<pair<float,float>> m(9);
        m[0].first = 1.50;
        m[1].first = 3.00;
        m[2].first = 1.50;
        m[3].first = 2.00;
        m[4].first = 3.00;
        m[5].first = 1.50;
        m[6].first = 3.00;
        m[7].first = 3.00;
        m[8].first = 0.75;

label4:

        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        cout << "  S/N  " << "  Course No.  " << "                   Cousre Title                  " << "    Credit  " << "   Obtained mark  " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 9; i++)
        {
            if(i == 0)
            {
                cout << "   1  "  << "   CSE 2200   " << "  Analytical Programming Sessional                " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label4;
                }
            }

            else if(i == 1)
            {
                cout << "   2  "  << "   CSE 2201   " << "  Algorithms                                         " << "   " << m[i].first << "              ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label4;
                }
            }

            else if(i == 2)
            {
                cout << "   3  "  << "   CSE 2202   " << "  Algorithms Sessional                             " << "     " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label4;
                }
            }

            else if(i == 3)
            {
                cout << "   4  "  << "   CSE 2203   " << "  Theory of Computation                             " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label4;
                }

            }

            else if(i == 4)
            {
                cout << "   5  "  << "   CSE 2205  " << "   Digital Systems                                  " << "      " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label4;
                }
            }

            else if(i == 5)
            {
                cout << "   6  "  << "   CSE 2206  " << "   Digital Systems Sessional                       " << "      " << m[i].first  << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label4;
                }
            }

            else if(i == 6)
            {
                cout << "   7  "  << "   MATH 2201 " << "   Complex analysis, Laplace and Fourier Transforms " << "      " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label4;
                }
            }

            else if(i == 7)
            {
                cout << "   8  "  << "   STAT 2201  " << "  Theory of Statistics                              " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label4;
                }
            }

            else if(i == 8)
            {
                cout << "   9  "  << "   CSE 2250 " << "    Viva Voce                                        " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label4;
                }
            }
            cout << "--------------------------------------------------------------------------------------------------- " << endl;

        }
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 9; i++)
        {
            if(m[i].second >= 80)
            {
                m[i].second = 4.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 75)
            {
                m[i].second = 3.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 70)
            {
                m[i].second = 3.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 65)
            {
                m[i].second = 3.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 60)
            {
                m[i].second = 3.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 55)
            {
                m[i].second = 2.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 50)
            {
                m[i].second = 2.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 45)
            {
                m[i].second = 2.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 40)
            {
                m[i].second = 2.00;
                sumCiGi += m[i].first * m[i].second;
            }
        }

        float gpa = sumCiGi / sumCi;

        cout << endl << endl;
        cout << "********************************************" << endl;
        printf("*                GPA : %0.2f               *\n", gpa);
        cout << "********************************************" << endl << endl << endl;

    }
    break;


    ///Semester 5
    case 5:
    {
        float sumCiGi = 0, sumCi = 21;
        vector<pair<float,float>> m(10);
        m[0].first = 3.00;
        m[1].first = 3.00;
        m[2].first = 1.50;
        m[3].first = 3.00;
        m[4].first = 0.75;
        m[5].first = 3.00;
        m[6].first = 1.50;
        m[7].first = 3.00;
        m[8].first = 1.50;
        m[9].first = 0.75;

label5:

        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        cout << "  S/N  " << "  Course No.  " << "                   Cousre Title                  " << "    Credit  " << "   Obtained mark  " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 10; i++)
        {
            if(i == 0)
            {
                cout << "   1  "  << "   CSE 3101  " << "    Computer Architecture and Organization          " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }
            }

            else if(i == 1)
            {
                cout << "   2  "  << "   CSE 3103   " << "  Compiler Design                                     " << "  " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }
            }

            else if(i == 2)
            {
                cout << "   3  "  << "   CSE 3104   " << "  Compiler Design Sessional                        " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }
            }

            else if(i == 3)
            {
                cout << "   4  "  << "   CSE 3105   " << "  Numerical Methods                                " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }

            }

            else if(i == 4)
            {
                cout << "   5  "  << "   CSE 3106  " << "   Numerical Methods Sessional                     " << "      " << m[i].first << "          ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }
            }

            else if(i == 5)
            {
                cout << "   6  "  << "   CSE 3107  " << "   Database Management Systems                     " << "      " << m[i].first  << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }
            }

            else if(i == 6)
            {
                cout << "   7  "  << "   CSE 3108  " << "   Database Management Systems Sessional           " << "      " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }
            }

            else if(i == 7)
            {
                cout << "   8  "  << "   ECE 3101  " << "   Data Communication                                " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }
            }

            else if(i == 8)
            {
                cout << "   9  "  << "   ECE 3102 " << "    Data Communication Sessional                     " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }
            }
            else if(i == 9)
            {
                cout << "  10  "  << "   CSE 3150   " << "  Viva Voce                                          " << "   " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label5;
                }
            }
            cout << "--------------------------------------------------------------------------------------------------- " << endl;

        }
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 10; i++)
        {
            if(m[i].second >= 80)
            {
                m[i].second = 4.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 75)
            {
                m[i].second = 3.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 70)
            {
                m[i].second = 3.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 65)
            {
                m[i].second = 3.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 60)
            {
                m[i].second = 3.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 55)
            {
                m[i].second = 2.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 50)
            {
                m[i].second = 2.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 45)
            {
                m[i].second = 2.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 40)
            {
                m[i].second = 2.00;
                sumCiGi += m[i].first * m[i].second;
            }
        }

        float gpa = sumCiGi / sumCi;

        cout << endl << endl;
        cout << "********************************************" << endl;
        printf("*                GPA : %0.2f               *\n", gpa);
        cout << "********************************************" << endl << endl << endl;
    }
    break;


    ///Semester 6
    case 6:
    {
        float sumCiGi = 0, sumCi = 22;
        vector<pair<float,float>> m(11);
        m[0].first = 1.00;
        m[1].first = 3.00;
        m[2].first = 3.00;
        m[3].first = 1.50;
        m[4].first = 3.00;
        m[5].first = 1.50;
        m[6].first = 3.00;
        m[7].first = 0.75;
        m[8].first = 3.00;
        m[9].first = 1.50;
        m[10].first = 0.75;

label6:

        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        cout << "  S/N  " << "  Course No.  " << "                   Cousre Title                  " << "    Credit  " << "   Obtained mark  " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 11; i++)
        {
            if(i == 0)
            {
                cout << "   1  "  << "   CSE 3200  " << "   Project                                          " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }

            else if(i == 1)
            {
                cout << "   2  "  << "   CSE 3201   " << "  System Analysis and Design                          " << "  " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }

            else if(i == 2)
            {
                cout << "   3  "  << "   CSE 3203   " << "  Operating Systems                                " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }

            else if(i == 3)
            {
                cout << "   4  "  << "   CSE 3204   " << "  Operating Systems Sessional                      " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }

            }

            else if(i == 4)
            {
                cout << "   5  "  << "   CSE 3205  " << "   Web Engineering                                 " << "      " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }

            else if(i == 5)
            {
                cout << "   6  "  << "   CSE 3206  " << "   Web Engineering Sessional                       " << "      " << m[i].first  << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }

            else if(i == 6)
            {
                cout << "   7  "  << "   CSE 3207  " << "   Digital Signal Processing                        " << "      " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }

            else if(i == 7)
            {
                cout << "   8  "  << "   CSE 3208  " << "   Digital Signal Processing Sessional               " << "     " << m[i].first << "         ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }

            else if(i == 8)
            {
                cout << "   9  "  << "   CSE 3209 " << "    Microprocessors and Assembly Language             " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }
            else if(i == 9)
            {
                cout << "   10  "  << "   CSE 3210 " << "   Microprocessors and Assembly Language Sessional   " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }
            else if(i == 10)
            {
                cout << "  11  "  << "  Viva Voce   " << "  Viva Voce                                           " << "   " << m[i].first << "          ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label6;
                }
            }
            cout << "--------------------------------------------------------------------------------------------------- " << endl;

        }
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 11; i++)
        {
            if(m[i].second >= 80)
            {
                m[i].second = 4.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 75)
            {
                m[i].second = 3.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 70)
            {
                m[i].second = 3.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 65)
            {
                m[i].second = 3.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 60)
            {
                m[i].second = 3.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 55)
            {
                m[i].second = 2.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 50)
            {
                m[i].second = 2.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 45)
            {
                m[i].second = 2.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 40)
            {
                m[i].second = 2.00;
                sumCiGi += m[i].first * m[i].second;
            }
        }

        float gpa = sumCiGi / sumCi;

        cout << endl << endl;
        cout << "********************************************" << endl;
        printf("*                GPA : %0.2f               *\n", gpa);
        cout << "********************************************" << endl << endl << endl;
    }
    break;


    ///Semester 7
    case 7:
    {
        float sumCiGi = 0, sumCi = 21;
        vector<pair<float,float>> m(10);
        m[0].first = 1.50;
        m[1].first = 3.00;
        m[2].first = 0.75;
        m[3].first = 3.00;
        m[4].first = 1.50;
        m[5].first = 3.00;
        m[6].first = 1.50;
        m[7].first = 3.00;
        m[8].first = 3.00;
        m[9].first = 0.75;

label7:

        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        cout << "  S/N  " << "  Course No.  " << "                   Cousre Title                  " << "    Credit  " << "   Obtained mark  " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 10; i++)
        {
            if(i == 0)
            {
                cout << "   1  "  << "   CSE 4100  " << "    Project/Thesis                                  " << "     " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }
            }

            else if(i == 1)
            {
                cout << "   2  "  << "   CSE 4101   " << "  Software Engineering                                 " << "  " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }
            }

            else if(i == 2)
            {
                cout << "   3  "  << "   CSE 4102   " << "  Software Engineering Sessional                   " << "     " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }
            }

            else if(i == 3)
            {
                cout << "   4  "  << "   CSE 4103   " << "  Artificial Intelligence                           " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }

            }

            else if(i == 4)
            {
                cout << "   5  "  << "   CSE 4104  " << "   Artificial Intelligence Sessional               " << "      " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }
            }

            else if(i == 5)
            {
                cout << "   6  "  << "   CSE 4105  " << "   Digital Image Processing                         " << "      " << m[i].first  << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }
            }

            else if(i == 6)
            {
                cout << "   7  "  << "   CSE 4106  " << "   Digital Image Processing Sessional              " << "      " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }
            }

            else if(i == 7)
            {
                cout << "   8  "  << "             " << "   Optional - I                                      " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }
            }

            else if(i == 8)
            {
                cout << "   9  "  << "   HUM 4101 " << "    Sociology and Bangladesh Studies                   " << "     " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }
            }
            else if(i == 9)
            {
                cout << "  10  "  << "   CSE 4150   " << "  Viva Voce                                          " << "   " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label7;
                }
            }
            cout << "--------------------------------------------------------------------------------------------------- " << endl;

        }
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 10; i++)
        {
            if(m[i].second >= 80)
            {
                m[i].second = 4.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 75)
            {
                m[i].second = 3.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 70)
            {
                m[i].second = 3.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 65)
            {
                m[i].second = 3.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 60)
            {
                m[i].second = 3.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 55)
            {
                m[i].second = 2.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 50)
            {
                m[i].second = 2.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 45)
            {
                m[i].second = 2.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 40)
            {
                m[i].second = 2.00;
                sumCiGi += m[i].first * m[i].second;
            }
        }

        float gpa = sumCiGi / sumCi;

        cout << endl << endl;
        cout << "********************************************" << endl;
        printf("*                GPA : %0.2f               *\n", gpa);
        cout << "********************************************" << endl << endl << endl;
    }
    break;


    ///Semester 8
    case 8:
    {
        float sumCiGi = 0, sumCi = 22.5;
        vector<pair<float,float>> m(10);
        m[0].first = 3.00;
        m[1].first = 3.00;
        m[2].first = 1.50;
        m[3].first = 3.00;
        m[4].first = 1.50;
        m[5].first = 3.00;
        m[6].first = 0.75;
        m[7].first = 3.00;
        m[8].first = 3.00;
        m[9].first = 0.75;

label8:

        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        cout << "  S/N  " << "  Course No.  " << "                   Cousre Title                  " << "    Credit  " << "   Obtained mark  " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 10; i++)
        {
            if(i == 0)
            {
                cout << "   1  "  << "   CSE 4200  " << "    Project/Thesis                                  " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }
            }

            else if(i == 1)
            {
                cout << "   2  "  << "   CSE 4201   " << "  Computer Networks                                   " << "  " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }
            }

            else if(i == 2)
            {
                cout << "   3  "  << "   CSE 4202   " << "  Computer Networks Sessional                     " << "     " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }
            }

            else if(i == 3)
            {
                cout << "   4  "  << "   CSE 4203   " << "  Computer Graphics                                " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }

            }

            else if(i == 4)
            {
                cout << "   5  "  << "   CSE 4204  " << "   Computer Graphics Sessional                    " << "      " << m[i].first << "            ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }
            }

            else if(i == 5)
            {
                cout << "   6  "  << "   CSE 4205  " << "   Interfacing and Microcontrollers                " << "      " << m[i].first  << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }
            }

            else if(i == 6)
            {
                cout << "   7  "  << "   CSE 4206  " << "   Interfacing and Microcontrollers Sessional     " << "      " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }
            }

            else if(i == 7)
            {
                cout << "   8  "  << "             " << "   Optional - II                                    " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }
            }

            else if(i == 8)
            {
                cout << "   9  "  << "   HUM 4201 " << "    Industrial Management and Accounting             " << "     " << m[i].first << "             ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }
            }
            else if(i == 9)
            {
                cout << "  10  "  << "  CSE 4250   " << "  Viva Voce                                          " << "   " << m[i].first << "           ";
                cin >> m[i].second;
                if(m[i].second < 0 || m[i].second > 100)
                {
                    cout << endl << "*** Invalid input! Enter again.. ***" << endl << endl;
                    goto label8;
                }
            }
            cout << "--------------------------------------------------------------------------------------------------- " << endl;

        }
        cout << "--------------------------------------------------------------------------------------------------- " << endl;

        for(int i = 0; i < 10; i++)
        {
            if(m[i].second >= 80)
            {
                m[i].second = 4.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 75)
            {
                m[i].second = 3.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 70)
            {
                m[i].second = 3.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 65)
            {
                m[i].second = 3.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 60)
            {
                m[i].second = 3.00;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 55)
            {
                m[i].second = 2.75;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 50)
            {
                m[i].second = 2.50;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 45)
            {
                m[i].second = 2.25;
                sumCiGi += m[i].first * m[i].second;
            }
            else if(m[i].second >= 40)
            {
                m[i].second = 2.00;
                sumCiGi += m[i].first * m[i].second;
            }
        }

        float gpa = sumCiGi / sumCi;

        cout << endl << endl;
        cout << "********************************************" << endl;
        printf("*                GPA : %0.2f               *\n", gpa);
        cout << "********************************************" << endl << endl << endl;
    }
    break;


    default:
    {
        cout << endl << endl << "Invalid input! Enter again from 1 - 8" << endl << endl;
        goto gpa;
    }
    }
}
