#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "game.h"

int main(int argc, char *argv[] )
{

    int spacesLeft = 9;
    initializeBoard();
    
    char turn = 'X';

    while(spacesLeft > 0)
    {

        if (turn == 'X')
        {
            //Human Player
            bool valid = humanPlayerMove();  
            if (valid){
                turn = 'O';
                spacesLeft--;
            }
            
            displayBoard();
        }
        else
        {
            //Computer Player
            computerPlayerMove();
            displayBoard();
            spacesLeft--;
            turn = 'X';
        }
        
    }
}


