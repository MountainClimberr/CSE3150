#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "timedSharedPtr.h"
#include "doctest.h"
#include <iostream>


TEST_CASE("TimedSharedPtr Tests"){
  SUBCASE("construction and destruction"){
    TimedSharedPtr<int> p(new int(42));
    CHECK(p.use_count() == 1);
    CHECK(*p.get() == 42);

    TimedSharedPtr<int> nullPtr;
    CHECK(nullPtr.use_count() == 0);
    CHECK(nullPtr.get() == nullptr);
  }

  SUBCASE("copy constructor"){
    TimedSharedPtr<int> p(new int(42));
    TimedSharedPtr<int> q = p;

    CHECK(p.use_count() == 2);
    CHECK(q.use_count() == 2);
    CHECK(p.get() == q.get());
    CHECK(*p.get() == 42);
  }

  SUBCASE("copy assignment operator"){
    TimedSharedPtr<int> p(new int(42));
    TimedSharedPtr<int> q(new int(10));

    q = p;
    CHECK(p.use_count() == 2);
    CHECK(q.use_count() == 2);
    CHECK(p.get() == q.get());
    CHECK(*q.get() == 42);
  }

  SUBCASE("expiration test"){
    TimedSharedPtr<int> p(new int(42), 50);

    CHECK(p.get() != nullptr);

    std::this_thread::sleep_for(std::chrono::milliseconds(60));

    CHECK(p.get() == nullptr);
  }

  SUBCASE("multiple pointers test"){
    TimedSharedPtr<int> p1(new int(10), 50);
    TimedSharedPtr<int> p2(new int(20), 100);


    std::this_thread::sleep_for(std::chrono::milliseconds(75));

    CHECK(p1.get() == nullptr);
    CHECK(p2.get() != nullptr);
    CHECK(*p2.get() == 20);
  }
}