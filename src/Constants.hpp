#pragma once

#define GHOST_ACCEL 6000
#define GHOST_DASH_ACCEL (GHOST_ACCEL * 7)
#define GHOST_FRICTION 0.7
#define GHOST_MAX_SPEED 15000
#define GHOST_DASH_COOLDOWN 1.0

#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
    #define XBOX360_NAME_ID     "Xbox 360 Controller"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif
