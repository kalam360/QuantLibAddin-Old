/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2004 Ferdinando Ametrano

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#ifndef qla_autolink_hpp
#define qla_autolink_hpp

#include <qlo/qladdindefines.hpp>

// select toolset:
#if (_MSC_VER >= 1930)
#  define OBJHANDLER_LIB_TOOLSET "v143"
#elif (_MSC_VER >= 1924)
#  define OBJHANDLER_LIB_TOOLSET "v142"
#elif (_MSC_VER >= 1910)
#  define QLADDIN_LIB_TOOLSET "v141"
#elif (_MSC_VER >= 1900)
#  define QLADDIN_LIB_TOOLSET "v140"
#elif (_MSC_VER >= 1800)
#  define QLADDIN_LIB_TOOLSET "v120"
#elif (_MSC_VER >= 1700)
#  define QLADDIN_LIB_TOOLSET "v110"
#elif (_MSC_VER >= 1600)
#  define QLADDIN_LIB_TOOLSET "v100"
#elif (_MSC_VER >= 1500)
#  define QLADDIN_LIB_TOOLSET "v90"
#else
#  error "unsupported Microsoft compiler"
#endif

/*** libraries to be linked ***/

// select architecture:
#ifdef _M_X64
#  define QLADDIN_LIB_PLATFORM "-x64"
#else
#  define QLADDIN_LIB_PLATFORM 
#endif

// select thread opt:
#ifdef _MT
#  define QLADDIN_LIB_THREAD_OPT "-mt"
#else
#  define QLADDIN_LIB_THREAD_OPT
#endif

// select linkage opt:
#ifdef _DLL
#  if defined(_DEBUG)
#    define QLADDIN_LIB_RT_OPT "-gd"
#  else
#    define QLADDIN_LIB_RT_OPT
#  endif
#else
#  if defined(_DEBUG)
#    define QLADDIN_LIB_RT_OPT "-sgd"
#  else
#    define QLADDIN_LIB_RT_OPT "-s"
#  endif
#endif

#define QLADDIN_LIB_NAME "QuantLibObjects-" QLADDIN_LIB_TOOLSET QLADDIN_LIB_PLATFORM QLADDIN_LIB_THREAD_OPT QLADDIN_LIB_RT_OPT "-" QLADDIN_LIB_VERSION ".lib"

#pragma comment(lib, QLADDIN_LIB_NAME)
#ifdef BOOST_LIB_DIAGNOSTIC
#  pragma message("Will (need to) link to lib file: " QLADDIN_LIB_NAME)
#endif

#endif

