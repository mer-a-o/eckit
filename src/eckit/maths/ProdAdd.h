/*
 * (C) Copyright 1996-2013 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/// @file ProdAdd.h
/// @author Baudouin Raoult
/// @author Tiago Quintino
/// @date November 2013

#ifndef eckit_maths_ProdAdd_h
#define eckit_maths_ProdAdd_h

#include "eckit/maths/Func.h"

namespace eckit {
namespace maths {

//--------------------------------------------------------------------------------------------

/// Generates a ProdAdd expressions
class ProdAdd {

public: // methods

    static std::string class_name() { return "ProdAdd"; }

    /// Represents a ProdAdd expression
    struct Op : public Func
    {
        Op( const args_t& args ) : Func( args ) {}
        Op( const ExpPtr& e );
        virtual std::string type_name() const { return ProdAdd::class_name(); }
        virtual std::string ret_signature() const;
    };

    /// Expr generator function
    ExpPtr operator() ( ExpPtr p0, ExpPtr p1, ExpPtr p2 )
    {
        args_t args;
        args.push_back( p0 );
        args.push_back( p1 );
        args.push_back( p2 );
        return ExpPtr( new Op(args) );
    }

    struct Register
    {
        Register();
    };

protected: // methods

    /// Specific computation for s * ( v + v )
    static ValPtr compute_svv( const args_t& p );

    /// Specific computation for v * ( v + v )
    static ValPtr compute_vvv( const args_t& p );

    /// Generic prod_add implementation based on calling first add() then prod()
    static ValPtr compute_ggg( const args_t& p );

};

//--------------------------------------------------------------------------------------------

ExpPtr prod_add( ExpPtr p0, ExpPtr p1, ExpPtr p2 ) { return ExpPtr( ProdAdd()(p0,p1,p2) ); }

//--------------------------------------------------------------------------------------------

} // namespace maths
} // namespace eckit

#endif
