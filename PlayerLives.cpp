
#include "PlayerLives.h"

PlayerLives::PlayerLives()
{
	number_ = 0;

}
PlayerLives::~PlayerLives()
{

}

void PlayerLives::AddPos(const int& xp)
{
	pos_list_.push_back(xp);

}

void PlayerLives::Init(SDL_Renderer* screen)
{
	LoadImg("img//player_lives.png", screen);
	number_ = 3;
	if (pos_list_.size() > 0)
	{
		pos_list_.clear();
	}
	AddPos(20);
	AddPos(60);
	AddPos(100);
}

void PlayerLives::Show(SDL_Renderer* screen)
{
	for (int i = 0; i < pos_list_.size(); i++)
	{
		rect_.x = pos_list_.at(i);
		rect_.y = 0;
		Render(screen);
	}
}

void PlayerLives::Decrease()
{
	number_--;
	pos_list_.pop_back();

}

void PlayerLives::InitCrease()
{
	number_++;
	int last_pos = pos_list_.back();
	last_pos += 40;
	pos_list_.push_back(last_pos);
}


PlayerEnergy::PlayerEnergy()
{
	x_pos_ = 0;
	y_pos_ = 0;
}

PlayerEnergy::~PlayerEnergy()
{

}

void PlayerEnergy::Init(SDL_Renderer* screen)
{
	bool ret = LoadImg("img/energy.png", screen);

}

void PlayerEnergy::Show(SDL_Renderer* screen)
{
	rect_.x = x_pos_;
	rect_.y = y_pos_;
	Render(screen);
}
