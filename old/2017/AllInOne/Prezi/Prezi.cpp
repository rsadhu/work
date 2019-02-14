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


typedef std::pair<float, float> pdd;

pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
	// Line AB represented as a1x + b1y = c1
	float a1 = B.second - A.second;
	float b1 = A.first - B.first;
	float c1 = a1*(A.first) + b1*(A.second);

	// Line CD represented as a2x + b2y = c2
	float a2 = D.second - C.second;
	float b2 = C.first - D.first;
	float c2 = a2*(C.first) + b2*(C.second);

	float determinant = a1*b2 - a2*b1;

	if (determinant != 0)
	{
		float x = (b2*c1 - b1*c2) / determinant;
		float y = (a1*c2 - a2*c1) / determinant;
		return pdd(x, y);
	}
}

std::vector<pdd> circleCircleIntersection(float x1, float y1, float r1, float x2, float y2, float r2)
{
	std::vector<pdd> res;

	float d = hypot(x2 - x1, y2 - y1);
	if (d <= (r1 + r2))
	{

		float ex = (x2 - x1) / d;
		float ey = (y2 - y1) / d;

		auto  x = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
		auto  y = sqrt(r1 * r1 - x * x);

		pdd X((x1 + x * ex - y * ey), (y1 + x * ey + y * ex));
		pdd Y((x1 + x * ex + y * ey), (y1 + x * ey - y * ex));
		
		res.push_back(X);
		res.push_back(Y);
	}
	return std::move(res);
}


float  FindLineCircleIntersections(
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
        intersection1 = std::pair<float,float>(point1.first + t * dx, point1.second+ t * dy);		
        return 1;
    }
    else
    {
        // Two solutions.
        t = (float)((-B + sqrt(det)) / (2 * A));
        intersection1 = std::pair<float, float>(point1.first + t * dx, point1.second + t * dy);
        t = (float)((-B - sqrt(det)) / (2 * A));
		intersection2 = std::pair<float, float>(point1.first + t * dx, point1.second + t * dy);
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


int _tmain(float argc, _TCHAR* argv[])
{
	std::map<float, float> POI;

	std::vector<std::string > queries;

	std::string data;		

	while (getline(std::cin, data))
		queries.push_back(data);
	
	for (float i = 1; i < queries.size(); i++)
	{
		std::string  fQ = queries.at(i);
		pdd intersection1, intersection2;

		for (float j = i + 1; j<queries.size();j++)
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
					auto res = circleCircleIntersection(std::stoi(ss.at(1)), std::stoi(ss.at(2)), std::stoi(ss.at(3)), std::stoi(fs.at(1)), std::stoi(fs.at(2)), std::stoi(fs.at(3)));					
					for (auto &it : res)
						POI.insert(it);
				}
				else
				{					
					auto res = lineLineIntersection(std::pair<float, float>(std::stoi(ss.at(1)), std::stoi(ss.at(2))), std::pair<float, float>(std::stoi(ss.at(3)), std::stoi(ss.at(4)))
						, std::pair<float, float>(std::stoi(fs.at(1)), std::stoi(fs.at(2))), std::pair<float, float>(std::stoi(fs.at(3)), std::stoi(fs.at(4))));

					if (res.first!=0 || res.second!=0)
						POI.insert(res);					
				}
			}
			else
			{
				pdd p1, p2;
				float  r = 0;
				if (ss.size() == 4)
					r = FindLineCircleIntersections(std::stoi(ss.at(1)), std::stoi(ss.at(2)), std::stoi(ss.at(3)), std::pair<float, float>(std::stoi(fs.at(1)), std::stoi(fs.at(2))), std::pair<float, float>(std::stoi(fs.at(3)), std::stoi(fs.at(4))), p1, p2);
				else
					r = FindLineCircleIntersections(std::stoi(fs.at(1)), std::stoi(fs.at(2)), std::stoi(fs.at(3)), std::pair<float, float>(std::stoi(ss.at(1)), std::stoi(ss.at(2))), std::pair<float, float>(std::stoi(ss.at(3)), std::stoi(ss.at(4))), p1, p2);

				if (r == 1)
					POI.insert(p1);
				else 
				if (r == 2)
				{
					POI.insert(p1);
					POI.insert(p2);
				}
			}
		}
	}

	return 0;
}

