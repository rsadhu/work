// Prezi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<cmath>
#include<vector>
#include<sstream>


typedef std::pair<int, int> pdd;

pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
	// Line AB represented as a1x + b1y = c1
	double a1 = B.second - A.second;
	double b1 = A.first - B.first;
	double c1 = a1*(A.first) + b1*(A.second);

	// Line CD represented as a2x + b2y = c2
	double a2 = D.second - C.second;
	double b2 = C.first - D.first;
	double c2 = a2*(C.first) + b2*(C.second);

	double determinant = a1*b2 - a2*b1;

	if (determinant != 0)
	{
		double x = (b2*c1 - b1*c2) / determinant;
		double y = (a1*c2 - a2*c1) / determinant;
		return pdd(x, y);
	}
}

std::vector<pdd> circleCircleIntersection(int x1, int y1, int r1, int x2, int y2, int r2)
{
	std::vector<pdd> res;

	double d = hypot(x2 - x1, y2 - y1);
	if (d <= (r1 + r2))
	{

		double ex = (x2 - x1) / d;
		double ey = (y2 - y1) / d;

		auto  x = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
		auto  y = sqrt(r1 * r1 - x * x);

		pdd X((x1 + x * ex - y * ey), (y1 + x * ey + y * ex));
		pdd Y((x1 + x * ex + y * ey), (y1 + x * ey - y * ex));
		
		res.push_back(X);
		res.push_back(Y);
	}
	return std::move(res);
}


int  FindLineCircleIntersections(
	float cx, float cy, float radius,
	pdd point1, pdd point2,
	pdd &intersection1, pdd &intersection2)
{
	float dx, dy, A, B, C, det, t;

	dx = point2.first - point1.first;
	dy = point2.second - point1.second;

	A = dx * dx + dy * dy;
	B = 2 * (dx * (point1.first - cx) + dy * (point1.second - cy));
	C = (point1.first - cx) * (point1.first - cx) +
		(point1.second - cy) * (point1.second - cy) -
		radius * radius;

	det = B * B - 4 * A * C;
	
	if ((A <= 0.0000001) || (det < 0))
    {
        // No real solutions.       
        return 0;
    }
    else if (det == 0)
    {
        t = -B / (2 * A);
        intersection1 = std::pair<int,int>(point1.first + t * dx, point1.second+ t * dy);		
        return 1;
    }
    else
    {
        // Two solutions.
        t = (float)((-B + sqrt(det)) / (2 * A));
        intersection1 = std::pair<int, int>(point1.first + t * dx, point1.second + t * dy);
        t = (float)((-B - sqrt(det)) / (2 * A));
		intersection2 = std::pair<int, int>(point1.first + t * dx, point1.second + t * dy);
        return 2;
    }
}


void tokenizer(const std::string & input,  char delim,std::vector<std::string> &tokens)
{
	std::stringstream  mySstream(input);
	std::string  temp;

	while (getline(mySstream, temp,delim )) 
	{
		tokens.push_back(temp);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	std::map<int, int> POI;

	std::vector<std::string > queries;

	std::string data;		

	while (getline(std::cin, data))
		queries.push_back(data);
	
	for (int i = 1; i < queries.size(); i++)
	{
		std::string  fQ = queries.at(i);
		pdd intersection1, intersection2;

		for (int j = i + 1; queries.size();j++)
		{
			std::vector<std::string> fs, ss;
			std::string  sQ = queries.at(j);
			tokenizer(fQ, ' ' , fs);
			tokenizer(sQ, ' ' , ss);

			if (fs.size() == ss.size())
			{
				if (fs.size() == 4)
				{
					// circles intersections
					 // FindLineCircleIntersections(
				}
				else
				{
					// lines intersection
					//circleCircleIntersection
				}
			}
			else
			{
				// line and circle intersections
				//pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
				auto res = lineLineIntersection(std::make_pair(-2, 1), std::make_pair(12, 6), std::make_pair(-4, 9), std::make_pair(8, -4));
			}
		}
	}

	return 0;
}

