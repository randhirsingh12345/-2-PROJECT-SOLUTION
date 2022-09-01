//project solution 2 :  "RANDHIR SINGH (STUDENT OF SAURABH SIR (MY SIR G.COM)))" :-
#include <string.h>
#include<stdio.h>
#include <conio.h>
#include <windows.h>
#include<time.h>
  void Print_position_value(char [][3], char [][30]);
  void Enter_name(char name[][30],int flag);
  void Enter_Position_value(char [][3], char [][30]);
  void Enter_smart_com_Position_value(char [][3], char[][30]);
  void Enter_evil_com_Position_value(char arr[][3],char name[][30]);
  int winGame(char [][3]);
  void playfriend(char [3][30],char [][3]);
  void playsmart_comp(char [3][30],char [][3]);
  void playevil_comp(char [3][30],char [][3]);
  int Display_menu();
  void restart_game();
  int check_exist(int place,char arr[][3]);
  int main()
  {
    char arr[3][3]={'1','2','3','4','5','6','7','8','9'}; // create char matrix for Position value
    char name[3][30]={'o'};  // create char matrix for Players name
    int i,flag=0;
    system("cls");
    system("color 9e");
    switch (Display_menu()) // Starting the game
    {
    case 1:
        playfriend(name,arr);
        break;
    case 2:
        playsmart_comp(name,arr);
        break;

    case 3:
        playevil_comp(name,arr);
        break;

    case 4:
        printf("Thnx for visiting the game hope you will enjoyed in this game. VISIT AGIAN!");
        exit(0);
    }
      return 0;
  }
  void Enter_name(char name[3][30],int flag) // Enter players name according to various function
  {
      fflush(stdin);
    printf("Enter player %d: ",1);
     fgets(name[1] ,30, stdin);
     if(flag==1)
    strcpy(name[2], "Smart Computer\n");
    else if(flag==2)
    strcpy(name[2], "Evil Computer\n");
    else{
     printf("Enter player %d: ",2);
     fgets(name[2] ,30, stdin);
    }
  }
  void Print_position_value(char arr[][3],char name[3][30]) // Display position value in the form of Tic_Tac_Toe game box
  {
          int i,j,k,place;
          system("cls");
          printf("\n ###################### Tic Tac Toe #######################\n\n\n");
    printf(" Player 1, %s Sign :(X)\n***********************\n Player 2, %s Sign :(O) \n***********************\n\n\n\n",name[1],name[2]);
      for(i=0;i<3;i++)
      {
          for(k=0;k<2;k++){
            printf("      |");
          }
          printf("\n");
          for(j=0;j<3;j++){
           printf(" %3c  ",arr[i][j]);
           if(j!=2)
           printf("|");
          }
           printf("\n");
           for(k=0;k<2;k++)
            printf("______|");
            printf("______");
           printf("\n");
      }
  }
  void Enter_Position_value(char arr[][3],char name[3][30])  //  enter position value for Playfriend();
  {
      int i,player=1,place=0,j,flag=0;
      char sign;
     do
    {
        system("color 9e");
        Print_position_value(arr,name); // Function call for display position value Before Start the game
        player=(player%2) ? 1 : 2;
        printf("\n\nPlayer %d, %s \n enter the place value : ",player,name[player]);
        scanf("%d",&place);
        if(place==1)
            place='1';
        else if(place==2)
            place='2';
        else if(place==3)
            place='3';
        else if(place==4)
            place='4';
        else if(place==5)
            place='5';
        else if(place==6)
            place='6';
        else if(place==7)
            place='7';
        else if(place==8)
            place='8';
        else if(place==9)
            place='9';
        sign=player==1 ? 'X' : 'O';
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]==place){
                    arr[i][j]=sign;
                    goto past;
                }
            }
        }
            printf("Invalid option !");
            place=0;
            player--;
            sleep(1);
        past:
        i=winGame(arr);
        player++;
    }while(i==-1);
      Print_position_value(arr,name); // Function call for display position value after replace by (X) or (O)
    if(i==1)
    {
        printf("\n\n\n#######################################################################\n\n");
        printf("Player %d %s   Congratulations, You won!\n",player,name[--player]);
        printf("\n#######################################################################\n\n");
        printf("press any key to continue....");
        getch();
        restart_game();
    }
    else if(i==0)
    {
        printf("\n\n\n#######################################################################\n\n");
        printf("Game draw!\n");
        printf("\n#######################################################################\n\n");
        printf("press any key to continue..");
        getch();
        restart_game();
    }
    getch();
}
int winGame(char arr[][3]) // Checking wining situation after position value replace by (x) or (O)
{
    int i, j,pluso,plusx;
    for (int i = 0; i < 3; i++)
    {
        pluso=0,plusx=0;
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == 'X')
                plusx++;
            if (arr[i][j] == 'O')
                pluso++;
        }
        if (plusx == 3)
            return 1;
        if (pluso == 3)
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        int countX = 0, countO = 0;
        for (j = 0; j < 3; j++)
        {
            if (arr[j][i] == 'X')
                countX++;
            if (arr[j][i] == 'O')
                countO++;
        }
        if (countO == 3)
            return 1;
        if (countX == 3)
            return 1;
    }
    int countX = 0, countO = 0;
    for (i = 0; i < 3; i++)
    {
        if (arr[i][i] == 'X')
            countX++;
        if (arr[i][i] == 'O')
            countO++;
    }
    if (countO == 3)
        return 1;
    if (countX == 3)
        return 1;

    countX = 0, countO = 0;
    for (i = 0, j = 2; i < 3; i++, j--)
    {
        if (arr[i][j] == 'X')
            countX++;
        if (arr[i][j] == 'O')
            countO++;
    }
    if (countO == 3)
        return 1;
    if (countX == 3)
        return 1;
    else if(arr[0][0] != '1' && arr[0][1] != '2' && arr[0][2] != '3' && arr[1][0] != '4' && arr[1][1] != '5' && arr[1][2] != '6' && arr[2][0] != '7' && arr[2][1] != '8' && arr[2][2] !='9')
    return 0;
    else
    return -1;
}
void Enter_smart_com_Position_value(char arr[][3],char name[3][30])  //// For playsmart_comp();
{
    srand(time(0));
    int i,player=1,place=0,j;
    char sign;
    do
    {
    system("color 9e");
    Print_position_value(arr,name);
    player=(player%2) ? 1 : 2;
    printf("\n\nPlayer %d, %s \n enter the place value : ",player,name[player]);
    scanf("%d",&place);
    if(place==1)
            place='1';
        else if(place==2)
            place='2';
        else if(place==3)
            place='3';
        else if(place==4)
            place='4';
        else if(place==5)
            place='5';
        else if(place==6)
            place='6';
        else if(place==7)
            place='7';
        else if(place==8)
            place='8';
        else if(place==9)
            place='9';
        sign=player==1 ? 'X' : 'O';
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]==place){
                    arr[i][j]=sign;
                    goto past;
                }
            }
        }
            printf("Invalid option !");
            place=0;
            player--;
            sleep(2);
            goto futur;
        past :
        i=winGame(arr);
        player++;
        if(i==-1){
        // for win
        // first row
         if (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] != 'X')
        arr[0][2] = 'O';
    else if (arr[0][0] == 'O' && arr[0][2] == 'O' && arr[0][1] != 'X')
        arr[0][1] = 'O';
    else if (arr[0][1] == 'O' && arr[0][2] == 'O' && arr[0][0] != 'X')
        arr[0][0] = 'O';

    // second row
    else if (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] != 'X')
        arr[1][2] = 'O';
    else if (arr[1][0] == 'O' && arr[1][2] == 'O' && arr[1][1] != 'X')
        arr[1][1] = 'O';
    else if (arr[1][1] == 'O' && arr[1][2] == 'O' && arr[1][0] != 'X')
        arr[1][0] = 'O';

    // third row
    else if (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] != 'X')
        arr[2][2] = 'O';
    else if (arr[2][0] == 'O' && arr[2][2] == 'O' && arr[2][1] != 'X')
        arr[2][1] = 'O';
    else if (arr[2][1] == 'O' && arr[2][2] == 'O' && arr[2][0] != 'X')
        arr[2][0] = 'O';

    // first col
    else if (arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] != 'X')
        arr[2][0] = 'O';
    else if (arr[0][0] == 'O' && arr[2][0] == 'O' && arr[1][0] != 'X')
        arr[1][0] = 'O';
    else if (arr[1][0] == 'O' && arr[2][0] == 'O' && arr[0][0] != 'X')
        arr[0][0] = 'O';

    // second col
    else if (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] != 'X')
        arr[2][1] = 'O';
    else if (arr[0][1] == 'O' && arr[2][1] == 'O' && arr[1][1] != 'X')
        arr[1][1] = 'O';
    else if (arr[1][1] == 'O' && arr[2][1] == 'O' && arr[0][1] != 'X')
        arr[0][1] = 'O';

    // third col
    else if (arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] != 'X')
        arr[2][2] = 'O';
    else if (arr[0][2] == 'O' && arr[2][2] == 'O' && arr[1][2] != 'X')
        arr[1][2] = 'O';
    else if (arr[1][2] == 'O' && arr[2][2] == 'O' && arr[0][2] != 'X')
        arr[0][2] = 'O';
    // left diagonal
    else if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] != 'X')
        arr[2][2] = 'O';
    else if (arr[0][0] == 'O' && arr[2][2] == 'O' && arr[1][1] != 'X')
        arr[1][1] = 'O';
    else if (arr[1][1] == 'O' && arr[2][2] == 'O' && arr[0][0] != 'X')
        arr[0][0] = 'O';
    // right diagonal
    else if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] != 'X')
        arr[2][0] = 'O';
    else if (arr[0][2] == 'O' && arr[2][0] == 'O' && arr[1][1] != 'X')
        arr[1][1] = 'O';
    else if (arr[1][1] == 'O' && arr[2][0] == 'O' && arr[0][2] != 'X')
        arr[0][2] = 'O';
    // for defend
    // first row
    else if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] != 'O')
        arr[0][2] = 'O';
    else if (arr[0][0] == 'X' && arr[0][2] == 'X' && arr[0][1] != 'O')
        arr[0][1] = 'O';
    else if (arr[0][1] == 'X' && arr[0][2] == 'X' && arr[0][0] != 'O')
        arr[0][0] = 'O';
    // for second row
    else if (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] != 'O')
        arr[1][2] = 'O';
    else if (arr[1][0] == 'X' && arr[1][2] == 'X' && arr[1][1] != 'O')
        arr[1][1] = 'O';
    else if (arr[1][1] == 'X' && arr[1][2] == 'X' && arr[1][0] != 'O')
        arr[1][0] = 'O';

    // for third row
     else if (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] != 'O')
        arr[2][2] = 'O';
    else if (arr[2][0] == 'X' && arr[2][2] == 'X' && arr[2][1] != 'O')
        arr[2][1] = 'O';
    else if (arr[2][1] == 'X' && arr[2][2] == 'X' && arr[2][0] != 'O')
        arr[2][0] = 'O';
    // for first col
    else if (arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] != 'O')
        arr[2][0] = 'O';
    else if (arr[0][0] == 'X' && arr[2][0] == 'X' && arr[1][0] != 'O')
        arr[1][0] = 'O';
     else if (arr[1][0] == 'X' && arr[2][0] == 'X' && arr[0][0] != 'O')
        arr[0][0] = 'O';

    // for second col
    else if (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] != 'O')
        arr[2][1] = 'O';
    else if (arr[0][1] == 'X' && arr[2][1] == 'X' && arr[1][1] != 'O')
        arr[1][1] = 'O';
     else if (arr[1][1] == 'X' && arr[2][1] == 'X' && arr[0][1] != 'O')
        arr[0][1] = 'O';

    // for third row
     else if (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] != 'O')
        arr[2][2] = 'O';
    else if (arr[0][2] == 'X' && arr[2][2] == 'X' && arr[1][2] != 'O')
        arr[1][2] = 'O';
    else if (arr[1][2] == 'X' && arr[2][2] == 'X' && arr[0][2] != 'O')
        arr[0][2] = 'O';

    // for left diagonal
    else if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] != 'O')
        arr[2][2] = 'O';
    else if (arr[0][0] == 'X' && arr[2][2] == 'X' && arr[1][1] != 'O')
        arr[1][1] = 'O';
    else if (arr[1][1] == 'X' && arr[2][2] == 'X' && arr[0][0] != 'O')
        arr[0][0] = 'O';

    // for right diagonal
    else if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] != 'O')
        arr[2][0] = 'O';
    else if (arr[0][2] == 'X' && arr[2][0] == 'X' && arr[1][1] != 'O')
        arr[1][1] = 'O';
    else if (arr[1][1] == 'X' && arr[2][0] == 'X' && arr[0][2] != 'O')
        arr[0][2] = 'O';
        else
        {
            while (1)
            {
                int place = rand() % 9 + 1;
            if(place==1)
            place='1';
        else if(place==2)
            place='2';
        else if(place==3)
            place='3';
        else if(place==4)
            place='4';
        else if(place==5)
            place='5';
        else if(place==6)
            place='6';
        else if(place==7)
            place='7';
        else if(place==8)
            place='8';
        else if(place==9)
            place='9';
                if (check_exist(place,arr))
                {
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            if (arr[i][j] == place)
                                arr[i][j] = 'O';

                    break;
                }
            }
        }
        futur :
        i=winGame(arr);
        player++;
        }
    }while(i==-1);
      Print_position_value(arr,name); // Function call for display position value after replace by 0 or *
    if(i==1)
    {
        printf("\n\n\n#######################################################################\n\n");
        printf("Player %d %s   Congratulations, You won!\n",player,name[--player]);
        printf("\n#######################################################################\n\n");
        printf("press any key to continue....");
        getch();
        restart_game();
    }
    else if(i==0)
    {
        printf("\n\n\n#######################################################################\n\n");
        printf("Game draw!\n");
        printf("\n#######################################################################\n\n");
        printf("press any key to continue..");
        getch();
        restart_game();
    }
    getch();
}
void Enter_evil_com_Position_value(char arr[][3],char name[3][30])   // For playevil_com();
{
    srand(time(0));
    int i,player=1,place=0,j,flag=0;
    char sign;
    do
    {
    system("color 9e");
    Print_position_value(arr,name);
    player=(player%2) ? 1 : 2;
    printf("\n\nPlayer %d, %s \n enter the place value : ",player,name[player]);
    scanf("%d",&place);
    if(place==1)
            place='1';
        else if(place==2)
            place='2';
        else if(place==3)
            place='3';
        else if(place==4)
            place='4';
        else if(place==5)
            place='5';
        else if(place==6)
            place='6';
        else if(place==7)
            place='7';
        else if(place==8)
            place='8';
        else if(place==9)
            place='9';
        sign=player==1 ? 'X' : 'O';
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]==place){
                    arr[i][j]=sign;
                    goto past;
                }
            }
        }
            printf("Invalid option !");
            place=0;
            player--;
            sleep(2);
            goto futur;
        past :
        i=winGame(arr);
        player++;
        if(i==-1){
            if(player==2){
        // for win
        // first row
        flag=0;
         if (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] != 'X'){
        arr[0][2] = 'O';
        flag=1;
         }
    else if (arr[0][0] == 'O' && arr[0][2] == 'O' && arr[0][1] != 'X'){
        arr[0][1] = 'O';
        flag=1;
         }
    else if (arr[0][1] == 'O' && arr[0][2] == 'O' && arr[0][0] != 'X'){
        arr[0][0] = 'O';
        flag=1;
         }
    // second row
    else if (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] != 'X'){
        arr[1][2] = 'O';
        flag=1;
         }
    else if (arr[1][0] == 'O' && arr[1][2] == 'O' && arr[1][1] != 'X'){
        arr[1][1] = 'O';
        flag=1;
         }
    else if (arr[1][1] == 'O' && arr[1][2] == 'O' && arr[1][0] != 'X'){
        arr[1][0] = 'O';
        flag=1;
         }

    // third row
    else if (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] != 'X'){
        arr[2][2] = 'O';
        flag=1;
         }
    else if (arr[2][0] == 'O' && arr[2][2] == 'O' && arr[2][1] != 'X'){
        arr[2][1] = 'O';
        flag=1;
         }
    else if (arr[2][1] == 'O' && arr[2][2] == 'O' && arr[2][0] != 'X'){
        arr[2][0] = 'O';
        flag=1;
         }

    // first col
    else if (arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] != 'X'){
        arr[2][0] = 'O';
        flag=1;
         }
    else if (arr[0][0] == 'O' && arr[2][0] == 'O' && arr[1][0] != 'X'){
        arr[1][0] = 'O';
        flag=1;
         }
    else if (arr[1][0] == 'O' && arr[2][0] == 'O' && arr[0][0] != 'X'){
        arr[0][0] = 'O';
        flag=1;
         }

    // second col
    else if (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] != 'X'){
        arr[2][1] = 'O';
        flag=1;
         }
    else if (arr[0][1] == 'O' && arr[2][1] == 'O' && arr[1][1] != 'X'){
        arr[1][1] = 'O';
        flag=1;
         }
    else if (arr[1][1] == 'O' && arr[2][1] == 'O' && arr[0][1] != 'X'){
        arr[0][1] = 'O';
        flag=1;
         }

    // third col
    else if (arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] != 'X'){
        arr[2][2] = 'O';
        flag=1;
         }
    else if (arr[0][2] == 'O' && arr[2][2] == 'O' && arr[1][2] != 'X'){
        arr[1][2] = 'O';
        flag=1;
         }
    else if (arr[1][2] == 'O' && arr[2][2] == 'O' && arr[0][2] != 'X'){
        arr[0][2] = 'O';
        flag=1;
         }

    // left diagonal
    else if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] != 'X'){
        arr[2][2] = 'O';
        flag=1;
         }
    else if (arr[0][0] == 'O' && arr[2][2] == 'O' && arr[1][1] != 'X'){
        arr[1][1] = 'O';
        flag=1;
         }
    else if (arr[1][1] == 'O' && arr[2][2] == 'O' && arr[0][0] != 'X'){
        arr[0][0] = 'O';
        flag=1;
         }

    // right diagonal
    else if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] != 'X'){
        arr[2][0] = 'O';
        flag=1;
         }
    else if (arr[0][2] == 'O' && arr[2][0] == 'O' && arr[1][1] != 'X'){
        arr[1][1] = 'O';
        flag=1;
         }
    else if (arr[1][1] == 'O' && arr[2][0] == 'O' && arr[0][2] != 'X'){
        arr[0][2] = 'O';
        flag=1;
         }

    // for defend
    // first row
    else if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] != 'O'){
        arr[0][2] = 'O';
        flag=1;
         }
    if (arr[0][0] == 'X' && arr[0][2] == 'X' && arr[0][1] != 'O'){
        arr[0][1] = 'O';
        flag=1;
         }
    if (arr[0][1] == 'X' && arr[0][2] == 'X' && arr[0][0] != 'O'){
        arr[0][0] = 'O';
        flag=1;
         }

    // for second row
    if (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] != 'O'){
        arr[1][2] = 'O';
        flag=1;
         }
    if (arr[1][0] == 'X' && arr[1][2] == 'X' && arr[1][1] != 'O'){
        arr[1][1] = 'O';
        flag=1;
         }
    if (arr[1][1] == 'X' && arr[1][2] == 'X' && arr[1][0] != 'O'){
        arr[1][0] = 'O';
        flag=1;
         }

    // for third row
    if (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] != 'O'){
        arr[2][2] = 'O';
        flag=1;
         }
    if (arr[2][0] == 'X' && arr[2][2] == 'X' && arr[2][1] != 'O'){
        arr[2][1] = 'O';
        flag=1;
         }
    if (arr[2][1] == 'X' && arr[2][2] == 'X' && arr[2][0] != 'O'){
        arr[2][0] = 'O';
        flag=1;
         }

    // for first col
    if (arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] != 'O'){
        arr[2][0] = 'O';
        flag=1;
         }
    if (arr[0][0] == 'X' && arr[2][0] == 'X' && arr[1][0] != 'O'){
        arr[1][0] = 'O';
        flag=1;
         }
    if (arr[1][0] == 'X' && arr[2][0] == 'X' && arr[0][0] != 'O'){
        arr[0][0] = 'O';
        flag=1;
         }

    // for second col
    if (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] != 'O'){
        arr[2][1] = 'O';
        flag=1;
         }
    if (arr[0][1] == 'X' && arr[2][1] == 'X' && arr[1][1] != 'O'){
        arr[1][1] = 'O';
        flag=1;
         }
    if (arr[1][1] == 'X' && arr[2][1] == 'X' && arr[0][1] != 'O'){
        arr[0][1] = 'O';
        flag=1;
         }

    // for third row
    if (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] != 'O'){
        arr[2][2] = 'O';
        flag=1;
         }
    if (arr[0][2] == 'X' && arr[2][2] == 'X' && arr[1][2] != 'O'){
        arr[1][2] = 'O';
        flag=1;
         }
    if (arr[1][2] == 'X' && arr[2][2] == 'X' && arr[0][2] != 'O'){
        arr[0][2] = 'O';
        flag=1;
         }

    // for left diagonal
    if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] != 'O'){
        arr[2][2] = 'O';
        flag=1;
         }
    if (arr[0][0] == 'X' && arr[2][2] == 'X' && arr[1][1] != 'O'){
        arr[1][1] = 'O';
        flag=1;
         }
    if (arr[1][1] == 'X' && arr[2][2] == 'X' && arr[0][0] != 'O'){
        arr[0][0] = 'O';
        flag=1;
         }

    // for right diagonal
    if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] != 'O'){
        arr[2][0] = 'O';
        flag=1;
         }
    if (arr[0][2] == 'X' && arr[2][0] == 'X' && arr[1][1] != 'O'){
        arr[1][1] = 'O';
        flag=1;
         }
    if (arr[1][1] == 'X' && arr[2][0] == 'X' && arr[0][2] != 'O'){
        arr[0][2] = 'O';
        flag=1;
         }
        }
    if(flag==0){
            while (1)
            {
                int place = rand() % 9 + 1;
            if(place==1)
            place='1';
        else if(place==2)
            place='2';
        else if(place==3)
            place='3';
        else if(place==4)
            place='4';
        else if(place==5)
            place='5';
        else if(place==6)
            place='6';
        else if(place==7)
            place='7';
        else if(place==8)
            place='8';
        else if(place==9)
            place='9';
                if (check_exist(place,arr))
                {
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            if (arr[i][j] == place)
                                arr[i][j] = 'O';

                    break;
                }
            }
        }
        futur:
        i=winGame(arr);
        player++;
        }
    }while(i==-1);
      Print_position_value(arr,name); // Function call for display position value after replace by 0 or *
    if(i==1)
    {
        printf("\n\n\n#######################################################################\n\n");
        printf("Player %d %s   Congratulations, You won!\n",player,name[--player]);
        printf("\n#######################################################################\n\n");
        printf("press any key to continue....");
        getch();
        restart_game();
    }
    else if(i==0)
    {
        printf("\n\n\n#######################################################################\n\n");
        printf("Game draw!\n");
        printf("\n#######################################################################\n\n");
        printf("press any key to continue..");
        getch();
        restart_game();
    }
    getch();
}
void restart_game() // Restart the game
{
    system("cls");
    int choice=0;
    printf("\n 1 : start game\n");
    printf(" 2 : Close game\n\n");
    printf("Enter your choice\n\n");
    scanf("%d",&choice);
    if(choice==1)
        main();
    else{
        printf("Thnx for playing!, Hope you will be enjoyed in this game!, Plz visit again!");
        sleep(4);
        exit(0);
    }

}
void playfriend(char name[3][30],char arr[][3]) // Playing with friend
{
    system("cls");
    int flag=0;
    printf("\n\n\t-----play with friends------\n");
    Enter_name(name,flag);
    Enter_Position_value(arr,name);
}
void playsmart_comp(char name[3][30],char arr[][3]) // Playing with smart computer
{
    system("cls");
    int flag = 1;
    printf("\n\n\t----Play With Smart computer----\n");
    Enter_name(name,flag);
    Enter_smart_com_Position_value(arr,name);

}
void playevil_comp(char name[3][30],char arr[][3]) // Playing with evil computer
{
    system("cls");
    int flag = 2;
    printf("\n\n\t----Play With Evil computer----\n");
    Enter_name(name,flag);
    Enter_evil_com_Position_value(arr,name);
}
int check_exist(int place,char arr[][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (arr[i][j] == place)
                return 1;
    return 0;
}
int Display_menu()  // Display game menu
{
    int choice;
    while (1)
    {
        system("cls");
        printf("\n\t< ***** New Game ***** >");
        printf("\n\n1 - Play With Friends(%c)",2);
        printf("\n2 - Play With Smart Computer (%c)",2);
        printf("\n3 - Play With Evil Computer (%c)",2);
        printf("\n4 - Exit (%c)",1);
        printf("\n\tEnter Your Choice: ");
        scanf("%d",&choice);
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
            return choice;
        else
        {
            printf("\n\tInvald Input.. TRY AGAIN!");
            getch();
        }
    }
}


