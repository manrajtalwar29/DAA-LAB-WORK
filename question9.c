// Library Book Management • Store the book ID, title, author, total copies, and available copies using structures. • Create a menu-driven program to add and search for books, issue and return books, and display all books currently unavailable.
#include <stdio.h>
struct Book
{
    int id;
    char title[30];
    char author[30];
    int total;
    int available;
};
int main()
{
    struct Book b[50];
    int n = 0, choice, id, i;
    do
    {
        printf("\n1.Add Book");
        printf("\n2.Search Book");
        printf("\n3.Issue Book");
        printf("\n4.Return Book");
        printf("\n5.Unavailable Books");
        printf("\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Book ID: ");
                scanf("%d", &b[n].id);
                printf("Title: ");
                scanf("%s", b[n].title);
                printf("Author: ");
                scanf("%s", b[n].author);
                printf("Total Copies: ");
                scanf("%d", &b[n].total);
                b[n].available = b[n].total;
                n++;
                break;
            case 2:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                for(i = 0; i < n; i++)
                {
                    if(b[i].id == id)
                    {
                        printf("%s by %s\n", b[i].title, b[i].author);
                    }
                }
                break;
            case 3:
                printf("Book ID: ");
                scanf("%d", &id);
                for(i = 0; i < n; i++)
                {
                    if(b[i].id == id && b[i].available > 0)
                    {
                        b[i].available--;
                        printf("Book Issued\n");
                    }
                }
                break;
            case 4:
                printf("Book ID: ");
                scanf("%d", &id);
                for(i = 0; i < n; i++)
                {
                    if(b[i].id == id && b[i].available < b[i].total)
                    {
                        b[i].available++;
                        printf("Book Returned\n");
                    }
                }
                break;
            case 5:
                printf("\nUnavailable Books:\n");
                for(i = 0; i < n; i++)
                {
                    if(b[i].available == 0)
                        printf("%s\n", b[i].title);
                }
                break;
        }
    } while(choice != 6);
    return 0;
}
