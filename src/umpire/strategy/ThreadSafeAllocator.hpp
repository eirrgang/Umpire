//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-19, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
//////////////////////////////////////////////////////////////////////////////
#ifndef UMPIRE_ThreadSafeAllocator_HPP
#define UMPIRE_ThreadSafeAllocator_HPP

#include <mutex>

#include "umpire/Allocator.hpp"
#include "umpire/strategy/AllocationStrategy.hpp"

namespace umpire {
namespace strategy {

class ThreadSafeAllocator :
  public AllocationStrategy
{
  public:
    ThreadSafeAllocator(
        const std::string& name,
        int id,
        Allocator allocator);

    void* allocate(std::size_t bytes);
    void deallocate(void* ptr);

    std::size_t getCurrentSize() const noexcept;
    std::size_t getHighWatermark() const noexcept;

    Platform getPlatform() noexcept;

  protected:
    strategy::AllocationStrategy* m_allocator;

    std::mutex m_mutex;
};

} // end of namespace strategy
} // end of namespace umpire

#endif // UMPIRE_ThreadSafeAllocator_HPP
