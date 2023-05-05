
#ifndef MAIN_CHARACTER_H_
#define MAIN_CHARECTER_H_

#include <vector>
#include "BaseFunction.h"
#include "BaseObject.h"
#include "BulletObject.h"


#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 8
#define PLAYER_JUMP_VAL 18
#define PLAYER_NUM_FRAME 12


class MainCharacter : public BaseObject
{
public:
	MainCharacter();
	~MainCharacter();

	enum WalkType
	{
		WALK_NONE = 0,
		WALK_RIGHT = 1,
		WALK_LEFT = 2,
	};
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void HandleInputAction(SDL_Event events, SDL_Renderer* screen, Mix_Chunk* bullet_sound[2]); //Ham xu li xu kien
	void set_clips();
	void CharacterAction(Map& map_data, Mix_Chunk* sound_player[2]);
	void CheckCrashingEvents(Map& map_data);
	void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x; map_y_ = map_y; }
	void CenterEntityOnMap(Map& map_data);
	void UpdateImagePlayer(SDL_Renderer* des);
	SDL_Rect GetRectFrame();

	void set_bullet_list(std::vector<BulletObject*> bullet_list)
	{
		p_bullet_list_ = bullet_list;

	}
	std::vector<BulletObject*> get_bullet_list() const
	{
		return p_bullet_list_;
	}
	void HandleBullet(SDL_Renderer* des);
	void RemoveBullet(const int& idx);
	void IncreaseEnergy();
	int get_frame_width() const
	{
		return width_frame_;
	}
	int get_frame_height() const
	{
		return height_frame_;
	}
	void set_comeback_time(const int& cb_time)
	{
		come_back_time_ = cb_time;
	}
	int GetEnergyAmount() const
	{
		return energy_amount;
	}

private:

	int energy_amount;
	std::vector<BulletObject*> p_bullet_list_;
	float x_val_, y_val_; // gia tri khi bam phim sang trai phai
	float x_pos_, y_pos_; // vi tri hien tai
	int width_frame_; // chieu dai cua 1 frame
	int height_frame_; // chieu cao cua 1 frame
	SDL_Rect frame_clip_[PLAYER_NUM_FRAME];
	Input input_type_;
	int frame_;
	int status_;
	bool on_ground_;

	int map_x_;
	int map_y_;

	int come_back_time_;
};

#endif