#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include "Function.h"
#include "Body.h"
#include "Head.h"

using namespace N;
using namespace std;
using namespace B;
using namespace H;

function fh_head;
boolean tOn = false;
GLenum glQuad = GL_QUADS, glLine = GL_LINE_LOOP, glTri = GL_TRIANGLES;

void head::textureOn(boolean t) {
	tOn = t;
}

void head::eye() {
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 1);
	// right
	glBegin(glQuad);
	fh_head.v3f(427.5, 400, 130);
	fh_head.v3f(427.5, 415, 130);
	fh_head.v3f(472.5, 415, 115);
	fh_head.v3f(492.5, 400, 92.5);
	fh_head.v3f(487.5, 387.5, 100);
	glEnd();

	// left
	glBegin(glQuad);
	fh_head.v3f(372.5, 400, 130);
	fh_head.v3f(372.5, 415, 130);
	fh_head.v3f(327.5, 415, 115);
	fh_head.v3f(307.5, 400, 92.5);
	fh_head.v3f(312.5, 387.5, 100);
	glEnd();
}

void head::rightTop() {
	// front
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.5, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(427.5, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(447.5, 205, 50);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(502.5, 240, 40);			// b
	glTexCoord2f(0.0, 0.0), fh_head.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.7, 0.7);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(502.5, 240, 40);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(522.5, 287.5, 55);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(522.5, 287.5, 55);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 375, 72.5);	// d?
	//fh_head.v3f(504, 387.5, 60);		// aa
	//fh_head.v3f(502.5, 392, 92);		// ee
	glTexCoord2f(1.0, 0.0), fh_head.v3f(492.5, 387.5, 105);	// dd
	glTexCoord2f(0.0, 0.0), fh_head.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side2.5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0, 0.7);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509.5, 375, 72.5);	// d?
	glTexCoord2f(1.0, 1.0), fh_head.v3f(504, 387.5, 60);		// aa
	glTexCoord2f(1.0, 0.0), fh_head.v3f(492.5, 387.5, 105);	// dd
	//fh_head.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.7, 0);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(504, 387.5, 60);		// aa
	glTexCoord2f(1.0, 1.0), fh_head.v3f(502.5, 392, 92);		// ee
	glTexCoord2f(1.0, 0.0), fh_head.v3f(492.5, 387.5, 105);	// dd
	glEnd();

	// front2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0.7, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(427.5, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(522.5, 287.5, 72.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(492.5, 387.5, 105);	// dd
	glTexCoord2f(0.0, 0.0), fh_head.v3f(427, 400, 130);
	glEnd();

	// front3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0.7, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(400, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(400, 400, 137.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(427, 400, 130);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(427.5, 287.5, 115);
	glEnd();
}

void head::eyeMid() {

	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.9, 0.3, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(372.5, 400, 130);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(372.5, 415, 130);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(400, 415, 137);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 400, 137);
	glEnd();

	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.9, 0.3, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(427.5, 415, 130);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(427.5, 400, 130);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(400, 400, 137);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 415, 137);
	glEnd();
}

void head::leftTop() {
	// front
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.5, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(372.5, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(352.5, 205, 50);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(297.5, 240, 40);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.7, 0.7);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(297.5, 240, 40);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(277.5, 287.5, 55);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(277.5, 287.5, 55);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(290.5, 375, 72.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(307.5, 387.5, 105);	// dd
	glTexCoord2f(0.0, 0.0), fh_head.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side2.5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0, 0.7);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(290.5, 375, 72.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(295, 387.5, 60);		// aa
	glTexCoord2f(1.0, 0.0), fh_head.v3f(307.5, 387.5, 105);	// dd
	glEnd();

	// side3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.7, 0);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(295, 387.5, 60);		// aa
	glTexCoord2f(1.0, 1.0), fh_head.v3f(297, 392, 92);		// ee
	glTexCoord2f(1.0, 0.0), fh_head.v3f(307.5, 387.5, 105);	// dd
	glEnd();

	// front2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0.7, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(372.5, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(277.5, 287.5, 72.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(307.5, 387.5, 105);	// dd
	glTexCoord2f(0.0, 0.0), fh_head.v3f(372.5, 400, 130);
	glEnd();

	// front3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0.7, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(400, 287.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(400, 400, 137.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(372.5, 400, 130);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(372.5, 287.5, 115);
	glEnd();
}

void head::rightBtm() {
	// side top
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.6, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head.v3f(504, 387.5, 60);		// aa
	glTexCoord2f(1.0, 0.0), fh_head.v3f(502.5, 392, 92);		// ee
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509, 415, 92);
	glEnd();

	// front top
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(502.5, 392, 92);		// ee
	glTexCoord2f(1.0, 1.0), fh_head.v3f(472.5, 415, 115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509, 415, 92);
	glEnd();

	// side top 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509, 415, 92);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(495, 457.5, 92.5);	// a2
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509, 435, 45);		// z
	glEnd();

	// front top 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509, 415, 92);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(495, 457.5, 92.5);	// a2
	glTexCoord2f(1.0, 0.0), fh_head.v3f(472.5, 457.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(472.5, 415, 115);
	glEnd();

	// front top 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(472.5, 415, 115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(427.5, 415, 130);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.5, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(427.5, 415, 130);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(427.5, 457.5, 130);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(400, 457.5, 137.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 1, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(427.5, 457.5, 130);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(400, 457.5, 137.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(400, 522.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(435, 522.5, 115);
	glEnd();

	// front btm 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.5, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(427.5, 457.5, 130);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(435, 522.5, 115);
	glEnd();

	// front btm 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.5, 0.3);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(435, 522.5, 115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.3, 0.7);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509, 435, 45);		// z
	glTexCoord2f(1.0, 1.0), fh_head.v3f(495, 457.5, 68);		// a1
	glTexCoord2f(1.0, 0.0), fh_head.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.7, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(495, 457.5, 68);		// a1
	glTexCoord2f(1.0, 1.0), fh_head.v3f(470, 505, 77.5);		// bb
	glTexCoord2f(1.0, 0.0), fh_head.v3f(435, 522.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(470, 505, 77.5);		// bb
	glTexCoord2f(1.0, 1.0), fh_head.v3f(467.5, 517.5, 75);	// y
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 530, 97.5);	// x
	glTexCoord2f(0.0, 0.0), fh_head.v3f(435, 522.5, 115);
	glEnd();
}

void head::leftBtm() {
	// side top
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.6, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 504, 387.5, 60);		// aa
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 502.5, 392, 92);		// ee
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 509, 415, 92);
	glEnd();

	// front top
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 502.5, 392, 92);		// ee
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 472.5, 415, 115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509, 415, 92);
	glEnd();

	// side top 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509, 415, 92);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 495, 457.5, 92.5);	// a2
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 509, 435, 45);		// z
	glEnd();

	// front top 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509, 415, 92);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 495, 457.5, 92.5);	// a2
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 472.5, 457.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 472.5, 415, 115);
	glEnd();

	// front top 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 472.5, 415, 115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 427.5, 415, 130);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.5, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 427.5, 415, 130);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 427.5, 457.5, 130);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 400, 457.5, 137.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 1, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 427.5, 457.5, 130);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 400, 457.5, 137.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 400, 522.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 435, 522.5, 115);
	glEnd();

	// front btm 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.5, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 427.5, 457.5, 130);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 435, 522.5, 115);
	glEnd();

	// front btm 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.5, 0.3);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 472.5, 457.5, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 435, 522.5, 115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.3, 0.7);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509, 435, 45);		// z
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 495, 457.5, 68);		// a1
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.7, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 495, 457.5, 68);		// a1
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 470, 505, 77.5);		// bb
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 435, 522.5, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 470, 505, 77.5);		// bb
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 467.5, 517.5, 75);	// y
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 447.5, 530, 97.5);	// x
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 435, 522.5, 115);
	glEnd();
}

void head::mask() {
	eye();

	rightTop();
	leftTop();
	eyeMid();

	rightBtm();
	leftBtm();
}

void head::headRightTop1() {
	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(447.5, 185, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(502.5, 222.5, 0);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(502.5, 240, 40);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(447.5, 205, 50);
	glEnd();

	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(447.5, 185, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(502.5, 222.5, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(502.5, 222.5, 0);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(447.5, 185, 0);
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(447.5, 212.5, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(502.5, 240, -115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(502.5, 222.5, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(447.5, 185, -57.5);
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(447.5, 260, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(502.5, 240, -115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(447.5, 212.5, -115);
	glEnd();
}

void head::headRightTop2() {
	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(502.5, 240, 40);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 335, 27.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(522.5, 287.5, 55);
	glEnd();

	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(522.5, 287.5, 55);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 335, 27.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509.5, 375, 72.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509.5, 352, 72.5);	// d?
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(502.5, 222.5, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 287, 0);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 335, 27.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(502.5, 240, 40);
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(502.5, 222.5, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 287, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 287, 0);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(502.5, 222.5, 0);
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.5, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(502.5, 240, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 287, -115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 287, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(502.5, 222.5, -57.5);
	glEnd();

	// 6
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.7, 0.5);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(502.5, 240, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 287, -115);
	glEnd();

}

void head::headRightMid() {
	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.5, 0.6);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 335, 27.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 352, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509.5, 375, 0);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509.5, 375, 72.5);
	glEnd();

	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.4, 0.1, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509.5, 375, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 415, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509, 415, 40);		// cc
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509.5, 375, 72.5);
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0.5, 0.6);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 287, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 352, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 335, 27.5);	
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.6, 1, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 287, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 352, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509.5, 352, -12.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(510, 287, 0);
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0.6, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 352, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 287, -57.5);
	glEnd();

	// 6
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.6, 0.1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 352, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 375, -82.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509.5, 352, -57.5);
	glEnd();

	// 7
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.6, 0.8);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 310, -160);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(510, 352, -127.5);
	glEnd();

	// 8
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.8, 0.1, 0.8);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(447.5, 260, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 310, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(502.5, 270, -127.5);
	glEnd();

	// 9 
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.8, 0.7, 0.2);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 310, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 352, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 352, -127.5);
	glEnd();
}

void head::headRightBtm() {
	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.6, 0.9);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 415, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509, 435, 45);		// z
	glEnd();

	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.9, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509.5, 415, -12.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(515, 487.5, 0);		// r
	glTexCoord2f(1.0, 0.0), fh_head.v3f(492.5, 550, 27.5);	// rr
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509, 435, 45);		// z
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.3, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 352, -127.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 415, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509.5, 415, -80);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(510, 375, -82.5);
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.7, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 352, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 415, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509.5, 415, -127.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(510, 352, -127.5);
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.3, 0.9);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509, 435, 45);		// z
	glTexCoord2f(1.0, 1.0), fh_head.v3f(492.5, 550, 27.5);	// rr
	glTexCoord2f(1.0, 0.0), fh_head.v3f(472.5, 532.5, 67.5);	// s
	glTexCoord2f(0.0, 0.0), fh_head.v3f(467.5, 517.5, 75);	// y = ss
	glEnd();

	// 6
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.9, 0.3, 0.1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(492.5, 550, 27.5);	// rr
	glTexCoord2f(1.0, 1.0), fh_head.v3f(447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 562.5, 87.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(472.5, 532.5, 67.5);	// s
	glEnd();

	// 7
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.9, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(447.5, 562.5, 87.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head.v3f(427.5, 572.5, 117.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(427.5, 550, 115);
	glEnd();

	// 8
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.2, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(427.5, 550, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(427.5, 572.5, 117.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(400, 572.5, 117.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 550, 115);
	glEnd();

	// 9
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.2, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(467.5, 517.5, 75);	// y = ss
	glTexCoord2f(1.0, 1.0), fh_head.v3f(472.5, 532.5, 67.5);	// s
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 562.5, 87.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(447.5, 530, 97.5);	// x
	glEnd();

	// 10
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.8, 0.6);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(447.5, 522, 97.5);	// x
	glTexCoord2f(1.0, 1.0), fh_head.v3f(447.5, 562.5, 87.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(427.5, 550, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(435, 522, 115);
	glEnd();

	// 11
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.2, 0.2, 0.6);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(435, 522, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(427.5, 550, 115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(400.0, 550, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400.0, 522, 115);
	glEnd();
}

void head::headRightBtm2() {
	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 0.3);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509.5, 415, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 466, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509.5, 415, -147.5);
	glEnd();

	// 2.1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 0.3);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509.5, 415, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 466, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509.5, 450, -135);
	glEnd();

	// 2.2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509.5, 415, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 450, -135);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(509.5, 415, -80);
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509.5, 415, -80);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(509.5, 450, -135);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(515, 487.5, 0);		// r
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 1);
	glBegin(glTri);
	fh_head.v3f(509.5, 415, -80);
	fh_head.v3f(515, 487.5, 0);		// r
	fh_head.v3f(509.5, 415, -12.5);
	glEnd();
}

void head::headRightBack() {
	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(400, 180, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(447.5, 185, 0);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 205, 50);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 200, 50);
	glEnd();

	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(400, 180, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(447.5, 185, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 185, 0);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 180, 0);
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(400, 207.5, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(447.5, 212.5, -115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 185, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 180, -57.5);
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(400, 255, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(447.5, 260, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 212.5, -115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 207.5, -115);
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(400, 310, -170);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 310, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 260, -147.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 255, -147.5);
	glEnd();

	// 6
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 1, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(400, 352, -170);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(510, 352, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(510, 310, -160);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(400, 310, -170);
	glEnd();

	// 7
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.7, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(510, 352, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(400, 352, -170);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(400, 415, -170);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509.5, 415, -160);
	glEnd();

	// 8
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(509.5, 415, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(400, 415, -170);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(400, 466, -157.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509.5, 466, -147.5);
	glEnd();

}

void head::headLeftTop1() {
	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 447.5, 185, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 502.5, 222.5, 0);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 502.5, 240, 40);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 447.5, 205, 50);
	glEnd();

	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 447.5, 185, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 502.5, 222.5, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 502.5, 222.5, 0);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 447.5, 185, 0);
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 447.5, 212.5, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 502.5, 240, -115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 502.5, 222.5, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 447.5, 185, -57.5);
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 447.5, 260, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 502.5, 240, -115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 447.5, 212.5, -115);
	glEnd();
}

void head::headLeftTop2() {
	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 502.5, 240, 40);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 335, 27.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 522.5, 287.5, 55);
	glEnd();

	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 522.5, 287.5, 55);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 335, 27.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509.5, 375, 72.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 509.5, 352, 72.5);	// d?
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 502.5, 222.5, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 287, 0);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 335, 27.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 502.5, 240, 40);
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 502.5, 222.5, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 287, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 287, 0);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 502.5, 222.5, 0);
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 0.5, 0.5);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 502.5, 240, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 287, -115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 287, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 502.5, 222.5, -57.5);
	glEnd();

	// 6
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.7, 0.5);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 502.5, 240, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 287, -115);
	glEnd();

}

void head::headLeftMid() {
	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.5, 0.6);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 335, 27.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 352, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509.5, 375, 0);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 509.5, 375, 72.5);
	glEnd();

	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.4, 0.1, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509.5, 375, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509, 415, 40);		// cc
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 509.5, 375, 72.5);
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0.5, 0.6);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 287, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 352, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 335, 27.5);
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.6, 1, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 287, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 352, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509.5, 352, -12.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 510, 287, 0);
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0.6, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 352, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 287, -57.5);
	glEnd();

	// 6
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.6, 0.1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 352, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 375, -82.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 509.5, 352, -57.5);
	glEnd();

	// 7
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.6, 0.8);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 287, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 502.5, 270, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 310, -160);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 510, 352, -127.5);
	glEnd();

	// 8
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.8, 0.1, 0.8);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 447.5, 260, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 310, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 502.5, 270, -127.5);
	glEnd();

	// 9 
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.8, 0.7, 0.2);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 310, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 352, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 352, -127.5);
	glEnd();
}

void head::headLeftBtm() {
	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.6, 0.9);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509, 415, 40);		// cc
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -12.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509, 435, 45);		// z
	glEnd();

	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.9, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -12.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 515, 487.5, 0);		// r
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 492.5, 550, 27.5);	// rr
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 509, 435, 45);		// z
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.3, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 352, -127.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -127.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509.5, 415, -80);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 510, 375, -82.5);
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.7, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 352, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509.5, 415, -127.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 510, 352, -127.5);
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.3, 0.9);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509, 435, 45);		// z
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 492.5, 550, 27.5);	// rr
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 472.5, 532.5, 67.5);	// s
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 467.5, 517.5, 75);	// y = ss
	glEnd();

	// 6
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.9, 0.3, 0.1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 492.5, 550, 27.5);	// rr
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 447.5, 562.5, 87.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 472.5, 532.5, 67.5);	// s
	glEnd();

	// 7
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.3, 0.9, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 447.5, 562.5, 87.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 427.5, 572.5, 117.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 427.5, 550, 115);
	glEnd();

	// 8
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.2, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 427.5, 550, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 427.5, 572.5, 117.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 400, 572.5, 117.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 400, 550, 115);
	glEnd();

	// 9
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.2, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 467.5, 517.5, 75);	// y = ss
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 472.5, 532.5, 67.5);	// s
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 447.5, 562.5, 87.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 447.5, 530, 97.5);	// x
	glEnd();

	// 10
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.8, 0.6);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 447.5, 522, 97.5);	// x
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 447.5, 562.5, 87.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 427.5, 550, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 435, 522, 115);
	glEnd();

	// 11
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.2, 0.2, 0.6);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 435, 522, 115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 427.5, 550, 115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 400.0, 550, 115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 400.0, 522, 115);
	glEnd();
}

void head::headLeftBtm2() {
	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 0.3);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 466, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509.5, 415, -147.5);
	glEnd();

	// 2.1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 0.3);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 466, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509.5, 450, -135);
	glEnd();

	// 2.2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 450, -135);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509.5, 415, -80);
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -80);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 509.5, 450, -135);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 515, 487.5, 0);		// r
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 1);
	glBegin(glTri);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -80);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 515, 487.5, 0);		// r
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 509.5, 415, -12.5);
	glEnd();
}

void head::headLeftBack() {
	// Left

	// 1
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 400, 180, 0);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 447.5, 185, 0);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 447.5, 205, 50);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 400, 200, 50);
	glEnd();

	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 400, 180, -57.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 447.5, 185, -57.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 447.5, 185, 0);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 400, 180, 0);
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 0, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 400, 207.5, -115);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 447.5, 212.5, -115);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 447.5, 185, -57.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 400, 180, -57.5);
	glEnd();

	// 4
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 400, 255, -147.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 447.5, 260, -147.5);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 447.5, 212.5, -115);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 400, 207.5, -115);
	glEnd();

	// 5
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0, 1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 400, 310, -170);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 310, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 447.5, 260, -147.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 400, 255, -147.5);
	glEnd();

	// 6
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.5, 1, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 400, 352, -170);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 510, 352, -160);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 510, 310, -160);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 400, 310, -170);
	glEnd();

	// 7
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.7, 0.3);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 510, 352, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 400, 352, -170);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 400, 415, -170);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 509.5, 415, -160);
	glEnd();

	// 8
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.1, 1);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -160);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 400, 415, -170);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(800.0 - 400, 466, -157.5);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(800.0 - 509.5, 466, -147.5);
	glEnd();

}

void head::headTop() {
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 1, 0);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(372.5, 287.5, 110);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(352.5, 205, 50);
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 205, 50);
	glTexCoord2f(0.0, 0.0), fh_head.v3f(427.5, 287.5, 110);
	glEnd();
}

void head::ear() {
	GLUquadricObj* disk = NULL;
	disk = gluNewQuadric();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 0, 0, 1);
	fh_head.color('r');
	gluQuadricDrawStyle(disk, GLU_FILL);
	gluDisk(disk, 0, fh_head.yP(55), 50, 50);
	glPopMatrix();
}

void head::btmCover() {
	// 1 (btm for left and right)
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 0.2, 0.6);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 427.5, 572.5, 117.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 587.5, 87.5);			// lowest
	glTexCoord2f(0.0, 0.0), fh_head.v3f(427.5, 572.5, 117.5);
	glEnd();

	// 2
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.7, 1, 0.6);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 492.5, 550, 27.5);		// rr
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 447.5, 587.5, 87.5);	// lowest
	glTexCoord2f(1.0, 0.0), fh_head.v3f(447.5, 587.5, 87.5);			// lowest
	glTexCoord2f(0.0, 0.0), fh_head.v3f(492.5, 550, 27.5);			// rr
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(1, 0.4, 0.6);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 515, 487.5, 0);		// r
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 492.5, 550, 27.5);		// rr
	glTexCoord2f(1.0, 0.0), fh_head.v3f(492.5, 550, 27.5);			// rr
	glTexCoord2f(0.0, 0.0), fh_head.v3f(515, 487.5, 0);				// r
	glEnd();

	// 3
	if (tOn) glColor3f(1.0, 1.0, 1.0); else glColor3f(0.2, 1, 0.7);
	glBegin(glQuad);
	glTexCoord2f(0.0, 1.0), fh_head.v3f(800.0 - 509.5, 415, -127.5);
	glTexCoord2f(1.0, 1.0), fh_head.v3f(800.0 - 515, 487.5, 0);		// r
	glTexCoord2f(1.0, 0.0), fh_head.v3f(515, 487.5, 0);		// r
	glTexCoord2f(0.0, 0.0), fh_head.v3f(509.5, 415, -127.5);
	glEnd();
}