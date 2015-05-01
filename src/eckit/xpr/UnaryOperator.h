/*
 * (C) Copyright 1996-2013 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/// @file UnaryOperator.h
/// @author Baudouin Raoult
/// @author Tiago Quintino
/// @author Florian Rathgeber
/// @date November 2013

#ifndef eckit_xpr_UnaryFunc_h
#define eckit_xpr_UnaryFunc_h

#include <functional>

#include "eckit/xpr/Function.h"
#include "eckit/xpr/Undef.h"


namespace eckit {
namespace xpr {

//--------------------------------------------------------------------------------------------

/// Generates a expressions
/// T is the operator type
template <class T>
class UnaryOperator : public Function {
public:

    /// generator for this expression type
    static ExpPtr make ( ExpPtr p0 )
    {
        args_t args;
        args.push_back( p0 );
        return ExpPtr( new UnaryOperator<T>(args) );
    }

    static const char * nodeName();

    UnaryOperator( ExpPtr e );

    UnaryOperator(UnaryOperator&&) = default;

    UnaryOperator(Stream& s);

    UnaryOperator& operator=(UnaryOperator&&) = default;

    virtual const ReanimatorBase& reanimator() const { return reanimator_; }
    static const ClassSpec& classSpec();

private: // methods

    UnaryOperator( args_t& a );

    virtual std::string factoryName() const;
    virtual const char * typeName() const;

    virtual ExpPtr cloneWith(args_t& a) const
    {
        return ExpPtr( new UnaryOperator<T>(a) );
    }

    virtual void asJSON( JSON& s ) const;

private: // static members

    static  Reanimator<UnaryOperator> reanimator_;
};

//--------------------------------------------------------------------------------------------

typedef std::negate<real_t>  Neg;
struct Sqrt;
struct Abs;

//--------------------------------------------------------------------------------------------

// version with stand alone functions

ExpPtr neg( ExpPtr e = undef() );
ExpPtr neg( Expression& e );

ExpPtr sqrt( ExpPtr e = undef() );
ExpPtr sqrt( Expression& e );

ExpPtr abs( ExpPtr e = undef() );
ExpPtr abs( Expression& e );

//--------------------------------------------------------------------------------------------

} // namespace xpr
} // namespace eckit

#endif
