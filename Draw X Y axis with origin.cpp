#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void plotAxis(int width, int height) {
	
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
	
	setcolor(YELLOW);
	line(0, height/2, width, height/2);
	line(width/2, 0, width/2, height);
}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth, screenHeight, "X _ Y Coordinate");
	
	plotAxis(screenWidth, screenHeight); 
	
	getch();
	closegraph();
}