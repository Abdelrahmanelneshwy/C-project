#include "SDB.h"
SimpleDB DB[10];  // creating an array from my struct SimpleDB

int main()
{
    int index_1=0;   // variable to hold output data from function
    int arr[10]= {0,0,0,0,0,0,0,0,0,0},arr_1[10]= {0,0,0,0,0,0,0,0,0,0}; // array to hold output data from function
    int ID,op;

    while(1)
    {
        Enter_Screen (); // function to show up welcome screen
        printf("Enter your operation -> ");
        scanf("%d",&op);
        switch(op)
        {


        case 1 :
            printf("the the no of student is %d\n",SDB_GetUsedSize()); // in this case we get number of student enter in our database
            break;


        case 2 :
           // fuction to store data enter by user
            Data_Store();
            break;



        case 3 :
            // request id to of student want to remove
            printf("Enter student ID: ");
            scanf(" %d",&ID);
            SDB_DeleteEntry(ID); // remove function
            printf("student Removed \n");
            break;



        case 4 :
            printf("Enter student ID: "); // request id to of student want to find its score
            scanf(" %d",&ID);
            SDB_ReadEntry (ID, &index_1, &arr,&arr_1); // read function used to extract data of student
            /*printing out student data*/
            printf("year of student is : %d \n",index_1);
            for(int i=0 ; i<3 ; i++)
            {
                printf("the subject ID is : %d \n",arr[i]);
                printf("the garde of subject = %d \n",arr_1[i]);
            }
            break;



        case 5 :
            SDB_GetIdList (&index_1,&arr); // pass an array & variable to the function to get a list of IDs of student & its count
            /*printing out data of list */
            printf("no. of enteries is : %d \n",index_1);
            printf("this list IDs is : \n");
            for(int i=0; i<10; i++)
            {
                if(arr[i] != 0)
                {
                    printf("ID of student no.%d->%d \n",i+1,arr[i]);
                }
            }

            break;



        case 6 :
            /*check if this id exist in data base or not*/
            printf("Enter student ID: ");
            scanf("%d",&ID);
            if(SDB_IsIdExist(ID)==1)
            {
                printf("this ID exist \n");
            }
            else
            {
                printf("this ID not exist \n");
            }
            break;

        case 7 :
            show_Database (); // function to show up student data
            break;

        default:
            printf("invalid operation \n");
            break;
        }
        printf("******************************\n");
    }
}


