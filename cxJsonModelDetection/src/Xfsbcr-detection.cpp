#include <gtest/gtest.h>
#include <XFSBCR.H>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfsbcr310.h"
#elif defined(XFS_VERSION_320)
	#include "Xfsbcr320.h"
#elif defined(XFS_VERSION_330)
	#include "Xfsbcr330.h"
#else
	#error please define CEN/XFS version
#endif
> Xfsbcr;

#define TESTING_TYPES		Xfsbcr

//#include "detection.h"
#include "detection.hpp"