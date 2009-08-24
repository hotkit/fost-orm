/*
    Copyright 1999-2009, Felspar Co Ltd. http://fost.3.felspar.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include "fost-schema.hpp"
#include <fost/detail/db.hpp>
#include <fost/detail/schema.hpp>
#include <fost/detail/schema/factory.hpp>

#include <fost/exception/null.hpp>


using namespace fostlib;


/*
    fostlib::model_base
*/

fostlib::model_base::model_base( const json &j )
: m_instance( new instance( *detail::find_factory( coerce< string >(  j[ L"_meta" ][ L"type_info" ] ) ).meta(), j ) ) {
}

fostlib::model_base::~model_base() {
}

instance &fostlib::model_base::_instance() {
    return *m_instance;
}


/*
    fostlib::model_base::tag_base
*/


model_base::attribute_meta fostlib::model_base::primary_tag::stereotype() const {
    return model_base::a_primary;
}

model_base::attribute_meta fostlib::model_base::nullable_tag::stereotype() const {
    return model_base::a_nullable;
}

model_base::attribute_meta fostlib::model_base::required_tag::stereotype() const {
    return model_base::a_required;
}

