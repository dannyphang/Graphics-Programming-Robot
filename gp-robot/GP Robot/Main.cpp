#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include <string>
#include <irrKlang.h>
#include "Function.h"
#include "Body.h"
#include "Body2.h"
#include "Head.h"
#include "Head2.h"
#include "Weapon.h"

using namespace N;
using namespace B;
using namespace B2;
using namespace H;
using namespace H2;
using namespace W;
using namespace irrklang;

#define WINDOW_TITLE "IRON-MAN"
#define CW 10
#define VALUE 800.0
#define WIDTH VALUE
#define HEIGHT VALUE
#define DEPTH VALUE
#define ORTHO_VIEW 1.0
#define FRUSTUM_VIEW 1.0

function fh;
body b;
body2 b2;
head h;
head2 h2;
weapon w;

//================ COMMON =================
int actionKeyNo = 1;
std::string str = " ";
std::string walkStr = " ";
GLenum nonGLUtype = GL_POLYGON;
//GLenum nonGLUtype = GL_LINE_LOOP;
GLenum GLUtype = GLU_FILL;
//GLenum GLUtype = GLU_LINE;
float testRotate = 0;
boolean stop = false;

float xxT = 0, yyT = 0;
//================ TEXTURE ================
GLuint texture;	// texture name
BITMAP BMP;			// bitmap structure
HBITMAP hBMP = NULL;	// bitmap handle.
boolean textureOn = false;
LPCSTR textureImg = "redMetal.bmp";
LPCSTR textureImg2 = "universe.bmp";
int textureCount = 1;

//=============== LIGHTING ================
float lightDir = 0;
float lightRX = 0, lightRY = 0, lightRZ = 0;
GLenum lightType = GL_SPECULAR;

float amb[] = {1.0, 1.0, 1.0}; //ambient
//float posDX = lightRX, posDY = light, posDY = 0;
float posA[] = { lightRX, lightRY, lightRZ};
//float diffA[] = { 1.0, 0.0, 0.0 };

float diff[] = { 0.0, 1.0, 0.0 }; //diffuse
float diffD[] = { 0.0, 1.0, 0.0 };
float posD[] = { lightRX, lightRY, lightRZ};
float ambM[] = {1.0, 0.0, 0.0};

float spec[] = { 0.0, 0.0, 1.0 }; //specular
float specM[] = { 0.0, 0.0, 1.0 };
float posS[] = { lightRX, lightRY, lightRZ};
boolean lightOn = false;
float lightCount = 1;

//================= HEAD =================
float AR = 0, AR1 = 0, AR2 = 0, AR3 = 0, AR4 = 0, AR0 = 0, AR01 = 0, AR5 = 0;
float maskRotate = 0, maskRotateSpeed = 0.5;
float nodRotate = 0, nodRotateSpeed = 0.5;
boolean openMask = false, nod = false;

//================= BODY =================
boolean bow = false;

//================= HAND =================
float armLowerRotate = 0, armRSpeed = 5.0, armx = 0, army = 0, armz = 0, armDirection = 1.0, armAngle = 0;
float armx2 = 0, army2 = 0, armz2 = 0, armRotateSpeed = 5;
float armUpperY = 0, armUpperZ = 0;
boolean armTurnUp = false, armTurnDown = false, armUp = false, armDown = false, armUpperRotateZ = false, armUpperRotateY = false;
float fingerRotate = 0, fingerRSpeed = 0, fx = 0, fy = 0, fz = 0 /*, fingerDirection = 0, fingerAngle = 0*/;
float fx2 = 0, fy2 = 0, fz2 = 0;
int fCount = 0, llCount = 0, lrCount = 0, aZCount = 1, aYCount = 0;
boolean fingerBend = false;

//================= LEG ==================
boolean raiseLeftLeg = false, raiseRightLeg = false, autoWalk = false;
float rLeftLeg = 0, rRightLeg = 0, legLSpeed = 0, legRSpeed = 0, walkSpeed = 5;
int walkCount = 0;

//================= VIEW =================
char view = 'p';
boolean isOrtho = false, sideView = true;
float zoom = 0.8, cameraTranslateSpeed = 0.1, rSpeedP = 10.0, isWalkZLimite = false;
float xT = 0, yT = 0, zT = 0, ry = 0;
char rotation = ' ';

//================ WEAPON =================
boolean gunOn = false, gunRotateOn = false, gunFireOn = false, swordOn = false, swordOpenOn = false;
float gunRotating = 0, gunXRotating = 0, bulletShot = 0;
float swordMiddle = 0;

//================= MUSIC =================
ISoundEngine* SoundEngine = createIrrKlangDevice();
boolean isSoundOn = false;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			PostQuitMessage(0);
		}
		else if (wParam == 0x31) {	// press 1.0
			actionKeyNo = 1.0;
		} // 1
		else if (wParam == 0x32) {	// press 2
			actionKeyNo = 2;
		} // 2
		else if (wParam == 0x33) {	// press 3
			actionKeyNo = 3;
		} // 3
		else if (wParam == 0x34) {	// press 4
			actionKeyNo = 4;
		} // 4
		else if (wParam == 0x35) {	// press 5
			actionKeyNo = 5;
		} // 5
		else if (wParam == 0x36) {	// press 6
			actionKeyNo = 6;
		} // 6
		else if (wParam == 0x37) {	// press 7
			actionKeyNo = 7;
		} // 7
		else if (wParam == 0x38) {	// press 8
			actionKeyNo = 8;
		} // 8
		else if (wParam == 0x39) {	// press 9
			actionKeyNo = 9;
		} // 9
		else if (wParam == 0x61) {	// press numpad 1.0
			actionKeyNo = 61;
		} // numpad 1
		else if (wParam == VK_UP) {
			stop = false;
			if (actionKeyNo == 4) {
				if (zT < ORTHO_VIEW) {
					zT += cameraTranslateSpeed;
				}
			}
			else if (actionKeyNo == 5) {	//lighting
				lightRX = 0, lightRY = 1.0, lightRZ = 0;
			}
			else if (actionKeyNo == 9) {
				if (yyT < 1.5) {
					yyT += cameraTranslateSpeed;
				}
			}
			else
				armx = 1.0, army = 0, armz = 0, armUp = true, armDown = false;
		}
		else if (wParam == VK_DOWN) {
			stop = false;
			if (actionKeyNo == 4) {
				if (zT > -ORTHO_VIEW) {
					zT -= cameraTranslateSpeed;
				}
			}
			else if (actionKeyNo == 5) {	//lighting
				lightRX = 0, lightRY = -1.0, lightRZ = 0;
			}
			else if (actionKeyNo == 9) {
				if (yyT > -1.5) {
					yyT -= cameraTranslateSpeed;
				}
			}
			else
				armx = 1.0, army = 0, armz = 0, armUp = false, armDown = true;
		}
		else if (wParam == VK_LEFT) {
			stop = false;
			if (actionKeyNo == 4) {
				if (xT < ORTHO_VIEW) {
					xT += cameraTranslateSpeed;
				}
			}
			else if (actionKeyNo == 5) {	//lighting
				lightRX = -1.0, lightRY = 0, lightRZ = 0;
			}
			else if (rotation == 'x') {
				armx2 = 1.0, army2 = 0, armz2 = 0, armTurnUp = true, armTurnDown = false;
			}
			else if (rotation == 'y') {
				armDirection = +1.0, armTurnDown = true, armTurnUp = false;
			}
			else if (actionKeyNo == 9){
				if (xxT > -1.5) {
					xxT -= cameraTranslateSpeed;
				}
			}
		}
		else if (wParam == VK_RIGHT) {
			stop = false;
			if (actionKeyNo == 4) {
				if (xT > -ORTHO_VIEW) {
					xT -= cameraTranslateSpeed;
				}
			}
			else if (actionKeyNo == 5) {	//lighting
				lightRX = 1.0, lightRY = 0, lightRZ = 0;
			}
			else if (rotation == 'x') {
				armx2 = 1.0, army2 = 0, armz2 = 0, armTurnDown = true, armTurnUp = false;
			}
			else if (rotation == 'y') {
				armDirection = -1.0, armTurnDown = true, armTurnUp = false;
			}
			else if (actionKeyNo == 9) {
				if (xxT < 1.5) {
					xxT += cameraTranslateSpeed;
				}
				
			}
		}
		else if (wParam == VK_SPACE) {
			str = "space";
			armx = 1.00, army = 0, armz = 0, armx2 = 0, army2 = 0, armz2 = 0;
			armAngle = 0, armLowerRotate = 0, armUpperY = 0;
			armUp = false, armDown = false, armTurnUp = false, armTurnDown = false;
			fx = 0, fy = 0, fz = 0, fx2 = 0, fy2 = 0, fz2 = 0;
			fingerRotate = 0, fingerRSpeed = 0, fingerBend = false, fCount = 0;
			
			sideView = false;
			llCount = 0, lrCount = 0;
			rLeftLeg = 0, legLSpeed = 0;
			rRightLeg = 0, legRSpeed = 0;

			armUpperZ = 0;
			rotation = ' ';

			walkCount = 0, autoWalk = 0, zT = 0, isWalkZLimite = false;
			isSoundOn = false;
			lightOn = false, lightRX = 0, lightRY = 0, lightRZ = 0;
		}
		else if (wParam == 0x41) { // A
			if (actionKeyNo == 5)
				lightType = GL_AMBIENT;
		} // A
		else if (wParam == 0x42) { // B to bow or straighten body
			bow = !bow;
		} // B
		else if (wParam == 0x43) { // C
			if (actionKeyNo == 6) {
				textureOn = true;
				textureCount++;
				if (textureCount == 1) {
					textureImg = "redMetal2.bmp";
					lightOn = false, lightRX = 0, lightRY = 0, lightRZ = 0;
					SoundEngine->stopAllSounds();
				}
				if (textureCount == 2) {
					textureImg = "blackMetal.bmp";
					lightOn = false, lightRX = 0, lightRY = 0, lightRZ = 0;
					SoundEngine->stopAllSounds();
				}
				if (textureCount == 3) {
					textureImg = "greenMetal2.bmp";
					lightOn = true;
					lightType = GL_DIFFUSE;
					lightRX = 0, lightRY = 0, lightRZ = 1.0;
					isSoundOn = true;
					SoundEngine->play2D("GreenLight.mp3", isSoundOn);
				}
				if (textureCount == 4) {
					textureCount = 1;
					textureImg = "redMetal2.bmp";
					lightOn = false, lightRX = 0, lightRY = 0, lightRZ = 0;
					SoundEngine->stopAllSounds();
				}
			}
		} // C
		else if (wParam == 0x44) { // D
			if (actionKeyNo == 5)
				lightType = GL_DIFFUSE;
		} // D
		else if (wParam == 0x46) { // F
			stop = false;
			if (fCount % 2 == 0)
				fx = 1, fy = 0, fz = 0, fx2 = 0, fy2 = 1, fz2 = 0, fingerRSpeed = 0.5, fingerBend = true, fCount++;
			else
				fx = 0, fy = 0, fz = 0, fx2 = 0, fy2 = 0, fz2 = 0, fingerRotate = 0, fingerRSpeed = 0, fingerBend = false, fCount++;
		} // F
		else if (wParam == 0x4B) { // K
			walkStr = "k";
			if (lrCount % 2 == 0)
				raiseRightLeg = true, raiseLeftLeg = false, lrCount+=2, llCount-=2, legRSpeed = 2, legLSpeed = -2;
			else
				raiseRightLeg = false, lrCount++, legRSpeed = -2;
		} // K
		else if (wParam == 0x4C) { // L
			walkStr = "l";
			if (llCount % 2 == 0) {
				raiseLeftLeg = true, raiseRightLeg = false, llCount+=2, lrCount-=2, legLSpeed = 2, legRSpeed = -2;
			}
			else
				raiseLeftLeg = false, llCount++, legLSpeed = -2;
		} // L
		else if (wParam == 0x4D) { // M
			if (actionKeyNo == 5)
				lightRX = 0, lightRY = 0, lightRZ = 1.0;
			else {
				openMask = !openMask;
			}
		} // M
		else if (wParam == 0x4E) { // N

			if (actionKeyNo == 5)
				lightRX = 0, lightRY = 0, lightRZ = -1.0;
			else {
				nod = !nod;
			}
		} // N
		else if (wParam == 0x4F){ // O
			
			if (actionKeyNo == 5) {
				lightCount *= -1;
				if (lightCount == -1) {
					lightOn = true;
				}
				else {
					lightOn = false;
				}
			}
		} // O
		else if (wParam == 0x50) { // P
			isOrtho = !isOrtho;
			if (isOrtho) {
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glTranslatef(xxT, yyT, 0.0);
				glOrtho(-ORTHO_VIEW, ORTHO_VIEW, -ORTHO_VIEW, ORTHO_VIEW, -ORTHO_VIEW, ORTHO_VIEW);
			}
			else {
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluPerspective(60.0, 1, FRUSTUM_VIEW, -FRUSTUM_VIEW);
				glFrustum(-FRUSTUM_VIEW, FRUSTUM_VIEW, -FRUSTUM_VIEW, FRUSTUM_VIEW, 1.0, FRUSTUM_VIEW * 2 + 1.0);
			}
		} // P
		else if (wParam == 0x51) { // Q
			if (actionKeyNo != 9) {
				ry += rSpeedP;
			}
		} // Q
		else if (wParam == 0x52) { // R
			if (actionKeyNo != 9) {
				ry -= rSpeedP;
			}
		} // R
		else if (wParam == 0x53) { // S
			if (actionKeyNo == 3)
				sideView = true;
			else if (actionKeyNo == 5)
				lightType = GL_SPECULAR;
			else
				stop = true;
		} // S
		else if (wParam == 0x54) { // T
			if (actionKeyNo == 6) {
				textureOn = !textureOn;
				h.textureOn(textureOn);
				b.textureOn(textureOn);
			}
		} // T
		else if (wParam == 0x57) { // W
			autoWalk = !autoWalk;
			if (autoWalk) {
				walkCount = 1;
			}
			else {
				walkCount = 0;
			}
		} // W
		else if (wParam == 0x58) { // X
			rotation = 'x';
		} //X
		else if (wParam == 0x59) { // Y
			rotation = 'y';
			armUpperRotateY = !armUpperRotateY;
		} // Y
		else if (wParam == 0x5A) { // Z
			rotation = 'z';
			stop = false;
			armUpperRotateZ = !armUpperRotateZ;
		} // Z
		else if (wParam == VK_ADD || wParam == 0xBB) {
			if (zoom < ORTHO_VIEW * 3) {
				zoom += 0.2;
			}
		}
		else if (wParam == VK_SUBTRACT || wParam == 0xBD) {
			if (zoom > ORTHO_VIEW / 4.9) {
				zoom -= 0.2;
			}
		}
		else if (wParam == VK_F1) {	// F1
			gunOn = !gunOn;
			if (gunOn == false) {
				gunFireOn = false;
			}
		}
		else if (wParam == VK_F2) {	// F2
			gunRotateOn = !gunRotateOn;
		}
		else if (wParam == VK_F3) {	// F3
			bulletShot = 0;
			gunFireOn = true;
			isSoundOn = true;
			SoundEngine->play2D("pew.mp3", isSoundOn);
		}
		else if (wParam == VK_F4) {	// F4
			swordOn = !swordOn;
		}
		else if (wParam == VK_F5) {	// F5
			swordOpenOn = !swordOpenOn;
		}
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void lighting() {

	posA[0] = lightRX;
	posA[1] = lightRY;
	posA[2] = lightRZ;

	posD[0] = lightRX;
	posD[1] = lightRY;
	posD[2] = lightRZ;

	posS[0] = lightRX;
	posS[1] = lightRY;
	posS[2] = lightRZ;

	if (lightOn)
		glEnable(GL_LIGHTING);
	else
		glDisable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_POSITION, posA);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT1, GL_POSITION, posD);

	glLightfv(GL_LIGHT2, GL_SPECULAR, spec);
	glLightfv(GL_LIGHT2, GL_POSITION, posS);


	if (lightType == GL_AMBIENT) {
		fh.color('r');
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambM);
	}
	else if (lightType == GL_DIFFUSE) {
		fh.color('g');
		glEnable(GL_LIGHT1);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffD);
	}
	else {
		fh.color('b');
		glEnable(GL_LIGHT2);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specM);
	}

	//glMaterialfv(GL_FRONT, lightType, diffM);
}

void cameraView() {

	if (actionKeyNo == 2) {
		glRotatef(ry, 1.0, 0.0, 0);
	}
	else {
		glRotatef(ry + 180, 0.0, 1.0, 0);
	}
	if (actionKeyNo == 4) {
		glTranslatef(xT, yT, zT);
		//gluLookAt(xT, yT, zT, 1, 1, 1, 1, 0, 0);
	}
	if (autoWalk) {
		glTranslatef(0, 0, zT);
	}

}

GLuint addTexture(LPCSTR textureName) {
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL),
		textureName, IMAGE_BITMAP, 0, 0,
		LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	// Assign texture to polygon
	if (textureOn) {
		fh.color('w'), glEnable(GL_TEXTURE_2D);
	}
	else {
		glDisable(GL_TEXTURE_2D);
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
	DeleteObject(hBMP);

	return texture;
}

void removeTexture(GLuint* textures) {
	glDeleteTextures(1, textures);
	glDisable(GL_TEXTURE_2D);
}

void init() {
	GLuint textures2[1];
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
}

void animation() {
	//==================== test =========================
	{
		testRotate++;
	}
	//===================================================

	//==================== body =========================
	{
		int angle = 10, angle2 = angle + 1, angle3 = angle2 + 1, angle4 = angle - 5, an = 5;

		// press 'B' to bow or straighten the body 
		if (bow) {
			if (AR1 < angle4) {
				AR1 += 0.1;
			}
			if (AR1 == angle4) {
				AR1 = angle4;
			}

			if (AR0 < angle) {
				AR0 += 0.1;
			}
			if (AR0 == angle) {
				AR0 = angle;
			}

			if (AR3 < angle2) {
				AR3 += 0.1;
				if (AR < an) {
					AR += 0.1;
				}
			}
			if (AR3 == angle2) {
				AR3 = angle2;
			}

			if (AR4 < angle3) {
				AR4 += 0.1;
				if (AR2 < (an + an)) {
					AR2 += 0.1;
				}
			}
			if (AR4 == angle3) {
				AR4 = angle3;
			}
		}

		if (!bow) {
			if (AR1 >= 0) {
				AR1 -= 0.1;
			}
			if (AR1 == 0) {
				AR1 = 0;
			}

			if (AR0 >= 0) {
				AR0 -= 0.1;
			}
			if (AR0 == 0) {
				AR0 = 0;
			}

			if (AR3 >= 0) {
				AR3 -= 0.1;
				if (AR >= 0) {
					AR -= 0.1;
				}
			}
			if (AR3 == 0) {
				AR3 = 0;
			}

			if (AR4 >= 0) {
				AR4 -= 0.1;
				if (AR2 >= 0) {
					AR2 -= 0.1;
				}
			}
			if (AR4 == 0) {
				AR4 = 0;
			}
		}
	}
	//===================================================

	// =================== head =========================
	{

		if (openMask && maskRotate <= 30) {
			maskRotate += maskRotateSpeed;
		}
		else if (!openMask && maskRotate > 0) {
			maskRotate -= maskRotateSpeed;
		}

		if (nod && nodRotate < 20) {
			nodRotate += nodRotateSpeed;
		}
		else if (!nod && nodRotate > 0) {
			nodRotate -= nodRotateSpeed;
		}
	}
	// ==================================================

	// =============== arm rotate =======================
	{
		if (rotation == 'z') {
			if (armUpperRotateZ && armUpperZ < 60 && !stop) {
				armUpperZ+=2;
			}
			else if (!armUpperRotateZ && armUpperZ >= 0 && !stop) {
				armUpperZ-=2;
			}
		}
		else if (rotation == 'y') {
			if (armUpperRotateY && armUpperY < 45 && !stop) {
				armUpperY++;
			}
			else if (!armUpperRotateY && armUpperY > -45 && !stop) {
				armUpperY--;
			}
		}

		// for right hand rotate
		if (armTurnUp && !armTurnDown && armLowerRotate > -30 && !stop) {
			armLowerRotate -= armRSpeed;
		}
		else if (armTurnDown && !armTurnUp && armLowerRotate < 90 && !stop) {
			armLowerRotate += armRSpeed;
		}

		// finger animation
		if (fingerBend && fingerRotate <= 45 && !stop)
			fingerRotate += fingerRSpeed;
		else if (!fingerBend && fingerRotate > 45 && !stop) {
			fingerRotate -= fingerRSpeed;
		}
	}
	// =================================================

	// ============== Lower Arm lift ===================
	{
		if (armAngle == 110) {
			armAngle = 110;
		}
		else if (armAngle == 0) {
			armAngle = 0;
			armDown = false;
		}

		if (armUp == true && armAngle <= 110 && !stop) {
			armAngle += armRSpeed;
		}
		else if (armDown == true && !stop) {
			armAngle -= armRSpeed;
		}
	}
	// =================================================

	// ================== Leg ==========================
	{
		// for the leg rotate to back angle 
		if (raiseLeftLeg && rLeftLeg < 45 || !raiseLeftLeg && rLeftLeg > -30)
			rLeftLeg += legLSpeed;
		else if (raiseRightLeg && rRightLeg < 45 || !raiseRightLeg && rRightLeg > -30)
			rRightLeg += legRSpeed;

		// auto walk
		if (autoWalk && !isWalkZLimite) {
			zT += cameraTranslateSpeed / 50;
		}

		if (walkCount == 1) {
			rLeftLeg += walkSpeed, rRightLeg -= walkSpeed, armUpperY -= armRotateSpeed;
		}
		else if (walkCount == 2) {
			rLeftLeg -= walkSpeed, rRightLeg += walkSpeed, armUpperY += armRotateSpeed;
		}

		if (rLeftLeg == 30) {
			walkCount = 2;
		}
		else if (rRightLeg == 30) {
			walkCount = 1;
		}

		if (zT > 1) {
			isWalkZLimite = true;
			walkCount = 0;
		}
	}
	// =================================================

	// ================== Gun ==========================
	{
		if (gunRotateOn) {
			gunRotating++;
		}
	}
	// =================================================

	// ================= sword =========================
	{

		if (swordOn && swordOpenOn) {
			if (swordMiddle < 0.69) {
				swordMiddle += 0.01;
			}
		}
		else if (swordOn && !swordOpenOn) {
			if (swordMiddle > 0.01) {
				swordMiddle -= 0.01;
			}
		}
	}
	// =================================================
}

void face() {
	GLuint textures2[1];
	if (textureOn || !textureOn) {
		textures2[0] = addTexture("dannyFace.bmp");
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 1.0), fh.v3f(800.0 - 500.0, 260.0, 53.0);
		glTexCoord2f(0.1, 0.0), fh.v3f(800.0 - 467.5, 517.5, 75);
		glTexCoord2f(0.9, 0.0), fh.v3f(467.5, 517.5, 75);
		glTexCoord2f(1.0, 1.0), fh.v3f(500.0, 260.0, 53.0);
		glEnd();
		glDeleteTextures(1, &textures2[0]);
		glDisable(GL_TEXTURE_2D);
	}
}

void helmet() {
	GLuint textures2[2];
	glPushMatrix();
	glRotatef(nodRotate, 1, 0, 0);

	glPushMatrix();
	glScalef(1, 1, 1.3);

	h.headTop();

	// right
	h.headRightTop1();
	h.headRightTop2();
	h.headRightMid();
	h.headRightBtm();
	h.headRightBtm2();
	h.headRightBack();

	// left
	h.headLeftTop1();
	h.headLeftTop2();
	h.headLeftMid();
	h.headLeftBtm();
	h.headLeftBtm2();
	h.headLeftBack();

	glPushMatrix();
	glTranslatef(0, 0, -0.65); // back to original place
	glRotatef(-maskRotate, 1, 0, 0);
	glTranslatef(0, 0, 0.65); // go to center point
	
	h.mask();

	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.9, 0.9);
	face();
	
	textures2[1] = addTexture(textureImg);
	glPopMatrix();
	h.btmCover();
	glPopMatrix();

	// right
	glTranslatef(fh.xP(-115), fh.yP(10), -fh.zP(55));
	h.ear();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	fh.cylinder(GLU_FILL, fh.yP(55), fh.yP(55), fh.yP(230), 50, 50);
	glPopMatrix();

	// right
	glTranslatef(fh.xP(230), fh.yP(0), fh.zP(0));
	h.ear();

	glPopMatrix();
	glDeleteTextures(1, &textures2[1]);
}

void helmet2() {
	helmet();
	GLuint textures2[2];
	glPushMatrix();
	glRotatef(nodRotate, 1, 0, 0);

	glPushMatrix();
	glScalef(1, 1, 1.3);

	h2.headTop();

	// right
	h2.headRightTop1();
	h2.headRightTop2();
	h2.headRightMid();
	h2.headRightBtm();
	h2.headRightBtm2();
	h2.headRightBack();

	// left
	h2.headLeftTop1();
	h2.headLeftTop2();
	h2.headLeftMid();
	h2.headLeftBtm();
	h2.headLeftBtm2();
	h2.headLeftBack();

	glPushMatrix();
	glTranslatef(0, 0, -0.65); // back to original place
	glRotatef(-maskRotate, 1, 0, 0);
	glTranslatef(0, 0, 0.65); // go to center point

	h2.mask();

	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.9, 0.9);
	face();

	//glDeleteTextures(1, &textures2[0]);
	textures2[1] = addTexture(textureImg);
	glPopMatrix();
	h2.btmCover();
	glPopMatrix();

	// right
	glTranslatef(fh.xP(-115), fh.yP(10), -fh.zP(55));
	h2.ear();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	fh.cylinder(GLU_FILL, fh.yP(55), fh.yP(55), fh.yP(230), 50, 50);
	glPopMatrix();

	// right
	glTranslatef(fh.xP(230), fh.yP(0), fh.zP(0));
	h2.ear();

	glPopMatrix();
	glDeleteTextures(1, &textures2[1]);
}

void finger(GLenum type, float size, float size2, int lineWidth) {
	glPushMatrix();
	if (fingerBend)
		glRotatef(fingerRotate * 2, fx2, fy2, fz2);
	glPushMatrix();
	glTranslatef(-size / 3.0 * 2, size, 0);

	glRotatef(-90, 0, 0, 1);
	//fh.color('r');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();

	glPushMatrix();
	if (fingerBend)
		glRotatef(fingerRotate, fx2, fy2, fz2);
	glPushMatrix();
	glTranslatef(-size / 3.0, size, 0);
	
	glRotatef(-90, 0, 0, 1);
	//fh.color('g');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(-size / 3.0 * 2.0, size - 0.15, size / 5.0);
	if (fingerBend) {
		glTranslatef(-size / 3.0 * 2.0, size - 0.15, size / 5.0 - 0.5);
		glRotatef(-fingerRotate, fx2, fy2, fz2);
		glTranslatef(-(-size / 3.0 * 2.0), -(size - 0.15), -size / 5.0);
	}
	fh.color('y');
	fh.sphere(GLU_LINE, size / 8.0, 10, 10);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void finger2(GLenum type, float size, float size2, int lineWidth) {
	glPushMatrix();
	if (fingerBend)
		glRotatef(-fingerRotate * 2, fx2, fy2, fz2);
	glPushMatrix();
	glTranslatef(-size / 3.0 * 2, size, 0);

	glRotatef(-90, 0, 0, 1);
	//fh.color('r');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();

	glPushMatrix();
	if (fingerBend)
		glRotatef(-fingerRotate, fx2, fy2, fz2);
	glPushMatrix();
	glTranslatef(-size / 3.0, size, 0);

	glRotatef(-90, 0, 0, 1);
	//fh.color('g');
	fh.cuboid(type, size / 3.0, size2, lineWidth);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();

	glPushMatrix();
	glTranslatef(-size / 3.0 * 2.0, size - 0.15, size / 5.0);
	if (fingerBend) {
		glTranslatef(-size / 3.0 * 2.0, size - 0.15, size / 5.0 - 0.5);
		glRotatef(-fingerRotate, fx2, fy2, fz2);
		glTranslatef(-(-size / 3.0 * 2.0), -(size - 0.15), -size / 5.0);
	}
	fh.color('y');
	fh.sphere(GLU_LINE, size / 8.0, 10, 10);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void leftPalm(GLenum type, float size, float size2, int lineWidth) {
	//--------------------palm--------------------
	glPushMatrix();
	glTranslatef(0, 0, -0.25);
	glLineWidth(lineWidth);
	//front
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0),	glVertex3f(0, size, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, 0, size2);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, 0, size2);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, size, size2);
	glEnd();
	//right
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0),	glVertex3f(size, size, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(size, 0, size2);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, 0, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, size, 0);
	glEnd();
	//left
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0),	glVertex3f(0, size, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, 0, size2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, 0, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(0, size, 0);
	glEnd();
	//bottom
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0),	glVertex3f(0, 0, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, 0, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, 0, size2);
	glEnd();
	//top
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0),	glVertex3f(0, size, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, size, 0);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, size, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, size, size2);
	glEnd();
	//back
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0),	glVertex3f(0, size, 0);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, 0, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, size, 0);
	glEnd();
	glPopMatrix();

	//--------------------thumb--------------------
	glPushMatrix();
	if (fingerBend) {
		glTranslatef(0, 0, -0.5);
		glRotatef(fingerRotate, fx, fy, fz);
	}
	glPushMatrix();
	glTranslatef(size * 2 / 3.0 + 0.1, size, 0);

	glRotatef(90, 0, 0, 1);
	fh.cuboid(type, size / 2.5, 1, lineWidth);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	if (fingerBend) {
		glTranslatef(0, 0, -0.5);
		glRotatef(fingerRotate, fx, fy, fz);
	}
	glPushMatrix();
	glTranslatef(size * 2 / 3.0 - 0.1, size + 0.4, 0.2);

	fh.sphere(GLU_LINE, size / 5.0, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//--------------------1st Finger--------------------
	float fSize = size;
	size2 = 0.8;
	finger(type, fSize, size2, lineWidth);

	//--------------------2nd Finger--------------------
	float fty = 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(1.25, 1.0, 1.0);
	finger(type, fSize, size2, lineWidth);
	glPopMatrix();

	//--------------------3rd Finger--------------------
	fty += 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(1.15, 1.0, 1.0);
	finger(type, fSize, size2, lineWidth);
	glPopMatrix();

	//--------------------4th Finger--------------------
	fty += 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(0.8, 1.0, 1.0);
	finger(type, fSize, size2, lineWidth);
	glPopMatrix();
}

void rightPalm(GLenum type, float size, float size2, int lineWidth) {
	//--------------------palm--------------------
	glPushMatrix();
	glTranslatef(0, 0, -0.25);
	glLineWidth(lineWidth);
	//front
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, size, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, 0, size2);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, 0, size2);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, size, size2);
	glEnd();
	//right
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0), glVertex3f(size, size, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(size, 0, size2);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, 0, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, size, 0);
	glEnd();
	//left
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, size, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, 0, size2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, 0, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(0, size, 0);
	glEnd();
	//bottom
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, 0, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, 0, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, 0, size2);
	glEnd();
	//top
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, size, size2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, size, 0);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, size, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, size, size2);
	glEnd();
	//back
	fh.color('w');
	glBegin(type);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, size, 0);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0), glVertex3f(size, 0, 0);
	glTexCoord2f(0.0, 0.0), glVertex3f(size, size, 0);
	glEnd();
	glPopMatrix();

	//--------------------thumb--------------------
	glPushMatrix();
	if (fingerBend) {
		glTranslatef(0, 0, 0.5);
		glRotatef(-fingerRotate, fx, fy, fz);
	}
	glPushMatrix();
	glTranslatef(size * 2 / 3.0 + 0.1, size, 0);

	glRotatef(90, 0, 0, 1);
	fh.cuboid(type, size / 2.5, 1, lineWidth);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	if (fingerBend) {
		glTranslatef(0, 0, 0.5);
		glRotatef(-fingerRotate, fx, fy, fz);
	}
	glPushMatrix();
	glTranslatef(size * 2 / 3.0 - 0.1, size + 0.4, 0.2);

	fh.sphere(GLU_LINE, size / 5.0, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//--------------------1st Finger--------------------
	float fSize = size;
	size2 = 0.8;
	finger2(type, fSize, size2, lineWidth);

	//--------------------2nd Finger--------------------
	float fty = 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(1.25, 1.0, 1.0);
	finger2(type, fSize, size2, lineWidth);
	glPopMatrix();

	//--------------------3rd Finger--------------------
	fty += 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(1.15, 1.0, 1.0);
	finger2(type, fSize, size2, lineWidth);
	glPopMatrix();

	//--------------------4th Finger--------------------
	fty += 0.25;
	glPushMatrix();
	glTranslatef(0, -fty, 0);
	glScalef(0.8, 1.0, 1.0);
	finger2(type, fSize, size2, lineWidth);
	glPopMatrix();
}

void shoe(float height, float footSize, float sRadius, float slices, float stacks) {
	glPushMatrix();
	glRotatef(-90, 1.0, 0, 0);
	glPushMatrix();
	fh.color('w');
	glTranslatef(/*-calfTopRadius - 0.02*/ 0.07, /*(-calfTopRadius - 0.01) * 2*/ -height - 0.07 /*- footSize*/, /*height + footSize*/ -footSize * 0.5);
	////glRotatef(90, 1.0, 0, 0);
	glRotatef(90, 0, 0, 1.0);
	glScalef(footSize, footSize, footSize * 1.25); //foot
	fh.cuboid(nonGLUtype, 1.0, 0.5, 2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -height, footSize * 0.5);
	glScalef(footSize * 0.5, footSize * 0.5, footSize * 0.5);
	glRotatef(220, 1.0, 0, 0);
	fh.pyramid(nonGLUtype, 0.5, 2); //ball of foot
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -height - 0.035, footSize * 1.25);
	glScalef(footSize, footSize * 0.5, footSize);
	glRotatef(90, 1.0, 0, 0);
	fh.pyramid(nonGLUtype, 0.5, 2); //ball of foot
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -height - 0.05, footSize * 1.3);
	glScalef(2.0, 0.75, 2.5);
	fh.sphere(GLUtype, sRadius * 0.4, slices, stacks); //ball of foot
	glPopMatrix();
	glPopMatrix();
}

void armArmour1(GLenum typeQ, GLenum typeT, GLenum typeP) {

	int direction = 1;

	fh.color('w');

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(400, 3, direction * 0);
	glTexCoord2f(1.0, 1.0), fh.v3f(445, 3, direction * 0);
	glTexCoord2f(1.0, 0.0), fh.v3f(445, 33, direction * 94);
	glTexCoord2f(0.0, 0.0), fh.v3f(400, 33, direction * 94);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(445, 3, direction * 0);
	glTexCoord2f(1.0, 1.0), fh.v3f(445, 33, direction * 94);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 33, direction * 94);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(445, 33, direction * 94);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 33, direction * 94);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 75, direction * 152);
	glTexCoord2f(0.0, 0.0), fh.v3f(445, 75, direction * 152);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(445, 3, direction * 0);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 33, direction * 94);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 33, -direction * 94);
	glTexCoord2f(0.0, 0.0), fh.v3f(445, 3, -direction * 0);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(445, 3, direction * 0);
	glTexCoord2f(1.0, 1.0), fh.v3f(445, 33, direction * 94);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 33, direction * 94);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(400, 33, direction * 94);
	glTexCoord2f(1.0, 1.0), fh.v3f(445, 33, direction * 94);
	glTexCoord2f(1.0, 0.0), fh.v3f(445, 75, direction * 152);
	glTexCoord2f(0.0, 0.0), fh.v3f(400, 75, direction * 152);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(540, 33, direction * 94);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 75, direction * 152);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 75, direction * 152);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(540, 33, direction * 94);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 75, direction * 152);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 75, -direction * 152);
	glTexCoord2f(0.0, 0.0), fh.v3f(540, 33, -direction * 94);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(400, 75, direction * 152);
	glTexCoord2f(1.0, 1.0), fh.v3f(400, 100, direction * 171);
	glTexCoord2f(1.0, 0.0), fh.v3f(340, 100, direction * 171);
	glTexCoord2f(0.0, 0.0), glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(400, 75, direction * 152);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 75, direction * 152);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 100, direction * 171);
	glTexCoord2f(0.0, 0.0), fh.v3f(400, 100, direction * 171);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(604, 75, direction * 152);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 100, direction * 171);
	glTexCoord2f(1.0, 0.0), fh.v3f(630, 100, direction * 171);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(604, 75, direction * 152);
	glTexCoord2f(1.0, 1.0), fh.v3f(630, 100, direction * 171);
	glTexCoord2f(1.0, 0.0), fh.v3f(630, 100, -direction * 171);
	glTexCoord2f(0.0, 0.0), fh.v3f(604, 75, -direction * 152);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 100, direction * 171);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 100, direction * 171);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 170, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 170, direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(604, 100, direction * 171);
	glTexCoord2f(1.0, 1.0), fh.v3f(630, 100, direction * 171);
	glTexCoord2f(1.0, 0.0), fh.v3f(685, 170, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(604, 170, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(630, 100, direction * 171);
	glTexCoord2f(1.0, 1.0), fh.v3f(685, 170, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(685, 170, -direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(630, 100, -direction * 171);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 170, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(664, 170, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(664, 253, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 253, direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(664, 170, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(685, 170, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(703, 253, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(664, 253, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(685, 170, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(703, 253, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(703, 253, -direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(685, 170, -direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 253, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 253, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 292, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 292, direction * 202);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(604, 253, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(703, 253, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 292, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(703, 253, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 292, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 292, -direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(703, 253, -direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 292, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 292, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 317, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 317, direction * 202);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(540, 292, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 292, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 317, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(604, 292, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 317, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 317, -direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(604, 292, -direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 317, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 317, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 400, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 400, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(540, 317, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 400, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 400, -direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(540, 317, -direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(470, 400, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 400, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 434, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(445, 434, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(540, 400, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 434, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 434, -direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(540, 400, -direction * 202);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 434, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 434, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(340, 543, direction * 202);
	glEnd();

	//join tgt
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(540, 434, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(340, 543, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(340, 543, -direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(540, 434, -direction * 202);
	glEnd();

	fh.color('r');
	glBegin(typeP);
	fh.circle(400, 400, direction * 204, 77, 77, 0, 360);
	glEnd();
	fh.color('g');
	glBegin(typeP);
	fh.circle(400, 400, direction * 206, 54, 54, 0, 360);
	glEnd();
}

void armArmour2(GLenum typeQ, GLenum typeT, GLenum typeP) {

	int direction = -1;

	fh.color('w');

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(400, 3, direction * 0);
	glTexCoord2f(1.0, 1.0), fh.v3f(445, 3, direction * 0);
	glTexCoord2f(1.0, 0.0), fh.v3f(445, 33, direction * 94);
	glTexCoord2f(0.0, 0.0), fh.v3f(400, 33, direction * 94);
	glEnd();

	//fh.color('y');
	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(445, 3, direction * 0);
	glTexCoord2f(1.0, 1.0), fh.v3f(445, 33, direction * 94);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 33, direction * 94);
	glEnd();

	//fh.color('r');
	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(400, 33, direction * 94);
	glTexCoord2f(1.0, 1.0), fh.v3f(445, 33, direction * 94);
	glTexCoord2f(1.0, 0.0), fh.v3f(445, 75, direction * 152);
	glTexCoord2f(0.0, 0.0), fh.v3f(400, 75, direction * 152);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(445, 33, direction * 94);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 33, direction * 94);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 75, direction * 152);
	glTexCoord2f(0.0, 0.0), fh.v3f(445, 75, direction * 152);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(540, 33, direction * 94);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 75, direction * 152);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 75, direction * 152);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(400, 75, direction * 152);
	glTexCoord2f(1.0, 1.0), fh.v3f(400, 100, direction * 171);
	glTexCoord2f(1.0, 0.0), fh.v3f(340, 100, direction * 171);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(400, 75, direction * 152);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 75, direction * 152);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 100, direction * 171);
	glTexCoord2f(0.0, 0.0), fh.v3f(400, 100, direction * 171);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(604, 75, direction * 152);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 100, direction * 171);
	glTexCoord2f(1.0, 0.0), fh.v3f(630, 100, direction * 171);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 100, direction * 171);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 100, direction * 171);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 170, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 170, direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(604, 100, direction * 171);
	glTexCoord2f(1.0, 1.0), fh.v3f(630, 100, direction * 171);
	glTexCoord2f(1.0, 0.0), fh.v3f(685, 170, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(604, 170, direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 170, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(664, 170, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(664, 253, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 253, direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(664, 170, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(685, 170, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(703, 253, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(664, 253, direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 253, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 253, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 292, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 292, direction * 202);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(604, 253, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(703, 253, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(604, 292, direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 292, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 292, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 317, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 317, direction * 202);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(540, 292, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(604, 292, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 317, direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 317, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 317, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 400, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(340, 400, direction * 202);
	glEnd();

	glBegin(typeQ);
	glTexCoord2f(0.0, 1.0), fh.v3f(470, 400, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 400, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(540, 434, direction * 202);
	glTexCoord2f(0.0, 0.0), fh.v3f(445, 434, direction * 202);
	glEnd();

	glBegin(typeT);
	glTexCoord2f(0.0, 1.0), fh.v3f(340, 434, direction * 202);
	glTexCoord2f(1.0, 1.0), fh.v3f(540, 434, direction * 202);
	glTexCoord2f(1.0, 0.0), fh.v3f(340, 543, direction * 202);
	glEnd();

	fh.color('r');
	glBegin(typeP);
	fh.circle(400, 400, direction * 204, 77, 77, 0, 360);
	glEnd();
	fh.color('g');
	glBegin(typeP);
	fh.circle(400, 400, direction * 206, 54, 54, 0, 360);
	glEnd();
}

void armArmour() {
	/*GLenum typeQ = GL_LINE_LOOP;
	GLenum typeT = GL_LINE_LOOP;
	GLenum typeP = GL_LINE_LOOP;*/

	GLenum typeQ = GL_QUADS;
	GLenum typeT = GL_TRIANGLES;
	GLenum typeP = GL_POLYGON;

	armArmour1(typeQ, typeT, typeP);
	armArmour2(typeQ, typeT, typeP);
}

void armUpperArmour3() {
	float depth, height = 0.08, length, length2;
	length = 108 / (WIDTH / 2);
	length2 = (length / 3) * 2;
	depth = height;

	glPushMatrix();
	glTranslatef(length, 0, 0);
	glRotatef(180, 0, 1, 0);
	glTranslatef(-length2, 0, 0);
	// 1 (top)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length, height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length, height, -depth / 2);
	glEnd();

	// 2 (top back)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length, height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length, height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, height / 2, depth / 2);
	glEnd();

	// 3 (back)
	if(textureOn)fh.color('w'); else fh.color('c');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length, -height / 2, -depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length, height / 2, -depth);
	glEnd();

	// 4 (back btm)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length, -height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length, -height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height / 2, depth / 2);
	glEnd();

	// 5 (btm)
	if(textureOn)fh.color('w'); else fh.color('w');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length, -height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length, -height, -depth / 2);
	glEnd();

	// 6 (front btm)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length, -height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length, -height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height / 2, -depth / 2);
	glTexCoord2f(0.0, 0.0), glEnd();

	// 7 (front)
	if(textureOn)fh.color('w'); else fh.color('c');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length, -height / 2, depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length, height / 2, depth);
	glEnd();

	// 8 (front top)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length, height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length, height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, height / 2, -depth / 2);
	glEnd();
	glPopMatrix();
}

void armUpperArmour2() {
	float depth, height = 0.08, length, length2;
	length = 108 / (WIDTH / 2);
	length2 = length / 3;
	depth = height;

	// 1 (top)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2, height, -depth / 2);
	glEnd();

	// 2 (top back)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, height / 2, -depth / 2);
	glEnd();

	// 3 (back)
	if(textureOn)fh.color('w'); else fh.color('c');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, -height / 2, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height / 2, -depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2, height / 2, -depth);
	glEnd();

	// 4 (back btm)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, -height / 2, -depth / 2);
	glEnd();

	// 5 (btm)
	if(textureOn)fh.color('w'); else fh.color('w');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, -height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, -height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2, -height, -depth / 2);
	glEnd();

	// 6 (front btm)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, -height / 2, depth / 2);
	glEnd();

	// 7 (front)
	if(textureOn)fh.color('w'); else fh.color('c');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, height / 2, depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, -height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height / 2, depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2, height / 2, depth);
	glEnd();

	// 8 (front top)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, height / 2, depth / 2);
	glEnd();
}

void armUpperArmour() {
	// height = 0.27 or 108 pixel
	float depth, height = 0.08, length, length2;
	length = 108 / (WIDTH / 2);
	length2 = length / 3;
	depth = height;
	glPushMatrix();
	glTranslatef(-0.27, 0, 0);
	// 1 (top)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height, -depth / 2);
	glEnd();

	// 2 (top back)
	if(textureOn)fh.color('w'); else fh.color('b');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, height, -depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height / 2, -depth);
	glEnd();

	// 3 (back)
	if(textureOn)fh.color('w'); else fh.color('g');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, -depth);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height / 2, -depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height / 2, -depth);
	glEnd();

	// 4 (back btm)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height, -depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, -height / 2, -depth);
	glEnd();

	// 5 (btm)
	if(textureOn)fh.color('w'); else fh.color('w');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, -height, -depth / 2);
	glEnd();

	// 6 (front btm)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, -height / 2, depth);
	glEnd();

	// 7 (front)
	if(textureOn)fh.color('w'); else fh.color('g');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, depth);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height / 2, depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height / 2, depth);
	glEnd();

	// 8 (front top)
	if(textureOn)fh.color('w'); else fh.color('b');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height / 2, depth);
	glEnd();

	armUpperArmour2();
	armUpperArmour3();

	glPopMatrix();
}

void legUpperArmour3() {
	float depth, height = 0.1, length, length2;
	length = 0.52;
	length2 = (length / 3) * 2;
	depth = height;

	glPushMatrix();
	glTranslatef(length, 0, 0);
	glRotatef(180, 0, 1, 0);
	glTranslatef(-length2, 0, 0);
	// 1 (top)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length, height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length, height, -depth / 2);
	glEnd();

	// 2 (top back)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length, height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length, height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, height / 2, depth / 2);
	glEnd();

	// 3 (back)
	if(textureOn)fh.color('w'); else fh.color('c');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length, -height / 2, -depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length, height / 2, -depth);
	glEnd();

	// 4 (back btm)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length, -height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length, -height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height / 2, depth / 2);
	glEnd();

	// 5 (btm)
	if(textureOn)fh.color('w'); else fh.color('w');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length, -height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length, -height, -depth / 2);
	glEnd();

	// 6 (front btm)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length, -height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length, -height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height / 2, -depth / 2);
	glEnd();

	// 7 (front)
	if(textureOn)fh.color('w'); else fh.color('c');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length, -height / 2, depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length, height / 2, depth);
	glEnd();

	// 8 (front top)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length, height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length, height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, height / 2, -depth / 2);
	glEnd();
	glPopMatrix();
}

void legUpperArmour2() {
	float depth, height = 0.1, length, length2;
	length = 0.52;
	length2 = length / 3;
	depth = height;

	// 1 (top)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2, height, -depth / 2);
	glEnd();

	// 2 (top back)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, height / 2, -depth / 2);
	glEnd();

	// 3 (back)
	if(textureOn)fh.color('w'); else fh.color('c');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, -height / 2, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height / 2, -depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2, height / 2, -depth);
	glEnd();

	// 4 (back btm)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, -height / 2, -depth / 2);
	glEnd();

	// 5 (btm)
	if(textureOn)fh.color('w'); else fh.color('w');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, -height / 2, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, -height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2, -height, -depth / 2);
	glEnd();

	// 6 (front btm)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, -height / 2, depth / 2);
	glEnd();

	// 7 (front)
	if(textureOn)fh.color('w'); else fh.color('c');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(0, height / 2, depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(0, -height / 2, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2, -height / 2, depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2, height / 2, depth);
	glEnd();

	// 8 (front top)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(0, height / 2, depth / 2);
	glEnd();
}

void legUpperArmour() {
	// height = 0.27 or 108 pixel
	float depth, height = 0.1, length, length2;
	length = 0.52;
	length2 = length / 3;
	depth = height;
	glPushMatrix();
	glTranslatef(-0.27, 0, 0);
	// 1 (top)
	if(textureOn)fh.color('w'); else fh.color('r');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height, -depth / 2);
	glEnd();

	// 2 (top back)
	if(textureOn)fh.color('w'); else fh.color('b');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, height, -depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height / 2, -depth);
	glEnd();

	// 3 (back)
	if(textureOn)fh.color('w'); else fh.color('g');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, -depth);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height / 2, -depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height / 2, -depth);
	glEnd();

	// 4 (back btm)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, -depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, -depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height, -depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, -height / 2, -depth);
	glEnd();

	// 5 (btm)
	if(textureOn)fh.color('w'); else fh.color('w');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height, -depth / 2);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, -height, -depth / 2);
	glEnd();

	// 6 (front btm)
	if(textureOn)fh.color('w'); else fh.color('y');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, -height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, -height / 2, depth);
	glEnd();

	// 7 (front)
	if(textureOn)fh.color('w'); else fh.color('g');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, -height / 2, depth);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, -height / 2, depth);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height / 2, depth);
	glEnd();

	// 8 (front top)
	if(textureOn)fh.color('w'); else fh.color('b');
	glBegin(nonGLUtype);
	glTexCoord2f(0.0, 1.0), glVertex3f(length2, height / 2, depth);
	glTexCoord2f(1.0, 1.0), glVertex3f(length2, height, depth / 2);
	glTexCoord2f(1.0, 0.0), glVertex3f(length2 + length2, height, depth / 2);
	glTexCoord2f(0.0, 0.0), glVertex3f(length2 + length2, height / 2, depth);
	glEnd();

	legUpperArmour2();
	legUpperArmour3();

	glPopMatrix();
}

void leftArm() {
	float uaBaseRadius = 0.05, uaTopRadius = uaBaseRadius - 0.005, height = 0.27, slices = 30, stacks = 30;
	float laBaseRadius = uaTopRadius, laTopRadius = laBaseRadius - 0.01;
	float sRadius = uaTopRadius;
	float palmSize = uaBaseRadius + 0.05;

	glPushMatrix();
	if (armTurnUp || armTurnDown) {
		glRotatef(armLowerRotate, armx2, army2, armz2);
	}
	armUpperArmour();
	glRotatef(-90, 1.0, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);

	glPushMatrix();

	glTranslatef(0, 0, -height);
	if(textureOn)fh.color('w'); else fh.color('g');
	fh.sphere(GLUtype, sRadius, slices, stacks);
	fh.cylinder(GLUtype, uaBaseRadius, uaTopRadius, height, slices, stacks); //upperarm
	glPopMatrix();

	glPushMatrix();
	
	glPushMatrix();
	if(textureOn)fh.color('w'); else fh.color('y');
	fh.sphere(GLUtype, sRadius, slices, stacks); //elbow
	glPopMatrix();

	height -= 0.01;
	glPushMatrix();
	if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);

	if(textureOn)fh.color('w'); else fh.color('r');
	fh.cylinder(GLUtype, laBaseRadius, laTopRadius, height, slices, stacks); //lowerarm
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);

	glPushMatrix();

	// sword
	glPushMatrix();
	glTranslatef(0.05, 0.3, 0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, -0.3, 0);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -0.7);
	glTranslatef(0, 0, 0.3);
	glTranslatef(0, 0, height + 0.1);
	
	if (swordOn && fingerBend) {
		w.sword(swordMiddle);
	}
	glPopMatrix();

	glRotatef(-90, 0.0, 1.0, 0.0);
	glTranslatef(0.27, 0, 0);
	armUpperArmour();
	glPopMatrix();

	glTranslatef(0, -laTopRadius - 0.01, height + palmSize);
	glRotatef(90, 0, 1.0, 0);
	glScalef(palmSize, palmSize, palmSize);
	leftPalm(nonGLUtype, 1.0, 0.5, 2);
	glPopMatrix();
	glPopMatrix();
}

void rightArm() {
	float uaBaseRadius = 0.05, uaTopRadius = uaBaseRadius - 0.005, height = 0.27, slices = 30, stacks = 30;
	float laBaseRadius = uaTopRadius, laTopRadius = laBaseRadius - 0.01;
	float sRadius = uaTopRadius;
	float palmSize = uaBaseRadius + 0.05;

	glPushMatrix();
	if (armTurnUp || armTurnDown) {
		glRotatef(-armLowerRotate, armx2, army2, armz2);
	}
	armUpperArmour();	// add here, jiayou
	glRotatef(90, 1.0, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);

	glPushMatrix();

	glTranslatef(0, 0, -height);
	if(textureOn)fh.color('w'); else fh.color('g');
	fh.sphere(GLUtype, sRadius, slices, stacks);
	fh.cylinder(GLUtype, uaBaseRadius, uaTopRadius, height, slices, stacks); //upperarm
	glPopMatrix();

	glPushMatrix();
	//glRotatef(-90, 1.0, 0, 0);
	//glTranslatef(0, 0, height);

	glPushMatrix();
	if(textureOn)fh.color('w'); else fh.color('y');
	fh.sphere(GLUtype, sRadius, slices, stacks); //elbow
	glPopMatrix();

	height -= 0.01;
	glPushMatrix();
	if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);

	if(textureOn)fh.color('w'); else fh.color('r');
	fh.cylinder(GLUtype, laBaseRadius, laTopRadius, height, slices, stacks); //lowerarm
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	if (armUp || armDown)
		glRotatef(-armAngle, armx, army, armz);

	glPushMatrix();

	glRotatef(-90, 0.0, 1.0, 0.0);
	glTranslatef(0.27, 0, 0);
	armUpperArmour();
	glPopMatrix();
	glTranslatef(0, -laTopRadius - 0.01, height + palmSize);
	glRotatef(90, 0, 1.0, 0);
	glScalef(palmSize, palmSize, palmSize);
	rightPalm(nonGLUtype, 1.0, 0.5, 2);
	glPopMatrix();

	glPopMatrix();
}

void leftLeg() {
	float thighBaseRadius = 0.08, thighTopRadius = thighBaseRadius - 0.01, height = 0.52, slices = 30, stacks = 30;
	float calfBaseRadius = thighTopRadius, calfTopRadius = calfBaseRadius - 0.02;
	float sRadius = thighTopRadius;
	float footSize = thighBaseRadius + 0.05;

	glPushMatrix();
	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glRotatef(-90, 0.0, 0.0, 1.0);
	legUpperArmour();
	glPopMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0, 0, -height);
	if(textureOn)fh.color('w'); else fh.color('g');
	fh.sphere(GLUtype, thighBaseRadius, slices, stacks);
	fh.cylinder(GLUtype, thighBaseRadius, thighTopRadius, height, slices, stacks); //thigh
	glPopMatrix();

	glPushMatrix();
	if(textureOn)fh.color('w'); else fh.color('y');
	fh.sphere(GLUtype, sRadius, slices, stacks); //knee
	glPopMatrix();

	height -= 0.01;
	glPushMatrix();
	if (!(rLeftLeg < 0)) {
		if (raiseLeftLeg && rLeftLeg < 30 || !raiseLeftLeg && rLeftLeg > 0)
			rLeftLeg += legLSpeed;
		glTranslatef(height, 0, 0), glRotatef(rLeftLeg, 1.0, 0, 0), glTranslatef(-height, 0, 0);
	}
	
	glPushMatrix();
	glRotatef(-90, 0.0, 1.0, 0.0);
	glTranslatef(0.25, 0, 0);
	legUpperArmour();
	glPopMatrix();

	if(textureOn)fh.color('w'); else fh.color('r');
	fh.cylinder(GLUtype, calfBaseRadius, calfTopRadius, height, slices, stacks); //calf

	shoe(height, footSize, sRadius, slices, stacks);

	glPopMatrix();
	glPopMatrix();
}

void rightLeg() {
	float thighBaseRadius = 0.08, thighTopRadius = thighBaseRadius - 0.01, height = 0.52, slices = 30, stacks = 30;
	float calfBaseRadius = thighTopRadius, calfTopRadius = calfBaseRadius - 0.02;
	float sRadius = thighTopRadius;
	float footSize = thighBaseRadius + 0.05;

	glPushMatrix();
	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glRotatef(-90, 0.0, 0.0, 1.0);
	legUpperArmour();
	glPopMatrix();

	glRotatef(90, 1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0, 0, -height);
	if(textureOn)fh.color('w'); else fh.color('g');
	fh.sphere(GLUtype, thighBaseRadius, slices, stacks);
	fh.cylinder(GLUtype, thighBaseRadius, thighTopRadius, height, slices, stacks); //thigh
	glPopMatrix();

	glPushMatrix();
	if(textureOn)fh.color('w'); else fh.color('y');
	fh.sphere(GLUtype, sRadius, slices, stacks); //knee
	glPopMatrix();

	height -= 0.01;
	glPushMatrix();
	if (!(rRightLeg < 0)) {
		if (raiseRightLeg && rRightLeg < 30 || !raiseRightLeg && rRightLeg > 0)
			rRightLeg += legRSpeed;
		glTranslatef(height, 0, 0), glRotatef(rRightLeg, 1.0, 0, 0), glTranslatef(-height, 0, 0); // the leg will bend to 90 degree when the leg lift
	}
	glPushMatrix();
	glRotatef(-90, 0.0, 1.0, 0.0);
	glTranslatef(0.25, 0, 0);
	legUpperArmour();
	glPopMatrix();

	if(textureOn)fh.color('w'); else fh.color('r');
	fh.cylinder(GLUtype, calfBaseRadius, calfTopRadius, height, slices, stacks); //calf

	shoe(height, footSize, sRadius, slices, stacks);

	glPopMatrix();
	glPopMatrix();
}

void robotWeapon() {
	if (gunOn) {
		w.gun(gunRotating, gunXRotating, gunFireOn, bulletShot);
	}
	if (gunRotateOn && gunXRotating < 90) {
		gunXRotating++;
	}
	else if (!gunRotateOn && gunXRotating > 0) {
		gunXRotating--;
	}
	if (gunFireOn & gunOn & gunRotateOn) {
		bulletShot += 0.1;
	}
	if (bulletShot > 15) {
		gunFireOn = false;
	}
}

void robotBody() {
	glLineWidth(1);
	GLuint textures3[1];
	// adomen 0 + chest
	glPushMatrix();
	
	
	glRotatef(AR4, 1, 0, 0);
	glTranslatef(0, fh.yP(85), 0);
	glRotatef(AR2, 1, 0, 0);
	b.chest();
	b.adomen0();

	// head
	glPushMatrix();
	glTranslatef(0, fh.yP(185), fh.zP(20));
	glScalef(0.25, 0.25, 0.25);
	helmet2();
	glPopMatrix();

	//arm right
	glPushMatrix();
	textures3[0] = addTexture(textureImg);
	glTranslatef(fh.xP(170), fh.yP(110), fh.zP(0));
	glScalef(0.9, 0.9, 0.9);
	glTranslatef(-0.3, 0, 0);

	// arm armour
	glPushMatrix();
	glTranslatef(0, -0.05, 0);
	glScalef(0.15, 0.15, 0.15);
	armArmour();
	glPopMatrix();

	if (rotation == 'z') {
		glRotatef(armUpperZ, 0, 0, 1);
	}
	if (rotation == 'y' || autoWalk) {
		glRotatef(armUpperY * armDirection, 1, 0, 0);
	}
	glRotatef(-85, 0, 0, 1);
	glTranslatef(0.3, 0, 0);
	rightArm();
	glPopMatrix();

	//arm left
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(fh.xP(170), fh.yP(110), fh.zP(0));
	glScalef(0.9, 0.9, 0.9);
	glTranslatef(-0.3, 0, 0);

	// arm armour
	glPushMatrix();
	glTranslatef(0, -0.05, 0);
	glScalef(0.15, 0.15, 0.15);
	armArmour();
	glPopMatrix();

	if (rotation == 'z') {
		glRotatef(armUpperZ, 0, 0, 1);
	}
	if (rotation == 'y' || autoWalk) {
		glRotatef(armUpperY * armDirection, 1, 0, 0);
	}

	glRotatef(-85, 0, 0, 1);
	glTranslatef(0.3, 0, 0);
	leftArm();
	glPopMatrix();

	glPopMatrix();

	// adomen 1
	glPushMatrix();
	glRotatef(AR3, 1, 0, 0);
	glTranslatef(0, fh.yP(72.5), 0);
	glRotatef(AR, 1, 0, 0);
	b.adomen1();
	glPopMatrix();

	// adomen 2
	glPushMatrix();
	glRotatef(AR0, 1, 0, 0);
	glTranslatef(0, fh.yP(60), 0);
	glRotatef(0, 1, 0, 0);
	b.adomen2();
	glPopMatrix();

	// adomen 3
	glPushMatrix();
	glRotatef(AR1, 1, 0, 0);
	glTranslatef(0, fh.yP(47.5), 0);
	b.adomen3();
	glPopMatrix();

	// below
	glPushMatrix();
	glTranslatef(0, fh.yP(47.5), 0);
	b.below();
	glPopMatrix();

	//left leg
	glPushMatrix();
	glRotatef(-rLeftLeg, 1.0, 0, 0);
	glTranslatef(-fh.xP(35), -fh.yP(140), fh.zP(0));
	glScalef(0.7, 0.7, 0.7);
	leftLeg();
	glPopMatrix();

	//right leg
	glPushMatrix();
	glRotatef(-rRightLeg, 1.0, 0, 0);
	glTranslatef(fh.xP(35), -fh.yP(140), fh.zP(0));
	glScalef(0.7, 0.7, 0.7);
	rightLeg();
	glPopMatrix();

	glDeleteTextures(1, &textures3[0]);
}

void skyBox() {
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	fh.color('w');
	fh.sphere(GLUtype, FRUSTUM_VIEW * 2, 50, 50);
	glPopMatrix();
}

void ground(){
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(0, -fh.yP(300), 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	fh.disk(GLU_FILL, 0, FRUSTUM_VIEW * 1.85, 50, 1);
	glPopMatrix();
}

void display() {
	GLuint textures[10];

	init();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(xxT, yyT, 0.0);
	glScalef(zoom, zoom, zoom);
	
	// sky box
	textures[0] = addTexture("sky.bmp");
	skyBox();
	glDeleteTextures(1, &textures[0]);

	// ground
	textures[1] = addTexture("groundGrass.bmp");
	ground();
	glDeleteTextures(1, &textures[1]);

	animation();

	lighting();

	textures[2] = addTexture(textureImg);

	glPushMatrix();
	cameraView();
	robotBody();
	robotWeapon();
	glPopMatrix();

	glDeleteTextures(1, &textures[2]);
	glDisable(GL_TEXTURE_2D);
}
//--------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW, CW, WIDTH, HEIGHT,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, FRUSTUM_VIEW, -FRUSTUM_VIEW);
	glFrustum(-FRUSTUM_VIEW, FRUSTUM_VIEW, -FRUSTUM_VIEW, FRUSTUM_VIEW, 1.0, FRUSTUM_VIEW * 2 + 1.0);
	
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		display();
		
		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------