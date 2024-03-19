#include "StackArray.h"
bool flag=true;
int x=8;
int y=0;
int oreo=3;
int xprev=0;
int yprev=0;
byte flood[16][16]={{14, 13, 12, 11, 10, 9, 8, 7, 7, 8, 9, 10, 11, 12, 13, 14},
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
byte cells[16][16]={
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


void update_cells(int x,int y, int oreo,bool L,bool R,bool F){
    if(L && R && F) {
        if (oreo==0){
            cells[x][y]=11;
        }
        else if (oreo==1){
            cells[x][y]=12;
        }
        else if (oreo==2){
            cells[x][y]=13;
        }
        else if (oreo==3){
            cells[x][y]=14;
        }
    }
    else if(L && R){
        if (oreo==0 || oreo==2){
            cells[x][y]=9;
        }
        else if (oreo==1 || oreo==3){
            cells[x][y]=7;
        }
    }
    else if(L && F){
        if (oreo==0){
            cells[x][y]=6;
        }
        else if (oreo==1){
            cells[x][y]=5;
        }
        else if (oreo==2){
            cells[x][y]=8;
        }
        else if (oreo==3){
            cells[x][y]=10;
        }
    }
    else if(F && R){
        if (oreo==0){
            cells[x][y]=5;
        }
        else if (oreo==1){
            cells[x][y]=8;
        }
        else if (oreo==2){
            cells[x][y]=10;
        }
        else if (oreo==3){
            cells[x][y]=6;
        }
    }
    else if(F){
        if (oreo==0){
            cells[x][y]=1;
        }
        else if (oreo==1){
            cells[x][y]=2;
        }
        else if (oreo==2){
            cells[x][y]=3;
        }
        else if (oreo==3){
            cells[x][y]=4;
        }
    }
    else if(L){
        if (oreo==0){
            cells[x][y]=4;
        }
        else if (oreo==1){
            cells[x][y]=1;
        }
        else if (oreo==2){
            cells[x][y]=2;
        }
        else if (oreo==3){
            cells[x][y]=3;
        }
    }
    else if (R){
        if (oreo==0){
            cells[x][y]=2;
        }
        else if (oreo==1){
            cells[x][y]=3;
        }
        else if (oreo==2){
            cells[x][y]=4;
        }
        else if (oreo==3){
            cells[x][y]=1;
        }
    }
}
//check if the cell is accessible by checking cells arary
bool isAccessible(int x,int y,int x1,int y1){
    int d=cells[x][y];
    if (x1<0||y1<0||x1>15||y1>15){
        return false;
    }
    if (x1==x){
        if (y1>y){
            if (d==1||d==5||d==6||d==7||d==11||d==12||d==14){
                return false;
            }
            return true;
        }
        else{
            if (d==3||d==7||d==8||d==10||d==12||d==13||d==14){
                return false;
            }
            return true;
        }
    }
    else {
        if(x1>x){
            if (d==2||d==5|d==8||d==9||d==11||d==12||d==13){
                return false;
            }
            return true;
        }
        else{
            if (d==4||d==6||d==9||d==10||d==11||d==13||d==14){
                return false;
            }
            return true;
        }
    }

}


void getSurrounds(int x,int y,int & x0,int & y0,int & x1,int & y1,int & x2,int & y2,int & x3,int & y3){
    x0=x;
    y0=y+1;
    x1=x+1;
    y1=y;
    x2=x;
    y2=y-1;
    x3=x-1;
    y3=y;
}

bool make_consistent(int x,int y){
    int x0,y0,x1,y1,x2,y2,x3,y3;
    getSurrounds(x,y,x0,y0,x1,y1,x2,y2,x3,y3);
    int minvalue[4] ={-1,-1,-1,-1};
    if (isAccessible(x,y,x0,y0)){
        minvalue[0]=flood[x0][y0];
    }
    if (isAccessible(x,y,x1,y1)){
        minvalue[1]=flood[x1][y1];
    }
    if (isAccessible(x,y,x2,y2)){
        minvalue[2]=flood[x2][y2];
    }
    if (isAccessible(x,y,x3,y3)){
        minvalue[3]=flood[x3][y3];
    }
    int minv=1000;
    for(int i=0;i<4;i++){
        if (!(minvalue[i]==-1)){
            if (minvalue[i]<minv){
                minv=minvalue[i];
            }
        }
    }
    if (flood[x][y]<=minv){
        flood[x][y]=minv+1;
        return true;
    }
    return false;
}
void flood_fill_update(int x,int y){
    StackArray <int> stakarr;
    if(make_consistent(x,y)){
    int x0,y0,x1,y1,x2,y2,x3,y3;
    getSurrounds(x,y,x0,y0,x1,y1,x2,y2,x3,y3);
    if(x0>=0 && y0>=0 && isAccessible(x,y,x0,y0)) {
    stakarr.push(x0);
    stakarr.push(y0);
  }
  if(x1>=0 && y1>=0 && isAccessible(x,y,x1,y1)) {
    stakarr.push(x1);
    stakarr.push(y1);
  }
  if(x2>=0 && y2>=0 && isAccessible(x,y,x2,y2)) {
    stakarr.push(x2);
    stakarr.push(y2);
  }
  if(x3>=0 && y3>=0 && isAccessible(x,y,x3,y3)) {
    stakarr.push(x3);
    stakarr.push(y3);
  }
    }
    while(!stakarr.isEmpty()){
        int yrun=stakarr.pop();
        int xrun=stakarr.pop();
        if (make_consistent(xrun,yrun)){
            int x0,y0,x1,y1,x2,y2,x3,y3;
            getSurrounds(xrun,yrun,x0,y0,x1,y1,x2,y2,x3,y3);
            if(isAccessible(xrun,yrun,x0,y0)) {
                stakarr.push(x0);
                stakarr.push(y0);
            }
            if(isAccessible(xrun,yrun,x1,y1)) {
                stakarr.push(x1);
                stakarr.push(y1);
            }
            if(isAccessible(xrun,yrun,x2,y2)) {
                stakarr.push(x2);
                stakarr.push(y2);
            }
            if(isAccessible(xrun,yrun,x3,y3)) {
                stakarr.push(x3);
                stakarr.push(y3);
            }
        }
    }
}
char toMove(int x, int y,int xprev,int yprev,int oreo){
    int x0,y0,x1,y1,x2,y2,x3,y3;
    getSurrounds(x,y,x0,y0,x1,y1,x2,y2,x3,y3);
    int prev=0;
    int minvalue[4]={1000,1000,1000,1000};
    if (isAccessible(x,y,x0,y0)){
        if (x0==xprev && y0==yprev){
            prev=0;
        }
        minvalue[0]=flood[x0][y0];
    }
    if (isAccessible(x,y,x1,y1)){
        if (x1==xprev && y1==yprev){
            prev=1;
        }
        minvalue[1]=flood[x1][y1];
    }
    if (isAccessible(x,y,x2,y2)){
        if (x2==xprev && y2==yprev){
            prev=2;
        }
        minvalue[2]=flood[x2][y2];
    }
    if (isAccessible(x,y,x3,y3)){
        if (x3==xprev && y3==yprev){
            prev=3;
        }
        minvalue[3]=flood[x3][y3];
    }
    int minv=minvalue[0];
    int mincell=0;
    for(int i=0;i<4;i++){
        if (minvalue[i]<=minv){
            minv=minvalue[i];
            mincell=i;
        }
    }
    if(mincell==oreo){
        return 'F';
    }
    else if (mincell==oreo+1||mincell==oreo-3){
        return 'R';
    }
    else if (mincell==oreo-1||mincell==oreo+3){
        return 'L';
    }
    else {
        return 'B';
    }
}
int orientation(int orient,char turning){
    if (turning=='L'){
        orient-=1;
        if (orient==-1){
            orient=3;
        }
    }
    else if(turning=='R'){
        orient+=1;
        if (orient==4){
            orient=0;
        }
    }
    else if (turning=='B'){
        if (orient==0){
            orient=2;
        }
        else if ( orient==1){
            orient=3;
        }
        else if(orient==2){
            orient=0;
        }
        else if(orient==3){
            orient=1;
        }
    }
    return orient;
}
void update_coordinates(int &x,int &y,int oreo){
    if (oreo==0){
        y+=1;
    }
    else if (oreo==1){
        x+=1;
    }
    else if (oreo==2){
        y-=1;
    }
    else if (oreo==3){
        x-=1;
    }
}
void loop(){
    int x=8;
    int y=0;
    int xprev=0;
    int yprev=0;
    int oreo=3;
    bool L,R,F;
    
    while(flag){
        L=wallLeft();
        R=wallRight();
        F=wallFront();
        Serial.println("x");
        Serial.println(x);
        Serial.println(y);
                update_cells(x,y,oreo,L,R,F);
        if (!((x==7 || x==8) &&(y==7||y==8))){
            flood_fill_update(x,y);
        }
        else{
            flag=false;
        }
        char direction=toMove(x,y,xprev,yprev,oreo);
        if (direction=='L'){
            turnLeft();
            delay(100);
            // moveForward();
            oreo=orientation(oreo,'L');
        }
        else if (direction=='R'){
            turnRight();
            delay(100);
            // moveForward();
            oreo=orientation(oreo,'R');
        }
        else if (direction=='B'){
            uturn();
            delay(100);
            // moveForward();
            oreo=orientation(oreo,'L');
            oreo=orientation(oreo,'L');
        }
        // showFlood();
        moveForward();
        xprev=x;
        yprev=y;
        update_coordinates(x,y,oreo);
        delay(1000);
    }
}