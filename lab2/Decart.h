#pragma once
#ifndef _DECART_H_
#define _DECART_H_
#include "gtest\gtest_prod.h"
#include <math.h>
#include <cmath>

namespace Prog2 {
	// ęëŕńń Decart îďđĺäĺë˙ĺň äĺęŕđňîâ ëčńň
	class Decart {
	private:
		double n; // íŕčáîëüřŕ˙ őîđäŕ äĺęŕđňîăî ëčńňŕ
	public:
		Decart(double N = 1); // ďóńňîé ęîíńňđóęňîđ ďî óěîë÷ŕíčţ îďđĺäĺë˙ĺň äĺęŕđňîâ ëčńň ń ěŕęńčěŕëüíîé őîđäîé đŕâíîé 1
		// ńĺňňĺđű
		Decart& setN(double n0);
		// ăĺňňĺđű
		double getN() const { return n; }
		// äđóăčĺ ěĺňîäű
		double square_side() const { return n/sqrt(2); } // ńňîđîíŕ ęâŕäđŕňŕ, ęîňîđŕ˙ đŕâíŕ íŕčáîëüřĺé őîđäĺ ëčńňŕ
			// đŕńńňî˙íčĺ äî öĺíňđŕ â ďîë˙đíîé ńčńňĺěĺ ęîîđäčíŕň â çŕâčńčěîńňč îň óăëŕ
		double distance_center(double ang) const { return n*sin(ang)*cos(ang)/(pow(sin(ang),3)+pow(cos(ang),3)); }
		double curvature_vertices() const { return n/(8*sqrt(2)); } // đŕäčóń ęđčâčçíű â âĺđřčíĺ ëčńňŕ
		double curvature_node() const { return n/2; } // đŕäčóń ęđčâčçíű â óçëîâîé ňî÷ęĺ
		double square() const { return n*n/6; } // ďëîůŕäü ďĺňëč ëčńňŕ
		double max_diameter() const { return sqrt(4*sqrt(3)-6)/3*n; } // äëčíŕ íŕčáîëüřĺăî ďîďĺđĺ÷íčęŕ ďĺňëč
		double distance_diameter() const { return n/sqrt(6); } // đŕńńňî˙íč˙ îň óçëŕ äî íŕčáîëüřĺăî ďîďĺđĺ÷íčęŕ
		char* frm() const; // ôîđěóëŕ äĺęŕđňîâîăî ëčńňŕ
	};
}
#endif
