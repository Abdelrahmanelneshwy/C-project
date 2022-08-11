#include "SDB.h"
extern SimpleDB DB[10];
int index=0; // its index to allow pointer to hold the address of required element of data base
/*this function check if my database is full or not*/
Bool SDB_IsFull(void)
{
    int counter=0;
    for (int i=0 ; i<10 ; i++)
    {
        if(DB[i].valid == T)  // check each sample in database is full or not
        {
            counter++;    // count no. of used database entry
        }
    }
    if (counter == 10) // when no. of used database equal 10 means that our database is full
    {
        return T;
    }
    else     // if counter is not equal 10 thats mean their is still empty database
    {
        return F;
    }
}

u8 SDB_GetUsedSize(void)
{
    int counter=0;
    for (int i=0 ; i<10 ; i++)
    {
        if(DB[i].valid == T)
        {
            counter++; // count no. of used database entry
        }
    }
    return counter;
}


/*take given data and store then in database*/

Bool SDB_AddEntry(int id,int year,  int* subject,int* grades )
{
    SimpleDB *ptr;
    ptr =&DB[0]; // pointer to first address in data base
    for(int i=0 ; i<10; i++)
    {
        if((ptr+index)->valid == T) // check if data base is fill increase th index to move to next one untill reach empty one
        {
            index ++;
        }
    }
    // start storing data
        (ptr+index)->S_ID = id;
        (ptr+index)->S_year = year;
        for (int i=0; i<3 ; i++)
        {
            (ptr+index)->C_ID[i] = *(subject+i);
            (ptr+index)->C_G[i] = *(grades+i);
        }
        (ptr+index)->valid = T; // after add student valid assigned to be true
        index ++;
        return T;
}


void SDB_DeleteEntry(int id)
{
    for(int i=0 ; i<10 ; i++)
    {
        if(DB[i].S_ID==id) // search for required id to remove
        {
            DB[i].S_ID = 0;
            DB[i].S_year = 0;
            for (int k=0; k<3 ; k++)
            {
                DB[i].C_ID[k] = 0;
                DB[i].C_G[k] = 0;
            }
            if (i <= index)
            {
               index=i;
            }
            DB[i].valid=F; // after removing valid assigned to be false
        }
    }
}

Bool SDB_ReadEntry (int id, int* year,  int* subject,int* grades )
{
    for(int i=0 ; i<10 ; i++)
    {
        if(DB[i].valid==T) // check if data base element is full
        {

            if(DB[i].S_ID==id) // search for required id
            {
                // collecting data
                *year=DB[i].S_year;

                for(int k=0 ; k<3 ; k++)
                {
                    *(subject)=DB[i].C_ID[k];
                    *(grades) =DB[i].C_G[k];
                    subject++;
                    grades++;
                }
            }
            return T;
        }
        else
        {
            return F;
        }
    }
}



void SDB_GetIdList (int* Count, int* List)
{

    for(int i=0 ; i<10 ; i++)
    {
        if(DB[i].valid==T) // check if data base element is full
        {
            (*Count)++; // count the number of user
            *List=DB[i].S_ID; // collecting IDs in list
             List++; // increase the pointer of list
        }
    }
}



Bool SDB_IsIdExist(int id )
{
    int flag=0;
    for(int i=0 ; i<10 ; i++)
    {
        if(DB[i].S_ID==id) // if id exist raise flag
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        return T;
    }
    else
    {
        return F;
    }
}

void show_Database ()
{
    for(int i=0 ; i<10 ; i++ )
    {
        if (DB[i].valid==1)
        { // printing data of student
            printf("----------------\n");
            printf("user %d\n",i+1);
            printf("ID %d\n",DB[i].S_ID);
            printf("year %d\n",DB[i].S_year);
            for(int k=0 ; k<3 ; k++)
            {
                printf("c_ID %d\n",DB[i].C_ID[k]);
                printf("C_G %d\n",DB[i].C_G[k]);
            }
        }
    }
}

void Data_Store()
{
    // store data function
    int ID,year,subject[3],grades[3],grade,flag=1;
    if(SDB_IsFull==1)
    {
        printf("database is full \n");
    }
    else
    {
        printf("Enter student ID: ");
        scanf("%d",&ID);
        printf("Enter student year: "); //when i take student id before year ... year over write the id
        scanf("%d",&year);
        if(SDB_IsIdExist(ID)==1)
        {
            printf("this ID exist plz enter different one \n");
        }
        else
        {
            for(int i=0 ; i<3; i++)
            {
                printf("Enter subject ID: ");
                scanf("%d",&subject[i]);
                printf("Enter subject grade in precentage: ");
                scanf("%d",&grades[i]);
            }
        }
        if  (SDB_AddEntry(ID,year,&subject,&grades)==1)
        {
            printf("the student is added successfully \n");
        }
    }
}

void Enter_Screen ()
{
    printf("1->no of student\n");
    printf("2->ADD student\n");
    printf("3->Remove student\n");
    printf("4->see detail\n");
    printf("5->see data sheet\n");
    printf("6->find student\n");
    printf("7->show database\n");
}
