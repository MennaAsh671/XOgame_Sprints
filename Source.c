#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable : 4996)


char mat[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
char ans;
bool add(int h, int v)
{
    if (mat[h - 1][v - 1] == ' ')
    {
        mat[h - 1][v - 1] = ans;
        return true;
    }
    else
        return false;
}
void display()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%-3c", mat[j][i]);
        }
        printf("\n");
    }
}
char playerwin(char mat[3][3])
{
    if ((mat[0][0] == 'x') && (mat[0][1] == 'x') && (mat[0][2] == 'x')) {
        return 'x';
    }
    else if ((mat[1][0] == 'x') && (mat[1][1] == 'x') && (mat[1][2] == 'x'))
    {
        return 'x';
    }
    else if ((mat[2][0] == 'x') && (mat[2][1] == 'x') && (mat[2][2] == 'x'))
    {
        return 'x';
    }
    else if ((mat[0][0] == 'x') && (mat[1][0] == 'x') && (mat[2][0] == 'x'))
    {
        return 'x';
    }
    else if ((mat[0][1] == 'x') && (mat[1][1] == 'x') && (mat[2][1] == 'x'))
    {
        return 'x';
    }
    else if ((mat[0][2] == 'x') && (mat[1][2] == 'x') && (mat[2][2] == 'x'))
    {
        return 'x';
    }
    else if ((mat[0][0] == 'o') && (mat[0][1] == 'o') && (mat[0][2] == 'o'))
    {
        return 'o';
    }
    else if ((mat[1][0] == 'o') && (mat[1][1] == 'o') && (mat[1][2] == 'o'))
    {
        return 'o';
    }
    else if ((mat[2][0] == 'o') && (mat[2][1] == 'o') && (mat[2][2] == 'o'))
    {
        return 'o';
    }
    else if ((mat[0][0] == 'o') && (mat[1][0] == 'o') && (mat[2][0] == 'o'))
    {
        return 'o';
    }
    else if ((mat[0][1] == 'o') && (mat[1][1] == 'o') && (mat[2][1] == 'o'))
    {
        return 'o';
    }
    else if ((mat[0][2] == 'o') && (mat[1][2] == 'o') && (mat[2][2] == 'o'))
    {
        return 'o';
    }
    else if ((mat[0][0] == 'x') && (mat[1][1] == 'x') && (mat[2][2] == 'x'))
    {
        return 'x';
    }
    else if ((mat[2][0] == 'x') && (mat[1][1] == 'x') && (mat[0][2] == 'x'))
    {
        return 'x';
    }
    else if ((mat[0][0] == 'o') && (mat[1][1] == 'o') && (mat[2][2] == 'o'))
    {
        return 'o';
    }
    else if ((mat[2][0] == 'o') && (mat[1][1] == 'o') && (mat[0][2] == 'o'))
    {
        return 'o';
    }
    else
    {
        return 't';             //no player wins ,tie
    }
}
int main()
{
    do
    {
        printf("Enter X to be the first player or O to be the second player:");
        scanf("%c", &ans);
    } while (ans != 'x' && ans != 'o');
    int h, v;
    ans = 'x';
    printf("   1  2  3 \n 1\n 2\n 3\n");
    for (int i = 0; i < 9; i++)
    {
        printf("\n%c turn\nEnter the location of the character:\n", ans);
        printf("col:");
        scanf_s("%d", &h);
        printf("row:");
        scanf_s("%d", &v);
        if (add(h, v))
        {
            display();
            if (playerwin(mat) == 'x')
            {
                i = 9;
                printf("X wins.");
            }
            else if (playerwin(mat) == 'o')
            {
                i = 9;
                printf("O wins.");
            }
            else if ((playerwin(mat) == 't') && (i == 8)) //all places occupied 
            {
                printf("Game Over.\n");
            }

            if (ans == 'x')
                ans = 'o';
            else
                ans = 'x';
        }
        else // add is false cell is not empty
        {
            i--;
            printf("this cell is occupied.\n");

        }
    }

    return 0;
}