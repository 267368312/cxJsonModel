#include <XFSIPM.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfsipm310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfsipm320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfsipm330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfsipm;


#define TESTING_TYPES		Xfsipm

#include "detection.hpp"