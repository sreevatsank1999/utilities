#ifndef UTILITIES_RANGE_H
#define UTILITIES_RANGE_H

#include <type_traits>
#include <cmath>

namespace utl {

    template <class T>
    class range {
    public:

        T min, max;

        range() = default;
        range(const T& _min, const T& _max)
            : min(_min), max(_max)
        {}
        range(const range&) = default;
        range(range&&) = default;

        range& operator= (const range&) = default;
        range& operator= (range&&) = default;

        friend bool operator== (const range&, const range&) = default;

        template <typename T1, typename T2, typename std::enable_if_t<std::is_convertible_v<T1,T2>,bool> = true >
        static range<T1> clip(const range<T1>& r, const range<T2>& B)
        {   
            range<T1> result(clip(r.min,B),clip(r.max,B));
            return result;
        }
        template <typename T1, typename T2, typename std::enable_if_t<std::is_convertible_v<T1,T2>,bool> = true >
        static T1 clip(const T1& r, const range<T2>& B)
        {
            return std::min(B.max, std::max(r,B.min));
        }

        template <typename T1, typename T2, typename std::enable_if_t<std::is_convertible_v<T1,T2>,bool> = true >
        static bool is_bounded(const range<T1>& r, const range<T2>& B)
        {
            return ( B.min <= static_cast<T2>(r.min) && static_cast<T2>(r.max) <= B.max );
        }
        template <typename T1, typename T2, typename std::enable_if_t<std::is_convertible_v<T1,T2>,bool> = true >
        static bool is_bounded(const T1& r, const range<T2>& B)
        {
            return ( B.min <= static_cast<T2>(r) && static_cast<T2>(r) <= B.max );
        }
    };

}

#endif