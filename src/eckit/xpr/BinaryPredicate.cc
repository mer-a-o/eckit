/*
 * (C) Copyright 1996-2013 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include "eckit/xpr/Scalar.h"
#include "eckit/xpr/Vector.h"
#include "eckit/xpr/BinaryPredicate.h"
#include "eckit/xpr/Optimiser.h"

namespace eckit {
namespace xpr {

//--------------------------------------------------------------------------------------------

static const char *opname(const Greater&)       { return "Greater";  }
static const char *opname(const GreaterEqual&)  { return "GreaterEqual";  }
static const char *opname(const Less&)          { return "Less";  }
static const char *opname(const LessEqual&)     { return "LessEqual";  }
static const char *opname(const Equal&)         { return "Equal";  }
static const char *opname(const NotEqual&)      { return "NotEqual";  }
static const char *opname(const And&)           { return "And";  }
static const char *opname(const Or&)            { return "Or";  }

static const char *opsymbol(const Greater&)       { return ">";  }
static const char *opsymbol(const GreaterEqual&)  { return ">=";  }
static const char *opsymbol(const Less&)          { return "<";  }
static const char *opsymbol(const LessEqual&)     { return "<=";  }
static const char *opsymbol(const Equal&)         { return "==";  }
static const char *opsymbol(const NotEqual&)      { return "!=";  }
static const char *opsymbol(const And&)           { return "&&";  }
static const char *opsymbol(const Or&)            { return "||";  }

//--------------------------------------------------------------------------------------------

struct Generic
{
    template <class T, class U, class V >
    static ExpPtr apply( T op, const U& a, const V& b )
    {
        return ExpPtr( new Boolean( op( a , b ) ) );
    }
};

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------


namespace _Greater {
typedef Greater T;

static BinaryPredicate< T >::Computer<Boolean,Boolean,Generic>  bbg;
static BinaryPredicate< T >::Computer<Boolean,Scalar,Generic>   bsg;
static BinaryPredicate< T >::Computer<Scalar,Boolean,Generic>   sbg;
static BinaryPredicate< T >::Computer<Scalar,Scalar,Generic>    ssg;

static OptimiseTo<Boolean> bb( std::string(opname( T () )) + "(b,b)" );
static OptimiseTo<Boolean> sb( std::string(opname( T () )) + "(s,b)" );
static OptimiseTo<Boolean> bs( std::string(opname( T () )) + "(b,s)" );
static OptimiseTo<Boolean> ss( std::string(opname( T () )) + "(s,s)" );

}

namespace _GreaterEqual {
typedef GreaterEqual T;

static BinaryPredicate< T >::Computer<Boolean,Boolean,Generic>  bbg;
static BinaryPredicate< T >::Computer<Boolean,Scalar,Generic>   bsg;
static BinaryPredicate< T >::Computer<Scalar,Boolean,Generic>   sbg;
static BinaryPredicate< T >::Computer<Scalar,Scalar,Generic>    ssg;

static OptimiseTo<Boolean> bb( std::string(opname( T () )) + "(b,b)" );
static OptimiseTo<Boolean> sb( std::string(opname( T () )) + "(s,b)" );
static OptimiseTo<Boolean> bs( std::string(opname( T () )) + "(b,s)" );
static OptimiseTo<Boolean> ss( std::string(opname( T () )) + "(s,s)" );

}

namespace _Less {
typedef Less T;

static BinaryPredicate< T >::Computer<Boolean,Boolean,Generic>  bbg;
static BinaryPredicate< T >::Computer<Boolean,Scalar,Generic>   bsg;
static BinaryPredicate< T >::Computer<Scalar,Boolean,Generic>   sbg;
static BinaryPredicate< T >::Computer<Scalar,Scalar,Generic>    ssg;

static OptimiseTo<Boolean> bb( std::string(opname( T () )) + "(b,b)" );
static OptimiseTo<Boolean> sb( std::string(opname( T () )) + "(s,b)" );
static OptimiseTo<Boolean> bs( std::string(opname( T () )) + "(b,s)" );
static OptimiseTo<Boolean> ss( std::string(opname( T () )) + "(s,s)" );

}

namespace _LessEqual {
typedef LessEqual T;

static BinaryPredicate< T >::Computer<Boolean,Boolean,Generic>  bbg;
static BinaryPredicate< T >::Computer<Boolean,Scalar,Generic>   bsg;
static BinaryPredicate< T >::Computer<Scalar,Boolean,Generic>   sbg;
static BinaryPredicate< T >::Computer<Scalar,Scalar,Generic>    ssg;

static OptimiseTo<Boolean> bb( std::string(opname( T () )) + "(b,b)" );
static OptimiseTo<Boolean> sb( std::string(opname( T () )) + "(s,b)" );
static OptimiseTo<Boolean> bs( std::string(opname( T () )) + "(b,s)" );
static OptimiseTo<Boolean> ss( std::string(opname( T () )) + "(s,s)" );

}

namespace _Equal {
typedef Equal T;

static BinaryPredicate< T >::Computer<Boolean,Boolean,Generic>  bbg;
static BinaryPredicate< T >::Computer<Boolean,Scalar,Generic>   bsg;
static BinaryPredicate< T >::Computer<Scalar,Boolean,Generic>   sbg;
static BinaryPredicate< T >::Computer<Scalar,Scalar,Generic>    ssg;

static OptimiseTo<Boolean> bb( std::string(opname( T () )) + "(b,b)" );
static OptimiseTo<Boolean> sb( std::string(opname( T () )) + "(s,b)" );
static OptimiseTo<Boolean> bs( std::string(opname( T () )) + "(b,s)" );
static OptimiseTo<Boolean> ss( std::string(opname( T () )) + "(s,s)" );

}

namespace _NotEqual {
typedef NotEqual T;

static BinaryPredicate< T >::Computer<Boolean,Boolean,Generic>  bbg;
static BinaryPredicate< T >::Computer<Boolean,Scalar,Generic>   bsg;
static BinaryPredicate< T >::Computer<Scalar,Boolean,Generic>   sbg;
static BinaryPredicate< T >::Computer<Scalar,Scalar,Generic>    ssg;

static OptimiseTo<Boolean> bb( std::string(opname( T () )) + "(b,b)" );
static OptimiseTo<Boolean> sb( std::string(opname( T () )) + "(s,b)" );
static OptimiseTo<Boolean> bs( std::string(opname( T () )) + "(b,s)" );
static OptimiseTo<Boolean> ss( std::string(opname( T () )) + "(s,s)" );

}

namespace _And {
typedef And T;

static BinaryPredicate< T >::Computer<Boolean,Boolean,Generic>  bbg;
static BinaryPredicate< T >::Computer<Boolean,Scalar,Generic>   bsg;
static BinaryPredicate< T >::Computer<Scalar,Boolean,Generic>   sbg;
static BinaryPredicate< T >::Computer<Scalar,Scalar,Generic>    ssg;

static OptimiseTo<Boolean> bb( std::string(opname( T () )) + "(b,b)" );
static OptimiseTo<Boolean> sb( std::string(opname( T () )) + "(s,b)" );
static OptimiseTo<Boolean> bs( std::string(opname( T () )) + "(b,s)" );
static OptimiseTo<Boolean> ss( std::string(opname( T () )) + "(s,s)" );

}

namespace _Or {
typedef Or T;

static BinaryPredicate< T >::Computer<Boolean,Boolean,Generic>  bbg;
static BinaryPredicate< T >::Computer<Boolean,Scalar,Generic>   bsg;
static BinaryPredicate< T >::Computer<Scalar,Boolean,Generic>   sbg;
static BinaryPredicate< T >::Computer<Scalar,Scalar,Generic>    ssg;

static OptimiseTo<Boolean> bb( std::string(opname( T () )) + "(b,b)" );
static OptimiseTo<Boolean> sb( std::string(opname( T () )) + "(s,b)" );
static OptimiseTo<Boolean> bs( std::string(opname( T () )) + "(b,s)" );
static OptimiseTo<Boolean> ss( std::string(opname( T () )) + "(s,s)" );

}


ExpPtr greater( ExpPtr l, ExpPtr r )        { return ExpPtr( new BinaryPredicate< Greater >(l,r) );      }
ExpPtr greater_equal( ExpPtr l, ExpPtr r )  { return ExpPtr( new BinaryPredicate< GreaterEqual >(l,r) ); }
ExpPtr less( ExpPtr l, ExpPtr r )           { return ExpPtr( new BinaryPredicate< Less >(l,r) );         }
ExpPtr less_equal( ExpPtr l, ExpPtr r )     { return ExpPtr( new BinaryPredicate< LessEqual >(l,r) );    }
ExpPtr equal( ExpPtr l, ExpPtr r )          { return ExpPtr( new BinaryPredicate< Equal >(l,r) );        }
ExpPtr not_equal( ExpPtr l, ExpPtr r )      { return ExpPtr( new BinaryPredicate< NotEqual >(l,r) );     }
ExpPtr logical_and( ExpPtr l, ExpPtr r )    { return ExpPtr( new BinaryPredicate< And >(l,r) );          }
ExpPtr logical_or( ExpPtr l, ExpPtr r )     { return ExpPtr( new BinaryPredicate< Or >(l,r) );           }

//--------------------------------------------------------------------------------------------

template < class T >
BinaryPredicate<T>::BinaryPredicate(ExpPtr a, ExpPtr b)
{
    push_back(a);
    push_back(b);
}

template < class T >
BinaryPredicate<T>::BinaryPredicate(args_t& a) : Function(a)
{
    ASSERT( a.size() == 2 );
}

template < class T >
std::string BinaryPredicate<T>::returnSignature() const
{
    return Boolean::sig();
}

template < class T >
std::string BinaryPredicate<T>::typeName() const
{
    return BinaryPredicate<T>::className();
}

template < class T >
std::string BinaryPredicate<T>::className()
{
    return opname( T() );
}

template < class T >
void BinaryPredicate<T>::asCode( std::ostream& o ) const {
    o << '(' << *args(0) << ' ' << opsymbol(T()) << ' ' << *args(1) << ')';
}
/*
template < class T >
ExpPtr BinaryPredicate<T>::optimise() const
{
    return Optimiser::apply(self());
}*/

template < class T >
template < class U, class V, class I >
BinaryPredicate<T>::Computer<U,V,I>::Computer()
{
    Function::dispatcher()[ sig() ] = &compute;
}

template < class T >
template < class U, class V, class I >
std::string BinaryPredicate<T>::Computer<U,V,I>::sig()
{
    return opname( T() ) + std::string("(") + U::sig() + std::string(",") + V::sig() + std::string(")");
}

template < class T >
template < class U, class V, class I >
ExpPtr BinaryPredicate<T>::Computer<U,V,I>::compute(Scope& ctx, const args_t &p)
{
    T op;
    typename U::value_t a = U::extract(ctx, p[0]);
    typename V::value_t b = V::extract(ctx, p[1]);

    return I::apply(op,a,b);
}

//--------------------------------------------------------------------------------------------

} // namespace xpr
} // namespace eckit