#ifndef COMM_H
#define COMM_H
#include<QApplication>
#include<QtGui>
#include<QGraphicsItem>
#include<QGraphicsLineItem>
#include<QStyleOptionGraphicsItem>
#include<QGraphicsSceneMouseEvent>
#include<QMessageBox>
#include<QInputDialog>
#include<QGraphicsScene>
#include<QTranslator>
#include<QFontMetricsF>
#include<QFontMetrics>
#include<iostream>
#include<cstdio>

class RBTree;
class RBNode;
class RBLink;
class RBTreeDemoWindow;



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

const int sceneCenterPosX=500;
const int sceneCenterPosY=500;
const int sceneHeaderPosY=200;

#endif // COMM_H
