#ifndef VALUETYPE_HPP
#define VALUETYPE_HPP

#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/variant.hpp>
#include <boost/mpl/vector.hpp>

#include <string>
#include <cstdint>
#include <type_traits>

namespace Intr
{
    namespace  mpl = boost::mpl;
    using LiteralTypes  = mpl::vector<
            std::int32_t,
            double,
            bool,
            std::string>::type
        ;

    using Literal = boost::make_variant_over<LiteralTypes>::type;

};

#endif // VALUETYPE_HPP
