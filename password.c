#include <stdio.h>
#include <string.h>
#include <ctype.h>


void checkpassword(char *password, char *username) {
    int upper = 0, lower = 0, digit = 0, special_char = 0;


    if (strlen(password) >= 8)
    {
        for (int i = 0; i < strlen(password); i++) {
            if (isupper(password[i])) 
            { upper = 1; }
            if (islower(password[i]))
            { lower = 1; }
            if (isdigit(password[i])) 
            { digit = 1; }
            if (password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '*') 
            {
                special_char = 1;
            }
        }

        
        if (upper==1 && lower==1 && digit==1 && special_char==1) {
            printf("Password for user %s is strong: %s\n", username, password);
        } else {
            printf("Password for user %s is weak: %s. It must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n", username, password);
        }
      } else { printf("Password for user %s is too short: %s (Minimum 8 characters required).\n", username, password);}
}


int main() {
    FILE *file;  
    char username[50], password[50];
    char line[100], name[100];

    printf("Enter the file name containing the password data:\n");
    scanf("%s", name);

    // Open the file
    file = fopen(name, "r");
    if (file == NULL) 
    {
        printf("File not found.\n");
        return 1; 
    }

    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^:]:%s", username, password); // this splits the string into two parts , separating with colon
        checkpassword(password, username);
    }

    fclose(file);
    return 0;
}