#include <XFSIDC.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfsidc310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfsidc320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfsidc330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfsidc;


#define TESTING_TYPES		Xfsidc

#include "detection.hpp"