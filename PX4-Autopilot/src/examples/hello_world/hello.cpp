#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/log.h>
#include <uORB/topics/input_rc.h>
extern "C" __EXPORT int hello_world_main(int argc, char *argv[]);
int hello_world_main(int argc, char *argv[])
{
	int input_rc_handle;
	input_rc_s input_rc_data;
	input_rc_handle = orb_subscribe(ORB_ID(input_rc));
	orb_set_interval(input_rc_handle, 200);
	while(1)
	{
		orb_copy(ORB_ID(input_rc), input_rc_handle, &input_rc_data);
		PX4_INFO("RJ(LR) = %f, RJ(UD) = %f, LJ(UD) = %f, LJ(LR) = %f, SWC = %f", (double)input_rc_data.values[0],
		(double)input_rc_data.values[1],
		(double)input_rc_data.values[2],
		(double)input_rc_data.values[3],
		(double)input_rc_data.values[4]);
		px4_usleep(200000);
	}
	return 0;
}
