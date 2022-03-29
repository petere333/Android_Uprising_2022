#pragma once
#include "object.h"
#include "bounding.h"

void createObjects(vector<Object>& list, vector<BoundingBox>& blist);

void createPlayer(vector<Object>& list);
void createSpace(vector<Object>& list, vector<BoundingBox>& blist);
void createObstacles(vector<Object>& list, vector<BoundingBox>& blist);




