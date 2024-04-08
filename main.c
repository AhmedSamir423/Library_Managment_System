#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *m[12]= {"January","February","March","April",
                    "May","June","July","August","September",
                    "October","November","December"
                   };
typedef struct
{
    int month;
    int year;
} date;

typedef struct
{
    char isbn[20];
    char title[50];
    char author[50];
    int quantity;
    float price;
    date published;

} book;

book x[100]; //global array of structs
int n=0; //no. of books

int isvalid(char s[])
{
    int i,l;
    l=strlen(s);
    for(i=0; i<l; i++)
    {
        if(isdigit(s[i])==0)
        {
            return 0;
        }

    }
        return 1;

}
int Login()
{
    int i,j =0,flag ;
    char  lines[200][200],username[200],password[200];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    FILE* fp = fopen("credentials.txt", "r");
    if (fp == NULL)
    {
        printf("Error loading the file:");
        return 0;
    }
    while(!feof(fp))
    {
        fgets(lines[j],sizeof(lines[j]),fp);
        j++;
    }
    for( i=0; i<j; i+=2)
    {
        if(strncmp(username,lines[i],strlen(lines[i])-1)==0 && strncmp(password,lines[i+1],strlen(lines[i+1])-1)==0)
        {
            printf("Login successful! \n");
            return 1;
        }
        else
        {
            flag = 0 ;
        }
    }
    if(flag==0)
        printf("Login Failed\n");
    return 0;
}
int LOAD()
{
    char line[200][200];

    FILE *f1;
    f1= fopen("books.txt","r");

    int j;
    if(f1==NULL)
    {
        printf("error");
        exit(1);
    }

    while(!feof(f1))
    {
        fgets(line[n],200,f1);
        n++;
    }
    rewind(f1);
    n--;
    for(j=0; j<n; j++)
    {
        fscanf(f1,"%[^,],%[^,],%[^,],%d,%f,%d-%d\n", &x[j].isbn,&x[j].title,&x[j].author,&x[j].quantity,&x[j].price,&x[j].published.month,&x[j].published.year);

    }

    fclose(f1);
}
void Search()
{
    int l,i,flag=0;
    char id[20];
again:
    printf("enter book ISBN\n");
    scanf("%s",id);
    l=strlen(id);
    if(l!=13)//isbn validation
    {
        printf("invalid\n");
        goto again;
    }
    for(i=0; i<13; i++)
    {
        if(isdigit(id[i])==0)
        {
            printf("invalid\n");
            goto again;
        }
    }

    for(i=0; i<n; i++)
    {
        if(strcmp(x[i].isbn,id)==0)

        {
            flag=1;
            printf("Found\n");
            printf("ISBN:%s\n",x[i].isbn);
            printf("Title:%s\n",x[i].title);
            printf("Author:%s\n",x[i].author);
            printf("Quantity:%d\n",x[i].quantity);
            printf("Price:$%0.2f\n",x[i].price);
            printf("Date:%s %d\n\n",m[x[i].published.month-1],x[i].published.year);
        }


    }
    if(flag==0)
        printf("Book not found");

}
void Advanced_Search()
{
    int i,flag=0;
    char key[20];

    printf("enter title\n");
    scanf("%s",key);

    for(i=0; i<n; i++)
    {
        if(strstr(x[i].title,key))
        {
            flag=1;

            printf("ISBN:%s\n",x[i].isbn);
            printf("Title:%s\n",x[i].title);
            printf("Author:%s\n",x[i].author);
            printf("Quantity:%d\n",x[i].quantity);
            printf("Price:$%0.2f\n",x[i].price);
            printf("Date:%s %d\n\n",m[x[i].published.month-1],x[i].published.year);
        }
    }
    if(flag==0)
    {
        printf("book not found");
    }
}
void Add_Book()
{
    int g,l,i;
    char id[20],month[10],year[10];
again:
    printf("Enter the Book ISBN:");
    scanf("%s",x[n].isbn);
    strcpy(id,x[n].isbn);
    l=strlen(id);
    if(l!=13)//isbn validation
    {
        printf("invalid\n");
        goto again;
    }
    for(i=0; i<12; i++)
    {
        if(isdigit(id[i])==0)
        {
            printf("invalid\n");
            goto again;
        }
    }
    printf("Enter the Book Title:");
    getchar();
    gets(x[n].title);
    printf("Enter the Book Author:");
    gets(x[n].author);
    do
    {
    printf("Enter the Book quantity:");
    scanf("%d",&x[n].quantity);
    }while(x[n].quantity <0);
    do{
        printf("Enter the Book Price:");
    scanf("%f",&x[n].price);

    }while(x[n].price < 0);

a:
    do//month and year validation
    {
        printf("Enter the Book month of publishment:");
        scanf("%s",month);
    }
    while(!isvalid(month));
     g=atoi(month);
            if(g>12 || g<1)
            {
                printf("1");
                goto a;
            }
    x[n].published.month=atoi(month);

b:
    do
    {
        printf("Enter the Book year of publishment:");
        scanf("%s",year);
    }
    while(!isvalid(year));
g=atoi(year);
            if(g>2023 || g<1000 )
            {
                goto b;
            }
            x[i].published.year=atoi(year);
    x[n].published.year=atoi(year);

    n++;

}
void Delete_book()
{
    int l,k,i,j,flag=0;
    char id[20];
again:
    printf("enter the ISBN:");
    scanf("%s",id);
    l=strlen(id);
    if(l!=13)
    {
        printf("invalid ISBN\n");
        goto again;
    }
    for(i=0; i<13; i++)
    {
        if(isdigit(id[i])==0)
        {
            printf("invalid Format\n");
            goto again;
        }
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(id,x[i].isbn)==0)
        {

            flag=1;
            for(j=i; j<n; j++)
            {
                x[j]=x[j+1];
            }
        }
    }

    if(flag==1)
    {
        n--;
    }
    else
    {
        printf("book not found\n");
    }

}
void MODIFY()
{
    char id[20],new_title[50],new_name[50],new_month[10],new_year[10];
    int g,l,i,z=0,new_quantity,flag=0;
    float new_price;
again:
    printf("enter the ISBN:");
    scanf("%s",id);
    l=strlen(id);
    if(l!=13)
    {
        printf("invalid ISBN\n");
        goto again;
    }
    for(i=0; i<13; i++)
    {
        if(isdigit(id[i])==0)
        {
            printf("invalid Format\n");
            goto again;
        }
    }

    for(i=0; i<n; i++)
    {
        if(strcmp(id,x[i].isbn)==0)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("book not found\n");

    }
    while(z!=7&&z<8&&flag==1)
    {
        printf("what would you like to change?\n1-title\n2-author name\n3-quantity\n4-price\n5-month published\n6-year published\n7-nothing\n");
        scanf("%d",&z);
        if(z==1)
        {
            printf("enter new title:\n");
            getchar();
            gets(new_title);
            strcpy(x[i].title,new_title);
        }
        else if(z==2)
        {
            printf("enter new author name:\n");
            getchar();
            gets(new_name);
            strcpy(x[i].author,new_name);
        }
        else if(z==3)
        {
            printf("enter new quantity:\n");
            scanf("%d",&new_quantity);
            x[i].quantity=new_quantity;
        }
        else if(z==4)
        {
            printf("enter new price:\n");
            scanf("%f",&new_price);
            x[i].price=new_price;
        }
        else if(z==5)
        {
a:
            do//month and year validation
            {
                printf("Enter the new month of publishment:");
                scanf("%s",new_month);
            }
            while(!isvalid(new_month));
            g=atoi(new_month);
            if(g>12 || g<1)
            {
                printf("1");
                goto a;
            }
            x[i].published.month=atoi(new_month);
        }

        else if(z==6)
        {
            b:
            do
            {
                printf("Enter the Book year of publishment:");
                scanf("%s",new_year);
            }
            while(!isvalid(new_year));
            g=atoi(new_year);
            if(g>2023 || g<1000 )
            {
                goto b;
            }
            x[i].published.year=atoi(new_year);
        }
    }

}
void sortByTitle()
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(x[j].title, x[j + 1].title) > 0)
            {
                book temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}
void sortByPrice()
{
    int i,j;

    for ( i = 0; i < n - 1; i++)
    {
        for ( j = 0; j < n - i - 1; j++)
        {
            if (x[j].price > x[j + 1].price)
            {
                book temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}
void sortByDate()
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (x[j].published.year < x[j + 1].published.year ||
                    (x[j].published.year == x[j + 1].published.year && x[j].published.month < x[j + 1].published.month))
            {

                book temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;

            }
        }
    }
}
void print()
{

    printf("Sort books by:\n");
    printf("1. Title\n");
    printf("2. Price\n");
    printf("3. Date of publication\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        sortByTitle();
    }
    else if (choice == 2)
    {
        sortByPrice();
    }
    else if (choice == 3)
    {
        sortByDate();
    }
    else
    {
        printf("Invalid choice\n");
    }
    if (choice==1 || choice==2 || choice==3)
    {
        for (int i = 0; i < n; i++)
    {
        printf("ISBN:%s\n",x[i].isbn);
        printf("Title:%s\n",x[i].title);
        printf("Author:%s\n",x[i].author);
        printf("Quantity:%d\n",x[i].quantity);
        printf("Price:$%0.2f\n",x[i].price);
        printf("Date:%s %d\n\n",m[x[i].published.month-1],x[i].published.year);
    }
    }

}
void SAVE()
{
    FILE *f1;
    int i;
    f1=fopen("books.txt","w");


    for(i=0; i<n; i++)
    {
        fprintf(f1,"%s,%s,%s,%d,%f,%d-%d\n",x[i].isbn,x[i].title,x[i].author,x[i].quantity,x[i].price,x[i].published.month,x[i].published.year);
    }
    fclose(f1);

}
int Menu()
{
    int choice1,choice2,choice3;
    printf("Hello , Welcome to Our Library!\n");
again:
    printf("please choose an option:\n");
    printf("PS: Type-in the number corresponding to the option you want\n");
    printf("1.Login: \n");
    printf("2.Quit: \n");
    scanf("%d",&choice1);
    if(choice1 ==1)
    {
        if(Login())
        {
            LOAD(x);
start:
            printf("Please choose an option from the following:\n");
            printf("1.Add\n");
            printf("2.Delete\n");
            printf("3.Modify\n");
            printf("4.Search\n");
            printf("5.Advanced Search\n");
            printf("6.Print\n");
            printf("7.Save\n");
            printf("8.Quit\n");
            scanf("%d",&choice2);
            while(choice2 <9 && choice2>0)
            {
                switch(choice2)
                {
                case 1 :
                    Add_Book();
                    goto start;
                    break;
                case 2:
                    Delete_book();
                    goto start;
                    break;
                case 3:
                    MODIFY();
                    goto start;
                    break;
                case 4:
                    Search();
                    goto start;
                    break;
                case 5:
                    Advanced_Search();
                    goto start;
                    break;
                case 6:
                    print();
                    goto start;
                    break;
                case 7:
                    printf("\n1.save and quit\n2.save and return to menu\n");
                    scanf("%d",&choice3);
                    if(choice3==1)
                    {
                        SAVE();
                        exit(1);
                    }
                    else
                    {
                        SAVE();
                        goto start;
                    }

                    break;
                case 8:
                    Quit();
                    exit(1);
                    break;
                default:
                    printf("Invalid Response\n");
                    goto start;
                    break;
                }
            }
        }
        else
        {
            goto again;
        }

    }
    else if(choice1 == 2)
    {
        Quit();

    }
    else
    {
        printf("choice Invalid \n");
    }

}
void Quit()
{
    int response;
    printf("WARNING:quitting will discard all of your changes\n");
choose:
    printf("Press 1 if you want to quit \nPress 2 if you want to return to the menu");
    scanf("%d",&response);
    if(response==1)
    {
        printf("Thanks for using the program!");
        return 0;
    }
    else if(response==2)
    {
        Menu();
    }
    else
    {
        printf("Invalid Choice\n");
        goto choose;

    }
}

int main()
{
    Menu();
    return 0;
}

