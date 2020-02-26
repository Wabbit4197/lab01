#include "person.h"
#include <stdio.h>
#include <string.h>

LIST *head = NULL, *tail = NULL;

void inputPersonalData(PERSON *person)
{
    // TODO implement the function
    // or check out part 9 of the c tutorial ;)
    scanf("%s",person->name);
    scanf("%d",&person->age);
    scanf("%f",&person->height);


    char date_string[15];
    scanf("%s",date_string);
    int string_size = strlen(date_string);
	char delim[] = "/";
    DATE *date = (DATE *) malloc(sizeof(DATE));


	char *ptr = strtok(date_string, delim);
    date->month = atoi(ptr);
    ptr = strtok(NULL, delim);
    date->day = atoi(ptr);
    ptr = strtok(NULL, delim);
    date->year = atoi(ptr);

    person->bday = *date;

}

void addPersonalDataToDatabase(PERSON *person)
{
    // TODO Implement the function
    add(&head,&tail,person);
    return;
}

void displayDatabase()
{
    LIST *temp= head;
    if(temp==NULL){
        printf("The Database is empty");
    }
    while(temp!=NULL){
        PERSON *person = temp->data;
        displayPerson(person);
        temp=temp->next;
    }
}

void displayPerson(PERSON *person)
{
    // TODO Implement the function
    // hmmmm seems familiar....
    // Zach : age 22, height 5.8, birthday 2/20/1989
    DATE *date = &(person->bday);
    printf("%s :age %d, height %.2f , birthday %d/%d/%d\n",person->name,person->age,person->height,date->month,date->day,date->year);

}

PERSON *findPersonInDatabase(char *name)
{
    // TODO Implement the function

    LIST *temp= head;
    while(temp!=NULL){
        PERSON *person = temp->data;
        if (strcmp(person->name,name) == 0){
            return person;
        }
        temp=temp->next;
    }
    return NULL; // if not found
}

void removePersonFromDatabase(char *name)
{
    // TODO Implement the function
    LIST *temp= head;
    while(temp!=NULL){
        PERSON *person = temp->data;
        if (strcmp(person->name,name) == 0){
            delete(&head,&tail,person);
            break;
        }
        temp=temp->next;
    }
    
}

void clearDatabase()
{
    clearIteratively(&head,&tail);
}
