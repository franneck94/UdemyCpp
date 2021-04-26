#pragma once

#include <chrono>
#include <atomic>

namespace cpptiming
{

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::nanoseconds nanosecs;
typedef std::chrono::microseconds microsecs;
typedef std::chrono::milliseconds millisecs;
typedef std::chrono::seconds secs;

class Timer
{
public:
    Timer() : m_start_point(Clock::now()) { }

    template <typename Units = nanosecs, typename Rep = double>
    Rep elapsed_time() const
    {
        std::atomic_thread_fence(std::memory_order_relaxed);
        auto counted_time = std::chrono::duration_cast<Units>(Clock::now() - m_start_point).count();
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
