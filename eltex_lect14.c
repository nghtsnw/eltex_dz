#include <stdio.h>
#include <stdlib.h>

typedef struct contact
{
    char *name;
    char *family;
    unsigned long long int number;
} contact;

contact phnbook[10] = {{"Oleg", "Olegov", 89131234501}, {"Vladislav", "Vladislavov", 89131234502},
    {"Dmitriy", "Dmitriev", 89131234503}, {"Juriy", "Juriev", 89131234504},
    {"Semen", "Semenov", 89131234505}, {"Viktoria", "Viktorova", 89131234506},
    {"Maria", "Marieva", 89131234507}, {"Ksenia", "Ksenieva", 89131234508},
    {"Julia", "Julieva", 89131234509}, {"Natalia", "Natalieva", 89131234510}
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
                if (phnbook[i].number != 0)
                {
                    printf("Contact number: %d\nName: %s\nFamily: %s\nPhone number: %llu \n", i, phnbook[i].name, phnbook[i].family, phnbook[i].number);
                    printf("\n");
                }
            }
            break;
        }
        case 2:
        {
            char emptyflag = 0;
            int emptypos = 0;
            for (int i = 0; i < bookcapacity; i++) // ищем пустую запись
            {
                if (phnbook[i].number == 0)
                {
                    emptyflag = 1;
                    emptypos = i;
                }
            }
            if (emptyflag != 0)
            {
                printf("Enter name: ");
                scanf("%s", phnbook[emptypos].name);
                printf("\n");
                printf("Enter family: ");
                scanf("%s", phnbook[emptypos].family);
                printf("\n");
                printf("Enter phone number: ");
                scanf("%llu", phnbook[emptypos].number);
                printf("\n");
            }
            else printf("No empty entries. Delete any contact before new adding.\n");
            break;
        }
        case 3:
        {
            int position;
            printf("Enter contact position in phone book: ");
            scanf("%d", &position);
            printf("\n");
            printf("Contact %s %s %llu deleted from phonebook.\n", phnbook[position].name, phnbook[position].family, phnbook[position].number);
            phnbook[position].name = "0";
            phnbook[position].family = "0";
            phnbook[position].number = 0;
            break;
        }
        case 4:
        {
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
