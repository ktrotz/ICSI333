
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Global declarations
const char LETTERS[27] = {'A','B','C','D','E','F','G','H','I','J',
                          'K','L','M','N','O','P','Q','R','S','T',
						  'U','V','W','X','Y','Z', ' '};
	
const char ROTOR_VALUES[10] = {7, 3, 0, 1, 9, 5, 2, 6, 4, 8};
const int ROTOR_SIZE = 10;
const int TEXT_SIZE = 256;
int rotorPosition1, rotorPosition2, rotorPosition3;


/* findCharIndex:  Finds the location(index) of a character in the
    Letters array
 * Input:  Character to find in Letters Array
 * Output: Index location in the Letters Array
 * Note:  Returns -1 if not found
 */
int findCharIndex(char c)
{
    //TODO: Need to implement this function
     
    //traverse array
    for(int index = 0; index < sizeof(LETTERS); index = index + 1)
    {
        //return position of char if char value is found
        if(LETTERS[index] == c)
        {
            return index;
        }       
    }    
    
    return -1; //if not found 
}

/*  mod:  Implements a true modulus function
 *  INPUT: original number (a) and dividor (b)
 *  OUTPUT: remainder
 *  NOTE:  Required since in C (%) does not implement true modulus
 *         function for negative remainders   */
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}


/* encryptLetter:  Returns an encrypted letter (character)
 * INPUT:  unencrypted letter (character) and key
 * OUTPUT:  encrypted letter   */
char encryptLetter(char unencrypted, int key)
{
    //TODO: Need to implement this function
    
    //unencrypted = original letter at inputText[i]
    //key = sum of the current values of each rotor position 
    
    //find unencrypted input's position to create new key
    int charIndex = findCharIndex(unencrypted);    
    int newKey = charIndex + key;
    
    if(newKey > 26)
    {
        newKey = newKey - 27; //charIndex + key - 27
    }
    
    char encrypted = LETTERS[newKey]; 
    
    return encrypted;
}

/* decryptLetter:  Returns an decrypted letter (character)
 * INPUT:  encrypted letter (character) and key
 * OUTPUT:  decrypted letter  */
char decryptLetter(char encrypted, int key)
{
    //TODO: Need to implement this function
    
    //find encrypted input's position to create new key
    int charIndex = findCharIndex(encrypted);
    int newKey = charIndex - key;
    
    if(newKey < 0)
    {
        newKey = 27 + (newKey); // 27 + charIndex - key
    }
    
    char unencrypted = LETTERS[newKey];
    
    return unencrypted;     
}

/* getKey: returns key based on current positions of the rotors  */
int getKey()
{
	return ROTOR_VALUES[rotorPosition1]+ROTOR_VALUES[rotorPosition2]+ROTOR_VALUES[rotorPosition3];	
}

/* incrementRotors: Advances rotor positions by one
 * USAGE: Used after every letter is encrypted or decrypted  */
void incrementRotors()
{
	rotorPosition1++;
	if (rotorPosition1 == ROTOR_SIZE){
		rotorPosition1 = 0;
		rotorPosition2++;
	}
	if (rotorPosition2 == ROTOR_SIZE){
		rotorPosition2 = 0;
		rotorPosition3++;
	}
	if (rotorPosition3 == ROTOR_SIZE)
		rotorPosition3 = 0;
}

int main( int argc, char *argv[] )
{
	//STEP #1: Get and check Command Line Arguments
	//TODO:  Implement this step  

    //argv is array of strings representing command line arguments
    //atoi converts string to int
    rotorPosition1 = atoi(argv[1]); 
    rotorPosition2 = atoi(argv[2]); 
    rotorPosition3 = atoi(argv[3]); 
   
    printf("\n\nRotor #1 Position is set to %d\n", rotorPosition1);
    printf("Rotor #2 Position is set to %d\n", rotorPosition2);
    printf("Rotor #3 Position is set to %d\n", rotorPosition3);  
    
    
    //STEP #2: Get text string from user
	char inputText[TEXT_SIZE];
	char outputText[TEXT_SIZE];
	scanf("%[^\n]%*c" , inputText );
	printf("\nInput text supplied is: %s\n", inputText);
    int input_text_size = strlen(inputText) - 1; 	//minus 1 to ignore \n char   

    
    int key; 
    printf("\n");
    
    //STEP #3: For each letter, encrypt or decrypt
    for (int i = 0; i <= input_text_size; i++)
    {
        //TODO:  Implement this step   
       
        //compare command line args to decide whether to encrypt or decrypt
        if(strcmp("e", argv[4]) == 0) //0 means equal
        {
            key = getKey(); //sum of all rotor values at their input position
            
            outputText[i] = encryptLetter(inputText[i], key); //creates output array
            incrementRotors();
            
            printf("unencrypted letter: %c | encrypted letter: %c\n", inputText[i], outputText[i]);
        } 
        
        else if(strcmp("d", argv[4]) == 0)
        {
            key = getKey();
            
            outputText[i] = decryptLetter(inputText[i], key); //creates output array
            incrementRotors(); 
            
            printf("encrypted letter: %c | unencrypted letter: %c\n", inputText[i], outputText[i]);
        }       
    }


    //STEP #4: Print result
	outputText[input_text_size + 1] = '\0';
	printf("\nOutput text: %s\n\n", outputText);

	return EXIT_SUCCESS;
}