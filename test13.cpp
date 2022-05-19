 #include <iostream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include "vec.h"

using namespace std;
using namespace my;
using Vec3f = my::Vec<float, 3>;

    bool isThe(Vec3f f)
    {
        return f.length() < 90 || f.length() > 120;
    }
void test_Vec3f(){

#ifndef NDEBUG
    
    cout << "======================" << endl;
    cout << "     Testing Vec      " << endl;
    cout << "======================" << endl;
 
 {
        cout << "Generating 10 Vec3fs Vector" << endl;
        std::vector<Vec3f> v;
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_real_distribution<> dist(0, 100);

        for (int i = 0; i < 10; i++)
        {
            std::vector<float> floats;
            floats.push_back(dist(e2));
            floats.push_back(dist(e2));
            floats.push_back(dist(e2));

            Vec3f vec = Vec3f(floats[0], floats[1], floats[2]);

            v.push_back(vec);
        };
        my::helperfunction<float, 3>(v);
        std::transform(begin(v), end(v), begin(v), [](const Vec3f value)
                       { return value + Vec3f(1, 1, 1); });
        cout << " " << endl;
        cout << " DAS IST NACH TRANSFORM" << endl;
        my::helperfunction<float, 3>(v);
        cout << " " << endl;
        std::stable_partition(v.begin(), v.end(), [](Vec3f n)
                              { return n.length() < 90; });
        cout << "NACH PARTITON" << endl;
        my::helperfunction<float, 3>(v);
        cout << " " << endl;
        cout << "NACH SORT" << endl;
        std::sort(v.begin(), v.end(), [](Vec3f a, Vec3f b)
                  { return a.length() > b.length(); });
        my::helperfunction<float, 3>(v);
        cout << " " << endl;
        cout << " MEDIAN " << endl;
        std::vector<Vec3f> v2;
        v2.push_back(v[v.size() / 2]);
        my::helperfunction<float, 3>(v2);

        cout << " " << endl;
        cout << "COPY IF" << endl;
        std::vector<Vec3f> v3;
        std::copy_if(v.begin(), v.end(),
                     back_inserter(v3),
                     [](Vec3f vic)
                     { return vic.length() < 80; });
        my::helperfunction<float, 3>(v3);

        cout << " " << endl;
        cout << "Löschen aller Elemente zwischen 90 und 120 " << endl;
        auto to_be_erased = remove_if(v.begin(), v.end(), isThe);
        v.erase(to_be_erased, v.end());
        my::helperfunction<float, 3>(v);
    }

    cout << "all Vec tests passed." << endl
         << endl;
#if 0
#endif // not 0
#endif // not NDEBUG
}