#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include "Function.h"
#include "Body.h"
#include "Weapon.h"

using namespace N;
using namespace std;
using namespace B;
using namespace W;

function fh3;

GLenum glQuad3 = GL_QUADS, glLine3 = GL_LINE_LOOP, glTri3 = GL_TRIANGLES;
GLenum glutype = GLU_FILL, glutype4 = GLU_LINE;
float baseRadius = 0.2, topRadius = baseRadius, height = 0.5, slice = 30, stack = slice;
float baseRadius2 = 0.18, topRadius2 = baseRadius2;
float wZoom = 0.2;
void weapon::frontGun() {
	// outer surface
	glColor3f(0.2, 0.6, 0.8);
	fh3.cylinder(glutype, baseRadius, topRadius, height, slice, stack);
	fh3.color('o');
	fh3.cylinder(glutype4, baseRadius + 0.001, topRadius + 0.001, height, 15, 1);

	// inner surface
	glColor3f(0.4, 0.4, 0.8);
	fh3.cylinder(glutype, baseRadius2, topRadius2, height, slice, stack);

	// ring back
	fh3.color('r');
	glPushMatrix();
	fh3.disk(glutype, 0, baseRadius, slice, 1);
	glPopMatrix();

	// ring front
	fh3.color('b');
	glPushMatrix();
	glTranslatef(0, 0, height);
	fh3.disk(glutype, baseRadius2, baseRadius, slice, 1);
	glPopMatrix();
}

void weapon::weaponRing() {

	// outer surface
	glColor3f(0.2, 0.6, 0.8);
	fh3.cylinder(glutype, baseRadius, topRadius, height / 8, slice, stack);
	fh3.color('o');
	fh3.cylinder(glutype4, baseRadius + 0.001, topRadius + 0.001, height / 8, 15, 1);

	// front
	fh3.color('c');
	fh3.disk(glutype, 0, baseRadius, slice, 1);

	// back
	fh3.color('y');
	glPushMatrix();
	glTranslatef(0, 0, height / 8);
	fh3.disk(glutype, 0, baseRadius, slice, 1);
	glPopMatrix();
}

void weapon::weaponRing2() {

	// outer surface
	glColor3f(0.2, 0.6, 0.8);
	fh3.cylinder(glutype, baseRadius + 0.03, topRadius + 0.03, (height + 0.1) / 8, slice, stack);
	fh3.color('o');
	fh3.cylinder(glutype4, baseRadius + 0.031, topRadius + 0.031, (height + 0.1) / 8, 15, 1);

	// front
	fh3.color('c');
	fh3.disk(glutype, 0, baseRadius + 0.03, slice, 1);

	// back
	fh3.color('y');
	glPushMatrix();
	glTranslatef(0, 0, (height + 0.03) / 8);
	fh3.disk(glutype, 0, baseRadius + 0.03, slice, 1);
	glPopMatrix();
}

void weapon::holder() {
	fh3.color('g');
	fh3.cylinder(glutype, 0.15, 0.15, 0.3, slice, stack);

	// down
	fh3.color('r');
	glPushMatrix();
	glTranslatef(0, 0, 0.3);
	fh3.cylinder(glutype, 0.15, 0.1, 0.05, slice, stack);
	glPopMatrix();

	// up
	fh3.color('r');
	glPushMatrix();
	glTranslatef(0, 0, -0.05);
	fh3.cylinder(glutype, 0.1, 0.15, 0.05, slice, stack);
	glPopMatrix();

	// up up
	glPushMatrix();
	glTranslatef(0, 0, -0.11);
	fh3.color('w');
	fh3.cylinder(glutype, 0.1, 0.1, 0.06, slice, stack);
	glPopMatrix();

	// up up up
	glPushMatrix();
	glTranslatef(0, 0, -0.17);
	fh3.color('b');
	fh3.cylinder(glutype, 0.12, 0.1, 0.06, slice, stack);
	glPopMatrix();

	// btm
	glPushMatrix();
	glTranslatef(0, 0, 0.4);
	fh3.color('b');
	fh3.sphere(glutype, 0.1, slice, stack);
	glPopMatrix();
}

void weapon::bullet(float i, boolean gunFireOn, float bulletShot) {
	if (gunFireOn) {
		glPushMatrix();
		glRotatef(-90, 0, 1, 0);
		glTranslatef(0, 0, bulletShot);
		glRotatef(i, 0, 0, 1);
		glTranslatef(0, 0.12, 0);
		fh3.sphere(glutype, 0.02, slice, stack);
		glPopMatrix();
	}
}

void weapon::pipe(float i) {
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glRotatef(i, 0, 0, 1);
	glTranslatef(0, 0.12, 0);
	glTranslatef(0, 0, -0.5);

	glPushMatrix();
	fh3.color('b');
	fh3.cylinder(glutype, 0.02, 0.02, 1.5, slice, stack);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 1.5);
	fh3.color('w');
	fh3.disk(glutype, 0, 0.02, slice, 1);
	glPopMatrix();
	glPopMatrix();
}

void weapon::gun(float gunRotating, float gunXRotating, boolean gunFireOn, float bulletShot) {
	//
	glPushMatrix();
	glScalef(wZoom, wZoom, wZoom);
	glTranslatef(1, 0, 0);
	glRotatef(15, 0, 0, 1);
	glTranslatef(-0.2, 0, -0.4);
	glRotatef(90, 0, 1, 0);
	glTranslatef(-0.6, 3.6, -0.5);
	glTranslatef(0.7, 0, 0);

	glTranslatef(0, -0.7, 0);
	glRotatef(gunXRotating - 90, 0, 0, 1);
	glTranslatef(0, 0.7, 0);

	glTranslatef(-0.7, 0.4, 0);
	
	// ==================== gun ====================
	glPushMatrix();
	glRotatef(gunRotating, 1, 0, 0);

	// pipe
	glPushMatrix();
	for (int i = 0; i < 360; i += 45) {	// got 8 cylinder
		bullet(i, gunFireOn, bulletShot);	// 1 * 8 = 8
		pipe(i);	// 2 * 8 = 16
	}
	glPopMatrix();

	// ring
	glPushMatrix();
	
	glTranslatef(-0.5, 0, 0);
	glRotatef(90, 0, 1, 0);
	weaponRing();	// 4
	glPopMatrix();

	// ring
	glPushMatrix();
	glTranslatef(-0.65, 0, 0);
	glRotatef(90, 0, 1, 0);
	weaponRing();	// 4
	glPopMatrix();

	// middle ring
	glPushMatrix();
	glTranslatef(-0.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	weaponRing2();	// 4
	glPopMatrix();
	
	// front
	glPushMatrix();
	glTranslatef(-0.75, 0, 0);
	glRotatef(-90, 0, 1, 0);
	frontGun();		// 5
	glPopMatrix();

	// middle back ring
	glPushMatrix();
	glTranslatef(0.3, 0, 0);
	glRotatef(90, 0, 1, 0);
	weaponRing2();	// 4
	glPopMatrix();

	glPopMatrix();

	// =============================================
	
	// ================== holder ===================

	glPushMatrix();
	glTranslatef(0.7, -0.45, 0);
	glPushMatrix();
	glTranslatef(0, -0.1, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	holder();	// 6
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.15, 0.15, -0.15);
	fh3.color('w');
	fh3.cube(glQuad3, 0.3, 3);	// 6
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	// =============================================

	// ================= gun back ==================

	// back
	glPushMatrix();
	glTranslatef(0.85, 0, 0);
	glRotatef(-90, 0, 1, 0);
	frontGun();	// 5
	glPopMatrix();

	// back 2
	glPushMatrix();
	glTranslatef(1.355, 0, 0);
	glRotatef(-90, 0, 1, 0);
	frontGun();	// 5
	glPopMatrix();

	// middle back ring 2
	glPushMatrix();
	glTranslatef(1.355, 0, 0);
	glRotatef(90, 0, 1, 0);
	weaponRing2();	// 4
	glPopMatrix();

	// =============================================

	glPopMatrix();
}

void weapon::sword(float swordMiddle) {
	glPushMatrix();
	glScalef(wZoom + 0.2, wZoom, wZoom);

	// holder
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	fh3.color('b');
	fh3.cylinder(glutype, 0.08, 0.08, 0.7, slice, stack);
	glPopMatrix();

	// middle
	glPushMatrix();
	glTranslatef(-swordMiddle, 0, 0);	// x = -0.5
	glRotatef(90, 0, 1, 0);
	fh3.color('c');
	fh3.cylinder(glutype, 0.05, 0.08, 0.7, slice, stack);
	glPopMatrix();

	// front
	glPushMatrix();
	glTranslatef(-(swordMiddle * 2), 0, 0);	// x = -0.5
	glRotatef(90, 0, 1, 0);
	fh3.color('y');
	fh3.cylinder(glutype, 0.05, 0.05, 0.7, slice, stack);
	glPopMatrix();

	// front top
	glPushMatrix();
	glTranslatef(-((swordMiddle) * 2 + 0.1), 0, 0);	// x = -0.5
	glRotatef(90, 0, 1, 0);
	fh3.color('r');
	fh3.cylinder(glutype, 0.08, 0.08, 0.1, slice, stack);
	fh3.color('c');
	fh3.disk(glutype, 0, 0.08, slice, 1);
	glPopMatrix();

	glPopMatrix();
}