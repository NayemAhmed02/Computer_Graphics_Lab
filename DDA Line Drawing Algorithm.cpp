#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

/* setcolor() all valuues
COLOR               INT VALUES
-------------------------------
BLACK                   0
BLUE                    1
GREEN                   2
CYAN                    3   
RED                     4
MAGENTA                 5
BROWN                   6 
LIGHTGRAY               7 
DARKGRAY                8
LIGHTBLUE               9
LIGHTGREEN             10
LIGHTCYAN              11
LIGHTRED               12
LIGHTMAGENTA           13
YELLOW                 14
WHITE                  15
*/

void plotgraph(int screenWidth,int screenHeight) {
	
	//plotting grids
	// ********************************************************************************************************************************************************
	// setcolor() function which is used to set the current drawing color to the new color.
    // Syntax --> void setcolor(int color);
    // Explanation --> In Graphics, each color is assigned a number. Total 16 colors are available (0 - 15). Number of available colors depends on current 
	// graphics mode and driver. For example, setcolor(RED) or setcolor(4) changes the current drawing color to RED. 
	// Remember that default drawing color is WHITE.
	// *********************************************************************************************************************************************************
	
	// line() function is used to draw a line from a point(x1,y1) to point(x2,y2) i.e. (x1,y1) and (x2,y2) are end points of the line.
	// Syntax --> void line(int x1, int y1, int x2, int y2);
	// ***********************************************************************************************************************************************************
	for(int i=screenWidth/2;i<=screenWidth;i=i+25)
	{
		for(int j=screenHeight/2;j<=screenHeight;j=j+25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	for(int i=screenWidth/2;i>=0;i=i-25)
	{
		for(int j=screenHeight/2;j>=0;j=j-25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	//plotting origin axes
	setcolor(YELLOW);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}

int main() {
	// gm means Graphics mode, which is one type of computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
	int gd = DETECT, gm;
	
	// initgraph initializes the graphics system
    // by loading a graphics driver from disk
    initgraph(&gd, &gm, "");
    
    // window size measurement and initialization
    
    // *************************************************************************************************************************************************
    // The DWORD means Double Word. As Microsoft WORD is 16 bits long, DWORD is 32 bits across all platforms.
    // Furthermore, DWORD is not a type in C++; it is instead defined in <windows.h>.
    // Use a DWORD whenever the code is expecting a DWORD, even though (as of writing this article) the unsigned int would work just as well.
    // Because, unsigned int range can be changed. unsigned int does not necessary have the range 0 to 4,294,967,295.
    // For myself, I would assume unsigned int is platform specific. Integers could be 16 bits, 32 bits or even 64 bits.
    //On the other hand, DWORD specifies its own size, which is Double Word. Words are 16 bits, so DWORD will be known as 32 bits across all platforms.
    // ********************************************************************************************************************************************************
    
    // GetSystemMetrics() --> Retrieves the specified system metric or system configuration setting. 
	// Note that all dimensions retrieved by GetSystemMetrics are in pixels.
    // SM_CXSCREEN --> Return or gives the width of the screen of the primary display monitor, in pixels.
    // SM_CYSCREEN --> Return or gives the height of the screen of the primary display monitor, in pixels.
    // ***********************************************************************************************************************************************************
    
    // Syntax --> int initwindow(int width, int height, const char* title="Windows BGI", int left=0, int top=0, bool dbflag=false, closeflag=true);
    // Description --> The initwindow function is available in the winbgim implementation of BGI graphics. You do not need to include conio.h; 
	// just include graphics.h. The function initializes the graphics system by opening a graphics window of the specified size. 
	// The first two parameters (width and height) are required, but all other parameters have default values. The title parameter is the title that will 
	// be printed at the top of the window (with a default of "Windows BGI".) If this is set to the empty string (no characters), then the window will be 
	// opened without a title bar or border (typically used for a popup message that the user can then close by clicking), and the user will not be able 
	// to move this window. If you want a title bar with no visible title, then set the title to a string containing one space.
	// The left and top parameters determine the screen coordinates of the left and top sides of the window. 
	// The dbflag parameter determines whether double-buffering for the window is automatically turned on as described in the swapbuffers function
	// (true means that double-buffering will be turned on).
	// If the closeflag parameter is true, then the user can click on the window's close button to shut down the entire program.
	
	// Return Value --> The original version of initgraph was a void function (with no flag argument), and only one graphics window could be created in any
	// program. The new version allows multiple graphics windows to be created. The return value from the new initwindow function is a unique int identifier
	// that can be used as an argument to setcurrentwindow in order to set which of several windows is currently being used. Immediately after calling 
	// initwindow, the current window is always the window that was just created.
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	
	//DDA algorithm
	float x,y,x0,y0,x1,y1,dx,dy,XIncrement,YIncrement,step;
	cout<<"Enter the starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the ending point (x1,y1): ";
	cin>>x1>>y1;
	
	dx=abs(x1-x0);
	dy=abs(y1-y0);
	
	if(dx>dy) {
		
		step=dx;
	}
	else {
		
		step=dy;
	}
	
	XIncrement = (x1-x0)/step;
	YIncrement = (y1-y0)/step;
	
	x=x0;
	y=y0;
	    
    for(int i=0;i<=step;i++) {
    	
    	// putpixel() function plots a pixel at location (x, y) of specified color.
		// Syntax --> void putpixel(int x, int y, int color);
        // For example,if we want to draw a GREEN color pixel at (35, 45) then we will write putpixel(35, 45, GREEN); in our c++ program, 
		// putpixel function can be used to draw circles, lines and ellipses using various algorithms.
        putpixel((screenWidth/2)+((int) (x+0.5)),(screenHeight/2)-((int)(y+0.5)),GREEN);

    	x=x+XIncrement;
    	y=y+YIncrement;
	}
	
	// outtextxy function display text or string at a specified point(x,y) on the screen.
    // Syntax --> void outtextxy(int x, int y, char *string);
    // x, y are coordinates of the point and third argument contains the string to be displayed.
	outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Starting point");
    outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "Ending point");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
    
	getch(); // For handling enter press buffer.
	// closegraph function closes the graphics mode, deallocates all memory allocated by graphics system and restores the screen to the mode it was in 
	// before you called initgraph.
	closegraph();
}