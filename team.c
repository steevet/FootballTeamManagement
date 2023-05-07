//
// EECS2031 team.c
//
// Program for maintaining a personal team.
//
//
// Uses a linked list to hold the team players.
//
// Author: <Your Name Goes Steeve Toussaint>
// Student Info: <217998196>


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <string.h>

//**********************************************************************
// Linked List Definitions 
//  Define your linked list node and pointer types
//  here for use throughout the file.
//
//
//   ADD STATEMENT(S) HERE



//**********************************************************************
// Linked List Function Declarations
//
// Functions that modify the linked list.
//   Declare your linked list functions here.
//
//   ADD STATEMENT(S) HERE



//**********************************************************************
// Support Function Declarations
//

void safegets (char s[], int arraySize);        // gets without buffer overflow
void familyNameDuplicate (char familyName[]);   // marker/tester friendly 
void familyNameFound (char familyName[]);       //   functions to print
void familyNameNotFound (char familyName[]);    //     messages to user
void familyNameDeleted (char familyName[]);
void printTeamEmpty (void);
void printTeamTitle(void);
void printNoPlayersWithLowerValue(int value);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';
const char GOALKEEPER = 'G';
const char DEFENDER = 'D';
const char MIDFIELDER = 'M';
const char STRIKER = 'S';


//**********************************************************************
// Main Program
//

struct node{
    struct node* next;
    char familyName[1023]; //char *familyName;
    char firstName[1023];
    char pos;
    int value;
};

typedef struct node nodet;
void insert(struct node** head, char *firstName, char *familyName, char pos, int value);
void print(nodet *head);
void delete(struct node** head, char deleteNode[]);
void searchName(nodet** head, char familyname[]);
void searchValue(nodet** head, int value);
void quit(nodet** head);

int main (void) { 

    nodet *head = NULL;

    const char bannerString[]
        = "Personal Team Maintenance Program.\n\n";
    const char commandList[]
        = "Commands are I (insert), D (delete), S (search by name),\n"
          "  V (search by value), P (print), Q (quit).\n";

    // Declare linked list head.
    //   ADD STATEMENT(S) HERE TO DECLARE LINKED LIST HEAD.

 
    // announce start of program
    printf("%s",bannerString);
    printf("%s",commandList);
    
    char response;
    char input[MAX_LENGTH+1];
    do
    {
        printf("\nCommand?: ");
        safegets(input,MAX_LENGTH+1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I')
        {
            char firstname[MAX_LENGTH];
            char familyname[MAX_LENGTH];
            char position;
            int value;
            // Insert a player entry into the linked list.
            // Maintain the list in correct order (G, D, M, S).
            //   ADD STATEMENT(S) HERE

            // USE THE FOLLOWING PRINTF STATEMENTS WHEN PROMPTING FOR DATA:
            printf("  family name: ");
            safegets(familyname, MAX_LENGTH);

            printf("  first name: ");
            safegets(firstname, MAX_LENGTH);

            printf("  position: ");
            scanf("%c", &position);
            //safegets(position, 1);

            printf("  value: ");
            scanf("%d", &value);

            char pos = toupper(position);

            insert(&head, firstname, familyname, pos, value);

        }
        else if (response == 'D')
        {
            char familyname[MAX_LENGTH];
            // Delete a player from the list.

            printf("\nEnter family name for entry to delete: ");
            //safegets(familyname, 50);
            scanf("%s", familyname);
            //   ADD STATEMENT(S) HERE
            delete(&head, familyname);
        }
        else if (response == 'S')
        {
            char familyname[MAX_LENGTH];
            // Search for a player by family name.

            printf("\nEnter family name to search for: ");

            //   ADD STATEMENT(S) HERE
            scanf("%s", familyname);

            searchName(&head, familyname);

        }
        else if (response == 'V')
        {
            int value;
            // Search for players that are worth less than or equal a value.

            printf("\nEnter value: ");
            scanf("%d", &value);

            //   ADD STATEMENT(S) HERE

            searchValue(&head, value);

        }
        else if (response == 'P')
        {
            // Print the team.

            //   ADD STATEMENT(S) HERE
            print(head);

        }
        else if (response == 'Q')
        {
            ; // do nothing, we'll catch this case below
        }
        
        else 
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n",commandList);
        }
    } while (response != 'Q');
  
    // Delete the whole linked list that hold the team.
    //   ADD STATEMENT(S) HERE

    quit(&head);
    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE
    printf("Print result: ");
    print(head);


    return 0;
}

//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets (char s[], int arraySize)
{
    int i = 0, maxIndex = arraySize-1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE)
    {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when user is trying to insert a family name 
// that is already in the book.
void familyNameDuplicate (char familyName[])
{
    printf("\nAn entry for <%s> is already in the team!\nNew entry not entered.\n",familyName);
}

// Function to call when a player with this family name was found in the team.
void familyNameFound (char familyName[])
{
    printf("\nThe player with family name <%s> was found in the team.\n",familyName);
}

// Function to call when a player with this family name was not found in the team.
void familyNameNotFound (char familyName[])
{
    printf("\nThe player with family name <%s> is not in the team.\n", familyName);
}

// Function to call when a family name that is to be deleted
// was found in the team.
void familyNameDeleted (char familyName[])
{
    printf("\nDeleting player with family name <%s> from the team.\n", familyName);
}

// Function to call when printing an empty team.
void printTeamEmpty (void)
{
    printf("\nThe team is empty.\n");
}

// Function to call to print title when whole team being printed.
void printTeamTitle (void)
{
    printf("\nMy Team: \n");
}

// Function to call when no player in the team has lower or equal value to the given value
void printNoPlayersWithLowerValue(int value)
{
    printf("\nNo player(s) in the team is worth less than or equal to <%d>.\n", value);
}

//**********************************************************************
// Add your functions below this line.

void insert(struct node** head, char *firstName, char *familyName, char pos, int value){

    struct node* name = *head;
    while (name != NULL){
        if (strcmp(name->familyName, familyName) == 0){
            familyNameDuplicate(familyName);
            return;
        }
        name = name->next;
    }

    if (pos == 'G'){
        struct node* newNode;
        newNode = (struct node*) malloc(sizeof(struct node));
    
        newNode->value = value;
        strcpy(newNode->firstName, firstName);
        strcpy(newNode->familyName, familyName);
        newNode->pos = pos;
    
        newNode->next = *head;
    
        *head = newNode;
    }

    else if (pos == 'S'){
        struct node* newNode = (struct node*) malloc(sizeof(struct node));
        newNode->value = value;
        strcpy(newNode->firstName, firstName);
        strcpy(newNode->familyName, familyName);
        newNode->pos = pos;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
            return;
        }

        struct node* curr = *head;

        while (curr->next != NULL){
            curr = curr->next;
        }

        curr->next = newNode;
    }

    else if (pos == 'D'){
        struct node* newNode = (struct node*) malloc(sizeof(struct node));
        newNode->value = value;
        strcpy(newNode->firstName, firstName);
        strcpy(newNode->familyName, familyName);
        newNode->pos = pos;

        struct node* curr = *head, *prev;
        //prev->next = NULL;

        if (*head == NULL){
            //newNode->value = value;
            newNode->next = NULL;
            *head = newNode;
            return;
        }
        else if (curr->next == NULL){
            newNode->next = NULL;
            curr->next = newNode;
            return;
        }

        if (curr->pos == 'G'){
            while(curr->pos != 'M' && curr->pos != 'S' && curr->pos != 'D' && curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            if (curr->pos == 'M' || curr->pos == 'S' || curr->pos == 'D'){
                newNode->next = curr;
                prev->next = newNode;
            }
            else {
                newNode->next = curr->next;
                curr->next = newNode; 
            }
            return;
        }

        while (curr->pos != 'M' && curr->next->value != 'M') {
            prev = curr;
            curr = curr->next;
        }

        if (curr->next == NULL){
            prev->next = newNode;
            newNode->next = curr;
            return;
        }

        if (curr->pos == 'M' && prev == NULL){
            newNode->next = curr->next;
            curr->next = newNode;
            return;
        }

        newNode->value = value;
        newNode->next = curr;
        prev->next = newNode;
    }

    else if (pos == 'M'){
        struct node* newNode = (struct node*) malloc(sizeof(struct node));
        newNode->value = value;
        strcpy(newNode->firstName,firstName);
        strcpy(newNode->familyName, familyName);
        newNode->pos = pos;

        struct node* curr = *head, *prev;
        //prev = NULL;

        if (*head == NULL){
            //newNode->value = value;
            newNode->next = NULL;
            *head = newNode;
            return;
        }
        else if (curr->next == NULL){
            newNode->next = NULL;
            curr->next = newNode;
            return;
        }

        if (curr->pos == 'G'){
            while(curr->pos != 'S' && curr->pos != 'M' && curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            if (curr->pos == 'M' || curr->pos == 'S'){
                newNode->next = curr;
                prev->next = newNode;
            }
            else {
                newNode->next = curr->next;
                curr->next = newNode; 
            }
            return;
        }

        while (curr->pos != 'S' && curr->next->value != 'S') {
            prev = curr;
            curr = curr->next;
        }

        if (curr->next == NULL){
            curr->next = newNode;
            newNode->next = curr;
            return;
        }

        if (curr->pos == 'S' && prev == NULL){
            newNode->next = curr->next;
            curr->next = newNode;
            return;
        }

        newNode->value = value;
        newNode->next = curr;
        prev->next = newNode;
    }
}

void delete(struct node** head, char *deleteNode){
    struct node* curr = *head, *prev;

    if (curr == NULL || *head == NULL){
        printTeamEmpty();
        return;
    }

    if (strcmp(curr->familyName, deleteNode) == 0) {
        *head = curr->next;
        free(curr);
        return;
    }

    while (curr != NULL) {
        if (strcmp(curr->familyName, deleteNode) == 0){
            familyNameDeleted(deleteNode);
            //printf("\nDeleting player with family name <%s> from the team.\n", deleteNode);
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    
    familyNameNotFound(deleteNode);
}

void searchName(nodet** head, char familyname[MAX_LENGTH]){
    struct node* curr = *head, *prev;


    if (*head == NULL){
        printTeamEmpty();
        return;
    }
    
    while(strcmp(curr->familyName, familyname) != 0 && curr->next != NULL){
        curr = curr->next;
    }

    if (strcmp(curr->familyName, familyname) == 0){
        familyNameFound(familyname);
        printf("\n%s\n%s\n%c\n%d\n", curr->familyName, curr->firstName, curr->pos, curr->value);
        return;
    }
    else if (strcmp(curr->familyName, familyname) != 0){
        familyNameNotFound(familyname);
    }
}

void searchValue(nodet** head, int value){
    struct node* curr = *head, *prev;
    int check = 0;

    if (*head == NULL || curr == NULL){
        printTeamEmpty();
        return;
    }

    while(curr != NULL){
        if (curr->value <= value){
            printf("\n%s\n%s\n%c\n%d\n", curr->familyName, curr->firstName, curr->pos, curr->value);
            printf("\n");
            check = 1;
        }
        curr = curr->next;
    }

    if (check == 0){
        printNoPlayersWithLowerValue(value);
    }
}

void print(nodet *head){
    nodet *curr = head;

    if (curr == NULL){
        printTeamEmpty();
        return;
    }

    printTeamTitle();

    while(curr != NULL){
        printf("%s %s %c %d -> ", curr->firstName, curr->familyName, curr->pos, curr->value);  //when write down curr.value it automatically changes to curr->value
        curr = curr->next;
    }
    printf("\n");
}

void quit(nodet** head){
    struct node* curr = *head;

    // while (curr != NULL){
    //     free(curr);
    //     curr = curr->next;
    // } 
    while (*head){
        *head = (*head)->next;
        free(curr);
        curr = *head;
    } 
}