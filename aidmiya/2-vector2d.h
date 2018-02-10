#pragma once

class Cvector2d {
	public:

		double x;
		double y;
		lengthSquare();
		double dot(const Cvector2d&);
		double cross(const Cvector2d&)
		bool isZero();
		// 二項+演算子(A+B)の適切なオーバーロード	
};

