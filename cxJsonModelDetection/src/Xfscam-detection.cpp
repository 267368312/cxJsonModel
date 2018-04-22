#include <XFSCAM.H>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfscam310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfscam320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfscam330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfscam;


#define TESTING_TYPES		Xfscam

#include "detection.hpp"