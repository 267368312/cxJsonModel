#include <XFSCIM.h>

#include <gtest/gtest.h>

typedef testing::Types<
#if defined(XFS_VERSION_310)
	#include "Xfscim310-1.h"
#elif defined(XFS_VERSION_320)
	#include "Xfscim320-1.h"
#elif defined(XFS_VERSION_330)
	#include "Xfscim330-1.h"
#else
	#error please define CEN/XFS version
#endif
> Xfscim1;

#define TESTING_TYPES		Xfscim1
#include "detection.hpp"



typedef testing::Types<
#if defined(XFS_VERSION_310)
#include "Xfscim310-2.h"
#elif defined(XFS_VERSION_320)
#include "Xfscim320-2.h"
#elif defined(XFS_VERSION_330)
#include "Xfscim330-2.h"
#else
#error please define CEN/XFS version
#endif
> Xfscim2;

#undef TESTING_TYPES
#define TESTING_TYPES		Xfscim2
#include "detection.hpp"