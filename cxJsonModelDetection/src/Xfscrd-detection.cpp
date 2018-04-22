#include <XFSCRD.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfscrd310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfscrd320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfscrd330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfscrd;


#define TESTING_TYPES		Xfscrd

#include "detection.hpp"