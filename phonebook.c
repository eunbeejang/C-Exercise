#include<stdio.h>
#include<stdlib.h>

void FindRecord(char*, char*, char[]);
void Replace(char*, char*, char[]);
void SaveRecord(char*, char*, char[]);


void main() {

	char name[1000] = {'\0'};
	char new_name[1000] = {'\0'};
	char record[1000] = {'\0'};
	char file_name[1000] = "phonebook.csv";
	

	// Ask for a name
	printf("Search person name: ");
	fgets(name, sizeof(name), stdin);


        // Ask for a replacement name
        printf("Replacement name: ");
        fgets(new_name, sizeof(new_name), stdin);
	

	FindRecord(file_name, name, record);
	Replace(name, new_name, record);
	SaveRecord(file_name, name, record);

	exit(0);

}


void FindRecord(char* filename, char* name, char record[]) {
	char temp[1000] = {'\0'};
	
	// Open the .csv file
	FILE *fp = fopen(filename, "r");


	// Terminate the program if the file does not exit
	if (fp == NULL) {
		printf("%s does not exist. Terminating the program.\n", *filename);
		exit(1);


	// Otherwise, search for the name
	} else {
		int i = 0;
		int j = 0;
		int found = 0;

		while(!feof(fp)) {
			fgets(temp, 999, fp);			
			
			// If the first letters match, check whether the rest of the letters are same
			if (temp[i] == name[0]) {
				while (temp[i] == name[j]) {
				i++;
				j++;
				}


				// If the length of the names do not match, terminate the program
				if (((temp[i] == ',') && !(name[j]  == '\n')) || (!(temp[i] == ',') && (name[j]  == '\n'))) {
					printf("Name not found.\nTerminating the program.\n");
					exit(1);
					break;


				// If the name is found, fetch the matching record
				} if ((temp[i] == ',') && (name[j]  == '\n')) {
					printf("Name found in the record.\n");
					for (int k = 0; temp[k] != '\0'; k++) {
						record[k] = temp[k];
					}
					found = 1;					
					break;	
					
				}
	
			}
						
		}

		if (found == 0) {
			printf("Name not found.\nTerminating the program.\n");
			exit(1);
		}
	
	}
	fclose(fp);
}





void Replace(char* name, char* newname, char record[]){

	char replace[1000] = {'\0'};


	// Copy newname into "replace" array
	// Count the length of the newname	
	int n = 0;
	for (char* precord = replace; (*precord = *newname) != '\0'; ++precord, ++newname) {
		n++;
	}


	// Check the length of the name
	int k = 0;
	while (*name++) {
		k++;
	}
	

	// Copy age and phone number into 'replace' array
	char* record_copy = record+k-1;
	for (char* precordc = (replace+n-1); (*precordc = (*record_copy)) != '\0'; ++precordc, ++record_copy) {
               ;
       }

    
	// Update the record
	for (int i = 0; i < sizeof(replace); i++) {
		*(record + i) = *(replace+i);
	}


	printf("The name successfully replaced with the replacement name.\n");

}





void SaveRecord(char* filename, char *name, char record[]) {
	char temp[1000] = {'\0'};


	// Open phonebook.csv
	// Create a temporary csv file to store new record
	FILE *fr = fopen(filename, "rt");
	FILE *fw = fopen("temp.csv", "w");


	// If the file does not exist, terminate the program
        if (fw == NULL) {
                printf("%s does not exist. Terminating the program.\n", *filename);
                exit(1);


	// Otherwise, store updated information into temp.csv
        } else {
                int i = 0;
                int j = 0;
		int number;


		while(1) {
                        fscanf(fr, "%s", temp);
			if(feof(fr)){
				break;
			}			


			// Append the line that holds new name 
			if (temp[i] == name[0]) {
                                while (temp[i] == name[j]) {
                                i++;
                                j++;
                                }
                                if ((temp[i] == ',') && (name[j]  == '\n')) {
                                        fprintf(fw, "%s", record);
                                }


			// Append the other lines
                        } else {
				fprintf(fw, "%s\n", temp);
			}
 
               }

        }
	fclose(fr);
	fclose(fw);


	// Remove current phonebook.csv file and rename temp.csv file as new phonebook.csv
	remove(filename);

	if(rename("temp.csv", filename) == 0) {
		printf("File successfully saved.\nTerminating the program.\n");
		exit(0);
	} else {
		printf("ERROR: File not saved.\nTerminating the program.\n");
		exit(1);
	}
}






