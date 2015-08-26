/*
 * (C) Copyright 1996-2013 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include "eckit/types/Types.h"
#include "eckit/exception/Exceptions.h"
#include "eckit/parser/StringTools.h"
#include "experimental/eckit/ecml/parser/Request.h"

#include "experimental/eckit/ecml/core/ExecutionContext.h"
#include "experimental/eckit/ecml/core/Environment.h"
#include "experimental/eckit/ecml/core/Interpreter.h"

#include "experimental/eckit/ecml/ast/FunctionDefinition.h"
#include "experimental/eckit/ecml/ast/Closure.h"
#include "experimental/eckit/ecml/prelude/DefineFunctionHandler.h"

using namespace std;

namespace eckit {

DefineFunctionHandler::DefineFunctionHandler(const string& name)
: SpecialFormHandler(name)
{}

Request DefineFunctionHandler::handle(const Request request, ExecutionContext& context)
{
    FunctionDefinition f (request);
    Closure closure (f, context);
    Cell* closureWrapped (new Cell("_list", "", closure, 0));
    context.pushEnvironmentFrame(new Cell("_verb", "let", 0, 
                                            new Cell("", f.name(), closureWrapped, 0)));
    return Cell::clone(closureWrapped);
}

} // namespace eckit