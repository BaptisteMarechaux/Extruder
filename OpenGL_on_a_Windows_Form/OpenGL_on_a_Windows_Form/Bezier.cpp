#include "stdafx.h"
#include "Bezier.h"



Bezier::Bezier()
{
}


Bezier::~Bezier()
{
}

std::vector<vec3> Bezier::GetControlPoints() const
{
	return controlPoints;
}

std::vector<vec3> Bezier::Curve(float step, float min, float max, vec3 p1, vec3 p2, vec3 p3, vec3 p4)
{
	std::vector<vec3> points = std::vector<vec3>();

	//points.push_back(p1);
	std::cout << "Starting Bezier" << std::endl;
	//std::cout << "X : " <<p1.x << " Y : " << p1.y << std::endl;

	for (float i = min; i <= max; i += step)
	{
		float t = i;
		float x = pow(1 - t, 3)*p1.x + 3 * t*pow(1 - t, 2)*p2.x + 3 * pow(t, 2)*(1 - t)*p3.x + pow(t, 3)*p4.x;
		float y = pow(1 - t, 3)*p1.y + 3 * t*pow(1 - t, 2)*p2.y + 3 * pow(t, 2)*(1 - t)*p3.y + pow(t, 3)*p4.y;

		std::cout << "X : " << x << " Y : " << y << std::endl;
		points.push_back(vec3(x, y, 0));

	}

	//points.push_back(p4);
	//std::cout << "X : " << p4.x << " Y : " << p4.y << std::endl;

	return points;
}

vec3 Bezier::Casteljau(std::vector<vec3> points, float step)
{
	if (points.size() == 1) {
		std::cout << "X : " << points[0].x << " Y : " << points[0].y << std::endl;
		return points[0];
	}
		
	std::vector<vec3> newPoints;
	for (int i = 0; i < points.size() - 1; i++)
	{
		newPoints.push_back(points[i] *step + points[i + 1] * (1-step) );
	}
	Casteljau(newPoints, step);
}

/*
std::vector<vec3> Bezier::Spline(float step, float min, float max, vec3 p1, vec3 p2, vec3 p3, vec3 p4)
{
	std::vector<vec3> points = std::vector<vec3>();

	//points.push_back(p1);
	std::cout << "Starting Bezier" << std::endl;
	//std::cout << "X : " <<p1.x << " Y : " << p1.y << std::endl;

	for (float i = min; i <= max; i += step)
	{
		float t = i;

		float x = (pow(1 - t, 3)*p1.x + (pow(3*t, 3) - pow(6*t, 2) + 4)*p2.x + (pow(-3*t, 3) + pow(3*t, 2) + 3*t + 1)*p3.x + pow(t, 3)*p4.x) / 6;
		float y = (pow(1 - t, 3)*p1.y + (pow(3*t, 3) - pow(6*t, 2) + 4)*p2.y + (pow(-3*t, 3) + pow(3*t, 2) + 3*t + 1)*p3.y + pow(t, 3)*p4.y) / 6;
		std::cout << "X : " << x << " Y : " << y << std::endl;
		points.push_back(vec3(x, y));

	}


	//points.push_back(p4);
	//std::cout << "X : " << p4.x << " Y : " << p4.y << std::endl;

	return points;
}
*/

std::vector<vec3> newPoints;
std::vector<vec3> returnPoints;

vec3 tmpCoord;

void getCasteljauPoint(int n, std::vector<vec3> points, float t, float min, float max) {

	std::vector<vec3> subTab = points;
	/*
	if (n == 1)
	{
		tmpCoord = points[0];
		newPoints.push_back(tmpCoord);
		std::cout << "X : " << tmpCoord.x << " Y : " << tmpCoord.y <<std::endl;
		return;
	}

	for (int i = 0; i < n - 1; i++)
	{
		float x = t * points[i].x + (1 - t)*points[i + 1].x;
		float y = t * points[i].y + (1 - t)*points[i + 1].y;
		subTab.push_back(vec3(x, y));
	}
	*/
	int s = 0;
	for (int j = 1; j < n; j++) {
		s = j;
		for (int i = 0; i < n - j; i++) {
			float x = ((max - t) / (max - min)) * subTab[i].x + ((t-min) / (max-min))*subTab[i + 1].x;
			float y = ((max - t) / (max - min)) * subTab[i].y + ((t - min) / (max - min))*subTab[i + 1].y;
			subTab[i] = (vec3(x, y, 0));
			//newPoints.push_back(vec3(x, y));

		}
		//newPoints.push_back(subTab[0]);
		//newPoints.push_back(subTab[n-j-1]);
		//newPoints.insert(newPoints.end(), subTab.begin(), subTab.end());
	}
	newPoints.push_back(subTab[0]);
	//newPoints = subTab;

	//getCasteljauPoint(n - 1, subTab, t);
}

std::vector<vec3> Bezier::CasteljauBezier(std::vector<vec3> points, float step, std::vector<int> paramSpace)
{
	//vec3 tmp;
	//newPoints = points;
	//returnPoints = std::vector<vec3>();
	float intistep = step;
	newPoints.clear();
	/*for (int i = 0; i < paramSpace.size()-1; i ++) {
		step = (paramSpace[i + 1] - paramSpace[i]) / intistep;
		for (float t = paramSpace[i]; t <= paramSpace[i + 1]; t += step) {
			getCasteljauPoint(points.size(), points, t, paramSpace[i], paramSpace[i + 1]);
			//returnPoints.push_back(tmp);
		}
	}*/
		step = (paramSpace[1] - paramSpace[0]) / intistep;
		for (float t = paramSpace[0]; t <= paramSpace[1]; t += step) {
			getCasteljauPoint(points.size(), points, t, paramSpace[0], paramSpace[1]);
			//returnPoints.push_back(tmp);
		}
	newPoints.push_back(points[points.size()-1]);
	return newPoints;
}

std::vector<vec3> Bezier::Raccord(int level, std::vector<vec3> points, std::vector<int> paramSpace)
{
	std::vector<vec3> returnPoints = std::vector<vec3>();
	std::vector<vec3> tmp;
	vec3 vect;
	vec3 vect2;
	vec3 vect3;
	switch (level)
	{
	case 0:
		//returnPoints =  (CasteljauBezier(points, step, 0, 1));
		returnPoints.push_back(points[points.size() - 1]);
		break;

	case 1:
		returnPoints.push_back(points[points.size() - 1]);
		// Vecteur
		vect = points[points.size() - 1] - points[points.size() - 2];
		// Normalisation
		vect *= (1.0 / vect.length());
		// Facteur
		//vect *= ((paramSpace[1]- paramSpace[0]) + (paramSpace[2] - paramSpace[1]))/ (paramSpace[1] - paramSpace[0]);
		vect *= (paramSpace[0] + paramSpace[1]) / (paramSpace[0]);
		returnPoints.push_back(points[points.size() - 1] + vect);
		break;
	case 2:
		//n(t)=(1-t)P1+P2
		returnPoints.push_back(points[points.size() - 1]);
		vect = points[points.size() - 1] - points[points.size() - 2];
		//vect *= (1.0 / vect.length());
		vect *= (paramSpace[0] + paramSpace[1]) / paramSpace[0];
		vect = points[points.size() - 1] + vect;
		returnPoints.push_back(vect);
		vect2 = points[points.size() - 2] - points[points.size() - 3];
		vect2 *= (1.0 / vect2.length());
		vect2 *= 2;
		// Point intermediaire
		vect2 = points[points.size() - 2] + vect2;
		vect3 = vect - vect2;
		//vect3 *= (1.0 / vect3.length());
		vect3 *= (paramSpace[0] + paramSpace[1]) / paramSpace[0];
		returnPoints.push_back(vect + vect3);
		break;
	default:
		break;
	}
	return returnPoints;
}


void Bezier::Spline(std::vector<vec3> points, std::vector<float> nodalVec, bool version1)
{
	
	std::vector<vec3> frags = std::vector<vec3>();
	currentCurveObjects = std::vector<std::vector<vec3>>();
	/*
	if (points.size() < 4)
	{
		newCurves[0].controlPoints = points;
		return std::vector<vec3>();
	}
	*/



	frags.push_back(points[0]);
	frags.push_back(points[1]);
	//On va parcourir les points de la courbes sans avoir � couper le premier et le dernier segment
	int nodalindex = 0;
	for (int i = 1; i < points.size() - 2; i++)
	{
		//prend le 2tier et rajoute le premier tiers du suivant :)
		vec3 f((points[i + 1] - points[i]) * 0.667f + points[i]);

		//On met un premier point du segment en cours
		frags.push_back(f);

		vec3 s((points[i + 2] - points[i + 1]) * 0.333f + points[i + 1]);

		//---
		frags.push_back((s - f)*0.333f + f);

		frags.push_back(s);

	}
	frags.push_back(points[points.size()-2]);
	frags.push_back(points[points.size()-1]);

	if(version1)
	for (int i = 0; i < frags.size(); i += 3) {
		std::vector<vec3> temp = std::vector<vec3>();
		if (frags.size() - i - 1 > 3) {
			
			temp.push_back(frags[i]);
			temp.push_back(frags[i+1]);
			temp.push_back(frags[i+2]);
			temp.push_back(frags[i+3]);
			currentCurveObjects.push_back(temp);
		}
		else
		{
			for (int j = i; j < frags.size(); j++) {
				temp.push_back(frags[j]);
			}
			currentCurveObjects.push_back(temp);
		}
	}
	else
	{
		currentCurveObjects.push_back(frags);
	}

	std::cout << "Frags : " << frags.size() << std::endl;

	return;
}

vec3 Bezier::deBoor(int k, int degree, int i, float x, std::vector<float> knots, std::vector<vec3> ctrlPoints)
{

	return vec3();
}

std::vector<vec3> Bezier::simpleExtrude(std::vector<vec3> points, float length, float step, float scale)
{
	last2DCurvePointsCount = points.size();
	std::vector<vec3> newPoints = std::vector<vec3>();
	vec3 bar = getBarycenter(points);

	std::vector<int> indices;
	for (int i = 0; i < points.size()-1; i++) {
		newPoints.push_back(vec3(points[i].x, points[i].z, points[i].y));
		newPoints.push_back(vec3(points[i+1].x, points[i+1].z, points[i+1].y));
		newPoints.push_back(vec3(points[i + 1].x + scale*(points[i + 1].x - bar.x), points[i + 1].z + length, points[i + 1].y + scale*(points[i + 1].y - bar.y)));
		newPoints.push_back(vec3(points[i].x + scale*(points[i].x - bar.x), points[i].z + length, points[i].y + scale*(points[i].y - bar.y)));
	}

	return newPoints;
}

std::vector<vec3> Bezier::revolutionExtrude(std::vector<vec3> points, float step, float radius)
{
	std::vector<vec3> newPoints = std::vector<vec3>();
	vector<int> indices;
	for (int i = 0; i < points.size()-1; i++) {
		for (float j = 0; j < 2 * PI - step; j += step) {
			if (j > 0) {
				newPoints.push_back(vec3(points[i].x * cos(j), points[i].x*sin(j), points[i].y));
				newPoints.push_back(vec3(points[i + 1].x * cos(j), points[i + 1].x*sin(j), points[i + 1].y));
				newPoints.push_back(vec3(points[i + 1].x * cos(j+step), points[i + 1].x*sin(j+step), points[i + 1].y));
				newPoints.push_back(vec3(points[i].x * cos(j+step), points[i].x*sin(j+step), points[i].y));
			}
			else {
				newPoints.push_back(vec3(points[i].x, points[i].z, points[i].y));
				newPoints.push_back(vec3(points[i + 1].x, points[i + 1].z, points[i + 1].y));
				newPoints.push_back(vec3(points[i + 1].x * cos(j), points[i + 1].x*sin(j), points[i + 1].y));
				newPoints.push_back(vec3(points[i].x * cos(j), points[i].x*sin(j), points[i].y));
			}
			
			
		}
	}

	return newPoints;
}

std::vector<vec3> Bezier::generalExtrude(std::vector<vec3> points, std::vector<vec3> linePoints, float step)
{
	std::vector<vec3> newPoints;
	vec3 vecTotal = vec3(0,0,0);

	std::vector<int> indices; //indices en Quad

	for (int i = 0; i < points.size()-1; i++) {
		//linePoints[i] += difference;
		for (int j = 0; j < linePoints.size()-1; j++) {
			
			if (j < 1) {
				//
				vec3 diff = linePoints[j + 1] - linePoints[j];
				newPoints.push_back(vec3(points[i].x, points[i].z, points[i].y));

				newPoints.push_back(vec3(points[i].x+diff.x, points[i].z+diff.z, points[i].y+diff.z));

				newPoints.push_back(vec3(points[i + 1].x+ diff.x, points[i + 1].z+ diff.z, points[i + 1].y+ diff.y));

				newPoints.push_back(vec3(points[i+1].x, points[i+1].z, points[i+1].y));
				
			}
			else {

				vec3 diff = linePoints[j] - linePoints[j-1];
				vec3 secDiff = linePoints[j+1] - linePoints[j];

				//std::cout << linePoints[i].x << ";" << linePoints[i].y << ";" << linePoints[i].z << std::endl;

				newPoints.push_back(vec3(points[i].x+diff.x, points[i].z+ diff.z, points[i].y+ diff.y));

				newPoints.push_back(vec3(points[i].x + secDiff.x, points[i].z + secDiff.z, points[i].y + secDiff.y));

				newPoints.push_back(vec3(points[i + 1].x + secDiff.x, points[i + 1].z + secDiff.z, points[i + 1].y + secDiff.y));

				newPoints.push_back(vec3(points[i+1].x + diff.x, points[i+1].z + diff.z, points[i+1].y + diff.y));
			}
	
			
		}
		
	}

	return newPoints;
}

std::vector<vec3> Bezier::getFirstPointsFromSimpleExtrude(std::vector<vec3> points, float length, float step, float scale)
{
	std::vector<vec3> res = std::vector<vec3>();
	//res.push_back(getBarycenter[points]); //envoie le barycentre si besoin
	res.push_back(points[0]);
	res.push_back(points[points.size() - 1]);
	return res;
}

std::vector<vec3> Bezier::getLastPointsFromSimpleExtrude(std::vector<vec3> points, float length, float step, float scale)
{
	/*std::vector<vec3> res = std::vector<vec3>();
	//res.push_back(getBarycenter[points]); //envoie le barycentre si besoin
	res.push_back(vec3(points[0].x, points[0].z+length, points[0].y));
	res.push_back(vec3(points[points.size() - 1].x, points[points.size() - 1].z+length, points[points.size() - 1].y));
	return res;*/

	last2DCurvePointsCount = points.size();
	std::vector<vec3> newPoints = std::vector<vec3>();
	vec3 bar = getBarycenter(points);
	std::vector<vec3> s = std::vector<vec3>();
	for (int i = 0; i < points.size() - 1; i++) {
		s.push_back(vec3(points[i + 1].x + scale*(points[i + 1].x - bar.x), points[i + 1].z + length, points[i + 1].y + scale*(points[i + 1].y - bar.y)));
		s.push_back(vec3(points[i].x + scale*(points[i].x - bar.x), points[i].z + length, points[i].y + scale*(points[i].y - bar.y)));
	}
	newPoints.push_back(getBarycenter(s));
	std::vector<int> indices;
	for (int i = 0; i < points.size() - 1; i++) {
		newPoints.push_back(vec3(points[i].x + scale*(points[i].x - bar.x), points[i].z + length, points[i].y + scale*(points[i].y - bar.y)));
		newPoints.push_back(vec3(points[i + 1].x + scale*(points[i + 1].x - bar.x), points[i + 1].z + length, points[i + 1].y + scale*(points[i + 1].y - bar.y)));
	}

	return newPoints;
}

std::vector<vec3> Bezier::getFirstPointsFromRevolutionExtrude(std::vector<vec3> points, float step)
{
	std::vector<vec3> res = std::vector<vec3>();
	for (int j = 0; j < 2 * PI; j += step) {
		newPoints.push_back(vec3(points[0].x * cos(j + step), points[0].x*sin(j + step), points[0].y));
	}
	return res;
}

std::vector<vec3> Bezier::getLastPointsFromRevolutionExtrude(std::vector<vec3> points, float step)
{
	std::vector<vec3> res = std::vector<vec3>();
	for (int j = 0; j < 2 * PI; j += step) {
		newPoints.push_back(vec3(points[points.size()-1].x * cos(j + step), points[points.size() - 1].x*sin(j + step), points[points.size() - 1].y));
	}
	return res;
}

vec3 Bezier::getBarycenter(std::vector<vec3> points)
{
	vec3 vecTotal;
	for (int i = 0; i < points.size(); i++) {
		vecTotal.x += points[i].x;
		vecTotal.y += points[i].y;
		vecTotal.z += points[i].z;
	}
	vecTotal /= points.size();
	return vecTotal;
}
