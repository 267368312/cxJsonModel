#include <XFSSIU.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfssiu310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfssiu320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfssiu330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfssiu;


#define TESTING_TYPES		Xfssiu

#include "detection.hpp"