#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD_TYPES.h"

 typedef enum
 {
     F,
     T
 }Bool;

typedef struct
{
    Bool valid; // way to ensure that data base is full or not
    int S_ID;
    int S_year;
    int C_ID[3];
    int C_G[3];
}SimpleDB;

Bool SDB_IsFull(void);

u8 SDB_GetUsedSize(void);

Bool SDB_AddEntry(int id,int year ,  int* subject ,int* grades );

void SDB_DeleteEntry(int id);

Bool SDB_ReadEntry (int id, int* year ,  int* subject ,int* grades );

void SDB_GetIdList (int* Count , int* List);

Bool SDB_IsIdExist(int id );

void show_Database ();

void Data_Store();

void Enter_Screen ();
#endif // SDB_H_INCLUDED
