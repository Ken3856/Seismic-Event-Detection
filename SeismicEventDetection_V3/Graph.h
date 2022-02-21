/*
Filename: graph.h
Author: Kenneth Johnson

===========================================================================
This file contains the code for graph.h
The file contains the classes and methods for graphing the data for the
seismic event detection application.
===========================================================================

*/

#include<windows.h>
#include<iostream>// for cin, cout, cerr
#include<stdio.h>
#include<conio.h>
//#include"resource.h"


//=== class declarations ====================================
class point
{
protected:
	int   x, y;
	COLORREF RGB_color;

public:
	point() { x = 0;   y = 0; RGB_color = RGB(0, 0, 0); }
	point(int xval, int yval, int r, int g, int b);
	void  draw(HDC hdc);
	void  set_x(int xval);
	void  set_y(int yval);
	int   get_x();
	int   get_y();
};




class line : public point
{

protected:
	int length;

public:
	line() { x = 0; y = 0; RGB_color = RGB(0, 0, 0); length = 0; }
	line(int xval, int yval, int r, int g, int b, int ilength);
	void  draw(HDC hDC);
	void  set_len(int ilength);
	int   get_len();
};




class square : public line
{
protected:
	int width;
	COLORREF RGB_fill_color;

public:
	square() {
		x = 0; y = 0; RGB_color = RGB(0, 0, 0);
		length = 0; width = 0; RGB_fill_color = RGB(0, 0, 0);
	}
	square(int xval, int yval, int r, int g, int b, int ilength, int iwidth, int fill_r, int fill_g, int fill_b);
	void  draw(HDC hdc);
	void set_width(int iwidth);
	int get_width();
};





//=== methods for point class ===============================
point::point(int xval, int yval, int r, int g, int b)
{
	x = xval;
	y = yval;
	RGB_color = RGB(r, g, b);
}
void point::set_x(int xval) { x = xval; }
void point::set_y(int yval) { y = yval; }
int point::get_x() { return(x); }
int point::get_y() { return(y); }
void point::draw(HDC hDC)
{
	int i, j;
	for (i = -2; i < 3; i++)
		for (j = -2; j < 3; j++)
			SetPixel(hDC, x + i, y + j, RGB_color);
}







//=== methods for line class ================================

line::line(int xval, int yval, int r, int g, int b, int ilength) : point(xval, yval, r, g, b)
{
	set_len(ilength);
}

void line::set_len(int ilength) { length = ilength; }
int line::get_len() { return(length); }
void line::draw(HDC hDC)
{
	HPEN pen = NULL;
	if (pen)DeleteObject(pen); //delete previous created pen 
	pen = CreatePen(PS_SOLID, 3, RGB_color);  // Create a new pen 
	SelectObject(hDC, pen); // select pen into context

	MoveToEx(hDC, x, y, NULL);
	LineTo(hDC, x + length, y);

	MoveToEx(hDC, x, y, NULL);
	LineTo(hDC, x, y - 270);
}




//=== methods for square class ==============================
square::square(int xval, int yval, int r, int g, int b, int ilength, int iwidth, int fill_r, int fill_g, int fill_b)
	: line(xval, yval, r, g, b, ilength)
{
	set_width(iwidth);
	RGB_fill_color = RGB(fill_r, fill_g, fill_b);
}

void square::set_width(int iwidth) { width = iwidth; }
int square::get_width() { return(width); }
void square::draw(HDC hDC)
{
	HPEN pen = NULL;
	HPEN pen2 = NULL;
	if (pen)DeleteObject(pen); //delete previous created pen
	if (pen2)DeleteObject(pen2); //delete previous created pen 
	pen = CreatePen(PS_SOLID, 5, RGB_color);  // Create a newpen 
	SelectObject(hDC, pen); // select pen into c on text 
	Rectangle(hDC, x, y, x + length, y + width);
	pen2 = CreatePen(PS_SOLID, 1, RGB_fill_color); //Create new pen            
	SelectObject(hDC, pen2); // select pen into context           
	Rectangle(hDC, x + 2, y + 2, x - 2 + length, y - 2 + width);
}


