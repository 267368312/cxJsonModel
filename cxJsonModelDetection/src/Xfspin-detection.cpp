#include <XFSPIN.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfspin310-1.h"
#elif defined(XFS_VERSION_320)
	#include "Xfspin320-1.h"
#elif defined(XFS_VERSION_330)
	#include "Xfspin330-1.h"
#else
	#error please define CEN/XFS version
#endif
> Xfspin1;
#define TESTING_TYPES		Xfspin1
#include "detection.hpp"


typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfspin310-2.h"
#elif defined(XFS_VERSION_320)
	#include "Xfspin320-2.h"
#elif defined(XFS_VERSION_330)
	#include "Xfspin330-2.h"
#else
	#error please define CEN/XFS version
#endif
> Xfspin2;
#undef TESTING_TYPES
#define TESTING_TYPES		Xfspin2
#include "detection.hpp"