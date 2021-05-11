#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include "Function.h"
#include "Body.h"
#include "Head2.h"

using namespace N;
using namespace std;
using namespace B;
using namespace H2;

function fh_head2;
GLenum type5 = GL_LINE_LOOP, gltype5 = GL_POLYGON;

void head2::eye() {
	glColor3f(1.0, 1.0, 1.0);
	// right
	glBegin(type5);
	fh_head2.v3f(427.5, 400, 130);
	fh_head2.v3f(427.5, 415, 130);
	fh_head2.v3f(472.5, 415, 115);
	fh_head2.v3f(492.5, 400, 92.5);
	fh_head2.v3f(487.5, 387.5, 100);
	glEnd();

	// left
	glBegin(type5);
	fh_head2.v3f(372.5, 400, 130);
	fh_head2.v3f(372.5, 415, 130);
	fh_head2.v3f(327.5, 415, 115);
	fh_head2.v3f(307.5, 400, 92.5);
	fh_head2.v3f(312.5, 387.5, 100);
	glEnd();
}

void head2::rightTop() {
	// front
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(427.5, 287.5, 115);
	fh_head2.v3f(447.5, 205, 50);
	fh_head2.v3f(502.5, 240, 40);			// b
	fh_head2.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side
	glColor3f(0.0, 0.0, 0.0);
	glBegin(type5);
	fh_head2.v3f(502.5, 240, 40);
	fh_head2.v3f(522.5, 287.5, 55);
	fh_head2.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(522.5, 287.5, 55);
	fh_head2.v3f(509.5, 375, 72.5);	// d?
	//fh_head2.v3f(504, 387.5, 60);		// aa
	//fh_head2.v3f(502.5, 392, 92);		// ee
	fh_head2.v3f(492.5, 387.5, 105);	// dd
	fh_head2.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side2.5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	//fh_head2.v3f(522.5, 287.5, 55);
	fh_head2.v3f(509.5, 375, 72.5);	// d?
	fh_head2.v3f(504, 387.5, 60);		// aa
	fh_head2.v3f(492.5, 387.5, 105);	// dd
	//fh_head2.v3f(522.5, 287.5, 72.5);
	glEnd();

	// side3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(504, 387.5, 60);		// aa
	fh_head2.v3f(502.5, 392, 92);		// ee
	fh_head2.v3f(492.5, 387.5, 105);	// dd
	glEnd();

	// front2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(427.5, 287.5, 115);
	fh_head2.v3f(522.5, 287.5, 72.5);
	fh_head2.v3f(492.5, 387.5, 105);	// dd
	fh_head2.v3f(427, 400, 130);
	glEnd();

	// front3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(400, 287.5, 115);
	fh_head2.v3f(400, 400, 137.5);
	fh_head2.v3f(427, 400, 130);
	fh_head2.v3f(427.5, 287.5, 115);
	glEnd();
}

void head2::eyeMid() {

	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(372.5, 400, 130);
	fh_head2.v3f(372.5, 415, 130);
	fh_head2.v3f(400, 415, 137);
	fh_head2.v3f(400, 400, 137);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(427.5, 415, 130);
	fh_head2.v3f(427.5, 400, 130);
	fh_head2.v3f(400, 400, 137);
	fh_head2.v3f(400, 415, 137);
	glEnd();
}

void head2::leftTop() {
	// front
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(372.5, 287.5, 115);
	fh_head2.v3f(352.5, 205, 50);
	fh_head2.v3f(297.5, 240, 40);
	fh_head2.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side
	glColor3f(0.0, 0.0, 0.0);
	glBegin(type5);
	fh_head2.v3f(297.5, 240, 40);
	fh_head2.v3f(277.5, 287.5, 55);
	fh_head2.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(277.5, 287.5, 55);
	fh_head2.v3f(290.5, 375, 72.5);
	fh_head2.v3f(307.5, 387.5, 105);	// dd
	fh_head2.v3f(277.5, 287.5, 72.5);
	glEnd();

	// side2.5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(290.5, 375, 72.5);
	fh_head2.v3f(295, 387.5, 60);		// aa
	fh_head2.v3f(307.5, 387.5, 105);	// dd
	glEnd();

	// side3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(295, 387.5, 60);		// aa
	fh_head2.v3f(297, 392, 92);		// ee
	fh_head2.v3f(307.5, 387.5, 105);	// dd
	glEnd();

	// front2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	//fh_head2.v3f(400, 287.5, 115);
	fh_head2.v3f(372.5, 287.5, 115);
	fh_head2.v3f(277.5, 287.5, 72.5);
	fh_head2.v3f(307.5, 387.5, 105);	// dd
	fh_head2.v3f(372.5, 400, 130);
	glEnd();

	// front3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(400, 287.5, 115);
	fh_head2.v3f(400, 400, 137.5);
	fh_head2.v3f(372.5, 400, 130);
	fh_head2.v3f(372.5, 287.5, 115);
	glEnd();
}

void head2::rightBtm() {
	// side top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509, 415, 40);		// cc
	fh_head2.v3f(504, 387.5, 60);		// aa
	fh_head2.v3f(502.5, 392, 92);		// ee
	fh_head2.v3f(509, 415, 92);
	glEnd();

	// front top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(502.5, 392, 92);		// ee
	fh_head2.v3f(472.5, 415, 115);
	fh_head2.v3f(509, 415, 92);
	glEnd();

	// side top 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509, 415, 40);		// cc
	fh_head2.v3f(509, 415, 92);
	fh_head2.v3f(495, 457.5, 92.5);	// a2
	fh_head2.v3f(509, 435, 45);		// z
	glEnd();

	// front top 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509, 415, 92);
	fh_head2.v3f(495, 457.5, 92.5);	// a2
	fh_head2.v3f(472.5, 457.5, 115);
	fh_head2.v3f(472.5, 415, 115);
	glEnd();

	// front top 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(472.5, 457.5, 115);
	fh_head2.v3f(472.5, 415, 115);
	fh_head2.v3f(427.5, 415, 130);
	fh_head2.v3f(427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(427.5, 415, 130);
	fh_head2.v3f(427.5, 457.5, 130);
	fh_head2.v3f(400, 457.5, 137.5);
	fh_head2.v3f(400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(427.5, 457.5, 130);
	fh_head2.v3f(400, 457.5, 137.5);
	fh_head2.v3f(400, 522.5, 115);
	fh_head2.v3f(435, 522.5, 115);
	glEnd();

	// front btm 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(472.5, 457.5, 115);
	fh_head2.v3f(427.5, 457.5, 130);
	fh_head2.v3f(435, 522.5, 115);
	glEnd();

	// front btm 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(472.5, 457.5, 115);
	fh_head2.v3f(435, 522.5, 115);
	fh_head2.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	//fh_head2.v3f(509, 415, 40);		// cc
	fh_head2.v3f(509, 435, 45);		// z
	fh_head2.v3f(495, 457.5, 68);		// a1
	fh_head2.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(495, 457.5, 68);		// a1
	fh_head2.v3f(470, 505, 77.5);		// bb
	fh_head2.v3f(435, 522.5, 115);
	fh_head2.v3f(495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(470, 505, 77.5);		// bb
	fh_head2.v3f(467.5, 517.5, 75);	// y
	fh_head2.v3f(447.5, 530, 97.5);	// x
	fh_head2.v3f(435, 522.5, 115);
	glEnd();
}

void head2::leftBtm() {
	// side top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509, 415, 40);		// cc
	fh_head2.v3f(800.0 - 504, 387.5, 60);		// aa
	fh_head2.v3f(800.0 - 502.5, 392, 92);		// ee
	fh_head2.v3f(800.0 - 509, 415, 92);
	glEnd();

	// front top
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 502.5, 392, 92);		// ee
	fh_head2.v3f(800.0 - 472.5, 415, 115);
	fh_head2.v3f(800.0 - 509, 415, 92);
	glEnd();

	// side top 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509, 415, 40);		// cc
	fh_head2.v3f(800.0 - 509, 415, 92);
	fh_head2.v3f(800.0 - 495, 457.5, 92.5);	// a2
	fh_head2.v3f(800.0 - 509, 435, 45);		// z
	glEnd();

	// front top 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509, 415, 92);
	fh_head2.v3f(800.0 - 495, 457.5, 92.5);	// a2
	fh_head2.v3f(800.0 - 472.5, 457.5, 115);
	fh_head2.v3f(800.0 - 472.5, 415, 115);
	glEnd();

	// front top 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 472.5, 457.5, 115);
	fh_head2.v3f(800.0 - 472.5, 415, 115);
	fh_head2.v3f(800.0 - 427.5, 415, 130);
	fh_head2.v3f(800.0 - 427.5, 457.5, 130);
	glEnd();

	// front top 4 (middle top)
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 427.5, 415, 130);
	fh_head2.v3f(800.0 - 427.5, 457.5, 130);
	fh_head2.v3f(800.0 - 400, 457.5, 137.5);
	fh_head2.v3f(800.0 - 400, 415, 137.5);
	glEnd();

	// front btm (middle btm)
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 427.5, 457.5, 130);
	fh_head2.v3f(800.0 - 400, 457.5, 137.5);
	fh_head2.v3f(800.0 - 400, 522.5, 115);
	fh_head2.v3f(800.0 - 435, 522.5, 115);
	glEnd();

	// front btm 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 472.5, 457.5, 115);
	fh_head2.v3f(800.0 - 427.5, 457.5, 130);
	fh_head2.v3f(800.0 - 435, 522.5, 115);
	glEnd();

	// front btm 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 472.5, 457.5, 115);
	fh_head2.v3f(800.0 - 435, 522.5, 115);
	fh_head2.v3f(800.0 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	//fh_head2.v3f(509, 415, 40);		// cc
	fh_head2.v3f(800.0 - 509, 435, 45);		// z
	fh_head2.v3f(800.0 - 495, 457.5, 68);		// a1
	fh_head2.v3f(800.0 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 495, 457.5, 68);		// a1
	fh_head2.v3f(800.0 - 470, 505, 77.5);		// bb
	fh_head2.v3f(800.0 - 435, 522.5, 115);
	fh_head2.v3f(800.0 - 495, 457.5, 92.5);	// a2
	glEnd();

	// side 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 470, 505, 77.5);		// bb
	fh_head2.v3f(800.0 - 467.5, 517.5, 75);	// y
	fh_head2.v3f(800.0 - 447.5, 530, 97.5);	// x
	fh_head2.v3f(800.0 - 435, 522.5, 115);
	glEnd();
}

void head2::mask() {
	eye();

	rightTop();
	leftTop();
	eyeMid();

	rightBtm();
	leftBtm();
}

void head2::headRightTop1() {
	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(447.5, 185, 0);
	fh_head2.v3f(502.5, 222.5, 0);
	fh_head2.v3f(502.5, 240, 40);
	fh_head2.v3f(447.5, 205, 50);
	glEnd();

	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(447.5, 185, -57.5);
	fh_head2.v3f(502.5, 222.5, -57.5);
	fh_head2.v3f(502.5, 222.5, 0);
	fh_head2.v3f(447.5, 185, 0);
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(447.5, 212.5, -115);
	fh_head2.v3f(502.5, 240, -115);
	fh_head2.v3f(502.5, 222.5, -57.5);
	fh_head2.v3f(447.5, 185, -57.5);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(447.5, 260, -147.5);
	fh_head2.v3f(502.5, 270, -127.5);
	fh_head2.v3f(502.5, 240, -115);
	fh_head2.v3f(447.5, 212.5, -115);
	glEnd();
}

void head2::headRightTop2() {
	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(502.5, 240, 40);
	fh_head2.v3f(510, 335, 27.5);
	fh_head2.v3f(522.5, 287.5, 55);
	//fh_head2.v3f(504, 387.5, 60);		// aa
	//fh_head2.v3f(509.5, 352, 72.5);	// d?
	//fh_head2.v3f(522.5, 287.5, 55);
	glEnd();

	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(522.5, 287.5, 55);
	fh_head2.v3f(510, 335, 27.5);
	fh_head2.v3f(509.5, 375, 72.5);
	fh_head2.v3f(509.5, 352, 72.5);	// d?
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(502.5, 222.5, 0);
	fh_head2.v3f(510, 287, 0);
	fh_head2.v3f(510, 335, 27.5);
	fh_head2.v3f(502.5, 240, 40);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(502.5, 222.5, -57.5);
	fh_head2.v3f(510, 287, -57.5);
	fh_head2.v3f(510, 287, 0);
	fh_head2.v3f(502.5, 222.5, 0);
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(502.5, 240, -115);
	fh_head2.v3f(510, 287, -115);
	fh_head2.v3f(510, 287, -57.5);
	fh_head2.v3f(502.5, 222.5, -57.5);
	glEnd();

	// 6
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(502.5, 240, -115);
	fh_head2.v3f(502.5, 270, -127.5);
	fh_head2.v3f(510, 287, -115);
	glEnd();

}

void head2::headRightMid() {
	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 335, 27.5);
	fh_head2.v3f(509.5, 352, -12.5);
	fh_head2.v3f(509.5, 375, 0);
	fh_head2.v3f(509.5, 375, 72.5);
	glEnd();

	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509.5, 375, 0);
	fh_head2.v3f(509.5, 415, -12.5);
	fh_head2.v3f(509, 415, 40);		// cc
	fh_head2.v3f(509.5, 375, 72.5);
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 287, 0);
	fh_head2.v3f(509.5, 352, -12.5);
	fh_head2.v3f(510, 335, 27.5);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 287, -57.5);
	fh_head2.v3f(509.5, 352, -57.5);
	fh_head2.v3f(509.5, 352, -12.5);
	fh_head2.v3f(510, 287, 0);
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 287, -115);
	fh_head2.v3f(509.5, 352, -57.5);
	fh_head2.v3f(510, 287, -57.5);
	glEnd();

	// 6
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 287, -115);
	fh_head2.v3f(510, 352, -127.5);
	fh_head2.v3f(510, 375, -82.5);
	fh_head2.v3f(509.5, 352, -57.5);
	glEnd();

	// 7
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 287, -115);
	fh_head2.v3f(502.5, 270, -127.5);
	fh_head2.v3f(510, 310, -160);
	fh_head2.v3f(510, 352, -127.5);
	glEnd();

	// 8
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(447.5, 260, -147.5);
	fh_head2.v3f(510, 310, -160);
	fh_head2.v3f(502.5, 270, -127.5);
	glEnd();

	// 9 
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 310, -160);
	fh_head2.v3f(510, 352, -160);
	fh_head2.v3f(510, 352, -127.5);
	glEnd();
}

void head2::headRightBtm() {
	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509, 415, 40);		// cc
	fh_head2.v3f(509.5, 415, -12.5);
	fh_head2.v3f(509, 435, 45);		// z
	glEnd();

	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509.5, 415, -12.5);
	fh_head2.v3f(515, 487.5, 0);		// r
	fh_head2.v3f(492.5, 550, 27.5);	// rr
	fh_head2.v3f(509, 435, 45);		// z
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 352, -127.5);
	fh_head2.v3f(509.5, 415, -127.5);
	fh_head2.v3f(509.5, 415, -80);
	fh_head2.v3f(510, 375, -82.5);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 352, -160);
	fh_head2.v3f(509.5, 415, -160);
	fh_head2.v3f(509.5, 415, -127.5);
	fh_head2.v3f(510, 352, -127.5);
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509, 435, 45);		// z
	fh_head2.v3f(492.5, 550, 27.5);	// rr
	fh_head2.v3f(472.5, 532.5, 67.5);	// s
	fh_head2.v3f(467.5, 517.5, 75);	// y = ss
	glEnd();

	// 6
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(492.5, 550, 27.5);	// rr
	fh_head2.v3f(447.5, 587.5, 87.5);	// lowest
	fh_head2.v3f(447.5, 562.5, 87.5);
	fh_head2.v3f(472.5, 532.5, 67.5);	// s
	glEnd();

	// 7
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(447.5, 562.5, 87.5);
	fh_head2.v3f(447.5, 587.5, 87.5);	// lowest
	fh_head2.v3f(427.5, 572.5, 117.5);
	fh_head2.v3f(427.5, 550, 115);
	glEnd();

	// 8
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(427.5, 550, 115);
	fh_head2.v3f(427.5, 572.5, 117.5);
	fh_head2.v3f(400, 572.5, 117.5);
	fh_head2.v3f(400, 550, 115);
	glEnd();

}

void head2::headRightBtm2() {
	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509.5, 415, -160);
	fh_head2.v3f(509.5, 466, -147.5);
	fh_head2.v3f(509.5, 415, -147.5);
	glEnd();

	// 2.1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509.5, 415, -147.5);
	fh_head2.v3f(509.5, 466, -147.5);
	fh_head2.v3f(509.5, 450, -135);
	glEnd();

	// 2.2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509.5, 415, -147.5);
	fh_head2.v3f(509.5, 450, -135);
	fh_head2.v3f(509.5, 415, -80);
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509.5, 415, -80);
	fh_head2.v3f(509.5, 450, -135);
	fh_head2.v3f(515, 487.5, 0);		// r
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509.5, 415, -80);
	fh_head2.v3f(515, 487.5, 0);		// r
	fh_head2.v3f(509.5, 415, -12.5);
	glEnd();
}

void head2::headRightBack() {
	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(400, 180, 0);
	fh_head2.v3f(447.5, 185, 0);
	fh_head2.v3f(447.5, 205, 50);
	fh_head2.v3f(400, 200, 50);
	glEnd();

	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(400, 180, -57.5);
	fh_head2.v3f(447.5, 185, -57.5);
	fh_head2.v3f(447.5, 185, 0);
	fh_head2.v3f(400, 180, 0);
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(400, 207.5, -115);
	fh_head2.v3f(447.5, 212.5, -115);
	fh_head2.v3f(447.5, 185, -57.5);
	fh_head2.v3f(400, 180, -57.5);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(400, 255, -147.5);
	fh_head2.v3f(447.5, 260, -147.5);
	fh_head2.v3f(447.5, 212.5, -115);
	fh_head2.v3f(400, 207.5, -115);
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(400, 310, -170);
	fh_head2.v3f(510, 310, -160);
	fh_head2.v3f(447.5, 260, -147.5);
	fh_head2.v3f(400, 255, -147.5);
	glEnd();

	// 6
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(400, 352, -170);
	fh_head2.v3f(510, 352, -160);
	fh_head2.v3f(510, 310, -160);
	fh_head2.v3f(400, 310, -170);
	glEnd();

	// 7
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(510, 352, -160);
	fh_head2.v3f(400, 352, -170);
	fh_head2.v3f(400, 415, -170);
	fh_head2.v3f(509.5, 415, -160);
	glEnd();

	// 8
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(509.5, 415, -160);
	fh_head2.v3f(400, 415, -170);
	fh_head2.v3f(400, 466, -157.5);
	fh_head2.v3f(509.5, 466, -147.5);
	glEnd();

}

void head2::headLeftTop1() {
	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 447.5, 185, 0);
	fh_head2.v3f(800.0 - 502.5, 222.5, 0);
	fh_head2.v3f(800.0 - 502.5, 240, 40);
	fh_head2.v3f(800.0 - 447.5, 205, 50);
	glEnd();

	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 447.5, 185, -57.5);
	fh_head2.v3f(800.0 - 502.5, 222.5, -57.5);
	fh_head2.v3f(800.0 - 502.5, 222.5, 0);
	fh_head2.v3f(800.0 - 447.5, 185, 0);
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 447.5, 212.5, -115);
	fh_head2.v3f(800.0 - 502.5, 240, -115);
	fh_head2.v3f(800.0 - 502.5, 222.5, -57.5);
	fh_head2.v3f(800.0 - 447.5, 185, -57.5);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 447.5, 260, -147.5);
	fh_head2.v3f(800.0 - 502.5, 270, -127.5);
	fh_head2.v3f(800.0 - 502.5, 240, -115);
	fh_head2.v3f(800.0 - 447.5, 212.5, -115);
	glEnd();
}

void head2::headLeftTop2() {
	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 502.5, 240, 40);
	fh_head2.v3f(800.0 - 510, 335, 27.5);
	fh_head2.v3f(800.0 - 522.5, 287.5, 55);
	//fh_head2.v3f(800.0 - 504, 387.5, 60);		// aa
	//fh_head2.v3f(800.0 - 509.5, 352, 72.5);	// d?
	//fh_head2.v3f(800.0 - 522.5, 287.5, 55);
	glEnd();

	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 522.5, 287.5, 55);
	fh_head2.v3f(800.0 - 510, 335, 27.5);
	fh_head2.v3f(800.0 - 509.5, 375, 72.5);
	fh_head2.v3f(800.0 - 509.5, 352, 72.5);	// d?
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 502.5, 222.5, 0);
	fh_head2.v3f(800.0 - 510, 287, 0);
	fh_head2.v3f(800.0 - 510, 335, 27.5);
	fh_head2.v3f(800.0 - 502.5, 240, 40);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 502.5, 222.5, -57.5);
	fh_head2.v3f(800.0 - 510, 287, -57.5);
	fh_head2.v3f(800.0 - 510, 287, 0);
	fh_head2.v3f(800.0 - 502.5, 222.5, 0);
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 502.5, 240, -115);
	fh_head2.v3f(800.0 - 510, 287, -115);
	fh_head2.v3f(800.0 - 510, 287, -57.5);
	fh_head2.v3f(800.0 - 502.5, 222.5, -57.5);
	glEnd();

	// 6
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 502.5, 240, -115);
	fh_head2.v3f(800.0 - 502.5, 270, -127.5);
	fh_head2.v3f(800.0 - 510, 287, -115);
	glEnd();

}

void head2::headLeftMid() {
	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 335, 27.5);
	fh_head2.v3f(800.0 - 509.5, 352, -12.5);
	fh_head2.v3f(800.0 - 509.5, 375, 0);
	fh_head2.v3f(800.0 - 509.5, 375, 72.5);
	glEnd();

	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509.5, 375, 0);
	fh_head2.v3f(800.0 - 509.5, 415, -12.5);
	fh_head2.v3f(800.0 - 509, 415, 40);		// cc
	fh_head2.v3f(800.0 - 509.5, 375, 72.5);
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 287, 0);
	fh_head2.v3f(800.0 - 509.5, 352, -12.5);
	fh_head2.v3f(800.0 - 510, 335, 27.5);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 287, -57.5);
	fh_head2.v3f(800.0 - 509.5, 352, -57.5);
	fh_head2.v3f(800.0 - 509.5, 352, -12.5);
	fh_head2.v3f(800.0 - 510, 287, 0);
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 287, -115);
	fh_head2.v3f(800.0 - 509.5, 352, -57.5);
	fh_head2.v3f(800.0 - 510, 287, -57.5);
	glEnd();

	// 6
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 287, -115);
	fh_head2.v3f(800.0 - 510, 352, -127.5);
	fh_head2.v3f(800.0 - 510, 375, -82.5);
	fh_head2.v3f(800.0 - 509.5, 352, -57.5);
	glEnd();

	// 7
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 287, -115);
	fh_head2.v3f(800.0 - 502.5, 270, -127.5);
	fh_head2.v3f(800.0 - 510, 310, -160);
	fh_head2.v3f(800.0 - 510, 352, -127.5);
	glEnd();

	// 8
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 447.5, 260, -147.5);
	fh_head2.v3f(800.0 - 510, 310, -160);
	fh_head2.v3f(800.0 - 502.5, 270, -127.5);
	glEnd();

	// 9 
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 310, -160);
	fh_head2.v3f(800.0 - 510, 352, -160);
	fh_head2.v3f(800.0 - 510, 352, -127.5);
	glEnd();
}

void head2::headLeftBtm() {
	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509, 415, 40);		// cc
	fh_head2.v3f(800.0 - 509.5, 415, -12.5);
	fh_head2.v3f(800.0 - 509, 435, 45);		// z
	glEnd();

	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509.5, 415, -12.5);
	fh_head2.v3f(800.0 - 515, 487.5, 0);		// r
	fh_head2.v3f(800.0 - 492.5, 550, 27.5);	// rr
	fh_head2.v3f(800.0 - 509, 435, 45);		// z
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 352, -127.5);
	fh_head2.v3f(800.0 - 509.5, 415, -127.5);
	fh_head2.v3f(800.0 - 509.5, 415, -80);
	fh_head2.v3f(800.0 - 510, 375, -82.5);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 352, -160);
	fh_head2.v3f(800.0 - 509.5, 415, -160);
	fh_head2.v3f(800.0 - 509.5, 415, -127.5);
	fh_head2.v3f(800.0 - 510, 352, -127.5);
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509, 435, 45);		// z
	fh_head2.v3f(800.0 - 492.5, 550, 27.5);	// rr
	fh_head2.v3f(800.0 - 472.5, 532.5, 67.5);	// s
	fh_head2.v3f(800.0 - 467.5, 517.5, 75);	// y = ss
	glEnd();

	// 6
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 492.5, 550, 27.5);	// rr
	fh_head2.v3f(800.0 - 447.5, 587.5, 87.5);	// lowest
	fh_head2.v3f(800.0 - 447.5, 562.5, 87.5);
	fh_head2.v3f(800.0 - 472.5, 532.5, 67.5);	// s
	glEnd();

	// 7
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 447.5, 562.5, 87.5);
	fh_head2.v3f(800.0 - 447.5, 587.5, 87.5);	// lowest
	fh_head2.v3f(800.0 - 427.5, 572.5, 117.5);
	fh_head2.v3f(800.0 - 427.5, 550, 115);
	glEnd();

	// 8
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 427.5, 550, 115);
	fh_head2.v3f(800.0 - 427.5, 572.5, 117.5);
	fh_head2.v3f(800.0 - 400, 572.5, 117.5);
	fh_head2.v3f(800.0 - 400, 550, 115);
	glEnd();

}

void head2::headLeftBtm2() {
	// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509.5, 415, -160);
	fh_head2.v3f(800.0 - 509.5, 466, -147.5);
	fh_head2.v3f(800.0 - 509.5, 415, -147.5);
	glEnd();

	// 2.1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509.5, 415, -147.5);
	fh_head2.v3f(800.0 - 509.5, 466, -147.5);
	fh_head2.v3f(800.0 - 509.5, 450, -135);
	glEnd();

	// 2.2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509.5, 415, -147.5);
	fh_head2.v3f(800.0 - 509.5, 450, -135);
	fh_head2.v3f(800.0 - 509.5, 415, -80);
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509.5, 415, -80);
	fh_head2.v3f(800.0 - 509.5, 450, -135);
	fh_head2.v3f(800.0 - 515, 487.5, 0);		// r
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509.5, 415, -80);
	fh_head2.v3f(800.0 - 515, 487.5, 0);		// r
	fh_head2.v3f(800.0 - 509.5, 415, -12.5);
	glEnd();
}

void head2::headLeftBack() {
	// Left
	// 1// 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 400, 180, 0);
	fh_head2.v3f(800.0 - 447.5, 185, 0);
	fh_head2.v3f(800.0 - 447.5, 205, 50);
	fh_head2.v3f(800.0 - 400, 200, 50);
	glEnd();

	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 400, 180, -57.5);
	fh_head2.v3f(800.0 - 447.5, 185, -57.5);
	fh_head2.v3f(800.0 - 447.5, 185, 0);
	fh_head2.v3f(800.0 - 400, 180, 0);
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 400, 207.5, -115);
	fh_head2.v3f(800.0 - 447.5, 212.5, -115);
	fh_head2.v3f(800.0 - 447.5, 185, -57.5);
	fh_head2.v3f(800.0 - 400, 180, -57.5);
	glEnd();

	// 4
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 400, 255, -147.5);
	fh_head2.v3f(800.0 - 447.5, 260, -147.5);
	fh_head2.v3f(800.0 - 447.5, 212.5, -115);
	fh_head2.v3f(800.0 - 400, 207.5, -115);
	glEnd();

	// 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 400, 310, -170);
	fh_head2.v3f(800.0 - 510, 310, -160);
	fh_head2.v3f(800.0 - 447.5, 260, -147.5);
	fh_head2.v3f(800.0 - 400, 255, -147.5);
	glEnd();

	// 6
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 400, 352, -170);
	fh_head2.v3f(800.0 - 510, 352, -160);
	fh_head2.v3f(800.0 - 510, 310, -160);
	fh_head2.v3f(800.0 - 400, 310, -170);
	glEnd();

	// 7
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 510, 352, -160);
	fh_head2.v3f(800.0 - 400, 352, -170);
	fh_head2.v3f(800.0 - 400, 415, -170);
	fh_head2.v3f(800.0 - 509.5, 415, -160);
	glEnd();

	// 8
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509.5, 415, -160);
	fh_head2.v3f(800.0 - 400, 415, -170);
	fh_head2.v3f(800.0 - 400, 466, -157.5);
	fh_head2.v3f(800.0 - 509.5, 466, -147.5);
	glEnd();

}

void head2::headTop() {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(372.5, 287.5, 110);
	fh_head2.v3f(352.5, 205, 50);
	fh_head2.v3f(447.5, 205, 50);
	fh_head2.v3f(427.5, 287.5, 110);
	glEnd();
}

void head2::ear() {
	GLUquadricObj* disk = NULL;
	disk = gluNewQuadric();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 0, 0, 1);
	fh_head2.color('r');
	gluQuadricDrawStyle(disk, GLU_FILL);
	gluDisk(disk, 0, fh_head2.yP(55), 50, 50);
	glPopMatrix();
}

void head2::btmCover() {
	// 1 (btm for left and right)
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 427.5, 572.5, 117.5);
	fh_head2.v3f(800.0 - 447.5, 587.5, 87.5);	// lowest
	fh_head2.v3f(447.5, 587.5, 87.5);			// lowest
	fh_head2.v3f(427.5, 572.5, 117.5);
	glEnd();

	// 2
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 492.5, 550, 27.5);		// rr
	fh_head2.v3f(800.0 - 447.5, 587.5, 87.5);	// lowest
	fh_head2.v3f(447.5, 587.5, 87.5);			// lowest
	fh_head2.v3f(492.5, 550, 27.5);			// rr
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 515, 487.5, 0);		// r
	fh_head2.v3f(800.0 - 492.5, 550, 27.5);		// rr
	fh_head2.v3f(492.5, 550, 27.5);			// rr
	fh_head2.v3f(515, 487.5, 0);				// r
	glEnd();

	// 3
	glColor3f(1.0, 1.0, 1.0);
	glBegin(type5);
	fh_head2.v3f(800.0 - 509.5, 415, -127.5);
	fh_head2.v3f(800.0 - 515, 487.5, 0);		// r
	fh_head2.v3f(515, 487.5, 0);		// r
	fh_head2.v3f(509.5, 415, -127.5);
	glEnd();
}