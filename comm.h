#ifndef COMM_H
#define COMM_H
#include<QtGui>


//Define enumeration type Status
//Meaning of each State
/*
 OK: return Normally
 OF overflow issue occured
 NOTFUND return this when a node cannot be found in tree
 TREECONSTRUCT_ERR the tree must be built wrong
  */
typedef enum{OK,OF,NOTFOUND,TREECONSTRUCT_ERR} Status;

#endif // COMM_H
