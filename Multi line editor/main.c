#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void textattr(int i);
void gotoxy( int column, int line );
char* LineEditor(int size, int col,int row, int startKey,int endKey);

#define Extended -32
#define Enter 13
#define Esc 27
#define Home 71
#define End 79
#define Up 72
#define Down 80
#define left 75
#define right 77
#define Tap 9
#define backspace 8
#define _size 30


int main()
{
    int flag = 1;
    int* ptr[4];
    int* *dptr = ptr;

    for(int i = 0; i < 4; i++)
    {
        ptr[i] = malloc(_size * sizeof(int));
    }
    //  dptr[0]= LineEditor(_size , 20, 10,1 ,1);
    ///     dptr[cursor]= LineEditor(_size , 20, 10 + cursor,1 ,1);

    int cursor = 0;
    do
    {
        gotoxy(20, 10 + cursor);
        char ch = getch();
        switch(ch)
        {
        case Extended:
            ch = getch();
            switch (ch)
            {
            case Down:
                if(cursor < 3)
                {
                    cursor++;
                }
                else
                {
                    cursor = 0;
                }
                break;
            case Up:
                if(cursor > 0)
                {
                    printf("- counter");
                    cursor--;
                }
                else if(cursor == 3)
                {
                    printf("counter = 3");
                    cursor = 2;
                }
                break;
            }
        default:
            dptr[cursor]= LineEditor(_size, 20, 10 + cursor,1,1);
            if(cursor < 3)
                cursor++;
            else
                cursor = 0;
            break;
        }
    }
    while(flag);

    return 0;
}

/// 4 rows if i clicked down will go to next line
///

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}



char* LineEditor(int size, int col,int row, int startKey,int endKey)
{
    int first, curr,last;
    char *arr = malloc(size * sizeof(char)),flag = 1;
    char *pfirst, *pcurr, *plast;
    pfirst = pcurr = plast = arr;
    first = curr = last = 0;
    for(int i = 0; i < size; i++)
    {
        gotoxy(col+i,row);
        textattr(2);
    }

    do
    {
        gotoxy(col + curr,row);
        char ch = getch();

        switch(ch)
        {
        case Extended:
            ch = getch();
            switch(ch)
            {
            case left:
                if(curr > first)
                {
                    curr--;
                    pcurr--;
                }
                else
                {
                    /// curr == first;
                }
                break;
            case right:
                if(curr < last)
                {
                    curr++;
                    pcurr++;
                }
                break;

            case Home :
                curr = first;
                break;
            case End :
                curr = last;
                break;
            case Down:
                flag = 0;
                break;
            case Up:
                flag = 0;
                break;
            }

            break;
        case Esc:
        case Enter:
            *pcurr = '\0';
            flag = 0;
            break;
        case backspace:
            /// at the end curr == last
            if(curr == last)
            {
                gotoxy( col + curr - 1,row) ;
                printf(" ");
                curr--;
                last--;
                pcurr--;
            }
            break;
        default :
            if(ch >= 65 && ch <= 95)
            {
                if(curr == last)
                {
                    if(last < size)
                    {
                        *pcurr = ch;
                        pcurr++;
                        plast++;
                        curr++;
                        last++;
                        printf("%c",ch);
                    }
                }
                else
                {
                    *pcurr = ch;
                    pcurr++;
                    curr++;
                    printf("%c",ch);
                }
            }
        }
    }
    while(flag);
    return arr;
}

/// create double pointer pointing to the return of line editor
/// every row should point to a row address
/// switchcase on key if pressed and loop over the array
