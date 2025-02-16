//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//

// <list>

// list(list&& c);

// REQUIRES: has-unix-headers
// UNSUPPORTED: !libcpp-has-debug-mode, c++03

#include <list>

#include "check_assertion.h"

int main(int, char**) {
    std::list<int> l1;
    l1.push_back(1); l1.push_back(2); l1.push_back(3);
    std::list<int>::iterator i = l1.begin();
    std::list<int> l2 = l1;
    TEST_LIBCUDACXX_ASSERT_FAILURE(l2.erase(i), "list::erase(iterator) called with an iterator not referring to this list");

    return 0;
}
