#pragma once

#include "variables.h"

namespace FlappyBird
{
	class Obstacle
	{
	private:
		Rectangle topRec;
		Rectangle downRec;
		Color color;
	public:
		Obstacle();

		Rectangle GetTopRec();
		Rectangle GetDownRec();

		void UpdateObstacle(float velocity);
		void DrawObstacle();

		void ResetObstaclePosition();
		bool IsObstacleOnTheLeft();
		void MoveObstacles(float velocity);
	};
}