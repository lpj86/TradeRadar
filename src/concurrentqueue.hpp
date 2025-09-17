#include <mutex>
#include <queue>
#include <condition_variable>
#include <optional>

template <typename T>

class ConcurrentQueue {
    public:
        ConcurrentQueue();
        bool try_pop();
        bool push();
    private:
        mutable std::mutex mutex_;
        std::queue<T> queue_;
};