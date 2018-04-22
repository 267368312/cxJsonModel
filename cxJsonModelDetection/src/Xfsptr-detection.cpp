#include <XFSPTR.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfsptr310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfsptr320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfsptr330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfsptr;


#define TESTING_TYPES		Xfsptr

#include "detection.hpp"