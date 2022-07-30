#pragma once
#include "func.h"


Vec2::Vec2(float f1, float f2)
{
	x = f1;
	y = f2;
}

Vec2::~Vec2(){}

Vec3::Vec3(float f1, float f2, float f3)
{
	x = f1;
	y = f2;
	z = f3;
}

Vec3::~Vec3(){}



vector<Vec2*> LoadData(const char* file)
{
	FILE* f = fopen(file, "r");
	float f1, f2, f3, f4, f5;
	
	vector<Vec2*> result;

	while (!feof(f))
	{
		fscanf(f, "(%f,  %f,  %f), (%f,  %f)\n", &f1, &f2, &f3, &f4, &f5);
		Vec2* v2 = new Vec2(f3, f2); //측면 그림자
		//Vec2* v2 = new Vec2(f1, f3); //위에서 본 그림자
		//Vec2* v2 = new Vec2(f1, f2); //앞에서 본 그림자
		result.push_back(v2);
	}
	fclose(f);
	return result;
}



float getStartX(vector<Vec2*> data)
{
	float sx = 10000.0f;

	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i]->x < sx)
		{
			sx = data[i]->x;
		}
	}
	return sx;
}

float getStartY(vector<Vec2*> data)
{
	float sy = 10000.0f;

	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i]->y < sy)
		{
			sy = data[i]->y;
		}
	}
	return sy;
}

float getEndX(vector<Vec2*> data)
{
	float ex = -10000.0f;

	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i]->x > ex)
		{
			ex = data[i]->x;
		}
	}
	return ex;
}

float getEndY(vector<Vec2*> data)
{
	float ex = -10000.0f;

	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i]->y > ex)
		{
			ex = data[i]->y;
		}
	}
	return ex;
}

vector<iVec2*> rescale(vector<Vec2*> data)
{
	float sx, sy, ex, ey;
	sx = getStartX(data);
	sy = getStartY(data);
	ex = getEndX(data);
	ey = getEndY(data);

	float width = ex - sx;
	float height = ey - sy;

	vector<iVec2*> result;
	

	for (int i = 0; i < data.size(); ++i)
	{
		// 1. 원점을 0,0으로 이동.
		data[i]->x -= sx;
		data[i]->y -= sy;
		// 2. 1024 크기로 배율조정.
		data[i]->x *= 1023.0f / width;
		data[i]->y *= 1023.0f / height;

		int i1 = static_cast<int>(data[i]->x);
		int i2 = static_cast<int>(data[i]->y);

		iVec2* v = new iVec2(i1, i2);
		result.push_back(v);
	}
	for (int i = 0; i < result.size(); ++i)
	{
		result[i]->y = 1023 - result[i]->y;
	}

	return result;
}



void writeImage(vector<iVec2*> data, const char* name)
{
	Mat image = Mat(1024, 1024, CV_8UC3, Scalar(255, 255, 255));
	//vector<Point> pt;
	//vector<Point> pt2;
	for (int i = 0; i < data.size(); ++i)
	{
		image.at<Vec3b>(data[i]->x, data[i]->y)[0] = 0;
		image.at<Vec3b>(data[i]->x, data[i]->y)[1] = 0;
		image.at<Vec3b>(data[i]->x, data[i]->y)[2] = 0;
		//pt.push_back(Point(data[i]->x, data[i]->y));
		//pt2.push_back(Point(data[data.size()-1 - i]->x, data[data.size()-1 - i]->y));
	}
	//fillPoly(image, pt, Scalar(0, 0, 0), LINE_AA);
	//fillPoly(image, pt2, Scalar(0, 0, 0), LINE_AA);
	for (int i = 0; i < data.size(); i+=3)
	{
		vector<Point> pts;
		pts.push_back(Point(data[i]->x, data[i]->y));
		pts.push_back(Point(data[i+1]->x, data[i+1]->y));
		pts.push_back(Point(data[i+2]->x, data[i+2]->y));
		/*
		pts.push_back(Point(data[i + 3]->x, data[i + 3]->y));
		pts.push_back(Point(data[i + 4]->x, data[i + 4]->y));
		pts.push_back(Point(data[i + 5]->x, data[i + 5]->y));
		pts.push_back(Point(data[i + 6]->x, data[i + 6]->y));
		pts.push_back(Point(data[i + 7]->x, data[i + 7]->y));
		pts.push_back(Point(data[i + 8]->x, data[i + 8]->y));
		pts.push_back(Point(data[i + 9]->x, data[i + 9]->y));
		*/
		/*
		pts.push_back(Point(data[i + 10]->x, data[i + 10]->y));
		pts.push_back(Point(data[i + 11]->x, data[i + 11]->y));
		pts.push_back(Point(data[i + 12]->x, data[i + 12]->y));
		pts.push_back(Point(data[i + 13]->x, data[i + 13]->y));
		pts.push_back(Point(data[i + 14]->x, data[i + 14]->y));
		pts.push_back(Point(data[i + 15]->x, data[i + 15]->y));
		pts.push_back(Point(data[i + 16]->x, data[i + 16]->y));
		pts.push_back(Point(data[i + 17]->x, data[i + 17]->y));
		pts.push_back(Point(data[i + 18]->x, data[i + 18]->y));
		pts.push_back(Point(data[i + 19]->x, data[i + 19]->y));
		*/
		//polylines(image, pts, true, Scalar(0, 0, 0), 1);
		fillPoly(image, pts, Scalar(0, 0, 0), LINE_AA);

		
		
		
	}
	/*
	for (int x = 0; x < 1024; ++x)
	{
		float sy = -1;
		float ey = 1025;
		for (int y = 0; y < 1024; ++y)
		{
			if (image.at<Vec4b>(x, y)[3] == 255)
			{
				if (sy == -1)
				{
					sy = y;
				}
				else
				{
					ey = y;
				}
			}
		}
		if (sy != -1 && ey != 1025)
		{
			for (int y = sy; y <= ey; ++y)
			{
				image.at<Vec4b>(x, y)[3] = 255;
			}
		}
	}
	
	for (int i = 0; i < 1024; ++i)
	{
		float sx = -1;
		float ex = 1025;
		for (int j = 0; j < 1024; ++j)
		{
			if (image.at<Vec4b>(j, i)[3] == 255)
			{
				if (sx == -1)
				{
					sx = j;
				}
				else
				{
					ex = j;
				}
			}
		}
		if (sx != -1 && ex != 1025)
		{
			for (int x = sx; x <= ex; ++x)
			{
				image.at<Vec4b>(x, i)[3] = 255;
			}
		}
	}
	*/
	vector<int> param;
	param.push_back(IMWRITE_PNG_COMPRESSION);
	param.push_back(9);

	
	imwrite(name, image, param);

	//Mat img = imread(name, IMREAD_UNCHANGED);
	//imshow(name, img);
}

