/*
 * (C) Copyright 1996-2013 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include "eckit/maths/Call.h"
#include "eckit/maths/List.h"

namespace eckit {
namespace maths {

//--------------------------------------------------------------------------------------------


Call::Call(const args_t& args) : Func(args)
{
    ASSERT(arity() > 0);
}

Call::Call( ExpPtr f) : Func()
{
    args_.push_back(f);
}


Call::Call( ExpPtr f,  ExpPtr a ) : Func()
{
    args_.push_back(f);
    args_.push_back(a);
}

Call::Call( ExpPtr f,  ExpPtr a, ExpPtr b ) : Func()
{
    args_.push_back(f);
    args_.push_back(a);
    args_.push_back(b);
}

string Call::ret_signature() const
{
    return List::sig();
}

ValPtr Call::evaluate( Context &ctx )
{
    ExpPtr f = param(0, ctx);

    args_t args;

    for( size_t i = 1; i < arity(); ++i )
    {
        args.push_back(param(i, ctx));
    }

    return f->eval(ctx, args);
}

//--------------------------------------------------------------------------------------------

ExpPtr call( ExpPtr f)
{
    return ExpPtr( new Call(f) );
}

ExpPtr call( ExpPtr f, ExpPtr a)
{
    return ExpPtr( new Call(f, a) );
}


ExpPtr call( ExpPtr f, ExpPtr a, ExpPtr b)
{
    return ExpPtr( new Call(f, a, b ) );
}

//--------------------------------------------------------------------------------------------

} // namespace maths
} // namespace eckit
