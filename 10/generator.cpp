#include <coroutine>
#include <iostream>
#include <optional>
#include <thread>
#include <chrono>

template<typename T>
struct Generator {
    struct promise_type {
        std::optional<T> current_value;
        std::suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        Generator get_return_object() { return Generator{this}; }
        void unhandled_exception() { std::terminate(); }
        void return_void() {}
    };

    struct iterator {
        std::coroutine_handle<promise_type> coro;
        iterator(std::coroutine_handle<promise_type> coro): coro(coro) {}
        iterator& operator++() {
            coro.resume();
            if (coro.done()) coro = nullptr;
            return *this;
        }
        T operator*() const { return *coro.promise().current_value; }
        bool operator==(const iterator& other) const { return coro == other.coro; }
    };

    iterator begin() {
        if (coro) coro.resume();
        return iterator{coro};
    }

    iterator end() {
        return iterator{nullptr};
    }

    Generator(promise_type* p)
        : coro(std::coroutine_handle<promise_type>::from_promise(*p)) {}
    ~Generator() { if (coro) coro.destroy(); }

private:
    std::coroutine_handle<promise_type> coro;
};

Generator<int> generateNumbers(int start, int end, int delayMilliseconds) {
    for (int i = start; i <= end; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
        co_yield i;
    }
}

int main() {
    for (auto n : generateNumbers(1, 5, 1000)) { // 1000 milliseconds delay
        std::cout << "Generated number: " << n << std::endl;
    }
    return 0;
}