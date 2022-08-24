#pragma once
#include "stdafx.h"

namespace ARRAY
{
	class Matrix
	{
	public:
		Matrix();
		~Matrix();
		void hackerRank2DSearch();
		void spiralDisplay();

	private:
		int **init(int, int);
		void del(int row, int **);
		void search();
		void searchGlassHour();

	private:
		int **mMat, **mSubMat;
		int mMatRow, mMatCol, mSubMatRow, mSubMatcol;
	};
}
