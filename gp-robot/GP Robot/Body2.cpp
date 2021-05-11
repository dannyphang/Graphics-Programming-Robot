#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include "Function.h"
#include "Body2.h"

using namespace N;
using namespace std;
using namespace B2;

function fhb2;

GLenum type4 = GL_LINE_LOOP, gltype4 = GL_POLYGON;
void body2::upperChest() {
	// front top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(378.75, 265, 25);
	fhb2.v3f(356.25, 270, 30);
	fhb2.v3f(443.75, 270, 30);
	fhb2.v3f(421.25, 265, 25);
	glEnd();

	// front btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25, 270, 30);
	fhb2.v3f(340 + 20, 307.5, 50);
	fhb2.v3f(460 - 20, 307.5, 50);
	fhb2.v3f(443.75, 270, 30);
	glEnd();

	// left top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(378.75, 265, -37.5);
	fhb2.v3f(356.25, 270, -42.5);
	fhb2.v3f(356.25, 270, 30);
	fhb2.v3f(378.75, 265, 25);
	glEnd();

	// left btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25, 270, -42.5);
	fhb2.v3f(340, 307.5, -60 + 20);
	fhb2.v3f(340, 307.5, 50 - 20);
	fhb2.v3f(356.25, 270, 30);
	glEnd();

	// right top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(421.25, 265, 25);
	fhb2.v3f(443.75, 270, 30);
	fhb2.v3f(443.75, 270, -42.5);
	fhb2.v3f(421.25, 265, -37.5);
	glEnd();

	// right btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75, 270, -42.5);
	fhb2.v3f(460, 307.5, -60 + 20);
	fhb2.v3f(460, 307.5, 50 - 20);
	fhb2.v3f(443.75, 270, 30);
	glEnd();

	// back top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(378.75, 265, -37.5);
	fhb2.v3f(356.25, 270, -42.5);
	fhb2.v3f(443.75, 270, -42.5);
	fhb2.v3f(421.25, 265, -37.5);
	glEnd();

	// back btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25, 270, -42.5);
	fhb2.v3f(340 + 20, 307.5, -60);
	fhb2.v3f(460 - 20, 307.5, -60);
	fhb2.v3f(443.75, 270, -42.5);
	glEnd();

	// front btm left 
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25, 270, 30);
	fhb2.v3f(340 + 20, 307.5, 50);
	fhb2.v3f(340 + 5, 307.5, 50 - 5);
	glEnd();

	// front btm right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75, 270, 30);
	fhb2.v3f(460 - 20, 307.5, 50);
	fhb2.v3f(460 - 5, 307.5, 50 - 5);
	glEnd();

	// back btm left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25, 270, -42.5);
	fhb2.v3f(340 + 20, 307.5, -60);
	fhb2.v3f(340 + 5, 307.5, -60 + 5);
	glEnd();

	// back btm right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75, 270, -42.5);
	fhb2.v3f(460 - 20, 307.5, -60);
	fhb2.v3f(460 - 5, 307.5, -60 + 5);
	glEnd();

	// left btm left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25, 270, -42.5);
	fhb2.v3f(340, 307.5, -60 + 20);
	fhb2.v3f(340 + 5, 307.5, -60 + 5);
	glEnd();

	// left btm right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25, 270, 30);
	fhb2.v3f(340, 307.5, 50 - 20);
	fhb2.v3f(340 + 5, 307.5, 50 - 5);
	glEnd();

	// right btm right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75, 270, -42.5);
	fhb2.v3f(460, 307.5, -60 + 20);
	fhb2.v3f(460 - 5, 307.5, -60 + 5);
	glEnd();

	// right btm left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75, 270, 30);
	fhb2.v3f(460, 307.5, 50 - 20);
	fhb2.v3f(460 - 5, 307.5, 50 - 5);
	glEnd();
}

void body2::lowerChest() {
	// front top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(340 + 20, 307.5, 50);
	fhb2.v3f(343.75 + 20, 327.5, 57.5);
	fhb2.v3f(456.25 - 20, 327.5, 57.5);
	fhb2.v3f(460 - 20, 307.5, 50);
	glEnd();

	// middle light (back)


	// middle light
	glColor3f(1.0, 1.0, 1.0);
	fhb2.sphere(GL_POLYGON, 13, 13, 13, 400, 321, 45, 0, 100, 0, 100, 1, 1, 1);

	// front btm
	glColor3f(0.0, 0.0, 0.0);
	glBegin(type4);
	fhb2.v3f(343.75 + 20, 327.5, 57.5);
	fhb2.v3f(346.25 + 20, 352.5, 52.5);
	fhb2.v3f(453.75 - 20, 352.5, 52.5);
	fhb2.v3f(456.25 - 20, 327.5, 57.5);
	glEnd();

	// left top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(340, 307.5, -60 + 20);
	fhb2.v3f(343.75, 327.5, -60 + 20);
	fhb2.v3f(343.75, 327.5, 57.5 - 20);
	fhb2.v3f(340, 307.5, 50 - 20);
	glEnd();

	// left btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(343.75, 327.5, -60 + 20);
	fhb2.v3f(346.25, 352.5, -47.5 + 20);
	fhb2.v3f(346.25, 352.5, 52.5 - 20);
	fhb2.v3f(343.75, 327.5, 57.5 - 20);
	glEnd();

	// right top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(460, 307.5, 50 - 20);
	fhb2.v3f(456.25, 327.5, 57.5 - 20);
	fhb2.v3f(456.25, 327.5, -60 + 20);
	fhb2.v3f(460, 307.5, -60 + 20);
	glEnd();

	// right btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(456.25, 327.5, -60 + 20);
	fhb2.v3f(453.75, 352.5, -47.5 + 20);
	fhb2.v3f(453.75, 352.5, 52.5 - 20);
	fhb2.v3f(456.25, 327.5, 57.5 - 20);
	glEnd();

	// back top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(340 + 20, 307.5, -60);
	fhb2.v3f(343.75 + 20, 327.5, -60);
	fhb2.v3f(456.25 - 20, 327.5, -60);
	fhb2.v3f(460 - 20, 307.5, -60);
	glEnd();

	// back btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(343.75 + 20, 327.5, -60);
	fhb2.v3f(346.25 + 20, 352.5, -47.5);
	fhb2.v3f(453.75 - 20, 352.5, -47.5);
	fhb2.v3f(456.25 - 20, 327.5, -60);
	glEnd();

	// front top left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(340 + 5, 307.5, 50 - 5);
	fhb2.v3f(343.75 + 5, 327.5, 57.5 - 5);
	fhb2.v3f(343.75 + 20, 327.5, 57.5);
	fhb2.v3f(340 + 20, 307.5, 50);
	glEnd();

	// front top right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(460 - 20, 307.5, 50);
	fhb2.v3f(456.25 - 20, 327.5, 57.5);
	fhb2.v3f(456.25 - 5, 327.5, 57.5 - 5);
	fhb2.v3f(460 - 5, 307.5, 50 - 5);
	glEnd();

	// back top left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(340 + 5, 307.5, -60 + 5);
	fhb2.v3f(343.75 + 5, 327.5, -60 + 5);
	fhb2.v3f(343.75 + 20, 327.5, -60);
	fhb2.v3f(340 + 20, 307.5, -60);
	glEnd();

	// back top right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(460 - 20, 307.5, -60);
	fhb2.v3f(456.25 - 20, 327.5, -60);
	fhb2.v3f(456.25 - 5, 327.5, -60 + 5);
	fhb2.v3f(460 - 5, 307.5, -60 + 5);
	glEnd();

	// left top left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(340 + 20, 307.5, -60);
	fhb2.v3f(343.75 + 20, 327.5, -60);
	fhb2.v3f(343.75, 327.5, -60 + 20);
	fhb2.v3f(340, 307.5, -60 + 20);
	glEnd();

	// left top right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(340, 307.5, 50 - 20);
	fhb2.v3f(343.75, 327.5, 57.5 - 20);
	fhb2.v3f(343.75 + 5, 327.5, 57.5 - 5);
	fhb2.v3f(340 + 5, 307.5, 50 - 5);
	glEnd();

	// right top left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(460 - 5, 307.5, 50 - 5);
	fhb2.v3f(456.25 - 5, 327.5, 57.5 - 5);
	fhb2.v3f(456.25, 327.5, 57.5 - 20);
	fhb2.v3f(460, 307.5, 50 - 20);
	glEnd();

	// right top right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(460, 307.5, -60 + 20);
	fhb2.v3f(456.25, 327.5, -60 + 20);
	fhb2.v3f(456.25 - 5, 327.5, -60 + 5);
	fhb2.v3f(460 - 5, 307.5, -60 + 5);
	glEnd();

	// front btm left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(343.75 + 5, 327.5, 57.5 - 5);
	fhb2.v3f(346.25 + 5, 352.5, 52.5 - 5);
	fhb2.v3f(346.25 + 20, 352.5, 52.5);
	fhb2.v3f(343.75 + 20, 327.5, 57.5);
	glEnd();

	// front btm right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(456.25 - 20, 327.5, 57.5);
	fhb2.v3f(453.75 - 20, 352.5, 52.5);
	fhb2.v3f(453.75 - 5, 352.5, 52.5 - 5);
	fhb2.v3f(456.25 - 5, 327.5, 57.5 - 5);
	glEnd();

	// back btm left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(343.75 + 5, 327.5, -60 + 5);
	fhb2.v3f(346.25 + 5, 352.5, -47.5 + 5);
	fhb2.v3f(346.25 + 20, 352.5, -47.5);
	fhb2.v3f(343.75 + 20, 327.5, -60);
	glEnd();

	// back btm right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(456.25 - 20, 327.5, -60);
	fhb2.v3f(453.75 - 20, 352.5, -47.5);
	fhb2.v3f(453.75 - 5, 352.5, -47.5 + 5);
	fhb2.v3f(456.25 - 5, 327.5, -60 + 5);
	glEnd();

	// left btm right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(343.75, 327.5, 57.5 - 20);
	fhb2.v3f(346.25, 352.5, 52.5 - 20);
	fhb2.v3f(346.25 + 5, 352.5, 52.5 - 5);
	fhb2.v3f(343.75 + 5, 327.5, 57.5 - 5);
	glEnd();

	// left btm left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(343.75 + 5, 327.5, -60 + 5);
	fhb2.v3f(346.25 + 5, 352.5, -47.5 + 5);
	fhb2.v3f(346.25, 352.5, -47.5 + 20);
	fhb2.v3f(343.75, 327.5, -60 + 20);
	glEnd();

	// right btm left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(456.25, 327.5, 57.5 - 20);
	fhb2.v3f(453.75, 352.5, 52.5 - 20);
	fhb2.v3f(453.75 - 5, 352.5, 52.5 - 5);
	fhb2.v3f(456.25 - 5, 327.5, 57.5 - 5);
	glEnd();

	// right btm right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(456.25 - 5, 327.5, -60 + 5);
	fhb2.v3f(453.75 - 5, 352.5, -47.5 + 5);
	fhb2.v3f(453.75, 352.5, -47.5 + 20);
	fhb2.v3f(456.25, 327.5, -60 + 20);
	glEnd();

}

void body2::neck() {
	// front btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(382, 240, 15);
	fhb2.v3f(378.75, 265, 25);
	fhb2.v3f(421.25, 265, 25);
	fhb2.v3f(418, 240, 15);
	glEnd();

	// left btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(382, 240, -15);
	fhb2.v3f(378.75, 265, -25);
	fhb2.v3f(378.75, 265, 25);
	fhb2.v3f(382, 240, 15);
	glEnd();

	// right btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(800.0 - 382, 240, -15);
	fhb2.v3f(800.0 - 378.75, 265, -25);
	fhb2.v3f(800.0 - 378.75, 265, 25);
	fhb2.v3f(800.0 - 382, 240, 15);
	glEnd();

	// back btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(382, 240, -15);
	fhb2.v3f(378.75, 265, -25);
	fhb2.v3f(421.25, 265, -25);
	fhb2.v3f(418, 240, -15);
	glEnd();

	// front top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(382, 210, 15);
	fhb2.v3f(382, 240, 15);
	fhb2.v3f(418, 240, 15);
	fhb2.v3f(418, 210, 15);
	glEnd();

	// left top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(382, 210, -15);
	fhb2.v3f(382, 240, -15);
	fhb2.v3f(382, 240, 15);
	fhb2.v3f(382, 210, 15);
	glEnd();

	// right top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(800.0 - 382, 210, -15);
	fhb2.v3f(800.0 - 382, 240, -15);
	fhb2.v3f(800.0 - 382, 240, 15);
	fhb2.v3f(800.0 - 382, 210, 15);
	glEnd();

	// back top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(382, 210, -15);
	fhb2.v3f(382, 240, -15);
	fhb2.v3f(418, 240, -15);
	fhb2.v3f(418, 210, -15);
	glEnd();
}

void body2::chest() {
	neck();
	upperChest();
	lowerChest();
}

void body2::adomen0() {
	//GLenum type4 = GL_POLYGON;

	// front
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(346.25 + 20, 352.5, 52.5);
	fhb2.v3f(351.25 + 20, 400, 50);
	fhb2.v3f(448.75 - 20, 400, 50);
	fhb2.v3f(453.75 - 20, 352.5, 52.5);
	glEnd();

	// back
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(346.25 + 20, 352.5, -47.5);
	fhb2.v3f(351.25 + 20, 400, -36.25);
	fhb2.v3f(448.75 - 20, 400, -36.25);
	fhb2.v3f(453.75 - 20, 352.5, -47.5);
	glEnd();

	// left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(346.25, 352.5, -47.5 + 20);
	fhb2.v3f(351.25, 400, -36.25 + 20);
	fhb2.v3f(351.25, 400, 50 - 20);
	fhb2.v3f(346.25, 352.5, 52.5 - 20);
	glEnd();

	// right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(453.75, 352.5, -47.5 + 20);
	fhb2.v3f(448.75, 400, -36.25 + 20);
	fhb2.v3f(448.75, 400, 50 - 20);
	fhb2.v3f(453.75, 352.5, 52.5 - 20);
	glEnd();

	// front left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(346.25 + 5, 352.5, 52.5 - 5);
	fhb2.v3f(351.25 + 5, 400, 50 - 5);
	fhb2.v3f(351.25 + 20, 400, 50);
	fhb2.v3f(346.25 + 20, 352.5, 52.5);
	glEnd();

	// left right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(346.25, 352.5, 52.5 - 20);
	fhb2.v3f(351.25, 400, 50 - 20);
	fhb2.v3f(351.25 + 5, 400, 50 - 5);
	fhb2.v3f(346.25 + 5, 352.5, 52.5 - 5);
	glEnd();

	// front right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(453.75 - 5, 352.5, 52.5 - 5);
	fhb2.v3f(448.75 - 5, 400, 50 - 5);
	fhb2.v3f(448.75 - 20, 400, 50);
	fhb2.v3f(453.75 - 20, 352.5, 52.5);
	glEnd();

	// right left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(453.75 - 5, 352.5, 52.5 - 5);
	fhb2.v3f(448.75 - 5, 400, 50 - 5);
	fhb2.v3f(448.75, 400, 50 - 20);
	fhb2.v3f(453.75, 352.5, 52.5 - 20);
	glEnd();

	// back left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(346.25 + 5, 352.5, -47.5 + 5);
	fhb2.v3f(351.25 + 5, 400, -36.25 + 5);
	fhb2.v3f(351.25 + 20, 400, -36.25);
	fhb2.v3f(346.25 + 20, 352.5, -47.5);
	glEnd();

	// left left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(346.25 + 5, 352.5, -47.5 + 5);
	fhb2.v3f(351.25 + 5, 400, -36.25 + 5);
	fhb2.v3f(351.25, 400, -36.25 + 20);
	fhb2.v3f(346.25, 352.5, -47.5 + 20);
	glEnd();

	// back right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(453.75 - 20, 352.5, -47.5);
	fhb2.v3f(448.75 - 20, 400, -36.25);
	fhb2.v3f(448.75 - 5, 400, -36.25 + 5);
	fhb2.v3f(453.75 - 5, 352.5, -47.5 + 5);
	glEnd();

	// right right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(453.75 - 5, 352.5, -47.5 + 5);
	fhb2.v3f(448.75 - 5, 400, -36.25 + 5);
	fhb2.v3f(448.75, 400, -36.25 + 20);
	fhb2.v3f(453.75, 352.5, -47.5 + 20);
	glEnd();
}

void body2::adomen1() {
	//GLenum type4 = GL_POLYGON;

	glColor3f(1.0, 1.0, 1.0);
	// front
	glBegin(type4);
	fhb2.v3f(351.25 + 20, 387.5, 50);
	fhb2.v3f(353.75 + 20, 400, 50);
	fhb2.v3f(446.25 - 20, 400, 50);
	fhb2.v3f(448.75 - 20, 387.5, 50);
	glEnd();

	// back
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(351.25 + 20, 387.5, -36.25);
	fhb2.v3f(353.75 + 20, 400, -36.25);
	fhb2.v3f(446.25 - 20, 400, -36.25);
	fhb2.v3f(448.75 - 20, 387.5, -36.25);
	glEnd();

	// left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(351.25, 387.5, -36.25 + 20);
	fhb2.v3f(353.75, 400, -36.25 + 20);
	fhb2.v3f(353.75, 400, 50 - 20);
	fhb2.v3f(351.25, 387.5, 50 - 20);
	glEnd();

	// right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(448.75, 387.5, -36.25 + 20);
	fhb2.v3f(446.25, 400, -36.25 + 20);
	fhb2.v3f(446.25, 400, 50 - 20);
	fhb2.v3f(448.75, 387.5, 50 - 20);
	glEnd();

	// front left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(351.25 + 5, 387.5, 50.0 - 5);
	fhb2.v3f(353.75 + 5, 400, 50 - 5);
	fhb2.v3f(353.75 + 20, 400, 50);
	fhb2.v3f(351.25 + 20, 387.5, 50.0);
	glEnd();

	// left right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(351.25, 387.5, 50.0 - 20);
	fhb2.v3f(353.75, 400, 50 - 20);
	fhb2.v3f(353.75 + 5, 400, 50 - 5);
	fhb2.v3f(351.25 + 5, 387.5, 50.0 - 5);
	glEnd();

	// front right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(448.75 - 5, 387.5, 50.0 - 5);
	fhb2.v3f(446.25 - 5, 400, 50 - 5);
	fhb2.v3f(446.25 - 20, 400, 50);
	fhb2.v3f(448.75 - 20, 387.5, 50.0);
	glEnd();

	// right left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(448.75 - 5, 387.5, 50.0 - 5);
	fhb2.v3f(446.25 - 5, 400, 50 - 5);
	fhb2.v3f(446.25, 400, 50 - 20);
	fhb2.v3f(448.75, 387.5, 50.0 - 20);
	glEnd();

	// back left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(351.25 + 5, 387.5, -36.25 + 5);
	fhb2.v3f(353.75 + 5, 400, -36.25 + 5);
	fhb2.v3f(353.75 + 20, 400, -36.25);
	fhb2.v3f(351.25 + 20, 387.5, -36.25);
	glEnd();

	// left left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(351.25 + 5, 387.5, -36.25 + 5);
	fhb2.v3f(353.75 + 5, 400, -36.25 + 5);
	fhb2.v3f(353.75, 400, -36.25 + 20);
	fhb2.v3f(351.25, 387.5, -36.25 + 20);
	glEnd();

	// back right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(448.75 - 20, 387.5, -36.25);
	fhb2.v3f(446.25 - 20, 400, -36.25);
	fhb2.v3f(446.25 - 5, 400, -36.25 + 5);
	fhb2.v3f(448.75 - 5, 387.5, -36.25 + 5);
	glEnd();

	// right right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(448.75 - 5, 387.5, -36.25 + 5);
	fhb2.v3f(446.25 - 5, 400, -36.25 + 5);
	fhb2.v3f(446.25, 400, -36.25 + 20);
	fhb2.v3f(448.75, 387.5, -36.25 + 20);
	glEnd();
}

void body2::adomen2() {
	//GLenum type4 = GL_POLYGON;

	glColor3f(1.0, 1.0, 1.0);
	// front
	glBegin(type4);
	fhb2.v3f(353.75 + 20, 387.5, 50);
	fhb2.v3f(356.25 + 20, 400, 50);
	fhb2.v3f(443.75 - 20, 400, 50);
	fhb2.v3f(446.25 - 20, 387.5, 50);
	glEnd();

	// back
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(353.75 + 20, 387.5, -36.25);
	fhb2.v3f(356.25 + 20, 400, -36.25);
	fhb2.v3f(443.75 - 20, 400, -36.25);
	fhb2.v3f(446.25 - 20, 387.5, -36.25);
	glEnd();

	// left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(353.75, 387.5, -36.25 + 20);
	fhb2.v3f(356.25, 400, -36.25 + 20);
	fhb2.v3f(356.25, 400, 50 - 20);
	fhb2.v3f(353.75, 387.5, 50 - 20);
	glEnd();

	// right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(446.25, 387.5, -36.25 + 20);
	fhb2.v3f(443.75, 400, -36.25 + 20);
	fhb2.v3f(443.75, 400, 50 - 20);
	fhb2.v3f(446.25, 387.5, 50 - 20);
	glEnd();

	// front left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(353.75 + 5, 387.5, 50.0 - 5);
	fhb2.v3f(356.25 + 5, 400, 50 - 5);
	fhb2.v3f(356.25 + 20, 400, 50);
	fhb2.v3f(353.75 + 20, 387.5, 50.0);
	glEnd();

	// left right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(353.75, 387.5, 50.0 - 20);
	fhb2.v3f(356.25, 400, 50 - 20);
	fhb2.v3f(356.25 + 5, 400, 50 - 5);
	fhb2.v3f(353.75 + 5, 387.5, 50.0 - 5);
	glEnd();

	// front right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(446.25 - 5, 387.5, 50.0 - 5);
	fhb2.v3f(443.75 - 5, 400, 50 - 5);
	fhb2.v3f(443.75 - 20, 400, 50);
	fhb2.v3f(446.25 - 20, 387.5, 50.0);
	glEnd();

	// right left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(446.25 - 5, 387.5, 50.0 - 5);
	fhb2.v3f(443.75 - 5, 400, 50 - 5);
	fhb2.v3f(443.75, 400, 50 - 20);
	fhb2.v3f(446.25, 387.5, 50.0 - 20);
	glEnd();

	// back left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(353.75 + 5, 387.5, -36.25 + 5);
	fhb2.v3f(356.25 + 5, 400, -36.25 + 5);
	fhb2.v3f(356.25 + 20, 400, -36.25);
	fhb2.v3f(353.75 + 20, 387.5, -36.25);
	glEnd();

	// left left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(353.75 + 5, 387.5, -36.25 + 5);
	fhb2.v3f(356.25 + 5, 400, -36.25 + 5);
	fhb2.v3f(356.25, 400, -36.25 + 20);
	fhb2.v3f(353.75, 387.5, -36.25 + 20);
	glEnd();

	// back right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(446.25 - 20, 387.5, -36.25);
	fhb2.v3f(443.75 - 20, 400, -36.25);
	fhb2.v3f(443.75 - 5, 400, -36.25 + 5);
	fhb2.v3f(446.25 - 5, 387.5, -36.25 + 5);
	glEnd();

	// right right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(446.25 - 5, 387.5, -36.25 + 5);
	fhb2.v3f(443.75 - 5, 400, -36.25 + 5);
	fhb2.v3f(443.75, 400, -36.25 + 20);
	fhb2.v3f(446.25, 387.5, -36.25 + 20);
	glEnd();
}

void body2::adomen3() {
	//GLenum type4 = GL_POLYGON;

	glColor3f(1.0, 1.0, 1.0);
	// front
	glBegin(type4);
	fhb2.v3f(356.25 + 20, 387.5, 50);
	fhb2.v3f(357.5 + 20, 400, 50);
	fhb2.v3f(442.5 - 20, 400, 50);
	fhb2.v3f(443.75 - 20, 387.5, 50);
	glEnd();

	// back
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25 + 20, 387.5, -36.25);
	fhb2.v3f(357.5 + 20, 400, -36.25);
	fhb2.v3f(442.5 - 20, 400, -36.25);
	fhb2.v3f(443.75 - 20, 387.5, -36.25);
	glEnd();

	// left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25, 387.5, -36.25 + 20);
	fhb2.v3f(357.5, 400, -36.25 + 20);
	fhb2.v3f(357.5, 400, 50 - 20);
	fhb2.v3f(356.25, 387.5, 50 - 20);
	glEnd();

	// right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75, 387.5, -36.25 + 20);
	fhb2.v3f(442.5, 400, -36.25 + 20);
	fhb2.v3f(442.5, 400, 50 - 20);
	fhb2.v3f(443.75, 387.5, 50 - 20);
	glEnd();

	// front left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25 + 5, 387.5, 50.0 - 5);
	fhb2.v3f(357.5 + 5, 400, 50 - 5);
	fhb2.v3f(357.5 + 20, 400, 50);
	fhb2.v3f(356.25 + 20, 387.5, 50.0);
	glEnd();

	// left right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25, 387.5, 50.0 - 20);
	fhb2.v3f(357.5, 400, 50 - 20);
	fhb2.v3f(357.5 + 5, 400, 50 - 5);
	fhb2.v3f(356.25 + 5, 387.5, 50.0 - 5);
	glEnd();

	// front right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75 - 5, 387.5, 50.0 - 5);
	fhb2.v3f(442.5 - 5, 400, 50 - 5);
	fhb2.v3f(442.5 - 20, 400, 50);
	fhb2.v3f(443.75 - 20, 387.5, 50.0);
	glEnd();

	// right left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75 - 5, 387.5, 50.0 - 5);
	fhb2.v3f(442.5 - 5, 400, 50 - 5);
	fhb2.v3f(442.5, 400, 50 - 20);
	fhb2.v3f(443.75, 387.5, 50.0 - 20);
	glEnd();

	// back left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25 + 5, 387.5, -36.25 + 5);
	fhb2.v3f(357.5 + 5, 400, -36.25 + 5);
	fhb2.v3f(357.5 + 20, 400, -36.25);
	fhb2.v3f(356.25 + 20, 387.5, -36.25);
	glEnd();

	// left left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(356.25 + 5, 387.5, -36.25 + 5);
	fhb2.v3f(357.5 + 5, 400, -36.25 + 5);
	fhb2.v3f(357.5, 400, -36.25 + 20);
	fhb2.v3f(356.25, 387.5, -36.25 + 20);
	glEnd();

	// back right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75 - 20, 387.5, -36.25);
	fhb2.v3f(442.5 - 20, 400, -36.25);
	fhb2.v3f(442.5 - 5, 400, -36.25 + 5);
	fhb2.v3f(443.75 - 5, 387.5, -36.25 + 5);
	glEnd();

	// right right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(443.75 - 5, 387.5, -36.25 + 5);
	fhb2.v3f(442.5 - 5, 400, -36.25 + 5);
	fhb2.v3f(442.5, 400, -36.25 + 20);
	fhb2.v3f(443.75, 387.5, -36.25 + 20);
	glEnd();

}

void body2::below() {
	// front top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(357.5 + 20, 400, 50);
	fhb2.v3f(378.75, 427.5, 50);
	fhb2.v3f(421.25, 427.5, 50);
	fhb2.v3f(442.5 - 20, 400, 50);
	glEnd();

	// front btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(378.75, 427.5, 50);
	fhb2.v3f(391.25, 457.5, 50 - 10);
	fhb2.v3f(408.75, 457.5, 50 - 10);
	fhb2.v3f(421.25, 427.5, 50);
	glEnd();

	// back top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(357.5 + 20, 400, -36.25);
	fhb2.v3f(378.75, 427.5, -45);
	fhb2.v3f(421.25, 427.5, -45);
	fhb2.v3f(442.5 - 20, 400, -36.25);
	glEnd();

	// back btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(378.75, 427.5, -45);
	fhb2.v3f(391.25, 457.5, -36.25);
	fhb2.v3f(408.75, 457.5, -36.25);
	fhb2.v3f(421.25, 427.5, -45);
	glEnd();

	// left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(357.5, 400, -36.25 + 20);
	fhb2.v3f(378.75, 427.5, -45);
	fhb2.v3f(391.25, 457.5, -36.25);
	fhb2.v3f(391.25, 457.5, 50 - 10);
	fhb2.v3f(378.75, 427.5, 50);
	fhb2.v3f(357.5, 400, 50 - 20);
	glEnd();

	// right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(442.5, 400, -36.25 + 20);
	fhb2.v3f(421.25, 427.5, -45);
	fhb2.v3f(408.75, 457.5, -36.25);
	fhb2.v3f(408.75, 457.5, 50 - 10);
	fhb2.v3f(421.25, 427.5, 50);
	fhb2.v3f(442.5, 400, 50 - 20);
	glEnd();

	// btm
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(391.25, 457.5, -36.25);
	fhb2.v3f(391.25, 457.5, 50 - 10);
	fhb2.v3f(408.75, 457.5, 50 - 10);
	fhb2.v3f(408.75, 457.5, -36.25);
	glEnd();

	// front left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(357.5 + 5, 400, 50 - 5);
	fhb2.v3f(378.75, 427.5, 50);
	fhb2.v3f(357.5 + 20, 400, 50);
	glEnd();

	// left right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(357.5, 400, 50 - 20);
	fhb2.v3f(378.75, 427.5, 50);
	fhb2.v3f(357.5 + 5, 400, 50 - 5);
	glEnd();

	// front right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(442.5 - 20, 400, 50);
	fhb2.v3f(421.25, 427.5, 50);
	fhb2.v3f(437.5, 400, 50 - 5);
	glEnd();

	// right left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(437.5, 400, 50 - 5);
	fhb2.v3f(421.25, 427.5, 50);
	fhb2.v3f(442.5, 400, 50 - 20);
	glEnd();

	// back left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(357.5 + 5, 400, -36.25 + 5);
	fhb2.v3f(378.75, 427.5, -45);
	fhb2.v3f(357.5 + 20, 400, -36.25);
	glEnd();

	// front right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(442.5 - 20, 400, -36.25);
	fhb2.v3f(421.25, 427.5, -45);
	fhb2.v3f(437.5, 400, -36.25 + 5);
	glEnd();

	// left left
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(357.5 + 5, 400, -36.25 + 5);
	fhb2.v3f(378.75, 427.5, -45);
	fhb2.v3f(357.5, 400, -36.25 + 20);
	glEnd();

	// right right
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type4);
	fhb2.v3f(437.5, 400, -36.25 + 5);
	fhb2.v3f(421.25, 427.5, -45);
	fhb2.v3f(442.5, 400, -36.25 + 20);
	glEnd();
}