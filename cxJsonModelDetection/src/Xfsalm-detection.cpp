#include <XFSALM.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfsalm310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfsalm320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfsalm330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfsalm;


#define TESTING_TYPES		Xfsalm

#include "detection.hpp"