#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char encryption(char, int);
char decryption(char, int);


int main()
{

	char plainText[100];
	char ciperText[100]="";
	char decryptText[100]="";
	char tempEncrypt;
	char tempDecrypt;
	int key;
	int i,j;


	// Two inputs typed in by the user -- Sentence and Key
	printf("Sentence: ");
	scanf("%[^\n]s", plainText);
	
	printf("Key: ");
	scanf("%d", &key);

	// Print error message when user inputs wrong key number
	if(key < 1 || key > 25)
	{
		printf("Key must be between 1 and 25. Terminating the program. \n");
		exit(1);
	}



	// Print out the original message typed by the user

	printf("Original message: %s \n", plainText);



	/* 
	 * Encryption
	 * The for-loop iterates through the char array
	 * which contains the original message, 
 	 * left shifts each char, then stores the shifted char into ciperText
	 */

	printf("Encrypted message: ");
	
	for(i=0; i < strlen(plainText); i++)
	{

		tempEncrypt=encryption(plainText[i], key);
		ciperText[i]=tempEncrypt;
	}

        printf("%s \n", ciperText);



        /* 
         * Decryption
         * The for-loop iterates through the char array 
         * which contains encrypted message,       
         * right shifts each char, then stores the shifted char into decryptText
         */

	printf("Decrypted message: ");
	
	for(j=0; j < strlen(ciperText); j++)
	{
		tempDecrypt=decryption(ciperText[j], key);
		decryptText[j]=tempDecrypt;
	}

	printf("%s \n", decryptText);



	return 0;

}





// Function for Encryption

char encryption(char letter, int key)
{

	int setLetter;
	int temp;



	// Leave any space as is, and only shift alphabet letters

	if(letter==' ')
	{
		temp=' ';
	}



	// Left shift uppercase letters

	else if(letter>='A' && letter<='Z')
	{

		setLetter=letter-65;

		if(setLetter-key<0)
		{
			temp=((26+setLetter-key)%26)+65;
		}
		else
		{	
			temp=(setLetter-key)+65;
		}

	}



	// Left shift lowercase letters

	else if(letter>='a' && letter<='z')	
	{
		
		setLetter=letter-97;
		

		if(setLetter-key<0)
		{
			temp=((26+setLetter-key)%26)+97;
		}
		else
		{
			temp=(setLetter-key)+97;
		}

	}



	// In all other cases, leave the char as it is

	else
	{
		temp=letter;
	}



	return temp;

}




// Function for decryption

char decryption(char letter, int key)
{

	int setLetter;
	int temp;



        // Leave any space as is, and only shift alphabet letters

        if(letter==' ')
        {
                temp=' ';
        }



	// Right shift uppercase letters

        else if(letter>='A' && letter<='Z')
        {
		setLetter=letter-65;
		temp=((setLetter+key)%26)+65;
        }



	// Right shift lowercase letters

        else if(letter>='a' && letter<='z')
        {
                setLetter=letter-97;
                temp=((setLetter+key)%26)+97;
        }



        // In all other cases, leave the char as it is

	else
	{
		temp=letter;
	}



        return temp;

}
