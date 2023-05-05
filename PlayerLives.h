#ifndef PLAYER_LIVES_H_
#define PLAYER_LIVES_H_

#include "BaseFunction.h"
#include "BaseObject.h"

class PlayerLives : public BaseObject
{
public:
	PlayerLives();
	~PlayerLives();

	void SetNum(const int& num)
	{
		number_ = num;
	}
	void AddPos(const int& xPos);
	void Show(SDL_Renderer* screen);
	void Init(SDL_Renderer* screen);

	void InitCrease();
	void Decrease();

private:
	int number_;
	std::vector<int> pos_list_;

};


class PlayerEnergy : public BaseObject
{
public:
	PlayerEnergy();
	~PlayerEnergy();

	void Init(SDL_Renderer* screen);
	void Show(SDL_Renderer* screen);
	void SetPos(const int& x, const int& y)
	{
		x_pos_ = x;
		y_pos_ = y;
	}
private:

	int x_pos_;
	int y_pos_;
};

#endif
