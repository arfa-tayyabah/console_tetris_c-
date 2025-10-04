#include<iostream>
#include<windows.h>
using namespace std;
#include<conio.h>
#include<math.h>
#include <stdlib.h>
#include<ctime>
#include<fstream>

char board[18][30];


void gotoRowCol(int rpos, int cpos)
{
int xpos=cpos, ypos = rpos;
COORD scrn;
HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
scrn.X = cpos;
scrn.Y = rpos;
SetConsoleCursorPosition(hOuput, scrn);
}
void sleep(int k)
{
    for (int i=0; i<k*21000;i++)
    {

    }
}
void print_box()
{
    char c=219;
    for (int row=0; row<20; row++)
    {
        for (int col=0; col<32; col++)
        {
            if (col==0 || row==0|| col==31 || row==19)
            {
               gotoRowCol(row,col);
                cout << c;
            }
        }
    }
}
void copy_array(char orig[3][3], char copi[3][3])
{
  for (int i=0; i<3;i++)
        {
            for (int j=0; j<3; j++)
            {
                copi[i][j]=orig[i][j];
            }
        }
}

void print_block(char arry[3][3], int r, int c)
{

       for (int i=0; i<3;i++)
        {

            for (int j=0; j<3; j++)
            {
                if (arry[i][j]!=0)
                {
                  gotoRowCol(r+i,c+j);
                  cout << arry[i][j] ;
                }
            }
        }
}
void rotate_block(char arr[3][3])
{
    char temp;
        for (int i=0;i<3;i++ )
        {
              for (int j=i+1;j<3;j++ )
                 {

                     temp=arr[i][j];
                     arr[i][j]=arr[j][i];
                     arr[j][i]=temp;
                 }
        }

        for (int i=0;i<3;i++ )
        {

                temp=arr[i][0];
                arr[i][0]=arr[i][2];
                arr[i][2]=temp;
        }
}

void t_block(char arr[3][3])
{
    char c='O';
    char z=0;
    char a;
    char temp;
     char A[3][3]={
                    {z,z,z},
                    {z,c,z},
                    {c,c,c}
                 };
    copy_array(A,arr);

}

void s_right_block(char arr[3][3])
{
    char c='O';
    char z=0;
    char A[3][3]={
                    {z,z,z},
                    {z,c,c},
                    {c,c,z}
                 };
copy_array(A,arr);
}
void s_left_block(char arr[3][3])
{
    char c='O';
    char z=0;
    char A[3][3]={
                    {z,c,z},
                    {z,c,c},
                    {z,z,c}
                 };
          copy_array(A,arr);
}
void l_block(char arr[3][3])
{
    char c='O';
    char z=0;
    char A[3][3]={
                    {z,c,z},
                    {z,c,z},
                    {z,c,c}
                 };
             copy_array(A,arr);
}

void i_block(char arr[3][3])
{
     char c='O' ;
    char z=0;
    char A[3][3]={
                    {z,c,z},
                    {z,c,z},
                    {z,c,z}
                 };
       copy_array(A,arr);

}
void box_block(char arr[3][3])
{
     char c='O';
    char z=0;
    char A[3][3]={
                    {z,z,z},
                    {z,c,c},
                    {z,c,c}

                 };
copy_array(A,arr);
}
void game_array()
{
    char z='.';
    for (int i=0; i<18;i++)
        {

            for (int j=0; j<30; j++)
            {
                board[i][j]=z;
            }
        }
}
void print_game_array()
{

     for (int i = 0; i < 18; ++i)
        {
        for (int j = 0; j < 30; ++j)
         {

                gotoRowCol(i+1,j+1);
                cout << board[i][j];

        }
    }
}
void save_game()
{
    ofstream write("save.txt");
    for (int i = 0; i < 18; ++i)
        {
        for (int j = 0; j < 30; ++j)
         {


                write << board[i][j] << " ";

        }
        write << endl;
    }

}

int check_position(int row, int col, char a[3][3])
{

   for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (board[row+i][col+j]!='.' && a[i][j]!=0)
                return 0;
        }
    }
    return 1;
}
void merge_array(char a[3][3], int row, int col)
 {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
             {
                    if (a[i][j] != 0 &&  board[row + i][col + j]=='.')
                    {
                        board[row + i][col + j] = a[i][j];
                    }
            }
    }
    save_game();
}

int random_block()
{
    int num;
    num = rand()%6+1;
    return num;
}
void delete_rows(int &score)
{
    int check;
    for (int row=18; row>1; row--)
    {
        check=0;
        for (int col=0; col<30; col++)
        {
            if (board[row][col]=='.')
            {
                check=0;
                break;
            }
            else
                check++;
        }
        if (check>=1)
        {
            score+=100;
            for (int col=0; col<30; col++)
                board[row][col]='.';
            for (int ro=row; ro>1; ro--)
            {
                  for (int col=0; col<30; col++)
                  {
                      board[ro][col]=board[ro-1][col];
                  }
            }
        }
    }
   gotoRowCol(22,2);
   cout << "Score: " << score;
}


void load_game()
{
    ifstream read("save.txt");
    for (int i = 0; i < 18; ++i)
        {
        for (int j = 0; j < 30; ++j)
         {


                read >> board[i][j];

        }

    }

}

void move_block() {

    int score=0;
    char arry[3][3];
    int nrow = 1, ncol = rand() % 25 + 2;

    int n = random_block();
    if (n == 1)
     t_block(arry);
    else if (n == 2)
     s_right_block(arry);
    else if (n == 3)
     s_left_block(arry);
    else if (n == 4)
     l_block(arry);
    else if (n == 5)
     i_block(arry);
    else if (n == 6)
     box_block(arry);

    do
    {
        char m;
        if (kbhit())
        {
             m = getch();
            if (m == 75)
               ncol -= 1;
            else if (m == 77)
                ncol += 1;
            else if (m==72 || m==80)
            {
               rotate_block(arry);
            }

        }
        if (ncol<1)
            ncol=1;
        if (ncol+3>29)
            ncol--;

        nrow++;
        if (check_position(nrow+1, ncol, arry))
        {
            print_block(arry, nrow, ncol);
            sleep(9900);
            print_game_array();
        }
        else
        {
            merge_array(arry, nrow, ncol-1);
            sleep(9900);
            print_game_array();
            break;
        }
        if (nrow==15)
        {
                merge_array(arry, nrow-1, ncol-1);
                print_game_array();
                  break;
        }
    }
    while (nrow != 18);
    delete_rows(score);


}

int main()
{

    srand(time(NULL));
    print_box();
    char c;
    do
    {
        gotoRowCol(21,2);
        cout << "Press L to load game and N for new game:";
        cin >> c;
    }
    while (c!='L' && c!='l' && c!='N' && c!='n');
    if (c=='n' || c=='N')
        game_array();
    else
    {
       load_game();
       print_game_array();
    }

    int full=0;
    while (true)
    {
        move_block();

       full=0;
       for (int col = 0; col < 30; col++)
        {

            if (board[4][col] != '.')
            {
                full++;
            }
        }
       if (full>=18)
       {
           gotoRowCol(22, 2);
                cout << "Game Over!" << endl;
                return 0;
       }
    }

    return 0;
}



