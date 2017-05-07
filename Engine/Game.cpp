/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.0f + 24.0f, 300.0f), Vec2(-300, -300)),
	walls(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)),
	pad(Vec2(400.0f, 500.0f)),
	Sbrick(L"Sounds//arkbrick.wav"),
	paddle(L"Sounds//arkpad.wav")
{
	int i = 0; //brick number counter;
	Color colors[4] = { Colors::Red,Colors::Green,Colors::Blue,Colors::Cyan };

	Vec2 topLeft(40.0f, 40.0f);
	 
		for (int y = 0; y < nBricksDown; y++)
		{
			Color c = colors[y];
			for (int x = 0; x < nBricksAcross; x++)
			{
				bricks[i] = Bricks(RectF(
					topLeft.x + (x*bWidth), topLeft.x + bWidth + (x*bWidth), topLeft.y + (y*bHeight), topLeft.y + bHeight + (y*bHeight)), c);
				i++;
			}
		}
}

void Game::Go()
{
	gfx.BeginFrame();	
	float ElapsedTime = ft.Mark();
	while (ElapsedTime>0.0f)
	{
		const float dt = std::min(0.0025f, ElapsedTime);
		UpdateModel(dt);
		ElapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	
	ball.Update(dt);

	if (ball.doWallCollision(walls)) {
		pad.ResetCoolDown();
		paddle.Play();
	}

	bool CollisionHappened = false;
	float CurColDisSq;
	int curColIndex;

	for (int i = 0; i < nBricks; i++)
	{
		if (bricks[i].isBallCollsion(ball))
		{
			float NewColDisSq = (ball.GetCenter() - bricks[i].GetCenter()).GetLengthSq();
			if (CollisionHappened)
			{
				if (CurColDisSq > NewColDisSq)
				{
					CurColDisSq = NewColDisSq;
					curColIndex = i;
				}
			}
			else
			{
				CurColDisSq = NewColDisSq;
				curColIndex = i;
				CollisionHappened = true;
			}
		}
	}
	
	if (CollisionHappened)
	{
		pad.ResetCoolDown();
		bricks[curColIndex].ExecuteBallCollision(ball);
		Sbrick.Play();
	}
	
	pad.Update(wnd.kbd,dt);
	pad.doWallCollision(walls);
	if (pad.doBallCollision(ball))
	{
		paddle.Play();
	}
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	for (const Bricks& b : bricks)
	{
		b.Draw(gfx);
	}
	pad.Draw(gfx);
}
