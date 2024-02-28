#include "StackArray.h"
int x=0;
int y=0;
int oreo=0;
int xprev=0;
int yprev=0;
int flood[16][16]={{14, 13, 12, 11, 10, 9, 8, 7, 7, 8, 9, 10, 11, 12, 13, 14},
    {13, 12, 11, 10, 9, 8, 7, 6, 6, 7, 8, 9, 10, 11, 12, 13},
    {12, 11, 10, 9, 8, 7, 6, 5, 5, 6, 7, 8, 9, 10, 11, 12},
    {11, 10, 9, 8, 7, 6, 5, 4, 4, 5, 6, 7, 8, 9, 10, 11},
    {10, 9, 8, 7, 6, 5, 4, 3, 3, 4, 5, 6, 7, 8, 9, 10},
    {9, 8, 7, 6, 5, 4, 3, 2, 2, 3, 4, 5, 6, 7, 8, 9},
    {8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7, 8},
    {7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, 7},
    {7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, 7},
    {8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7, 8},
    {9, 8, 7, 6, 5, 4, 3, 2, 2, 3, 4, 5, 6, 7, 8, 9},
    {10, 9, 8, 7, 6, 5, 4, 3, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 10, 9, 8, 7, 6, 5, 4, 4, 5, 6, 7, 8, 9, 10, 11},
    {12, 11, 10, 9, 8, 7, 6, 5, 5, 6, 7, 8, 9, 10, 11, 12},
    {13, 12, 11, 10, 9, 8, 7, 6, 6, 7, 8, 9, 10, 11, 12, 13},
    {14, 13, 12, 11, 10, 9, 8, 7, 7, 8, 9, 10, 11, 12, 13, 14}};
  
//setting up cell array
int cells[16][16]={
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


void setup() {
    Serial.begin(19200);
}
void showFlood(){
  for (int a=0;a<16;a++){
    for (int b=0;b<16;b++){
      String ada=String(flood[b][a]);
      setText(a,b,ada);
  }
  }
  }
void update_cells(int x,int y,int oreo,bool L,bool R,bool F){
  if(L && R && F) {
    if(oreo==0) {
      cells[y][x]=13;
        }
    else if(oreo==1) {
      cells[y][x]=12;
    }
    else if (oreo==2){
      cells[y][x]=11;
    }
    else if (oreo==3){
      cells[y][x]=14;
    }
  }

  else if(L && R) {
    if(oreo==0) {
      cells[y][x]=9;
        }
    else if(oreo==1) {
      cells[y][x]=10;
    }
    else if (oreo==2){
      cells[y][x]=9;
    }
    else if (oreo==3){
      cells[y][x]=10;
    }
  }

  else if(L && F) {
    if(oreo==0) {
      cells[y][x]=8;
        }
    else if(oreo==1) {
      cells[y][x]=7;
    }
    else if (oreo==2){
      cells[y][x]=6;
    }
    else if (oreo==3){
      cells[y][x]=5;
    }
  }

    else if(F && R) {
    if(oreo==0) {
      cells[y][x]=7;
        }
    else if(oreo==1) {
      cells[y][x]=6;
    }
    else if (oreo==2){
      cells[y][x]=5;
    }
    else if (oreo==3){
      cells[y][x]=8;
    }
  }
    
  else if(F) {
    if(oreo==0) {
      cells[y][x]=2;
        }
    else if(oreo==1) {
      cells[y][x]=3;
    }
    else if (oreo==2){
      cells[y][x]=4;
    }
    else if (oreo==3){
      cells[y][x]=1;
    }
  }

  else if(L) {
    if(oreo==0) {
      cells[y][x]=1;
        }
    else if(oreo==1) {
      cells[y][x]=2;
    }
    else if (oreo==2){
      cells[y][x]=3;
    }
    else if (oreo==3){
      cells[y][x]=4;
    }
  }

  else if (R) {
    if(oreo==0) {
      cells[y][x]=3;
        }
    else if(oreo==1) {
      cells[y][x]=4;
    }
    else if (oreo==2){
      cells[y][x]=1;
    }
    else if (oreo==3){
      cells[y][x]=2;
    }
  }
}
//check if the cell is accessible by checking cells arary
bool isAccessible(int x,int y,int x1,int y1){
  int d=cells[y][x];
  if (x1<0||y1<0){
    return false;
  }
  if(x==x1){
    if (y>y1){
      if (d==4||d==5||d==6||d==10||d==11||d==12||d==14){
        return false;
      }
      return true;
    }
    else{
      if(d==2||d==7||d==8||d==10||d==12||d==13||d==14){
        return false;
      }
      return true;
    }
  }
  //else if
  else{
    if(x>x1){
      if(d==1||d==5||d==8||d==9||d==11||d==13||d==14){
        return false;
      }
      return true;
    }
    else{
      if (d==3||d==6||d==7||d==9||d==11||d==12||d==13){
        return false;
      }
      return true;
    }

  }
}
//get coordinates of neighbour cells
void getSurrounds(int x,int y,int &x0,int &y0,int &x1,int &y1,int &x2,int &y2,int &x3,int &y3){
  x0=x;
  y0=y+1;
  x1=x+1;
  y1=y;
  x2=x;
  y2=y-1;
  x3=x-1;
  y3=y;











  
  //check here 
  //x1=-1 or x1-=1


  
  if(x1>=16){
    x1=-1;
  }
  if(y0>=16){
    y0=-1;
  }
}
//check if the current cell has min value amoung all accessible neighbours
bool is_consistant(int x,int y){
  int x0,y0,x1,y1,x2,y2,x3,y3;
  getSurrounds(x,y,x0,y0,x1,y1,x2,y2,x3,y3);
  int val=flood[y][x];
  int minvalue[4] ={-1,-1,-1,-1};

  if (x0>=0 && y0>=0){
    if (isAccessible(x,y,x0,y0)){
      minvalue[0]=flood[y0][x0];
    }
  }
  if (x1>=0 && y1>=0){
    if (isAccessible(x,y,x1,y1)){
      minvalue[1]=flood[y1][x1];
    }
  }
  if (x2>=0 && y2>=0){
    if (isAccessible(x,y,x2,y2)){
      minvalue[2]=flood[y2][x2];
    }
  }
  if (x3>=0 && y3>=0){
    if (isAccessible(x,y,x3,y3)){
      minvalue[3]=flood[y3][x3];
    }
  }
  int mincount=0;
  for(int i=0;i<4;i++){
    if (minvalue[i]==-1){
      continue;
    }
    else if (minvalue[i]==val+1){
      continue;
    }
    else if (minvalue[i]==val-1){
      mincount+=1;
      continue;
    }
  }
  if (mincount>0)
    return true;
  else
    return false;
}
//updates the value of flood array to make the cell consistent(not having minimum value than neighbours)
void make_consistent(int x,int y){
  int x0,y0,x1,y1,x2,y2,x3,y3;
  getSurrounds(x,y,x0,y0,x1,y1,x2,y2,x3,y3);
//  int val=flood[y][x];
  int minvalue[4] ={-1,-1,-1,-1};

  if (x0>=0 && y0>=0){
    if (isAccessible(x,y,x0,y0)){
      minvalue[0]=flood[y0][x0];
    }
  }
  if (x1>=0 && y1>=0){
    if (isAccessible(x,y,x1,y1)){
      minvalue[1]=flood[y1][x1];
    }
  }
  if (x2>=0 && y2>=0){
    if (isAccessible(x,y,x2,y2)){
      minvalue[2]=flood[y2][x2];
    }
  }
  if (x3>=0 && y3>=0){
    if (isAccessible(x,y,x3,y3)){
      minvalue[3]=flood[y3][x3];
    }
  }
  int minv=1000;
  for(int i=0;i<4;i++){
    if (minvalue[i]==-1) {
      minvalue[i]=1000;
    }
    if(minv>minvalue[i]){
      minv=minvalue[i];
  }}

  flood[y][x]=minv+1;
}
//makes all cells consistant 
void flood_fill_update(int x,int y,int xprev,int yprev){
  int cou=0;
  if(!is_consistant(x,y)) {
    flood[y][x]=(flood[yprev][xprev]+1);
  }
  StackArray <int> mstack;
  mstack.push(x);
  mstack.push(y);
  cou+=2;
  int x0,y0,x1,y1,x2,y2,x3,y3;
  getSurrounds(x,y,x0,y0,x1,y1,x2,y2,x3,y3);
  if(x0>=0 && y0>=0 && isAccessible(x,y,x0,y0)) {
    mstack.push(x0);
    mstack.push(y0);
    cou+=2;
  }
  if(x1>=0 && y1>=0 && isAccessible(x,y,x1,y1)) {
    mstack.push(x1);
    mstack.push(y1);
    cou+=2;
  }
  if(x2>=0 && y2>=0 && isAccessible(x,y,x2,y2)) {
    mstack.push(x2);
    mstack.push(y2);
    cou+=2;
  }
  if(x3>=0 && y3>=0 && isAccessible(x,y,x3,y3)) {
    mstack.push(x3);
    mstack.push(y3);
    cou+=2;
  }
  
  while(cou>0) {
    log("WOrking");
    int yrun=mstack.pop ();
    int xrun=mstack.pop ();
    cou-=2;
    if(is_consistant(xrun,yrun)) {
      continue;
    }
    else {
      make_consistent(xrun,yrun);
      mstack.push(xrun);
      mstack.push(yrun);
      cou+=2;
      getSurrounds(xrun,yrun,x0,y0,x1,y1,x2,y2,x3,y3);
      if(x0>=0 && y0>=0 && isAccessible(xrun,yrun,x0,y0)) {
        mstack.push(x0);
        mstack.push(y0);
        cou+=2;
      }
      if(x1>=0 && y1>=0 && isAccessible(xrun,yrun,x1,y1)) {
        mstack.push(x1);
        mstack.push(y1);
        cou+=2;
      }
      if(x2>=0 && y2>=0 && isAccessible(xrun,yrun,x2,y2)) {
        mstack.push(x2);
        mstack.push(y2);
        cou+=2;
      }
      if(x3>=0 && y3>=0 && isAccessible(xrun,yrun,x3,y3)) {
        mstack.push(x3);
        mstack.push(y3);
        cou+=2;
      }
    }
  }
}

//choose which direction to move
char toMove(int x,int y,int xprev,int yprev,int oreo){
  int x0,y0,x1,y1,x2,y2,x3,y3;
  getSurrounds(x,y,x0,y0,x1,y1,x2,y2,x3,y3);
  log("x,yvalues");
  log(String(x));
  log(String(y));
  log(String(x0));
  log(String(y0));
  log(String(x1));
  log(String(y1));
  log(String(x2));
  log(String(y2));
  log(String(x3));
  log(String(y3));
  int prev=0;
  int minvalue[4] ={1000,1000,1000,1000};
//if x0==0 error
  // if (x0>=0 && y0>=0){
    if (isAccessible(x,y,x0,y0)){
      
      if(x0==xprev && y0==yprev){
        prev=0;
      }
      minvalue[0]=flood[y0][x0];
      log("first");
    }
  
  // if (x1>=0 && y1>=0){
    if (isAccessible(x,y,x1,y1)){
      
      if(x1==xprev && y1==yprev){
        prev=1;
      }
      minvalue[1]=flood[y1][x1];
      log("second");
    }
  
  // if (x2>=0 && y2>=0){
    if (isAccessible(x,y,x2,y2)){
      
      if(x2==xprev && y2==yprev){
        prev=2;
      }
      minvalue[2]=flood[y2][x2];
      log("third");
    }
  
  // if (x3>=0 && y3>=0){
    if (isAccessible(x,y,x3,y3)){
      
      if(x3==xprev && y3==yprev){
        prev=3;
      }
      minvalue[3]=flood[y3][x3];
      log("forth");
    }
  
  
  int minv=minvalue[0];
  int mincell=0;
  int no_of_movement=0;
  for(int i=0;i<4;i++){
    if (minvalue[i]!=1000){
      no_of_movement+=1;
    }
  }
  for(int i=1;i<4;i++){
    if (minvalue[i]<minv){
      if (no_of_movement==1){
        minv=minvalue[i];
        mincell=i;
        log("minceLL11");
        log(String(i));
      }
    
    else{
      if (i==prev){
        continue;
      }
      else{
        minv=minvalue[i];
        mincell=i;
        log("mincell");
        log(String(i));
      }
    }
  }
  }
 log(String(mincell));
  if (mincell==oreo){
    return 'F';
  }
  else if((mincell==oreo-1) || (mincell==oreo+3)){
    return 'L';
  }
  else if((mincell==oreo+1) || (mincell==oreo-3)){
    return 'R';
  }
  else{
    return 'B';
  }
}
/*
char toMoveBack(int x,int y,int xprev,int yprev,int oreo){
  int x0,y0,x1,y1,x2,y2,x3,y3;
  getSurrounds(x,y,x0,y0,x1,y1,x2,y2,x3,y3);
  int val=flood[y][x];
  int prev=0;
  int minvalue[4] ={1000,1000,1000,1000};
//if x0==0 error
  if (x0>=0 && y0>=0){
    if (isAccessible(x,y,x0,y0)){
      minvalue[0]=flood[y0][x0];
      if(x0==xprev && y0==yprev){
        prev=0;
      }
    }}
  
if (x1>=0 && y1>=0){
    if (isAccessible(x,y,x1,y1)){
      minvalue[1]=flood[y1][x1];
      if(x1==xprev && y1==yprev){
        prev=1;
      }}
    }
  
  if (x2>=0 && y2>=0){
    if (isAccessible(x,y,x2,y2)){
      minvalue[2]=flood[y2][x2];
      if(x2==xprev && y2==yprev){
        prev=2;
      }
    }}
  
  if (x3>=0 && y3>=0){
    if (isAccessible(x,y,x3,y3)){
      minvalue[3]=flood[y3][x3];
      if(x3==xprev && y3==yprev){
        prev=3;
      }
    }}
  
  
  int maxv=minvalue[0];
  int mincell=0;
  int no_of_movement=0;
  for(int i=0;i<4;i++){
    if (minvalue[i]!=1000){
      no_of_movement+=1;
    }
  }
  //if error here change max to min
  for(int i=1;i<4;i++){
    if (minvalue[i]!=1000 && minvalue[i]>maxv){
      if (no_of_movement==1){
        maxv=minvalue[i];
        mincell=i;
      }
    
    else{
      if (i==prev){
        continue;
      }
      else{
        maxv=minvalue[i];
        mincell=i;
      }
    }
  }
  }

  if (mincell==oreo){
    return 'F';
  }
  else if(mincell==oreo-1 || mincell==oreo+3){
    return 'L';
  }
  else if(mincell==oreo+1 || mincell==oreo-3){
    return 'R';
  }
  else{
    return 'B';
  }
}
*/
int orientation(int orient,char turning){
  if (turning=='L'){
    orient-=1;
    if(orient==-1){
      orient=3; 
    }
  }
  else if(turning=='R'){
    orient+=1;
    if(orient==4){
      orient=0;
    }
  }
  else if(turning=='B'){
    if(orient==0){
      orient=2;
    }
    else if(orient==1){
      orient=3;
    }
    else if(orient==2){
      orient=0;
    }
    else if(orient==3){
      orient =1;
    }
  }
  return orient;
}
void update_coordinates(int &x,int &y,int oreo){
  if(oreo==0){
    y+=1;
  }
  else if(oreo==1){
    x+=1;
  }
  else if(oreo==2){
    y-=1;
  }
  else if(oreo==3){
    x-=1;
  }
}
void loop() {
 log("Running...");
 setColor(0, 0, 'G');
 setText(0, 0, "abc");
 int x=0;
 int y=0;
 int xprev=0;
 int yprev=0;
 int oreo=0;
 bool L,R,F;
 while(true){
  L=wallLeft();
  R=wallRight();
  F=wallFront();
  update_cells(x,y,oreo,L,R,F);
  log("update_cells");
  //end condition
  if ((x==7 || x==8) &&(y==7||y==8)){
    log("ended");
    break;
  }
  
  if(flood[y][x]!=0){
    flood_fill_update(x,y,xprev,yprev);
  }
//  
//  else{
//    while(true){
//      continue;
//    }
//  }
  log("flood_fill_update");
  char direction=toMove(x,y,xprev,yprev,oreo);
  log("direction");
  
  if (direction=='L'){
    turnLeft();
    log("L");
    oreo=orientation(oreo,'L');
  }
  else if (direction=='R'){
    turnRight();
    log("R");
    oreo=orientation(oreo,'R');
  }
  else if (direction=='B'){
    turnLeft();
    oreo=orientation(oreo,'L');
    turnLeft();
    oreo=orientation(oreo,'L');
    log("B");
  }
//  showFlood();
  moveForward();
  log("moveForward");
  xprev=x;
  yprev=y;
  log("oreo");
  log(String(oreo));
  update_coordinates(x,y,oreo);
  
 }
}
