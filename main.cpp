#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


class Game
{
    char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};

    int player=1, place, check;
    int score1=0, score2=0;
    char mark, Name1[10], Name2[10], PName[10];

public:

    void Display();
        void Reset();

    void Interaction(); //MAIN
        void Intro();
        void Score();

    void Logic();

};



void Game::Display()
{
    system("cls");

//HEADER
    cout << "\n\n\t\t     TIC TAC TOE" << endl;
    cout << "\t\t -x_______________x-" << endl;

    cout << "\n\t    " << Name1 << " (X)              "<< Name2 << " (O)\n\n" << endl;

//GRID (MAINFRAME)
    cout << "\t\t" << "      |       |   " << endl;
    cout << "\t\t   " << arr[1] << "  |   " << arr[2] << "   |  " << arr[3] << endl;

    cout << "\t\t" << "______|_______|______" << endl;
    cout << "\t\t" << "      |       |   " << endl;

    cout << "\t\t   " << arr[4] << "  |   " << arr[5] << "   |  " << arr[6] << endl;

    cout << "\t\t" << "______|_______|______" << endl;
    cout << "\t\t" << "      |       |   " << endl;

    cout << "\t\t   " << arr[7] << "  |   " << arr[8] << "   |  " << arr[9] << endl;
    cout << "\t\t" << "      |       |   \n\n" << endl;
}



//RESTARTING
void Game::Reset()
{
  player=1;

  arr[0] = '0';
  arr[1] = '1';
  arr[2] = '2';
  arr[3] = '3';
  arr[4] = '4';
  arr[5] = '5';
  arr[6] = '6';
  arr[7] = '7';
  arr[8] = '8';
  arr[9] = '9';

 /*
 arr[10] = {'0','1','2','3','4','5','6','7','8','9'};

 WAS NOT WORKING
 */
}



void Game::Interaction()
{
    system("cls");

//GAME STARTS
    do
    {
        Display();

    //CHANGING PLAYERS TURN (1&2)
            if(player%2==0)
            {
                player = 2;
                strcpy(PName,Name2);
            }
            else
            {
                strcpy(PName,Name1);
                player = 1;
            }

    //TAKING INPUT
        cout << "\t\t     " << PName << "'s Turn\n" << endl;
        cout << "\t\tEnter the place value : " ;
        cin >> place;

        mark = (player==1) ? 'X':'O' ;       //boolean expression

    //MARKING THE PLACE
        if(place == 1 && arr[1] == '1')  arr[1] = mark;
        else if(place == 2 && arr[2] == '2')  arr[2] = mark;
        else if(place == 3 && arr[3] == '3')  arr[3] = mark;
        else if(place == 4 && arr[4] == '4')  arr[4] = mark;
        else if(place == 5 && arr[5] == '5')  arr[5] = mark;
        else if(place == 6 && arr[6] == '6')  arr[6] = mark;
        else if(place == 7 && arr[7] == '7')  arr[7] = mark;
        else if(place == 8 && arr[8] == '8')  arr[8] = mark;
        else if(place == 9 && arr[9] == '9')  arr[9] = mark;
        else
        {
            cout << "Please enter valid place no. !!!!" << endl;
            player--;
        }

    //FOR INCREMENTING THE LOOP CONDITION
        player++;
        Logic();        //TO CHECK THE WINNING CONDITION

        if(check==1)
        {
            Display();
        }
    }
    while(check==0);        //CONTINUATION CONDITION IS WHEN CHECK IS 0

//RESULT
    if(check==1)
    {
        cout << "\n\t\t      CONGRATULATIONS!!!\n";
        cout << "\n\t      "<< PName << player << " HAS WON THE GAME!!!" << endl;

        if(player%2==0)     //because player value will be 1,2,3...
        {
            score1++;
        }
        else
        {
            score2++;
        }
    }
    else
    {
        cout << "\n\t\t      MATCH HAS BEEN DRAW!!!" << endl;
    }
}



void Game::Intro()
{
//HEADER
    cout << "\n\n\t\t     TIC TAC TOE" << endl;
    cout << "\t\t -x_______________x-" << endl;
    cout << "\n\t       Created by Vatsal Singh\n\n" << endl;

//INTRODUCTION OF USERS
    cout << "\tEnter Player 1 Name : " ;
    cin >> Name1;

    cout << "\tEnter Player 2 Name : ";
    cin >> Name2;
}



void Game::Score()
{
    char Exit;

    system("cls");

    cout << "\n\n\t\t      SCOREBOARD" << endl;
    cout << "\t\t  -x_______________x-\n" << endl;

    cout << "\t\t"  << Name1 << "\t\t  " << Name2 << endl;
    cout << "\n\t\t  " << score1 << "\t\t     " << score2;

//FOR GIVING TIME TO SEE RESULTS
    cout << "\n\n\n\n\n\tPress any key to exit " ;
    cin >> Exit;
}



void Game::Logic()
{
//WINNING CONDITIONS-->

    //CHECKING HORIZONTALLY
    if(mark==arr[1] && mark==arr[2] && mark==arr[3]) check = 1;
    else if(mark==arr[4] && mark==arr[5] && mark==arr[6]) check = 1;
    else if(mark==arr[7] && mark==arr[8] && mark==arr[9]) check = 1;

    //CHECKING VERTICALLY
    else if(mark==arr[1] && mark==arr[4] && mark==arr[7]) check = 1;
    else if(mark==arr[2] && mark==arr[5] && mark==arr[8]) check = 1;
    else if(mark==arr[3] && mark==arr[6] && mark==arr[9]) check = 1;

    //CHECKING DIAGONALLY
    else if(mark==arr[1] && mark==arr[5] && mark==arr[9]) check = 1;
    else if(mark==arr[3] && mark==arr[5] && mark==arr[7]) check = 1;

//CONTINUATION CONDITION
    else if(arr[1]=='1' || arr[2]=='2' || arr[3]=='3' || arr[4]=='4' || arr[1]=='5' || arr[5]=='6' || arr[7]=='7' || arr[8]=='8' || arr[9]=='9')
    {
        check = 0;
    }

//DRAW CONDITION
    else
    {
        check = -1;
    }
}



int main()
{
    char choice;

    Game obj;
    obj.Intro();

     do
     {
        obj.Interaction();
        obj.Reset();

        cout << "\n\t\tPLAY AGAIN (Y/N) : " ;
        cin >> choice;

     //TO PLAY AGAIN
     }while(choice == 'Y' || choice == 'y');

    obj.Score();

    return 0;
}
