#include <XFSDEP.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfsdep310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfsdep320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfsdep330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfsdep;


#define TESTING_TYPES		Xfsdep

#include "detection.hpp"