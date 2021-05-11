#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#ifndef MY_CLASS_HEAD2 // include guard
#define MY_CLASS_HEAD2

namespace H2 {
	class head2 {
	public:
		void eye();
		void rightTop();
		void eyeMid();
		void leftTop();
		void rightBtm();
		void leftBtm();
		void mask();
		void headRightTop1();
		void headRightTop2();
		void headRightMid();
		void headRightBtm();
		void headRightBtm2();
		void headRightBack();
		void headLeftTop1();
		void headLeftTop2();
		void headLeftMid();
		void headLeftBtm();
		void headLeftBtm2();
		void headLeftBack();
		void headTop();
		void ear();
		void btmCover();
	};
}

#endif /* MY_CLASS_H2 */