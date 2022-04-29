#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact
{
    char *name;
    char *family;
    char *number;

} contact;

contact phnbook[10] = {{"Oleg", "Olegov", "89131234501"}, {"Vladislav", "Vladislavov", "89131234502"},
    {"Dmitriy", "Dmitriev", "89131234503"}, {"Juriy", "Juriev", "89131234504"},
    {"Semen", "Semenov", "89131234505"}, {"Viktoria", "Viktorova", "89131234506"},
    {"Maria", "Marieva", "89131234507"}, {"Ksenia", "Ksenieva", "89131234508"},
    {"Julia", "Julieva", "89131234509"}, {"Natalia", "Natalieva", "89131234510"}
};

int bookcapacity = sizeof(phnbook)/sizeof(contact);

unsigned int task;

int main()
{
    while(task!=5)
    {
        printf("\n1. View full phonebook \n2. Add contact \n3. Delete contact \n4. Find contact \n5. Exit\nEnter task: ");
        scanf("%d", &task);
        printf("\n");
        switch (task)
        {
        case 1:
        {
            for (int i = 0; i < bookcapacity; i++)
            {
                if (phnbook[i].number != "0")
                {
                    printf("Contact number: %d\nName: %s\nFamily: %s\nPhone number: %s \n", i, phnbook[i].name, phnbook[i].family, phnbook[i].number);
                    printf("\n");
                }
            }
            break;
        }
        case 2:
        {
            char emptyFlag = 0;
            int emptypos = 0;
            for (int i = 0; i < bookcapacity; i++) // ищем пустую запись
            {
                if (phnbook[i].number == "0")
                {
                    emptyFlag = 1;
                    emptypos = i;
                }
            }
            if (emptyFlag != 0)
            {
                char name[20];
                printf("Enter name: ");
                scanf("%20s", name);
                phnbook[emptypos].name = name;
                printf("\n");
                char family[20];
                printf("Enter family: ");
                scanf("%20s", family);
                phnbook[emptypos].family = family;
                printf("\n");
                char number[20];
                printf("Enter phone number: ");
                scanf("%20s", number);
                phnbook[emptypos].number = number;
                printf("\n");
            }
            else printf("No empty entries. Delete any contact before new adding.\n");
            break;
        }
        case 3:
        {
            int position;
            printf("Enter contact position in phone book for delete: ");
            scanf("%d", &position);
            printf("\n");
            printf("Contact %s %s %s deleted from phonebook.\n", phnbook[position].name, phnbook[position].family, phnbook[position].number);
            phnbook[position].name = "0";
            phnbook[position].family = "0";
            phnbook[position].number = "0";
            break;
        }
        case 4:
        {
            char number[20];
            char foundFlag = 0;
            printf("Enter phone number for finding contact: ");
            scanf("%s", number);
            printf("\n");
            for (int i = 0; i < bookcapacity; i++)
            {
                printf("\n");
                if (strcmp(phnbook[i].number, number) == 0)
                {
                    foundFlag = 1;
                    printf("Contact number: %d\nName: %s\nFamily: %s\nPhone number: %s \n", i, phnbook[i].name, phnbook[i].family, phnbook[i].number);
                    printf("\n");
                }
            }
            if (!foundFlag)
            {
                printf("Contact not found");
                printf("\n");
            }
            break;
        }
        case 5:
            break;
        default:
        {
            printf("Not correct task number, please reenter\n");
        }
        }
    }
    return 0;
}
