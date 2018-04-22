#include <XFSTTU.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfsttu310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfsttu320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfsttu330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfsttu;


#define TESTING_TYPES		Xfsttu

#include "detection.hpp"