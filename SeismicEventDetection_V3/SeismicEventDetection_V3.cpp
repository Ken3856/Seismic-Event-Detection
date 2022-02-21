/*
Filename: SeismicEventDetection_V3.cpp
Author: Kenneth Johnson

===========================================================================
This file contains the source code for seismicEventDetection.cpp
The program allows the user to enter a threshold value, read a data file
into an array and calculate if a seismic event has occured. The results
are then output as text and graphics to the console screen and the findings
are stored in a data file.
===========================================================================

*/

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class SeismicEventDetection
{
public:
	//constructors & Destructor
	SeismicEventDetection(void); //Default constructor
	SeismicEventDetection(int ak, int aNpts, float aT_incr, float aShortTimePower, float aLongTimePower, int aSensor[], float aRatio[], float aPoint_d[], float aThreshold, string aFilename); //Regular constructor
	~SeismicEventDetection(void);//Destructor

	//mutators
	void setTheSeismicEventDetection (int ak, int aNpts, float aT_incr, float aShortTimePower, float aLongTimePower, int aSensor[], float aRatio[], float aPoint_d[], float aThreshold, string aFilename);//set method
	void getTheSeismicEventDetection(); //get method

	//methods
	void askUserThreshold(); //asks user for input
	void readData(); //reads data file
	void calculate(); //calculates if seismic event occurred
	void writeData(); // writes data to .dat file
	void graph(); // uses graphics to display graph on console screen


private:
	int k, npts;
	float  t_incr, shortTimePower, longTimePower;
	int sensor[11];
	float ratio[11];
	float point_d[11];
	float threshold;
	string filename;

};



inline SeismicEventDetection::SeismicEventDetection(void) {
	k = 0;
	npts = 0;
	t_incr = 0.0;
	shortTimePower = 0.0;
	longTimePower = 0.0;
	threshold = 0.0;
	filename = "an invalid filename";


	//cout << "** DEBUG FROM THE DEFAULT CONSTRUCTOR **" << 
	//	"\n k is: " << k <<
	//	"\n Number of points is: " << npts << 
	//	"\n Time increment is " << t_incr << 
	//	"\n Short time power is: "<< shortTimePower << 
	//	"\n Long time power is: " << longTimePower << 
	//	"\n The threshold is: " << threshold << 
	//	"\n The filename is: " << filename << endl << endl;

	//cout << " The sensor array data is: " << endl;
	for (int k = 0; k < 11; ++k) {
		sensor[k] = {};
		//cout  << sensor[k] << endl;
	}

	//cout << " The ratio array data is: " << endl;
	for (int k = 0; k < 11; ++k) {
		ratio[k] = {};
		// cout << ratio[k] << endl;
	}

	//cout << " The datapoint array data is: " <<endl;
	for (int k = 0; k < 11; ++k) {
		point_d[k] = {};
		// cout << point_d[k] << endl;
	}

}

inline SeismicEventDetection::SeismicEventDetection(int ak, int aNpts, float aT_incr, float aShortTimePower, float aLongTimePower, int aSensor[], float aRatio[], float aPoint_d[], float aThreshold, string aFilename) {

	k = ak;
	npts = aNpts;
	t_incr = aT_incr;
	shortTimePower = aShortTimePower;
	longTimePower = aLongTimePower;
	threshold = aThreshold; 
	filename = aFilename;

	//cout << "\n\n** DEBUG REGULAR CONSTRUCTOR " <<
	//	"\n k is: " << k <<
	//	"\n Number of points is: " << npts <<
	//	"\n Time increment is: " << t_incr <<
	//	"\n Short time power is: " << shortTimePower <<
	//	"\n Long time power is: " << longTimePower <<
	//	"\n The threshold is: " << threshold <<
	//	"\n The filename is: " << filename << endl;

	//cout << " The sensor array data is: " << endl;
	for (int k = 0; k < npts; ++k) {
		sensor[k] = {};
		//cout << sensor[ak] << endl;
	}
	//cout << " The ratio array data is: " << endl;
	for (int k = 0; k < npts; ++k) {
		ratio[k] = {};
		//cout << ratio[k] << endl;
	}

	//cout << " The datapoint array data is: " << endl;
	for (int k = 0; k < npts; ++k) {
		point_d[k] = {};
		//cout << point_d[k] << endl;
	}

}

inline SeismicEventDetection::~SeismicEventDetection(void) {
	//cout << "\n\n Test 4 - Destructor " << 
	//	"\n k is: " << k <<
	//	"\n Number of points is: " << npts << 
	//	"\n Time increment is: " << t_incr << 
	//	"\n Short time power is: " << shortTimePower << 
	//	"\n Long time power is: " << longTimePower << 
	//	"\n The threshold is: " << threshold<< 
	//	"\n The filename is: " << filename << endl;

	//cout << "\n The data array contains the following data: " << endl;
	for (int k = 0; k < npts; ++k) {
	//cout << sensor[k] << endl;

	}	

	//cout << "\n The ratio array contains the following data: " << endl;
	for (int k = 0; k < npts; ++k) {
		//cout << ratio[k] << endl;
	}
}

inline void SeismicEventDetection::setTheSeismicEventDetection(int ak, int aNpts, float aT_incr, float aShortTimePower, float aLongTimePower, int aSensor[], float aRatio[], float aPoint_d[], float aThreshold, string aFilename) {

	k = ak;
	npts = aNpts;
	t_incr = aT_incr;
	shortTimePower = aShortTimePower;
	longTimePower = aLongTimePower;
	threshold = aThreshold;
	filename = aFilename;

	//cout << "\n\n DEBUG from the setTheSeismicEventDetection " << 
	//	"\n k is: " << k <<
	//	"\n Number of points is " << npts << 
	//	"\n Time increment is "<< t_incr << 
	//	"\n Short time power is " << shortTimePower<< 
	//	"\n Long time power is " << longTimePower << 
	//	"\n The threshold is " << threshold << 
	//	"\n The filename is " << filename << endl;

	//cout << " The sensor array data is: " << endl;
	for (int k = 0; k < npts; ++k) {
		sensor[k] = {};
		//cout << sensor[ak] << endl;
	}
	//cout << " The ratio array data is: " << endl;
	for (int k = 0; k < npts; ++k) {
		ratio[k] = {};
		//cout << ratio[k] << endl;
	}

	//cout << " The datapoint array data is: " << endl;
	for (int k = 0; k < npts; ++k) {
		point_d[k] = {};
		//cout << point_d[k] << endl;
	}
}


inline void SeismicEventDetection::getTheSeismicEventDetection() {
	//cout << "\n\n Debug from getTheSeismicEventDetection():"
	//	<< "\n k is: " << k << 
	//	"\n Number of points is " << npts << 
	//	"\n Time increment is " << t_incr << 
	//	"\n Short time power is " << shortTimePower << 
	//	"\n Long time power is " << longTimePower <<  
	//	"\n The threshold is " << threshold << 
	//	"\n The filename is " << filename << endl;

	//cout << " The sensor array data is: " << endl;
	for (int k = 0; k < npts; ++k) {
		sensor[k] = {};
		//cout << sensor[k] << endl;
	}
	//cout << " The ratio array data is: " << endl;
	for (int k = 0; k < npts; ++k) {
		ratio[k] = {};
		//cout << ratio[k] << endl;
	}
	//cout << " The datapoint array data is: " << endl;
	for (int k = 0; k < npts; ++k) {
		point_d[k] = {};
		//cout << point_d[k] << endl;
	}
}

inline void SeismicEventDetection::askUserThreshold() {
	
	//----------ASK USER TO ENTER A THRESHOLD VALUE----------------------------------------
	cout << " ====== SEISMIC EVENT DETECTION PROGRAM ===== \n ====== Author: Kenneth Johnson =======" << endl;
	cout << "\n To begin, please enter a threshold value: ";
	cin >> threshold;
	while (threshold <= 1)
	{
		cout << "\n **ERROR**\n The Threshold value must be greater than 1 " << endl;
		cout << " Please enter a new Threshold value: ";
		cin >> threshold;
	}
}

inline void SeismicEventDetection::readData() {

	//----------ASK USER TO ENTER A FILE NAME----------------------------------------
	cout << "\n\n Please enter the filename:";
	cout << " "; cin >> filename;
	ifstream fin;
	fin.open(filename);
	cout << " " << filename << " is opening..." << endl;
	if (fin.is_open())
	{
		fin >> npts >> t_incr;
		cout << "\n The Number of Points are: " << npts << "\n The Time increment is: " << t_incr << endl;

		//----------READ THE FILE DATA INTO AN ARRAY-----------
		cout << " The Data is: ";
		for (k = 0; k < npts; ++k)
		{
			fin >> sensor[k];
			cout << sensor[k] << " ";
		}
		fin.close();

	}
	else
	{
		cout << " **ERROR! FILE NOT FOUND!" << endl;
		return readData();
	}
}



inline void SeismicEventDetection::calculate() {

	//---------- ALGORITHM TO CALCULATE VALID POINTS ----------------------
	cout << "\n\n SEISMIC EVENT DETECTION COMMENCING....";
	for (k = 0; k < (npts - 4); ++k) {
		point_d[k] = t_incr * (4 + k);
		if (k == 0)
		{
			cout << "\n\n The first valid point is at the time " << point_d[k] << "s"
				<< " for which: " << endl;
		}
		else
		{
			cout << " \n The next valid point is at time " << point_d[k] << "s"
				<< " for which: " << endl;
		}

		shortTimePower = (pow(sensor[3 + k], 2) + pow(sensor[4 + k], 2)) / 2;
		cout << " The Value for short time power is: " << shortTimePower << endl;

		longTimePower = (pow(sensor[3 + k], 2) + pow(sensor[4 + k], 2) + pow(sensor[2 + k], 2) + pow(sensor[1 + k], 2) + pow(sensor[0 + k], 2)) / 5;
		cout << " The value for long time power is: " << longTimePower << endl;

		ratio[k] = shortTimePower / longTimePower;
		cout << " The Value for ratio is: " << ratio[k] << endl;

		if (ratio[k] > threshold)
		{
			cout << " **WARNING!! EARTHQUAKE EVENT HAS OCCURRED!** " << endl;
		}
		else
		{
			cout << " No Event has occurred " << endl;
		}
	}
}



inline void SeismicEventDetection::writeData() {

	//===========Write file=========================
	ofstream file;
	file.open("Seismic_Report.dat");

	if (file.is_open())
	{
		file << " ===================================================================================="
			<< "\n ==== This is the data file containing the times of potential seismic events, ======="
			<< "\n ==== the corresponding short time to long-time power ratio and threshold values ===="
			<< "\n ====================================================================================" << endl << endl;

		for (k = 0; k < (npts - 4); ++k) {
			point_d[k] = t_incr * (4 + k);
			if (k == 0) {
				file << " The first valid point is at the time " << point_d[k] << "s"
					<< " for which: " << endl;
			}
			else {
				file << " \n The next valid point is at time " << point_d[k] << "s"
					<< " for which: " << endl;
			}
			shortTimePower = (pow(sensor[3 + k], 2) + pow(sensor[4 + k], 2)) / 2;
			file << " The Value for short time power is: " << shortTimePower << endl;

			longTimePower = (pow(sensor[3 + k], 2) + pow(sensor[4 + k], 2) + pow(sensor[2 + k], 2) + pow(sensor[1 + k], 2) + pow(sensor[0 + k], 2)) / 5;
			file << " The value for long time power is: " << longTimePower << endl;

			file << " The value of the Threshold is: " << threshold << endl;
			ratio[k] = shortTimePower / longTimePower;
			file << " The Value for ratio is: " << ratio[k] << endl;

			if (ratio[k] > threshold)
			{
				file << " **WARNING!! EARTHQUAKE EVENT HAS OCCURRED!** " << endl;
			}
			else
			{
				file << " No Event has occurred " << endl;
			}
		}
		cout << "\n... Data is written to file " << "Seismic_Report.dat" << endl;
	}
	else {
		cout << "\n **Error Data not written to file** " << endl;
	}
	file.close();


}

inline void SeismicEventDetection::graph() {


	line line1(530, 530, 0, 0, 0, 400); //(x position, y position, red, green, blue, length)
	square square1(480, 240, 18, 105, 255, 530, 330, 0, 0, 0);
	square square2(485, 245, 54, 140, 207, 520, 320, 0, 0, 0); //(x pos, y pos, red, green, blue, length, width, fill red, fill green, fill blue

	HWND hWnd = GetForegroundWindow();
	HDC hDC = GetDC(hWnd);
	square1.draw(hDC);
	square2.draw(hDC);
	line1.draw(hDC);

	//-------------Point #1---------------------------
	if (450 - (100 * ratio[0]) < 300)
	{
		point* point1 = new point(600, 520 - (100 * ratio[0]), 255, 0, 0);
		point1->draw(hDC);
	}
	else
	{
		point* point1 = new point(600, 520 - (100 * ratio[0]), 0, 7, 204);
		point1->draw(hDC);
	}


	//-------------Point #2---------------------------
	if (450 - (100 * ratio[1]) < 300)
	{
		point* point2 = new point(630, 520 - (100 * ratio[1]), 255, 0, 0);
		point2->draw(hDC);
	}
	else
	{
		point* point2 = new point(630, 520 - (100 * ratio[1]), 0, 7, 204);
		point2->draw(hDC);
	}


	//-------------Point #3---------------------------
	if (450 - (100 * ratio[2]) < 300) {
		point* point3 = new point(660, 520 - (100 * ratio[2]), 255, 0, 0);
		point3->draw(hDC);
	}
	else
	{
		point* point3 = new point(660, 520 - (100 * ratio[2]), 0, 7, 204);
		point3->draw(hDC);
	}


	//-------------Point #4---------------------------
	if (450 - (100 * ratio[3]) < 300)
	{
		point* point4 = new point(690, 520 - (100 * ratio[3]), 255, 0, 0);
		point4->draw(hDC);
	}
	else
	{
		point* point4 = new point(690, 520 - (100 * ratio[3]), 0, 7, 204);
		point4->draw(hDC);
	}


	//-------------Point #5---------------------------
	if (450 - (100 * ratio[4]) < 300)
	{
		point* point5 = new point(720, 520 - (100 * ratio[4]), 255, 0, 0);
		point5->draw(hDC);
	}
	else
	{
		point* point5 = new point(720, 520 - (100 * ratio[4]), 0, 7, 204);
		point5->draw(hDC);
	}


	//-------------Point #6---------------------------
	if (450 - (100 * ratio[5]) < 300)
	{
		point* point6 = new point(750, 520 - (100 * ratio[5]), 255, 0, 0);
		point6->draw(hDC);
	}
	else
	{
		point* point6 = new point(750, 520 - (100 * ratio[5]), 0, 7, 204);
		point6->draw(hDC);
	}


	//-------------Point #7---------------------------
	if (450 - (100 * ratio[6]) < 300)
	{
		point* point7 = new point(780, 520 - (100 * ratio[6]), 255, 0, 0);
		point7->draw(hDC);
	}
	else
	{
		point* point7 = new point(780, 520 - (100 * ratio[6]), 0, 7, 204);
		point7->draw(hDC);
	}


	//-------------Point #8---------------------------
	if (450 - (100 * ratio[7]) < 300)
	{
		point* point8 = new point(810, 520 - (100 * ratio[7]), 255, 0, 0);
		point8->draw(hDC);
	}
	else
	{
		point* point8 = new point(810, 520 - (100 * ratio[7]), 0, 7, 204);
		point8->draw(hDC);
	}

}




int main(void)
{
	//cout << " Main has started " << endl;



	SeismicEventDetection s1;
	SeismicEventDetection s2(0, 12, 2.2, 0.9, 4.8, {}, {}, {}, 5.6, "Filename2");
	s2.setTheSeismicEventDetection(2, 14, 4.4, 5.8, 6.2, {}, {}, {}, 5.9, "filename3");
	s2.getTheSeismicEventDetection();
	s2.askUserThreshold();
	s2.readData();
	s2.calculate();
	s2.writeData();


	
	cout << "\n** To Display the Graph, please press <Enter>.. " << endl;
	_getch();

	s2.graph();
	_getch();

	//cout << " Main has ended " << endl;


	return 0;
}




