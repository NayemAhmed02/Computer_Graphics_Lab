#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void plotGraph(int width, int height) {
	
	// plotting graph grids
	for(int i=width/2; i<=width; i+=20) {
		for(int j=height/2; j<=height; j+=20) {
			setcolor(WHITE);
			line(0, j, width, j);
			line(i, 0, i, height);
		}
	}
	
	for(int i=width/2; i>=0; i-=20) {
		for(int j=height/2; j>=0; j-=20) {
			setcolor(WHITE);
			line(0, j, width, j);
			line(i, 0, i, height);
		}
	}
	
	// ploting origin line
	setcolor(YELLOW);
	line(0, height/2, width, height/2);
	line(width/2, 0, width/2, height);
}

int main() {
	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth, screenHeight, "Coordinate", -3, -3);
	
	plotGraph(screenWidth, screenHeight);
	
	double x0, y0, x1, y1;
	
	cout<<"Enter value of x0 and yo : ";
	cin>>x0>>y0;
	
	cout<<"Enter value of x1 and y1 : ";
	cin>>x1>>y1;
	
	setcolor(GREEN);
	line(x0+screenWidth/2, screenHeight/2-y0, x1+screenWidth/2, screenHeight/2-y1);
	
	getch();
	closegraph();
}