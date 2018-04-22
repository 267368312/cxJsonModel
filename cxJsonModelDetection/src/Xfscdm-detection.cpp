#include <XFSCDM.H>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfscdm310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfscdm320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfscdm330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfscdm;


#define TESTING_TYPES		Xfscdm

#include "detection.hpp"