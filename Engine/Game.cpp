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
	brick(RectF(271.0f, 300.0f, 240.0f, 270.0f), Colors::Cyan),
	ball(Vec2(70, 70), Vec2(500, 500)),
	walls(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)),
	pad(Vec2(400.0f,500.0f)),
	Sbrick(L"Sounds//arkbrick.wav"),
	paddle(L"Sounds//arkpad.wav")
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	ball.Update(dt);
	if (ball.doWallCollision(walls)) {
		paddle.Play();
	};

	if (brick.doBallCollsion(ball)) {
		Sbrick.Play();
	};

	pad.Update(wnd.kbd,dt);
	pad.doWallCollision(walls);
	if (pad.doBallCollision(ball))
	{
		paddle.Play();
	}; 
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	brick.Draw(gfx);
	pad.Draw(gfx);

}
