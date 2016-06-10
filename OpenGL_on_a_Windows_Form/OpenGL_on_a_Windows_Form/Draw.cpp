#pragma once

#include "stdafx.h"

#include "SOIL.h"
// C, standard, dio
#include <cstdio>
// C, standard, int
#include <cstdint>
#include <stdlib.h>
#include <GL/glut.h>
#include <gl\glu.h>	
#include <iostream>
#include "libs\glm\glm.hpp"

// Pour les fonctions
#include "Draw.h"
#include "Bezier.h"

using namespace std;

#using <System.Windows.Forms.dll>
using namespace System::Windows::Forms;

#define PI 3.14159265

typedef GLfloat color[3];

// Pour les tableaux
#include <vector>

// Enregistre les coordonnées de la souris
GLint mousex;
GLint mousey;
GLint oldMousex;
GLint oldMousey;

// Enregistre la taille de la fenêtre
GLint Win;

// Index du mode pour le traçage des formes
int indexPolyMode = 3;
// Index du mode général
int mode; // 1 = Poly
bool modifying = false;
int indexOfModifyingPoly = 0;
int indexOfModifyingPoint = 0;
int modifyingMode = 0;

int modifyingMode2 = 0;
int indexOfModifyingPoly2 = 0;
vector<int> indexOfModifyingSpline;
vector<int> indexOfModifyingSplinePoint;

vector<int> currentParameterSpace;

bool leftButtonPressed = false;
bool leftButtonRealPressed = false;

//B Curve ArrayPoint
vector<CurveObject> curves;

int currentCurve = 0;

//Couleur selectionnée pour les formes
vector<int>polyColor = { 1 };

float x1, x2, x3, x4, y5, y2, y3, y4;
bool pointSelected = false;
bool showCredits;
bool showParam;

// Pas
int nStep = 20;

// Dimmension du repère de la fenêtre
int hmax = 800, vmax = 600, hmin = 0, vmin = 0;

// Définition de la couleur de remplissager
color redColor = { 1.0f, 0.0f, 0.0f };
color blueColor = { 0.0f, 0.0f, 1.0f };
color greenColor = { 0.0f, 1.0f, 0.0f };
color blackColor = { 0.0f, 0.0f, 0.0f };
color purpleColor = { 0.75f, 0.0f, 0.75f };

Bezier b = Bezier();

vector<glm::vec3> casPoints = vector<glm::vec3>();



float tMatrix[16] = { 1,0,0,10, 0,1,0,10, 0,0,1,10, 0,0,0,10 };
float ntMatrix[16] = { 1,0,0,-10, 0,1,0,-10, 0,0,1,-10, 0,0,0,-10 };
float rMatrix[16] = { cos(1 * PI / 180.0),-sin(1 * PI / 180.0),0,0, sin(1 * PI / 180.0),cos(1 * PI / 180.0),0,0, 0,0,1,0, 0,0,0,1 };
float nrMatrix[16] = { cos(-1 * PI / 180.0), -sin(-1 * PI / 180.0),0,0, sin(-1 * PI / 180.0),cos(-1 * PI / 180.0),0,0, 0,0,1,0, 0,0,0,1 };
float sMatrix[16] = { 1.1,0,0,0, 0,1.1,0,0, 0,0,1.1,0, 0,0,0,0 };
float nsMatrix[16] = { 0.9,0,0,0, 0,0.9,0,0, 0,0,0.9,0, 0,0,0,0 };
float cMatrix[16] = { 1,0.5f,0,0, 0.5f,1,0,0, 0,0,1,0, 0,0,0,0 };
float ncMatrix[16] = { 1,-0.5f,0,0, -0.5f,1,0,0, 0,0,1,0, 0,0,0,0 };

int modifierType = 0;

int index = 0;

int w = 800, h = 600;
bool alreadyInit = false;
bool alreadyLoadTextures = false;

int rotLight1 = 0;

GLuint ListeTextures[4];

int renderType = 0, textureIndex = 0;

double extrudeSimpleScale=0.5;
double extrudeSimpleLenght=1.0;

int extrudeType = 0;

void setDim(int _w, int _h) {
	w = _w;
	h = _h;
}

void Initialize()
{
	/*//std::cout << sin(1);
	std::cout << sin(1.0);
	glClearColor(1.0, 0.984, 0.906, 0.961);
	glColor3f(0.0f, 0.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0.0, (GLdouble)800,
	(GLdouble)600, 0.0);*/

	//polyColor.push_back(2);

	glColor3f(0.0f, 0.0f, 1.0f);
	// Taille des points
	glPointSize(7.0);

	if (alreadyInit == false) {

		CurveObject firstPoly;
		curves.push_back(firstPoly);

		currentParameterSpace.push_back(index++);

		modifying = true;

		polyMade_menu(1);

		mode = 1;
		/*if (curves[currentCurve].paramPoints.size() < 2) {
			curves[currentCurve].paramPoints.clear();
			curves[currentCurve].paramPoints.push_back(1);
			curves[currentCurve].paramPoints.push_back(1);
		}
		if (curves.size() != 0) {
			if (curves[currentCurve].controlPoints.size() > 3) {
				CurveObject tmpPoly;
				curves.push_back(tmpPoly);
				polyColor.push_back(2);
				currentCurve++;
			}
			else
			{
				curves[currentCurve].controlPoints.clear();
				curves[currentCurve].controlPoints.clear();
			}
		}*/

		if (alreadyLoadTextures == false) {
			// Chargement des textures
			ListeTextures[0] = SOIL_load_OGL_texture("tex1.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
			ListeTextures[1] = SOIL_load_OGL_texture("tex2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
			ListeTextures[2] = SOIL_load_OGL_texture("tex3.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
			ListeTextures[3] = SOIL_load_OGL_texture("tex4.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

			alreadyLoadTextures = true;
		}

		UpdateCam();

		curves[currentCurve].drawPoints.push_back(vec3(0.0f, 0.0f, 0.0f));
		curves[currentCurve].drawPoints.push_back(vec3(0.0f, 0.0f, 1));
		curves[currentCurve].drawPoints.push_back(vec3(0.0f, 1, 1));
		curves[currentCurve].drawPoints.push_back(vec3(0.0f, 1, 0.0f));
		curves[currentCurve].drawPoints.push_back(vec3(0.0f, 0.0f, 1.0f));
		curves[currentCurve].drawPoints.push_back(vec3(0.0f, 0.0f, 2));
		curves[currentCurve].drawPoints.push_back(vec3(0.0f, 1, 2));
		curves[currentCurve].drawPoints.push_back(vec3(0.0f, 1, 1.0f));

		curves[currentCurve].texCoordsPoints.push_back(vec2(0.0f, 0.0f));
		curves[currentCurve].texCoordsPoints.push_back(vec2(1.0f, 0.0f));
		curves[currentCurve].texCoordsPoints.push_back(vec2(1.0f, 1.0f));
		curves[currentCurve].texCoordsPoints.push_back(vec2(0.0f, 1.0f));

		alreadyInit = true;
	}
	std::cout << mode << " mode" << "\n";
}

// Rendu des formes dans la fenêtre
void DrawRender()
{
	// Nettoyage de la fenêtre
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// On trace le poly en fonction du mode de traçage choisi
	switch (indexPolyMode) {
	case 3:
		for (int p = 0; p < curves.size(); p++)
		{
			if (curves[p].controlPoints.size() >= 4) {
				curves[p].curvePoints = b.CasteljauBezier(curves[p].controlPoints, nStep, currentParameterSpace);
				if (extrudeType == 0) {
					curves[p].drawPoints = b.simpleExtrude(curves[p].curvePoints, extrudeSimpleLenght, 1, extrudeSimpleScale);
					for (size_t i = 0; i < curves[p].drawPoints.size(); i++)
					{
						curves[p].texCoordsPoints.push_back(vec2(curves[p].drawPoints[i].x, curves[p].drawPoints[i].y));
					}
				}else if (extrudeType == 1) {
					curves[p].drawPoints = b.revolutionExtrude(curves[p].curvePoints, 0.1f, 3);
				}
				else
				{
					if(curves[p].soulPoints.size() > 0)
						curves[p].drawPoints = b.generalExtrude(curves[p].curvePoints, curves[p].soulPoints, 1);
				}
			}

			if (curves[p].soulControlPoints.size() >= 4) {
				curves[p].soulPoints = b.CasteljauBezier(curves[p].soulControlPoints, nStep, currentParameterSpace);
			}

			glColor3f(0.0f, 0.0f, 0.7f);
			glLoadIdentity();
			glBegin(GL_POINTS);
			for (int i = 0; i < curves[p].controlPoints.size(); i++) {
				glVertex3d(curves[p].controlPoints[i].x, curves[p].controlPoints[i].z, curves[p].controlPoints[i].y);
			}
			glEnd();
			glLoadIdentity();
			glBegin(GL_LINE_STRIP);//POINTS
			for (int i = 0; i < curves[p].controlPoints.size(); i++) {
				glVertex3d(curves[p].controlPoints[i].x, curves[p].controlPoints[i].z, curves[p].controlPoints[i].y);
			}
			glEnd();

			glColor3f(0.0f, 0.0f, 0.2f);
			// Soul
			glLoadIdentity();
			glBegin(GL_POINTS);
			for (int i = 0; i < curves[p].soulControlPoints.size(); i++) {
				glVertex3d(curves[p].soulControlPoints[i].x, curves[p].soulControlPoints[i].z, curves[p].soulControlPoints[i].y);
			}
			glEnd();
			glLoadIdentity();
			glBegin(GL_LINE_STRIP);//POINTS
			for (int i = 0; i < curves[p].soulControlPoints.size(); i++) {
				glVertex3d(curves[p].soulControlPoints[i].x, curves[p].soulControlPoints[i].z, curves[p].soulControlPoints[i].y);
			}
			glEnd();

			// On choisi la couleur du poly
			switch (polyColor[p]) {
			case 1:
				glColor3fv(redColor);
				break;
			case 2:
				glColor3fv(blueColor);
				break;
			case 3:
				glColor3fv(greenColor);
				break;
			case 4:
				glColor3fv(blackColor);
				break;
			case 5:
				glColor3fv(purpleColor);
				break;
			}
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < curves[p].curvePoints.size(); i++) {
				glVertex3d(curves[p].curvePoints[i].x, 0, curves[p].curvePoints[i].y);
			}
			glEnd();


			if (curves[p].splineCurvePoints.size() == 0) {
				for (int i = 0; i < curves[p].splineControlPoints.size(); i++) {
					curves[p].splineCurvePoints.push_back(b.CasteljauBezier(curves[p].splineControlPoints[i], nStep, currentParameterSpace));
				}
			}
			else
			{
				for (int i = 0; i < curves[p].splineControlPoints.size(); i++) {
					curves[p].splineCurvePoints[i] = b.CasteljauBezier(curves[p].splineControlPoints[i], nStep, currentParameterSpace);
				}
			}

			glColor3fv(greenColor);
			for (int i = 0; i < curves[p].splineControlPoints.size(); i++) {
				glBegin(GL_POINTS);
				for (int j = 0; j < curves[p].splineControlPoints[i].size(); j++) {
					glVertex3d(curves[p].splineControlPoints[i][j].x, 0, curves[p].splineControlPoints[i][j].y);
				}
				glEnd();
			}

			for (int i = 0; i < curves[p].splineCurvePoints.size(); i++) {
				glBegin(GL_LINE_STRIP);
				for (int j = 0; j < curves[p].splineCurvePoints[i].size(); j++) {
					glVertex3d(curves[p].splineCurvePoints[i][j].x, 0, curves[p].splineCurvePoints[i][j].y);
				}
				glEnd();
			}

			// Soul
			glColor3fv(purpleColor);
			glBegin(GL_LINE_STRIP);
			for (int i = 0; i < curves[p].soulPoints.size(); i++) {
				glVertex3d(curves[p].soulPoints[i].x, 0, curves[p].soulPoints[i].y);
			}
			glEnd();
		}
		break;

	default:
		break;
	}

	///// Lumières
	// Pour parametrer nos objets
	GLUquadric* params = gluNewQuadric();
	// Supporte les textures
	gluQuadricTexture(params, GL_TRUE);
	//Positionnement de la lumiere avec les differents param?tres
	glEnable(GL_LIGHTING);

	// Parametre de la lumiere d'environnement
	GLfloat global[] = { 0.5f,0.5f,0.5f,1.0f };
	// Lumiere globale
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global);
	//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	glPushMatrix();
	// Light 1
	rotLight1 += 1;
	// Mouvement de la light
	glRotated(rotLight1, 0.0, 0.0, 0.0);
	// Parametres
	GLfloat bleu[4] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat bleuSpecular[4] = { 0.0, 1.0, 0.5, 0.5 };
	GLfloat light1_position[] = { 2.0f, 8.0f, 2.0f, 0.0f };
	glLightfv(GL_LIGHT1, GL_AMBIENT, bleu);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, bleu);
	glLightfv(GL_LIGHT1, GL_SPECULAR, bleuSpecular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	// Parametres du spot
	GLfloat pos1[3] = { 0.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, pos1);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 90.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 30);
	glEnable(GL_LIGHT1);
	glPopMatrix();
	glPushMatrix();
	// Light 2
	glRotated(rotLight1 + 120, 0.0, 0.0, 0.0);
	GLfloat green[4] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat greenSpecular[4] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat light2_position[] = { 2.0f, 8.0f, 2.0f, 0.0f };
	glLightfv(GL_LIGHT2, GL_AMBIENT, green);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, green);
	glLightfv(GL_LIGHT2, GL_SPECULAR, greenSpecular);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	GLfloat pos2[3] = { 0.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, pos2);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 90.0);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 30);
	glEnable(GL_LIGHT2);
	glPopMatrix();
	glPushMatrix();
	// Light 3
	glRotated(rotLight1 + 240, 0.0, 0.0, 0.0);
	GLfloat red[4] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat redSpecular[4] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat light3_position[] = { 2.0f, 8.0f, 2.0f, 0.0f };
	glLightfv(GL_LIGHT3, GL_AMBIENT, red);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, red);
	glLightfv(GL_LIGHT3, GL_SPECULAR, redSpecular);
	glLightfv(GL_LIGHT3, GL_POSITION, light3_position);
	GLfloat pos3[3] = { 0.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, pos3);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 90.0);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 30);
	glEnable(GL_LIGHT3);
	glPopMatrix();

	//GL_FRONT_AND_BACK
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat low_shininess[] = { 5.0 };
	GLfloat high_shininess[] = { 100.0 };
	GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

	// Activation de material couleur
	if (renderType == 1) {
		//glEnable(GL_COLOR_MATERIAL);
		//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	}

	if (renderType == 1) {
		glBegin(GL_QUADS);
		for (int i = 0; i < curves[currentCurve].drawPoints.size(); i++) {
				glVertex3f(curves[currentCurve].drawPoints[i].x, curves[currentCurve].drawPoints[i].y, curves[currentCurve].drawPoints[i].z);
		}
		glEnd();
	}

	if (renderType == 2) {
		glDisable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ListeTextures[textureIndex]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		for (int i = 0; i < curves[currentCurve].drawPoints.size() && i < curves[currentCurve].texCoordsPoints.size(); i++) {
			glTexCoord2f(curves[currentCurve].texCoordsPoints[i].x, curves[currentCurve].texCoordsPoints[i].y);
			glVertex3f(curves[currentCurve].drawPoints[i].x, curves[currentCurve].drawPoints[i].y, curves[currentCurve].drawPoints[i].z);
		}
		glEnd();
	}

	if (renderType == 0) {
		//On se met en mode ligne (edge)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// On va dessinner de la couleur suivante
		glColor3f(0.0f, 1.0f, 0.0f);
		// Avec cette epaisseur de trait
		glLineWidth(2.0f);
		glBegin(GL_QUADS);
		for (int i = 0; i < curves[currentCurve].drawPoints.size(); i++) {
				glVertex3f(curves[currentCurve].drawPoints[i].x, curves[currentCurve].drawPoints[i].y, curves[currentCurve].drawPoints[i].z);
		}
		glEnd();
		/*if (curves[currentCurve].curvePoints.size() > 4) {
			std::vector<vec3> res = std::vector<vec3>();
			res = b.getLastPointsFromSimpleExtrude(curves[currentCurve].curvePoints, extrudeSimpleLenght, 1, extrudeSimpleScale);
			//curves[p].drawPoints = b.simpleExtrude(curves[p].curvePoints, extrudeSimpleLenght, 1, extrudeSimpleScale);
			glBegin(GL_TRIANGLE_FAN); {
				for (int i = 0; i < res.size(); i++) {
					glVertex3f(res[i].x, res[i].y, res[i].z);
				}
			}
			glEnd();
		}*/

		glLineWidth(1.0f);
		//glDisable(GL_POLYGON_OFFSET_LINE);
		// On passe en mode face
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//glEnable(GL_POLYGON_OFFSET_FILL);
		//glPolygonOffset(1.0f, 1.0f);
	}

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glFlush();
}

// Fonction d'evenements à la souris
void _mouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	//Si on effectue un clic gauche
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		mousex = e->X;
		mousey = e->Y;
		vec3 tmpPoint;
		tmpPoint.x = ((float)mousex - w / 2) / 150;
		tmpPoint.y = ((float)mousey - h / 2) / 150;
		tmpPoint.z = 0;
		//std::cout << e->X << " " << e->Y << " " << tmpPoint.x << " " << tmpPoint.y << "\n";
		if (mode == 1) {
				if (curves[currentCurve].controlPoints.size() > 2 && sqrt((((float)e->X - w / 2) / 150 - curves[currentCurve].controlPoints[0].x)*(((float)e->X - w / 2) / 150 - curves[currentCurve].controlPoints[0].x) + (((float)e->Y - h / 2) / 150 - curves[currentCurve].controlPoints[0].y)*(((float)e->Y - h / 2) / 150 - curves[currentCurve].controlPoints[0].y)) < 0.1) {
					tmpPoint.x = curves[currentCurve].controlPoints[0].x;
					tmpPoint.y = curves[currentCurve].controlPoints[0].y;
					curves[currentCurve].controlPoints.push_back(tmpPoint);
					currentParameterSpace.push_back(index += 10);
					CurveObject tmpPoly;
					tmpPoly.controlPoints = b.Raccord(1, curves[currentCurve].controlPoints, curves[currentCurve].paramPoints);
					curves[currentCurve].controlPoints[1].x = tmpPoly.controlPoints[1].x;
					curves[currentCurve].controlPoints[1].y = tmpPoly.controlPoints[1].y;
					//polyMade_menu(1);
				}
				else {
					curves[currentCurve].controlPoints.push_back(tmpPoint);
					if (currentParameterSpace.size() < curves[currentCurve].controlPoints.size())
						currentParameterSpace.push_back(index += 10);
					//curves[currentCurve].paramPoints.push_back()
				}
		}
		else if (mode == 2) {
			curves[currentCurve].soulControlPoints.push_back(tmpPoint);
			if(currentParameterSpace.size() < curves[currentCurve].soulControlPoints.size())
				currentParameterSpace.push_back(index += 10);
		}

		leftButtonPressed = false;
	}

	if (e->Button == System::Windows::Forms::MouseButtons::Right)

	{
		leftButtonPressed = false;
		leftButtonRealPressed = false;
	}
}

void _mouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		indexOfModifyingPoly = 0;
		indexOfModifyingPoint = 0;
		modifyingMode = 0;

		modifyingMode2 = 0;
		indexOfModifyingPoly2 = 0;
		indexOfModifyingSpline.clear();
		indexOfModifyingSplinePoint.clear();

		for (int p = 0; p < curves.size(); p++)
		{
			for (unsigned int i = 0; i < curves[p].controlPoints.size(); i++) {
				if (sqrt((((float)e->X - w / 2) / 150 - curves[p].controlPoints[i].x)*(((float)e->X - w / 2) / 150 - curves[p].controlPoints[i].x) + (((float)e->Y - h / 2) / 150 - curves[p].controlPoints[i].y)*(((float)e->Y - h / 2) / 150 - curves[p].controlPoints[i].y)) < 0.1) {
					indexOfModifyingPoly = p;
					indexOfModifyingPoint = i;
					modifyingMode = 1;
					leftButtonPressed = true;
					break;
				}
			}
			if (indexOfModifyingPoly != 0)
				break;
		}
		for (int p = 0; p < curves.size(); p++)
		{
			for (unsigned int i = 0; i < curves[p].splineControlPoints.size(); i++) {
				for (unsigned int j = 0; j < curves[p].splineControlPoints[i].size(); j++) {
					if (sqrt((((float)e->X - w / 2) / 150 - curves[p].splineControlPoints[i][j].x)*(((float)e->X - w / 2) / 150 - curves[p].splineControlPoints[i][j].x) + (((float)e->Y - h / 2) / 150 - curves[p].splineControlPoints[i][j].y)*(((float)e->Y - h / 2) / 150 - curves[p].splineControlPoints[i][j].y)) < 0.1) {
						indexOfModifyingPoly2 = p;
						indexOfModifyingSpline.push_back(i);
						indexOfModifyingSplinePoint.push_back(j);
						modifyingMode2 = 1;
						leftButtonPressed = true;
						break;
					}
				}
			}
		}
		for (int p = 0; p < curves.size(); p++)
		{
			for (unsigned int i = 0; i < curves[p].soulControlPoints.size(); i++) {
				if (sqrt((((float)e->X - w / 2) / 150 - curves[p].soulControlPoints[i].x)*(((float)e->X - w / 2) / 150 - curves[p].soulControlPoints[i].x) + (((float)e->Y - h / 2) / 150 - curves[p].soulControlPoints[i].y)*(((float)e->Y - h / 2) / 150 - curves[p].soulControlPoints[i].y)) < 0.1) {
					indexOfModifyingPoly = p;
					indexOfModifyingPoint = i;
					modifyingMode = 2;
					leftButtonPressed = true;
					break;
				}
			}
		}
	}
	if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		leftButtonRealPressed = true;
	}
}

void mouseMotion(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (modifying && leftButtonPressed) {
		if (modifyingMode == 1) {
			curves[indexOfModifyingPoly].controlPoints[indexOfModifyingPoint].x = ((float)e->X - w / 2) / 150;
			curves[indexOfModifyingPoly].controlPoints[indexOfModifyingPoint].y = ((float)e->Y - h / 2) / 150;
		}
		if (modifyingMode2 == 1) {
			for (unsigned int i = 0; i < indexOfModifyingSpline.size(); i++) {
				curves[indexOfModifyingPoly2].splineControlPoints[indexOfModifyingSpline[i]][indexOfModifyingSplinePoint[i]].x = ((float)e->X - w / 2) / 150;
				curves[indexOfModifyingPoly2].splineControlPoints[indexOfModifyingSpline[i]][indexOfModifyingSplinePoint[i]].y = ((float)e->Y - h / 2) / 150;
			}
		}
		// Soul
		if (modifyingMode == 2) {
			curves[indexOfModifyingPoly].soulControlPoints[indexOfModifyingPoint].x = ((float)e->X - w / 2) / 150;
			curves[indexOfModifyingPoly].soulControlPoints[indexOfModifyingPoint].y = ((float)e->Y - h / 2) / 150;
		}
	}

	if (leftButtonRealPressed) {

		// these lines limit the camera's range
		/*if (mouseY < 200)
			mouseY = 200;
		if (mouseY > 450)
			mouseY = 450;*/

		if (e->Y != oldMousey) {
			draw::camera_y = sin(draw::camAngle);
			//draw::camera_z = cos(draw::camAngle);
			draw::y_direction = -sin(draw::camAngle);
			//draw::z_direction = -cos(draw::camAngle);

			if ((e->Y - oldMousey) > 0)             // mouse moved to the right
				draw::camAngle += 0.01f;
			else if ((e->Y - oldMousey) < 0)     // mouse moved to the left
				draw::camAngle -= 0.01f;
		}
		if (e->X != oldMousex)
		{
			draw::camera_x = cos(draw::camAngle);
			draw::camera_z = sin(draw::camAngle);
			draw::x_direction = -cos(draw::camAngle);
			draw::z_direction = -sin(draw::camAngle);

			if ((e->X - oldMousex) > 0)             // mouse moved to the right
			draw::camAngle += 0.01f;
			else if ((e->X - oldMousex) < 0)     // mouse moved to the left
			draw::camAngle -= 0.01f;

		}

		oldMousex = e->X;
		oldMousey = e->Y;

		UpdateCam();
	}
}

void _mouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	cout << draw::zoom << endl;
	if(draw::camera_y * (draw::zoom + -e->Delta * SystemInformation::MouseWheelScrollLines / 120 / 2) > 0)
		draw::zoom += -e->Delta * SystemInformation::MouseWheelScrollLines / 120 /2;
	UpdateCam();
}

void UpdateCam() {

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	gluPerspective(45.0f, (GLfloat)600 / (GLfloat)600, 0.1f, 100.0f);

	gluLookAt(draw::camera_x * draw::zoom, draw::camera_y * draw::zoom, draw::camera_z * draw::zoom, 
		draw::x_direction, draw::y_direction, draw::z_direction, 0.0, 1.0, 0.0);


	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();
}

// Procédés appelés au clavier
void keyboard(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	vector<CurveObject> splineParts;
	Bezier bez;
	// En fonction de la touche
	switch (e->KeyCode) {
		// On change la couleur de fond
	case System::Windows::Forms::Keys::A:
		glClearColor(1.0, 0.984, 0.906, 0.961);
		std::cout << "clear";
		break;
		// On change la couleur de fond
	case System::Windows::Forms::Keys::B:
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		std::cout << "clear";
		break;
		// On quitte l'application avec la touche echap
	case System::Windows::Forms::Keys::Escape:
		//glutDestroyWindow(Win);
		break;
	case System::Windows::Forms::Keys::Space:
		//confirmer la spline
		bez.Spline(curves[currentCurve].controlPoints, vector<float>(), true);
		//curves.pop_back();
		//currentCurve--;
		curves[currentCurve].splineControlPoints = bez.currentCurveObjects;
		for (int i = 0; i < bez.currentCurveObjects.size(); i++) {
			/*currentCurve++;
			curves.push_back(CurveObject());
			polyColor.push_back(2);
			curves[curves.size() - 1].controlPoints = bez.currentCurveObjects[i];*/
			//curves[currentCurve].splinePoints.push_back(bez.currentCurveObjects[i]);
		}
		break;
		// On zoom avec le + du pavé numérique
	case System::Windows::Forms::Keys::Add:
		nStep += 1;
		break;

		// On dé-zoom avec le - du pavé numérique
	case System::Windows::Forms::Keys::Subtract:
		if (nStep > 1)
			nStep -= 1;
		break;
	default:
		break;
	}


	int _x = 0;
	int _y = 0;

	// En fonction de la touche
	switch (e->KeyCode) {
	case System::Windows::Forms::Keys::Up:    // key up
		switch (modifierType)
		{
		case 1:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].y = ntMatrix[4] * _y + ntMatrix[5] * _y + ntMatrix[6] * _y + ntMatrix[7];
				}
			}
			break;
		case 4:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].y = ncMatrix[4] * _x + ncMatrix[5] * _y + ncMatrix[6] * _y + ncMatrix[7];
				}
			}
			break;
		}
		break;
	case System::Windows::Forms::Keys::Down:    // key down
		switch (modifierType)
		{
		case 1:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].y = tMatrix[4] * _y + tMatrix[5] * _y + tMatrix[6] * _y + tMatrix[7];
				}
			}
			break;
		case 4:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].y = cMatrix[4] * _x + cMatrix[5] * _y + cMatrix[6] * _y + cMatrix[7];
				}
			}
			break;
		}
		break;
	case System::Windows::Forms::Keys::Right:    // key right
		switch (modifierType)
		{
		case 1:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					curves[p].controlPoints[i].x = tMatrix[0] * _x + tMatrix[1] * _x + tMatrix[2] * _x + tMatrix[3];

				}
			}
			break;
		case 2:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].x = rMatrix[0] * _x + rMatrix[1] * _y + rMatrix[3];
					curves[p].controlPoints[i].y = rMatrix[4] * _x + rMatrix[5] * _y + rMatrix[7];
				}
			}
			break;
		case 3:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					curves[p].controlPoints[i].x = sMatrix[0] * _x + sMatrix[1] * _x + sMatrix[2] * _x + sMatrix[3];
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].y = sMatrix[4] * _y + sMatrix[5] * _y + sMatrix[6] * _y + sMatrix[7];
				}
			}
			break;
		case 4:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].x = cMatrix[0] * _x + cMatrix[1] * _y + cMatrix[2] * _x + cMatrix[3];
				}
			}
			break;
		}
		break;
	case System::Windows::Forms::Keys::Left:    // key left
		switch (modifierType)
		{
		case 1:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					curves[p].controlPoints[i].x = ntMatrix[0] * _x + ntMatrix[1] * _x + ntMatrix[2] * _x + ntMatrix[3];

				}
			}
			break;
		case 2:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].x = nrMatrix[0] * _x + nrMatrix[1] * _y + nrMatrix[3];
					curves[p].controlPoints[i].y = nrMatrix[4] * _x + nrMatrix[5] * _y + nrMatrix[7];
				}
			}
			break;
		case 3:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					curves[p].controlPoints[i].x = nsMatrix[0] * _x + nsMatrix[1] * _x + nsMatrix[2] * _x + nsMatrix[3];
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].y = nsMatrix[4] * _y + nsMatrix[5] * _y + nsMatrix[6] * _y + nsMatrix[7];
				}
			}
			break;
		case 4:
			for (int p = 0; p < curves.size(); p++)
			{
				for (size_t i = 0; i < curves[p].controlPoints.size(); i++)
				{
					_x = curves[p].controlPoints[i].x;
					_y = curves[p].controlPoints[i].y;
					curves[p].controlPoints[i].x = ncMatrix[0] * _x + ncMatrix[1] * _y + ncMatrix[2] * _x + ncMatrix[3];
				}
			}
			break;
		}
		break;
	default:
		break;
	}
}

// Fonction de menu principal
void processMenuEvents(int option) {
	switch (option) {
		// Bouton qui permet de quitter l'application
	case 0:
		glutDestroyWindow(Win);
		break;
	}
	modifying = false;

	// Demande de le redessin de la fenêtre
	glutPostRedisplay();
}

void mod_menu(int option) {
	switch (option) {
	case 0:
		modifierType = 1;
		break;
	case 1:
		modifierType = 2;
		break;
	case 2:
		modifierType = 3;
		break;
	case 3:
		modifierType = 4;
		break;
	}
	glutPostRedisplay();
}

void prop_menu(int option) {
	vector<CurveObject> splineParts;
	Bezier bez;
	switch (option) {
	case 1:
		glutPostRedisplay();
		curves[currentCurve].paramPoints.clear();
		std::cout << "Entrez a, b, c" << std::endl;
		int a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		curves[currentCurve].paramPoints.push_back(b - a);
		curves[currentCurve].paramPoints.push_back(c - b);
		break;
	case 2:
		bez.Spline(curves[currentCurve].controlPoints, vector<float>(), false);
		curves[currentCurve].splineControlPoints = bez.currentCurveObjects;
		break;
	}
	modifying = false;
	glutPostRedisplay();
}

// Fonction du menu qui permet de changer la couleur de la forme dessinée
void colors_menu(int option) {
	if (polyColor.size() != 0) {
		polyColor[currentCurve] = option;
	}
	else
	{
		polyColor.push_back(option);
	}
}

void render_menu(int option) {
	renderType = option;
}

void textures_menu(int option) {
	textureIndex = option;
}

// Fonction du menu qui permet de changer la nature de la forme dessinée
void polyMade_menu(int option) {
	mode = 1;
	if (curves[currentCurve].paramPoints.size() < 2) {
		curves[currentCurve].paramPoints.clear();
		curves[currentCurve].paramPoints.push_back(1);
		curves[currentCurve].paramPoints.push_back(1);
	}
	switch (option) {
		// Nettoie la fenêtre et les structures
	case 1:
		if (curves.size() != 0) {
			/*if (curves[currentCurve].controlPoints.size() > 3) {
				CurveObject tmpPoly;
				curves.push_back(tmpPoly);
				polyColor.push_back(2);
				currentCurve++;
			}
			else
			{*/
				curves[currentCurve].controlPoints.clear();
				curves[currentCurve].controlPoints.clear();
			//}
			break;
		}
	case 2:
		if (curves.size() != 0) {
			if (curves[currentCurve].controlPoints.size() > 3) {
				CurveObject tmpPoly;
				tmpPoly.controlPoints = b.Raccord(0, curves[currentCurve].controlPoints, curves[currentCurve].paramPoints);
				curves.push_back(tmpPoly);
				polyColor.push_back(2);
				currentCurve++;
			}
		}
		break;
	case 3:
		if (curves.size() != 0) {
			if (curves[currentCurve].controlPoints.size() > 3) {
				CurveObject tmpPoly;
				tmpPoly.controlPoints = b.Raccord(1, curves[currentCurve].controlPoints, curves[currentCurve].paramPoints);
				curves.push_back(tmpPoly);
				polyColor.push_back(2);
				currentCurve++;
			}
		}
		break;
	case 4:
		if (curves.size() != 0) {
			if (curves[currentCurve].controlPoints.size() > 3) {
				CurveObject tmpPoly;
				tmpPoly.controlPoints = b.Raccord(2, curves[currentCurve].controlPoints, curves[currentCurve].paramPoints);
				curves.push_back(tmpPoly);
				polyColor.push_back(2);
				currentCurve++;
			}
		}
		break;
	case 5:
		if (curves.size() != 0) {
			mode = 2;
			//if (curves[currentCurve].soulControlPoints.size() < 3) {
				curves[currentCurve].soulControlPoints.clear();
				curves[currentCurve].soulControlPoints.clear();
			//}
			break;
		}
	}

	//modifying = false;
}

// Menu doption supplémentaires
void option_menu(int option) {
	switch (option) {
		// Nettoie la fenêtre et les structures
	case 1:
		modifying = !modifying;
		mode = 0;
		break;
	case 3:
		for (int p = 0; p < curves.size(); p++)
		{
			curves[p].controlPoints.clear();
			curves[p].curvePoints.clear();
			curves[p].soulControlPoints.clear();
			curves[p].soulPoints.clear();
		}
		curves.clear();
		//currentCurve = 0;
		mode = 0;
		alreadyInit = false;
		Initialize();
		//indexPolyMode = 3;
		break;
		// Affiche les crédits
	case 4:
		showCredits = !showCredits;
		break;
	}
}

void option_lenght(double v) {
	extrudeSimpleLenght = v;
}
void  option_scale(double v) {
	extrudeSimpleScale = v;
}
void  extruder_menu(int v) {
	extrudeType = v;
}

// Initialise le menu
void initMenu() {

	// Index du menu
	int menu;
	// Création du menu
	menu = glutCreateMenu(processMenuEvents);

	// Liste des index des sous menus
	GLint colorsMenu, polyMadeMenu, modMenu, propMenu, optionMenu;

	propMenu = glutCreateMenu(prop_menu);
	glutAddMenuEntry("Espace de paramétrage", 1);
	glutAddMenuEntry("Spline cubique", 2);

	modMenu = glutCreateMenu(mod_menu);
	glutAddMenuEntry("Translation", 0);
	glutAddMenuEntry("Rotation", 1);
	glutAddMenuEntry("Scale", 2);
	glutAddMenuEntry("cisaillement", 3);

	optionMenu = glutCreateMenu(option_menu);
	glutAddMenuEntry("Modifier", 1);
	glutAddMenuEntry("Remise à zero", 3);
	glutAddMenuEntry("Credits", 4);

	glutCreateMenu(processMenuEvents);
	glutAddSubMenu("Colours", colorsMenu);
	glutAddSubMenu("Créer une courbe", polyMadeMenu);
	glutAddSubMenu("Modifier la courbe", modMenu);
	glutAddSubMenu("Propriétés", propMenu);
	glutAddSubMenu("Options", optionMenu);
	glutAddMenuEntry("Quitter", 0);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
