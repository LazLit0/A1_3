#pragma once
#include <cassert>
#include <iostream>
#include <array>
#include <cmath>
namespace my
{
    template <typename T, size_t SIZE>
    class Vec
    {

    public:
        Vec();
        Vec(T v0);
        Vec(T v0, T v1);
        Vec(T v0, T v1, T v2);
        Vec(T v0, T v1, T v2, T v3);

        using value_type = T;
        constexpr static int dimension = SIZE;

        T &operator[](int i);
        T operator[](int i) const;
        bool operator==(const Vec &v2) const;
        bool operator!=(const Vec &v2) const;
        Vec &operator+=(const Vec &v2);
        Vec operator+(const Vec &v2) const;
        Vec operator-() const;
        double dot(const Vec &v1, const Vec &v2);
        auto length();
        void helperfunction(const std::vector<Vec<T, SIZE>> &a);

    private:
        std::array<T, SIZE> m_a = {};
    };
    // Alle auf T setzen
    template <typename T, size_t SIZE>
    Vec<T, SIZE>::Vec() : m_a({})
    {
        std::fill(m_a.begin(), m_a.end(), 0);
    }

    template <typename T, size_t SIZE>
    Vec<T, SIZE>::Vec(T v0) : m_a({v0})
    {
        static_assert(SIZE == 1, "wrong number of arguments");
    }

    template <typename T, size_t SIZE>
    Vec<T, SIZE>::Vec(T v0, T v1) : m_a({v0, v1})
    {
        static_assert(SIZE == 2, "wrong number of arguments");
    }

    template <typename T, size_t SIZE>
    Vec<T, SIZE>::Vec(T v0, T v1, T v2) : m_a({v0, v1, v2})
    {
        static_assert(SIZE == 3, "wrong number of arguments");
    }

    template <typename T, size_t SIZE>
    Vec<T, SIZE>::Vec(T v0, T v1, T v2, T v3) : m_a({v0, v1, v2, v3})
    {
        static_assert(SIZE == 4, "wrong number of arguments");
    }

    template <typename T, size_t SIZE>
    T dot(const Vec<T, SIZE> &v1, const Vec<T, SIZE> &v2);

    template <typename T, size_t SIZE>
    T &Vec<T, SIZE>::operator[](int i)
    {
        return m_a[i];
    };

    template <typename T, size_t SIZE>
    T Vec<T, SIZE>::operator[](int i) const
    {
        return m_a[i];
    };

    template <typename T, size_t SIZE>
    bool Vec<T, SIZE>::operator==(const Vec<T, SIZE> &rhs) const
    {
        if (rhs.m_a.size() != SIZE)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (rhs[i] != m_a[i])
                {
                    return false;
                }
            }
            return true;
        }
    };

    template <typename T, size_t SIZE>
    bool Vec<T, SIZE>::operator!=(const Vec<T, SIZE> &rhs) const
    {
        Vec<T, SIZE> temp(*this);
        return !(temp == rhs);
    };

    template <typename T, size_t SIZE>
    Vec<T, SIZE> &Vec<T, SIZE>::operator+=(const Vec<T, SIZE> &rhs)
    {
        for (size_t i = 0; i < m_a.size(); i++)
        {
            m_a[i] += rhs.m_a[i];
        };

        return *this;

        // m_a[0] += rhs.m_a[0];
        // m_a[1] += rhs.m_a[1];
        // m_a[2] += rhs.m_a[2];
        // return *this;
    };

    template <typename T, size_t SIZE>
    Vec<T, SIZE> Vec<T, SIZE>::operator+(const Vec<T, SIZE> &rhs) const
    {
        Vec<T, SIZE> temp(*this);
        temp += rhs;
        return temp;
    };

    template <typename T, size_t SIZE>
    Vec<T, SIZE> Vec<T, SIZE>::operator-() const
    {
        Vec<T, SIZE> temp(*this);
        for (size_t i = 0; i < SIZE; i++)
        {
            temp[i] *= -1;
        }
        return temp;
    }

    template <typename T, size_t SIZE>
    T dot(const Vec<T, SIZE> &v1, const Vec<T, SIZE> &v2)
    {
        auto product = 0.0;
        for (size_t i = 0; i < SIZE; i++)
        {
            product += v1[i] * v2[i];
        }

        return product;
    }

    template <typename T, size_t SIZE>
    auto Vec<T, SIZE>::length()
    {
        auto sum = 0.0;
        for (size_t i = 0; i < SIZE; i++)
        {
            sum += pow(m_a[i], 2);
        }
        auto sumsqrt = sqrt(sum);
        return sumsqrt;
    }

    template <typename T, size_t SIZE>
    void helperfunction(const std::vector<Vec<T, SIZE>> &a)
    {
        std::for_each(a.begin(), a.end(),
                      [](Vec<T, SIZE> v)
                      { std::cout << "{" << v[0] << "," << v[1] << "," << v[2] << "}\tLength: " << v.length() << std::endl; });
    }
}