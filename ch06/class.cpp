#include	<iostream>
#include	<stdlib.h>
#include	<unistd.h>
#include	<cstdlib>

using namespace std;

class 		accelerator;
const int	dummy = 0;

class engine
{
private:
	// 가상함수 -> 구현 x -> 추상 클래스
	virtual void	acceleration_output() = 0;
	virtual void	reduce_output() = 0;
	friend class	accelerator;	// accelerator 클래스가 engine의 private 멤버에 접근 가능
};

class ic_engine : public engine
{
private:
	// 가상함수 -> 구현 x -> 추상 클래스
	virtual void	acceleration_output() = 0;
	virtual void	reduce_output() = 0;
};

class gs_engine : public ic_engine
{
private:
	void	acceleration_output() override { increasing_fuel();	};	// 추상 클래스의 함수 구현
	void	reduce_output() override { decreasing_fuel(); };			// 추상 클래스의 함수 구현
	void	increasing_fuel() { increasing_piston_speed(); };
	void	decreasing_fuel() { decreasing_piston_speed(); };
	void	increasing_piston_speed() { cout << "increasing_piston_speed\n"; };
	void	decreasing_piston_speed() { cout << "decreasing_piston_speed\n"; };
};

class elec_engine : public engine
{
private:
	void	acceleration_output() override { increasing_motor_speed(); };
	void	reduce_output() override { decreasing_motor_speed(); };
	void	increasing_motor_speed() { cout << "increasing_motor_speed\n"; };
	void	decreasing_motor_speed() { cout << "decreasing_motor_speed\n"; };
};

class break_system
{
public:
	void	pushing_break(accelerator &accelerator_obj);
};

class accelerator
{
public:
	accelerator(engine &engine) : my_engine(engine) {};	// 생성자. engine을 받아와서 my_engine 멤버 변수에 저장
	void	acceleration_output() { my_engine.acceleration_output(); };
	void	set_engine(engine &engine) { my_engine = engine; };

private:
	engine	&my_engine;
	
	void		reduce_output();
	friend void	break_system::pushing_break(accelerator &accelerator_obj);	// pushing_break 함수가 accelerator 클래스의 Private 멤버에 접근 가능
};

// 각 class 별 멤버 함수 정의부
void	break_system::pushing_break(accelerator &accelerator_obj)
{
	accelerator_obj.reduce_output();
}

void	accelerator::reduce_output()
{
	my_engine.reduce_output();
}


class sensor
{
public:
	int	inquiring_range() { return dummy; };
	int	inquiring_current_speed() { return dummy; };
};

class cruise_controller
{
public:
	// 생성자
	cruise_controller(sensor &sensor, accelerator &accelerator, break_system &break_system)
		:my_sensor(sensor), 			// 멤버 변수 my_sensor에 sensor를 저장
		my_accelerator(accelerator), 	// 멤버 변수 my_accelerator에 accelerator를 저장
		my_break_system(break_system)	// 멤버 변수 my_break_system에 break_system을 저장
	{
		acceleration_adjusting_period = 1;
		user_target_speed = 0;
		keep_cruise = false;
	};

	void	do_cruise();
	void	stop_cruise() { keep_cruise = false; };
	void	set_target_speed(int speed) { user_target_speed = speed; };

private:
	int		calculating_fit_speed(int range, int orginal_target_speed) { return dummy; };
	void	acceleration_adjusting(int current_speed, int target_speed);

	sensor			&my_sensor;
	accelerator		&my_accelerator;
	break_system	&my_break_system;

	int				user_target_speed;
	int				acceleration_adjusting_period;
	bool			keep_cruise;
};

// class 별 멤버 함수 정의부
void	cruise_controller::do_cruise()
{
	int	range = dummy;
	int	current_speed = dummy;

	keep_cruise = true;
	while (keep_cruise)
	{
		range = my_sensor.inquiring_range();
		current_speed = my_sensor.inquiring_current_speed();
		acceleration_adjusting(calculating_fit_speed(range, current_speed), user_target_speed);
		sleep(acceleration_adjusting_period / 1000);
		keep_cruise = false;
	}
}

void	cruise_controller::acceleration_adjusting(int current_speed, int target_speed)
{
	if (target_speed == current_speed)
	{
		return ;
	}
	if (target_speed > current_speed)
	{
		my_accelerator.acceleration_output();
		return ;
	}
	else
	{
		my_break_system.pushing_break(my_accelerator);
		return ;
	}
}

class car
{
public:
	// 생성자
	car(engine &engine, sensor &sensor, break_system &break_system, accelerator &accelerator, cruise_controller &cruise_controller)
		:my_engine(engine),
		my_sensor(sensor),
		my_break_system(break_system),
		my_accelerator(accelerator),
		my_cruise_controller(cruise_controller) {};

	void	do_cruise();
	void	stop();

private:
	engine				&my_engine;
	sensor				&my_sensor;
	break_system		&my_break_system;
	accelerator			&my_accelerator;
	cruise_controller	&my_cruise_controller;
};

// 각 class 별 멤버 함수 정의부
void	car::stop()
{
	my_break_system.pushing_break(my_accelerator);
}

void	car::do_cruise()
{
	my_cruise_controller.set_target_speed(100);
	my_cruise_controller.do_cruise();
}

int	main(int argc, char **argv)
{
	gs_engine			my_engine;
	sensor				my_sensor;
	break_system		my_break_system;
	accelerator			my_accelerator(my_engine);
	cruise_controller	my_cruise_controller(my_sensor, my_accelerator, my_break_system);
	car					my_car(my_engine, my_sensor, my_break_system, my_accelerator, my_cruise_controller);

	my_car.do_cruise();
	return (0);
}
