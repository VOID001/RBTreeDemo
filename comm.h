#ifndef COMM_H
#define COMM_H
#include<QtGui>
#include<QGraphicsItem>
#include<QGraphicsLineItem>
#include<QInputDialog>
#include<iostream>
#include<cstdio>


//Define enumeration type Status
//Meaning of each State
/*
 OK: return Normally
 OF overflow issue occured
 NOTFUND return this when a node cannot be found in tree
 TREECONSTRUCT_ERR the tree must be built wrong
 NODE_ALREADY_EXIST the key has already be used before
  */
typedef enum{OK,OF,NOTFOUND,TREECONSTRUCT_ERR,NODE_ALREADY_EXIST} Status;
typedef enum{RED,BLACK} NodeColor;

#endif // COMM_H
