////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-20, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
////////////////////////////////////////////////////////////////////////////
#include "umpire/DeviceAllocator.hpp"
#include "umpire/util/device_allocator_helper.hpp"

namespace umpire {

namespace util {

__device__ int getDeviceAllocator(int id)
{
  return umpire::util::UMPIRE_DEV_ALLOCS[id];
}

} // end namespace util

} // end namespace umpire
