//
// Created by dewe on 12/28/22.
//
#include "filesystem"
#include <iostream>
#include "scalar.h"


namespace pd {
Scalar::Scalar(std::shared_ptr<arrow::Scalar>&& value)
    : scalar(std::move(value))
{
}

Scalar::operator bool()
{
    if (scalar)
    {
        auto boolScalar = pd::ReturnOrThrowOnFailure(scalar->CastTo(arrow::boolean()));
        return std::dynamic_pointer_cast<arrow::BooleanScalar>(boolScalar)
            ->value;
    }
    return false;
}
}