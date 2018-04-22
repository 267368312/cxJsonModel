#include <XFSCHK.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfschk310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfschk320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfschk330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfschk;


#define TESTING_TYPES		Xfschk

#include "detection.hpp"