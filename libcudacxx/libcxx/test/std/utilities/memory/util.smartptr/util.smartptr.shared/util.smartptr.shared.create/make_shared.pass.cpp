//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// shared_ptr

// template<class T, class... Args> shared_ptr<T> make_shared(Args&&... args);

#include <memory>
#include <cassert>

#include "test_macros.h"
#include "count_new.h"

struct A
{
    static int count;

    A(int i, char c) : int_(i), char_(c) {++count;}
    A(const A& a)
        : int_(a.int_), char_(a.char_)
        {++count;}
    ~A() {--count;}

    int get_int() const {return int_;}
    char get_char() const {return char_;}

    A* operator& () = delete;

private:
    int int_;
    char char_;
};

int A::count = 0;


struct Foo
{
    Foo() = default;
    virtual ~Foo() = default;
};

#ifdef _LIBCUDACXX_VERSION
struct Result {};
static Result theFunction() { return Result(); }
static int resultDeletorCount;
static void resultDeletor(Result (*pf)()) {
  assert(pf == theFunction);
  ++resultDeletorCount;
}

void test_pointer_to_function() {
    { // https://bugs.llvm.org/show_bug.cgi?id=27566
      std::shared_ptr<Result()> x(&theFunction, &resultDeletor);
      std::shared_ptr<Result()> y(theFunction, resultDeletor);
    }
    assert(resultDeletorCount == 2);
}
#else // _LIBCUDACXX_VERSION
void test_pointer_to_function() {}
#endif // _LIBCUDACXX_VERSION

int main(int, char**)
{
    int nc = globalMemCounter.outstanding_new;
    {
    int i = 67;
    char c = 'e';
    std::shared_ptr<A> p = std::make_shared<A>(i, c);
    assert(globalMemCounter.checkOutstandingNewEq(nc+1));
    assert(A::count == 1);
    assert(p->get_int() == 67);
    assert(p->get_char() == 'e');
    }

    { // https://bugs.llvm.org/show_bug.cgi?id=24137
    std::shared_ptr<Foo> p1       = std::make_shared<Foo>();
    assert(p1.get());
    std::shared_ptr<const Foo> p2 = std::make_shared<const Foo>();
    assert(p2.get());
    }

    test_pointer_to_function();

    nc = globalMemCounter.outstanding_new;
    {
    char c = 'e';
    std::shared_ptr<A> p = std::make_shared<A>(67, c);
    assert(globalMemCounter.checkOutstandingNewEq(nc+1));
    assert(A::count == 1);
    assert(p->get_int() == 67);
    assert(p->get_char() == 'e');
    }
    assert(A::count == 0);

  return 0;
}
