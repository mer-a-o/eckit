/*
 * (C) Copyright 1996-2014 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/// @file Eigen.h
/// @author Tiago Quintino
/// @date March 2014

#ifndef eckit_maths_Eigen_h
#define eckit_maths_Eigen_h

#include "eckit/eckit_config.h"

//--------------------------------------------------------------------------------------------

#ifndef EIGEN3_FOUND
#error Eigen 3 is not enabled
#else

#define EIGEN_NO_AUTOMATIC_RESIZING
#define EIGEN_DONT_ALIGN
#define EIGEN_DONT_VECTORIZE

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Sparse>

#endif

//--------------------------------------------------------------------------------------------

#endif
