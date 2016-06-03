#pragma once
#include "libs\glm\glm.hpp"
#include <vector>
#include <iostream>
#include "Draw.h"

using namespace glm;

class Bezier
{
private:
	std::vector<vec3> controlPoints;

public:
	Bezier();
	~Bezier();

	std::vector<std::vector<vec3>> currentCurveObjects;

	std::vector<vec3> GetControlPoints() const;
	std::vector<vec3> Curve(float step, float min, float max, vec3 p1, vec3 p2, vec3 p3, vec3 p4);
	vec3 Casteljau(std::vector<vec3> points, float step);
	//std::vector<vec3> Spline(float step, float min, float max, vec3 p1, vec3 p2, vec3 p3, vec3 p4);
	//std::vector<vec3> CasteljauBezier(std::vector<vec3> points, float step, float min, float max);
	std::vector<vec3> CasteljauBezier(std::vector<vec3> points, float step, std::vector<int> paramSpace);

	//Raccordements avec des niveau allant de 0 à 2 C0, C1, C2
	//std::vector<vec3> Raccord(int level, std::vector<vec3> points, float r0, float r1, float step);
	std::vector<vec3> Bezier::Raccord(int level, std::vector<vec3> points, std::vector<int> paramSpace);

	void Spline(std::vector<vec3> points, std::vector<float> nodalVec, bool version1);

	vec3 deBoor(int k, int degree, int i, float x, std::vector<float> knots, std::vector<vec3> ctrlPoints);
};

