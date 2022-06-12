#pragma once
#include "object.h"
#include "bounding.h"

void createObjects(vector<Object>& list, vector<BoundingBox>& blist);

void createPlayer(vector<Object>& list);
void createSpace(vector<Object>& list, vector<BoundingBox>& blist);
void createObstacles1_1(vector<Object>& list, vector<BoundingBox>& blist);
void createObstacles1_2(vector<Object>& list, vector<BoundingBox>& blist);
void createObstacles1_3(vector<Object>& list, vector<BoundingBox>& blist);
void createObstacles2_1(vector<Object>& list, vector<BoundingBox>& blist);
void createObstacles2_2(vector<Object>& list, vector<BoundingBox>& blist);
void createObstacles2_3(vector<Object>& list, vector<BoundingBox>& blist);




