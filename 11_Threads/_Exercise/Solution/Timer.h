#pragma once

#include <atomic>
#include <chrono>

namespace cpptiming
{

using Clock = std::chrono::steady_clock;
using nanosecs = std::chrono::nanoseconds;
using microsecs = std::chrono::microseconds;
using millisecs = std::chrono::milliseconds;
using secs = std::chrono::seconds;

class Timer
{
public:
    Timer() : m_start_point(Clock::now())
    {
    }

    template <typename Units = nanosecs, typename Rep = double>
    Rep elapsed_time() const
    {
        std::atomic_thread_fence(std::memory_order_relaxed);
        const auto counted_time =
            std::chrono::duration_cast<Units>(Clock::now() - m_start_point)
                .count();
        std::atomic_thread_fence(std::memory_order_relaxed);
        return static_cast<Rep>(counted_time);
    }

    void reset()
    {
        m_start_point = Clock::now();
    }

private:
    std::chrono::time_point<Clock> m_start_point;
};

} // namespace cpptiming
