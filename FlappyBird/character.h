#pragma once

#include "variables.h"

namespace FlappyBird
{
	class Character
	{
	private:
		Vector2 position;
		Color color;
		Move_Status moveStatus;
		Texture_Shown textureShown;
		Texture2D characterTextureDown;
		Texture2D characterTextureMid;
		Texture2D characterTextureUp;

		float radius;
		float velocity;
		float fallingSpeed;
		float jumpingTime;
		float currentTextureTime;
		float rotation;
	public:
		Character();
		~Character();

		Vector2 GetPosition();
		float GetRadius();

		void InputCharacter(char letter);
		void UpdateCharacter();
		void DrawCharacter();

		void Move();
		void MovementInputDetection(char letter);
		void ResetCharacter();
		void AnimationManager();
		void NextTexture();
		bool PlayerTouchesDownBorder();
	};
}