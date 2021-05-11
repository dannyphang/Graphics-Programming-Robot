#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "GL Testing"
#define CW_USEDEFAULT 10
#define VALUE 800.0
#define WIDTH VALUE
#define HEIGHT VALUE
#define DEPTH VALUE
#define M_PI 3.141593

int qNo = 1;
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
		else if (wParam == 0x31) {
			qNo = 1;
		}
		else if (wParam == VK_LEFT) {
            
		}
		else if (wParam == VK_RIGHT) {
			
		}
		else if (wParam == VK_UP) {
			
		}
		else if (wParam == VK_DOWN) {
			
		}
		else if (wParam == 0x32) {
			qNo = 2;
		}
		else if (wParam == VK_SPACE) {
			
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

float xC(float x) {
	float xCoor, width = WIDTH / 2;
	if (x < width) {
		xCoor = (x / width) - 1;
	}
	else if (x > width) {
		xCoor = (x - width) / width;
	}
	else if (x == width) {
		xCoor = 0.0;
	}
	return xCoor;
}

float zC(float z) {
	float zCoor, depth = DEPTH / 2;
	/*if (z < 0) {
		zCoor = (z / depth);
	}
	else if (z > depth) {
		zCoor = (z - depth) / depth;
	}
	else if (z == depth) {
		zCoor = 0;
	}*/
	return (z / depth);
}

float yC(float y) {
	float yCoor, height = HEIGHT / 2;
	if (y < height) {
		yCoor = 1 - (y / height);
	}
	else if (y > height) {
		yCoor = 0 - ((y - height) / height);
	}
	else if (y == height) {
		yCoor = 0.0;
	}
	return yCoor;
}

float xP(float x) {
	return (x / (WIDTH / 2));
}

float yP(float y) {
	return (y / (HEIGHT / 2));
}

float zP(float z) {
	return (z / (DEPTH / 2));
}

float cC(float color) {
	return (color / 255);
}

void v2f(float xpixel, float ypixel) {
	glVertex2f(xC(xpixel), yC(ypixel));
}

void v3f(float xpixel, float ypixel, float zpixel) {
	glVertex3f(xC(xpixel), yC(ypixel), zC(zpixel));
}

void sphere(float xradius, float yradius, float zradius, /* int xaxis, int yaxis, float zaxis,  */float xmin, float xmax, float ymin, float ymax) {
	float i, j, lats = 100, longs = 100;
	float x2 = xC(xaxis), y2 = yC(yaxis), z2 = zC(zaxis);
	float xr = xP(xradius), yr = yP(yradius), zr = zP(zradius);

	for (i = xmin; i <= xmax; i++) {
		float lat0 = M_PI * (-0.5 + (i - 1) / lats);
		float z0 = sin(lat0);
		float zr0 = cos(lat0);

		float lat1 = M_PI * (-0.5 + i / lats);
		float z1 = sin(lat1);
		float zr1 = cos(lat1);

		glBegin(GL_POLYGON);
		for (j = ymin; j <= ymax; j++) {
			float lng = 2 * M_PI * (j - 1.0) / longs;
			float x = cos(lng);
			float y = sin(lng);

			glColor3f(1, 1, 1);
			//glNormal3f(x2 + x * zr0, y2 + y * zr0, z2 + z0);
			glVertex3f(x2 + xr * x * zr0, y2 + yr * y * zr0, z2 + zr * z0);

			glColor3f(1, 0, 0);
			//glNormal3f(x2 + x * zr1, y2 + y * zr1, z2 + z1);
			glVertex3f(x2 + xr * x * zr1, y2 + yr * y * zr1, z2 + zr * z1);
		}
		glEnd();
	}
}

//full circle
void circle(GLenum type, float radius, float x, float y, float lineWidth) {
	float x2 = 0, y2 = 0;
	float min = 0, max = 2 * PI;
	glLineWidth(lineWidth);
	glBegin(type);
	for (angle = min; angle < max; angle += max / noOfSegment)
	{
		x2 = x + radius * cos(angle);
		y2 = y + radius * sin(angle);

		v2f(x2, y2);
	}
	glEnd();
}
//curve
//i separated it so that when we want to draw a circle we don't need to put in so many parameters
void circle(GLenum type, float radius, float x, float y, float min, float max, float lineWidth) {
	float x2 = 0, y2 = 0;
	// glVertex2f(x, y);
	glLineWidth(lineWidth);
	glBegin(type);
	for (angle = min; angle < max; angle += max / noOfSegment)
	{
		x2 = x + radius * cos(angle);
		y2 = y + radius * sin(angle);

		v2f(x2, y2);
	}
	glEnd();
}
	//float z2;
	for (float i = min; i < max; i++)
	{
		float x2 = xC(x) + cos(i * M_PI / 180.f) * xP(xr);
		float y2 = yC(y) + sin(i * M_PI / 180.f) * yP(yr);
		glVertex2f(x2, y2);
	}
}

void triangle(GLenum type, float base, float height, int lineWidth) {
	int xStartCoor = 400, yStartCoor = 400;
	glLineWidth(lineWidth);
	glBegin(type);
		v2f(xStartCoor, yStartCoor);
		v2f(xStartCoor + base, yStartCoor);
		v2f(xStartCoor + (base / 2), yStartCoor - height);
	glEnd();
}

void quad(GLenum type, float length, float height, int lineWidth) {
	int xStartCoor = 400, yStartCoor = 400;
	glLineWidth(lineWidth);
	glBegin(type);
		v2f(xStartCoor, yStartCoor - height);
		v2f(xStartCoor, yStartCoor);
		v2f(xStartCoor + length, yStartCoor);
		v2f(xStartCoor + length, yStartCoor - height);
	glEnd();
}

//for 3D objects, size value follows openGL coordinates, so use xC/yC/zC if you need it in pixels
void pyramid(GLenum type, float size, int lineWidth) {
	glBegin(type);
      //front
      glVertex3f(0, size, 0);
      glVertex3f(-size, -size, size);
      glVertex3f(size, -size, size);
 
      //right
      glVertex3f(0, size, 0);
      glVertex3f(size, -size, size);
      glVertex3f(size, -size, -size);
 
      //back
      glVertex3f(0, size, 0);
      glVertex3f(size, -size, -size);
      glVertex3f(-size, -size, -size);
 
      //left
      glVertex3f( 0, size, 0);
      glVertex3f(-size,-size,-size);
      glVertex3f(-size,-size, size);
   glEnd();

   glBegin(type);
      glVertex3f(-size, -size, size);
      glVertex3f(size, -size, size);
	  glVertex3f(size, -size, size);
	  glVertex3f(size, -size, -size);
	  glVertex3f(size, -size, -size);
	  glVertex3f(-size, -size, -size);
	  glVertex3f(-size, -size, -size);
	  glVertex3f(-size, -size, size);
   glEnd();
}

void cube(GLenum type, float size, int lineWidth) {
	glLineWidth(lineWidth);
	//top
	glBegin(type);
		glVertex3f(0,size,size);
		glVertex3f(0,0,size);
		glVertex3f(size,0,size);
		glVertex3f(size,size,size);
	glEnd();
	//right
	glBegin(type);
		glVertex3f(size,size,size);
		glVertex3f(size,0,size);
		glVertex3f(size,0,0);
		glVertex3f(size,size,0);
	glEnd();
	//left
	glBegin(type);
		glVertex3f(0,size,size);
		glVertex3f(0,0,size);
		glVertex3f(0,0,0);
		glVertex3f(0,size,0);
	glEnd();
	//front
	glBegin(type);
		glVertex3f(0,0,size);
		glVertex3f(size,0,size);
		glVertex3f(size,0,0);
		glVertex3f(0,0,0);
	glEnd();
	//back
	glBegin(type);
		glVertex3f(0,size,size);
		glVertex3f(size,size,size);
		glVertex3f(size,size,0);
		glVertex3f(0,size,0);
	glEnd();
	//bottom
	glBegin(type);
		glVertex3f(0,size,0);
		glVertex3f(size,size,0);
		glVertex3f(size,0,0);
		glVertex3f(0,0,0);
	glEnd();
}
	int xStartCoor = 400, yStartCoor = 400;
	glLineWidth(lineWidth);
	glBegin(type);
		v2f(xStartCoor, yStartCoor - yHeight);
		v2f(xStartCoor, yStartCoor);
		v2f(xStartCoor + xLength, yStartCoor);
		v2f(xStartCoor + xLength, yStartCoor - yHeight);
	glEnd();
}

//need to change to array
void bezierQuad(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float r, float g, float b) {
	float smoothness = 0.01;
	const int numberOfPoints = 500;
	float t;
	double xt[numberOfPoints], yt[numberOfPoints], xt2[numberOfPoints], yt2[numberOfPoints];
	float xD = 0, yD = 0;
	int i;

	float x5 = -x1, x6 = -x2, x7 = -x3, x8 = -x4;

	for (i = 0, t = 0; t <= 1.0; i++, t += smoothness) {
		// left
		xt[i] = pow((1 - t), 3) * x1 + 3 * t * pow((1 - t), 2) * x2 + 3 * pow(t, 2) * (1 - t) * x3 + pow(t, 3) * x4;
		yt[i] = pow((1 - t), 3) * y1 + 3 * t * pow((1 - t), 2) * y3 + 3 * pow(t, 2) * (1 - t) * y3 + pow(t, 3) * y4;
		// right
		xt2[i] = pow((1 - t), 3) * x5 + 3 * t * pow((1 - t), 2) * x6 + 3 * pow(t, 2) * (1 - t) * x7 + pow(t, 3) * x8;
	}

    // border
	glColor3f(0, 0, 0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < numberOfPoints; i++) {
		glVertex2f((xt[i] / 600) - xP(4), (yt[i] / 600));
		glVertex2f((xt2[i] / 600) + xP(3.5), (yt[i] / 600));
	}
	glEnd();

	glColor3f(r, g, b);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < numberOfPoints; i++) {
		// left
		glVertex2f((xt[i] / 600), (yt[i] / 600));
		// right
		glVertex2f((xt2[i] / 600), (yt[i] / 600));
	}
	glEnd();
}

void drawBezier(GLenum type, float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4) {
	float smoothness = 0.02;
	const int numberOfPoints = 500;
	double xt[numberOfPoints], yt[numberOfPoints];
	float xD = 0, yD = 0;
	int i;
	float t;

	for (i = 0, t = 0; t <= 1.0; i++, t += smoothness) {
		xt[i] = pow((1 - t), 3) * x1 + 3 * t * pow((1 - t), 2) * x2 + 3 * pow(t, 2) * (1 - t) * x3 + pow(t, 3) * x4;
		yt[i] = pow((1 - t), 3) * y1 + 3 * t * pow((1 - t), 2) * y2 + 3 * pow(t, 2) * (1 - t) * y3 + pow(t, 3) * y4;
	}

	//glColor3f(1, 0, 0);
	glBegin(type);
	for (i = 0; i < numberOfPoints; i++) {
		glVertex2f((xt[i] / 600), (yt[i] / 600));
	}
	glEnd();
}

void display()
{
	switch (qNo) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 20:
		break;
	default:
		break;
	}
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
		CW_USEDEFAULT, CW_USEDEFAULT, WIDTH, HEIGHT,
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