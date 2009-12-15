/*
    Copyright (c) 2007-2009 FastMQ Inc.

    This file is part of 0MQ.

    0MQ is free software; you can redistribute it and/or modify it under
    the terms of the Lesser GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    Lesser GNU General Public License for more details.

    You should have received a copy of the Lesser GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ZMQ_ZMQ_DECODER_HPP_INCLUDED__
#define __ZMQ_ZMQ_DECODER_HPP_INCLUDED__

#include "../bindings/c/zmq.h"

#include "decoder.hpp"

namespace zmq
{
    //  Decoder for 0MQ backend protocol. Converts data batches into messages.

    class zmq_decoder_t : public decoder_t <zmq_decoder_t>
    {
    public:

        //  If prefix is not NULL, it will be glued to the beginning of every
        //  decoded message.
        zmq_decoder_t (size_t bufsize_, void *prefix_, size_t prefix_size_);
        ~zmq_decoder_t ();

        void set_inout (struct i_inout *destination_);

    private:

        bool one_byte_size_ready ();
        bool eight_byte_size_ready ();
        bool message_ready ();

        struct i_inout *destination;
        unsigned char tmpbuf [8];
        ::zmq_msg_t in_progress;

        void *prefix;
        size_t prefix_size;

        zmq_decoder_t (const zmq_decoder_t&);
        void operator = (const zmq_decoder_t&);
    };

}

#endif

