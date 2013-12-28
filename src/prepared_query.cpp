/*
 * Copyright (c) 2013, Roland Bock
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 *   Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 *   Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <iostream>
#include <sqlpp11/mysql/prepared_query.h>
#include "detail/prepared_query_handle.h"


namespace sqlpp
{
	namespace mysql
	{
		namespace detail
		{
			prepared_query_impl_t::prepared_query_impl_t()
			{}

			prepared_query_impl_t::prepared_query_impl_t(std::unique_ptr<detail::prepared_query_handle_t>&& handle):
				_handle(std::move(handle))
			{
				if (_handle and _handle->debug)
					std::cerr << "MySQL debug: Constructing prepared_query, using handle at " << _handle.get() << std::endl;
			}

			prepared_query_impl_t::~prepared_query_impl_t() = default;
			prepared_query_impl_t::prepared_query_impl_t(prepared_query_impl_t&& rhs) = default;
			prepared_query_impl_t& prepared_query_impl_t::operator=(prepared_query_impl_t&&) = default;
		}
	}
}

