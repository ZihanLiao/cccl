//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// test forward

#include <utility>

#include "test_macros.h"

struct A
{
};

A source() {return A();}
const A csource() {return A();}

int main(int, char**)
{
    {
        std::forward<A&>(source()); // expected-error 0-1 {{ignoring return value of function declared with const attribute}}
        // expected-error-re@__utility/forward.h:* {{{{(static_assert|static assertion)}} failed{{.*}} {{"?}}cannot forward an rvalue as an lvalue{{"?}}}}
    }
    {
        const A ca = A();
        std::forward<A&>(ca); // expected-error {{no matching function for call to 'forward'}}
    }
    {
        std::forward<A&>(csource());  // expected-error {{no matching function for call to 'forward'}}
    }
    {
        const A ca = A();
        std::forward<A>(ca); // expected-error {{no matching function for call to 'forward'}}
    }
    {
        std::forward<A>(csource()); // expected-error {{no matching function for call to 'forward'}}
    }
    {
        A a;
        std::forward(a); // expected-error {{no matching function for call to 'forward'}}
    }

  return 0;
}
